#include <cstdio>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int n, T, k;
string s[310];
int trans[310][310], dp[310][310];

int doit() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	sort(s + 1, s + n + 1);
	int ans = 1e9;
	for (int j = 0; j <= n; j++)
	for (int i = 1; i <= k; i++)
		dp[j][i] = 1e9;
	for (int i = 1; i < n; i++) 
		for (int j = i + 1; j <= n; j++) {
		int l = 0;
		while (l < s[i].size() && l < s[j].size() && s[i][l] == s[j][l])
			l += 1;
		trans[i][j] = s[i].size() + s[j].size() - 2 * l;
	}
	for (int i = 1; i <= n; i++) {
		dp[i][1] = s[i].size();
		for (int p = i + 1; p <= n; p++)
			for (int j = 1; j < k; j++) {
				dp[p][j + 1] = min(dp[p][j + 1], dp[i][j] + trans[i][p]);
			}
		ans = min(ans, dp[i][k] + (int) s[i].size());
	}
	

	return ans + k;
}

int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
		printf("Case #%d: %d\n", i, doit());
}

