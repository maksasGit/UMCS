struct Student {
    first_name: String,
    last_name: String,
    birth_year: u32,
    subject: String,
}

impl Student {
    fn new(first_name: String, last_name: String, birth_year: u32, subject: String) -> Self {
        Student {
            first_name,
            last_name,
            birth_year,
            subject,
        }
    }

    fn get_first_name(&self) -> &str {
        &self.first_name
    }

    fn get_last_name(&self) -> &str {
        &self.last_name
    }

    fn get_birth_year(&self) -> u32 {
        self.birth_year
    }

    fn get_subject(&self) -> &str {
        &self.subject
    }

    fn set_first_name(&mut self, first_name: String) {
        self.first_name = first_name;
    }

    fn set_last_name(&mut self, last_name: String) {
        self.last_name = last_name;
    }

    fn set_subject(&mut self, subject: String) {
        self.subject = subject;
    }

    fn is_older(&self, other: &Student) -> bool {
        self.birth_year < other.birth_year
    }

    fn same_subject(&self, other: &Student) -> bool {
        self.subject == other.subject
    }
}

fn main() {

    // SET and GET
    
    let mut student_alex = Student::new("Alex".to_string() , "Madry".to_string() , 1999, "Nucklear Phisics".to_string());
    println!("Get name: {} {}", student_alex.get_first_name(), student_alex.get_last_name());
    student_alex.set_first_name("Pawel".to_string());
    println!("Get name: {} {}", student_alex.get_first_name(), student_alex.get_last_name());
    println!("Get info: {} {}",student_alex.get_birth_year(), student_alex.get_subject());
    student_alex.set_subject("Math".to_string());
    println!("Get info: {} {}",student_alex.get_birth_year(), student_alex.get_subject());
    // funkcje

    let student_maksim = Student::new("Maksim".to_string(), "Ryshko".to_string(), 2005, "Computer Science".to_string());
    let student_ala = Student::new("Ala".to_string(), "Ma-Kota".to_string(), 1900, "Philosophy".to_string());
    println!("Funkcja, ktora odpowiada na pytanie, czy pewien student jest starszy od innego studenta: {}", student_maksim.is_older(&student_ala));
    println!("Funkcjc, ktora odpowiada na pytanie, czy pewien student studiuje ten sam kierunek co inny student: {}", student_maksim.same_subject(&student_ala));
}
