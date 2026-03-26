pub fn convert(t_farenheight: f64) -> f64 {
    /*°C equals °F minus 32, divided by 9/5.

    °C = (°F - 32) ÷ (9/5)

    */

    (t_farenheight - 32.0) / (9.0 / 5.0)
}
