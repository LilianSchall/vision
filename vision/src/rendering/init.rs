use sdl2::render::{TextureCreator, WindowCanvas};
use sdl2::video::{Window, WindowContext};
use crate::rendering::Engine;

pub fn initialize_canvas(title: &str, dim: (u32, u32)) -> WindowCanvas {
    let (w,h) = dim;
    let sdl_context = sdl2::init().unwrap();
    let video = sdl_context.video().unwrap();

    let window = video.window(title, w, h)
        .position_centered()
        .build()
        .unwrap();
    let canvas = window.into_canvas()
        .accelerated()
        .build()
        .unwrap();
    canvas
}

pub fn init(title: &str, dim: (u32, u32)) -> WindowCanvas {
    let canvas = initialize_canvas(title, dim);
    canvas
}