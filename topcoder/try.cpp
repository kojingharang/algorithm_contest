// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// The Order of All Things Pointy and Magical has commissioned the creation of some new wizard hats. A wizard hat is created by taking two cones: a decorative top cone, and a warm and fluffy bottom cone. To assemble the hat, both cones are first placed onto a table, so that their bases are horizontal and their apexes point upwards. The top cone is then lifted and placed onto the bottom cone. The base of the top cone has to remain horizontal, and the apex of the top cone must be strictly above the apex of the bottom cone. 

Not every pair of cones can be used to create a wizard hat. A wizard hat is only produced if the following two criteria are both met:

The apex of the top cone must be strictly above the apex of the bottom cone. I.e., when the top cone is placed on top of the bottom cone and released, their apexes must not touch.
Some part of the bottom cone must remain visible to form the brim of the hat. (Otherwise, the hat would look like a simple cone, not like a wizard hat!)


You have several top cones and several bottom cones of various sizes. Each cone can be described by its height (the distance between the apex and the base) and by the radius of its base. The top cones you have are described by topHeight and topRadius: for each valid i, you have one top cone with height topHeight[i] and radius topRadius[i]. The bottom cones you have are described by bottomHeight and bottomRadius in the same way. 

Your task is to determine the maximum number of wizard hats you can make using each of the available top and bottom cones at most once.

DEFINITION
Class:PointyWizardHats
Method:getNumHats
Parameters:vector <int>, vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int getNumHats(vector <int> topHeight, vector <int> topRadius, vector <int> bottomHeight, vector <int> bottomRadius)


CONSTRAINTS
-topHeight and topRadius will contain the same number of elements.
-bottomHeight and bottomRadius will contain the same number of elements.
-topHeight will contain between 1 and 50 elements, inclusive.
-topRadius will contain between 1 and 50 elements, inclusive.
-bottomHeight will contain between 1 and 50 elements, inclusive.
-bottomRadius will contain between 1 and 50 elements, inclusive.
-Each element of topHeight, topRadius, bottomHeight, and bottomRadius will be between 1 and 10,000, inclusive.


EXAMPLES

0)
{30}
{3}
{3}
{30}

Returns: 1

The top and bottom cone can be used together to make a wizard hat.

1)
{4,4}
{4,3}
{5,12}
{5,4}

Returns: 1

The only way to produce a wizard hat is to use the top cone 1 (height 4, radius 3) and the bottom cone 0 (height 5, radius 5).

2)
{3}
{3}
{1,1}
{2,4}

Returns: 1



3)
{10,10}
{2,5}
{2,9}
{3,6}

Returns: 2



4)
{3,4,5}
{5,4,3}
{3,4,5}
{3,8,5}

Returns: 2



5)
{1,2,3,4,5}
{2,3,4,5,6}
{2,3,4,5,6}
{1,2,3,4,5}

Returns: 0



6)
{123,214,232,323,342,343}
{123,123,232,123,323,434}
{545,322,123,545,777,999}
{323,443,123,656,767,888}

Returns: 5



7)
{999,999,999,10000,10000,10000}
{10000,10000,10000,1,2,3}
{2324,2323,234,5454,323,232}
{1,2,3222,434,5454,23}

Returns: 3



*/
// END CUT HERE
#line 119 "PointyWizardHats.cpp"

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

#define INF 1000000
typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])
Weight maximumFlow(const Graph &g, int s, int t) {
  int n = g.size();
  Matrix flow(n, Array(n)), capacity(n, Array(n));
  REP(u,n) FOR(e,g[u]) capacity[e->src][e->dst] += e->weight;

  Weight total = 0;
  while (1) {
    queue<int> Q; Q.push(s);
    vector<int> prev(n, -1); prev[s] = s;
    while (!Q.empty() && prev[t] < 0) {
      int u = Q.front(); Q.pop();
      FOR(e,g[u]) if (prev[e->dst] < 0 && RESIDUE(u, e->dst) > 0) {
        prev[e->dst] = u;
        Q.push(e->dst);
      }
    }
    if (prev[t] < 0) return total; // prev[x] == -1 <=> t-side
    Weight inc = INF;
    for (int j = t; prev[j] != j; j = prev[j])
      inc = min(inc, RESIDUE(prev[j], j));
    for (int j = t; prev[j] != j; j = prev[j])
      flow[prev[j]][j] += inc, flow[j][prev[j]] -= inc;
    VI path;
    for (int j = t; prev[j] != j; j = prev[j]) path.push_back(j);
    path.push_back(s);
    reverse(ALL(path));
    total += inc;
    //cout<<"Update "<<path<<" -> total "<<total<<endl;
  }
}
void add_edge(Graph& g, int s, int e, int w) {
	//cout<<s<<" -> "<<e<<endl;
	g[s].push_back(Edge(s, e, w));
	g[e].push_back(Edge(e, s, 0));
}

int f(ll H0, ll R0, ll H1, ll R1) {
	if(R0>=R1) return 0;
	return R1*H0 > H1*R0;
}

template<class BidirectionalIterator> 
  bool next_combination(BidirectionalIterator first1,
                        BidirectionalIterator last1,
                        BidirectionalIterator first2,
                        BidirectionalIterator last2)
  {
      if ((first1 == last1) || (first2 == last2)) {
          return false;
      }
      
      BidirectionalIterator m1 = last1;
      BidirectionalIterator m2 = last2; --m2;
      
      // Find first m1 not less than *m2 (i.e., lower_bound(first1, last1, *m2)).
      // Actually, this loop stops at one position before that, except perhaps
      // if m1 == first1 (in which case one must compare *first1 with *m2).
      while (--m1 != first1 && !(*m1 < *m2)) {
      }
      
      // Test if all elements in [first1, last1) not less than *m2.
      bool result = (m1 == first1) && !(*first1 < *m2);
      
      if (!result) {

          // Find first first2 greater than *m1 (since *m1 < *m2, we know it
          // can't pass m2 and there's no need to test m2).
          while (first2 != m2 && !(*m1 < *first2)) {
              ++first2;
          }
          
          first1 = m1;
          std::iter_swap (first1, first2);
          ++first1;
          ++first2;
      }
      
      // Merge [first1, last1) with [first2, last2), given that the rest of the
      // original ranges are sorted and compare appropriately.
      if ((first1 != last1) && (first2 != last2)) {      
          for (m1 = last1, m2 = first2;  (m1 != first1) && (m2 != last2); ++m2) {
              std::iter_swap (--m1, m2);
          }
          
          std::reverse (first1, m1);
          std::reverse (first1, last1);
          
          std::reverse (m2, last2);
          std::reverse (first2, last2);
      }
      
      return !result;
  }
template<class BidirectionalIterator> 
  bool next_combination(BidirectionalIterator first,
                        BidirectionalIterator middle,
                        BidirectionalIterator last)
  {
    return next_combination(first, middle, middle, last);
  }

class PointyWizardHats {
	public:
	int getNumHats(vector <int> tH, vector <int> tR, vector <int> bH, vector <int> bR) {
		VI ww(5);
		REP(i, ww.size()) ww[i] = i;
		do {
			cout<<ww<<endl;
		} while(next_combination(ww.begin(), ww.begin()+3, ww.end()));
		
		//cout<<f(tH[0], tR[0], bH[0], bR[0])<<endl;
		int N=tH.size();
		int M=bH.size();
		Graph g(N+M+2);
		int S=N+M, T=N+M+1;
		REP(i, N) add_edge(g, S, i, 1);
		REP(i, M) add_edge(g, N+i, T, 1);
		REP(i, N) {
			REP(j, M) {
				if(f(tH[i], tR[i], bH[j], bR[j])) {
					add_edge(g, i, N+j, 1);
				}
			}
		}
		int ans = maximumFlow(g, S, T);
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
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, PointyWizardHats().getNumHats(topHeight, topRadius, bottomHeight, bottomRadius));}

//Fill(a, 1, 10000);
void Fill(vector<int>& a, int Min, int Max) {
	REP(i, a.size()) {
		a[i] = (int)(Min + (Max-Min) * (double)rand()/RAND_MAX);
	}
}

int main(){

CASE(0)
	int topHeight_[] = {30};
	  vector <int> topHeight(topHeight_, topHeight_+sizeof(topHeight_)/sizeof(*topHeight_)); 
	int topRadius_[] = {3};
	  vector <int> topRadius(topRadius_, topRadius_+sizeof(topRadius_)/sizeof(*topRadius_)); 
	int bottomHeight_[] = {3};
	  vector <int> bottomHeight(bottomHeight_, bottomHeight_+sizeof(bottomHeight_)/sizeof(*bottomHeight_)); 
	int bottomRadius_[] = {30};
	  vector <int> bottomRadius(bottomRadius_, bottomRadius_+sizeof(bottomRadius_)/sizeof(*bottomRadius_)); 
	int _ = 1; 
END
CASE(1)
	int topHeight_[] = {4,4};
	  vector <int> topHeight(topHeight_, topHeight_+sizeof(topHeight_)/sizeof(*topHeight_)); 
	int topRadius_[] = {4,3};
	  vector <int> topRadius(topRadius_, topRadius_+sizeof(topRadius_)/sizeof(*topRadius_)); 
	int bottomHeight_[] = {5,12};
	  vector <int> bottomHeight(bottomHeight_, bottomHeight_+sizeof(bottomHeight_)/sizeof(*bottomHeight_)); 
	int bottomRadius_[] = {5,4};
	  vector <int> bottomRadius(bottomRadius_, bottomRadius_+sizeof(bottomRadius_)/sizeof(*bottomRadius_)); 
	int _ = 1; 
END
CASE(2)
	int topHeight_[] = {3};
	  vector <int> topHeight(topHeight_, topHeight_+sizeof(topHeight_)/sizeof(*topHeight_)); 
	int topRadius_[] = {3};
	  vector <int> topRadius(topRadius_, topRadius_+sizeof(topRadius_)/sizeof(*topRadius_)); 
	int bottomHeight_[] = {1,1};
	  vector <int> bottomHeight(bottomHeight_, bottomHeight_+sizeof(bottomHeight_)/sizeof(*bottomHeight_)); 
	int bottomRadius_[] = {2,4};
	  vector <int> bottomRadius(bottomRadius_, bottomRadius_+sizeof(bottomRadius_)/sizeof(*bottomRadius_)); 
	int _ = 1; 
END
CASE(3)
	int topHeight_[] = {10,10};
	  vector <int> topHeight(topHeight_, topHeight_+sizeof(topHeight_)/sizeof(*topHeight_)); 
	int topRadius_[] = {2,5};
	  vector <int> topRadius(topRadius_, topRadius_+sizeof(topRadius_)/sizeof(*topRadius_)); 
	int bottomHeight_[] = {2,9};
	  vector <int> bottomHeight(bottomHeight_, bottomHeight_+sizeof(bottomHeight_)/sizeof(*bottomHeight_)); 
	int bottomRadius_[] = {3,6};
	  vector <int> bottomRadius(bottomRadius_, bottomRadius_+sizeof(bottomRadius_)/sizeof(*bottomRadius_)); 
	int _ = 2; 
END
CASE(4)
	int topHeight_[] = {3,4,5};
	  vector <int> topHeight(topHeight_, topHeight_+sizeof(topHeight_)/sizeof(*topHeight_)); 
	int topRadius_[] = {5,4,3};
	  vector <int> topRadius(topRadius_, topRadius_+sizeof(topRadius_)/sizeof(*topRadius_)); 
	int bottomHeight_[] = {3,4,5};
	  vector <int> bottomHeight(bottomHeight_, bottomHeight_+sizeof(bottomHeight_)/sizeof(*bottomHeight_)); 
	int bottomRadius_[] = {3,8,5};
	  vector <int> bottomRadius(bottomRadius_, bottomRadius_+sizeof(bottomRadius_)/sizeof(*bottomRadius_)); 
	int _ = 2; 
END
CASE(5)
	int topHeight_[] = {1,2,3,4,5};
	  vector <int> topHeight(topHeight_, topHeight_+sizeof(topHeight_)/sizeof(*topHeight_)); 
	int topRadius_[] = {2,3,4,5,6};
	  vector <int> topRadius(topRadius_, topRadius_+sizeof(topRadius_)/sizeof(*topRadius_)); 
	int bottomHeight_[] = {2,3,4,5,6};
	  vector <int> bottomHeight(bottomHeight_, bottomHeight_+sizeof(bottomHeight_)/sizeof(*bottomHeight_)); 
	int bottomRadius_[] = {1,2,3,4,5};
	  vector <int> bottomRadius(bottomRadius_, bottomRadius_+sizeof(bottomRadius_)/sizeof(*bottomRadius_)); 
	int _ = 0; 
END
CASE(6)
	int topHeight_[] = {123,214,232,323,342,343};
	  vector <int> topHeight(topHeight_, topHeight_+sizeof(topHeight_)/sizeof(*topHeight_)); 
	int topRadius_[] = {123,123,232,123,323,434};
	  vector <int> topRadius(topRadius_, topRadius_+sizeof(topRadius_)/sizeof(*topRadius_)); 
	int bottomHeight_[] = {545,322,123,545,777,999};
	  vector <int> bottomHeight(bottomHeight_, bottomHeight_+sizeof(bottomHeight_)/sizeof(*bottomHeight_)); 
	int bottomRadius_[] = {323,443,123,656,767,888};
	  vector <int> bottomRadius(bottomRadius_, bottomRadius_+sizeof(bottomRadius_)/sizeof(*bottomRadius_)); 
	int _ = 5; 
END
CASE(7)
	int topHeight_[] = {999,999,999,10000,10000,10000};
	  vector <int> topHeight(topHeight_, topHeight_+sizeof(topHeight_)/sizeof(*topHeight_)); 
	int topRadius_[] = {10000,10000,10000,1,2,3};
	  vector <int> topRadius(topRadius_, topRadius_+sizeof(topRadius_)/sizeof(*topRadius_)); 
	int bottomHeight_[] = {2324,2323,234,5454,323,232};
	  vector <int> bottomHeight(bottomHeight_, bottomHeight_+sizeof(bottomHeight_)/sizeof(*bottomHeight_)); 
	int bottomRadius_[] = {1,2,3222,434,5454,23};
	  vector <int> bottomRadius(bottomRadius_, bottomRadius_+sizeof(bottomRadius_)/sizeof(*bottomRadius_)); 
	int _ = 3; 
END
CASE(7)
	int topHeight_[] = {999,999,10000,10000,10000,999,999,10000,10000,10000,999,999,10000,10000,10000,999,999,10000,10000,10000,999,999,10000,10000,10000,999,999,10000,10000,10000,999,999,10000,10000,10000,999,999,10000,10000,10000,999,999,10000,10000,10000,999,999,10000,10000,10000,};
	  vector <int> topHeight(topHeight_, topHeight_+sizeof(topHeight_)/sizeof(*topHeight_)); 
	int topRadius_[] = {10000,10000,10000,1,2,10000,10000,10000,1,2,10000,10000,10000,1,2,10000,10000,10000,1,2,10000,10000,10000,1,2,10000,10000,10000,1,2,10000,10000,10000,1,2,10000,10000,10000,1,2,10000,10000,10000,1,2,10000,10000,10000,1,2,};
	  vector <int> topRadius(topRadius_, topRadius_+sizeof(topRadius_)/sizeof(*topRadius_)); 
	int bottomHeight_[] = {2324,2323,234,5454,323,2324,2323,234,5454,323,2324,2323,234,5454,323,2324,2323,234,5454,323,2324,2323,234,5454,323,2324,2323,234,5454,323,2324,2323,234,5454,323,2324,2323,234,5454,323,2324,2323,234,5454,323,2324,2323,234,5454,323,};
	  vector <int> bottomHeight(bottomHeight_, bottomHeight_+sizeof(bottomHeight_)/sizeof(*bottomHeight_)); 
	int bottomRadius_[] = {1,2,3222,434,5454,1,2,3222,434,5454,1,2,3222,434,5454,1,2,3222,434,5454,1,2,3222,434,5454,1,2,3222,434,5454,1,2,3222,434,5454,1,2,3222,434,5454,1,2,3222,434,5454,1,2,3222,434,5454,};
	  vector <int> bottomRadius(bottomRadius_, bottomRadius_+sizeof(bottomRadius_)/sizeof(*bottomRadius_)); 
	int _ = 3; 
END

}
// END CUT HERE


