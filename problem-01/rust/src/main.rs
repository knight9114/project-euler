fn main() {
    println!("Solution #1: {}", solution_1(1000));
}

fn solution_1(n: u32) -> u32 {
    let mut output = 0;

    for x in 0..n {
        if x % 3 == 0 || x % 5 == 0 {
            output += x;
        }
    }

    return output
}
