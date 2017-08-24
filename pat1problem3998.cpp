#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int stringtoTime( string x){
	int flag = 0;
	int res = 0;
	int k = 5;
	for( int i = 0; i < x.size(); i++){
		if( flag != 2){
			res += (x[i] - '0') * ( pow( 10, k--));
			flag ++;
		}
		else flag = 0;
	}
	return res;
}

int main(int argc, char const *argv[]){
	int N;
	cin >> N;
	std::vector<string> name;
	std::vector<int> st;
	std::vector<int> en;
	while( N--){
		string a, b, c;
		cin >> a >> b >> c;
		name.push_back(a);
		st.push_back(stringtoTime( b));
		en.push_back(stringtoTime( c));
	}
	cout << name[ min_element( st.begin(), st.end()) - st.begin()] << " " << name[ max_element( en.begin(), en.end()) - en.begin()] << endl;
	return 0;
}

