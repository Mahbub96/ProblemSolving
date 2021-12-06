#include <stdio.h>

int main(){
	FILE *fp;
	fp = fopen("test.cpp","r");

	while(fp != '\0'){
		printf("%c",*fp);
	}
	return 0;
}
