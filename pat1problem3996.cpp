#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
	int x;
	int sum = 0;
	int last = 0;
	cin >> x;
	while( x--){
		int n;
		cin >> n;
		if( n > last)
			sum += 6 *(n-last);
		else
			sum += 4 *(last-n);
		sum += 5;
		last = n;
	}
	cout << sum << endl;;
	return 0;
}
