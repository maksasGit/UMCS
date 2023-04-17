fn zlicz_wielie(s1: &Vec<i32>, s2: &Vec<i32>) -> usize{
    let mut wynik:usize = 0;
    for i in s1{
        for j in s2{
            if i == j{
                wynik += 1;
            }
        }
    } 
    wynik
}

fn main() {
    let  vec1 = vec![1, 2, 1, 3];
    let  vec2 = vec![1, 2, 2, 1];
    println!("{}" , zlicz_wielie(&vec1, &vec2));

}
