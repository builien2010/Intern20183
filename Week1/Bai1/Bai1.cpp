#include <bits/stdc++.h>

using namespace std;

// O(n)
int divide1( int a, int b){
	
	// dau cua phep chia
	int sign = ((a< 0) ^ (b < 0)) ? -1 : 1;
	
	a = abs(a);
	b = abs(b);
	
	

	if( b == 0){
		cout << "Ban nhap sai, b phai khac 0" << endl;
		return 0;
	}


	int quotient = 0;	// thuong
	
	while( a >= b){
		
		a -= b;
		quotient = quotient + 1;
	}
	
	cout << sign*quotient << endl;
}

// O(logn)
voiid divide2(int a, int b){

	// dau cua phep chia
	int sign = ((a< 0) ^ (b < 0)) ? -1 : 1;
	
	a = abs(a);
	b = abs(b);
	

	if( b == 0){
		cout << "Ban nhap sai, b phai khac 0" << endl;
		return 0;
	}

	int mask = 1, quotient = 0;

	while ( b <= a){
		b = b << 1;
		mask = mask << 1;
	}

	while ( mask > 1){
		b = b >> 1;
		mask = mask >> 1;

		if( a > b){
			a = a - b;
			quotient = quotient | mask;
		}
	}

	cout << quotient* sign << endl;
}


int main(){
	
	int a, b;
	//cin >> a >> b;
	
	//divide2(a, b)
	divide1(-10000000, 3) ;
	divide2(-10000000, 3);
	divide1(3, 5);
	divide2(3, 5);
	
	return 0;
	
}
