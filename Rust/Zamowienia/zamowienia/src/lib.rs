mod towar;
mod pozycja_zamowienia;
mod zamowienie;

use towar::Towar;
use pozycja_zamowienia::PozycjaZamowienia;
use zamowienie::Zamowienie;

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