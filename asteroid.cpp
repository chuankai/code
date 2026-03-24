#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
	stack<int> movingRight;
	vector<int> remaining;

	for (int a: asteroids) {
		if (a > 0) {
			movingRight.push(a);	
		} else {
			while (!movingRight.empty() && -a > movingRight.top()) {
					movingRight.pop();
			}
			if (movingRight.empty()) { remaining.push_back(a);
			} else if (-a == movingRight.top()) {
				movingRight.pop();
			}
		}
	}

	vector<int> remainingMovingRights; 
	while (!movingRight.empty()) {
		int a = movingRight.top();
		remainingMovingRights.insert(remainingMovingRights.begin(), a);
		movingRight.pop();
	}

	//remaining.append_range(remainingMovingRights);
	for (auto a: remainingMovingRights)
		remaining.push_back(a);

	return remaining;
}

int main() {
	vector<vector<int>> as_list {	{5, 10, -5},
									{8, -8},
									{10, 2, -5},
									{3, 5, -6, 2, -1, 4},
								};
	for (auto as: as_list) {
		auto after = asteroidCollision(as);
		if (!after.empty()) {
			for (int a: after)
				cout << a << " - "; 
		} else {
			cout << "Empty!";
		}
		cout << '\n';
	}


	return 0;
}
