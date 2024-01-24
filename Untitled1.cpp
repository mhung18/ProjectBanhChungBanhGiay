#include <iostream>
#include <math.h>
using namespace std;
int main (){
	int arr[10000];
	int A, B;
	int count = 0;
	for (int i = 0;i < 10000;i++){
		int a = 0;
		cin >> a;
		arr[i] = a;
		if (a % 2 == 0 && a % 3 == 0){
			count++;
			if(count == 2){
				break;
			}
		}
	}
	for (int i = 0;i < 10000;i++){
		if (arr[i] == 0){
			break;
		}
		cout << sqrt(arr[i]) << " ";
		
	}
}
