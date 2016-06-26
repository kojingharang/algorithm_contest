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


int main()
{
	int T;
	cin>>T;
	//cout<<T<<endl;
	REP(t, T)
	{
		int N;
		cin>>N;
		string sc[N];
		double WP[N];
		double OWP[N];
		double OOWP[N];
		CLR(WP);
		CLR(OWP);
		CLR(OOWP);
		REP(i, N){ cin>>sc[i]; }
		REP(i, N)
		{
			{
				int win=0, all=0;
				REP(j, N)
				{
					if(sc[i][j]!='.')
					{
						win += sc[i][j]=='1';
						all++;
					}
				}
				WP[i] = (double)win/all;
			}
			{
				int _all=0;
				REP(j, N)
				{
					if(sc[i][j]!='.')
					{
						_all++;
						// calc wp of j except i
						int win=0, all=0;
						REP(k, N)
						{
							if(k==i) continue;
							if(sc[j][k]!='.')
							{
								win += sc[j][k]=='1';
								all++;
							}
						}
						OWP[i] += (double)win/all;
					}
				}
				OWP[i] /= (double)_all;
			}
		}
		cout<<"Case #"<<t+1<<":"<<endl;
		REP(i, N)
		{
			int all=0;
			REP(j, N)
			{
				if(sc[i][j]!='.')
				{
					OOWP[i] += OWP[j];
					all++;
				}
			}
			OOWP[i] /= all;
			double RPI = 0.25 * WP[i] + 0.50 * OWP[i] + 0.25 * OOWP[i];
			cout<<RPI<<endl;
		}
		cout<<endl;
	}
	return 0;
}



