/*
from : 
author : Guanghao Zhang
create date : 2013/11/10
finish date :
*/

#include<stdio.h>

char s[1000005];
int next[1000005];

void get_next(int n);

int main() {
	int case_num = 0, n;
	int i, j, k, flag;
	char temp;
	scanf("%d", &n);
	while(n) {
		/*
		flag = getchar();
		temp = getc(stdin);
		*/
		scanf("%c", &temp);
		case_num++;
		scanf("%s", s);
		/*
		for(i=0; i<n; i++) {
			scanf("%c", &s[i]);
		}
		*/
		printf("Test case #%d\n", case_num);
		get_next(n);
		/*
		for(i=0; i<=n; i++)
			printf("%d ", next[i]);
		printf("\n");
		*/
		for(i=2; i<=n; i++) {
			j = i - next[i];
			k = i/j;
			if(i%j == 0 && k > 1) {
				printf("%d %d\n", i, k);
			}
		}
		printf("\n");
		scanf("%d", &n);
	}
	return 0;
}

void get_next(int n){
	int i, j, k;
	next[0] = -1; next[1] = 0;
	k = 0;
	for(j=1; j<n; j++) {
		while(k >= 0 && s[j]!= s[k])
			k = next[k];
		k++;
		next[j+1] = k;
	}
}
