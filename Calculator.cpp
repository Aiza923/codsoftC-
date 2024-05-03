#include <iostream>
using namespace std;

int main()
{
	double num1, num2;
	char op;
	cout<<"\n\n\t\t\t\t**CALCULATOR**\n"<<endl;
	cout<<"\tEnter the operation to be perform : ";
	cin>>op;
	cout<<"Enter the first number : ";
	cin>>num1;
	cout<<"Enter the second number : ";
	cin>>num2;
	
	switch (op)
	{
		case '+':
			cout<<num1 << op << num2 << " = " << num1+num2 <<endl;
			break;
			
		case '-':
			cout<<num1 << op << num2 << " = " << num1-num2 <<endl;
			break;
			
		case '*':
			cout<<num1 << op << num2 << " = " << num1*num2 <<endl;
			break;
			
		case '/':
			if (num2 == 0.0)
			{
				cout<<"Undefined"<<endl;
			}
			else
			{
			cout<<num1<< op <<num2 << " = " << num1/num2 <<endl;
		    }
			break;
			
		default:
			cout<<"Invalid operation!!"<<endl;
	}
}
