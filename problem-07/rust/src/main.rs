use primes::{Sieve, PrimeSet};

fn main() {
    println!("Solution #7: {}", solution(10_001));
}

fn solution(n: i32) -> i32 {
    let mut primes = Sieve::new();
    return primes.iter().skip((n - 1) as usize).next().unwrap() as i32
}
