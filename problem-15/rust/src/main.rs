fn main() {
    println!("Solution #15: {}", solution(20, 20));
}

fn solution(n_rows: u64, n_cols: u64) -> u64 {
    return n_choose_k(n_rows + n_cols, n_cols)
}

fn n_choose_k(n: u64, k: u64) -> u64 {
    // Prepare
    let mut prod: u64 = 1;

    // Load
    for i in 1..=k {
        prod *= n - k + i;
        prod /= i;
    }

    return prod
}
