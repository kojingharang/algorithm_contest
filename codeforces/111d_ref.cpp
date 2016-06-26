#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,cp=1,tim,wnow;
int f[100100];
int ans[100100];
int hd[100100],ot[200200],nt[200200],w[200200],r[200200];
int dfn[100100],low[100100],pre[100100];
bool u[100100];
struct edge{
	int a,b,w,d;
}e[100100];
bool cmp(const edge &A,const edge &B){
	return A.w<B.w;
}
int bcj(const int x){
	if ( f[x]==x ) return x;
	return f[x]=bcj(f[x]);	
}
void add(const int x,const int y,const int z,const int u){
	ot[++cp]=y;
	w[cp]=z,r[cp]=u;
	nt[cp]=hd[x];
	hd[x]=cp;
}
void dfs(const int x)
{
	u[x]=1;
	dfn[x]=low[x]=(++tim);
	//cout<<x<<' '<<tim<<endl;
	for(int i=hd[x];i!=0 && w[i]==wnow;i=nt[i])
	if ( i!=pre[x] )
	{
		//cout<<i<<'?'<<pre[x]<<endl;
		int k=ot[i];
		if ( u[k]==0 )
		{
			pre[k]=i^1;
			dfs(k);
			if ( low[k]<low[x] ) low[x]=low[k];
			if ( low[k]>dfn[x] ) ans[r[i]]=2;
			//cout<<low[k]<<' '<<dfn[x]<<' '<<x<<' '<<k<<' '<<r[i]<<endl;
		}
		if ( u[k]==1 && low[k]<low[x] ) low[x]=low[k];		
	}
	if (low[x]==dfn[x] ) tim=dfn[x]-1;
	
}
void work()
{
	int s=1,t,o,p;
	while ( s<=m )
	{
		t=s;wnow=e[s].w;
		while ( e[t].w==e[s].w )
		{
			o=bcj(e[t].a);
			p=bcj(e[t].b);
			if ( o!=p ) 
			{
				ans[e[t].d]=1;
				add(o,p,e[t].w,e[t].d);
				add(p,o,e[t].w,e[t].d);
				u[o]=u[p]=0;
			}else ans[e[t].d]=0;
			++t;
		}
		//cout<<"===="<<endl;
		for(int i=s;i<t;++i)
			if ( bcj(e[i].a)!=bcj(e[i].b) )
			{
				//cout<<e[i].a<<' '<<e[i].b<<' '<<e[i].w<<endl;
				o=bcj(e[i].a);
				p=bcj(e[i].b);
				tim=0;
				if (!u[o]) dfs(o);
				tim=0;
				if (!u[p]) dfs(p);
			}
		for(int i=s;i<t;++i)
			f[bcj(e[i].a)]=bcj(e[i].b);
		s=t;
		//cout<<"===="<<endl;
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	memset(hd,0,sizeof(hd));
	memset(ans,0,sizeof(ans));
	memset(pre,0,sizeof(pre));
	for(int i=1;i<=n;++i) f[i]=i;
	for(int i=1;i<=m;++i) 
		scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].w),e[i].d=i;
	sort(e+1,e+1+m,cmp);
	e[m+1].w=e[m].w+10;
	work();
	for(int i=1;i<=m;++i)
	if ( ans[i]==0 ) printf("none\n");
		else if ( ans[i]==1 ) printf("at least one\n");
			else printf("any\n");
	return 0;
}
