fn main() {
    println!("Solution #14: {}", solution(1_000_000));
}

fn solution(n: u64) -> usize {
    return (0..n)
        .map(|x| Collatz::new(x).count())
        .enumerate()
        .max_by_key(|x| x.1)
        .unwrap()
        .0
}

struct Collatz {
    n: u64,
}

impl Collatz {
    fn new(n: u64) -> Collatz {
        return Collatz{
            n: n,
        }
    }
}

impl Iterator for Collatz {
    type Item = u64;

    fn next(&mut self) -> Option<u64> {
        // Default Case
        if self.n == 0 {
            return None
        }

        // Output Value
        let output = Some(self.n);

        // Update State
        self.n = match self.n {
            1 => 0,
            _ => match self.n % 2 {
                0 => self.n / 2,
                1 => (3 * self.n) + 1,
                _ => 1,
            },
        };
        
        return output
    }
}
