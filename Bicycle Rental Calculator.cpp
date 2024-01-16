//Group members:
// 222008524 TUYISHIME David
// 222006273 BYUKUSENGE Immaculee
// 222010802 NYODUSENGA Florence


#include<iostream>
using namespace std;
int calculateRental(int, int, int);
int main()
{
	int startTime, endTime;
	cout<<"Enter the starting time: ";
	cin>>startTime;
	cout<<"Enter the ending time: ";
	cin>>endTime;
	if(startTime >= 0 && startTime <= 23 && endTime >= 1 && endTime <= 24 && endTime > startTime)
	{
		cout<<"The Total Rental fees = "<<calculateRental(startTime, endTime, 0)<<endl;
	}
	else
	{
		cout<<"\n\nFollow all conditions.\n\n1. Start Time must be between 0-23\n2. End Time must be between 1-24\n3. End Time must be greater than Start Time.\n\n";
	}
	return 0;
}

int calculateRental(int startTime, int endTime, int currentCost)
{
	
	if(startTime < 7)
	{
		if(endTime <= 7)
		{
			currentCost += (endTime - startTime) * 500;
			return currentCost;
		}
		currentCost += (7 - startTime) * 500;
		startTime = 7;
		return calculateRental(startTime, endTime, currentCost);
	}
	
	else if(startTime < 14)
	{
		if(endTime <= 14)
		{
			currentCost += (endTime - startTime) * 1000;
			return currentCost;
		}
		currentCost += (14 - startTime) * 1000;
		startTime = 14;
		return calculateRental(startTime, endTime, currentCost);
	}
	
	else if(startTime < 19)
	{
		if(endTime <= 19)
		{
			currentCost += (endTime - startTime) * 1500;
			return currentCost;
		}
		currentCost += (19 - startTime) * 1500;
		startTime = 19;
		return calculateRental(startTime, endTime, currentCost);
	}
	
	else if(startTime < 21)
	{
		if(endTime <= 21)
		{
			currentCost += (endTime - startTime) * 1000;
			return currentCost;
		}
		currentCost += (21 - startTime) * 1000;
		startTime = 21;
		return calculateRental(startTime, endTime, currentCost);
	}
	
	else if(startTime < 24)
	{
		currentCost += (endTime - startTime) * 500;
		return currentCost;
	}
	
	else
	{
		return 0;
	}
}
