fn main() {
    let mut x = 5;
    println!("The value of x is: {x}");
    x = 6;
    println!("The value of x is: {x}");

    let x = 10; // "shadowing, ao utilizar let x = ... se está criando uma nova variável x com o mesmo nome."

    // the first variable is shadowed by the second.

    let x = x + 1;

    {
        let x = x * 2;
        println!("The value of x in the inner scope is: {x}");
    }

    println!("The value of x is: {x}");

    let spaces = "   ";
    let spaces = spaces.len();
    // runs
    println!("The length of spaces is: {spaces}");

    let mut spaces = "   ";
    spaces = spaces.len();
    // does not run
    println!("The length of spaces is: {spaces}");
}
