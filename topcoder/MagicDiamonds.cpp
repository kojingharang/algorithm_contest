#line 65 "MagicDiamonds.cpp"
#define ll long long
using namespace std;
int IsPrime(ll n){
    ll i;
 
    if(n < 2)
        return 0;
    else if(n == 2)
        return 1;
 
    if(n % 2 == 0)
        return 0;
 
    for(i = 3; i * i <= n; i += 2)
         if(n % i == 0)
            return 0;
    return 1;
}
class MagicDiamonds {
	public:
	long long minimalTransfer(long long n) {
		if(IsPrime(n)) return 2;
		else return 1;
	}
	

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
