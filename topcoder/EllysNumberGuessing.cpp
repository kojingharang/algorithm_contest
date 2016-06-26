// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Elly and Kris play the following game. In the beginning Kristina thinks of a number between 1 and 1,000,000,000, inclusive. After that Elly starts trying to guess it. In each round she says a number and Kristina says what is the absolute difference between the number she has thought of, and the number Elly guessed. Now Elly wonders if the guesses she has already made are sufficient to uniquely determine Kristina's number.

You are given a vector <int> guesses and a vector <int> answers of the same length. For each valid i, in round i of the game (0-based index) Elly guessed the number guesses[i] and Kristina answered answers[i]. If Kristina's number can be uniquely determined, return that number. If there are multiple possibilities that are consistent with the current set of guesses and answers, return -1. If it can be shown that at some point Kristina has lied (some of her answers were inconsistent), return -2.

DEFINITION
Class:EllysNumberGuessing
Method:getNumber
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int getNumber(vector <int> guesses, vector <int> answers)


CONSTRAINTS
-guesses and answers will each contain between 1 and 50 elements, inclusive.
-guesses and answers will contain the same number of elements.
-Each element of guesses will be between 1 and 1,000,000,000, inclusive.
-Each element of answers will be between 1 and 999,999,999, inclusive.


EXAMPLES

0)
{600, 594}
{6, 12}

Returns: 606

Apparently Kristina has thought of the number of this SRM.

1)
{100, 50, 34, 40}
{58, 8, 8, 2}

Returns: 42

It is not guaranteed that Elly has used a perfect strategy so far.

2)
{500000, 600000, 700000}
{120013, 220013, 79987}

Returns: -2

The answers here are inconsistent. After the second guess we can conclude that the answer is below 500000. But the third one indicates that it is above 500000. Thus, Kristina is a liar and you should return -2.

3)
{500000000}
{133742666}

Returns: -1

There are multiple possibilities here, thus you should return -1.

4)
{76938260, 523164588, 14196746, 296286419, 535893832,
 41243148, 364561227, 270003278, 472017422, 367932361,
 395758413, 301278456, 186276934, 316343129, 336557549,
 52536121, 98343562, 356769915, 89249181, 335191879}
{466274085, 20047757, 529015599, 246925926, 7318513,
 501969197, 178651118, 273209067, 71194923, 175279984,
 147453932, 241933889, 356935411, 226869216, 206654796,
 490676224, 444868783, 186442430, 453963164, 208020466}

Returns: 543212345



5)
{42}
{42}

Returns: 84

Don't forget that the number Kris has thought of must be between 1 and 1,000,000,000.

6)
{999900000}
{100001}

Returns: 999799999

Don't forget that the number Kris has thought of must be between 1 and 1,000,000,000.

*/
// END CUT HERE
#line 90 "EllysNumberGuessing.cpp"

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
#include <cassert>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<int>
#define PII pair<int, int> 
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T> v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }



class EllysNumberGuessing {
	public:
	int getNumber(vector <int> G, vector <int> A) {
        PII z(G[0]+A[0], G[0]-A[0]);
        PII ok(z.first<=1000000000, z.second>=1);
        for(int i=1;i<G.size();i++) {
            int a=G[i]+A[i];
            int b=G[i]-A[i];
            ok.first=ok.first && (a==z.first||b==z.first);
            ok.second=ok.second && (a==z.second||b==z.second);
        }
        if(ok.first&&ok.second) return -1;
        else if(!ok.first&&!ok.second) return -2;
        else return ok.first?z.first:z.second;
	}
};

class EllysNumberGuessingTry {
	public:
	int getNumber(vector <int> G, vector <int> A) {
		ll limit=1000000000;
        VI w(2);
        w[0]=G[0]-A[0];
        w[1]=G[0]+A[0];
        VI ans;
        REP(j, 2) {
            bool has=true;
            REP(i, G.size()) {
                ll a=G[i]-A[i];
                ll b=G[i]+A[i];
                if(!(w[j]==a || w[j]==b)) has=false;
            }
            if(has) {
                if(1<=w[j] && w[j]<=limit) {
                    ans.PB(w[j]);
                }
            }
        }
        if(ans.size()==0) return -2;
        if(ans.size()==1) return ans[0];
        if(ans.size()==2) return -1;
        return -1;
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const int& Expected, const int& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, EllysNumberGuessing().getNumber(guesses, answers));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int guesses_[] = {5};
	  vector <int> guesses(guesses_, guesses_+sizeof(guesses_)/sizeof(*guesses_)); 
	int answers_[] = {999999999};
	  vector <int> answers(answers_, answers_+sizeof(answers_)/sizeof(*answers_)); 
	int _ = -2; 
END
CASE(0)
	int guesses_[] = {600, 594};
	  vector <int> guesses(guesses_, guesses_+sizeof(guesses_)/sizeof(*guesses_)); 
	int answers_[] = {6, 12};
	  vector <int> answers(answers_, answers_+sizeof(answers_)/sizeof(*answers_)); 
	int _ = 606; 
END
CASE(1)
	int guesses_[] = {100, 50, 34, 40};
	  vector <int> guesses(guesses_, guesses_+sizeof(guesses_)/sizeof(*guesses_)); 
	int answers_[] = {58, 8, 8, 2};
	  vector <int> answers(answers_, answers_+sizeof(answers_)/sizeof(*answers_)); 
	int _ = 42; 
END
CASE(2)
	int guesses_[] = {500000, 600000, 700000};
	  vector <int> guesses(guesses_, guesses_+sizeof(guesses_)/sizeof(*guesses_)); 
	int answers_[] = {120013, 220013, 79987};
	  vector <int> answers(answers_, answers_+sizeof(answers_)/sizeof(*answers_)); 
	int _ = -2; 
END
CASE(3)
	int guesses_[] = {500000000};
	  vector <int> guesses(guesses_, guesses_+sizeof(guesses_)/sizeof(*guesses_)); 
	int answers_[] = {133742666};
	  vector <int> answers(answers_, answers_+sizeof(answers_)/sizeof(*answers_)); 
	int _ = -1; 
END
CASE(4)
	int guesses_[] = {76938260, 523164588, 14196746, 296286419, 535893832,
 41243148, 364561227, 270003278, 472017422, 367932361,
 395758413, 301278456, 186276934, 316343129, 336557549,
 52536121, 98343562, 356769915, 89249181, 335191879};
	  vector <int> guesses(guesses_, guesses_+sizeof(guesses_)/sizeof(*guesses_)); 
	int answers_[] = {466274085, 20047757, 529015599, 246925926, 7318513,
 501969197, 178651118, 273209067, 71194923, 175279984,
 147453932, 241933889, 356935411, 226869216, 206654796,
 490676224, 444868783, 186442430, 453963164, 208020466};
	  vector <int> answers(answers_, answers_+sizeof(answers_)/sizeof(*answers_)); 
	int _ = 543212345; 
END
CASE(5)
	int guesses_[] = {42};
	  vector <int> guesses(guesses_, guesses_+sizeof(guesses_)/sizeof(*guesses_)); 
	int answers_[] = {42};
	  vector <int> answers(answers_, answers_+sizeof(answers_)/sizeof(*answers_)); 
	int _ = 84; 
END
CASE(6)
	int guesses_[] = {999900000};
	  vector <int> guesses(guesses_, guesses_+sizeof(guesses_)/sizeof(*guesses_)); 
	int answers_[] = {100001};
	  vector <int> answers(answers_, answers_+sizeof(answers_)/sizeof(*answers_)); 
	int _ = 999799999; 
END
#if 01  // DO RANDOM TESTS
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<10;loop++) {
// param type: int
start_time=clock();
	vector <int> guesses; 
	{
		int N=UNIFORM_LL(1, 50);
		guesses = vector <int>(N); 
		REP(i, N) {
			guesses[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
start_time=clock();
	vector <int> answers; 
	{
		int N=UNIFORM_LL(1, 50);
		answers = vector <int>(N); 
		REP(i, N) {
			answers[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = EllysNumberGuessing().getNumber(guesses, answers);
	int _1 = EllysNumberGuessingTry().getNumber(guesses, answers);
	if(!verify_case(_0, _1, true)) {
print(guesses);
print(answers);
	}
}
#endif

}
// END CUT HERE
