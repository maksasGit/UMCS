enum Axis {
    Ox,
    Oy,
    ObieOsi,
}

enum Transformation {
    Move(f32, f32),
    Reflect(Axis),
    Turn(f32),
    Scale(f32),
}

impl Transformation {
    fn reflect(&self) -> Option<Transformation> {
        match self {
            Transformation::Move(dx, dy) => Some(Transformation::Move(-dx, -dy)),
            Transformation::Reflect(axis) => Some(Transformation::Reflect(axis)),
            Transformation::Turn(angle) => Some(Transformation::Turn(-angle)),
            Transformation::Scale(ratio) => {
                if *ratio == 0.0 {
                    None
                } else {
                    Some(Transformation::Scale(1.0 / ratio))
                }
            }
        }
    }
}

struct Punkt {
    x: f32,
    y: f32,
}

impl Punkt {
    fn new(x: f32, y: f32) -> Self {
        Punkt { x, y }
    }

    fn transform(&mut self, method:Transformation){
        match method {
            Transformation::Move(dx, dy) => {
                self.x += dx;
                self.y += dy;
            },
            Transformation::Reflect(axis) => {
                match axis{
                    Axis::Ox => self.x = -self.x,
                    Axis::Oy => self.y = -self.y,
                    Axis::ObieOsi => {
                        self.x = -self.x;
                        self.y = -self.y;
                    },
                }
            },
            Transformation::Turn(angel) => {
                let x = self.x;
                let y = self.y; 
                self.x = x * angel.cos() - y * angel.sin();
                self.y = y * angel.sin() + y * angel.cos();
            },
            Transformation::Scale(ratio) => {
                self.x *= ratio;
                self.y *= ratio;
            },
        }
    }
}

fn main() {
    let mut point = Punkt::new(0.0, 0.0);
    println!("Start: ({}, {})", point.x, point.y);
    point.transform(Transformation::Move(2.0, 3.0));
    println!("Move: ({}, {})", point.x, point.y);
    point.transform(Transformation::Reflect(Axis::Ox));
    println!("Reflect: ({}, {})", point.x, point.y);
    point.transform(Transformation::Turn(90.0));
    println!("Turn: ({}, {})", point.x, point.y);
    point.transform(Transformation::Scale(2.0));
    println!("Scale: ({}, {})", point.x, point.y);
}
