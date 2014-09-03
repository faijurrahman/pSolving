//http://www.geeksforgeeks.org/searching-for-patterns-set-5-finite-automata/
#include<string>
#include<iostream>
using namespace std;

#define NO_OF_CHARS 256
int (*dfa)[NO_OF_CHARS];
void computedfa(string pattern)
{
	int pSize = pattern.size();
	dfa = (int (*)[NO_OF_CHARS])malloc((pSize+1)*sizeof(*dfa));

    for (int state = 0; state <= pSize; state++)
        for (int chars = 0; chars < NO_OF_CHARS; chars++)
		{
			int nextState = 0;
			if(string::npos != pattern.find(chars))
			{
				string newPattern = pattern.substr(0,state);
				newPattern.push_back(chars);
				for (int i = 0; i<=state; i++)
					if(0 == pattern.find(newPattern.substr(i)))
					{
						nextState = state-i+1;
						break;
					}

			}
			dfa[state][chars] = nextState;
		}
}
 
/* Prints all occurrences of pat in txt */
void search(string text, string pattern)
{
    int X = text.size();
	int Y = pattern.size();
    computedfa(pattern);

    // Process txt over dfa.
    int state = 0;
    for (int i = 0; i < X; i++)
    {
       state = dfa[state][text[i]];
	   if (state == Y)
			cout << "Pattern found at index " << i-Y+1 <<endl;   
    }

	free(dfa);
}
 
// Driver program to test above function
int main()
{
   string txt = "AABADCAADAABAAABAA";
   string pat = "AABA";
   search(txt, pat);
   return 0;
}