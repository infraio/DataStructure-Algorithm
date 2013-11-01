#include<stdio.h>

int main() {
	int t, n, m;
	
	int i, j, ans[15][15];
	for(i=0; i<15; i++) {
		for(j=0; j<15; j++) {
			if(j == 0)
				ans[i][j] = 0;
			else if(j == 1)
				ans[i][j] = 1;
			else if(i == 0)
				ans[i][j] = 1;
			else if(i < j)
				ans[i][j] = ans[i][i];
			else
				ans[i][j] = ans[i][j-1] + ans[i-j][j];
			//printf("%d ", ans[i][j]);
		}
		//printf("\n");
	}

	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		printf("%d\n", ans[n][m]);
	}

	return 0;
}
