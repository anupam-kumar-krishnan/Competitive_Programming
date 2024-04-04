
// fibonnaci function

fn fibonnaci(n: u32) -> u32 {
    if n == 0 {
        return 0;
    } else if n == 1 {
        return 1;
    } else {
        return fibonnaci(n - 1) + fibonnaci(n - 2);
    }
}



fn main() {
    let n = 10;
    println!("Fibonnaci of {} is {}", n, fibonnaci(n));
}
```
