#include <iostream>
#include <string>
using namespace std;

void pai(int n1[],int m);
void pai(double n2[],int m);

int main() {

    int m;
    cin>>m;
	int n1[m];
	double n2[m];
	int i;                               
	for (i = 0; i < m; i++) 
		cin >> n1[i];
	for (i = 0; i < m; i++) 
		cin >> n2[i];

	pai(n1,m);
    //cout <<endl;
    pai(n2,m);
	return 0;
}

void pai(int n1[],int m){
	int i, j;
	int temp;
	for (i = 0; i < m-1;i++) {                  
		for (j = 0; j < m-1 - i;j++) {      
			if (n1[j] > n1[j + 1]) {
				temp = n1[j];
				n1[j] = n1[j + 1];
				n1[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < m; i++)
	{
	    cout << n1[i] << " ";
	}
}

void pai(double n2[],int m){
	int i, j;
	double temp;
    
	for (i = 0; i < m-1;i++) {                  
		for (j = 0; j < m-1 - i;j++) {      
			if (n2[j] > n2[j + 1]) {
				temp = n2[j];
				n2[j] = n2[j + 1];
				n2[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < m; i++)
	{
	    cout << n2[i] << " ";
	}
}