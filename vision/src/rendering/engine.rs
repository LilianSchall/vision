use std::time::Duration;
use sdl2::pixels::Color;
use sdl2::render::{TextureAccess, TextureCreator, WindowCanvas};
use sdl2::video::WindowContext;
use crate::constraints::Vector;
use crate::math::{Vector2, Vector3};
use crate::rendering::Camera;

pub struct Engine<'a> {
    canvas: WindowCanvas,
    renderer: TextureCreator<WindowContext>,
    cameras: Vec<Camera<'a>>,
    width: u32,
    height: u32,
}

impl Engine<'_> {
    pub fn new(canvas: WindowCanvas, width: u32, height: u32) -> Engine<'static> {
        let renderer = canvas.texture_creator();
        Engine {
            canvas,
            renderer,
            cameras: vec![],
            width,
            height,
        }
    }

    pub fn add_camera(&mut self, pos_on_screen: Vector2, pos_in_world: Vector3, rotation: Vector3) {
        let camera = Camera::new(pos_on_screen, pos_in_world, rotation, &self.renderer);
        self.cameras.push(camera);
    }

    pub fn add_centered_camera(&mut self, pos_on_screen: Vector2) {
        self.add_camera(pos_on_screen, Vector3::ZERO, Vector3::ZERO)
    }

    pub fn run(&mut self) {
        self.canvas.set_draw_color(Color::RGB(0, 255, 255));
        self.canvas.clear();
        self.canvas.present();
        std::thread::sleep(Duration::new(5, 0));
    }
}