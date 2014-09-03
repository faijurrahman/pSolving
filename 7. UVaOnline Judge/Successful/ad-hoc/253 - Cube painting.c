#include <stdio.h>
#include <string.h>

int main(void)
{
	char String[20], Cube1Str[8], Cube2Str[8];
	char indx16, indx25, indx34, Flag, TempChar;

    while(scanf("%12s", &String) != EOF)
    {
		Flag = 0;
		strncpy(&Cube1Str[1],&String[0],6);
		strncpy(&Cube2Str[1],&String[6],6);        
		
		for(indx16=0; indx16<4; indx16++)
		{
			TempChar    = Cube1Str[2];
            Cube1Str[2] = Cube1Str[4];
			Cube1Str[4] = Cube1Str[5];
			Cube1Str[5] = Cube1Str[3];
            Cube1Str[3] = TempChar;

			for(indx25=0; indx25<4; indx25++)
			{
				TempChar    = Cube1Str[1];
				Cube1Str[1] = Cube1Str[4];
				Cube1Str[4] = Cube1Str[6];
				Cube1Str[6] = Cube1Str[3];
				Cube1Str[3] = TempChar;

				for(indx34=0; indx34<4; indx34++)
				{
					TempChar    = Cube1Str[1];
					Cube1Str[1] = Cube1Str[2];
					Cube1Str[2] = Cube1Str[6];
					Cube1Str[6] = Cube1Str[5];
					Cube1Str[5] = TempChar;

					if(!strncmp(&Cube1Str[1],&Cube2Str[1],6))
						Flag = 1;

				}//End for indx34
			}//End for indx25
		}//End for indx16

		if(Flag)
			printf("TRUE\n");
		else
			printf("FALSE\n");
        
    }

    return 0;
}
