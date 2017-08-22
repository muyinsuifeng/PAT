#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main(int argc, char const *argv[]){	
	vector<double> array(1001, 0);
	int N;
	int count = 0;
	cin >> N;
	while( N--){
		int i;
		double j;
		cin >> i >> j;
		array[i] = j;
		count ++;
	}
	cin >> N;
	while( N--){
		int i;
		double j;
		cin >> i >> j;
		if( array[i] != 0){
			array[i] += j;
			if( array[i] == 0)
				count --;
		}
		else {
			array[i] = j;
			count ++;
		}
	}
	cout << count << " ";
	for( int i = 1000; i >= 0; --i)
		if( array[i] != 0){
			if( --count)
				cout << setiosflags(ios::fixed) << setprecision(1) << i << " " << array[i] << " ";
			else 
				cout << setiosflags(ios::fixed) << setprecision(1) << i << " " << array[i] << endl;;
		}
	return 0;
}
