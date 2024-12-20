//use std::time::Instant;
//use std::vec;
//use crate::common::DayData;

mod common;
mod day05;

/*fn print_table(days: Vec<DayData>) {
    println!("╔{}╗", "═".repeat(67));
    println!("║ {:^63} ║", "🦀 Advent of Code 2023 🦀");
    println!(
        "╠{}╦{}╦{}╦{}╣",
        "═".repeat(23),
        "═".repeat(14),
        "═".repeat(15),
        "═".repeat(12)
    );
    println!(
        "║ {:<21} ║ {:<7}      ║ {:<8}      ║ {:<07}    ║",
        "Day", "Part 1", "Part 2", "Time"
    );
    println!(
        "╠{}╬{}╦{}╬{}╦{}╬{}╣",
        "═".repeat(23),
        "═".repeat(9),
        "═".repeat(4),
        "═".repeat(10),
        "═".repeat(4),
        "═".repeat(12)
    );

    for day in days {
        let start = Instant::now();
        let result = day.;
        let duration = start.elapsed();
        let part1_symbol = if result.part1_correct { "✅" } else { "❌" };
        let part2_symbol = if result.part2_correct { "✅" } else { "❌" };

        println!(
            "║ {:<21} ║ {:<7} ║ {} ║ {:<8} ║ {} ║ {:<07} μs ║",
            result.name,
            result.part1_answer,
            part1_symbol,
            result.part2_answer,
            part2_symbol,
            duration.as_micros()
        );
    }

    println!(
        "╚{}╩{}╩{}╩{}╩{}╩{}╝",
        "═".repeat(23),
        "═".repeat(9),
        "═".repeat(4),
        "═".repeat(10),
        "═".repeat(4),
        "═".repeat(12)
    );
}
*/
pub fn main() {
    //let days: Vec<_> = vec![
    //    day05::solve(),
    //];

    //print_table(days);
    day05::solve();
}