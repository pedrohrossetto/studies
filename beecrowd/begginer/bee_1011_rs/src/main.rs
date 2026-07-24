fn main() {
    const PI_VALUE: f64 = 3.14159;

    let mut input_radius = String::new();

    std::io::stdin().read_line(&mut input_radius).unwrap();

    let radius: f64 = input_radius.trim().parse().unwrap();

    let volume: f64 = (4.0 / 3.0) * PI_VALUE * radius.powi(3);
    println!("VOLUME = {:.3}", volume);
}
