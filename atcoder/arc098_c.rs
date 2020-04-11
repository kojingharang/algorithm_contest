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

fn to_i(s : &str) -> Result<usize, std::num::ParseIntError> {
	s.parse::<usize>()
}

fn main() {
	loop {
		let nn = to_i(&rd()[0]);
		if nn.is_err() {
			break
		}

		let n = nn.unwrap();
		let s = read_line().as_bytes().to_vec();
		let mut t = s.clone();
		let mut cost = 0;
		for i in 1..n {
			if s[i]==b'E' {
				t[i] = b'W';
				cost+=1;
			}
		}
		let mut ans = cost;
		for i in 1..n {
			if s[i-1]==b'W' && s[i-1]==t[i-1] {
				t[i-1] = b'E';
				cost+=1;
			}
			if s[i]!=t[i] {
				t[i] = s[i];
				cost-=1;
			}
			ans = cmp::min(ans, cost);
		}
		let mut a = "abc".to_string();
		a[0] = 'b';
		println!("{}", ans);
//		println!("[{}] [{}] [{}]", n, String::from_utf8(s).unwrap(), String::from_utf8(t).unwrap());
	}
}

