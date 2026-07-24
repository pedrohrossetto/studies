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
    let mut employee_id = String::new();

    io::stdin().read_line(&mut employee_id).unwrap();

    let salary_base = read_value::<f64>();
    let sales_value = read_value::<f64>();

    let salary = salary_base + sales_value * 0.15;

    println!("TOTAL = R$ {:.2}", salary);
}
