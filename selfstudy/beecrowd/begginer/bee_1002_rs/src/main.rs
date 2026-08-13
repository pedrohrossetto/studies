use std::io;

fn main() {
    const PI_VALUE:f64 = 3.14159;

    let mut input_radius = String::new();

    io::stdin().read_line(&mut input_radius).unwrap();

    let radius: f64 = input_radius.trim().parse().unwrap();

    let area_circ:f64  = PI_VALUE * radius.powi(2);

    println!("A={:.4}",area_circ);
    
}