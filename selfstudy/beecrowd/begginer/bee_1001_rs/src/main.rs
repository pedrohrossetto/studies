/*

Read 2 variables, named A and B and make the sum of these two variables, assigning its result to the variable X.
Print X as shown below.
Print endline after the result otherwise you will get “Presentation Error”.

The input file will contain 2 integer numbers.

Print the letter X (uppercase) with a blank space before and after the equal signal followed by the value of X, according to the following example.
sample: io 10,9. o "X = 10"

*/

use std::io;

fn main() {
let mut input_a = String::new();
let mut input_b = String::new();

io::stdin().read_line(&mut input_a).unwrap();
io::stdin().read_line(&mut input_b).unwrap();

let a: i32 = input_a.trim().parse().unwrap();
let b: i32 = input_b.trim().parse().unwrap();

println!("X = {}", a + b);
}