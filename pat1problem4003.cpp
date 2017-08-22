#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[]){
	int a, b;
	cin >> a >> b;
	int res = a + b;
	bool flag = false;
	string output;
	if( res < 0) {
		flag = true;
		res *= -1;
	}
	int i = 0;
	while( res > 0){
		int d = res % 10;
		res /= 10;
		if( i == 3){
			output = "," + output;
			i = 0;
		}
		string tmp;
		stringstream ss;
		ss << d;
		tmp = ss.str();
		output = tmp + output;
		i++;
	}
	if( flag) 
		cout << "-" << output << endl;
	else 
		cout << output << endl;
	return 0;
}