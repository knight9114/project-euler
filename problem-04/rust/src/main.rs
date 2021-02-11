use palindrome;

fn main() {
    println!("Solution #4: {}", solution_4(100, 1000));
}

fn solution_4(min: i32, max: i32) -> i32 {
    let mut output = 0;

    for x in ((min + 1)..max).rev() {
        for y in (min..(x - 1)).rev() {
            let prod = x * y;
            if !(prod < output) && palindrome::is_palindrome(prod.to_string()) {
                output = prod;
            }
        }
    }

    return output
}
