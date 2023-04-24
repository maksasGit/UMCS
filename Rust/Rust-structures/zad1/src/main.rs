struct RGB {
    red: u8,
    green: u8,
    blue: u8,
}

impl RGB {

    fn brightness(&self) -> f32 {
        (self.red as f32 + self.green as f32 + self.blue as f32) / 3.0
    }

    fn from_3u8(red: u8, green: u8, blue: u8) -> RGB {
        RGB { red, green, blue }
    }

    fn from_f32(red: f32, green: f32, blue: f32) -> RGB {
        RGB {
            red: (red * 255.0) as u8,
            green: (green * 255.0) as u8,
            blue: (blue * 255.0) as u8,
        }
    }

    fn from_html(hex: &str) -> RGB {
        let hex = hex.trim_start_matches('#');
        let red = u8::from_str_radix(&hex[0..2], 16).unwrap();
        let green = u8::from_str_radix(&hex[2..4], 16).unwrap();
        let blue = u8::from_str_radix(&hex[4..6], 16).unwrap();
        RGB { red, green, blue }
    }

    fn black() -> RGB {
        RGB { red: 0, green: 0, blue: 0 }
    }

    fn white() -> RGB {
        RGB { red: 255, green: 255, blue: 255, }
    }

    fn red() -> RGB {
        RGB { red: 255, green: 0, blue: 0 }
    }

    fn green() -> RGB {
        RGB { red: 0, green: 255, blue: 0 } 
    }

    fn blue() -> RGB {
        RGB { red: 0, green: 0, blue: 255 }
    }
}

fn main() {
    let rgb1 = RGB::from_3u8(255, 128, 0);
    println!("RGB1: {}, {}, {}", rgb1.red, rgb1.green, rgb1.blue);
    let rgb2 = RGB::from_f32(1.0, 0.5, 0.0);
    println!("RGB2: {}, {}, {}", rgb2.red, rgb2.green, rgb2.blue);
    let rgb3 = RGB::from_html("#FF0000");
    println!("RGB3: {}, {}, {}", rgb3.red, rgb3.green, rgb3.blue);
    let black = RGB::black();
    println!("Black: {}, {}, {}", black.red, black.green, black.blue);
    let white = RGB::white();
    println!("White: {}, {}, {}", white.red, white.green, white.blue);
    let red = RGB::red();
    println!("Red: {}, {}, {}", red.red, red.green, red.blue);
    let green = RGB::green();
    println!("Green: {}, {}, {}", green.red, green.green, green.blue);
    let blue = RGB::blue();
    println!("Blue: {}, {}, {}", blue.red, blue.green, blue.blue);
    println!("{}" , blue.brightness());
}