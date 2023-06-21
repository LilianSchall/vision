use vision::constraints::Vector;
use vision::math::{Vector2};
use vision::rendering::{Engine, init};

fn main() {
    //let mut initializer = Box::<Init>::new(init("Square: Vision", (800, 600)));
    let mut initializer = init("Square: Vision", (800,600));

    let mut engine: Engine = Engine::new(&mut initializer);
    engine.add_centered_camera(Vector2::ZERO);
    engine.run();
}
