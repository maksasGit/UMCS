enum Karta {
    Trefl,
    Karo,
    Kier,
    Pik,
}

impl Karta {
    fn wyliczyc(&self) {
        match self {
            Karta::Trefl => println!("Trefl, Parzandek w brydzu: 1"),
            Karta::Karo => println!("Trefl, Parzandek w brydzu: 2"),
            Karta::Kier => println!("Trefl, Parzandek w brydzu: 3"),
            Karta::Pik => println!("Trefl, Parzandek w brydzu: 4"),
        }
    }
}

fn main() {

    // test


    let karta1 = Karta::Karo;
    let karta2 = Karta::Pik;
    karta1.wyliczyc();
    karta2.wyliczyc();
}