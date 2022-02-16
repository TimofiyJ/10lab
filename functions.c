#include "functions.h"


void addNode(struct books** start, struct books* newBook) {
	if ((*start) == NULL) {
		(*start) = newBook;
		(*start)->next = NULL;
	}
	else {
		if ((*start)->year > newBook->year) {
			newBook->next = (*start);
			(*start) = newBook;
			return;
		}
		struct books* tester = *start;
		while (tester->next != NULL) {
			if (newBook->year > tester->year && newBook->year < tester->next->year) {
				newBook->next = tester->next;
				tester->next = newBook;
				return;
			}
			tester = tester->next;
		}
	}
}

void readFile(FILE* f1, struct books** start) {
	int symb;
	int i = 0;
	while ((symb = getc(f1)) != EOF) {
		struct books* newBook = (struct books*)malloc(sizeof(newBook));
		fscanf_s(f1, "%s", newBook->author);
		fscanf_s(f1, "%s", newBook->name);
		fscanf_s(f1, "%d", &newBook->year);
		fscanf_s(f1, "%d", &newBook->pages);
		fscanf_s(f1, "%lf", &newBook->price);
		i++;
		newBook->next = NULL;
		addNode(start, newBook);
	}
}
struct books* searchMin(struct books* start, int* min, int* max) {
	struct books* tester = start;
	struct books* minBook =start;
	while (tester->next != NULL) {
		if (tester->pages < *min && tester->pages > *max) {
			*min = tester->pages;
			minBook = tester;
		}
		tester = tester->next;
	}
	if (tester->pages < *min) {
		*min = tester->pages;
		minBook = tester;
	}
	return minBook;
}

void deleteNode(struct books** start) {
	for (struct books* prev = NULL, *cur = *start; cur; ) {
		if (cur->author[0] == 'Y') {
			if (prev) {
				prev->next = cur->next;
				free(cur);
				cur = prev->next;
			}
			else {
				cur = (*start)->next;
				free((*start));
				(*start) = cur;
			}
			continue;
		}
		prev = cur;
		cur = cur->next;
	}

}
void printFile(FILE* f2, struct books* start) {
	while (start->next != NULL) {
		fprintf(f2, "Author: %s Book called: %s Year: %d Pages: %d Price: %lf\n ",
			start->author, start->name, start->year, start->pages, start->price);
		start = start->next;
	}
}