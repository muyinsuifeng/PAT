#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]){
	int n, b;
	cin >> n >> b;
	vector<int> tmp;
	if( n == 0){
		cout << "Yes" << endl;
		cout << "0" << endl;
		return 0;
	}
	for( ; n; n /= b){
		int middle = n % b;
		tmp.push_back(middle);
	}
	bool flag = false;
	for( vector<int>::iterator bit = tmp.begin(), eit = tmp.end()-1; (bit != eit &&bit < eit); bit++, eit--){
		// cout << *bit << " " << *eit << endl;
		if( *bit != *eit) {
			cout << "No" << endl;
			flag = true;
			break;
		}
	}
	if( !flag) 
		cout << "Yes" << endl;
	for( vector<int>::iterator it = tmp.end()-1; it >= tmp.begin(); it--){
			if( it == tmp.begin()) cout << *it << endl;
			else cout << *it << " ";
		}
	return 0;
}
