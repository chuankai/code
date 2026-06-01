#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> count;
	vector<int> ret {-1, -1};

	for (int x: nums) {
		++count[x];
		cout << "count[" << x << "] = " << count[x] << '\n';
	}

	for (int x: nums) {
		int d = target - x;
		cout << "Current: " << x << ", delta: " << d << ", count[" << d << "] = " << count[d] << '\n';
		//if (count[d] == (d == x ? 2 : 1))
		if (count[d] == 1) {
			ret = {x, d};
			break;
		}
	}

	return ret;
}

vector<int> twoSum_2(vector<int>& nums, int target) {
	unordered_map<int, int> num2count;

	for (int i = 0; i < nums.size(); ++i) {
		int complement = target - nums[i];
		if (num2count.count(complement))
			return  {i, num2count[complement]};
		else
			num2count[nums[i]] = i;
	}

	return {};
}

int main() {
	vector<int> nums {2, 7, 11, 15};
	auto res = twoSum(nums, 9);

	cout << res[0] << ", " << res[1] << '\n'; 

	auto res2 = twoSum_2(nums, 9);
	cout << res2[0] << ", " << res2[1] << '\n'; 

	return 0;
}


