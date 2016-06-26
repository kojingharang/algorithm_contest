// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Correct parentheses sequences can be defined recursively as follows:

The empty string "" is a correct sequence.
If "X" and "Y" are correct sequences, then "XY" (the concatenation of X and Y) is a correct sequence.
If "X" is a correct sequence, then "(X)" is a correct sequence.
Each correct parentheses sequence can be derived using the above rules.

Examples of correct parentheses sequences include "", "()", "()()()", "(()())", and "(((())))".


You have a string s.
You want to change it into a correct parentheses sequence.



You can only change the string using magic flips.
In order to do a magic flip, you specify two 0-based indices L and R such that L <= R.
The operation modifies the characters on indices from L to R, inclusive.
First, the order of these characters is reversed.
Then, each character is toggled to the opposite one.
That is, each '(' in the specified range changes to a ')' and vice versa.



For example, suppose you have the string "((()".
If you do a magic flip on the entire string (i.e., choosing L=0 and R=3), it first gets reversed to ")(((" and then all parentheses are toggled. Thus, flipping the string "((()" produces the string "()))".



Given s, find and report any sequence of at most 10 magic flips that changes s into a correct parentheses sequence.
If there is no such sequence of magic flips, return the vector <int> {-1}.
If there are multiple such sequences, you may return any of them.
In particular, you are not required to find the shortest possible sequence of flips.
The returned vector <int> should contain 2*F elements, where F is the number of flips you want to perform: 
for each flip, in order, first its L and then its R.

DEFINITION
Class:ParenthesesDiv1Easy
Method:correct
Parameters:string
Returns:vector <int>
Method signature:vector <int> correct(string s)


CONSTRAINTS
-s will contain between 1 and 1,000 characters, inclusive.
-Each character in s will be '(' or ')'.


EXAMPLES

0)
")("

Returns: {0, 0, 1, 1 }

The first flip has L=R=0.
It changes the string to "((".
The second flip has L=R=1.
It changes that string to "()", which is a correct parentheses sequence.

1)
"))))))(((((("

Returns: {0, 5, 6, 11 }

Here, the first flip changes the string to "((((((((((((" and then the second flip changes it to "(((((())))))".

Note that {0,0,1,1,2,2,...,11,11} is not a valid solution.
This sequence of flips produces a correct parentheses sequence (by flipping each character separately).
However, this sequence consists of 12 flips and we are only allowed to perform at most 10 flips.

2)
"))()())()"

Returns: {-1 }

This s has length 9.
There is no correct parentheses sequence of length 9, so there can be no good sequence of flips.

3)
")()((("

Returns: {0, 0, 3, 3, 5, 5 }



4)
"()"

Returns: { }

This time we don't need to do anything.

******************************/
// END CUT HERE
#line 101 "ParenthesesDiv1Easy.cpp"
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cassert>
using namespace std;

#define EPS 1e-12
#define ull unsigned long long
#define ll long long
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define RANGE(i,a,b) for(int i=(int)a,_b=(int)(b);(i)<_b;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT(v) __builtin_popcountll((ll)(v))
#define IN_RANGE(v, a, b) ((a)<=(v) && (v)<(b))
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT2(table, I, J) REP(i, I) { REP(j, J) cout<<table[i][j]<<" "; cout<<"\n"; }
#define PRINT3(table, I, J, K) REP(i, I) { REP(j, J) { REP(k, K) cout<<table[i][j][k]<<" "; cout<<"\n"; } cout<<"\n"; }
#define DD(v) cout<<#v<<": "<<(v)<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

bool check(const string& s) {
	int N=s.size();
	int cnt=0;
	REP(i, N) {
		cnt += s[i]=='(' ? 1 : -1;
		if(cnt<0) return false;
	}
	return cnt==0;
}
string replace(string str, const string& from, const string& to) {
	string::size_type pos = 0;
	while(pos = str.find(from, pos), pos != string::npos) {
		str.replace(pos, from.length(), to);
		pos += to.length();
	}
	return str;
}

string reduce(string s) {
	while(1) {
		string ss = replace(s, "()", "");
		if(ss==s) return ss;
		s = ss;
	}
	return "";
}
vector<int> reduce_(string s) {
	vector<int> idx(s.size());
	REP(i, s.size()) idx[i]=i;
	cout<<idx<<endl;
	while(1) {
		string ns;
		vector<int> nidx;
		int i=0;
		for(;i<s.size()-1;i++) {
			if(s[i]=='(' && s[i+1]==')') {
				i++;
			} else {
				ns.push_back(s[i]);
				nidx.push_back(idx[i]);
			}
		}
		if(i<s.size()) {
			ns.push_back(s[i]);
			nidx.push_back(idx[i]);
		}
		string ss = replace(s, "()", "");
//		cout<<ns<<endl;
//		cout<<ss<<endl;
//		cout<<nidx<<endl;
		assert(ns==ss);
		if(ss==s) {
//			cout<<"OK"<<endl;
//			cout<<ns<<endl;
//			cout<<ss<<endl;
//			cout<<nidx<<endl;
			int N=s.size();
			int N2=s.size()/2;
			vector<int> ans;
			{
				int c=0;
				REP(i, N2) {
					if(ss[i]==')') c++;
				}
				if(c) {
					ans.PB(nidx[0]);
					ans.PB(nidx[c-1]);
				}
			}
			{
				int c=0;
				REP(i, N2) {
					if(ss[N-1-i]=='(') c++;
				}
				if(c) {
					ans.PB(nidx[N-1-(c-1)]);
					ans.PB(nidx[N-1]);
				}
			}
			cout<<"ANS "<<ans<<endl;
			return ans;
		}
		s = ns;
		idx = nidx;
	}
	return {};
}

string rev(string s, int i, int j) {
	REP(k, (j-i+1)/2) {
		swap(s[i+k], s[j-k]);
	}
	RANGE(k, i, j+1) s[k]=s[k]=='('?')':'(';
	return s;
}

template<class T> inline int chkmin(T& a, const T& val) {return a > val ? a = val, 1 : 0;}
class ParenthesesDiv1Easy {
	public:
	vector <int> correct(string s) {
		int N = s.size();
		vector<int> res;
		if(N%2==1) return {-1};
		int cur=0;
		while(cur<N) {
			if(s[cur]=='(') {
				int tot=0, idx=-1;
				RANGE(i, cur, N) {
					tot+=s[i]=='('?1:-1;
					if(tot==0) {
						idx=i;
						break;
					}
				}
				if(~idx) {
					cur=idx+1;
				} else {
					int tmp=0;
					RANGE(i, cur, N-1) {
						tmp+=s[i]=='('?1:-1;
						if(s[i+1]=='('&&tmp*2==tot) {
							res.PB(i+1);
							res.PB(N-1);
							return res;
						}
					}
				}
			}
			else {
				int dmin=1<<30, idx=-1;
				int tot=0;
				RANGE(i, cur, N) {
					tot += s[i]=='('?1:-1;
					if(chkmin(dmin, tot)) {
						idx=i;
					}
				}
				res.PB(cur);res.PB(idx);
				reverse(s.begin()+cur,s.begin()+idx+1);
				RANGE(i, cur, idx+1) {
					if(s[i]=='(') s[i]=')';
					else s[i]='(';
				}
			}
		}
		return res;
	}
};

class ParenthesesDiv1EasyRef {
	public:
	vector <int> correct(string s) {
		int N = s.size();
		if(N%2==1) return {-1};
		if(check(s)) return {};
		return reduce_(s);
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const vector <int>& Expected, const vector <int>& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: " << Expected << endl << "\tx: " << Received << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, ParenthesesDiv1Easy().correct(s));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 

void validate(string s, vector<int> ans) {
	string ss(s);
	REP(i, ans.size()/2) {
		ss = rev(ss, ans[i*2], ans[i*2+1]);
	}
//	cout<<"ANS "<<ans<<endl;
	cout<<ss<<endl;
	assert(check(ss));
}

int main(){

	REP(i, 100) {
		string s(1000, ' ');
		REP(i, 1000) s[i]=UNIFORM_DOUBLE(0, 1)<0.5?'(':')';
		vector<int> ans = reduce_(s);
		string ss(s);
		REP(i, ans.size()/2) {
			ss = rev(ss, ans[i*2], ans[i*2+1]);
		}
		cout<<"ANS "<<ans<<endl;
		cout<<ss<<endl;
		assert(check(ss));
	}
	return 0;
//
//	int N = 14;
//	REP(bits, 1<<N) {
//		string ss(N, ' ');
//		REP(i, N) ss[i] = bits>>i&1 ? '(':')';
////		cout<<"----"<<endl;
////		cout<<ss<<endl;
//		cout<<reduce(ss)<<endl;
////		REP(i, N) RANGE(j, i, N) {
////			string s(ss);
////			REP(k, (j-i+1)/2) {
////				swap(s[i+k], s[j-k]);
////			}
////			RANGE(k, i, j+1) s[k]=s[k]=='('?')':'(';
////			if(check(s)) {
////				string z(N, ' ');
////				RANGE(k, i, j+1) z[k]='*';
////				cout<<"OK "<<endl;
////				cout<<ss<<endl;
////				cout<<s<<endl;
////				cout<<z<<endl;
////			}
////		}
//	}
//	return 0;


CASE(0)
	string s = ")("; 
	int __[] = {0, 0, 1, 1 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(1)
	string s = "))))))(((((("; 
	int __[] = {0, 5, 6, 11 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(2)
	string s = "))()())()"; 
	int __[] = {-1 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(3)
	string s = ")()((("; 
	int __[] = {0, 0, 3, 3, 5, 5 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(4)
	string s = "()"; 
	vector <int> _; 
END
#if 01  // DO RANDOM TESTS

// INIT GLOBAL VARIABLES IN TRIAL CODE !!!!!!!!!!!!!!
// 1. Copy my class 
// 2. Add `Ref` suffix to my original class 
// 3. Write someone's code into copied class 
// 4. Run and verify example test case and random tests

//#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
if(!allOK) return 0;
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<100;loop++) {
// param type: String
	string s; 
	{
		int N=UNIFORM_LL(1, 51);
		s = string(N, ' '); 
		REP(i, N) s[i]=UNIFORM_DOUBLE(0, 1)<0.5?'(':')';
	}
	vector <int> _0 = ParenthesesDiv1Easy().correct(s);
	cout<<s<<endl;
	validate(s, _0);
	//vector <int> _1 = ParenthesesDiv1EasyRef().correct(s);
//	if(!verify_case(_0, _1, true)) {
//print(s);
//	}
}
#endif

}
// END CUT HERE
