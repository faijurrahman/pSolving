#include <iostream>
#include <conio.h>
#include <cstring>
#include <cmath>
using namespace std;

class baseConversion
{
	char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	baseConversion(int currentBase, int desireBase)
	{

	}

public:
	int toDecimal(char value[], int starting_base) 
	{

		long int return_value = 0;
		unsigned short int digit = 0;
		for (short int pos = strlen(value)-1; pos > -1; pos--) {
			for (int i=0; i<starting_base; i++) {
				if (hex[i] == value[pos]) {
					return_value+=i*pow((float)starting_base, digit++);
					break;
				}
			}
		}
		return return_value;
	}

	char* fromDecimal(int value, int ending_base) 
	{
		char *return_value = (char *)malloc(30);
		unsigned short int digit = (int)ceil(log10((double)(value+1))/log10((double)ending_base));
		return_value[digit] = 0;
		for (; value != 0; value/=ending_base) return_value[--digit] = hex[value%ending_base];
		return return_value;
	}
};

int main() 
{
	
	char value[30];
	int starting_base, ending_base;
	cout << "This program converts from one base to another, so long as the bases are" << endl
		<< "between 2 and 16." << endl
		<< endl;
input_numbers:
	cout << "Enter the number, then starting base, then ending base:" << endl;
	cin >> value >> starting_base >> ending_base;
	if (starting_base < 2 || starting_base > 16 || ending_base < 2 || ending_base > 16) {
		cout << "Invalid base(s). ";
		goto input_numbers;
	}

	for (int i=0; value[i]; i++) value[i] = toupper(value[i]);

	baseConversion base(starting_base, ending_base);
	cout << "Base " << ending_base << ": " << base.fromDecimal(base.toDecimal(value, starting_base), ending_base) << endl
		<< "Press any key to exit.";
	getch();
	return 0;
}