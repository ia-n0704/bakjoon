use std::io;
use rand::Rng;

fn main()
{
    let mut guess=String::new();
    io::stdin().read_line(&mut guess)
        .expect("failed to read line");
    println!("Output : {}",guess);
    let a=123;
    let mut b=a;
    println!("a : {} \nb : {}",a,b);
}