use std::fs;
use std::str::Lines;

fn main() {
    let contents = fs::read_to_string("day1_input.txt").expect("Should be able to read the file");
    //let contents = fs::read_to_string("day1_input.txt").expect("Should be able to read the file");

    // convert to numbers
    let lineint = contents.lines().map(|x| { x.parse::<i32>().unwrap() });

/*    day 1
    for (i, el) in lineint.clone().enumerate() {
        let val = lineint.clone().find(|x1| { return (el + x1) == 2020 });
        if(val.is_some()) {
            println!("{el}");
            let v = val.unwrap();
            println!("{v}");

            println!("{}", el*v);
            return;
        }
    }*/

    for(i, el_1) in lineint.clone().enumerate() {
        for(j, el_2) in lineint.clone().enumerate() {
            if(j == i) {
                continue;
            } else {
                let tot = el_1 + el_2;
                let rem = 2020 - tot;
                let tst = lineint.clone().find(|x1| { *x1 == rem });

                if(tst.is_none()) {
                    continue;
                } else {
                    let f = tst.unwrap();
                    println!("{}, {}, {}", el_1, el_2, tst.unwrap());
                    println!("{}", el_1 * el_2 * tst.unwrap());
                    return;
                }
            }
        }
    }

}
