// 配置文件恢复

#include<bits/stdc++.h>
using namespace std;
int main() {
	string input;
	vector<pair<string, string>> instru = {{"reset", ""},
		{"reset", "board"},
		{"board", "add"},
		{"board", "delete"},
		{"reboot", "backplane"},
		{"backplane", "abort"}
	};    //存放每一对关键字
	
	vector<string> outInstru = {"reset what", "board fault", "where to add",
	                            "no board at all", "impossible", "install first"
	                           };    //存放每条命令对应执行结果
	while (getline(cin, input)) {   //获取输入的一行字符串
		stringstream ss(input);    //通过stingstream和getline的组合实现对字符串按空格进行分割
		string key1, key2;
		getline(ss, key1, ' ');
		getline(ss, key2, ' ');
		int count = 0;  //记录匹配的关键字个数
		string result;    //存放执行结果
		for (auto it = instru.begin(); it != instru.end(); it++) { //对所有命令进行匹配
			int i1 = it->first.find(key1); //i1记录key1在命令的前半部分第一次出现的下标
			int i2;    //i2记录key2在命令的后半部分第一次出现的下标
			if (key2 != "") { //如果key2不为空字符串，则获取key2在命令的后半部分第一次出现的下标
				i2 = it->second.find(key2);
			} else if (key2 == "" && it->second.empty()) { //如果key2和命令的后半部分都为空字符串，则i2为0
				i2 = 0;
			} else {   //否则i2为-1，表示后半部分没有匹配到对应的命令
				i2 = -1;
			}
			if (i1 == 0 && i2 == 0) { //只有当i1和i2都匹配成功时，才对匹配成功的命令进行计数
				count++;
				result = outInstru[it - instru.begin()];  //result存放执行结果
			}
		}
		if (count == 1) { //如果只有一个匹配的关键字，标志匹配命令成功，输出对应执行结果
			cout << result << endl;
		} else {   //否则就是没有匹配成功，输出"unknown command"
			cout << "unknown command" << endl;
		}
	}
	return 0;
}

