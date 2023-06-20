use sdl2::render::{Texture};
use crate::constraints::Movable;
use crate::math::Vector3;
use crate::rendering::mesh::Mesh;
use crate::rendering::Renderable;

pub struct Object {
    pos: Vector3,
    rotation: Vector3,
    mesh: Mesh,
}

impl Object {
    pub fn new(pos: Vector3, rotation: Vector3, mesh: Mesh) -> Object {
        Object {
            pos,
            rotation,
            mesh,
        }
    }
}

impl Movable<Vector3> for Object {
    fn translate(&mut self, translation: &Vector3) {
        self.pos.translate(translation);
    }
}

impl Renderable for Object {
    fn render(&mut self, texture: &Texture) {
        todo!()
    }
}