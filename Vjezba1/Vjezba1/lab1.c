#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE (50)
#define MAX_LINE (1024)
#define FILE_ERROR_OPEN (-1)

typedef struct _student {
	char name[MAX_SIZE];
	char surname[MAX_SIZE];
	double points;
} student;

int readNoRows()
{
	int counter = 0;
	FILE* filepointer = NULL;
	char buffer[MAX_LINE] = { 0 };

	filepointer = fopen("studenti.txt", "r");
	if (!filepointer) {
		printf("file is not open");
		return FILE_ERROR_OPEN;
	}

	while (!feof(filepointer))
	{
		fgets(buffer, MAX_LINE, filepointer);
		counter++;
	}
	fclose(filepointer);
	return counter;
}

int main()
{

	int noRows = 0;

	noRows = (readNoRows);

	printf("%d", noRows);

	return 0;
}