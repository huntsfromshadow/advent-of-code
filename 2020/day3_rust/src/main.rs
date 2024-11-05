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
    let r = load_data(INPUT_FILE);
    let w = WoodMap::new(r);
    //println!("{:?}", w);

    // Now lets actually do the logic
    let endy = w.template_h;

    let vs = vec!((1, 1), (3, 1), (5, 1), (7, 1), (1, 2));
    for s in vs {
        let mut tx = 1;
        let mut ty = 1;

        let slopex = s.0;
        let slopey = s.1;

        let mut treehit = 0;

        while (ty < endy) {
            // move by slope
            tx = tx + slopex;
            ty = ty + slopey;

            let c = w.get_element(tx, ty);
            //println!("Accessing {},{} -> {}",tx,ty,c);

            let c = w.get_element(tx, ty);
            if (c == '#') {
                treehit = treehit + 1;
            }
        }

        println!("Done. ({},{}) - Trees Hit - {}", slopex, slopey, treehit);
    }
}
