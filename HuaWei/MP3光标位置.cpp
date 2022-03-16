// MP3光标位置

//C++实现，不借助容器，设定两个变量，一个是光标指向的歌曲数(1—歌曲总数)，另一个是光标在框内的的相对位置(1/2/3/4)
//得到这两个值就可以推导出框内的4首歌曲，代码如下，还可以更简介

#include<iostream>
using namespace std;
#include<string>

int main() {
	int num;
	string str;
	while (cin >> num >> str) {
		int index = 1;
		int len = str.length();
		int Up = 0, Down = 0;
		int pos = 0;  //记录当前光标的位置
		if (num <= 4) {
			for (int i = 0; i < len; ++i) {
				if (index == num && str[i] == 'D') {
					index = 1;
				} else if (index == 1 && str[i] == 'U') {
					index = index - 1 + num;
				} else if (str[i] == 'U') {
					index--;
				} else if (str[i] == 'D') {
					index++;
				}
			}
			for (int i = 1; i <= num; ++i) {
				cout << i << " ";
			}
		} else {
			for (int i = 0; i < len; ++i) {
				if (index == num && str[i] == 'D') {
					index = 1;
					pos = 1;
				} else if (index == 1 && str[i] == 'U') {
					index = num;
					pos = 4;
				} else if (str[i] == 'U') {
					index--;
					if (pos != 1)    pos--;
					else pos = 1;
				} else if (str[i] == 'D') {
					index++;
					if (pos != 4) pos++;
					else pos = 4;
				}
			}
			switch (pos) {
				case 1: {
					for (int i = index; i < index + 4; ++i)
						cout << i << " ";
					break;
				}
				case 2: {
					for (int i = index - 1; i < index + 3; ++i)
						cout << i << " ";
					break;
				}
				case 3: {
					for (int i = index - 2; i < index + 2; ++i)
						cout << i << " ";
					break;
				}
				case 4: {
					for (int i = index - 3; i < index + 1; ++i)
						cout << i << " ";
					break;
				}
			}
		}
		cout << endl << index << endl;
	}
	return 0;
}
