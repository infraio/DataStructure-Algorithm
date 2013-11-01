#include<stdio.h>
#include<stdlib.h>
typedef struct NODE{
	int factor;
	int power;
	struct NODE * next;
} node;
typedef node* nodePtr;
nodePtr insert(nodePtr head, int f, int p);

int main() {
	int n;
	int f, p, flag;
	nodePtr head;
	scanf("%d", &n);
	while(n > 0) {
		head = malloc(sizeof(nodePtr));
		head->factor = -1;
		head->power = -1;
		head->next = NULL;
		flag = 0;
		scanf("%d", &f);
		scanf("%d", &p);
		while(flag == 0 || p >= 0) {
			//printf("%d %d\n", f, p);
			if(p >= 0) {
				head = insert(head, f, p);
			}
			else {
				flag = 1;
			}
			scanf("%d", &f);
			scanf("%d", &p);
		}
		while(head->power != -1) {
			if(head->factor != 0) {	
				printf("[ %d %d ] ", head->factor, head->power);
			}
			head = head->next;
		}
		printf("\n");
		n--;
	}
	return 0;
}

nodePtr insert(nodePtr head, int f, int p) {
	nodePtr newPtr, prePtr, nowPtr;
	newPtr = malloc(sizeof(nodePtr));
	newPtr->factor = f;
	newPtr->power = p;
	if(p > head->power) {
		newPtr->next = head;
		return newPtr;
	} else if(p == head->power) {
		head->factor += f;
		return head;
	} else {
		prePtr = head;
		nowPtr = head->next;
		while(p < nowPtr->power) {
			prePtr = nowPtr;
			nowPtr = nowPtr->next;
		}
		if(p == nowPtr->power) {
			nowPtr->factor += f;		
		} else {
			prePtr->next = newPtr;
			newPtr->next = nowPtr;
		}
		return head;
	}
}
