use std::fs;

fn main() {
    let path: &str = "/home/knight/Documents/github/project-euler/problem-08/input.txt";
    println!("Solution #8: {}", solution(13, path));
}

fn solution(n: i32, path: &str) -> u64 {
    return fs::read_to_string(path)
        .unwrap()
        .chars()
        .filter_map(|c| c.to_digit(10))
        .map(|x| x as u64)
        .collect::<Vec<_>>()
        .windows(n as usize)
        .map(|window| window.iter().product())
        .max()
        .unwrap()
}
