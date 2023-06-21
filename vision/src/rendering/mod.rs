mod init;
mod object;
mod mesh;
mod engine;
mod camera;

use sdl2::render::{Texture};
pub use init::{Init, init, initialize_canvas};
pub use object::Object;
pub use engine::Engine;
pub use camera::Camera;

pub trait Renderable {
    fn render(&mut self, texture: &Texture);
}
