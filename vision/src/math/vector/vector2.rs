use crate::constraints::{Movable, Vector};

pub struct Vector2 {
    pub x: f64,
    pub y: f64,
}

impl Vector2 {
    pub fn new(x: f64, y: f64) -> Vector2 {
        Vector2 {
            x,
            y,
        }
    }
}

impl Movable<Vector2> for Vector2 {
    fn translate(&mut self, translation: &Vector2) {
        self.x += translation.x;
        self.y += translation.y;
    }
}


impl Vector for Vector2 {
    const ZERO: Vector2 = Vector2{x: 0.0, y: 0.0};
}