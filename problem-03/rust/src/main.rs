use primes;

fn main() {
    println!("Solution #3: {}", solution(600851475143));
}

fn solution(n: u64) -> u64 {
    return *primes::factors_uniq(n).last().unwrap();
}
