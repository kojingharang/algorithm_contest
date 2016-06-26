#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <stdio.h>
#include <string.h>
#include <assert.h>

using namespace std;
static const double EPS = 1e-9;
int ROUND(double x) { return (int)(x+0.5); }
bool ISINT(double x) { return fabs(ROUND(x)-x)<=EPS; }
bool ISEQUAL(double x,double y) { return fabs(x-y)<=EPS*max(1.0,max(fabs(x),fabs(y))); }
double SQSUM(double x,double y) { return x*x+y*y; }
template<class T> bool INRANGE(T x,T a,T b) { return a<=x&&x<=b; }
#define PI  (acos(-1))
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define NG (-1)
#define BIG (987654321)
#define SZ(a) ((int)((a).size()))
#define SQ(a) ((a)*(a))
typedef long long ll;
typedef unsigned long long ull;

#define FOR(v,i) for(__typeof((v).begin())i=(v).begin();i!=(v).end();++i)
// BEGIN CUT HERE
#undef FOR
#define FOR(v,i) for(auto i=(v).begin();i!=(v).end();++i)
// END CUT HERE

#define PRINTF(fmt,...) fprintf(fp,fmt,__VA_ARGS__); fprintf(stderr,fmt,__VA_ARGS__);

int main()
{
	FILE* fp;
	fp = fopen("output.txt","w");
	if(fp)
	{
		int T;
		cin >> T;
		for (int testcase = 0; testcase < T; testcase++)
		{
			string s,ans;
			unsigned long long n;

			cin >> s >> n;
			n--;
			const unsigned int len = s.size();

			while(1)
			{
				ans = s[n%len] + ans;
				n /= len;
				if(n==0)
				{
					break;
				}
				n--;
			}

			PRINTF("Case #%d: %s\n",testcase+1,ans.c_str());
		}
		fclose(fp);
	}
}


