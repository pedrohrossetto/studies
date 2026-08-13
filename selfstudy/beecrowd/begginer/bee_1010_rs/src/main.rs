fn read_line_tokens() -> Vec<String> {
    use std::io;

    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();

    buffer.split_whitespace().map(|s| s.to_string()).collect()
}

fn parse_token<T>(token: &str) -> T
where
    T: std::str::FromStr,
    T::Err: std::fmt::Debug,
{
    token.parse().unwrap()
}
fn main() {
    struct Produto {
        id: i32,
        quant: i32,
        valor: f64,
    }

    let linha1 = read_line_tokens();
    let linha2 = read_line_tokens();

    let prod1 = Produto {
        id: parse_token(&linha1[0]),
        quant: parse_token(&linha1[1]),
        valor: parse_token(&linha1[2]),
    };

    let prod2 = Produto {
        id: parse_token(&linha2[0]),
        quant: parse_token(&linha2[1]),
        valor: parse_token(&linha2[2]),
    };

    let valor_a_pagar = prod1.quant as f64 * prod1.valor + prod2.quant as f64 * prod2.valor;

    // Exibindo os resultados
    println!("VALOR A PAGAR: R$ {:.2}", valor_a_pagar);
}
