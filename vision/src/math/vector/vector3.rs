use crate::constraints::{Movable, Vector};

pub struct Vector3 {
    x: f64,
    y: f64,
    z: f64,
}

impl Vector3 {
    pub fn new(x: f64, y: f64, z: f64) -> Vector3 {
        Vector3 {
            x,
            y,
            z,
        }
    }
}

impl Movable<Vector3> for Vector3 {
    fn translate(&mut self, translation: &Vector3) {
        self.x += translation.x;
        self.y += translation.y;
        self.z += translation.z;
    }
}

impl Vector for Vector3 {
    const ZERO: Vector3 = Vector3{x: 0.0, y: 0.0, z: 0.0};
}
