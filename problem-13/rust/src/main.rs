use std::io::{BufRead, BufReader};
use std::fs::{File};

fn main() {
    let path = "/home/knight/Documents/github/project-euler/problem-13/input.txt";
    println!("Solution #13: {:?}", solution(path, 10));
}

fn solution(path: &str, n: u64) -> u64 {
    let n_digits_expanded = (n + ((n as f32).log10() as u64 + 1)) as usize;
    let output = BufReader::new(File::open(path).expect("failed to open file"))
        .lines()
        .map(|line| line.unwrap()[0..n_digits_expanded].parse::<u64>().unwrap())
        .sum::<u64>()
        .to_string()
        .as_str()[0..n as usize]
        .parse::<u64>()
        .unwrap();

    return output
}
