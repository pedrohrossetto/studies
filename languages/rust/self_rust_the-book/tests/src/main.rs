fn main() {
    let x = Box::new(0);

    let y = Box::new(&x);
    println!("{}", { y });
}
01  