/*
from : 
author : Guanghao Zhang
create date : 2013/11/10
finish date :
*/

#include<stdio.h>
#include<string.h>

int main() {
	char s[205];
	int i;
	while(1) {
		gets(s);
		if(strcmp(s, "ENDOFINPUT") == 0)
			break;
		gets(s);
		for(i=0; s[i]!='\0'; i++) {
			if(s[i] >= 'F' && s[i] <='Z')
				printf("%c", s[i] - 5);
			else if(s[i] >= 'A' && s[i] <='E')
				printf("%c", s[i] + 21);
			else
				printf("%c", s[i]);
		}
		printf("\n");
		gets(s);
	}
	return 0;
}
