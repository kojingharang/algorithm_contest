// Hacker Cup 2017
// Round 2
// Big Top
// Jacob Plachta

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
using namespace std;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define Fox(i,n) for (i=0; i<n; i++)
#define Fox1(i,n) for (i=1; i<=n; i++)
#define FoxI(i,a,b) for (i=a; i<=b; i++)
#define FoxR(i,n) for (i=(n)-1; i>=0; i--)
#define FoxR1(i,n) for (i=n; i>0; i--)
#define FoxRI(i,a,b) for (i=b; i>=a; i--)
#define Foxen(i,s) for (i=s.begin(); i!=s.end(); i++)
#define Min(a,b) a=min(a,b)
#define Max(a,b) a=max(a,b)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x<0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }

const int INF = (int)1e9;
const LD EPS = 1e-9;
const LD PI = acos(-1.0);

bool Read(int &x)
{
	char c,r=0,n=0;
	x=0;
		for(;;)
		{
			c=getchar();
				if ((c<0) && (!r))
					return(0);
				if ((c=='-') && (!r))
					n=1;
				else
				if ((c>='0') && (c<='9'))
					x=x*10+c-'0',r=1;
				else
				if (r)
					break;
		}
		if (n)
			x=-x;
	return(1);
}

LL ans;
set<PR> S;

LL Area(PR a,PR b)
{
	LD o=max((LD)0,(LD)a.y+b.y-((LD)b.x-a.x));
	return((LL)a.y*a.y*2 + (LL)b.y*b.y*2 - o*o);
}

void Add(PR p)
{
	set<PR>::iterator I,J;
	S.insert(p);
	I=J=S.find(p),I--,J++;
	ans-=Area(*I,*J);
	ans+=Area(*I,p)+Area(p,*J);
}

void Del(set<PR>::iterator J)
{
	set<PR>::iterator I,K;
	I=K=J,I--,K++;
	ans-=Area(*I,*J)+Area(*J,*K);
	ans+=Area(*I,*K);
	S.erase(J);
}

int main()
{
	int T,t;
	int N;
	int X,Ax,Bx,Cx;
	int H,Ah,Bh,Ch;
	PR p;
	LL tot;
	set<PR>::iterator I,J,K;
	Read(T);
		Fox1(t,T)
		{
			S.clear();
			S.insert(mp(-INF-5,0));
			S.insert(mp(INF*2+5,0));
			ans=tot=0;
			Read(N);
			Read(X),Read(Ax),Read(Bx),Read(Cx);
			Read(H),Read(Ah),Read(Bh),Read(Ch);
				while (N--)
				{
					p=mp(X,H);
					I=J=S.lower_bound(p),I--;
						if (p.y<=(I->y)-(p.x-(I->x)))
							goto Skip;
						if (p.y<=(J->y)-((J->x)-p.x))
							goto Skip;
						while ((I->y)<=p.y-(p.x-(I->x)))
						{
							K=I,I--;
							Del(K);
						}
						while ((J->y)<=p.y-((J->x)-p.x))
						{
							K=J,J++;
							Del(K);
						}
					Add(p);
Skip:;
					tot+=ans;
					X=((LL)Ax*X+Bx)%Cx+1;
					H=((LL)Ah*H+Bh)%Ch+1;
				}
//			printf("Case #%d: %lld.%lld\n",t,tot/4,(tot%4)*25);
			printf("Case #%d: %.9f\n",t,tot/4.0);
		}
	return(0);
}
