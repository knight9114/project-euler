fn main() {
    println!("Test: {}", solution(20));
}

fn solution(max_mod: i32) -> i32 {
    let mut output = max_mod;

    'outer: for x in (max_mod..).step_by(max_mod as usize) {
        for y in (1..=max_mod).rev() {
            if x % y != 0 {
                continue 'outer;
            }
        }

        output = x;
        break;
    }

    return output
}
