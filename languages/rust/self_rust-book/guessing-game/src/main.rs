use std::io; // standard imput/output
use rand::Rng;
use std::cmp::Ordering; // standard : compare : Ordering as Ordering

fn main() {
    println!("Guess the number!");
    // criando número aleatório antes de iniciar o loop
    let secret_number = rand::thread_rng().gen_range(1..=100); // gen.range(range), range sintaxe = "inicio..=fim" limites inclusivos
    loop { 
        println!("Please, input you guess:");

        // criando com let uma variavel mutável (mut) chamada guess,
        // inicializando como uma string vazia 
        let mut guess = String::new(); 

        // bloco de recebimento de input
        // io:stdin -> use std::io, sem isso seria std::io:stdin()
        io::stdin()
            .read_line(&mut guess) // chama a função read_line do stdin(), passando uma referencia (&) (por padrão imutável) de destino com flag de mutável (mut) e seu nome (guess)
            .expect("Failed to read a line"); // método de falha do stdin(), passando uma string de mensagem padrão
        
        // acima equivalente a: io::stdin().read_line(&mut guess).expect("Failed to read line");


        // Linha de conversão após receber input de string:
        // : u32 -> define o tipo do dado, nesse caso 32-bit integer ;
        // = guess.trim() elimina qualquer espaço em branco ou char especial como \n (\n e \r (linux e windows) por padrão em input por que tem que apertar enter)
        // .parse() é o q tenta converter a variável guess para o tipo definido em "let guess:u32 = "
        // .expect(texto) retorna mensagem de erro caso qualquer etapa falhe.
        let guess: u32 = guess.trim().parse().expect("Please type a number!");


        //println!("The secret number is: {secret_number}");

        println!("You guessed: {guess}");

        match guess.cmp(&secret_number) {
            Ordering::Less => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal => {
                println!("You win!");
                break;
            }
        }
    }
}
