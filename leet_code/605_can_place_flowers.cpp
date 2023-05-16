#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		if (n == 0){
			return true;
		}
        for(int i = 0;i < flowerbed.size();i++){
			if(flowerbed[i] == 0 && (i == flowerbed.size()-1 || flowerbed[i+1] == 0) && (i==0 || flowerbed[i-1] == 0) ){
				//cout << i << endl;
				n--;
				flowerbed[i] = 1;

				if(n<=0)
				{
					return true;
				}
			}
		}
	return false;
	}

};


int main(){
	int N;
	cin >> N;
	vector<int> flowerbed(N);
	int n;

	for(int i = 0; i < N;i++){
		int temp;
		cin >> temp;
		flowerbed[i] = temp;
	}

	cin >> n;
	Solution solution;

	cout << solution.canPlaceFlowers(flowerbed,n);
	return 0;
}
