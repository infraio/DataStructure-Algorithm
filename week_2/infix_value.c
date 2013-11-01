/*
from : http://dsalgo.openjudge.cn/dsmoochw3/4/
author : Guanghao Zhang
time : 2013/10/29
   */

#include<stdio.h>

int mycmp(char a, char b) {
	if(b == '(')
		return 1;//左括号直接入栈
	else if((b == '*' || b == '/') &&(a == '+' || a == '-' || a == '('))
		return 1;//*、/优先级高于+、-、(，入栈
	else if((b == '+' || b == '-') && (a == '('))
		return 1;//+、-优先级高于(，入栈
	else
		return 0;
}

/*中缀表达式转后缀表达式
 中缀表达式之间无分割
 后缀表达式操作数、操作符之间用空格分割，便于区分不同操作数*/
void infix_to_suffix(char* infix, char* suffix) {
	int i, k, j=0, top=0;
	char stack[1000];//存储运算符的栈

	for(i=0; infix[i]!='\0'; i++) {
		if(infix[i] >= '0' && infix[i] <= '9') {
			suffix[j++] = infix[i];//操作数则直接输出
		} else {
			if(i != 0 && infix[i-1] >= '0' && infix[i-1] <= '9') {
				suffix[j++] = ' ';//操作数后补充空格分割
			}
			if(infix[i] == ')') {
				//遇到右括号则一直弹出直到左括号，但左括号不输出
				while(stack[top-1] != '(') {
					suffix[j++] = stack[--top];
					suffix[j++] = ' ';
				}
				top--;
			} else if(top == 0 || mycmp(stack[top-1], infix[i])) {
				//栈为空或当前操作符的优先级高于栈顶操作符，当前操作符入栈
				stack[top++] = infix[i];
			} else {
				//当前操作符优先级等于或低于栈顶操作符则弹出栈顶
				while(!mycmp(stack[top-1], infix[i])) {
					suffix[j++] = stack[--top];
					suffix[j++] = ' ';
					if(top == 0)
						break;
				}
				stack[top++] = infix[i];//当前操作符入栈
			}
		}
		//suffix[j] = '\0';
		//printf("suffix=%s\nstack : ", suffix);
		//for(k=0; k<top; k++)
		//	printf("%c ", stack[k]);
		//printf("\n");
	}
	//补充空格分割
	if(suffix[j-1] != ' ') {
		suffix[j++] = ' ';
	}
	//如果操作符栈不为空，弹出所有操作符
	while(top != 0) {
		suffix[j++] = stack[--top];
		suffix[j++] = ' ';
	}
	suffix[j] = '\0';
	//printf("%s\n", suffix);
}
/*后缀表达式求值*/
int suffix_value(char* suffix) {
	int i, j;
	char op;
	int stack[1000];
	int top = 0, value = 0;
	//printf("%s\n", suffix);
	for(i=0; suffix[i] != '\0'; i++) {
		if(suffix[i] >= '0' && suffix[i] <= '9') {
			value = value*10 + suffix[i] - '0';
			//printf("%d\n", value);
		} else if(suffix[i] == ' ') {
			//操作数入栈
			stack[top++] = value;
			//for(j=0; j<top; j++) {
			//	printf("%d ", stack[j]);
			//}
			//printf("\n");
			value = 0;
		} else {
			//根据操作符，对栈顶两个操作数进行计算并得到结果
			switch(suffix[i]) {
				case '+': value = stack[top-2] + stack[top-1];break;
				case '-': value = stack[top-2] - stack[top-1];break;
				case '*': value = stack[top-2] * stack[top-1];break;
				case '/': value = stack[top-2] / stack[top-1];break;
				default: break;
			}
			top -= 2;
		}
	}

	return stack[0];
}

int main() {
	int n;
	char infix[1000], suffix[1000];//infix中缀表达式，suffix后缀表达式
	
	scanf("%d\n", &n);
	while(n--) {
		gets(infix);
		//printf("%s\n", infix);
		infix_to_suffix(infix, suffix);	
		printf("%d\n", suffix_value(suffix));
	}

	return 0;
}
