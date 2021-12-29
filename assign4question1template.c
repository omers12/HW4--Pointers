#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#define EXIT 1
// Returns true if the sequence of integers a is a derangement. Otherwise, returns false;
// Assumes the length of the sequence a is n > 0.
bool isDerangement(int* a, int n) {
    int* b = (int*)calloc(n, sizeof(int)); // define new array 
    if (b == NULL) {
        printf("Error! memory not allocated.");
        exit(EXIT);
    }
    for (int i = 0; i < n; i++) {
        if (*(a + i) >= 0 && *(a + i) < n) {
            *(b + *(a + i))+= 1; // change the value to 1 
        }
        else {
            return false;
        }
    }
    for (int i = 0; i < n; i++) { //check if the value of number is not 1 
        if (*(b + i) != 1)
            return false;
    }
    free(b);
    for (int i = 0; i < n; i++)
        if (*(a + i) == i) //run over the array and check if the value is equal to its index.
            return false;
    return true; 
}


void test1_IsDerangement() {
    printf("\n* test1_IsDerangement()\n");

    bool result;

    int* a = (int *) calloc(4,sizeof(int)); // define new array 
    if(a == NULL) {
        printf("Error! memory not allocated."); // print Error
        exit(EXIT_FAILURE);
    }
    *(a+0) = 3;
    *(a+1) = 2;
    *(a+2) = 0;
    *(a+3) = 1;

    result = isDerangement(a, 4);
    free(a);

    assert(result == true);
}


void test2_IsDerangement() {
    printf("\n* test2_IsDerangement()\n");

    bool result;

    int* a = (int *) calloc(4,sizeof(int));
    if(a == NULL) {
        printf("Error! memory not allocated.");
        exit(EXIT_FAILURE);
    }
    *(a+0) = 3;
    *(a+1) = 1;
    *(a+2) = 1;
    *(a+3) = 2;

    result = isDerangement(a, 4);
    free(a);

    assert(result == false);
}


void test3_IsDerangement() {
    printf("\n* test3_IsDerangement()\n");

    bool result;

    int* a = (int*)calloc(5, sizeof(int));
    if (a == NULL) {
        printf("Error! memory not allocated.");
        exit(EXIT_FAILURE);
    }
    *(a + 0) = 0;
    *(a + 1) = 3;
    *(a + 2) = 1;
    *(a + 3) = 2;
    *(a + 4) = 4;

    result = isDerangement(a, 5);
    free(a);

    assert(result==false); 
}


void test4_IsDerangement() {
    printf("\n* test4_IsDerangement()\n");

    bool result;

    int* a = (int*)calloc(4, sizeof(int));
    if (a == NULL) {
        printf("Error! memory not allocated.");
        exit(EXIT_FAILURE);
    }
    *(a + 0) = 3;
    *(a + 1) = 0;
    *(a + 2) = 2;
    *(a + 3) = 1;

    result = isDerangement(a, 4);
    free(a);

    assert(result == false);
}


void test5_IsDerangement() {
    printf("\n* test5_IsDerangement()\n");

    bool result;

    int* a = (int*)calloc(4, sizeof(int));
    if (a == NULL) {
        printf("Error! memory not allocated.");
        exit(EXIT_FAILURE);
    }
    *(a + 0) = 3;
    *(a + 1) = 2;
    *(a + 2) = 0;
    *(a + 3) = 1;

    result = isDerangement(a, 4);
    free(a);

    assert(result == true);
}


void test6_IsDerangement() {
    printf("\n* test6_IsDerangement()\n");
    bool result;
    int* a = (int*)calloc(4, sizeof(int));
    if (a == NULL) {
        printf("Error! memory not allocated.");
        exit(EXIT_FAILURE);
    }
    *(a + 0) = 3;
    *(a + 1) = 0;
    *(a + 2) = 1;
    *(a + 3) = 2;

    result = isDerangement(a, 4);
    free(a);

    assert(result == true);
}


void test7_IsDerangement() {
    printf("\n* test7_IsDerangement()\n");

    bool result;

    int* a = (int*)calloc(4, sizeof(int));
    if (a == NULL) {
        printf("Error! memory not allocated.");
        exit(EXIT_FAILURE);
    }
    *(a + 0) = 6;
    *(a + 1) = 8;
    *(a + 2) = 1;
    *(a + 3) = 2;

    result = isDerangement(a, 4);
    free(a);

    assert(result == false);
}


void test8_IsDerangement() {
    printf("\n* test8_IsDerangement()\n");

    bool result;

    int* a = (int*)calloc(4, sizeof(int));
    if (a == NULL) {
        printf("Error! memory not allocated.");
        exit(EXIT_FAILURE);
    }
    *(a + 0) = 0;
    *(a + 1) = 1;
    *(a + 2) = 2;
    *(a + 3) = 3;
    result = isDerangement(a, 4);
    free(a);
    assert(result == false);
}


void test9_IsDerangement() {
    printf("\n* test9_IsDerangement()\n");

    bool result;

    int* a = (int*)calloc(4, sizeof(int));
    if (a == NULL) {
        printf("Error! memory not allocated.");
        exit(EXIT_FAILURE);
    }
    *(a + 0) = 1;
    *(a + 1) = 0;
    *(a + 2) = 3;
    *(a + 3) = 2;

    result = isDerangement(a, 4);
    free(a);

    assert(result == true);
}


int main()
{
    printf("\nMain started...\n");

    test1_IsDerangement();
    test2_IsDerangement();
    test3_IsDerangement();
    test4_IsDerangement();
    test5_IsDerangement();
    test6_IsDerangement();
    test7_IsDerangement();
    test8_IsDerangement();
    test9_IsDerangement();

    printf("\nMain ended...\n");
    return 0;
}
