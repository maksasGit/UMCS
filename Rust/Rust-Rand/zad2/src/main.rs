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

struct Urna<T> {
    generator: RandGen,
    elements: Vec<T>,
}

impl<T> Urna<T> {
    fn new(generator: RandGen) -> Urna<T> {
        Urna {
            generator,
            elements: Vec::new(),
        }
    }

    fn add(&mut self, element: T) {
        self.elements.push(element);
    }

    fn ilosc_elementow(&self) -> usize {
        self.elements.len()
    }

    fn losuj_z_usuwaniem(&mut self) -> Option<T> {
        if self.ilosc_elementow() == 0 {
            return None;
        }
        let index = self.generator.gen_range(0, self.elements.len() as u64);
        let element = self.elements.get(index as usize).cloned();
        self.elements.remove(index as usize);
        element
    }

    fn losuj_bez_usuwania(&mut self) -> Option<T> {
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
    urna.add(3);
    urna.add(1);
    urna.add(2);
    urna.add(1);
    urna.add(-1);
    let x = urna.losuj_bez_usuwania();
    let y = urna.losuj_z_usuwaniem();

    let n = urna.ilosc_elementow();

    println!("x: {:?}", x);
    println!("y: {:?}", y);
    println!("n: {}", n);
    urna.print_all();
}
