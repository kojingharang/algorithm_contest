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
#define REP(i, n) for(ll i=0, _n=(n);(i)<_n;i++)
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

int f(ll a)
{
	int r = 0;
	REP(i, sizeof(ll)*8)
	{
		r += ((a>>i) & 1) ? 1 : 0;
	}
	return r;
}

ll be[200], si[200];
int n_entry;
ll total_s;

// fill from right
void add_list(ll _end, ll _size, int _s)
{
	cout<<"add_list "<<_end<<" "<<_size<<" "<<_s<<endl;
	
	for(int i=n_entry-1; i>=0; i--)
	{
		if( be[i] <= _end)
		{
			ll maxput = _end-be[i]+1;
			ll put = min(maxput, _size);
			
			// update free list
			if(maxput=put) be[i] = _end+1;
			else if(be[i]+si[i]-1==_end) si[i]-=put;
			else {
				// shift
				for(int j=n_entry-1; j>=i+1;j--)
				{
					be[j+1] = be[j];
					si[j+1] = si[j];
				}
				si[i] = maxput-put;
				be[i+1] = _end+1;
				si[i+1] = si[i] - maxput;
				n_entry++;
			}
			
			_end-=put;
			_size-=put;
			total_s += _s * put;
			if(_size==0) return;
		}
	}
}

int main()
{
	int TT;
	cin>>TT;
	//cout<<T<<endl;
	REP(t, TT)
	{
		int N;
		ll K;
		cin>>N>>K;
		
		total_s = 0;
		// free list
		n_entry = 1;
		be[0] = 1;
		si[0] = K;
		
		REP(i, N)
		{
			int C,T,S;
			cin>>C>>T>>S;
			if(C>T) C=T;
			// add to free list
			add_list(T, T-C+1, S);
		}
		cout<<"Case #"<<t+1<<": "<<total_s<<endl;;
	}
	return 0;
}



