struct Fibonacci {
    curr: i64,
    next: i64,
}

impl Iterator for Fibonacci {
    type Item = i64;
    fn next(&mut self) -> Option<Self::Item> {
        let update = self.curr + self.next;
        self.curr = self.next;
        self.next = update;

        return Some(self.curr)
    }
}

fn main() {
    println!("Solution #2: {}", solution_2(4_000_000));
}

fn solution_2(n: i64) -> i64 {
    let fib = Fibonacci{curr: 0, next: 1};
    return fib
        .take_while(|&x| x < n)
        .filter(|&x| x % 2 == 0)
        .fold(0i64, |acc, x| acc + x)
}
