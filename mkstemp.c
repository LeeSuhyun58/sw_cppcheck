#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main() {
	char temp[1024];
	char *tmpfilwname;
	int fd;
	static char mesg[] = "I am looking into the 'mktemp' temporary file\n";

	strcpy(temp, "/tmp/tmpXXXXXX");
	fd = mkstemp(temp); //without open() function call

	if(fd < 0){
		perror("open");
		exit(1);
	}
	else{
		printf("Filename is %s\n", temp);
		write(fd, mesg, strlen(mesg));
	}
}