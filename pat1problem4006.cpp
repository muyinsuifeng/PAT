#include <iostream>
#include <unordered_map>
#include <string>
#include <iterator>
#include <sstream>

using namespace std;

bool double1(string &a) {
	bool flag = false;
	for( string::iterator it = a.end()-1; it >= a.begin(); --it){
		int tmp = (*it - '0');
		tmp *= 2;
		if( flag) tmp += 1;
		if( tmp > 9){
			flag = true;
			tmp %= 10;
		}else
			flag = false;
		*it = ('0' + tmp);
	}
	if( flag) return false;
	else return true;
}

int main(int argc, char const *argv[]){
	string a;
	cin >> a;
	string c = a;
	unordered_map<char, int> map;
	for( string::iterator it = a.begin(); it != a.end(); ++it)
		map[*it] ++;
	if( !double1( a)) {
		cout << "No" << endl;
		cout << ("1" + a) << endl;
	}
	else{
		for( string::iterator it = a.begin(); it != a.end(); ++it)
			map[*it] --;
		for( string::iterator it = c.begin(); it != c.end(); ++it){
			if( map[*it] != 0){
				cout << "No" << endl;
				cout << a << endl;
				return 0;
			} 
		}
		cout << "Yes" << endl;
		cout << a << endl;
	}
	return 0;
}
