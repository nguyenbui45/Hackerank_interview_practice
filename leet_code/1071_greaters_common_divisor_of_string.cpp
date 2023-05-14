#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution{

	public:
		Solution(){
		}

		bool isDivisor(int l,string str1,string str2){
			int len1 = str1.length();
			int len2 = str2.length();

			if(len1 % l != 0 || len2 % l != 0)
			{
				return false;
			}
			int f1 = len1 / l;
			int f2 = len2 / l;
			
			string test1,test2,test3;
			test1.clear();
			test2.clear();
			test3.clear();
			for(int i = 0; i < l;i++){
				test1 = test1 + str1[i];
			}
			for(int i=0;i < f1;i++){
				test2 = test2 + test1;
			}
			for(int i=0;i < f2;i++){
				test3 = test3 + test1;
			}

			if(test3 == str2 && test2 == str1){
				return true;
			}
			else
			{
				return false;
			}



		}

		string gcdOfString(string str1, string str2){
			int len1 = str1.length();
			int len2 = str2.length();
			string subs;
			for (int i = min(len1,len2); i > 0;i--)
			{
				if(this->isDivisor(i,str1,str2) == true){
					for(int j = 0; j < i;j++){
						subs = subs + str1[j];
					}
					return subs;
				}
			}
			return "";
		}
};


class Optimal_Solution {
	public:	
	string gcdOfString(string str1,string str2){
		int len1 = str1.length();
		int len2 = str2.length();

		if(str1 + str2 != str2 + str1) {
			return "";
		}

		return str1.substr(0,__gcd(len1,len2));
	}
};


int main(){
	string s1,s2;
	cin >> s1;
	cin >> s2;
	Optimal_Solution gcd;
	cout << gcd.gcdOfString(s1,s2);
	return 0;
}

