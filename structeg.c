#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct list { int hd; struct list *tl;} list_t;

void printlist(list_t *l) {
	while(l != NULL) {
		printf("%i\n", l->hd);
		l = l->tl;
	}
}

int main(int argc, char *argv[]){
	int c;
	list_t *cell = NULL;

	for(c=argc-1; c>0; c--){
		list_t *newcell = malloc(sizeof(list_t));
	(*newcell).hd = (int)(strlen(argv[c]));
	newcell->tl = cell;
	cell = newcell;
	}
	
	if (cell != NULL) printlist(cell);
}