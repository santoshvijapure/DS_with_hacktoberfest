#include <iostream>
using namespace std; 

int fac(int num){
	
	if(num == 0 || num == 1){ //Base case
		return 1;
	}

	return num * fac(num-1); //Returns X * X-1 * X-2 [...] until it's the base case. 	
}

int main(){

int x; 
cout << "Insert your number: "; 
cin >> x; 

cout << "The factorial of " << x << " is: " << fac(x) << endl; 


}