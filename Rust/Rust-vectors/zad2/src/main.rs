fn amount(t: &Vec<i32>, el: i32) -> i32 {
    t.iter().filter(|&i| *i == el).count() as i32
}

fn powtorki(t: &Vec<i32>) -> Vec<i32>{
    let mut wynik: Vec<i32> = Vec::new();
    for i in t{
        if amount(t,*i)> 1{
            wynik.push(*i);
        }
    }
    wynik
}

fn main() {
    let vec = vec![1, 3, 4, 3, 3, 3, 3, 4, 1, 1, 6];
    let new_vec = powtorki(&vec);
    for i in new_vec{
        print!("{} ",i);
    }
}
