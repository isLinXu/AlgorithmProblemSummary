// 矩阵乘法计算量估算

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


struct Node {
	Node(pair<int, int> i): rc(i), is_matrix(true) {}
	Node(char i): c(i), is_matrix(false) {}
	pair<int, int> rc;
	char c;
	bool is_matrix;
};

// 计算
Node compute(Node a, Node b, int &count) {
	count += (a.rc.first * a.rc.second * b.rc.second);
	Node c(make_pair(a.rc.first, b.rc.second));
	return c;
}

// 插入操作符
void enop(stack<Node> &op, stack<Node> &re, char p, int &count) {
	if (p == '(') op.emplace(Node(p));
	else if (p == ')') {
		while (op.top().c != '(') {
			op.pop();
			Node a = re.top();
			re.pop();
			Node b = re.top();
			re.pop();
			re.emplace(compute(b, a, count));
		}
		op.pop();
	} else {
		if (op.top().c == '*') {
			op.pop();
			Node a = re.top();
			re.pop();
			Node b = re.top();
			re.pop();
			re.emplace(compute(b, a, count));
		}
		op.emplace(Node('*'));
	}
}

int main() {
	int n;
	while (cin >> n) {
		vector<pair<int, int>> matrix(n);
		int i = 0;
		pair<int, int> t;
		for (; i < n; ++i) {
			cin >> t.first >> t.second;
			matrix[i] = t;
		}
		i = 0;
		string s;
		cin >> s;
		stack<Node> re;
		stack<Node> op;
		int count = 0;
		// 遍历字符串，将矩阵和操作符压栈并计算，在合适的地方添加乘法操作符
		for (int j(0); j < s.size(); ++j) {
			if (s[j] >= 'A' && s[j] <= 'Z') {
				if (j == 0) {
					re.emplace(Node(matrix[i]));
					i++;
				} else if ((s[j - 1] >= 'A' && s[j - 1] <= 'Z') || s[j - 1] == ')') {
					enop(op, re, '*', count);
					re.emplace(Node(matrix[i]));
					i++;
				} else {
					re.emplace(Node(matrix[i]));
					i++;
				}
			} else if (s[j] == '(') {
				if (j == 0) enop(op, re, s[j], count);
				else if (s[j - 1] != '(') {
					enop(op, re, '*', count);
					enop(op, re, s[j], count);
				} else enop(op, re, s[j], count);
			} else enop(op, re, s[j], count);
		}
		// 操作符栈不为空，则继续计算
		while (!op.empty()) {
			op.pop();
			Node a = re.top();
			re.pop();
			Node b = re.top();
			re.pop();
			re.emplace(compute(b, a, count));
		}
		cout << count << endl;
	}
	return 0;
}

