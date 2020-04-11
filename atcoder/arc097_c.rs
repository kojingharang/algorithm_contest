use std::io;
use std::cmp;
use std::collections::HashSet;

fn read_line() -> String {
	let mut line = String::new();
	let _ = io::stdin().read_line(&mut line);
	line.trim().to_string()
}

fn rd() -> Vec<String> {
	let mut vs : Vec<String> = vec![];
	for s in read_line().as_str().split(' ') {
//		println!("A {}", s);
		vs.push(s.to_string())
	}
	vs
}

fn to_i(s : &str) -> Result<usize, std::num::ParseIntError> {
	s.parse::<usize>()
}

fn main() {
	loop {
		let s = read_line().as_bytes().to_vec();
		if s.len()==0 {
			break
		}
		let k = to_i(&rd()[0]).unwrap();
		let mut h = HashSet::new();
		for i in 0..s.len() {
			for j in 1..k+1 {
				if i+j <= s.len() {
					h.insert(&s[i..i+j]);
				}
			}
		}
//		println!("{:?}", h);
		let mut a : Vec<&[u8]> = h.iter().cloned().collect();
		a.sort();
		println!("{}", String::from_utf8(a[k-1].to_vec()).unwrap());
	}
}

