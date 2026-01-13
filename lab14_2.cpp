#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

//Do not modify source code above this line

void showMatrix(const bool B[][N]){
	for( int i=0 ; i<N ; i++){
		for( int j=0 ; j<N ; j++){
			cout << B[i][j] << " ";
		}
		cout << endl;
	}
}

void inputMatrix(double A[][N]){
	for( int i=0 ; i<N ; i++){
		cout << "Row " << i+1 << ": ";
		for( int j=0 ; j<N ; j++){
			cin >> A[i][j];
		}
	}
}

void findLocalMax(const double Matrix[][N], bool LocalMax[][N]){
	for(int i = 0;i < N;i++){
		for(int j = 0;j < N;j++){
			LocalMax[i][j] = false;
		}
	}	

	for(int i = 1;i < N - 1;i++){
		for(int j = 1;j < N-1;j++){
			if(
			Matrix[i][j] >= Matrix[i][j+1] and 
			Matrix[i][j] >= Matrix[i][j-1] and
			Matrix[i][j] >= Matrix[i+1][j] and
			Matrix[i][j] >= Matrix[i-1][j]
			){
				LocalMax[i][j] = true;
			}
		}
	}
}