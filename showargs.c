#include <stdio.h>

void main(int argc, char *argv[]) {
	
	int c;
	
	printf("Number of arguments passed: %d\n", argc);
	
	for(c=0; c<argc; c++){
		printf("%dth argument is %s\n", c+1, argv[c]);
	}
}