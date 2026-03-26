fn main() {
    println!("Hello, world!");
    let f: u32 = 6;
    let n = fibonacci_seq(f);

    println!("F{f} is {n}");
}

fn fibonacci_seq(n: u32) -> u32 {
    if n == 0 {
        return 0;
    } else if n == 1 {
        return 1;
    } else {
        fibonacci_seq(n - 1) + fibonacci_seq(n - 2)
    }
}
