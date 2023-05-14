#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        //vector<int> extra_candies(candies.size());
		int extra_candies;
		vector<bool> result(candies.size());
		for(int i = 0; i < candies.size();i++){
			extra_candies = candies[i] + extraCandies;
			if(extra_candies >= *max_element(candies.begin(),candies.end())){
				result[i] = true;
			}
			else{
				result[i] = false;
			}
		}
		return result;
    }
};

int main(){

	int extra_candies;
	int n;
	cin >> n;
	vector<int> candies(n);
	for(int i = 0; i < n;i++){
		int temp;
		cin >> temp;
		candies[i] = temp;
	}

	cin >> extra_candies;
	Solution solution;
	vector <bool> result(n);
	result = solution.kidsWithCandies(candies,extra_candies);

	for(int j = 0; j < n; j++){
		cout << result[j] << " ";
	}
	return 0;
}

