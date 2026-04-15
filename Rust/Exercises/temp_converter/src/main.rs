mod functions;
use functions::convert;

fn main() {
    let t_farenheight: f64 = 80.0;

    let t_celsius = convert(t_farenheight);

    println!("{:.0} degrees F are equal to around {:.0} degrees C.", t_farenheight, t_celsius);
}
