use std::time::Duration;
use sdl2::pixels::Color;
use sdl2::render::WindowCanvas;

fn initialize_sdl(title: &str, dim: (u32, u32)) -> WindowCanvas {
    let (w,h) = dim;
    let sdl_context = sdl2::init().unwrap();
    let video = sdl_context.video().unwrap();

    let window = video.window(title, w, h)
        .position_centered()
        .build()
        .unwrap();
    let canvas = window.into_canvas().build().unwrap();

    canvas
}

pub fn init(title: &str, dim: (u32, u32)) {
    let mut canvas = initialize_sdl(title, dim);

    canvas.set_draw_color(Color::RGB(0,255,255));
    canvas.clear();
    canvas.present();
    std::thread::sleep(Duration::new(5, 0));
}