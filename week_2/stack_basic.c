/*
from : http://dsalgo.openjudge.cn/dsmoochw3/2/
author : Guanghao Zhang
time : 2013/10/29
   */

#include<stdio.h>

int stack[200];
int top;
void clear(void) {
	top = 0;
}
void push(int k) {
	stack[top++] = k;
}
int pop(void) {
	top--;
	if(top == -1) {
		top = 0;
		return 0;
	} else {
		return 1;
	}
}

int main() {
	int m, n, i, k, flag;
	char opera[5];
	scanf("%d", &m);
	while(m--) {
		scanf("%d", &n);
		flag = 1;
		clear();
		while(n--) {
			scanf("%s", opera);
			if(opera[1] == 'u') {
				scanf("%d", &k);
				push(k);
			} else if(opera[1] == 'o') {
				flag = flag&pop();
			}
		}
		if(flag == 1) {
			for(i=0; i<top; i++) {
				printf("%d ", stack[i]);
			}
		} else {
			printf("error");
		}
		printf("\n");
	}
	return 0;
}
