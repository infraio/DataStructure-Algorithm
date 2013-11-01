/*
from : http://dsalgo.openjudge.cn/dsmoochw3/3/
author : Guanghao Zhang
time : 2013/11/01
   */

#include<stdio.h>

int main() {
	int i, t, n, type, value;
	int queue[2013]={-1}, front=0, rear=0;
	int stack[2013]={-1}, top=0;
	int flag = 0, stack_pop, queue_out;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		flag = 0;
		front = 0;
		rear = 0;
		top = 0;
		while(n--) {
			scanf("%d %d", &type, &value);
			if(flag != 0)
				continue;
			if(type == 1) {
				stack[top++] = value;
				queue[rear++] = value;
			} else if(type == 2) {
				if(top == 0) {
					flag = 2;
				} else if(front == rear) {
					flag = 1;
				} else {
					stack_pop = stack[--top];
					queue_out = queue[front++];
					if(stack_pop != queue_out) {
						if(stack_pop == value) {
							flag = 1;
						} else if(queue_out == value) {
							flag = 2;
						}
					}
				}
			}
			/*for(i=0; i<top; i++) {
				printf("%d ", stack[i]);
			}
			printf("\n");
			for(i=front; i<rear; i++) {
				printf("%d ", queue[i]);
			}
			printf("\n");*/
		}
		if(flag == 1) {
			printf("Stack\n");
		} else if(flag == 2) {
			printf("Queue\n");
		}
	}
	return 0;
}
