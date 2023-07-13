use sdl2::rect::Rect;
use sdl2::render::{Texture, TextureAccess, TextureCreator, WindowCanvas};
use sdl2::video::WindowContext;
use crate::math::{Vector2, Vector3};
use crate::rendering::Object;

/// A camera is an object that render its perception of the world
/// # Attributes
/// * `pos_on_canvas`: its position on screen
/// * `pos_in_world`: its position in the world
/// * `rotation`: its rotation
/// * `texture`: the SDL texture that will be rendered on canvas
/// * `pixels`: an array that represent every pixel of the texture
/// * `scale`: the ratio that represent the amount of pixel per spatial unit
pub struct Camera<'a> {
    pos_on_canvas: Vector2,
    pos_in_world: Vector3,
    rotation: Vector3,
    size: Vector2,
    texture: Texture<'a>,
    pixels: Vec<u8>,
    pub scale: usize,
}

impl<'a> Camera<'a> {
    /// Instantiate a new camera
    /// # Arguments
    /// * `size`: the size of the camera frame on screen (in pixel)
    /// * `pos_on_canvas`: the position of the camera on screen (in pixel)
    /// * `pos_in_world`: the position of the camera in the world (in spatial unit)
    /// * `rotation`: the rotation of the camera in the world
    /// * `renderer`: the SDL Texture creator of the canvas
    /// * `scale`:  the ratio amount of pixel per spatial unit
    ///
    /// returns: Camera
    pub fn new(size: Vector2,
               pos_on_canvas: Vector2,
               pos_in_world: Vector3,
               rotation: Vector3,
               renderer: &'a TextureCreator<WindowContext>,
               scale: Option<usize>) -> Camera {
        let (width, height) = (size.x as u32, size.y as u32);
        let texture = renderer.create_texture(None, TextureAccess::Streaming, width, height).unwrap();
        Camera {
            pos_on_canvas,
            pos_in_world,
            rotation,
            texture,
            size,
            pixels: vec![0; (width * height * 3) as usize],
            scale: scale.unwrap_or(100),
        }
    }

    /// Render the camera view on the canvas
    /// # Arguments
    ///
    /// * `canvas`: The SDL canvas used as screen
    /// * `objects`: The objects to render
    pub fn render_pov(&mut self, canvas: &mut WindowCanvas, objects: &Vec<Object>) {
        self.texture.update(None, &self.pixels, (3 * self.size.x as usize) as usize).expect("Could not update texture");
        canvas.copy(&self.texture, None, Some(self.abs_position_to_rect())).expect("Could not render texture");
    }

    fn abs_position_to_rect(&self) -> Rect {
        Rect::new(self.pos_on_canvas.x as i32,
                  self.pos_on_canvas.y as i32,
                  self.size.x as u32,
                  self.size.y as u32,
        )
    }
}