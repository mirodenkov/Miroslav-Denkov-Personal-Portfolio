fn main() {
    let x = 6;
    println!("The value of x is {x}");
    let y = 7;
    println!("The value of y is {y}");

    const THREE_HOURS_IN_SECONDS: u32 = 60 * 60 * 3;
    println!("Three hours is {THREE_HOURS_IN_SECONDS} seconds");

    let a = 5;
    let a = a + 6;

    {
        let a = a * 2;
        println!("The value of a is {a}");
    }

    println!("The value of a is {a}");

    let mut spaces = "   ";
    spaces = spaces.len();
}
