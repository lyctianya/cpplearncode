//����һ���ַ����������ʽ����ַ������򣬲��������  

#include<stdio.h>
#include <iostream>

//p��q֮�������  
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
		if (*q == ' ') {//�鵽һ������  
			ReverseWord(p, q - 1);
			q++; //ָ����һ�����ʵ��ַ�  
			p = q;
		}
		else
			q++;
	}
	ReverseWord(p, q - 1);//�������һ������  
	ReverseWord(s, q - 1);//������������  

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