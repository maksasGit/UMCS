enum Blad {
    BrakBledu,
    ZlyFormatPliku,
    PlikNieIstnieje(String),
    PlikZbytDuzy(u64, u64),
}

impl Blad {
    fn pokaz_komunikat(&self) {
        match self {
            Blad::BrakBledu => println!("Brak bledu."),
            Blad::ZlyFormatPliku => println!("Zly format pliku."),
            Blad::PlikNieIstnieje(nazwa_pliku) => {
                println!("Plik nie istnieje: {}", nazwa_pliku)
            }
            Blad::PlikZbytDuzy(aktualny_rozmiar , maksymalny_rozmiar) => {
                println!("Plik zbyt duzy: {}/{} bajtow", aktualny_rozmiar , maksymalny_rozmiar)
            }
        }
    }
}

fn main() {

    // test

    let blad1 = Blad::BrakBledu;
    let blad2 = Blad::ZlyFormatPliku;
    let blad3 = Blad::PlikNieIstnieje("UMCS.txt".to_string());
    let blad4 = Blad::PlikZbytDuzy(317,256);
    blad1.pokaz_komunikat();
    blad2.pokaz_komunikat();
    blad3.pokaz_komunikat();
    blad4.pokaz_komunikat();
}
