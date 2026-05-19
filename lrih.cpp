#include <vector>
#include <memory>
#include <iostream>

using namespace std;

struct bar {
	int pos;
	int height;
};

int largestRectangleArea(vector<int>& heights) {
	vector<unique_ptr<bar>> lower_bars;
	lower_bars.push_back(make_unique<bar>(-1, 0));
	int max_area = 0;

	for (size_t i = 0; i < heights.size(); ++i) {
		while (!lower_bars.empty() && lower_bars.back()->height >= heights[i])
			lower_bars.pop_back();

		lower_bars.push_back(make_unique<bar>(i, heights[i]));
		for (size_t j = 1; j < lower_bars.size(); ++j) {
			int area = lower_bars[j]->height * (i - lower_bars[j - 1]->pos);	
			max_area = max(max_area, area); 
		}
	}

	return max_area;
}

int main() {
	vector<vector<int>> heights_list {{2, 1, 5, 6, 2, 3}, {2, 4}, {0}};

	for (auto& heights: heights_list)
		cout << largestRectangleArea(heights) << '\n';

	return 0;
}
