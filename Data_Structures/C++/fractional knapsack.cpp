// fractional knapsack
#include<iostream>
using namespace std;

void frac(float V[], float W[], float c, int n, float &value){
	float R[100], t;
	for(int i=0; i<n; i++)
		R[i] = V[i]/W[i];
		
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(R[j]<R[j+1]){
				t = R[j];
				R[j] = R[j+1];
				R[j+1] = t;
				
				t = V[j];
				V[j] = V[j+1];
				V[j+1] = t;
				
				t = W[j];
				W[j] = W[j+1];
				W[j+1] = t;
			}
		}
	}
	
	float wgt = 0, f = 0;
	value = 0;
	for(int i=0; i<n; i++){
		if(c!=0){
			f = c/W[i];
			if(f>=1)
				f=1;
			wgt+=f*W[i];
			value+=f*V[i];
			c-=f*W[i];
		}
	}
}

int main(){
	float V[100], W[100], value, c, n;
	cout<<"items ";
	cin>>n;
	cout<<"value and weight ";
	for(int i=0; i<n; i++){
		cin>>V[i]>>W[i];
	}
	
	cout<<"capacity ";
	cin>>c;
	frac(V, W, c, n, value);
	cout<<"value "<<value;
	return 0;
}
