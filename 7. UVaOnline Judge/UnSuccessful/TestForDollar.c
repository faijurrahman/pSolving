#include <stdio.h>

//#define NOTE_NORMAL_INT
//#define DOLLAR_PROB_UVa
#define NOTE_VARIABLE_LENGTH

#ifdef NOTE_NORMAL_INT
#define NOTE_TYPE 9
#define MAX_NOTE_VALUE 6000

unsigned long long int data[NOTE_TYPE+1][MAX_NOTE_VALUE+1];
unsigned int note[NOTE_TYPE+1] = {0,1,2,5,10,20,50,100,500,1000};//value=note_value*20 for P147
unsigned int LowestNoteIndx, HighestNoteIndx;
#endif // 1

#ifdef DOLLAR_PROB_UVa
#define NOTE_TYPE 11
#define MAX_NOTE_VALUE 6000

unsigned long long int data[NOTE_TYPE+1][MAX_NOTE_VALUE+1];
unsigned int note[NOTE_TYPE+1] = {0,1,2,4,10,20,40,100,200,400,1000,2000};//value=note_value*20 for P147
unsigned int LowestNoteIndx, HighestNoteIndx;
#endif // 1


#ifdef NOTE_VARIABLE_LENGTH
#define NOTE_TYPE 300
#define MAX_NOTE_VALUE 300

unsigned int note[NOTE_TYPE+1], LowestNoteIndx, HighestNoteIndx;
unsigned long long int data[NOTE_TYPE+1][MAX_NOTE_VALUE+1];  
#endif // 0

unsigned int findMaxUsableNoteFirstTime(unsigned int Amount)
{
    unsigned int indx;
	if(Amount < note[1])
		return 0;

    for(indx=1; indx<=NOTE_TYPE; indx++)
    {
        if(note[indx]<=Amount && Amount<note[indx+1])
            return indx;
    }
    
    return NOTE_TYPE;
}

unsigned int findMaxUsableNote(unsigned int Amount)
{
    unsigned int indx;
	if(Amount < note[LowestNoteIndx])
		return 0;

    for(indx=LowestNoteIndx; indx<=HighestNoteIndx; indx++)
    {
        if(note[indx]<=Amount && Amount<note[indx+1])
            return indx;
    }
    
    return HighestNoteIndx;
}


unsigned int TempAmount, TempNoteIndx;
unsigned long long int findSolution(unsigned int Amount, unsigned int NoteIndx)
{
    unsigned long long int numSolution=0;
    unsigned int loopNoteIndx;

	//This is the main use of DP in this function
	if(data[NoteIndx][Amount] != 0)
        return data[NoteIndx][Amount]; 


	//Two base condition for lowest two notes
	if(note[NoteIndx] == note[LowestNoteIndx])//if current note is equal to lowest note
	{
		if(Amount%note[LowestNoteIndx] == 0)  //and if the reminder is zero 
		{
			data[NoteIndx][Amount] = 1;
			return 1;						  //then return 1
		}
		else
			return 0;						  //otherwise return 0
	}    
    else if(note[NoteIndx] == note[LowestNoteIndx+1])//for second lowest note value
    {
        TempAmount = Amount%note[LowestNoteIndx+1];
        if(TempAmount%note[LowestNoteIndx] == 0)
		{
			data[NoteIndx][Amount] = 1 + (unsigned int) Amount/note[LowestNoteIndx+1];
            return data[NoteIndx][Amount];
		}
        else
            return 0;
    }    


	//Recursion logic is here. Do recurtion for usable all notes for given amount
	for(loopNoteIndx=LowestNoteIndx; loopNoteIndx <= NoteIndx; loopNoteIndx++)
	{
		TempAmount = Amount - note[loopNoteIndx];

		if(TempAmount >= note[loopNoteIndx])
		{
			TempNoteIndx = loopNoteIndx;
			numSolution+=findSolution(TempAmount, TempNoteIndx);
		}
		else if((note[loopNoteIndx] > TempAmount)  && (TempAmount >= note[LowestNoteIndx]))
		{
			TempNoteIndx = findMaxUsableNote(TempAmount);
			if(TempNoteIndx!=0)
				numSolution+=findSolution(TempAmount, TempNoteIndx);
		}
		else if(TempAmount == 0)
		{
			numSolution++;
		}
			
	}
 
	//Save and return
	data[NoteIndx][Amount] = numSolution;
    return data[NoteIndx][Amount]; 
}


int main(void)
{


    unsigned long long int NumofSolution;
    unsigned long long int table[MAX_NOTE_VALUE+1];

	char TempInputStr[50];
	unsigned int inNoteValue, inLimit1, inLimit2;

	unsigned int indx1, indx2, tempValue;	

	LowestNoteIndx  = 1;
	HighestNoteIndx = NOTE_TYPE;
    //Initialize
    for(indx1=LowestNoteIndx; indx1<=HighestNoteIndx; indx1++)
    {
        for(indx2=0;indx2<=MAX_NOTE_VALUE;indx2++)
        {
            data[indx1][indx2] = 0;
        }

	#ifdef NOTE_VARIABLE_LENGTH
		note[indx1] = indx1;//Initialize note value here
    #endif
    }

#ifdef NOTE_NORMAL_INT
	while(scanf("%u", &inNoteValue) == 1)
	{
		if(inNoteValue == 0)
			break;

		printf("%llu\n",findSolution(inNoteValue, findMaxUsableNote(inNoteValue)));
	}  
#endif // 0	

#ifdef DOLLAR_PROB_UVa
	float input;
	while(scanf("%f", &input) == 1)
	{
		inNoteValue = input * 20;
		if(inNoteValue == 0)
			break;

		printf("%llu\n",findSolution(inNoteValue, findMaxUsableNote(inNoteValue)));
	}  
#endif // 0


#ifdef NOTE_VARIABLE_LENGTH
	while(gets(TempInputStr) != NULL)
	{
		inNoteValue = 0;
		inLimit1 = 0;
		inLimit2 = 0;
		sscanf(TempInputStr, "%u %u %u", &inNoteValue, &inLimit1, &inLimit2);

		if(inNoteValue == 0)
			continue;

		if(inLimit1 == 0)
		{
			LowestNoteIndx  = 1;
			HighestNoteIndx = NOTE_TYPE;
		}
		else if(inLimit2 == 0)
		{
			LowestNoteIndx  = findMaxUsableNoteFirstTime(inLimit1);
			HighestNoteIndx = NOTE_TYPE;
		}
		else
		{
			LowestNoteIndx  = findMaxUsableNoteFirstTime(inLimit1);
			HighestNoteIndx = findMaxUsableNoteFirstTime(inLimit2);
		}

		
		//Clear all previous data
		for(indx1=1; indx1<=NOTE_TYPE; indx1++)
		{
			for(indx2=1;indx2<=MAX_NOTE_VALUE;indx2++)
			{
				data[indx1][indx2] = 0;
			}
		}

		tempValue     = findMaxUsableNoteFirstTime(inNoteValue);
		NumofSolution = findSolution(inNoteValue, tempValue);
		if(tempValue!=0)
			printf("%llu\n", NumofSolution);
		else
			printf("0\n");
	}  
#endif // 1

    return 0;
}