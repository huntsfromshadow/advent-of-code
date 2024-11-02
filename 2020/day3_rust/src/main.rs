mod wood_map;

use std::fs;
use crate::wood_map::WoodMap;

const TEST_FILE: &str = "test_input.txt";
const INPUT_FILE: &str = "day3_input.txt";

pub fn load_data(filename: &str) -> String {
    let r = fs::read_to_string(filename).expect("Have real file");
    // Break into line split
    r
}

fn main() {
    let r = load_data(TEST_FILE);
    let w = WoodMap::new(r);
    println!("{:?}", w);

    // Now lets actually do the logic
    let mut tx = 0;
    let mut ty = 0;
    let endy = w.template_h + 1;

    let mut treehit = 0;

    let slopex = 3;
    let slopey = 1;

    while (ty < endy) {
        // move by slope
        tx = tx + slopex;
        ty = ty + slopey;

        println!("Accessing {},{}",tx,ty);

        let c = w.get_element(tx,ty);
        if(c == '#') {
            treehit = treehit + 1;
        }
    }

    println!("Done. Trees Hit - {}", treehit);
}
