#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, char const *argv[]){
	int N;
	cin >> N;
	vector<long long> nc;
	while( N--){
		long long tmp;
		cin >> tmp;
		nc.push_back(tmp);
	}
	cin >> N;
	vector<long long> np;
	while( N--){
		long long tmp;
		cin >> tmp;
		np.push_back(tmp);
	}
	sort( nc.begin(), nc.end());
	sort( np.begin(), np.end());
	int i = 0;
	long long sum = 0;
	while( nc[i] < 0 && np[i] < 0) {
		sum += (nc[i] *np[i]);
		i++;
	}
	int n = nc.size()-1;
	int m = np.size()-1;
	while( n >=0 && nc[n] > 0 && m >= 0&& np[m] > 0){
		sum += (nc[n] *np[m]);
		n--;
		m--;
	}
	cout << sum << endl;

	return 0;
}
