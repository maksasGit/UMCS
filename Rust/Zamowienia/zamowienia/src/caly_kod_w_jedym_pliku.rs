struct Towar {
    nazwa: String,
    cena: f64,
}

impl Towar {
    fn new(nazwa: String, cena: f64) -> Towar {
        Towar { nazwa, cena }
    }

    fn zwroc_nazwe(&self) -> &String {
        &self.nazwa
    }


    fn zwroc_cene(&self) -> f64 {
        self.cena
    }
}

struct PozycjaZamowienia {
    towar: Towar,
    ilosc: u32,
}

impl PozycjaZamowienia {


    fn new(towar: Towar, ilosc: u32) -> PozycjaZamowienia {
        PozycjaZamowienia { towar, ilosc }
    }

    fn zwroc_towar(&self) -> &Towar {
        &self.towar
    }

    fn ile_sztuk(&self) -> u32 {
        self.ilosc
    }

    fn zwroc_wartosc(&self) -> f64 {
        self.towar.zwroc_cene() * f64::from(self.ilosc)
    }

    fn zmien_liczbe_sztuk(&mut self, nowa_ilosc: u32) {
        self.ilosc = nowa_ilosc;
    }
}

struct Zamowienie {
    lista_towarow: Vec<PozycjaZamowienia>,
}

impl Zamowienie {
    fn new() -> Zamowienie {
        Zamowienie {
            lista_towarow: Vec::new(),
        }
    }

    fn dodaj(&mut self, pozycja: PozycjaZamowienia) {
        self.lista_towarow.push(pozycja);
    }

    fn dlina_listy(&self) -> usize {
        self.lista_towarow.len()
    }

    fn get_sum(&self) -> f64 {
        let mut suma = 0.0;
        for pozycja in &self.lista_towarow {
            suma += pozycja.zwroc_wartosc();
        }
        suma
    }

    fn zmien_ilosc(&mut self, num: usize, nowa_ilosc: u32) {
        if num < self.lista_towarow.len() {
            self.lista_towarow[num].zmien_liczbe_sztuk(nowa_ilosc);
        }
    }

    fn usun(&mut self, num: usize) {
        if num < self.lista_towarow.len() {
            self.lista_towarow.remove(num);
        }
    }

    fn show(&self) {
        println!("{:<3} {:<15} {:>10} {:>12} {:>14}", "", "towar", "cena", "ilość", "wartość");
        println!("----------------------------------------------------------");
        for (index, pozycja) in self.lista_towarow.iter().enumerate() {
            let towar = pozycja.zwroc_towar();
            let numer = index + 1;
            println!(
                "{:<1.3}. {:<15} {:>7.2} zł {:>8.4} szt. {:>10.2} zł",
                numer,
                towar.zwroc_nazwe(),
                towar.zwroc_cene(),
                pozycja.ile_sztuk(),
                pozycja.zwroc_wartosc()
            );
        }
        println!("----------------------------------------------------------");
        println!(
            "{:<23} {:>31.2} zł",
            "RAZEM",
            self.get_sum()
        );
    }
    
    
}


fn main() {
    let mut zamowienie = Zamowienie::new();
    let towar1 = Towar::new(String::from("jaja"), 0.99);
    let pozycja1 = PozycjaZamowienia::new(towar1, 10);
    let towar2 = Towar::new(String::from("chleb"), 23.99);
    let pozycja2 = PozycjaZamowienia::new(towar2, 4);
    let towar3 = Towar::new(String::from("persymona"), 1.65);


    zamowienie.dodaj(pozycja1);
    zamowienie.dodaj(pozycja2);
    zamowienie.dodaj(pozycja3);



    zamowienie.show();
}


