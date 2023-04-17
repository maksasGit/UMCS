fn amount(t: &Vec<i32>, el: i32) -> i32 {
    t.iter().filter(|&i| *i == el).count() as i32
}


fn unikalne(t: &Vec<i32>) -> Vec<i32> {
    t.iter().filter(|&i| amount(t, *i) == 1).copied().collect()
}

fn main() {
    let vec: Vec<i32> = vec![1, 3, 4, 3, 3, 5, 3, 4, 1, 1, 6];
    let new_vec = unikalne(&vec);
    for i in new_vec {
        print!("{} ", i);
    }
}