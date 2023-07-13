pub trait Vector {
    const ZERO: Self;
}

pub trait Movable<T: Vector> {
    fn translate(&mut self, translation: T);
    fn rotate(&mut self, translation: T);
}