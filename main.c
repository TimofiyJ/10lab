#include "functions.h"






int main() {
	FILE* f1, *f2;
	f1= fopen("students.txt", "r");
	f2 = fopen("result.txt", "w");
	if (f1 == NULL)
	{
		printf("я балбес!!");
		return 0;
	}
	struct books* start = NULL;
	readFile(f1, &start);
	int min = start->pages;
	int max = 0;
	struct books* minBook1 = searchMin(start,min,max);
	max = minBook1->pages;
	struct books* minBook2 = searchMin(start, min, max);
	max = minBook2->pages;
	struct books* minBook3 = searchMin(start, min, max);
	fprintf(f2,"\n MINIMAL PAGES:");
	fprintf(f2,"name 1: %s, name2: %s, name 3: %s", minBook1->name, minBook2->name, minBook3->name);
	deleteNode(&start);
	printFile(f2, start);
	fclose(f2);
	fclose(f1);
}