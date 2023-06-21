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

    pub fn new_square(pos: Vector3, rotation: Vector3, scale: f64) -> Object {
        let mut vertices: Vec<Vector3> = vec![];
        let mut edges: Vec<(usize, usize)> = vec![];
        let mut i: f64 = -1.0;
        let mut index: usize = 1;
        loop {
            vertices.push(Vector3::new(scale / 2.0, i * (scale / 2.0), scale / 2.0));
            vertices.push(Vector3::new(scale / 2.0, i * (scale / 2.0), -scale / 2.0));
            vertices.push(Vector3::new(-scale / 2.0, i * (scale / 2.0), -scale / 2.0));
            vertices.push(Vector3::new(-scale / 2.0, i * (scale / 2.0), scale / 2.0));

            edges.push((index * 4, index * 4 + 1));
            edges.push((index * 4 + 1, index * 4 + 2));
            edges.push((index * 4 + 2, index * 4 + 3));
            edges.push((index * 4 + 3, index * 4));

            index += 1;
            i += 2.0;
            if i >= 1.0 {
                break;
            }
        }
        for j in 0..4 {
            edges.push((j, j + 4));
        }
        let mesh = Mesh::new(vertices, edges);

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