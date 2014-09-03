/*
ID: faijur1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
	int monthDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int countDay[7]={0};
    int year;
	int day=2;//monday

    fin >> year;
	year += 1900-1;
	for(int i=1900; i<=year; i++)
	{
		for(int j=0; j<12; j++)
		{
			day = (day+13-1)%7;//13th day
			countDay[day]++;
			day++;

			if(j==1 && i%4==0)//February in leap year
			{
				if(i%100==0)
				{
					if(i%400==0) day = (day+29-13)%7;//Leap Year
					else day = (day+28-13)%7;//Normal Year
				}
				else
				{
					day = (day+29-13)%7;//Leap Year
				}
			}
			else
			{
				day = (day+monthDay[j]-13)%7;//Normal Year
			}
		}
	}

	for(int i=0; i<7; i++)
	{
		if(i == 6) fout << countDay[i]<<endl;
		else fout << countDay[i] << " ";
	}
   
    return 0;
}