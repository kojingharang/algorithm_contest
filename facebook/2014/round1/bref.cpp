#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<utility>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<queue>

#define MP(a,b)	make_pair(a,b)
#define ii pair<int,int>
#define MAX_N 110
#define LL long long
#define pll pair<long long,long long>
#define inf 1123123123
#define MOD 1000000007
using namespace std;
LL n,i,j,t,z,c,k,ans,tmp,a,a1,a2,l,p,pp,sisa;
void OPEN(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
int main(){
//	OPEN();
	scanf("%lld",&t);
	for(z=1;z<=t;z++){
		scanf("%lld %lld %lld",&n,&c,&k);
		ans=k;
		printf("Case #%lld: ",z);
		if(n>=c){
			printf("%lld\n",ans + n-c);
			continue;
		}
		l=c/n;
		if(k<=n*l){
			printf("%lld\n",ans);
			continue;
		}
		ans=n*c;
		p=l+1;
		sisa=n - c/(l+1);
		ans=k+ sisa;
		printf("%lld\n",ans);
	}
	return 0;
}