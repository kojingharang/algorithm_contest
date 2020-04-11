use std::io;
use std::cmp;

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

fn to_i(s : &str) -> Result<i64, std::num::ParseIntError> {
	s.parse::<i64>()
}

fn sign(v:i32, idx:i32) -> i64 {
	if (v>>idx)&1==1 {
		-1
	} else {
		1
	}
}

fn main() {
	loop {
		let n_m = rd();
		if n_m.len() < 2 {
			break
		}
		let n = to_i(n_m[0].as_str()).unwrap() as usize;
		let m = to_i(n_m[1].as_str()).unwrap() as usize;
		let mut x = vec![0i64; n];
		let mut y = vec![0i64; n];
		let mut z = vec![0i64; n];
		for i in 0..n {
			let s = rd();
//			println!("{:?}", s);
			x[i] = to_i(s[0].as_str()).unwrap().into();
			y[i] = to_i(s[1].as_str()).unwrap().into();
			z[i] = to_i(s[2].as_str()).unwrap().into();
		}
		let mut ans = 0;
		for bits in 0..8 {
			let mut w = vec![0i64; n];
			for i in 0..n {
				w[i] = sign(bits, 0)*x[i] + sign(bits, 1)*y[i] + sign(bits, 2)*z[i];
			}
			w.sort();
			w.reverse();
			if w.len() >= m {
				let lans = w[0..m].iter().sum();
				ans = cmp::max(ans, lans);
			}
		}
		println!("{}", ans);
	}
}

