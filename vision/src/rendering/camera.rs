use sdl2::render::Texture;
use crate::math::{Vector2, Vector3};

pub struct Camera<'a> {
    // its position on screen
    pos_on_canvas: Vector2,
    // its position in the world
    pos_in_world: Vector3,
    // the SDL texture that will be rendered on canvas
    texture: Texture<'a>,
}

impl <'a>Camera<'a> {
    pub fn new(pos_on_canvas: Vector2, pos_in_world: Vector3, texture: Texture<'a>) -> Camera {
        Camera {
            pos_on_canvas,
            pos_in_world,
            texture
        }
    }
}