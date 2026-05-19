#include <stack>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

struct bar {
	int height;
	int pos;
};

int largestRectangleArea(vector<int>& heights) {
	int size = heights.size();
	vector<int> left_nearest_smaller(size);
	vector<int> right_nearest_smaller(size);
	stack<unique_ptr<bar>> first_smaller;

	first_smaller.push(make_unique<bar>(-1, -1));

	for (int i = 0; i < size; ++i) {
		while (!first_smaller.empty() && heights[i] <= first_smaller.top()->height)
			first_smaller.pop();

		left_nearest_smaller[i] = first_smaller.top()->pos;
		first_smaller.push(make_unique<bar>(heights[i], i));
	}

	first_smaller = {};
	first_smaller.push(make_unique<bar>(-1, size));
	for (int i = size - 1; i > -1; --i) {
		while (!first_smaller.empty() && heights[i] <= first_smaller.top()->height)
			first_smaller.pop();

		right_nearest_smaller[i] = first_smaller.top()->pos;
		first_smaller.push(make_unique<bar>(heights[i], i));
	}

	int max_area = 0;

	for (int i = 0; i < size; ++i) {
		int area = heights[i] * (right_nearest_smaller[i] - left_nearest_smaller[i] - 1);
		max_area = max(max_area, area);
	}

	return max_area;
}

int largestRectangleArea_2(vector<int>& heights) {
	stack<int> left_bars;
	left_bars.push(-1);
	int max_area;

	for (int i = 0; i < heights.size(); ++i) {
		while (left_bars.top() != -1 && heights[i]  <= heights[left_bars.top()]) {
			int h = heights[left_bars.top()];
			left_bars.pop();
			int area = h * (i - left_bars.top());
			max_area = max(max_area, area);
		}

		left_bars.push(i);
	}

	while (left_bars.top() != -1) {
		int h = left_bars.top();
		left_bars.pop();
		int area = h * (heights.size() - left_bars.top() - 1);
		max_area = max(max_area, area);
	}

	return max_area;
}

int main() {
	vector<vector<int>> inputs = {
		{2, 1, 5, 6, 2, 3},
		{2, 4},
		{0}
	};

	for (auto& input: inputs)
		cout << largestRectangleArea(input) << '\n';

	return 0;
}
