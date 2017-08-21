#include <iostream>
#include <string>
#include <vector>

using namespace std;
class team{
public:
	string teamname;
	string passwd;
	team(string teamname, string passwd): teamname(teamname), passwd(passwd){};
};
int main(int argc, char const *argv[]){
	int N;
	cin >> N;
	int count = 0;
	vector<team> v;
	for( int j = 0; j < N; ++j){
		string teamname, passwd;
		cin >> teamname >> passwd;
		bool flag = false;
		for( int i = 0; i < passwd.size(); ++i){
			if( passwd[i] == '1') {
				passwd[i] = '@';
				flag = true;
			}else if( passwd[i] == '0') {
				passwd[i] = '%';
				flag = true;
			}else if( passwd[i] == 'l') {
				passwd[i] = 'L';
				flag = true;
			}else if( passwd[i] == 'O') {
				passwd[i] = 'o';
				flag = true;
			}
		}
		if( flag){
			count++;
			team tmp( teamname, passwd);
			v.push_back(tmp);
		} 
	}
	if( !count) {
		if( N == 1)
			cout << "There is " << N << " account and no account is modified" << endl;
		else
			cout << "There are " << N << " accounts and no account is modified" << endl;
	}
	else{
		cout << count << endl;
		for( auto i : v)
			cout << i.teamname << " " << i.passwd << endl;
	}
	return 0;
}
