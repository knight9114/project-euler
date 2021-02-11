fn main() {
    println!("Solution #9: {}", solution(1000));
}

fn solution(n: i32) -> i32 {
    for a in 1..n {
        for b in 1..n {
            for c in 1..n {
                if is_pythagorean_triple(a,b,c) && ((a + b + c) == n) {
                    return a * b * c
                }
            }
        }
    }

    return 0
}

fn is_pythagorean_triple(a: i32, b: i32, c: i32) -> bool {
    return ((a * a) + (b * b)) == (c * c)
}
