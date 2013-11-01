#include<stdio.h>

int main() {
	char a[15], b[5];
	int max, i;
	while(scanf("%s", a) != EOF) {
		scanf("%s", b);
		//printf("%s\n", a);
		//printf("%s\n", b);
		max = 0;
		for(i=1; a[i]!='\0'; i++) {
			if(a[i] > a[max])
				max = i;
		}
		for(i=0; a[i]!='\0'; i++) {
			printf("%c", a[i]);
			if(i == max) {
				printf("%s", b);
			}
		}
		printf("\n");
	}

	return 0;
}
