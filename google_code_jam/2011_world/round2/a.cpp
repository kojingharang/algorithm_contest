#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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


class Pr
{
public:
  bool operator()(const VI& x, const VI& y) const {
    return x[2] < y[2];
  }
};

int main()
{
	int T;
	cin>>T;
	//cout<<T<<endl;
	REP(ttt, T)
	{
		int X, S, R, t, N;
		cin>>X>>S>>R>>t>>N;
		int walkL = X;
		
		VVI ww;
		REP(i, N)
		{
			VI w(3);
			cin>>w[0]>>w[1]>>w[2];
			w[2]+=S;
			ww.PB(w);
			walkL -= w[1]-w[0];
		}
		VI w(3);
		w[0] = 0; w[1] = walkL; w[2] = S;
		ww.PB(w);
		
		sort(ww.B, ww.E, Pr());
		//cout<<ww<<endl;
		
		double restt = t;
		double total = 0.0;
		REP(i, ww.SZ)
		{
			double rL = (ww[i][2]+R-S) * restt;
			//cout<<i<<" restt "<<restt<<" rL "<<rL<<endl;
			if(rL<ww[i][1]-ww[i][0])
			{
				total += restt;
				total += (ww[i][1]-ww[i][0] - rL)/(double)ww[i][2];
				restt=0;
			}
			else
			{
				double rT = (ww[i][1]-ww[i][0])/(double)(ww[i][2]+R-S);
				total += rT;
				restt-=rT;
			}
			//cout<<"total "<<total<<endl;
		}
		
		cout<<"Case #"<<ttt+1<<": ";
		printf("%f\n", total);
	}
	return 0;
}



