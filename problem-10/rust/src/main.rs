use primes::{Sieve, PrimeSet};

fn main() {
    println!("Solution #10: {}", solution(2_000_000));
}

fn solution(n: u64) -> u64 {
    return Sieve::new()
        .iter()
        .take_while(|&x| x < n)
        .fold(0, |acc, prime| acc + prime)
}
