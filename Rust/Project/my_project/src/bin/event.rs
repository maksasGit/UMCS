pub struct Event {
    date: Date,
    description: String,
}

impl Event {
    pub fn new(date: Date, description: String) -> Self {
        Event { date, description }
    }

    pub fn get_date(&self) -> &Date {
        &self.date
    }

    pub fn get_description(&self) -> &str {
        &self.description
    }
}