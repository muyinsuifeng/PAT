#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <string.h>

using namespace std;

bool isPalindromicNumber( string x){
	string a = x;
	reverse( a.begin(), a.end());
	return a == x;
}

bool stringAdd( char*& x, char* y){
	int flag = 0;
	int q =  strlen(y) - 1;
	// cout << "q:" << q << endl;
	// cout << "xy :" << x << "        " << y << endl;
	for( int i = 0; i < strlen(x); i++){
		// cout << (x[i] - '0') << " " << (y[q - i ] - '0') << endl;
		int mid = (x[i] - '0') + (y[q - i] - '0') + flag;
		// cout << i << " " << mid << endl;
		if( mid > 9){
			flag = mid / 10;
			mid %= 10;
		}else
			flag = 0;
		x[i] = '0' + mid;
	}
	// cout << x << endl;
	// cout << flag << endl;
	return flag;
}

int main(int argc, char const *argv[]){
	string n;
	int times;
	cin >> n >> times;
	char* p = new char[n.size()];
	reverse( n.begin(), n.end());
	// memset(p, 0, n.size());
    strcpy(p, n.c_str());
    // cout << strlen(p) << endl;
    // cout << p << endl;
	for( int i = 0; i < times; i++){
		string qew = p;
		if( isPalindromicNumber( qew)) {
			cout << p << endl;
			cout << i << endl;
			return 0;
		}else{
			char* a = new char[strlen(p)];
			strcpy(a, p);
			char b[2] = "1";
			if( stringAdd( p, a)){
				char * t = new char[strlen(p)+1];
				strcpy( t, p);
				strcat( t, b);
				p = t;
			}
			// cout << p << endl;
		}
	}
	string res = p;
	reverse( res.begin(), res.end());
	cout << res << endl;
	cout << times << endl;
	return 0;
}
