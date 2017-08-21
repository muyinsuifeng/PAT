#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class student{
public:
	string ID;
	string name;
	int score;
	student(){};
};

bool sortComp1( student x, student y){
	return x.ID < y.ID;
}

bool sortComp2( student x, student y){
	return (x.name <  y.name) || ((x.name == y.name) && sortComp1(x, y));
}

int main(int argc, char const *argv[]){
	int N, C;
	cin >> N >> C;
	vector<student> v;
	for( int i = 0; i < N; i++){
		student tmp;
		cin >> tmp.ID >> tmp.name >> tmp.score;
		v.push_back(tmp);
	}
	if( C == 1){
		sort( v.begin(), v.end(), sortComp1);
	}else if( C == 2){
		sort( v.begin(), v.end(), sortComp2);
	}else{
		sort( v.begin(), v.end(), [](student x, student y){return (x.score < y.score) || ((x.score == y.score)&&(sortComp1(x, y)));});
	}

	for( auto i : v)
		cout << i.ID << " " << i.name << " " << i.score << endl;
	return 0;
}