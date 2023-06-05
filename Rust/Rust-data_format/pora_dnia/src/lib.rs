struct PoraDnia {
    h: i32,
    min: i32,
    s: i32,
}

impl PoraDnia {
    fn new(h: i32, min: i32, s: i32) -> Self {
        PoraDnia { h, min, s }
    }


    fn h(&self) -> i32{
        self.h
    }

    fn min(&self) -> i32{
        self.min
    }

    fn s(&self) -> i32{
        self.s
    }



    fn as24h(&self) -> String {
        format!("{:02}:{:02}:{:02}", self.h, self.min, self.s)
    }

    fn as12h(&self) -> String {
        let hour = if self.h % 12 == 0 { 12 } else { self.h % 12 };
        let period = if self.h < 12 { "AM" } else { "PM" };
        format!("{:01}:{:02}:{:02} {}", hour, self.min, self.s, period)
    }
}

impl PartialEq for PoraDnia {
    fn eq(&self, other: &Self) -> bool {
        self.h == other.h && self.min == other.min && self.s == other.s
    }
}

impl PartialOrd for PoraDnia {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some((self.h, self.min, self.s).cmp(&(other.h, other.min, other.s)))
    }
}

use std::ops::{Add, Sub};

impl Add for PoraDnia {
    type Output = PoraDnia;

    fn add(self, other: PoraDnia) -> PoraDnia {
        let mut result = PoraDnia::new(0, 0, 0);
        result.s = (self.s + other.s) % 60;
        let carry_mins = (self.s + other.s) / 60;
        result.min = (self.min + other.min + carry_mins) % 60;
        let carry_hours = (self.min + other.min + carry_mins) / 60;
        result.h = (self.h + other.h + carry_hours) % 24;
        result
    }
}

impl Sub for PoraDnia {
    type Output = PoraDnia;

    fn sub(self, other: PoraDnia) -> PoraDnia {
        let mut result = PoraDnia::new(0, 0, 0);
        let self_secs = self.s + self.min * 60 + self.h * 3600;
        let other_secs = other.s + other.min * 60 + other.h * 3600;
        let diff_secs = (self_secs - other_secs + 24 * 3600) % (24 * 3600);
        result.h = diff_secs / 3600;
        result.min = (diff_secs % 3600) / 60;
        result.s = (diff_secs % 3600) % 60;
        result
    }
}

fn main() {
    let pd1 = PoraDnia::new(10, 30, 15);
    let pd2 = PoraDnia::new(8, 45, 20);

    println!("pd1 == pd2: {}", pd1 == pd2);
    println!("pd1 < pd2: {}", pd1 < pd2);

    let pd3 = pd1 + pd2;
    let pd4 = pd1 - pd2;

    println!("pd3 as 24h: {}", pd3.as24h());
    println!("pd3 as 12h: {}",
