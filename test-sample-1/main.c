#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include "fun.h"

void sf_a(char* buf){
	int flag[5];
	memset(flag, 0, sizeof(flag));
	for (int i = 0; i < strlen(buf); i++){
		switch(buf[i]){
			case 'c':
				flag[0]++;
				break;
			case 'r':
				flag[1]++;
				break;
			case 'a':
				flag[2]++;
				break;
			case 's':
				flag[3]++;
				break;
			case 'h':
				flag[4]++;
				break;
			default:
				break;
		}
	}
	if(flag[0] > 1 && flag[1] > 1 && flag[2] > 1 && flag[3] > 1 && flag[4] > 1)
		raise(SIGSEGV);
}

void sf_b(char* buf){
	if(!strcmp(buf, "crash"))
		raise(SIGSEGV);
}

void sf_c(char* buf){
	int len = strlen(buf);
	if(len == strlen("crash"))
		if(buf[0] == 'c')
			if(buf[1] == 'r')
				if(buf[2] == 'a')
					if(buf[3] == 's')
						if(buf[4] == 'h')
							raise(SIGSEGV);
}

void sf_d(char* buf){
	int cnt = 0;
	for (int i = 0; i < strlen(buf); i++){
		if(buf[i] == 'c')
			cnt++;
		if(cnt == 5){
			raise(SIGSEGV);
		}
	}
}

int main(int argc, char* argv[]){
	char buf[500];
	FILE* input = NULL;
	input = fopen(argv[1], "r");
	if(input != 0){
		int tmp = fread(buf, 8, 8, input);
		sf_a(buf);
		sf_b(buf);
		sf_c(buf);
		sf_d(buf);
		fclose(input);
	}
	return 0;
}
