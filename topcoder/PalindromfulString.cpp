// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// A palindrome is a string that is the same whether it is read from left to right or from right to left.

Consider a string of length N which contains only uppercase letters. Write down all of its contiguous substrings of length M (a separate substring must be written down for each starting position, even if some of these substrings are the same strings). If at least K of the substrings you have written down are palindromes, we call the string palindromful.

Return the number of different palindromful strings of length N.

DEFINITION
Class:PalindromfulString
Method:count
Parameters:int, int, int
Returns:long long
Method signature:long long count(int N, int M, int K)


CONSTRAINTS
-N will be between 2 and 11, inclusive.
-M will be between 2 and N, inclusive.
-K will be between 0 and 11, inclusive. 


EXAMPLES

0)
2
2
1

Returns: 26

For a string of length 2, the only substring of length 2 is the string itself. Therefore, in this case we need to count palindromes of length 2, which are "AA", "BB", ..., "ZZ".

1)
2
2
0

Returns: 676

This time there can be no palindrome among the substrings, so any string of length 2 will do.

2)
3
2
1

Returns: 1326

Either the first two or the last two characters of the string should be equal, with no restrictions on the remaining one. This gives us 2*26*26=1352 variants, of which 26 are strings consisting entirely of the same character and therefore duplicated.

3)
4
4
1

Returns: 676

We're looking for palindromes of length 4.

4)
7
3
3

Returns: 4310176



*/
// END CUT HERE
#line 74 "PalindromfulString.cpp"
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#define ll long long
using namespace std;
#define REP(i, n) for(int i=0, _n=(n);(i)<_n;i++)
#define FOR(i, a, b) for(int i=(a),_b=(b);(i)<_b;i++)
#define FORD(i, a, b) for(int i=(a),_b=(b);(i)>=_b;i--)
#define CLR(a) memset(a, 0, sizeof(a))
class PalindromfulString {
	public:
	long long count(int N, int M, int K) {
printf("%s %d\n", __FILE__, __LINE__);
		cout << N << M << K << endl;
		
		ll ans = 0;
		REP(i, 1<<(N-M+1))
		{
			int co = 0;
			int bm[12];
			int ii = 0;
			REP(iii, 12) if((i>>iii)&1) { co++; bm[ii++]=iii;}
			if(co==K)
			{
				REP(j, K)
				{
					printf("%d ", bm[j]);
				}
				printf("\n");
				
				int lbl = 1;
				int w[20];
				CLR(w);
				REP(j, K)
				{
					int be = bm[j];
					FOR(zi, 0, M)
					{
						if(w[be+zi]==0)
						{
							w[be+zi]=lbl++;
						}
						w[be+M-1-zi] = w[be+zi];
					}
					printf("W   ");
					REP(zi, N) { printf("%d ", w[zi]);}
					printf("\n");
				}
				REP(zi, N)
				{
					if(w[zi]==0)
					{
						w[zi] = lbl++;
					}
				}
				printf("W   ");
				REP(zi, N) { printf("%d ", w[zi]);}
				printf("\n");
				ll lans = 1;
				REP(zi, lbl-1) lans *= 26;
				printf(" += %d\n", lans);
				ans += lans;
			}
		}
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; long long Arg3 = 26LL; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 0; long long Arg3 = 676LL; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 1; long long Arg3 = 1326LL; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 1; long long Arg3 = 676LL; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 7; int Arg1 = 3; int Arg2 = 3; long long Arg3 = 4310176LL; verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	PalindromfulString ___test;

	___test.run_test(-1);

}

// END CUT HERE
