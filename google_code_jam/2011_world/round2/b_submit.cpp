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


int main()
{
	int T;
	cin>>T;
	//cout<<T<<endl;
	REP(ttt, T)
	{
		int R,C,D;
		cin>>R>>C>>D;
		vector<string> v(R);
		REP(i, R) cin>>v[i];
		
		for(int k=min(R, C)+1; k>=3; k--)
		{
			REP(y, R-k+1)
			{
				REP(x, C-k+1)
				{
					double cx = k/2.0;
					double cy = k/2.0;
					//cout<<"k x y "<<k<<" "<<x<<" "<<y<<"  c "<<cx<<" "<<cy<<endl;
					double wx = cx;
					double wy = cy;
					
					{
						double len = k/4.0;
						REP(loop, 100)
						{
							double www = 0.0;
							REP(yy, k) REP(xx, k)
							{
								if(yy==0&&xx==0||yy==k-1&&xx==0||yy==0&&xx==k-1||yy==k-1&&xx==k-1) continue;
								//cout<<"--- "<<D+(v[y+yy][x+xx]-'0')<<" "<<(xx+0.5-wx)<<endl;
								www += (double)(D+(v[y+yy][x+xx]-'0')) * (xx+0.5-wx);
							}
							wx += www>0.0 ? len : -len;
							//cout<<"$$ "<<www<<" "<<len<<" => "<<wx<<endl;
							len /= 2.0;
						}
					}
					{
						double len = k/4.0;
						REP(loop, 100)
						{
							double www = 0.0;
							REP(yy, k) REP(xx, k)
							{
								if(yy==0&&xx==0||yy==k-1&&xx==0||yy==0&&xx==k-1||yy==k-1&&xx==k-1) continue;
								//cout<<"--- "<<D+(v[y+yy][x+xx]-'0')<<" "<<(xx+0.5-wx)<<endl;
								www += (double)(D+(v[y+yy][x+xx]-'0')) * (yy+0.5-wy);
							}
							wy += www>0.0 ? len : -len;
							//cout<<"$$ "<<www<<" "<<len<<" => "<<wx<<endl;
							len /= 2.0;
						}
					}
					//cout<<"w "<<wx<<" "<<wy<<endl;
					if(fabs(cx-wx)<1e-6 && fabs(cy-wy)<1e-6)
					{
						cout<<"Case #"<<ttt+1<<": "<<k<<endl;
						goto END;
					}
				}
			}
		}
		
		
		cout<<"Case #"<<ttt+1<<": IMPOSSIBLE"<<endl;
		END:;
	}
	return 0;
}



