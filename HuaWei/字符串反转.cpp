// 字符串反转
/*输入：abcd
  输出：dcba
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	
	string str;
	
	getline(cin, str);
	reverse(str.begin(), str.end());
	cout << str << endl;
	
	return 0;
}
