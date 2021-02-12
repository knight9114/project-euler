fn main() {
    println!("Solution #12: {:?}", solution(500));
}

fn solution(n: u64) -> u64 {
    return Triangle::new()
        .skip_while(|&x| get_num_factors(x) <= n)
        .next()
        .unwrap()
}

fn get_num_factors(n: u64) -> u64 {
    return (1..n + 1).into_iter().filter(|&x| n % x == 0).collect::<Vec<u64>>().len() as u64
}

struct Triangle {
    index: u64,
    total: u64,
}

impl Triangle {
    fn new() -> Triangle {
        return Triangle{index: 0, total: 0}
    }
}

impl Iterator for Triangle {
    type Item = u64;

    fn next(&mut self) -> Option<Self::Item> {
        // Update State
        self.index += 1;
        self.total += self.index;

        return Some(self.total)
    }
}
