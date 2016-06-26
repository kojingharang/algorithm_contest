};

class LuckySum {
	public:
	ll value(int pat, int di) {
		ll v=0;
		ll p=1;
		REP(i, di) {
			v += ((pat&1) ? 7 : 4)*p;
			p*=10;
			pat>>=1;
		}
		return v;
	}
	long long construct(string note) {
		if(0)
		{
			VI one, w;
			RANGE(di, 1, 14)
			REP(i, 1<<di) {
	//			cout<<value(i, di)<<endl;
				one.PB(value(i, di));
			}
			REP(i, one.size()) REP(j, one.size()) {
				w.PB(one[i]+one[j]);
			}
			sort(ALL(w));
//			cout<<w.size()<<endl;
			w.erase(unique(ALL(w)), w.end());
//			cout<<w.size()<<endl;
			REP(i, w.size()) {
				cout<<w[i]<<",";
				if(i%1000==0) cout<<endl;
			}
			return 0;
		}
		
		int co=0;
		int N=note.size();
		for(ll v : values) {
//			cout<<v<<endl;
			ll vv = v;
			int ok=1;
			REP(i, N) {
				if(vv==0) {ok=0;break;}
				if(note[N-1-i]!='?') {
					if(vv%10 != (note[N-1-i]-'0')) {ok=0;break;}
				}
				vv/=10;
			}
			if(ok) return v;
			co++;
			if(co>100) break;
		}
		return -1;
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const long long& Expected, const long long& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, LuckySum().construct(note));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string note = "?"; 
	long long _ = 8LL; 
END
//return 0;
CASE(1)
	string note = "?1"; 
	long long _ = 11LL; 
END
CASE(2)
	string note = "4?8"; 
	long long _ = 448LL; 
END
CASE(3)
	string note = "2??"; 
	long long _ = -1LL; 
END
CASE(4)
	string note = "??????????????"; 
	long long _ = 11888888888888LL; 
END
#if 0  // DO RANDOM TESTS

// INIT GLOBAL VARIABLES IN TRIAL CODE !!!!!!!!!!!!!!
// 1. Copy my class 
// 2. Add `Ref` suffix to my original class 
// 3. Write someone's code into copied class 
// 4. Run and verify example test case and random tests

#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
if(!allOK) return 0;
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<100;loop++) {
// param type: String
	string note; 
	{
		int N=UNIFORM_LL(1, 51);
		note = string(N, ' '); 
		string tb = "ABCDE";
		REP(i, N) {
			note[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
	long long _0 = LuckySum().construct(note);
	long long _1 = LuckySumRef().construct(note);
	if(!verify_case(_0, _1, true)) {
print(note);
	}
}
#endif

}
// END CUT HERE
