#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main() {
	char temp[1024];
	int fd;
	static char mesg[] = "I am looking into the 'mktemp' temporary file\n";

	strcpy(temp, "/tmp/tmpXXXXXX");
	mktemp(temp);

	fd=open(temp, O_CREAT | O_RDWR, 0700);
	if(fd < 0){
		perror("open");
		exit(1);
	}
	else{
		printf("Filename is %s\n", temp);
		write(fd, mesg, strlen(mesg));
	}
}
