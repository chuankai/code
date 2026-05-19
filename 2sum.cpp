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

int main() {
	vector<int> nums {2, 7, 11, 15};
	auto res = twoSum(nums, 9);

	cout << res[0] << ", " << res[1] << '\n'; 

	return 0;
}


