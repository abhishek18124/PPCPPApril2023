#include<iostream>
#define PI 3.14
#define PRINT cout <<
#define SEMICOLON ;
#define NEWLINE endl
#define F for(int i=1; i<=5; i++) {cout << "*";}
#define FF(n) for(int i=1; i<=n; i++) {cout << "#";}

using namespace std;

int main() {
	
	PRINT PI << NEWLINE SEMICOLON
	PRINT 2*PI << endl SEMICOLON 

	F

	PRINT NEWLINE SEMICOLON

	F

	PRINT NEWLINE SEMICOLON

	FF(10)

	PRINT NEWLINE SEMICOLON


	return 0;
}