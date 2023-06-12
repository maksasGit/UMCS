use std::collections::LinkedList;
use crate::event::Event;
use crate::date::Date;


pub struct ToDo {
    list: LinkedList<Event>,
}


impl ToDo {
    pub fn new() -> Self {
        ToDo {
            list: LinkedList::new(),
        }
    }

    pub fn add(&mut self, date: Date, description: String) {
        let event = Event { date, description };
        self.list.push_back(event);
    }

    pub fn remove(&mut self, index: usize){
        self.list.remove(index);
    }

    pub fn display(&self) {
        for (index, event) in self.list.iter().enumerate() {
            println!("{} - {} ({})", index + 1, event.get_description(), event.get_date());
        }
    }



}

