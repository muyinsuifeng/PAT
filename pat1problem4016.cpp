#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char const *argv[]){
	int n,m;
	cin >> n;
	vector<long> v1(n);
	for( int i = 0; i < n; ++i)
		cin >> v1[i];
	cin >> m;
	vector<long> v2(m);
	for( int i = 0; i < m; ++i)
		cin >> v2[i];
	int middle = (n+m+1)/2;
	int i = 0, j = 0; 
	long res;
	while(middle--){
		if( v1[i] < v2[j]){
			if( i < n)
				res = v1[i];
			else{
				res = v2[j + middle];
				break;
			}
			i++;
		} 
		else {
			if( j < m)
				res = v2[j];
			else{
				res = v1[i + middle];
				break;
			}
			j++;
		}
	}
	cout << res << endl;
	return 0;
}
