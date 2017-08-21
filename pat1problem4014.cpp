#include <iostream>
#include <string>

using namespace std;
string rgbtoMars( int rgb){
	string res;
	if( rgb / 13 == 0){
		res += "0";
		if( rgb <= 9)
			res += to_string(rgb);
		else
			res += ('A' + (rgb - 10));
	}else{
		int rgb1 = rgb/13;
		int rgb2 = rgb%13;
		if( rgb1 <= 9)
			res += to_string(rgb1);
		else
			res += ('A' + (rgb1 - 10));
		if( rgb2 <= 9)
			res += to_string(rgb2);
		else
			res += ('A' + (rgb2 - 10));
	}
	return res;
}

int main(int argc, char const *argv[]){
	int R, G, B;
	cin >> R >> G >> B;
	string res = "#" + rgbtoMars( R) +rgbtoMars( G)+ rgbtoMars( B);
	cout << res << endl;;
	return 0;
}
