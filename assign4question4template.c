
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100

// prints the content of 'text' -- a sequence of strings/words
// 'text' is the text to be printed
// 'n' is the number of words in the text
void print(char** text, int n) {
	for (int i = 0; i < n; i++)
		printf("%s ", *(text + i));
}

// returns the length of the given null-terminated string,
// that is, the number of characters in the string whose
// first element is pointed to by 's' up to and not including
// the first null character
int length(char* s) {
	int size = 0;
	for (int i = 0; *(s + i) != '\0'; i++) //count number of chars in the string
		size++;
	return size; //return the size of string 
}

// returns copy of the null-terminated string pointed to by 's',
// including the null terminator,
char* copy(char* s) { //s - is the tring that the user put
	int size = length(s); //size of string s 
	char* newS = malloc(sizeof(char) * (size+1));// define new array for the new string
	for (int i = 0; *(s + i) != '\0'; i++) //run on the old
		*(newS + i) = *(s + i);
	*(newS + size) = '\0';
	return newS;
}

// returns true if and only if the string 'a' and the string 'b'
// are the same, i.e., have the same characters in the same order
bool equals(char* a, char* b) {
	if (length(a) != length(b)) //case 1 
		return false;
	for (int i = 0; *(a + i) != '\0'; i++)
		if (*(a + i) != *(b + i))
			return false;
	return true;
}

// returns a copy of the text 'text'
// the returned copy is that same as 'text'
// with one exception -- all the words/strings
// that equal to 'old' are replaced with  the
// string 'new'
char** replace(char** text, int n, char* old, char* new) {
	char** newText = malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++)
		if (equals(*(text + i), old) == true) // call the function "equals"
			*(newText + i) = copy(new); //call the function "copy"
		else
			*(newText + i) = copy(*(text + i));
	return newText;
}

// reads a text from the user
// assumes the user types the text word by word,
// and after each word types ENTER
// assume that the string EOT marks the end of the text
// so, when the user type EOT the function stop reading words
// from the user
// the function return the text typed by the user
// the function put the number of words in the text
// in *numberOfWords
char** readText(int* numberOfWords) {
	char** text = NULL, * word = NULL; //define 2 pointers
	word = malloc(sizeof(char) * MAX_WORD_LENGTH); // define array with pointer
	int size = 0;
	printf("Please enter words:\n");
	while (true) {
		scanf("%s", word);
		if (equals(word, "EOT"))
			break;
		size++;

		text = (char**)realloc(text, sizeof(char*) * size);
		if (text == NULL)
		{
			printf("Error");
			exit(0);
		}
		*(text + size - 1) = copy(word);
	}
	*numberOfWords = size;
	return text;
}

// reads user text
// prints the user text
// reads a word to be replaced 'old', from the user
// reads a word to use instead of 'old', from the user
// creates a copy of the user text in which all the occurrences of 'old' are replaced by 'new'
// prints the updated text
// (do not forget to free all the dynamically allocated memory)

int main() {
	int num = 0;
	printf("Type a text, word by word, after each word type ENTER. To end the text type EOT(and press ENTER)\n");
	char** text = readText(&num);
	print(text, num);
	char new_word[MAX_WORD_LENGTH];
	char old_word[MAX_WORD_LENGTH];
	printf("Type the word you want to change (and press ENTER)\n");
	scanf("%s", &old_word);
	printf("Type the word you want to use instead (and press ENTER)\n");
	scanf("%s", &new_word);
	char** new_text = replace(text, num, old_word, new_word);
	print(new_text, num);

	for (int i = 0; i < num; i++)
	{
		free(*(text + i));
		free(*(new_text + i));
	}
	free(text);
	free(new_text);
	return 0;
}

