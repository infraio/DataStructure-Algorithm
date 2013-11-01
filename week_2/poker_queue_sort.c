/*
from : http://dsalgo.openjudge.cn/dsmoochw3/1/
author : Guanghao Zhang
time : 2013/11/1
	*/

#include<stdio.h>

#define SIZE 110
int queue[10][SIZE]={0}, front[10], rear[10];

void clear(void) {
	int i;
	//front指向位置存储元素，rear指向位置不存储元素，队列为空即front==rear，队列满即front==(rear+1)%SIZE
	for(i=0; i<10; i++) {
		front[i] = 0;
		rear[i] = 0;
	}
}
void in_queue(int i, int index) {
	queue[i][rear[i]] = index;
	rear[i]++;
}
int out_queue(int i) {
	int index;
	if(front[i] == rear[i]) {
		return -1;
	} else {
		index = queue[i][front[i]];
		front[i]++;
		return index;
	}
}

int main() {
	char card[SIZE][5];
	int n, i, j, index, output[SIZE];
	clear();
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%s", card[i]);
		//printf("%s\n", card[i]);
		in_queue(card[i][1] - '0', i);
	}
	//for(i=1; i<10; i++) {
	//	printf("%d %d\n", front[i], rear[i]);
	//}
	j = 0;
	for(i=1; i<10; i++) {
		printf("Queue%d:", i);
		index = out_queue(i);
		while(index != -1) {
			printf("%s ", card[index]);
			output[j++] = index;
			index = out_queue(i);
		}
		printf("\n");
	}
	clear();
	for(j=0; j<n; j++) {
		in_queue(card[output[j]][0] - 'A', output[j]);
	}
	j = 0;
	for(i=0; i<4; i++) {
		printf("Queue%c:", 'A'+i);
		index = out_queue(i);
		while(index != -1) {
			printf("%s ", card[index]);
			output[j++] = index;
			index = out_queue(i);
		}
		printf("\n");
	}
	for(j=0; j<n; j++) {
		printf("%s ", card[output[j]]);
	}
	printf("\n");

	return 0;
}
