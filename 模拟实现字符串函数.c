#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* Strcat(char* dest, char* source) {
	int i , j;
	for (i = 0; dest[i] != '\0'; ++i);
	for (j = 0; source[j] != '\0'; ++i, ++j) {
		dest[i] = source[j];
	}
	dest[i] = '\0';
	return dest;
}

char* Strstr(char* source, char* to_find) {
	char* ptr = to_find;
	int sourecelen = strlen(source);
	int to_findlen = strlen(to_find);
	for (int i = 0; i < sourecelen; ++i) {
		if (source[i] == *ptr){
			char* ptrx;
			for (ptrx = ptr; *ptrx != '\0'; ++i, ++ptrx) {
				if (*ptrx != source[i]){
					break;
				}
			}
			if (*ptrx == '\0'){
				return &source[i-to_findlen];
			}
		}
	}
	return NULL;
}

char* Strcpy(char* dest, char* source) {
	int i;
	for (i = 0; source[i-1] != '\0'; ++i) {
		dest[i] = source[i];
	}
	return dest;
}
char* Strchr(char* source, int to_find) {
	int i;
	int len = strlen(source);
	for (i = 0; i < len; ++i) {
		if ((int)source[i] == to_find){
			return &source[i];
		}
	}
	return NULL;
}
int Strcmp(char* source1, char* source2) {
	char* ptr1 = source1;
	char* ptr2 = source2;
	if (*ptr1 =='\0' && *ptr2 == '\0'){
		return 0;
	}
	else {
		if (*ptr1 == *ptr2) {
			return Strcmp(ptr1 + 1 ,ptr2 + 1);
		}
		else {
			return *ptr1-*ptr2;
		}
	}
}
int main() {
	char str1[1024] = "kishere";
	char str2[1024] = " is god!";
	printf("%d\n", Strcmp(str1, "kisha"));
	Strcat(str1, str2);
	printf("%s\n", str1);
	printf("%s\n", Strstr(str1, str2));
	Strcpy(str2, str1);
	printf("%s\n", str2);
	printf("%s\n", Strchr(str1, 'e'));
	printf("%d\n", Strcmp(str1, str2));
	system("pause");
	return 0;
}