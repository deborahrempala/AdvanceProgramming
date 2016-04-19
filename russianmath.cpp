// Deborah Rempala
// csci 342
// Russian Peasent Math


#include <iostream>
#include <iomanip>
int math(int, int);
using namespace std;

int main()
{
	 int x =0;
	 int y =0;
	cout<<"Enter the First Number: ";
	cin>> x;
	cout <<"Enter the Second Number: ";
	cin>> y;
	cout<< math(x,y);
	return 0;
	
}


int math(int x, int y)
{
	
	int val =0;
	cout << left << setw(5) << x << left << setw(5) << y << left << setw(5) << val << endl;
	while( x > 0){
		 if(((x >> 1)+(x >>1)) != x) // checking to see if odd
		 {
			 val = val +y;
		 }
		 
		 y = y << 1;  // double
		x = x >> 1;  // half
		cout << left << setw(5) << x << left << setw(5) << y << left << setw(5) << val << endl; 
	
		
		
		
	}
	
	return val;
	
}
