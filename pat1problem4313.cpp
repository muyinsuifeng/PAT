// #include <iostream>
// #include <string>
// #include <vector>
// #include <istream>
// using namespace std;

// class student{
// 	friend istream& operator>>(istream& in, student& x){
// 		in >> x._name >> x._ID >> x._score;
// 	}
// 	friend bool operator > (student& x, student& y){
// 		if(x._score > y._score) return true;
// 		else return false;
// 	}
// 	public:
// 		string _name;
// 		string _ID;
// 		int _score;
// 		student() = default;
// 		student(const student& x){
// 			this->_name = x._name;
// 			this->_ID = x._ID;
// 			this->_score = x._score;
// 		}
// };
// int partition(vector<student>& array, int start, int end){
// 	student standard(array[end]);
// 	int j = start - 1;
// 	for (int i = start; i < end; ++i){
// 		if(array[i] > standard){
// 			++j;
// 			swap(array[i], array[j]);
// 		}
// 	}
// 	swap(array[j + 1], array[end]);
// 	return j + 1;
// }
// void student_sort(vector<student>& array, int start, int end){
// 	if(start < end){
// 		student_sort(array, partition(array, start, end) + 1, end);
// 		student_sort(array, start, partition(array, start, end) - 1);
// 	}
// }
// int main(int argc, char const *argv[]){
// 	std::vector<student> v;
// 	int T;
// 	while(cin >> T){
// 		v.clear();
// 		while(T --) {
// 		    student x;
// 		    cin >> x;
// 		    v.push_back(x);
// 		}
// 		int up,low;
// 		student_sort(v, 0, v.size()-1);
// 		for (std::vector<student>::iterator i = v.begin(); i != v.end(); ++i){
// 			if( i->_score >= low && i->_score <= up) cout << i->_name << " " << i->_ID << endl;
// 			else if(i->_score < low) break;	
// 		}
// 	}
// 	return 0;
// }



// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <istream>
// #include <vector>

// using namespace std;
// class student{
// 	// friend istream& operator>>(istream& in, student& x){
// 	// 	in >> x._name >> x._ID >> x._score;
// 	// }
	
// 	public:
// 		string _name;
// 		string _ID;
// 		int _score;
// 		student() = default;
// 		student(const student& x){
// 			this->_name = x._name;
// 			this->_ID = x._ID;
// 			this->_score = x._score;
// 		}
// };
// bool cmp(student& x, student& y){
// 	if(x._score > y._score) return true;
// 	else return false;
// }
// int main(int argc, char const *argv[]){
// 	int T;
// 	std::vector<student> v;
// 	while(cin >> T){
// 		v.clear();
// 		for (int i = 0; i < T; ++i){
// 			student x;
// 			// cin >> x;
// 			cin >> x._name >> x._ID >> x._score;
// 			v.push_back(x);
// 			/* code */
// 		}
// 		int low,up;
// 		cin >> low >> up;
// 		sort(v.begin(), v.end(), cmp);
// 		for (std::vector<student>::iterator i = v.begin(); i != v.end(); ++i){
// 			if( i->_score >= low && i->_score <= up) cout << i->_name << " " << i->_ID << endl;
// 			else if(i->_score < low) break;	
// 		}

// 	}	
// 	return 0;
// }
