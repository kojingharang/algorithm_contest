// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
The signature of a permutation is a string that is computed as follows: for each pair of consecutive elements of the permutation, write down the letter 'I' (increasing) if the second element is greater than the first one, otherwise write down the letter 'D' (decreasing).



For example, the signature of the permutation {3,1,2,7,4,6,5} is "DIIDID".



Your task is to reverse this computation: You are given a string signature containing the signature of a permutation.
Find and return the lexicographically smallest permutation with the given signature.
If no such permutation exists, return an empty vector <int> instead.


DEFINITION
Class:PermutationSignature
Method:reconstruct
Parameters:string
Returns:vector <int>
Method signature:vector <int> reconstruct(string signature)


NOTES
-For any positive integer N, a permutation of N elements is a sequence of length N that contains each of the integers 1 through N exactly once.
-To compare two permutations A and B, find the smallest index i such that A[i] and B[i] differ. If A[i] < B[i], we say that A is lexicographically smaller than B, and vice versa.


CONSTRAINTS
-signature will contain between 1 and 50 characters, inclusive.
-Each character in signature will be either 'I' or 'D'.


EXAMPLES

0)
"IIIII"

Returns: {1, 2, 3, 4, 5, 6 }



1)
"DI"

Returns: {2, 1, 3 }

There are two permutations with this signature: {3,1,2} and {2,1,3}. You must return the lexicographically smaller one.

2)
"IIIID"

Returns: {1, 2, 3, 4, 6, 5 }



3)
"DIIDID"

Returns: {2, 1, 3, 5, 4, 7, 6 }

This is the signature from the problem statement. Note that the correct answer is not the permutation from the problem statement.

*/
// END CUT HERE
#line 69 "PermutationSignature.cpp"
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define VI vector<int>
#define VVI vector<vector<int> >
#define B begin()
#define E end()
#define SZ size()
#define PB(v) push_back(v)
using namespace std;
#define REP(i, n) for(int i=0, _n=(n);(i)<_n;i++)
#define FOR(i, a, b) for(int i=(a),_b=(b);(i)<_b;i++)
#define FORD(i, a, b) for(int i=(a),_b=(b);(i)>=_b;i--)
#define CLR(a) memset(a, 0, sizeof(a))
#define SORT(v) sort(v.B, v.E)
template <typename T>
void UNIQ(T& v)
{
	typename T::iterator end = unique(v.B, v.E);
	v.erase(end, v.end());
}
template <typename T0, typename T1>
std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v)
{
	for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ )
	{
		os << p->first << ": " << p->second << " ";
	}
	return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const vector<T>& v)
{
	for( int i = 0; i < v.size(); i++ )
	{
		os << v[i] << " ";
	}
	return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const set<T>& v)
{
	vector<T> tmp(v.B, v.E);
	os << tmp;
	return os;
}

vector<vector<int> > combination(vector<int> vi, int K)
{
	sort(vi.begin(), vi.end());

	set<vector<int> > se;
	do
	{
		vector<int> tm(vi.begin(), vi.begin()+K);
		sort(tm.begin(), tm.end());
		se.insert(tm);
	}
	while(next_permutation(vi.begin(), vi.end()));
	return vector< vector<int> >(se.begin(), se.end());
}


class PermutationSignature {
	public:
	int dfs(string& sig, int pos, int start, VI& ans)
	{
		//cout<<"pos "<<pos<<endl;
//printf("%s %d\n", __FILE__, __LINE__);
		int sz = sig.SZ;
		FOR(i, 1, sz+2)
		{
			//cout<<"try pos "<<pos<<" i "<<endl;
			int ok = 1;
			REP(j, pos)
			{
				if(ans[j]==i) {/*cout<<"NG dup "<<ans[j]<<endl;*/ok=0; break;}
			}
			if(!ok) continue;
			if(pos!=0)
			{
				if(sig[pos-1]=='I' && i<ans[pos-1]) {/*cout<<"NG "<<sig[pos-1]<<" "<<i<<" "<<ans[pos-1]<<endl;*/ ok=0;continue;}
				if(sig[pos-1]=='D' && i>ans[pos-1]) {/*cout<<"NG "<<sig[pos-1]<<" "<<i<<" "<<ans[pos-1]<<endl;*/ ok=0;continue;}
			}
			//cout<<"pos "<<pos<<" i "<<i<<" ok "<<ok<<endl;
			//if(!ok) continue;
			ans[pos] = i;
			if(pos==sz)
			{
				cout<<"FOUND "<<ans<<endl;
				return 1;
			}
			int ret = dfs(sig, pos+1, 0, ans);
			if(ret) return 1;
		}
		return 0;
	}
	vector <int> reconstruct(string sig) {
printf("%s %d\n", __FILE__, __LINE__);
		int sz = sig.SZ;
		VI ans(sz+1);
		dfs(sig, 0, 1, ans);
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "IIIII"; int Arr1[] = {1, 2, 3, 4, 5, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, reconstruct(Arg0)); }
	void test_case_1() { string Arg0 = "I"; int Arr1[] = {1, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, reconstruct(Arg0)); }
	void test_case_2() { string Arg0 = "IIIID"; int Arr1[] = {1, 2, 3, 4, 6, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, reconstruct(Arg0)); }
	void test_case_3() { string Arg0 = "DDDDDDDDDDDDDDDDDDDD"; int Arr1[] = {21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, reconstruct(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	PermutationSignature ___test;

	___test.run_test(-1);

}

// END CUT HERE
