#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cassert>
#include <cstring>

using namespace std;

double res;

int N;
#define MAXN 128

double V;
double X;
double R[MAXN];
double C[MAXN];

#define EPS 1e-8

bool dbeq(double x, double y){
  return x - y < EPS && x - y > -EPS;
}

bool solve(){
  if(N == 1){
    if(!dbeq(C[0], X)){
      return false;
    }
    res = V / R[0];
    return true;
  }
  // N == 2
  bool ans = false;
  if(dbeq(C[0], X)){
    ans = true;
    res = V / R[0];
  }
  if(dbeq(C[1], X)){
    if(ans){
      res = V/(R[0] + R[1]);
    }else{
      res = V/R[1];
    }
    ans = true;
  }
  if(ans){
    return true;
  }
  if((C[0] < X && C[1] > X) ||
     (C[0] > X && C[1] < X)){
    double t0 = (X - C[1]) * V / (C[0] - C[1]) / R[0];
    double t1 = (V - t0 * R[0]) / R[1];
    res = max(t0, t1);
    return true;
  }
  return false;
}

int main(){
  size_t T;
  std::cin >> T;
  for(size_t i = 1; i <= T; ++i){
    std::cin >> N >> V >> X;
    for(int j = 0; j < N; ++j){
      cin >> R[j] >> C[j];
    }
    if(solve()){
      std::cout << "Case #" << i << ": " << fixed << setprecision(9) <<res << "\n";
    }else{
      std::cout << "Case #" << i << ": IMPOSSIBLE\n";
    }
  }
}
