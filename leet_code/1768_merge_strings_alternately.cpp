#include<iostream>
#include<string>
using namespace std;

class Solution{
	public:
		string Alternately(string word1, string word2){
			int len_word1 =word1.length();
			int len_word2 =word2.length();
			int len;
			int offset;
			string merge_string;
			if (len_word1 > len_word2)
			{
				len = len_word2;
				offset = len_word1 - len_word2;
			}
			else
			{
				len = len_word1;
				offset = len_word2 - len_word1;
			}

			for(int i = 0; i < len; i++)
			{
				merge_string.push_back(word1[i]);
				merge_string.push_back(word2[i]);
			}
			
			for(int i = len; i < (len+offset);i++)
			{
				if(len_word1 == len)
				{
					merge_string.push_back(word2[i]);
				}
				else
				{
					merge_string.push_back(word1[i]);
				}
			}
		return merge_string;
		}
};

int main()
{
	Solution solution;
	string word1,word2;
	cin >> word1 >> word2;
	cout << (solution.Alternately(word1,word2));
	return 0;
}
