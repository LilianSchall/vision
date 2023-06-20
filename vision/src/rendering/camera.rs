use sdl2::render::{Texture, TextureAccess, TextureCreator};
use sdl2::video::WindowContext;
use crate::math::{Vector2, Vector3};

pub struct Camera<'a> {
    // its position on screen
    pos_on_canvas: Vector2,
    // its position in the world
    pos_in_world: Vector3,
    // its rotation
    rotation: Vector3,
    // the SDL renderer that is responsible of the texture
    renderer: &'a TextureCreator<WindowContext>,
    // the SDL texture that will be rendered on canvas
    texture: Texture<'a>,
}

impl<'a> Camera<'a> {
    pub fn new(pos_on_canvas: Vector2, pos_in_world: Vector3, rotation: Vector3, renderer: &'a TextureCreator<WindowContext>) -> Camera {
        let texture = renderer.create_texture(None, TextureAccess::Streaming, 800, 600).unwrap();
        Camera {
            pos_on_canvas,
            pos_in_world,
            rotation,
            renderer,
            texture,
        }
    }
}