fn main() {

    //Let's make a tuple 

    let tuple: (i32, &str, bool) = (67, "I am in a tuple :D", true);

    /*Let's access the data in the tuple*/
    println!("tuple.0 is {0}", tuple.0);
    println!("Accessing data in tuple.1:{0}",tuple.1);

    let arr: [i32;2] = [5,3];
    println!("{} {}",arr[0], arr[1]);
}
