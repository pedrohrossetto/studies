use std::io;

fn main() {
let mut input_a = String::new();
let mut input_b = String::new();


io::stdin().read_line(&mut input_a).unwrap();
io::stdin().read_line(&mut input_b).unwrap();


let mut a: f64 = input_a.trim().parse().unwrap();
let mut b: f64 = input_b.trim().parse().unwrap();


a = a * 3.5;
b = b * 5.5;

let media:f64 = (a+b) / (3.5 + 5.5);

println!("MEDIA = {:.1}", media);
}