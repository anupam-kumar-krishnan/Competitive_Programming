#include<iostream>

using namespace std;

int main()
{
	int number, i, sum = 0;
	
	cout << "Please Enter the Number to check for Perfect  =  ";
	cin >> number;
	
	for(i = 1 ; i < number ; i++)
	{
		if(number % i == 0)
		{
			sum = sum + i;
		}
	}
			
	if(number == sum)
	{
		cout << number << " is a Perfect Number";
	}
	else
	{
		cout << number << " is Not a Perfect Number";
	}
 	return 0;
}
