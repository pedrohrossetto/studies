fn main() {

    // Teste de if
    let condition:bool = true;
    let number = if condition { 5 } else { 30 };
    println!("{}",number);

    if number % 4 == 0 {
        println!("number is divisible by 4");
    } else if number % 3 == 0 {
        println!("number is divisible by 3");
    } else if number % 2 == 0 {
        println!("number is divisible by 2");
    } else {
        println!("number is not divisible by 4, 3, or 2");
    }

    println!("End of block 1");

    if number % 4 == 0 {
        println!("number is divisible by 4");
    } if number % 3 == 0 {
        println!("number is divisible by 3");
    } if number % 2 == 0 {
        println!("number is divisible by 2");
    } else {
        println!("number is not divisible by 4, 3, or 2");
    }

    // Teste de loop
    let mut counter: u32 = 0;
    loop{
        println!("Again!");
        counter += 1;
        if counter == 10 {
            counter *= 2;
            break;
        }
    };
    println!("{}", counter);
    counter = 0;
    'tier1: loop {
        println!("count = {}", counter);
        let mut remaining = 10;
        'tier2: loop {
            println!("remaining = {}",remaining);
            if remaining == 9 {
                break;
            }
            if counter == 2 {
                break 'tier1;
            }
            remaining -= 1;
        }
        counter += 1;
    }
    println!("End count = {}",counter);


    for number in (1..4).rev() {
        println!("{}!",number);
    }
    println!("LIFTOFF!!!");
}