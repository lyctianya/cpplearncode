//给定一个字符串，按单词将该字符串逆序，不包括标点  

#include<stdio.h>
#include <iostream>

//p和q之间的逆序  
void ReverseWord(char *p, char *q) {
	while (p < q) {
		*p = *p ^ *q;
		*q = *p ^ *q;
		*p = *p++ ^ *q--;
	}
}

char *ReverseSentence(char *s) {
	char *p = s;
	char *q = s;
	while (*q != '\0') {
		if (*q == ' ') {//查到一个单词  
			ReverseWord(p, q - 1);
			q++; //指向下一个单词道字符  
			p = q;
		}
		else
			q++;
	}
	ReverseWord(p, q - 1);//逆序最后一个单词  
	ReverseWord(s, q - 1);//整个句子逆序  

	return s;
}

int main() {

	char s[] = "I am glad to see you";

	printf("%s\n", s);
	ReverseSentence(s);
	printf("%s\n", s);
	system("pause");
	return 0;
}