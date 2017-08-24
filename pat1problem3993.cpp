#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]){
	vector<double> match(3);
	vector<char> v;
	int n = 3;
	double sum = 1.000;
	while( n--){
		cin >> match[0] >> match[1] >> match[2];
		if( max_element( match.begin(), match.end()) - match.begin() == 0){
			v.push_back('W');
			sum *= match[0];
		}else if( max_element( match.begin(), match.end()) - match.begin() == 1){
			v.push_back('T');
			sum *= match[1];
		}else if( max_element( match.begin(), match.end()) - match.begin() == 2){
			v.push_back('L');
			sum *= match[2];
		}
		// cout << setiosflags(ios::fixed) << setprecision(2) << sum << endl;
	}
	for( auto i : v)
		cout << i << " ";
	// cout << setiosflags(ios::fixed) << setprecision(4) << (sum * 0.650) << endl;
	// cout << (sum * 0.650 - 1) << endl;
	double res = (sum * 0.650 - 1) * 2.000;
	// cout << setiosflags(ios::fixed) << setprecision(4) << res << endl;
	// int a = ( res + 0.005)*100;
	// cout << a << endl;
	// res = a / 100;
	double a = res + 0.005;
	int b = a * 100;
	// cout << b <<endl;
	res = (double)b / 100;
	cout << setiosflags(ios::fixed) << setprecision(2) << res << endl;
	return 0;
}
