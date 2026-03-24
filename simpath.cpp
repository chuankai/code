#include <memory>
#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

bool getstring(istringstream& iss, string& str, char delim = '\n') {
	char tmp[255];
	
	if (iss.getline(tmp, sizeof(tmp), delim)) {
		str = string {tmp};
		return true; 
	} else {
		str = "";
		return false;
	} 
}

string simplifyPath(string p) {
	vector<string> filedirs {};
	istringstream iss {p};

	for (char tmp[255]; iss.getline(tmp, 255, '/'); ) {
		string str {tmp};
		if (str == "" || str == ".") {
			continue;
		} else if (str == "..") {
			if (!filedirs.empty())
				filedirs.pop_back();
		} else {
			filedirs.push_back(str);
		}
	}

	string path {};
	if (filedirs.size() == 0)
		path = "/";
	else
		for (auto& s: filedirs)
			path += '/' + s;

	return path;
}

int main() {
	for (string path: {	"/home/john/work/projects",
						"/home/", "/home//foo/",
						"/home/user/Documents/../Pictures", "/../",
						"/.../a/../b/c/../d/./"
						})
		cout << simplifyPath(path) << '\n';
	
	return 0;
}
