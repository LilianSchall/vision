pub trait Vector {

}

pub trait Movable<T: Vector> {
    fn translate(&mut self, translation: &T);
}