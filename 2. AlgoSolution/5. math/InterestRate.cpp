#include<string>
#include<iostream>
using namespace std;

#define DIFF 1e-12

double calCumPrinciple(double interestRate)
{
	int week=46;//Number of week
	double weeklyPayment=25;//Weekly installment
	double cumPrinciple=1000;//Initial Loan
	
	interestRate/=100;//Yearly interest rate in fraction (Percentage)
	interestRate/=52;//Weekly interest rate

	while(week--)
	{
		cumPrinciple+=cumPrinciple*interestRate;//Cumulative priciple after weekly interest
		cumPrinciple-=weeklyPayment;//Cumulative priciple after weekly payment
	};

	return cumPrinciple;//Return cumulative principle after 46 weeks.
}

int main()
{
	//Use binary search to find out best yearly interest rate
	double high=100, mid=0, low=0;
	while((high-low)>DIFF) 
	{
		mid = (low+high)/2;
		if(calCumPrinciple(mid)>0) high=mid;
		else low = mid;
	}

	cout<<"Best Yearly Interest Rate: "<<mid<<"%"<<endl;//Best Yearly Interest Rate
	cout<<"Diff Amount: "<<calCumPrinciple(mid)<<endl;//Difference with expected value

	return 0;
}