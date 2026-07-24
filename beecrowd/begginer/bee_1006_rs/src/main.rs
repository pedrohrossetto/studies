use std::io;

/// Calcula a média ponderada para qualquer lista de tuplas (nota, peso)
fn media_ponderada(itens: &[(f64, f64)]) -> f64 {
    let mut soma_produtos = 0.0;
    let mut soma_pesos = 0.0;

    for &(valor, peso) in itens {
        soma_produtos += valor * peso;
        soma_pesos += peso;
    }

    if soma_pesos == 0.0 {
        return 0.0;
    }

    // Expressão de retorno (sem ponto e vírgula final)
    soma_produtos / soma_pesos
}

fn read_value<T>() -> T
where
    T: std::str::FromStr,    // Caminho completo
    T::Err: std::fmt::Debug, // Caminho completo
{
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();
    buffer.trim().parse().unwrap()
}

fn main() {
    // Lê qualquer tipo reaproveitando a mesma função helper
    let a = read_value::<f64>();
    let b = read_value::<f64>();
    let c = read_value::<f64>();

    let media = media_ponderada(&[(a, 2.0), (b, 3.0), (c,5.0)]);

    println!("MEDIA = {:.1}", media); 
}