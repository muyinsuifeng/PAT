#include <iostream>
#include <math.h>
using namespace std;

bool isprime( int x){
	if( x <= 1) return false;
	for( int i = 2; i <= sqrt(x); i++)
		if( x%i == 0) return false;
	return true;
}

int main(int argc, char const *argv[]){
	int num;
	cin >> num;
	while( num > 0){
		int rex;
		cin >> rex;
		if( isprime( num)){
			int x = 0;
			for( ; num; num /= rex)
				x = x * rex + num % rex;
			// cout << x << endl;
			if( isprime(x)) cout << "Yes" << endl;
			else cout << "No" << endl;
		}else cout << "No" << endl;
		cin >> num;
	}
	return 0;
}

