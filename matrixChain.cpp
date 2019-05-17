#include <bits/stdc++.h>
using namespace std;

int MatrixChainOrder(int p[], int n){
	int m[n][n];
	int i, j, k, L, q;
	memset(m, 0, sizeof(m));
	for (L=2; L<n; L++)
		for (i=1; i<n-L+1; i++){
			cout << "i: " << i << " | upto: " << n-L+1 << endl;
			j = i+L-1;
			cout << "j: " << j << " | upto: " << j+L-1 << endl;
			m[i][j] = INT_MAX;
			for (k=i; k<=j-1; k++){
				q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if (q < m[i][j])
					m[i][j] = q;
				cout << q << endl;
			}
		}
	return m[1][n-1];
}

int main(){
	int arr[] = {1, 2, 3, 4};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout << "Minimum number of multiplications is " << MatrixChainOrder(arr, size) << endl;
	return 0;
}
