#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Function to parse the HTML code
void parser(char* S)
{
    int n = strlen(S);
    int start = 0, end = n - 1;
    int i, j;

    for (int i = 0; i < n; i++) {

	if (S[i] == '>')  {
	    start = i + 1;
	    break;
	}
    }

    // remove the blank spaces
    while (S[start] == ' ') {
	start++;
    }

    for (i = start; i < n; i++) {
	if (S[i] == '<') {
	    end = i - 1;
	    break;
	}
    }


    for (j = start; j < end; j++) {
	printf("%c", S[j]);
    }
    printf("\n");
}


int main()
{
    char input1[] = "<h1>This is a statement!</h1>";
    char input2[] = "<h1>      This is a statement with some spaces</h1>";
    char input3[] = "<p>This is a statement with some @ #$., / special characters!</p>";

    printf("Parsed Statements:\n");

    // Function call
    parser(input1);
    parser(input2);
    parser(input3);
    
    return 0;


}
