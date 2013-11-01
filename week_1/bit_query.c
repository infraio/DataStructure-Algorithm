#include<stdio.h>

void cal(int n, int d);

int a[100001];
int count[16] = {0};

int main() {
	int n, m, i, d;
	char c[5], temp;
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	cal(n, 0);
	scanf("%c", &temp);
	for(i=0; i<m; i++) {
		gets(c);
		//printf("%s\n", c);
		if(c[3] == '\0') {
			d = c[2] - '0';
		} else {
			d = 10*(c[2] - '0') + c[3] - '0';
		}
		if(c[0] == 'Q')
			printf("%d\n", count[d]);
		else if(c[0] == 'C') {
			cal(n, d);
		}
	}
	return 0;
}

void cal(int n, int d) {
	int i, j, num;
	for(i=0; i<=15; i++)
		count[i] = 0;
	if(d != 0) {
		for(i=0; i<n; i++)
			a[i] = (a[i] + d) % 65536;
	}
	for(i=0; i<n; i++) {
		num = a[i];
		for(j=0; num!=0; j++) {
			count[j] = count[j] + num%2;
			num = num/2;
		}
	}
	/*for(i=0; i<=15; i++) {
		printf("%d ", count[i]);
	}
	printf("\n");*/
}
