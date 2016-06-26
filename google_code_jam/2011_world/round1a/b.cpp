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

int gcd ( int a, int b )
{
	if(a<b)
	{
		int tmp=a;
		a=b; b=tmp;
	}
	
	int c;
	while ( a != 0 ) {
	c = a; a = b%a;  b = c;
	}
	return b;
}

int main()
{
	int T;
	cin>>T;
	//cout<<T<<endl;
	REP(t, T)
	{
		int N, M;
		cin>>N>>M;
		string D[N];
		string L[M];
		REP(i, N) cin>>D[i];
		REP(i, M) cin>>L[i];
		//REP(i, N) cout<<D[i]<<endl;
		//REP(i, M) cout<<L[i]<<endl;
		
		cout<<"Case #"<<t+1<<":";
		REP(Li, M)
		{
			int lose[N];
			CLR(lose);
			REP(di, N)
			{
				// choose D[di]
				//cout<<"choose "<<D[di]<<endl;
				int ng[N];
				int nng=0;
				CLR(ng);
				REP(i, N)
				{
					if(D[di].SZ != D[i].SZ) {ng[i]=1;nng++;}
				}
				if(nng==N-1) continue;
				
				// begin guess
				REP(li, 26)
				{
					int contains=0;
					REP(i, N)
					{
						if(ng[i]) continue;
						if(D[i].find(L[Li][li])!=D[i].npos) { contains=1; break; }
					}
					if(contains)
					{
						char guess = L[Li][li];
						//cout<<"guess "<<guess<<endl;
						int revealed=0;
						REP(p, D[di].SZ)
						{
							if(D[di][p]==guess) {revealed=1;break;}
						}
						if(!revealed) lose[di]++;
						REP(i, N)
						{
							if(ng[i]) continue;
							REP(p, D[i].SZ)
							{
								if(D[di][p]==guess && D[i][p]!=guess || D[di][p]!=guess && D[i][p]==guess) {ng[i]=1;nng++;break;}
							}
						}
						if(nng==N-1) break;
					}
				}
			}
			int max = -1;
			int maxi = -1;
			REP(i, N)
			{
				//cout<<lose[i]<<endl;
				if(max<lose[i]) {max=lose[i];maxi=i;}
			}
			cout<<" "<<D[maxi];
		}
		cout<<endl;
	}
	return 0;
}



