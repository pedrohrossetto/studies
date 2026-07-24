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
    let a = read_value::<i32>();
    let b = read_value::<i32>();
    let c = read_value::<i32>();
    let d = read_value::<i32>();

    let diferenca: i32 = a * b - c * d;
    println!("DIFERENCA = {}", diferenca);
}
