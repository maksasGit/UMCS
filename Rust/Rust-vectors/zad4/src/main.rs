fn indeksy(vec: &Vec<i32>, el: i32) -> Vec<usize> {
    let mut wynik: Vec<usize> = Vec::new();
    for (i, &x) in vec.iter().enumerate() {
        if x == el {
            wynik.push(i);
        }
    }
    wynik
}

fn main() {
    let vec = vec![1, 2, 3, 2, 4, 2, 5];
    let el = 2;
    let wynik = indeksy(&vec, el);
    for i in wynik {
        print!("{} ", i);
    }
}
