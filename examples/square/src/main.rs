use vision::constraints::Vector;
use vision::math::{Vector2, Vector3};
use vision::rendering::{Engine, init, Object};

fn main() {
    let (width, height) = (1200, 600);
    //let mut initializer = Box::<Init>::new(init("Square: Vision", (800, 600)));
    let mut initializer = init("Square: Vision", (width,height));

    let mut engine: Engine = Engine::new(&mut initializer);
    engine.add_centered_camera(Vector2::new(width as f64, height as f64),Vector2::ZERO);
    engine.add_object(Object::new_square(Vector3::new(0.0, 2.0, 0.0), Vector3::ZERO, 1.0));
    engine.run();
}
