#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	unordered_map<int, int> num2count;
	vector<int> res;

	for (int x: nums1)
		++num2count[x];

	for (int y: nums2) {
		if (num2count.count(y)) {
			res.push_back(y);
			num2count.erase(y);
		}
	}

	return res;
}

int main() {
	vector<int> nums1 {3, 5, 7, 5, 3};
	vector<int> nums2 {3, 9, 5, 1, 11};

	vector<int> res = intersection(nums1, nums2);


	for (size_t i = 0; i < res.size(); ++i)
		cout << (i == 0 ? "" : ", ") << res[i];

	cout << '\n';

	return 0;
}
