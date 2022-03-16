// 百钱买百鸡

#include<iostream>
using namespace std;

//鸡翁、鸡母、鸡雏分别为x, y, z 三个变量。
//x+y+z=100
//5x+3y+z/3=100
//确定x即可算出y和z，若y和z为非负整数，则为有效结果，输出。

//int main(){
//	for(int x=0;x<=3;x++){
//		cout<<4*x<<" "<<25-7*x<<" "<<75+3*x<<endl;
//	}
//	return 0;
//}


#include<iostream>
using namespace std;

int main(){
	for(int i = 0; i <= 20; i++) {
		for(int j = 0; j <= 33; j++) {
			for(int k = 0; k <= 100; k++){ //遍历所有可能的公鸡、母鸡、小鸡取值
				if(i + j + k == 100 && 5 * i + 3 * j + double(k) / 3 == 100) {//鸡的总数等于100，且总共花了100元
					cout << i << " " << j << " " << k << endl;
				}
			}
		}
	}
	return 0;
}



