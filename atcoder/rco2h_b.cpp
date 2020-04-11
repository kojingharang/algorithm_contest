#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <functional>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cassert>
using namespace std;

#define EPS 1e-12
#define ull unsigned long long
#define ll long long
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define RANGE(i,a,b) for(int i=(int)a,_b=(int)(b);(i)<_b;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
#define IN(v, lo, hi) ((lo)<=(v) && (v)<(hi))
#define DD(v) cerr<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

#define MOD 1000000007LL
#define INF (1LL<<60)

string gen(int i) {
	string s;
	while(i) {
		s = string(1, 'a'+(i%23)) + s;
		i/=23;
	}
	while(s.size()<3) s="a"+s;
	s[0] = 'z'-(s[0]-'a');
	return s;
}

ll toi(string s) {
	s[0] = ('z'-s[0])+'a';
//	DD(s);
	ll v = 0;
	REP(i, s.size()) {
		v = s[i]-'a' + v*23;
	}
	return v;
}

ll guess(const string& tb, string s) {
	REP(i, s.size()) {
		if(s[i]=='z' || s[i]=='y') {
//			DD(s);
//			DD(i);
//			DD(toi(s.substr(i, 3)));
			return (toi(s.substr(i, 3)) * 3 - i + 3000) % 3000;
		}
	}
	assert(0);
}
/*
q: bozbpzb
v: 121
i: 1388

zaazabzaczadzaezafzagzahzaizajzakzalzamzanzaozapzaqzarzaszatzauzavzawzbazbbzbczbdzbezbfzbgzbhzbizbjzbkzblzbmzbnzbozbpzbqzbrzbszbtzbuzbvzbwzcazcbzcczcdzcezcfzcgzchzcizcjzckzclzcmzcnzcozcpzcqzcrzcszctzcuzcvzcwzdazdbzdczddzdezdfzdgzdhzdizdjzdkzdlzdmzdnzdozdpzdqzdrzdszdtzduzdvzdwzeazebzeczedzeezefzegzehzeizejzekzelzemzenzeozepzeqzerzeszetzeuzevzewzfazfbzfczfdzfezffzfgzfhzfizfjzfkzflzfmzfnzfozfpzfqzfrzfszftzfuzfvzfwzgazgbzgczgdzgezgfzggzghzgizgjzgkzglzgmzgnzgozgpzgqzgrzgszgtzguzgvzgwzhazhbzhczhdzhezhfzhgzhhzhizhjzhkzhlzhmzhnzhozhpzhqzhrzhszhtzhuzhvzhwziazibziczidziezifzigzihziizijzikzilzimzinziozipziqzirziszitziuzivziwzjazjbzjczjdzjezjfzjgzjhzjizjjzjkzjlzjmzjnzjozjpzjqzjrzjszjtzjuzjvzjwzkazkbzkczkdzkezkfzkgzkhzkizkjzkkzklzkmzknzkozkpzkqzkrzkszktzkuzkvzkwzlazlbzlczldzlezlfzlgzlhzlizljzlkzllzlmzlnzlozlpzlqzlrzlszltzluzlvzlwzmazmbzmczmdzmezmfzmgzmhzmizmjzmkzmlzmmzmnzmozmpzmqzmrzmszmtzmuzmvzmwznaznbznczndzneznfzngznhzniznjznkznlznmznnznoznpznqznrznszntznuznvznwzoazobzoczodzoezofzogzohzoizojzokzolzomzonzoozopzoqzorzoszotzouzovzowzpazpbzpczpdzpezpfzpgzphzpizpjzpkzplzpmzpnzpozppzpqzprzpszptzpuzpvzpwzqazqbzqczqdzqezqfzqgzqhzqizqjzqkzqlzqmzqnzqozqpzqqzqrzqszqtzquzqvzqwzrazrbzrczrdzrezrfzrgzrhzrizrjzrkzrlzrmzrnzrozrpzrqzrrzrszrtzruzrvzrwzsazsbzsczsdzsezsfzsgzshzsizsjzskzslzsmzsnzsozspzsqzsrzsszstzsuzsvzswztaztbztcztdzteztfztgzthztiztjztkztlztmztnztoztpztqztrztszttztuztvztwzuazubzuczudzuezufzugzuhzuizujzukzulzumzunzuozupzuqzurzuszutzuuzuvzuwzvazvbzvczvdzvezvfzvgzvhzvizvjzvkzvlzvmzvnzvozvpzvqzvrzvszvtzvuzvvzvwzwazwbzwczwdzwezwfzwgzwhzwizwjzwkzwlzwmzwnzwozwpzwqzwrzwszwtzwuzwvzwwyaayabyacyadyaeyafyagyahyaiyajyakyalyamyanyaoyapyaqyaryasyatyauyavyawybaybbybcybdybeybfybgybhybiybjybkyblybmybnyboybpybqybrybsybtybuybvybwycaycbyccycdyceycfycgychyciycjyckyclycmycnycoycpycqycrycsyctycuycvycwydaydbydcyddydeydfydgydhydiydjydkydlydmydnydoydpydqydrydsydtyduydvydwyeayebyecyedyeeyefyegyehyeiyejyekyelyemyenyeoyepyeqyeryesyetyeuyevyewyfayfbyfcyfdyfeyffyfgyfhyfiyfjyfkyflyfmyfnyfoyfpyfqyfryfsyftyfuyfvyfwygaygbygcygdygeygfyggyghygiygjygkyglygmygnygoygpygqygrygsygtyguygvygwyhayhbyhcyhdyheyhfyhgyhhyhiyhjyhkyhlyhmyhnyhoyhpyhqyhryhsyhtyhuyhvyhwyiayibyicyidyieyifyigyihyiiyijyikyilyimyinyioyipyiqyiryisyityiuyivyiwyjayjbyjcyjdyjeyjfyjgyjhyjiyjjyjkyjlyjmyjnyjoyjpyjqyjryjsyjtyjuyjvyjwykaykbykcykdykeykfykgykhykiykjykkyklykmyknykoykpykqykryksyktykuykvykwylaylbylcyldyleylfylgylhyliyljylkyllylmylnyloylpylqylrylsyltyluylvylwymaymbymcymdymeymfymgymhymiymjymkymlymmymnymoympymqymrymsymtymuymvymwynaynbyncyndyneynfyngynhyniynjynkynlynmynnynoynpynqynrynsyntynuynvynwyoayobyocyodyoeyofyogyohyoiyojyokyolyomyonyooyopyoqyoryosyotyouyovyowypaypbypcypdypeypfypgyphypiypjypkyplypmypnypoyppypqyprypsyptypuypvypwyqayqbyqcyqdyqeyqfyqgyqhyqiyqjyqkyqlyqmyqnyqoyqpyqqyqryqsyqtyquyqvyqwyrayrbyrcyrdyreyrfyrgyrhyriyrjyrkyrlyrmyrnyroyrpyrqyrryrsyrtyruyrvyrwysaysbyscysdyseysfysgyshysiysjyskyslysmysnysoyspysqysryssystysuysvyswytaytbytcytdyteytfytgythytiytjytkytlytmytnytoytpytqytrytsyttytuytvytwyuayubyucyudyueyufyugyuhyuiyujyuk
*/
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,M,Q;
	while(cin>>N>>M>>Q) {
		string s;
		REP(i, 1000) {
			s += gen(i);
		}
		s = s.substr(0, N);
		DD(s);
		DD(s.size());
		
		DD(toi("zaa"));
		DD(toi("yuk"));
//		DD(guess(s, "hyyhzyi")); // 2647
		cout<<s<<endl;
		cout<<"1.0"<<endl;
//return 0;
		VI ans(Q);
		REP(i, Q) {
			string q;
			cin>>q;
			ll v = guess(s, q);
			ans[i] = v;
			if(v<0 || v>=N) {
				DD(i);
				DD(q);
				DD(v);
				assert(0);
			}
		}
		REP(i, Q) {
//			DD(ans[i]);
			cout<<ans[i]<<endl;
		}
		return 0;
	}
	
	return 0;
}
