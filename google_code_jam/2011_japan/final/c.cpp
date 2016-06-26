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


int countstar(const string& a) {
	int ret = 0;
	REP(i, a.size()) if(a[i]=='*') ret++;
	return ret;
}

class LessPat {
public:
    bool operator()(const string& a, const string& b) const {
		if(a.size()!=b.size()) {
			return a.size()<b.size();
		} else {
			if(countstar(a) == countstar(b)) {
				return a<b;
			} else {
				return countstar(a) < countstar(b);
			}
		}
    }
};


int main()
{
	int TT;
	cin>>TT;
	//cout<<T<<endl;
	REP(t, TT)
	{
		string sa, sb;
		cin>>sa>>sb;
		//cout<<"sa "<<sa<<endl;
		//cout<<"sb "<<sb<<endl;
		
		int minl = 10000000;
		vector<string> ok;
		for(int xb=0;xb<sa.size();xb++)
		{
			for(int xs=1;xs<sa.size()-xb+1;xs++)
			{
				string pat = sa.substr(xb, xs);
				//cout<<pat<<endl;
				int pos = sb.find(pat);
				if(pos==string::npos)
				{
					if(xb>0) pat = "*"+pat;
					if(xb+xs<sa.size()) pat = pat+"*";
					//cout<<"pat "<<pat<<endl;
					if(pat.size() <= minl) {
						ok.push_back(pat);
						minl = min(minl, (int)pat.size());
					}
				}else if((xb==0 && xb!=pos) || (xb+xs==sa.size() && sb.size() != pos+pat.size()))
				{
					cout<<pos<<endl;
					if(xb>0) pat = "*"+pat;
					if(xb+xs<sa.size()) pat = pat+"*";
					cout<<"pat "<<pat<<endl;
					if(pat.size() <= minl) {
						ok.push_back(pat);
						minl = min(minl, (int)pat.size());
					}
				}
			}
		}
		sort(ok.begin(), ok.end(), LessPat());
		//REP(i, ok.size()) cout<<ok[i]<<endl;
		
		cout<<"Case #"<<t+1<<": "<<ok[0]<<endl;;
	}
	return 0;
}



