#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;

int main()
{
   int n,m;
   cin >> n >> m;
   bool onoff[100004];
   bool prime[100004];
   int occupy[100004];
   vector<int> primevec;
   memset( onoff, false, sizeof(onoff) );
   memset( occupy, -1, sizeof(occupy) );
   for( int i = 0 ; i < 100004; i++ ) prime[i] = true;
   prime[0] = false;
   prime[1] = false;
   for( int i = 2 ; i < 100004; i++ ){
      if( prime[i] ){
         primevec.push_back(i);
         for( int k = 2; k*i < 100004; k++ ){
            prime[k*i] = false;
         }
      }
   }
   int psize = primevec.size();
   for( int i = 0 ; i < m ; i++ ){
      char sign;
      int num;
      cin >> sign >> num;
      if( sign == '+' ){
         if( !onoff[num] ){
            /*do something*/
            if( num == 1 ){
               cout << "Success" << endl;
               onoff[num] = true;
            }
            else{
               vector<int> yakusu;
               int occupied = -1;
               for( int pi = 0 ; pi < psize; pi++ ){
                  int curprime = primevec[pi];
                  if( curprime > num ) break;
                  if( num % curprime==0 ){
                     if( occupy[curprime] != -1 ){
                        occupied = occupy[curprime];
                        break;
                     }
                     yakusu.push_back( curprime );
                  }
               }
               if( occupied == -1 ){
                cout << "Success" << endl;
                onoff[num] = true;
                int yakususize = yakusu.size();
                for( int k = 0 ; k < yakususize; k++ ){
                  //cout << yakusu[k] << "," ;
                  occupy[yakusu[k]] = num;
                }
                //cout << endl;
               }
               else{
                  cout << "Conflict with " << occupied << endl;
               }
            }
         }
         else{
            cout << "Already on" << endl;
         }
               
      }
      else{
         if( onoff[num] ){
            cout << "Success" << endl;
            onoff[num] = false;
            if( num != 1){
               for( int pi = 0 ; pi < psize ; pi++ ){
                  int curprime = primevec[pi];
                  if( curprime > num ) break;
                  if( num % curprime==0 ){
                     occupy[curprime] = -1;
                  }
               }
            }
         }
         else{
            cout << "Already off" << endl;
         }
      }
   }
   return 0;
}