#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int INF = 99999999;

int gprime[20];
int A[20], N, K, B[20], n;

int status[155];
int *dyn[20][1 << 15];
int wprime[50];

int procss() {
	int res = 0;
	sort(A, A + N);
	if (A[N - 1] <= 1) {
		for (int i = 1; i < N; i++) A[i] = 1;
		for (int i = 0; i < N; i++) {
			res += A[i];
		}
		return res;
	}
	n = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] == 0) A[i] = 1;
		if (A[i] != 1) {
			B[n++] = A[i];
		}
		else {
			res++;
		}
	}

	int dysol = INF;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (1 << 15); j++) {
			for (int k = 0; k < B[i]; k++) {
				dyn[i][j][k] = INF;
			}
			for (int k = B[i]; k <= gprime[i]; k++) {
				dyn[i][j][k] = INF;

				if (i == 0) {
					if (status[k] == j ||
						(status[k] == -1 && j == 0)) dyn[i][j][k] = k;
				}
				else {
					int lastK = k - 1;
					if (lastK > gprime[i - 1]) lastK = gprime[i - 1];
					if (status[k] == -1) { // no status change
						dyn[i][j][k] = dyn[i - 1][j][lastK] + k;
					}
					else {
						int S = status[k];
						if ((S & j) == S) {
							dyn[i][j][k] = dyn[i - 1][j^S][lastK] + k;
						}
					}
				}

				dyn[i][j][k] = min(dyn[i][j][k], dyn[i][j][k - 1]);
				if (dyn[i][j][k] > INF) dyn[i][j][k] = INF;

				if (i == n - 1) {
					dysol = min(dysol, dyn[i][j][k]);
				}
			}
		}
	}
	res += dysol;
	return res;
}
int main() {
	int cnt = 0;
	for (int i = 2;; i++) {
		if (i == 50) cnt = 0;
		bool notprime = false;
		for (int j = 2; j < i; j++) if (i % j == 0) notprime = true;

		if (!notprime) {
			if (i < 50) {
				wprime[cnt++] = i;
			}
			else {
				gprime[cnt++] = i;
				status[i] = -1;
				if (cnt >= 20) {
					break;
				}
			}
		}
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < (1 << 15); j++) {
			dyn[i][j] = new int[gprime[i] + 1];
		}
	}
	for (int i = 2; i <= 150; i++) {
		if (status[i] == -1) continue;
		status[i] = 0;
		for (int j = 0; j < 15; j++) {
			if (i % wprime[j] == 0) status[i] |= (1 << j);
		}
	}
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	freopen("preventing_alzheimers.txt", "r", stdin);
	freopen("preventing_alzheimers.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T-- > 0) {
		scanf("%d %d", &N, &K);
		int sumA = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &A[i]);
			sumA += A[i];
		}

		for (int i = 0; i < N; i++) {
			if (A[i] % K > 0) {
				A[i] += (K - A[i] % K);
			}
			A[i] /= K;
		}

		int sum = procss() * K;
		static int cs = 1;
		printf("Case #%d: ", cs++);
		printf("%d", sum - sumA);
		printf("\n");
	}
	return 0;
}
