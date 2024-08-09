
#[derive(Debug)]
struct Row {
    dest_start: i64,
    //dest_end: i64,
    source_start: i64,
    source_end: i64,
}
impl Row {
    pub fn convert_val(&self, val: i64) -> i64 {
        if val >= self.source_start && val <= self.source_end {
                let diff = val - self.source_start;
            return self.dest_start + diff;
        } else {
            return val;
        }
    }

    pub fn in_sequence(&self, val: i64) -> bool {
        if val >= self.source_start && val <= self.source_end {
            return true;
        } else {
            return false;
        }
    }

    pub fn new(d_start: i64, s_start: i64, len: i64) -> Row {
        Row {
            dest_start: d_start,
            //dest_end: d_start + len - 1,
            source_start: s_start,
            source_end: s_start + len - 1,
        }
    }
}

pub struct Data {
    seed_list: Vec<i64>,
    seed_to_soil: Vec<Row>,
    soil_to_fertilizer: Vec<Row>,
    fertilizer_to_water: Vec<Row>,
    water_to_light: Vec<Row>,
    light_to_temperature: Vec<Row>,
    temperature_to_humidity: Vec<Row>,
    humidity_to_location: Vec<Row>,
}
impl Data {
    pub fn new() -> Data {
        Data {
            seed_list: vec![],
            seed_to_soil: vec![],
            soil_to_fertilizer: vec![],
            fertilizer_to_water: vec![],
            water_to_light: vec![],
            light_to_temperature: vec![],
            temperature_to_humidity: vec![],
            humidity_to_location: vec![],
        }
    }
}

pub fn solve(input: &str) -> String {
    let lines = input.lines();
    //println!("{:?}", lines);

    let mut dat = Data::new();

    let mut mode = 1;
    for l in lines {
        //println!("{}", l);
        if l == "" {
            //println!(" ");
            continue;
        } else if l.contains("seeds:") {
            let sl: Vec<_> = l.replace("seeds:", "").trim().split(" ")
                .map(|s| s.trim())
                .filter(|s| !s.is_empty())
                .map(|s| s.parse().unwrap())
                .collect();

            let mut i = 0;
            while i < sl.len() {
                let v1 = sl[i];
                let v2 = sl[i+1];
                let ns = (v1..=v1 + v2).collect::<Vec<i64>>();
                let _ = &dat.seed_list.extend(ns);
                i = i + 2;
            }
        } else if l.contains("seed-to-soil map:") {
            mode = 2;
        } else if l.contains("soil-to-fertilizer map:") {
            mode = 3;
        } else if l.contains("fertilizer-to-water map:") {
            mode = 4;
        } else if l.contains("water-to-light map:") {
            mode = 5;
        } else if l.contains("light-to-temperature map:") {
            mode = 6;
        } else if l.contains("temperature-to-humidity map:") {
            mode = 7;
        } else if l.contains("humidity-to-location map:") {
            mode = 8;
        } else {
            let t: Vec<i64> = l.trim().split(" ")
                .map(|s| s.trim())
                .filter(|s| !s.is_empty())
                .map(|s| s.parse().unwrap())
                .collect();
            
            match mode {
                2 => dat.seed_to_soil.push(Row::new(t[0], t[1], t[2])),
                3 => dat.soil_to_fertilizer.push(Row::new(t[0], t[1], t[2])),
                4 => dat.fertilizer_to_water.push(Row::new(t[0], t[1], t[2])),
                5 => dat.water_to_light.push(Row::new(t[0], t[1], t[2])),
                6 => dat.light_to_temperature.push(Row::new(t[0], t[1], t[2])),
                7 => dat.temperature_to_humidity.push(Row::new(t[0], t[1], t[2])),
                8 => dat.humidity_to_location.push(Row::new(t[0], t[1], t[2])),
                _ => println!("Blah")
            }
        }
    }

    //----------
    let mut fval: Vec<i64> = vec![];
    for s in &dat.seed_list {
        let v = lookup_seed(*s, &dat);
        fval.push(v);
        println!("{} -> Loc {}", *s, v);
    }

    let m = fval.iter().min().unwrap().to_string();
    println!("Min Value = {}", m);
    return m;

}

pub fn lookup_seed(seed: i64, dat: &Data) -> i64 {

    let mut v = handle_seed_to_soil(seed, &dat);
    //dbg!(v);
    v = handle_soil_to_fertlizier(v, &dat);
    //dbg!(v);
    v = handle_fertilizer_to_water(v, &dat);
    //dbg!(v);
    v = handle_water_to_light(v, &dat);
    //dbg!(v);
    v = handle_light_to_temperature(v, &dat);
    //dbg!(v);
    v = handle_temperature_to_humidity(v, &dat);
    //dbg!(v);
    v = handle_humidity_to_location(v, &dat);
    //dbg!(v);
    return v;

}

pub fn handle_seed_to_soil(seed: i64, dat: &Data) -> i64  {
    let mut rv = -1;
    for r in &dat.seed_to_soil {
        if r.in_sequence(seed) {
            if rv != -1 {
                panic!("Yea double 1");
            }
            rv = r.convert_val(seed);
        }
    }

    if rv == -1 {
        return seed;
    } else {
        return rv;
    }
}

pub fn handle_soil_to_fertlizier(seed: i64, dat: &Data) -> i64  {
    let mut rv = -1;
    for r in &dat.soil_to_fertilizer {
        if r.in_sequence(seed) {
            if rv != -1 {
                panic!("Yea double 2");
            }
            rv = r.convert_val(seed);
        }
    }

    if rv == -1 {
        return seed;
    } else {
        return rv;
    }
}

pub fn handle_fertilizer_to_water(seed: i64, dat: &Data) -> i64  {
    let mut rv = -1;
    for r in &dat.fertilizer_to_water {
        if r.in_sequence(seed) {
            if rv != -1 {
                panic!("Yea double 3");
            }
            rv = r.convert_val(seed);
        }
    }

    if rv == -1 {
        return seed;
    } else {
        return rv;
    }
}

pub fn handle_water_to_light(seed: i64, dat: &Data) -> i64  {
    let mut rv = -1;
    for r in &dat.water_to_light {
        if r.in_sequence(seed) {
            if rv != -1 {
                panic!("Yea double 4");
            }
            rv = r.convert_val(seed);
        }
    }

    if rv == -1 {
        return seed;
    } else {
        return rv;
    }
}

pub fn handle_light_to_temperature(seed: i64, dat: &Data) -> i64  {
    let mut rv = -1;
    for r in &dat.light_to_temperature {
        if r.in_sequence(seed) {
            if rv != -1 {
                panic!("Yea double 5");
            }
            rv = r.convert_val(seed);
        }
    }

    if rv == -1 {
        return seed;
    } else {
        return rv;
    }
}

pub fn handle_temperature_to_humidity(seed: i64, dat: &Data) -> i64  {
    let mut rv = -1;
    for r in &dat.temperature_to_humidity {
        if r.in_sequence(seed) {
            if rv != -1 {
                panic!("Yea double 6");
            }
            rv = r.convert_val(seed);
        }
    }

    if rv == -1 {
        return seed;
    } else {
        return rv;
    }
}

pub fn handle_humidity_to_location(seed: i64, dat: &Data) -> i64  {
    let mut rv = -1;
    for r in &dat.humidity_to_location {
        if r.in_sequence(seed) {
            if rv != -1 {
                panic!("Yea double 7");
            }
            rv = r.convert_val(seed);
        }
    }

    if rv == -1 {
        return seed;
    } else {
        return rv;
    }
}