#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define EXIT 1
int* coprime(int* a, int n, int* b, int m) {
	int* c = (int*)calloc(m, sizeof(int));// define a destinition array.
	if (c == NULL) // check if memort location is found.
	{
		printf("no memory allocated");// if not show Error message to user.
		exit(EXIT);
	}
	for (int i = 0; i < m; i++) // run over array b
		for (int j = 0; j < n; j++) //run over array a
			if (*(a + j) != 1 && *(b + i) != 1 && (*(a + j) % *(b + i) == 0 || *(b + i) % *(a + j) == 0))// a[j]!1 and b[i]!=1 and one is divided by the second without remainder ;
				(*(c + i))++; 
	for (int i = 0; i < m; i++) //run over array c and abstract (n-*(c+i));
		*(c + i) = n - *(c + i); // that operation return the number of coprime numbers in each cell in array c.
	return c; //return the new array
}

int main()
{ 
	int n;
	printf("Please enter a size of array: ");
	scanf("%d", &n);
	printf("\nPlease enter %d numbers\n", n);
	int* a = (int*)malloc(n * sizeof(int));
	if (a == NULL)
	{
		printf("\nno memory allocated");
		exit(0);
	}
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);

	int sizeM;
	printf("\nPlease enter a size of array: ");
	scanf("%d", &sizeM);
	printf("\nPlease enter %d numbers\n", sizeM);
	int* m = (int*)malloc(sizeM * sizeof(int));
	if (m == NULL)
	{
		printf("\nno memory allocated");
		exit(0);
	}
	for (int i = 0; i < sizeM; i++)
		scanf("%d", m + i);
	
	int* c=coprime(a, n, m, sizeM);
	for (int i = 0; i < sizeM; i++)
		printf("%d ", c[i]);
	free(m);
	free(c);
	free(a);
	return 0;
}
