/*
from : 
author : Guanghao Zhang
create date : 2013/11/10
finish date :
*/

#include<stdio.h>

int main() {
	int n, i, max_c, max_i;
	char s[1010];
	int count[26];
	scanf("%d\n", &n);
	while(n--) {
		for(i=0; i<26; i++)
			count[i] = 0;
		gets(s);
		for(i=0; s[i]!='\0'; i++) {
			count[s[i]-'a']++;
		}
		max_c = count[0];
		max_i = 0;
		for(i=1; i<26; i++) {
			//printf("%d ", count[i]);
			if(count[i] > max_c) {
				max_c = count[i];
				max_i = i;
			}
		}
		gets(s);
		printf("%c %d\n", 'a'+max_i, max_c);
	}
	return 0;
}
