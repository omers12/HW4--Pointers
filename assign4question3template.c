#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int** minor(int** a, int n, int i, int j) { // define new matrix
	int** minorMat = (int**)malloc((n - 1) * sizeof(int*));
	if (minorMat == NULL) // check if memory allocation succees.
	{
		printf("\nno memory allocated");
		exit(0);
	}

	for (int i = 0; i < n - 1; i++) //for n elements there is a n-1 places in array.
	{
		*(minorMat + i) = (int*)malloc(sizeof(int) * (n - 1));
		if (minorMat + i == NULL)
		{
			printf("\no memory allocated");
			exit(0);
		}
	}

	for (int k = 0, r = 0, p = 0; k < n; k++)
		for (int t = 0; t < n; t++)
			if (k != i && t != j)
			{
				*(*(minorMat + r) + p) = *(*(a + k) + t);
				p++;
				if (p == n - 1)
				{
					p = 0;
					r++;
				}
			}
	return minorMat;
}


int main()
{
	int n;
	printf("Please enter a size of array: ");
	scanf("%d", &n);
	printf("\nPlease enter %d numbers\n", n * n);

	int** mat = (int**)malloc(n * sizeof(int*));
	if (mat == NULL)
	{
		printf("\nno memory allocated");
		exit(0);
	}

	for (int i = 0; i < n; i++)
	{
		*(mat + i) = (int*)malloc(sizeof(int) * n);
		if (mat + i == NULL)
		{
			printf("\nno memory allocated");
			exit(0);
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", *(mat + i) + j);

	printf("Please enter i and j: ");
	int i, j;
	scanf("%d %d", &i, &j);
	int** c = minor(mat, n, i, j); //define pointer c 
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
			printf("%d ", *(*(c + i) + j));
		printf("\n");
	}
	for (int i = 0; i < n; i++)
		free(*(mat + i));
	free(mat);

	for (int i = 0; i < n-1; i++)
		free(*(c + i));
	free(c);
	return 0;
}