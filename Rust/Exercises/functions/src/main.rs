fn main() {
    new_function();
    println!("Hello, world!");

    parameter_function(6447);

    measure_func(5, "seconds");

    let y = {
        let x = 3;
        x + 1
    };

    println!("The value of y is {y}");

    let x = five();

    println!("The value of x is {x}");
}
fn new_function() {
    println!("Hello from function!!");
}

fn parameter_function(x: i32) {
    println!("The value of x is {x}");
}

fn measure_func(x: i32, unit: &str) {
    println!("Measured {x} {unit}");
}

fn five() -> i32 {
    5
}
