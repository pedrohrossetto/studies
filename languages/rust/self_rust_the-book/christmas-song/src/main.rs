fn main() {
    let presents: [&str; 12] = [
        "And a partridge in a pear tree.",
        "Two turtle doves",
        "Three French hens",
        "Four calling birds",
        "Five golden rings",
        "Six geese a-laying",
        "Seven swans a-swimming",
        "Eight maids a-milking",
        "Nine ladies dancing",
        "Ten lords a-leaping",
        "Eleven pipers piping",
        "Twelve drummers drumming",
    ];
    the_twelve_days_of_christmas(presents);
}

fn numero_ordinal(n: u32) -> String {
    // Regra especial para o grupo dos "teens" (11th, 12th, 13th) em inglês
    let sufixo = match (n % 100) {
        11 | 12 | 13 => "th",
        _ => match n % 10 {
            1 => "st",
            2 => "nd",
            3 => "rd",
            _ => "th",
        },
    };

    format!("{}{}", n, sufixo)
}

fn the_twelve_days_of_christmas(list_presents: [&str; 12]) {
    for day in 1..=list_presents.len() {
        if day == 1 {
            println!(
                "On the {} day of Christmas,\nmy true love sent to me",
                numero_ordinal(day as u32) // Convertendo usize para u32 se o seu numero_ordinal pedir u32
            );
            println!("A partridge in a pear tree.");
        } else {
            println!(
                "On the {} day of Christmas,\nmy true love sent to me",
                numero_ordinal(day as u32) // Convertendo usize para u32 se o seu numero_ordinal pedir u32
            );
            day_christmas(day as usize, list_presents);
        }
        println!("");
    }
}

fn day_christmas(day: usize, list_presents: [&str; 12]) {
    if day == 0 {
        return;
    } else {
        println!("{}", list_presents[day - 1]);
    }
    day_christmas(day - 1, list_presents);
}
