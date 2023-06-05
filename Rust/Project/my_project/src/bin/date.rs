
pub struct Date {
    year: i32,
    month: u32,
    day: u32,
}

impl Date {
    pub fn new(year: i32, month: u32, day: u32) -> Option<Self> {
        if Self::is_valid_date(year, month, day) {
            Some(Date { year, month, day })
        } else {
            None
        }
    }

    fn is_valid_date(year: i32, month: u32, day: u32) -> bool {
        if year < 0 || month < 1 || month > 12 || day < 1 {
            return false;
        }

        let max_days = match month {
            1 | 3 | 5 | 7 | 8 | 10 | 12 => 31,
            4 | 6 | 9 | 11 => 30,
            2 => {
                if year % 4 == 0 && (year % 100 != 0 || year % 400 == 0) {
                    29
                } else {
                    28
                }
            }
            _ => return false,
        };

        day <= max_days
    }
}

impl fmt::Display for Date {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{:04}-{:02}-{:02}", self.year, self.month, self.day)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_valid_date() {
        assert!(Date::new(2023, 6, 5).is_some());
    }

    #[test]
    fn test_invalid_date() {
        assert!(Date::new(2023, 13, 32).is_none());
        assert!(Date::new(-1, 6, 5).is_none());
        assert!(Date::new(2023, 2, 30).is_none());
    }

    #[test]
    fn test_display_format() {
        let date = Date::new(2023, 6, 5).unwrap();
        assert_eq!(format!("{}", date), "2023-06-05");
    }
}