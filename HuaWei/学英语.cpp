// 学英语

#include <iostream>
#include <string>

using namespace std;

const string ones[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
const string tens[] = { "ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen" };
const string twenties[] = { "zero","ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety" };
const int ihundreds[] = { (int)1e2, (int)1e3, (int)1e6, (int)1e9, (int)1e12 };
const string hundreds[] = { "hundred", "thousand", "million", "billion" };

string itoe(long long n){
	if (0<=n && n<=9){//个位数，直接输出
		return ones[n];
	}
	if (10<=n && n<20){//十位数，直接输出
		return tens[n%10];
	}
	if (20<=n && n<1e2){//20-100
		return twenties[n/10] + (n%10 ? " " + ones[n%10] : "");
	}
	for (int i=0; i < 4; i++){//大于100
		if (n < ihundreds[i+1]) {//确定范围
			return itoe(n/ihundreds[i]) + " " + hundreds[i] + (n%ihundreds[i] ? (i ? " ": " and ") + itoe(n%ihundreds[i]) : "");//递归转换
		}
	}
	return "";
}

int main(){
	long long n;
	while (cin>>n){
		cout<<itoe(n)<<endl;
	}
	return 0;
}

