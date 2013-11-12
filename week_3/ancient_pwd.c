/*
from : 
author : Guanghao Zhang
create date : 2013/11/10
finish date :
原文字母与密码的对应关系是任意的，所以只统计次数，并用排序后的结果作为hash值，然后进行对比
*/

#include<stdio.h>
#include<string.h>

void mySort(int* a) {
	int i, j, x;
	for(i=1; i<26; i++) {
		x = a[i];
		for(j=i-1; j>=0&&x>a[j]; j--) {
				a[j+1] = a[j];
		}
		a[j+1] = x;
	}
}

int main() {
	char pwd[105], ori[105];
	int pCount[26] = {0}, oCount[26] = {0};
	int flag = 0, i;
	gets(pwd);
	gets(ori);
	//printf("%s\n%s\n", mySort(pwd), mySort(ori));
	for(i=0; pwd[i]!='\0'; i++) {
		pCount[pwd[i]-'A']++;
		oCount[ori[i]-'A']++;
	}
	mySort(pCount);
	mySort(oCount);
	for(i=0; i<26; i++) {
		if(pCount[i] != oCount[i]) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}
