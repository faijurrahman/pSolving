#include <stdio.h>

#define NOTE_TYPE 21
#define MAX_NOTE_VALUE 10000

unsigned long long int data[NOTE_TYPE][MAX_NOTE_VALUE+1];
unsigned int note[NOTE_TYPE];   

unsigned int findMaxUsableNote(unsigned int Amount)
{
    unsigned int indx;
    for(indx=0;indx<NOTE_TYPE;indx++)
    {
        if(note[indx]<=Amount && Amount<note[indx+1])
            return indx;
    }
    
    return (NOTE_TYPE-1);
}


unsigned int TempAmount, TempNoteIndx;
unsigned long long int findSolution(unsigned int Amount, unsigned int NoteIndx)
{
    unsigned long long int numSolution=0;
    unsigned int loopNoteIndx;

    if(Amount == 0)
    	return 1;

    if(note[NoteIndx] == note[0])//Note value is 1
    {
        if(Amount%note[0] == 0)
            return 1;
        else
            return 0;
    }       
    else if(note[NoteIndx] == note[1])//Note value is 2
    {
        TempAmount = Amount%note[1];
        if(TempAmount%note[0] == 0)
            return (1 + (unsigned int) Amount/note[1]);
        else
            return 0;
    }

       
    if(data[NoteIndx][Amount] != 0)
        return data[NoteIndx][Amount]; 


	for(loopNoteIndx=0; loopNoteIndx <= NoteIndx; loopNoteIndx++)
	{
		TempAmount = Amount - note[loopNoteIndx];
		if(TempAmount>=note[loopNoteIndx])
		{
			TempNoteIndx = loopNoteIndx;
		}
		else
		{
			TempNoteIndx = findMaxUsableNote(TempAmount);
		}
		numSolution+=findSolution( TempAmount, TempNoteIndx);
	}

		 
	data[NoteIndx][Amount] = numSolution;
    return data[NoteIndx][Amount]; 
}


int main(void)
{
    //unsigned int input;
    unsigned long long int NumofSolution;

    unsigned int indx1, indx2;

    //Initialize
    for(indx1=0;indx1<NOTE_TYPE;indx1++)
    {
        for(indx2=0;indx2<=MAX_NOTE_VALUE;indx2++)
        {
            data[indx1][indx2] = 0;
        }
        
        note[indx1] = (indx1+1) * (indx1+1) * (indx1+1);
    }

	unsigned int input;
	while(scanf("%u", &input) != EOF)
	{
		if(input == 0)
			break;

		NumofSolution = findSolution(input, findMaxUsableNote(input));
		printf("%lld\n",NumofSolution);
	}  

	return 0;  
}
