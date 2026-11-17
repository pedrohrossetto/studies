fn main() {
    println!("Hello, world!");
    let mut fib = fibonacci_better(10);
    println!("The 11th fibonnaci number is {fib}");
}

// Complexidade O(2^n) por que a cada passo, o algoritmo se mulitiplica em dois passos paralelos
fn fibonacci(n: u64) -> u64 {
    if (n > 1) {
        return fibonacci(n - 1) + fibonacci(n - 2);
    } else if n == 1 {
        return 1;
    } else {
        return 0;
    }
}

fn fibonacci_better(n: u64) -> u64 {
    if n == 0 {
        return 0;
    }

    // Variáveis para guardar apenas os dois últimos passos
    // Começa a = 0 e b = 1 por que são os dois menores passos possíves
    let mut a = 0;
    let mut b = 1;

    // O loop repete (n - 1) vezes
    for _ in 1..n {
        let proximo = a + b; // Calcula o próximo número
        a = b; // O 'a' vira o número da frente
        b = proximo; // O 'b' assume o novo valor calculado
    }

    b // retorna b
}
