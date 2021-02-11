fn main() {
    println!("Solution #6: {}", solution(100));
}

fn sum_of_squares(n: i32) -> i32 {
    return n * (n + 1) * (2*n + 1) / 6
}

fn square_of_sum(n: i32) -> i32 {
    let sum = n * (n + 1) / 2;
    return sum * sum
}

fn solution(n: i32) -> i32 {
    return square_of_sum(n) - sum_of_squares(n)
}
