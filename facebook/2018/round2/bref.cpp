#include <stdio.h>

double V[3030],D[3030],C[3030][3030];

void proc()
{
	int N,K; double p; scanf ("%d %d %lf",&N,&K,&p);
	C[0][0] = 1;
	for (int i=1;i<=N;i++){
		for (int j=0;j<=i;j++){
			C[i][j] = (1 - p) * C[i-1][j];
			if (j) C[i][j] += p * C[i-1][j-1];
		}
	}
	for (int i=0;i<=N;i++){
		V[i] = 0;
		for (int j=K;j<=i;j++) V[i] += C[i][j];
	}
	for (int i=1;i<=N;i++){
		D[i] = 0;
		for (int j=1;j<=i;j++){
			if (D[i] < D[i-j] + V[j])
				D[i] = D[i-j] + V[j];
		}
	}
	printf ("%.12lf\n",D[N]);
}

int main()
{
//	freopen ("input.txt","r",stdin);
//	freopen ("output.txt","w",stdout);

	int Test; scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		printf ("Case #%d: ",Case);
		proc();
	}

	return 0;
}