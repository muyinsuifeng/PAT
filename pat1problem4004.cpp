
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct student{
	string id;
	int group;
	int score;
	int rank = 0;
	int grouprank = 0;
};

int main(int argc, char const *argv[]){
	vector<student*> totalStudent;
	vector<student*> groupStudent;
	int groupNum;
	cin >> groupNum;
	for( int i = 1; i <= groupNum; ++i){
		int studentNum;
		cin >> studentNum;
		vector<student*>().swap( groupStudent);
		while( studentNum--){
			student* a = new student();
			cin >> a->id >> a->score;
			a->group = i;
			groupStudent.push_back(a);
			totalStudent.push_back(a);
		}
		sort( groupStudent.begin(), groupStudent.end(), [](student* x, student* y){return x->score >= y->score;});
		int lastscore = 301;
		int ranktmp = 1;
		for( int j = 0; j < groupStudent.size(); j++,ranktmp++){
			if( groupStudent[j]->score == lastscore) groupStudent[j]->grouprank = groupStudent[j-1]->grouprank;
			else {
				groupStudent[j]->grouprank = ranktmp;
				lastscore = groupStudent[j]->score;
			}
		}
	}
	sort( totalStudent.begin(), totalStudent.end(), [](student* x, student* y){
		if( x->score > y->score) return true;
		else if( x->score == y->score) 
			return x->group < y->group;
		else return false;
	});
	int lastscore = 301;
	int ranktmp = 1;
	for( int j = 0; j < totalStudent.size(); j++,ranktmp++){
			if( totalStudent[j]->score == lastscore) totalStudent[j]->rank = totalStudent[j-1]->rank;
			else {
				totalStudent[j]->rank = ranktmp;
				lastscore = totalStudent[j]->score;
			}
		}
	cout << totalStudent.size() << endl;
	for( auto i : totalStudent)
		cout << i->id  << " " << i->rank << " " << i->group << " " << i->grouprank << endl;
	return 0;
}