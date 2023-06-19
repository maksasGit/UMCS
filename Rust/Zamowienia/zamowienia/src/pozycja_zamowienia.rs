use crate::towar::Towar;

pub struct PozycjaZamowienia {
    towar: Towar,
    ilosc: u32,
}

impl PozycjaZamowienia {
    pub fn new(towar: Towar, ilosc: u32) -> PozycjaZamowienia {
        PozycjaZamowienia { towar, ilosc }
    }

    pub fn zwroc_towar(&self) -> &Towar {
        &self.towar
    }

    pub fn ile_sztuk(&self) -> u32 {
        self.ilosc
    }

    pub fn zwroc_wartosc(&self) -> f64 {
        self.towar.zwroc_cene() * f64::from(self.ilosc)
    }

    pub fn zmien_liczbe_sztuk(&mut self, nowa_ilosc: u32) {
        self.ilosc = nowa_ilosc;
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::towar::Towar;

    #[test]
    fn test_ile_sztuk() {
        let towar = Towar::new(String::from("jaja"), 0.99);
        let pozycja = PozycjaZamowienia::new(towar, 10);
        assert_eq!(pozycja.ile_sztuk(), 10);
    }

    #[test]
    fn test_zwroc_wartosc() {
        let towar = Towar::new(String::from("jaja"), 0.99);
        let pozycja = PozycjaZamowienia::new(towar, 10);
        assert_eq!(pozycja.zwroc_wartosc(), 9.9);
    }
}
