fn main() {
    println!("Hello, world! Let's Convert to celsius!");
    let fahr: f64 = 40.0;
    let celsius:f64 = convert_to_celsius(fahr);
    println!("Temperatura: {:.2}°C / {:.2}°F",celsius,fahr);

    let celsius_2:f64 = 32.5;
    let fahr_2 = convert_to_fahr(celsius_2);
    println!("Temperatura: {:.2}°C / {:.2}°F",celsius_2,fahr_2);

}


fn convert_to_celsius(fahr_temp: f64) -> f64{
    (fahr_temp - 32.00) * (5.0/9.0)
}

fn convert_to_fahr(celsius_temp:f64) -> f64{
    (celsius_temp * (9.0/5.0)) + 32.00
}