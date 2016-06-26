// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Warning: This problem statement contains superscripts and/or subscripts. It may not display properly outside of the applet.


Tomek and Wojtek are going to participate as a team in their local ICPC competition next week. The organizers allow the contestants to bring their own printed materials such as books to the contest site. Their university has some books they could borrow; the i-th of those books weighs books[i] grams. Our heroes would like to have as much material available as possible, however neither of them wishes to be carrying too much weight. Let T be the total weight of books that Tomek will take, and W be the total weight of books that Wojtek will take. Then, Tomek wants to maximize W - T, while Wojtek wants to maximize T - W; if they would have multiple optimal choices, both of them want to maximize T + W as a tie-breaker. The way it will be decided who carries which books to the contest will be as follows:

First, Tomek selects any moves[0] books from the library, and put them in Wojtek's backpack. These will be the books that their team will take to the contest.
Then, Wojtek selects any moves[1] books from his backpack, and moves them to Tomek's backpack.
Then, Tomek selects any moves[2] books from his backpack, and moves them to Wojtek's backpack, and so on...

This process continues for a total of n moves, where n is the number of elements in moves. If there are less than moves[i] books available in the i-th move, the player simply moves all the available books.



You are given a vector <int> books and a vector <int> moves. Return a vector <int> containing exactly two elements, (T, W), with the first element equal to the total weight of books that Tomek will carry, and the second element equal to the total weight of books that Wojtek will carry. Assume that both Tomek and Wojtek make optimal choices during the process described above.


DEFINITION
Class:HeavyBooks
Method:findWeight
Parameters:vector <int>, vector <int>
Returns:vector <int>
Method signature:vector <int> findWeight(vector <int> books, vector <int> moves)


NOTES
-The books may be very heavy.
-The correct return value is always uniquely determined by the problem statement.


CONSTRAINTS
-books will contain between 1 and 50 elements, inclusive.
-Each element of books will be between 1 and 106, inclusive.
-moves will contain between 1 and 50 elements, inclusive.
-Each element of moves will be between 1 and the number of elements in books, inclusive.


EXAMPLES

0)
{5,2,3,1}
{3,2,1,1,1}

Returns: {3, 7 }

The process can go as follows:


First, Tomek will pick books with weights 5, 2 and 3 and put them in Wojtek's backpack.
Wojtek will move the books with weights 5 and 3 to Tomek's backpack.
Tomek will move the book with weight 5 back to Wojtek's backpack.
Wojtek will move the book with weight 5 back to Tomek's backpack.
Finally, Tomek will move the book with weight 5 back to Wojtek's backpack again.


1)
{10, 100, 1000}
{2, 3}

Returns: {110, 0 }

Wojtek has only two books after Tomek's opening move, so he empties his backpack in his move.

2)
{155870,565381}
{1,1,1}

Returns: {0, 565381 }

3)
{500,500,500,500}
{4,1,1,3,2}

Returns: {500, 1500 }

Here, all the books have the same weight.

4)
{1,1,1,1,1000000}
{1}

Returns: {0, 1000000 }



5)
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}
{20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1}

Returns: {110, 100 }



*/
// END CUT HERE
#line 99 "HeavyBooks.cpp"

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <ctime>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }


vector <int> BB;
VI w;

map<PII, PII> memo;
PII f(int bi, int wi) {
	PII key = MP(bi, wi);
	if(memo.count(key)) return memo[key];
	
	if(wi==w.size()) return MP(0, 0);
	if(bi==BB.size()) return MP(-100000000, -100000000);
	
	PII rest = f(bi+1, wi+1);
	if(w[wi]==0) rest.first-=BB[bi];
	else         rest.first+=BB[bi];
	rest.second+=BB[bi];
	
	PII restB = f(bi+1, wi);
	//cout<<bi<<" "<<wi<<" "<<rest<<" "<<restB<<endl;
	return memo[key] = max(rest, restB);
}

class HeavyBooks {
	public:
	vector <int> findWeight(vector <int> B, vector <int> M) {
		memo = map<PII, PII>();
		sort(ALL(B));
		
		w = VI(M[0], 1);
		int to=0;
		REP(i, M.size()-1) {
			int mo = M[i+1];
			for(int j=M[0]-1;j>=0;j--) {
				if(w[j]==1-to) {
					w[j]=to;
					mo--;
					if(mo==0) break;
				}
			}
			to=1-to;
		}
		cout<<w<<endl;
		BB=B;
		PII r = f(0, 0);
		cout<<r<<endl;
		vector<int> ans(2);
		ans[0]=-(r.first-r.second)/2;
		ans[1]=(r.first+r.second)/2;
		return ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
//mplate<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
// os << "{ ";
// for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
// os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const vector <int>& Expected, const vector <int>& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: " << Expected << endl << "\tx: " << Received << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, HeavyBooks().findWeight(books, moves));}
int main(){

CASE(0)
	int books_[] = {5,2,3,1};
	  vector <int> books(books_, books_+sizeof(books_)/sizeof(*books_)); 
	int moves_[] = {3,2,1,1,1};
	  vector <int> moves(moves_, moves_+sizeof(moves_)/sizeof(*moves_)); 
	int __[] = {3, 7 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
//return 0;
CASE(1)
	int books_[] = {10, 100, 1000};
	  vector <int> books(books_, books_+sizeof(books_)/sizeof(*books_)); 
	int moves_[] = {2, 3};
	  vector <int> moves(moves_, moves_+sizeof(moves_)/sizeof(*moves_)); 
	int __[] = {110, 0 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(2)
	int books_[] = {155870,565381};
	  vector <int> books(books_, books_+sizeof(books_)/sizeof(*books_)); 
	int moves_[] = {1,1,1};
	  vector <int> moves(moves_, moves_+sizeof(moves_)/sizeof(*moves_)); 
	int __[] = {0, 565381 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(3)
	int books_[] = {500,500,500,500};
	  vector <int> books(books_, books_+sizeof(books_)/sizeof(*books_)); 
	int moves_[] = {4,1,1,3,2};
	  vector <int> moves(moves_, moves_+sizeof(moves_)/sizeof(*moves_)); 
	int __[] = {500, 1500 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(4)
	int books_[] = {1,1,1,1,1000000};
	  vector <int> books(books_, books_+sizeof(books_)/sizeof(*books_)); 
	int moves_[] = {1};
	  vector <int> moves(moves_, moves_+sizeof(moves_)/sizeof(*moves_)); 
	int __[] = {0, 1000000 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(5)
	int books_[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	  vector <int> books(books_, books_+sizeof(books_)/sizeof(*books_)); 
	int moves_[] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	  vector <int> moves(moves_, moves_+sizeof(moves_)/sizeof(*moves_)); 
	int __[] = {110, 100 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END

}
// END CUT HERE
