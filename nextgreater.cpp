#include <vector>
#include <stack>
#include <iostream>
#include <unordered_map>
#include <ranges>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
  vector<int> res;

  for (int n : nums1) {
    bool found = false;
    res.push_back(-1);
    for (int m : nums2)
      if (!found) {
          found = n == m;
      } else if (m > n) {
          res.back() = m;
          break;
      }
  }

  return res;
}

vector<int> nextGreaterElement2(vector<int>& nums1, vector<int>& nums2) {
  stack<int> greater;
  unordered_map<int, int> next_greater;

  for (int n : nums2 | views::reverse) {
	while (!greater.empty() && n >= greater.top()) {
		greater.pop();
	}	

	next_greater[n] = greater.empty() ? -1 : greater.top();

    greater.push(n);
  }

  vector<int> res;

  for (int n : nums1)
    res.push_back(next_greater[n]);

  return res;
}

int main() {
  vector all_nums {50, 30, 10, 90, 20, 70, 40, 60, 80};
  vector some_nums {20, 10, 30, 70, 90};

  auto r = nextGreaterElement2(some_nums, all_nums);
  for (int n : r)
    cout << n << ' '; 

  cout << '\n';

  return 0;
}
