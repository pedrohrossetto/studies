use std::io;

fn read_value<T>() -> T
where
    T: std::str::FromStr,
    T::Err: std::fmt::Debug,
{
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();
    buffer.trim().parse().unwrap()
}

fn main() {
    // Lê qualquer tipo reaproveitando a mesma função helper
    let employee_id = read_value::<i32>();
    let total_hours = read_value::<i32>();
    let pay_per_hour = read_value::<f64>();

    let salary = total_hours as f64 * pay_per_hour;

    println!("NUMBER = {}", employee_id);
    println!("SALARY = U$ {:.2}", salary);
}
