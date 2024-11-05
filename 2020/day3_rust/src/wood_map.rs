#[derive(Debug)]
pub enum MapSpace {
    TREE,
    OPEN,
    UNKNOWN,
}

#[derive(Debug)]
pub struct WoodMap {
    pub map_template: Vec<char>,
    pub template_w: i32,
    pub template_h: i32,
}

impl WoodMap {
    pub fn new(data_input: String) -> Self {
        let v: Vec<&str> = data_input.split("\n").collect();
        let h = v.len() as i32;
        let w = v[0].len() as i32;

        let mut arr: Vec<char> = vec![];

        for r in v {
            arr.extend(r.chars());
        }
        WoodMap {
            template_h: h,
            template_w: w,
            map_template: arr,
        }
    }

    pub fn gcords_to_lcords(&self, gx: i32, gy: i32) -> (i32, i32) {

        let mut lx = gx % self.template_w;
        if(lx == 0) {
            lx = self.template_w;
        }

        //println!("g to l - ({}, {} -> {}, {})",
        //         gx, gy, lx, gy);
        (lx, gy)
    }

    pub fn lcords_to_vcord(&self, lx: i32, ly: i32) -> i32 {
        let fv = ((ly - 1) * self.template_w) + (lx - 1);;
        //println!("l to v - ({}, {}) -> {}", lx, ly, fv);
        fv
    }

    pub fn get_element(&self, gx: i32, gy: i32) -> char {
        let cord = self.gcords_to_lcords(gx, gy);
        let c = self.map_template[self.lcords_to_vcord(cord.0, cord.1) as usize];
        c
    }
}