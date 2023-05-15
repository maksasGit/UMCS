
struct RandGen{
    seed:u64
}


impl RandGen{
    fn new(seed: u64) -> RandGen {
        RandGen { seed }
    }

    fn gen_range(&mut self, min: u64, max: u64) -> u64 {
        self.seed = (self.seed * 110545 + 12345) % (1 << 31);
        min + (self.seed % (max - min + 1))
    }
}



fn main() {
    let mut generator = RandGen::new(123);
    let a = generator.gen_range(3,5);
    let b = generator.gen_range(3,5);
    let c = generator.gen_range(3,5);

    let mut generator2 = RandGen::new(123);
    let a2 = generator.gen_range(3,5);
    let b2 = generator.gen_range(3,5);
    let c2 = generator.gen_range(3,5);


    println!("Generated numbers for generator:");
    println!("a: {}", a);
    println!("b: {}", b);
    println!("c: {}\n", c);

    println!("Generated numbers for generator2:");
    println!("a2: {}", a2);
    println!("b2: {}", b2);
    println!("c2: {}", c2);
    
}

