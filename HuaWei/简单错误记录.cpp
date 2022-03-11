// 简单错误记录
#include <iostream>
#include <string>
#include <deque>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::deque;

int main() {
	string str;
	map<string, int> result;
	deque<string> deq;
	while (getline(cin, str)) {
		str = str.substr(str.find_last_of('\\') + 1);
		int pos = str.find_last_of(' ');
		if ( pos > 16) {
			str = str.substr(pos - 16);
		}

		if (result.find(str) == result.end()) deq.push_back(str);
		++result[str];
		if (deq.size() > 8) deq.pop_front();
	}
	for (auto x : deq) {
		cout << x << " " << result[x] << endl;
	}
	return 0;
}
