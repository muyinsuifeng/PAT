#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]){
	int N;
	cin >> N;
	string mname = "Absent", mID, fname = "Absent", fID;
	int mscore = 101, fscore = -1;
	while( N--){
		string name, ID;
		char mf;
		int score;
		cin >> name >> mf >> ID >> score;
		if( mf == 'M'){
			if( score < mscore){
				mname = name;
				mID = ID;
				mscore = score;
			}
		}else{
			if( score > fscore){
				fname = name;
				fID = ID;
				fscore = score;
			}
		}
	}	
	if( fname == "Absent") cout << "Absent" << endl;
	else cout << fname << " " << fID << endl;
	if( mname == "Absent") cout << "Absent" << endl;
	else cout << mname << " " << mID << endl;
	if( mname == "Absent" ||fname == "Absent" ) cout << "NA" << endl;
	else cout << ( fscore - mscore) << endl;
	return 0;
}
