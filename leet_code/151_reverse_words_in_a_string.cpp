#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
		int count_space = 0;
		vector<string> normalized_str;
		string temp;
       for(int i = 0; i < s.length(); i++){
			if(s[i]==' '){
				cout << "count space"<<endl;
				count_space++;
			}
			else if(s[i] != ' '){
				temp.push_back(s[i]);
				cout << "push_back !"<<endl;
				count_space = 0;
				}

			if(temp.length() == 0 && s[i] == ' '){
				cout << "ignore" <<endl;
				continue;
			}
			else if(s[i] == ' ' && count_space == 1){
				cout << "normalized push back " << i <<endl;
				temp.push_back(s[i]);
				normalized_str.push_back(temp);
				count_space = 0;
				temp.clear();
			}

		if(i == s.length()-1 && s[i]!= ' '){
			temp.push_back(' ');
			normalized_str.push_back(temp);
		}

	   }
		//cout << "Done"<<endl;
		string output = "";
		for(int i = normalized_str.size()-1; i >= 0; i--){
			output = output + normalized_str[i];
		}

		if(output[-1] == ' '){
			output.pop_back();
		}

		return output;

    }
};

int main(){
	string s;
	getline(cin,s);
	Solution solution;
	cout << solution.reverseWords(s);
	return 0;
}
