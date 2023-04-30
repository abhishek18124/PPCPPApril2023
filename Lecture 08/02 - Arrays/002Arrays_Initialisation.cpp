#include<iostream>

using namespace std;

int main() {

	int A[5] = {10, 20, 30, 40, 50};

	cout << "sizeof(A) = " << sizeof(A) << "B" << endl;
	cout << "A[0] = " << A[0] << endl;
	cout << "A[1] = " << A[1] << endl;
	cout << "A[2] = " << A[2] << endl;
	cout << "A[3] = " << A[3] << endl;
	cout << "A[4] = " << A[4] << endl;

	int B[] = {100, 200, 300};

	cout << "sizeof(B) = " << sizeof(B) << "B" << endl;
	cout << "B[0] = " << B[0] << endl;
	cout << "B[1] = " << B[1] << endl;
	cout << "B[2] = " << B[2] << endl;
	
	int C[5] = {1000, 2000, 3000};

	cout << "sizeof(C) = " << sizeof(C) << "B" << endl;
	cout << "C[0] = " << C[0] << endl;
	cout << "C[1] = " << C[1] << endl;
	cout << "C[2] = " << C[2] << endl;
	cout << "C[3] = " << C[3] << endl;
	cout << "C[4] = " << C[4] << endl;
		
	// int D[5] = {1, 2, 3, 4, 5, 6}; // error : size of the initialzer list cannot exceed the size of the array

	int E[5] = {0}; // zero init
	
	cout << "sizeof(E) = " << sizeof(E) << "B" << endl;
	cout << "E[0] = " << E[0] << endl;
	cout << "E[1] = " << E[1] << endl;
	cout << "E[2] = " << E[2] << endl;
	cout << "E[3] = " << E[3] << endl;
	cout << "E[4] = " << E[4] << endl;
	
	int F[10];

	memset(F, 0, sizeof(F)); // assigns the value 0 to all indices of F

	int n = sizeof(F) / sizeof(int);

	for(int i=0; i<n; i++) {
		cout << "F[" << i << "] = " << F[i] << endl;
	}

	return 0;
}