use crate::pozycja_zamowienia::PozycjaZamowienia;

pub struct Zamowienie {
    lista_towarow: Vec<PozycjaZamowienia>,
}

impl Zamowienie {
    pub fn new() -> Zamowienie {
        Zamowienie {
            lista_towarow: Vec::new(),
        }
    }

    pub fn dodaj(&mut self, pozycja: PozycjaZamowienia) {
        self.lista_towarow.push(pozycja);
    }

    pub fn dlina_listy(&self) -> usize {
        self.lista_towarow.len()
    }

    pub fn get_sum(&self) -> f64 {
        let mut suma = 0.0;
        for pozycja in &self.lista_towarow {
            suma += pozycja.zwroc_wartosc();
        }
        suma
    }

    pub fn zmien_ilosc(&mut self, num: usize, nowa_ilosc: u32) {
        if num < self.lista_towarow.len() {
            self.lista_towarow[num].zmien_liczbe_sztuk(nowa_ilosc);
        }
    }

    pub fn usun(&mut self, num: usize) {
        if num < self.lista_towarow.len() {
            self.lista_towarow.remove(num);
        }
    }

    pub fn show(&self) {
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

#[cfg(test)]
mod tests {
    use super::*;
    use crate::pozycja_zamowienia::PozycjaZamowienia;
    use crate::towar::Towar;

    #[test]
    fn test_dodaj() {
        let towar = Towar::new(String::from("jaja"), 0.99);
        let pozycja = PozycjaZamowienia::new(towar, 10);
        let mut zamowienie = Zamowienie::new();
        zamowienie.dodaj(pozycja);
        assert_eq!(zamowienie.dlina_listy(), 1);
    }

    #[test]
    fn test_get_sum() {
        let towar1 = Towar::new(String::from("jaja"), 0.99);
        let pozycja1 = PozycjaZamowienia::new(towar1, 10);
        let towar2 = Towar::new(String::from("chleb"), 23.99);
        let pozycja2 = PozycjaZamowienia::new(towar2, 4);
        let mut zamowienie = Zamowienie::new();
        zamowienie.dodaj(pozycja1);
        zamowienie.dodaj(pozycja2);
        assert_eq!(zamowienie.get_sum(), 44.86);
