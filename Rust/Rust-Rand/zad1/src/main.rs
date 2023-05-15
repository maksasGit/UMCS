struct RandGen {
    seed: u64,
}

impl RandGen {
    fn new(seed: u64) -> RandGen {
        RandGen { seed }
    }

    fn gen_range(&mut self, min: u64, max: u64) -> u64 {
        self.seed = (self.seed * 110545 + 12345) % (1 << 31);
        min + (self.seed % (max - min + 1))
    }
}

struct Urna {
    generator: RandGen,
    elements: Vec<char>,
}

impl Urna {
    fn new(generator: RandGen) -> Urna {
        Urna {
            generator,
            elements: Vec::new(),
        }
    }

    fn add(&mut self, element: char) {
        self.elements.push(element);
    }

    fn ilosc_elementow(&self) -> usize {
        self.elements.len()
    }

    fn losuj_z_usuwaniem(&mut self) -> Option<char> {
        if self.ilosc_elementow() == 0 {
            return None;
        }
        let index = self.generator.gen_range(0, self.elements.len() as u64);
        let element = self.elements.get(index as usize).cloned();
        self.elements.remove(index as usize);
        element
    }

    fn losuj_bez_usuwania(&mut self) -> Option<char> {
        if self.ilosc_elementow() == 0 {
            return None;
        }
        let index = self.generator.gen_range(0, self.elements.len() as u64);
        self.elements.get(index as usize).cloned()
    }

    fn print_all(&self) {
        for element in &self.elements {
            print!("{} ", element);
        }
        println!();
    }
}

fn main() {
    let mut generator = RandGen::new(228);
    let mut urna = Urna::new(generator);
    urna.add('a');
    urna.add('b');
    urna.add('c');
    urna.add('b');
    urna.add('f');
    let x: Option<char> = urna.losuj_bez_usuwania();
    let y: Option<char> = urna.losuj_z_usuwaniem();

    let n = urna.ilosc_elementow();

    println!("x: {:?}", x);
    println!("y: {:?}", y);
    println!("n: {}", n);
    urna.print_all();
}
