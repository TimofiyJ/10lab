#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct books {
	char author[50];
	char name[50];
	int year;
	int pages;
	double price;
	struct books* next;
};

void addNode(struct books** start, struct books* newBook);
void readFile(FILE* f1, struct books** start);
struct books* searchMin(struct books* start, int* min, int* max);
void deleteNode(struct books** start);
void printFile(FILE* f2, struct books* start);