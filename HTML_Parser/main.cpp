#include <bits/stdc++.h>
using namespace std;


void parser(string s) {
    int n = s.size();
    int start = 0,  end = n - 1;
    int i, j;

    for (i = 0; i < n; i++) {
	if (s[i] == '>') {
	    start = i + 1;
	    break;
	}

    }

    while (s[start] == ' ') {
	start++;
    }


    for (i = start; i < n; i++) {
	if (s[i] == '<') {
	    end = i - 1;
	    break;
	}
    }

    for (int j = start; j <= end; j++) {
	cout << s[j];
    }
    cout << endl;
    

}

void charParser(char* S) {
    int n = strlen(S);
    int start = 0 , end = n - 1;
    int i, j;


    for (i = 0; i < n; i++) {
	if (S[i] == '>') {
	    start = i + 1;
	    break;
	}
    }

    while (S[start] == ' ') {
	start++;
    }

    for (i = start; i < n; i++) {
	if (S[i] == '<') {
	    end = i - 1;
	    break;
	}
    }

    for (j = start; j <= end; j++) {
	cout << S[j];
    }
    cout << endl;

}




int main()
{
    string s = "<h1>This is a statement</h1>";
    string s1 = "<h1>           This is a statement with some spaces</h1>";
    char s2[] = "<h1>           This is a statement with some @ #$., / special characters</h1>";
    parser(s);
    parser(s1);
    charParser(s2);
}
