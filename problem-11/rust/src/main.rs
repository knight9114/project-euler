use std::fs::File;
use std::io::{BufRead, BufReader, Error};
use std::cmp;

fn main() {
    let path = "/home/knight/Documents/github/project-euler/problem-11/input.txt";
    println!("Solution #11: {:?}", solution(path, 20, 20, 4).unwrap());
}

fn solution(path: &str, n_rows: u32, n_cols: u32, length: u32) -> Result<u64, Error> {
    // Read File
    let matrix: Vec<Vec<u32>> = BufReader::new(File::open(path)?)
        .lines()
        .map(|line| {
            line
                .unwrap()
                .split_whitespace()
                .filter_map(|s| s.parse().ok())
                .collect()
        })
        .collect();
         
    // Search
    let mut output = 0u64;
    for r in 0..n_rows {
        for c in 0..n_cols {
            // Vertical
            if r < n_rows - length {
                output = cmp::max(output, vertical(r, c, length, &matrix));
            }

            // Horizontal
            if c < n_cols - length {
                output = cmp::max(output, horizontal(r, c, length, &matrix));
            }

            // Diagonal "\"
            if r < n_rows - length && c < n_cols - length {
                output = cmp::max(output, diagonal_1(r, c, length, &matrix));
            }

            // Diagonal "/"
            if r < n_rows - length && c > length - 1 {
                output = cmp::max(output, diagonal_2(r, c, length, &matrix));
            }
        }
    }

    return Ok(output)
}

fn horizontal(r: u32, c: u32, n: u32, matrix: &Vec<Vec<u32>>) -> u64 {
    // Prepare
    let mut prod = 1u64;

    // Find
    for i in 0..n {
        prod *= matrix[r as usize][(c + i) as usize] as u64;
    }

    return prod
}

fn vertical(r: u32, c: u32, n: u32, matrix: &Vec<Vec<u32>>) -> u64 {
    // Prepare
    let mut prod = 1u64;

    // Find
    for i in 0..n {
        prod *= matrix[(r + i) as usize][c as usize] as u64;
    }

    return prod
}

fn diagonal_1(r: u32, c: u32, n: u32, matrix: &Vec<Vec<u32>>) -> u64 {
    // Prepare
    let mut prod = 1u64;

    // Find
    for i in 0..n {
        prod *= matrix[(r + i) as usize][(c + i) as usize] as u64;
    }

    return prod
}

fn diagonal_2(r: u32, c: u32, n: u32, matrix: &Vec<Vec<u32>>) -> u64 {
    // Prepare
    let mut prod = 1u64;

    // Find
    for i in 0..n {
        prod *= matrix[(r + i) as usize][(c - i) as usize] as u64;
    }

    return prod
}
