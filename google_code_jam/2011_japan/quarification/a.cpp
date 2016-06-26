#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define ll long long
#define VI vector<int>
#define VVI vector<vector<int> >
//#define B begin()
//#define E end()
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


int main()
{
	int T;
	cin>>T;
	//cout<<T<<endl;
	REP(t, T)
	{
		int M, C, W;
		cin>>M>>C>>W;
		
		int A[200],B[200];
		REP(i, C) cin>>A[i]>>B[i];
		FORD(i, C-1, 0)
		{
			//cout<<i<<" "<<W<<endl;
			if(B[i]<W && W<B[i]+A[i]) W-=B[i];
			else if(W<=B[i]) W+=A[i]-1;
			assert(1<=W && W<=M);
		}
		
		cout<<"Case #"<<t+1<<": "<<W<<endl;;
	}
	return 0;
}



