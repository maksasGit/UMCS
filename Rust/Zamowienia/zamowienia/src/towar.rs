pub struct Towar {
    nazwa: String,
    cena: f64,
}

impl Towar {
    pub fn new(nazwa: String, cena: f64) -> Towar {
        Towar { nazwa, cena }
    }

    pub fn zwroc_nazwe(&self) -> &String {
        &self.nazwa
    }

    pub fn zwroc_cene(&self) -> f64 {
        self.cena
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_zwroc_nazwe() {
        let towar = Towar::new(String::from("jaja"), 0.99);
        assert_eq!(towar.zwroc_nazwe(), "jaja");
    }

    #[test]
    fn test_zwroc_cene() {
        let towar = Towar::new(String::from("jaja"), 0.99);
        assert_eq!(towar.zwroc_cene(), 0.99);
    }
}
