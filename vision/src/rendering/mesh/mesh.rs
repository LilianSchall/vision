use crate::math::Vector3;

pub struct Mesh {
    vertices: Vec<Vector3>,
    edges: Vec<(usize, usize)>
}

impl Mesh {
    pub fn new(vertices: Vec<Vector3>, edges: Vec<(usize, usize)>) -> Mesh {
        Mesh {
            vertices,
            edges
        }
    }

    pub fn new_full_bound(vertices: Vec<Vector3>) -> Mesh {
        let mut edges: Vec<(usize, usize)> = vec![];

        for i in 0..vertices.len() {
            for j in (i+1)..vertices.len() {
                edges.push((i,j))
            }
        }
        Mesh {
            vertices,
            edges
        }
    }
}