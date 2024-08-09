pub fn solve(input: &str) -> Option<usize> {
    if let Some((seeds, maps)) = input.split_once("\n\n") {
        let ids = seeds
            .split_ascii_whitespace()
            .filter_map(|id| id.parse::<usize>().ok())
            .collect::<Vec<_>>();

        let maps = maps
            .split("\n\n")
            .map(|m| {
                m.lines()
                    .skip(1)
                    .map(|l| {
                        l.split_ascii_whitespace()
                            .filter_map(|num| num.parse::<usize>().ok())
                            .collect::<Vec<usize>>()
                    })
                    .collect::<Vec<_>>()
            })
            .collect::<Vec<_>>();

        let mut arr = ids
            .chunks_exact(2)
            .map(|ele| ele[0]..(ele[0] + ele[1]))
            .collect::<Vec<_>>();

        for mut map in maps {
            map.sort_unstable_by(|a, b| a[1].cmp(&b[1]));

            let mut idx = 0;
            loop {
                if let None = arr.get_mut(idx) {
                    break;
                }

                let current_range = arr[idx].clone();

                for m in map.iter() {
                    let destination = m[0];
                    let source = m[1];
                    let length = m[2];
                    let range = source..(source + length);

                    let current_start = current_range.start;
                    let current_end = current_range.end - 1;

                    let start_distance = current_start.saturating_sub(source);
                    let end_distance = current_end.saturating_sub(source);

                    if range.contains(&current_start) && range.contains(&current_end) {
                        arr[idx] = (destination + start_distance)..(destination + end_distance);

                        // println!("Range Contained -> {:?}", current_range);
                        // println!("Output Range -> {:?}", arr[idx]);

                        break;
                    } else if range.contains(&current_start) && !range.contains(&current_end) {
                        arr[idx] = (destination + start_distance)..(destination + length);
                        let next_range = (source + length)..current_end + 1;

                        // println!(
                        //     "Start Included, End Excluded -> Split Range: {:?} -> {:?}",
                        //     current_start..source + length,
                        //     next_range
                        // );
                        // println!("Output Range -> {:?}", arr[idx]);

                        arr.insert(idx + 1, next_range);
                        // solved.insert(idx + 1, false);
                        break;
                    } else if !range.contains(&current_start) && range.contains(&current_end) {
                        arr[idx] = (destination)..(destination + end_distance);
                        let next_range = (current_start)..(source);

                        // println!(
                        //     "Start Excluded, End Included -> Split Range: {:?} -> {:?}",
                        //     source..source + end_distance,
                        //     next_range
                        // );
                        // println!("Output Range -> {:?}", arr[idx]);

                        arr.insert(idx + 1, next_range);
                        // solved.insert(idx + 1, false);
                        break;
                    }
                    ()
                }
                idx += 1;
            }
        }

        let result = arr.iter().map(|r| r.start).min().unwrap();

        println!("{}", result);
        Some(result)
    } else {
        None
    }
}