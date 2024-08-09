mod part1;
mod part2;

use crate::common::DayData;

const INPUT: &str = include_str!("./day5-input.txt");
//const INPUT: &str = include_str!("./test-input.txt");
//const EXPECTED_PART1: &str = include_str!("./expected_part1.txt");
//const EXPECTED_PART2: &str = include_str!("./expected_part2.txt");

pub fn solve() -> DayData {
    //let part1_answer = part1::solve(INPUT);
    let part2_answer = part2::solve(INPUT);

    DayData {
        name: "Day 5: If You Give A Seed A Fertilizer".to_string(),
        part1_answer: "".to_string(),
        part1_correct: false, /*part1_answer == EXPECTED_PART1,*/
        part2_answer: "".to_string(),
        part2_correct: false, /*part2_answer == EXPECTED_PART2,*/
    }
}