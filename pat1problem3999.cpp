#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <unordered_map>

using namespace std;
int main(int argc, char const *argv[]){
	string tmp;
	int sum = 0;
	unordered_map<char, string> v({{'0', "zero"}, {'1', "one"}, {'2', "two"}
				, {'3', "three"}, {'4', "four"}, {'5', "five"}, {'6', "six"}
				, {'7', "seven"}, {'8', "eight"}, {'9', "nine"}});
	cin >> tmp;
	for( string::iterator it = tmp.begin(); it != tmp.end(); ++it)
		sum += (*it - '0');
	string ssum;
	stringstream ss;
	ss << sum;
	ss >> ssum;
	for( string::iterator it = ssum.begin(); it != ssum.end(); ++it){
		if( (it+1) == ssum.end())
			cout << v[*it] << endl;
		else 
			cout << v[*it] << " ";
	}
	return 0;
}
