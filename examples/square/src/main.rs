use vision::constraints::Vector;
use vision::math::{Vector2, Vector3};
use vision::rendering::{Camera, Engine, init};

fn main() {
    let canvas = init("Square: Vision", (800, 600));
    let mut engine: Engine<'static> = Engine::new(canvas, 800, 600);
    engine.add_centered_camera(Vector2::ZERO);
    engine.run();
}
