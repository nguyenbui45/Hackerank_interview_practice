#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

	vector<int< productExceptSelfOne(vector<int>& nums){
		/*Find the accumulative multiplication of the vector, then divide for each element access.
		 *
		 *Only work when the element list have no zero !
		 * O(n+n) runtime complexity and O(n) space complexity
		 *
		 */

		vector<int> ans(nums.size());
		int multi=1;
		for(const auto& e:nums)
			multi *= e;
		for(int i = 0;i < nums.size();i++){
			ans[i] = multi / nums[i];
		}

		return ans;
	}

    vector<int> productExceptSelfTwo(vector<int>& nums) {
		/* Finding the multiplication before and after the accessed element !
		 * O(n^2) run time complexity and O(n) space complexity
		 */
		vector<int> ans(nums.size());
		vector<int> pre(nums.size());
		vector<int> suff(nums.size());
		
		pre[0] = 1;
		suff[nums.size()-1] = 1;
        for(int i = 1;i < nums.size();i++){
			pre[i] = pre[i-1] * nums[i-1];
		}

        for(int i = nums.size() - 2 ;i >=0;i--){
			suff[i] = suf[i+1] * nums[i+1];
		}

		for(int i = 0; i < nums.size();i++){
			ans[i] = pre[i-1] * suf[i+1];
		}

		return ans;

    }

    vector<int> productExceptSelfTwo(vector<int>& nums) {
		vector<int> ans(nums.size(),1);
		int temp = 1;
        for(int i = 0;i < nums.size();i++){
			ans[i] *= temp;
			tempt *= nums[i];
		}
		temp = 1;
		for(int i = nums.size() - 1; i >=0;i--){
			ans[i] *= temp;
			temp *= nums[i];
		}

		return ans;

    }


};



	}


int main(){
	int N;
	cin >> N;
	vector<int> nums;
	for(int i = 0; i < N;i++){

		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	
	int index;
	cin >> index;
	//Solution solution;
	//cout << solution.productExceptSelf(nums);
	
	cout << recursive(0,N-1,index,nums);
	return 0;


}
