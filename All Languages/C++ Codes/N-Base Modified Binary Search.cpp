
#include<bits/stdc++.h>
using namespace std;

#define N 3
#define PowerOf2 4

int NumericBaseSearch(int arr[], int M, int target){
	unsigned long long i, step1,step2 = PowerOf2, times;


	for (step1 = 1; step1 < M; step1 *= N);
	
	for (i = 0; step1; step1 /= N)

	
		if (i + step1 < M && arr[i + step1] <= target){
			for (times = 1; step2;step2 >>= 1)
				if (i +
					(step1 * (times + step2)) < M && arr[i + (step1 * (times + step2))] <= target)
					times += step2;

			step2 = PowerOf2;

			i += times * step1;
		}
	return arr[i] == target ? i : -1;
}


int main(){
	int arr[10] =
	{11, 25, 45, 48, 61, 77, 129, 243};
	int target = 61, M = 5;
	int answer = NumericBaseSearch(arr, M, target);
	cout<<answer;
	return 0;
}
