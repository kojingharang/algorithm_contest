#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

#define T 30

int V;
int id[40][40];
bool graph[1010][1010];

void add_edge(int a, int b){
    graph[a][b] = graph[b][a] = true;
//	cout<<a<<"-"<<b<<endl;q
}

int main(void){
	cout<<"---------"<<endl;
    int i,j;
    
    V = 2;
    id[0][0] = 0;
    for(i=1;i<=T;i++) REP(j,i+1){
        id[i][j] = V;
        V++;
    }
    
    REP(i,T){
        REP(j,i+1) add_edge(id[i][j], id[i+1][j]);
        REP(j,i+1) add_edge(id[i][j], id[i+1][i+1]);
    }
    
    int K;
    cin >> K;
    
    REP(i,T) if(K&(1<<i)) add_edge(id[T][1+i], 1);
    
    cout << V << endl;
    REP(i,V){
        string s;
        REP(j,V) if(graph[i][j]) s += 'Y'; else s += 'N';
        printf("%s\n", s.c_str());
    }
    
    return 0;
}


