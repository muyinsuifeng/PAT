#include <iostream>
#include <string>
using namespace std;
int change(char a){
	return a - '0';
}
int main(int argc, char const *argv[]){
	string num[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	string jinzhi[9] = {"", "Shi", "Bai", "Qian", "Wan","Shi", "Bai", "Qian", "Yi"};
	string T;
	while(cin >> T){
		if(T == "0") cout << "ling" << endl;
		else{
			string result = "";
			int weishu = T.size();
			if(T[0] == '-'){	
				weishu--;
				result += "Fu ";
				int flag = 0;
				for (int i = 1; i < T.size(); ++i){
					if(T[i] == '0'){
						if((T.size() - 1 - i) % 4 == 0){ //102000,1012000
							if((T.size() - 1 - i) / 4 == 1){
								if(flag == 0)
									result = result + "Wan ";
								else
									result = result.substr(0,result.size()-5);
							}else{
								if(flag > 0)
									result = result.substr(0,result.size()-5);
							}
							flag = 0;
						}else{
							if(!flag){
								result = result + num[0] + " ";
							}
							flag ++;
						}
					}else{
						result = result + num[change(T[i])] + " " + jinzhi[weishu - 1] + " ";
						flag = 0;
					}
					weishu --;
				}
			}else{
				int flag = 0;
				for (int i = 0; i < T.size(); ++i){
					if(T[i] == '0'){
						if((T.size() - 1 - i) % 4 == 0){ //102000,1012000
							if((T.size() - 1 - i) / 4 == 1){
								if(flag == 0)
									result = result + "Wan ";
								else
									result = result.substr(0,result.size()-5);
							}else{
								if(flag > 0)
									result = result.substr(0,result.size()-5);
							}
							flag = 0;
						}else{
							if(!flag){
								result = result + num[0] + " ";
							}
							flag ++;
						}
					}else{
						result = result + num[change(T[i])] + " " + jinzhi[weishu - 1] + " ";
						flag = 0;
					}
					weishu --;
				}
			}
			cout << (result.substr(0,result.size()-1)) << endl; 
		}
		
	}
	return 0;
}
