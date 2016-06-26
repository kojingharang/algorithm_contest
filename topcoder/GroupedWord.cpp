// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// A word is grouped if, for each letter in the word, all occurrences of that letter form exactly one consecutive sequence.  In other words, no two equal letters are separated by one or more letters that are different.  For example, the words "ccazzzzbb" and "code" are grouped, while "aabbbccb" and "topcoder" are not.

A grouped word was divided into several parts.  You are given all the parts in random order as a vector <string>.  Reconstruct the original word and return it.  If there is more than one possible answer, return "MANY" instead.  If no grouped word could have resulted in the given parts, return "IMPOSSIBLE" instead (all quotes for clarity).


DEFINITION
Class:GroupedWord
Method:restore
Parameters:vector <string>
Returns:string
Method signature:string restore(vector <string> parts)


CONSTRAINTS
-parts will contain between 1 and 50 elements, inclusive.
-Each element of parts will contain between 1 and 20 characters, inclusive.
-Each element of parts will contain only lowercase letters ('a' - 'z').


EXAMPLES

0)
{"aaa", "a", "aa"}

Returns: "aaaaaa"

These parts could only have come from the word "aaaaaa", which is a grouped word.

1)
{"ab", "bba"}

Returns: "IMPOSSIBLE"

The only possible original words are "abbba" and "bbaab", and neither of them are grouped words.

2)
{"te", "st"}

Returns: "stte"



3)
{"te", "s", "t"}

Returns: "MANY"

The initial word could be either "stte" or "ttes".

4)
{"orr", "rd", "woo", "www"}

Returns: "wwwwooorrrd"



5)
{"abcb"}

Returns: "IMPOSSIBLE"

*/
// END CUT HERE
#line 68 "GroupedWord.cpp"

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define ll long long
#define VI vector<int>
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }


int loopdetect(int idx, VVI& node, VI& vis) {
	if(vis[idx]==2) return 0;
	if(vis[idx]==1) return 1;
	vis[idx]=1;
	FOR(n, node[idx]) if(loopdetect(*n, node, vis)) return 1;
	vis[idx]=2;
	return 0;
}


class GroupedWord {
	public:
	string restore(vector <string> pa) {
		{
			FOR(s, pa) {
				VI st(256);
				FOR(c, *s) {
					if(st[*c]==2) return "IMPOSSIBLE";
					FOR(v, st) if(*v==1) *v=2;
					st[*c]=1;
				}
			}
			VI ahi(256);
			FOR(ss, pa) {
				string& s=*ss;
				VI hi(256);
				int B=0, E=s.size()-1;
				while(s[0]==s[B]) B++;
				while(s[s.size()-1]==s[E]) E--;
				for(int i=B;i<=E;i++) {
					hi[s[i]]=1;
				}
				for(char c='a';c<='z';c++) {
					if(hi[c]&&ahi[c]) return "IMPOSSIBLE";
					ahi[c]=hi[c];
				}
			}
			VVI node(pa.size());
			REP(i, pa.size())
			REP(j, pa.size()) {
				if(i==j) continue;
				if(pa[i][pa[i].size()-1]==pa[j][0]) node[i].push_back(j);
			}
			//cout<<node<<endl;
			VI vis(node.size());
			REP(i, node.size()) if(loopdetect(i, node, vis)) return "IMPOSSIBLE";
			
			vector<string> se;
			
		}
		
		return "";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	//void test_case_0() { string Arr0[] = {"aaa", "a", "aa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aaaaaa"; verify_case(0, Arg1, restore(Arg0)); }
	//void test_case_0() { string Arr0[] = {"abaa", }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aaaaaa"; verify_case(0, Arg1, restore(Arg0)); }
	void test_case_0() { string Arr0[] = {"cbaa", "aaac"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aaaaaa"; verify_case(0, Arg1, restore(Arg0)); }
	void test_case_1() { string Arr0[] = {"ab", "bba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "IMPOSSIBLE"; verify_case(1, Arg1, restore(Arg0)); }
	void test_case_2() { string Arr0[] = {"te", "st"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "stte"; verify_case(2, Arg1, restore(Arg0)); }
	void test_case_3() { string Arr0[] = {"te", "s", "t"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "MANY"; verify_case(3, Arg1, restore(Arg0)); }
	void test_case_4() { string Arr0[] = {"orr", "rd", "woo", "www"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "wwwwooorrrd"; verify_case(4, Arg1, restore(Arg0)); }
	void test_case_5() { string Arr0[] = {"abcb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "IMPOSSIBLE"; verify_case(5, Arg1, restore(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	GroupedWord ___test;

	___test.run_test(-1);

}

// END CUT HERE
