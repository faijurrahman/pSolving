//http://www.geeksforgeeks.org/pattern-searching-set-5-efficient-constructtion-of-finite-automata/
#include<string>
#include<iostream>
using namespace std;

#define NO_OF_CHARS 256
int (*dfa)[NO_OF_CHARS];
void computedfa(string pattern) 
{
	int pSize = pattern.size();
	dfa = (int (*)[NO_OF_CHARS])malloc((pSize+1)*sizeof(*dfa));
    
 
    // Fill entries in first row
    for (int chars=0; chars<NO_OF_CHARS; chars++)
       dfa[0][chars] = 0;

	int lps = 0;
    dfa[0][pattern[0]] = 1;
    for (int state=1; state<= pSize; state++)
    {
        for (int chars=0; chars<NO_OF_CHARS; chars++)
           dfa[state][chars] = dfa[lps][chars];

        dfa[state][pattern[state]] = state + 1;
        if (state < pSize) lps = dfa[lps][pattern[state]];
    }
}
 
void search(string text, string pattern)
{
    int X = text.size();
	int Y = pattern.size();
    computedfa(pattern);

    int state = 0;
    for (int i = 0; i < X; i++)
    {
       state = dfa[state][text[i]];
	   if (state == Y) cout << "Pattern found at index " << i-Y+1 <<endl;   
    }

	free(dfa);
}
 
/* Driver program to test above function */
int main()
{
    string txt = "GEEKS FOR GEEKS";
    string pat = "GEEKS";
    search(txt, pat);
    return 0;
}