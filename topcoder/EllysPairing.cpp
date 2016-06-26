// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Please note that this problem has a non-standard memory limit: 16 megabytes.

Elly is quite excited! She is about to participate in an awesome initiative: several universities from all around the world are collaborating on a pair-programming project. Now the organizers of the initiative want to form the pairs (teams of two people) that will work on the project.

Any two people may be paired, regardless of whether they are from the same university or not. However, it is awkward when the two teammates share the same name. Therefore the organizers would like to maximize the number of pairs such that the two paired participants have different names.

There are M different possible names, M being an exact power of two (e.g., 1, 2, 32, 131072, 1073741824). For simplicity, we will represent each name as a number between 0 and M-1, inclusive. You are given the int M and the vector <int>s count, first, mult, and add. Their meaning is as follows. University i sends count[i] people. The name of the first participant from that university is first[i]. The name of the second participant from that university (say second[i]) is (first[i] * mult[i] + add[i]) modulo M. The name of the third one (say third[i]) is (second[i] * mult[i] + add[i]) modulo M, and so on. See the notes for important information about an efficient implementation of the given generation process.

Return the maximum number of disjoint pairs in which the two people have different names.

DEFINITION
Class:EllysPairing
Method:getMax
Parameters:int, vector <int>, vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int getMax(int M, vector <int> count, vector <int> first, vector <int> mult, vector <int> add)


NOTES
-In order to make the generation of the names more efficient, it is guaranteed that M will be an exact power of two. Thus, instead of computing modulo M, the next name can be computed from the previous one by using the following formula: next = (previous * mult[i] + add[i]) & (M - 1). In this formula, '&' is the bitwise operator AND.
-Depending on your programming language, you may make the generation of names even faster by using 32-bit integers only. Even though the multiplication may overflow, the & will then only select the bits we are interested in, and those will be correct. (Note that in C++ you should use unsigned 32-bit integers. Even though your code will probably also work with signed ints, signed integer overflow leads to undefined behavior in C++.)
-The bitwise operator AND (the operator '&' in C++, Java, Python, and C#; the operator 'And' in VB) takes the binary representation of two numbers and creates a new number which has 1-bits only in the positions where both initial numbers had 1. For example 5 & 3 = 1, since 101 & 011 = 001.


CONSTRAINTS
-M will be between 1 and 1,073,741,824, inclusive.
-M will be an exact power of two.
-count, first, mult, and add will contain between 1 and 50 elements, inclusive.
-count, first, mult, and add will contain the same number of elements.
-Each element of count will be between 1 and 1,000,000, inclusive.
-Each element of first, mult, and add will be between 0 and M-1, inclusive.


EXAMPLES

0)
16
{4, 7}
{5, 3}
{2, 3}
{1, 0}

Returns: 5

The people from university 0 have names {5, 7, 11, 15} and the ones from university 1 have names {1, 3, 3, 9, 9, 11, 11}.
Since the number of people is odd, there can be at most 5 pairs altogether.
It turns out that each of those pairs can contain two people with different names!
One of the possible pairings is: {(5, 15), (7, 3), (11, 9), (1, 3), (9, 11)}.


1)
8
{6, 4, 3}
{0, 3, 2}
{3, 7, 5}
{0, 3, 2}

Returns: 5

In this example the people have names {0, 3, 2, 0, 0, 4, 0, 3, 6, 0, 0, 0, 0}.
In the best solution there are 5 pairs such that the two people have different names. Additionally, there is one pair in which both people have the same name and one other person without a partner.

2)
128
{42, 13, 666, 17, 1337, 42, 1}
{18, 76, 3, 122, 0, 11, 11}
{33, 17, 54, 90, 41, 122, 20}
{66, 15, 10, 121, 122, 1, 30}

Returns: 1059



3)
1048576
{4242, 42, 9872, 13, 666, 21983, 17, 1337, 42, 1}
{19, 18, 76, 42, 3, 112, 0, 11, 11, 12}
{27, 33, 10, 8, 17, 9362, 90, 41, 122, 20}
{98, 101, 66, 15, 10, 144, 3, 1, 5, 1}

Returns: 16232



4)
1073741824
{894602, 946569, 887230, 856152, 962583, 949356, 904847, 829100, 842183, 958440,
 811081, 864078, 809209, 938727, 949135, 892809, 816528, 961237, 979142, 890922}
{844085078, 898937259, 243490172, 887804102, 187696417, 156820442, 237600210, 618812924, 153000239, 912364033,
 254936966, 650298774, 982988140, 649258331, 566444626, 201481721, 492943390, 1061953081, 492672963, 960519711}
{1036482037, 583219072, 819168094, 253755052, 548208982, 401830167, 638626082, 43642932, 123607749, 485521178,
 860368129, 30334704, 219771462, 733375600, 130839219, 415503960, 294132484, 1044831462, 256910484, 198852170}
{889169006, 604831366, 967292994, 980686280, 844875791, 1027687492, 357734882, 295879743, 48284748, 421729100,
 1049536313, 327207332, 948053446, 271229570, 664579359, 795815285, 842856528, 876662975, 675611938, 634229925}

Returns: 8971965

Don't forget that the memory limit for the problem is only 16 megabytes! We recommend that you test this example in the arena before you submit.

*/
// END CUT HERE
#line 106 "EllysPairing.cpp"

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

class EllysPairing {
	public:
	int getMax(int M, vector <int> count, vector <int> first, vector <int> mult, vector <int> add) {
		int N=count.size();
        int total=accumulate(ALL(count), 0);
        int co=0;
        ll maj=-1;
        REP(i, N) {
            uint32_t v = first[i];
            REP(loop, count[i]) {
                if(v==maj) co++;
                else if(co==0) maj=v,co=1; else co--;
                v = (v * mult[i] + add[i]) & (M-1);
            }
        }
        co=0;
        REP(i, N) {
            uint32_t v = first[i];
            REP(loop, count[i]) {
                if(maj==v) co++;
                v = (v * mult[i] + add[i]) & (M-1);
            }
        }
        int th = total/2;
        if(co>th) {
            int rest = (co-th) - (total-th*2);
            th-=rest;
        }
        return th;
	}
};


/*
class EllysPairing {
	public:
	int getMax(int M, vector <int> count, vector <int> first, vector <int> mult, vector <int> add) {
		int N=count.size();
        map<int, int> hi;
        int total=0;
        REP(i, N) {
            total+=count[i];
            VI w;
            uint32_t v = first[i];
            REP(loop, count[i]) {
                if(loop<4) {
                    w.PB(v);
                    hi[v]++;
                } else {
                    REP(j, 4) if(w[j]==v){hi[v]++;break;}
                }
                v = (v * mult[i] + add[i]) & (M-1);
            }
        }
//        cout<<endl;
//        cout<<w<<endl;
        int mx=0;
        FOR(e, hi) mx=max(mx, e->second);
        int th = total/2;
        if(mx>th) {
            int rest = (mx-th) - (total-th*2);
            th-=rest;
            cout<<"--- "<<rest<<endl;
        }
        return th;
	}
};
*/

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
#define END	 verify_case(_, EllysPairing().getMax(M, count, first, mult, add));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){





CASE(0)
	int M = 134217728; 
	int count_[] = {7463, 11941, 19994, 4709, 7081, 951, 7752, 16161, 9038, 12081, 17766, 14296, 19147, 18575, 6429, 3546, 13577, 14518, 17542, 7552, 16575, 141, 2401, 1342, 11750, 19479, 9647, 1345, 11509, 936, 19498, 6915, 16630, 8574, 13724, 17861, 8129, 153, 10327, 7876, 6127, 12629, 5548, 4056, 13881, 15422, 16934, 16673, 4810, 510888};
	  vector <int> count(count_, count_+sizeof(count_)/sizeof(*count_)); 
	int first_[] = {73231047, 119083464, 109181729, 100278224, 48793770, 101314280, 31325015, 125411053, 128903487, 48517677, 19707011, 129066211, 108429199, 124261860, 31807082, 38521161, 96100319, 24640963, 82712888, 31622509, 63940427, 82554566, 56830878, 29532843, 75383901, 82151424, 85035491, 125059529, 108920992, 89948285, 86369793, 62302025, 17249089, 78251534, 3112123, 78636230, 21476511, 82566444, 21432243, 115404619, 131843817, 91885001, 131692680, 118313639, 105572272, 79735084, 84350184, 57091533, 77116037, 53628428};
	  vector <int> first(first_, first_+sizeof(first_)/sizeof(*first_)); 
	int mult_[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22923461};
	  vector <int> mult(mult_, mult_+sizeof(mult_)/sizeof(*mult_)); 
	int add_[] = {42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 35994048};
	  vector <int> add(add_, add_+sizeof(add_)/sizeof(*add_)); 
	int _ = 510937; 
END
CASE(0)
	int M = 2; 
	int count_[] = {1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000};
	  vector <int> count(count_, count_+sizeof(count_)/sizeof(*count_)); 
	int first_[] = {1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0};
	  vector <int> first(first_, first_+sizeof(first_)/sizeof(*first_)); 
	int mult_[] = {1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1};
	  vector <int> mult(mult_, mult_+sizeof(mult_)/sizeof(*mult_)); 
	int add_[] = {0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1};
	  vector <int> add(add_, add_+sizeof(add_)/sizeof(*add_)); 
	int _ = 20000001; 
END

CASE(0)
	int M = 1073741824; 
	int count_[] = {999825, 999600, 992131, 999944, 993917, 997121, 991984, 992356, 994191, 998231, 997591, 990050, 996529, 992901, 997664, 996775, 998812, 996288, 995649, 990324, 991093, 993270, 990314, 994393, 990810};
	  vector <int> count(count_, count_+sizeof(count_)/sizeof(*count_)); 
	int first_[] = {96494602, 117585745, 303034923, 377785703, 271357839, 3840255, 965092511, 269904991, 739821279, 823438815, 953501663, 127861727, 952642527, 3382239, 458963935, 772471775, 391478239, 937196511, 641104863, 242383839, 916093919, 202013663, 262831071, 661289951, 569015263};
	  vector <int> first(first_, first_+sizeof(first_)/sizeof(*first_)); 
	int mult_[] = {844085078, 844085078, 844085078, 844085078, 844085078, 844085078, 844085078, 844085078, 844085078, 844085078, 844085078, 844085078, 844085078, 844085078, 844085078, 844085078, 844085078, 844085078, 844085078, 844085078, 844085078, 844085078, 844085078, 844085078, 844085078};
	  vector <int> mult(mult_, mult_+sizeof(mult_)/sizeof(*mult_)); 
	int add_[] = {1036482037, 1036482037, 1036482037, 1036482037, 1036482037, 1036482037, 1036482037, 1036482037, 1036482037, 1036482037, 1036482037, 1036482037, 1036482037, 1036482037, 1036482037, 1036482037, 1036482037, 1036482037, 1036482037, 1036482037, 1036482037, 1036482037, 1036482037, 1036482037, 1036482037};
	  vector <int> add(add_, add_+sizeof(add_)/sizeof(*add_)); 
	int _ = 450; 
END



CASE(0)
	int M = 16; 
	int count_[] = {4, 7};
	  vector <int> count(count_, count_+sizeof(count_)/sizeof(*count_)); 
	int first_[] = {5, 3};
	  vector <int> first(first_, first_+sizeof(first_)/sizeof(*first_)); 
	int mult_[] = {2, 3};
	  vector <int> mult(mult_, mult_+sizeof(mult_)/sizeof(*mult_)); 
	int add_[] = {1, 0};
	  vector <int> add(add_, add_+sizeof(add_)/sizeof(*add_)); 
	int _ = 5; 
END
CASE(1)
	int M = 8; 
	int count_[] = {6, 4, 3};
	  vector <int> count(count_, count_+sizeof(count_)/sizeof(*count_)); 
	int first_[] = {0, 3, 2};
	  vector <int> first(first_, first_+sizeof(first_)/sizeof(*first_)); 
	int mult_[] = {3, 7, 5};
	  vector <int> mult(mult_, mult_+sizeof(mult_)/sizeof(*mult_)); 
	int add_[] = {0, 3, 2};
	  vector <int> add(add_, add_+sizeof(add_)/sizeof(*add_)); 
	int _ = 5; 
END
CASE(2)
	int M = 128; 
	int count_[] = {42, 13, 666, 17, 1337, 42, 1};
	  vector <int> count(count_, count_+sizeof(count_)/sizeof(*count_)); 
	int first_[] = {18, 76, 3, 122, 0, 11, 11};
	  vector <int> first(first_, first_+sizeof(first_)/sizeof(*first_)); 
	int mult_[] = {33, 17, 54, 90, 41, 122, 20};
	  vector <int> mult(mult_, mult_+sizeof(mult_)/sizeof(*mult_)); 
	int add_[] = {66, 15, 10, 121, 122, 1, 30};
	  vector <int> add(add_, add_+sizeof(add_)/sizeof(*add_)); 
	int _ = 1059; 
END
CASE(3)
	int M = 1048576; 
	int count_[] = {4242, 42, 9872, 13, 666, 21983, 17, 1337, 42, 1};
	  vector <int> count(count_, count_+sizeof(count_)/sizeof(*count_)); 
	int first_[] = {19, 18, 76, 42, 3, 112, 0, 11, 11, 12};
	  vector <int> first(first_, first_+sizeof(first_)/sizeof(*first_)); 
	int mult_[] = {27, 33, 10, 8, 17, 9362, 90, 41, 122, 20};
	  vector <int> mult(mult_, mult_+sizeof(mult_)/sizeof(*mult_)); 
	int add_[] = {98, 101, 66, 15, 10, 144, 3, 1, 5, 1};
	  vector <int> add(add_, add_+sizeof(add_)/sizeof(*add_)); 
	int _ = 16232; 
END
CASE(4)
	int M = 1073741824; 
	int count_[] = {894602, 946569, 887230, 856152, 962583, 949356, 904847, 829100, 842183, 958440,
 811081, 864078, 809209, 938727, 949135, 892809, 816528, 961237, 979142, 890922};
	  vector <int> count(count_, count_+sizeof(count_)/sizeof(*count_)); 
	int first_[] = {844085078, 898937259, 243490172, 887804102, 187696417, 156820442, 237600210, 618812924, 153000239, 912364033,
 254936966, 650298774, 982988140, 649258331, 566444626, 201481721, 492943390, 1061953081, 492672963, 960519711};
	  vector <int> first(first_, first_+sizeof(first_)/sizeof(*first_)); 
	int mult_[] = {1036482037, 583219072, 819168094, 253755052, 548208982, 401830167, 638626082, 43642932, 123607749, 485521178,
 860368129, 30334704, 219771462, 733375600, 130839219, 415503960, 294132484, 1044831462, 256910484, 198852170};
	  vector <int> mult(mult_, mult_+sizeof(mult_)/sizeof(*mult_)); 
	int add_[] = {889169006, 604831366, 967292994, 980686280, 844875791, 1027687492, 357734882, 295879743, 48284748, 421729100,
 1049536313, 327207332, 948053446, 271229570, 664579359, 795815285, 842856528, 876662975, 675611938, 634229925};
	  vector <int> add(add_, add_+sizeof(add_)/sizeof(*add_)); 
	int _ = 8971965; 
END
#if 0  // DO RANDOM TESTS
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<10;loop++) {
// param type: int
start_time=clock();
	int M = UNIFORM_LL(0, 100); 
// param type: int
start_time=clock();
	vector <int> count; 
	{
		int N=UNIFORM_LL(1, 50);
		count = vector <int>(N); 
		REP(i, N) {
			count[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
start_time=clock();
	vector <int> first; 
	{
		int N=UNIFORM_LL(1, 50);
		first = vector <int>(N); 
		REP(i, N) {
			first[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
start_time=clock();
	vector <int> mult; 
	{
		int N=UNIFORM_LL(1, 50);
		mult = vector <int>(N); 
		REP(i, N) {
			mult[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
start_time=clock();
	vector <int> add; 
	{
		int N=UNIFORM_LL(1, 50);
		add = vector <int>(N); 
		REP(i, N) {
			add[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = EllysPairing().getMax(M, count, first, mult, add);
	int _1 = EllysPairingTry().getMax(M, count, first, mult, add);
	if(!verify_case(_0, _1, true)) {
print(M);
print(count);
print(first);
print(mult);
print(add);
	}
}
#endif

}
// END CUT HERE
