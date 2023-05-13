#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

vector<int> parseInts(string str)
{
	stringstream ss(str);
	int temp;
	char comma;
	vector<int> numbers;
	while(ss >> temp)
	{
		ss >> comma;
		numbers.push_back(temp);
	}
	return numbers;
}

int main() 
{
	string str;
	cin >> str;
	vector<int> integers = parseInts(str);
	for(int i = 0; i < integers.size();i++)
	{
		cout << integers[i] << "\n";
	}

	return 0;

}
