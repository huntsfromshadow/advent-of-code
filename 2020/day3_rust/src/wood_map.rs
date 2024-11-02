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
        (gx % self.template_w, gy)
    }

    pub fn lcords_to_vcord(&self, lx: i32, ly: i32) -> i32 {
        ly * self.template_w + lx
    }

    pub fn get_element(&self, gx: i32, gy: i32) -> char {
        let cord = self.gcords_to_lcords(gx, gy);
        let c = self.map_template[self.lcords_to_vcord(cord.0, cord.1) as usize];
        c
    }
}