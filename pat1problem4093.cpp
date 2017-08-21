#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char const *argv[]){
	int M, N;
	cin >> M >> N;
	int color = -1, count = 0;
	for( int i = 0; i < N; i++)
		for( int j = 0; j < M; j++){
			int readColor;
			cin >> readColor;
			if( readColor == color)
				count ++;
			else{
				if( count == 0){
					color = readColor;
				}else{
					count --;
				}
			}
		}

	cout << color << endl;
	return 0;
}
