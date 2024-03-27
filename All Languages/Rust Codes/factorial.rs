

// Factorial recursive function
def factorial_recursive(n: i32) -> i32 {
    if n == 0 {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}



// Factorial iterative function
def factorial_iterative(n: i32) -> i32 {
    let mut result = 1;
    for i in 1..=n {
        result *= i;
    }
    return result;
}






fn main() {
    // test the factorial_recursive function
    let n = 5;
    println!("Recursive Factorial of {} is {}", n, factorial_recursive(n));
    // test the factorial_iterative function
    println!("Iterative Factorial of {} is {}", n, factorial_iterative(n));
}
