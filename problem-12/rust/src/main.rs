fn main() {
    println!("Solution #12: {:?}", solution(500));
}

fn solution(n: u64) -> u64 {
    // Prepare
    let mut output = 0;

    // Search
    for i in 0.. {
        // Handle Summation
        let n_factors = match i % 2 {
            0 => count_factors(i / 2, 2) * count_factors(i + 1, 2),
            1 => count_factors(i, 2) * count_factors((i + 1) / 2, 2),
            _ => u64::MAX,
        };

        // Break
        if n_factors > n {
            output = i * (i + 1) / 2;
            break;
        }
    }

    return output
}

fn count_factors(mut n: u64, start: u64) -> u64 {
    // Base Case
    if n == 1 {
        return 1
    }

    // Recursively Count Factors
    for i in start..sqrt(n) {
        if n % i == 0 {
            let mut n_factors = 1;

            while n % i == 0 {
                n /= i;
                n_factors += 1;
            }

            return count_factors(n, i + 1) * n_factors
        }
    }

    return 2
}

fn sqrt(n: u64) -> u64 {
    return ((n as f64).sqrt() as u64) + 1
}
