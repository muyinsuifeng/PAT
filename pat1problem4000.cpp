// 		   01
// 	02     03     04
//   05  06        07
//  08             09
//                10 11
// 01|02|03|04|05|06|07|08|09|10|11|
// 01|01|01|01|02|02|04|05|07|09|09|
// 1 | 2| 2| 2| 3| 3| 3| 4| 4| 5| 5|
// 11 6
// 01 3 02 03 04
// 02 2 05 06
// 04 1 07
// 05 1 08
// 07 1 09
// 09 2 10 11
// 0 1 1 1 2

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]){
	int n, m;
	cin >> n >> m;
	vector<int> node(n);
	vector<int> leaf(n - m);
	vector<int> rank(n, 1);
	unordered_set<int> noleaf;
	for( int i = 0; i < m; ++i){
		int father, k;
		cin >> father >> k;
		noleaf.insert(father-1);
		while( k--){
			int child;
			cin >> child;
			node[child - 1] = father - 1;
			rank[child-1] += rank[father-1];
		}
	}

	

	int maxrank = *max_element( rank.begin(), rank.end());
	// for( auto i: noleaf)
	// 	cout << i << " ";
	// cout << endl;
	// cout << maxrank << endl;
	vector<int> res( maxrank, 0);
	for( int i = 0; i < n; i++){
		if( noleaf.find(i) == noleaf.end()){
			// cout << i << endl;
			res[rank[i]-1] ++;
		}
	}
	for( int i = 0; i < res.size()-1; i++)
		cout << res[i] << " ";
	cout << res[res.size()-1] << endl;
	// for( auto i : rank)
	// 	cout << i << endl;
	return 0;
}
