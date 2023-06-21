use std::time::Duration;
use sdl2::pixels::Color;
use sdl2::render::{TextureCreator, WindowCanvas};
use sdl2::video::WindowContext;
use crate::constraints::Vector;
use crate::math::{Vector2, Vector3};
use crate::rendering::{Camera, Object};
use crate::rendering::init::Init;

pub struct Engine<'a> {
    cameras: Vec<Camera<'a>>,
    objects: Vec<Object>,
    width: u32,
    height: u32,
    renderer: &'a TextureCreator<WindowContext>,
    canvas: &'a mut WindowCanvas,
}

impl <'a>Engine<'a> {
    pub fn new(initializer: &mut Init) -> Engine {
        Engine {
            cameras: vec![],
            objects: vec![],
            width: initializer.dim.0,
            height: initializer.dim.1,
            renderer: &initializer.renderer,
            canvas: &mut initializer.canvas,
        }
    }

    pub fn add_camera(&mut self, pos_on_screen: Vector2, pos_in_world: Vector3, rotation: Vector3) {
        let camera = Camera::new(pos_on_screen, pos_in_world, rotation, self.renderer);
        self.cameras.push(camera);
    }

    pub fn add_centered_camera(&mut self, pos_on_screen: Vector2) {
        self.add_camera(pos_on_screen, Vector3::ZERO, Vector3::ZERO)
    }

    pub fn run(&mut self) {
        self.canvas.set_draw_color(Color::RGB(0, 0,0));
        self.canvas.clear();

        for cam in &mut self.cameras {
            cam.render_pov(self.canvas, &self.objects);
        }

        self.canvas.present();
        std::thread::sleep(Duration::new(5, 0));
    }
}