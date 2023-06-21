use sdl2::rect::Rect;
use sdl2::render::{Texture, TextureAccess, TextureCreator, WindowCanvas};
use sdl2::video::WindowContext;
use crate::math::{Vector2, Vector3};
use crate::rendering::Object;

pub struct Camera<'a> {
    // its position on screen
    pos_on_canvas: Vector2,
    // its position in the world
    pos_in_world: Vector3,
    // its rotation
    rotation: Vector3,
    size: Vector2,
    // the SDL texture that will be rendered on canvas
    texture: Texture<'a>,
    pixels: Vec<u8>,
}

impl<'a> Camera<'a> {
    pub fn new(size: Vector2, pos_on_canvas: Vector2, pos_in_world: Vector3, rotation: Vector3, renderer: &'a TextureCreator<WindowContext>) -> Camera {
        let (width, height) = (size.x as u32, size.y as u32);
        let texture = renderer.create_texture(None, TextureAccess::Streaming, width, height).unwrap();
        Camera {
            pos_on_canvas,
            pos_in_world,
            rotation,
            texture,
            size,
            pixels: vec![0; (width * height * 3) as usize],
        }
    }

    pub fn render_pov(&mut self, canvas: &mut WindowCanvas, objects: &Vec<Object>) {
        self.texture.update(None, &self.pixels, (3 * self.size.x as usize) as usize).expect("Could not update texture");
        canvas.copy(&self.texture, None, Some(self.abs_position_to_rect())).expect("Could not render texture");
    }

    pub fn abs_position_to_rect(&self) -> Rect {
        Rect::new(self.pos_on_canvas.x as i32,
                  self.pos_on_canvas.y as i32,
                  self.size.x as u32,
                  self.size.y as u32,
        )
    }
}