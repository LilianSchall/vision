use sdl2::render::{TextureCreator, WindowCanvas};
use sdl2::video::WindowContext;
use crate::rendering::Camera;

pub struct Engine {
    canvas: WindowCanvas,
    renderer: TextureCreator<WindowContext>,
}

impl Engine {
    pub fn new(canvas: WindowCanvas, renderer: TextureCreator<WindowContext>) -> Engine {
        Engine {
            canvas,
            renderer,
        }
    }

    pub fn add_camera(&mut self) -> Camera {
        todo!()
    }
}