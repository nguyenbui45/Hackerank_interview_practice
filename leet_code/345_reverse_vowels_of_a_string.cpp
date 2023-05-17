#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
		vector<char> vowels;
        for(int i = 0; i < s.length();i++){
			if(s[i] == 'a'|| s[i] == 'A' ||s[i] == 'e' || s[i] == 'E' || 
				s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' ||
				s[i] == 'u' || s[i] == 'U' ){
				vowels.push_back(s[i]);

			}
		}
		int index_vowels_list = vowels.size()-1;
        for(int i = 0; i < s.length();i++){
			if(s[i] == 'a'|| s[i] == 'A' ||s[i] == 'e' || s[i] == 'E' || 
				s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' ||
				s[i] == 'u' || s[i] == 'U' ) {

				s[i] = vowels[index_vowels_list];
				index_vowels_list--;
			}

		}
	return s;
	}
};


class Optimal_Solution{
	public: 
		string reverseVowels(string s) {
			

		}


};


int main(){
	string s;
	cin >> s;

	Solution solution;
	cout << solution.reverseVowels(s);
	return 0;
}
