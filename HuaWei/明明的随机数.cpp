#include<iostream>
#include<cstdio>
#include<string.h>
#include<unordered_map> //hash map


using namespace std;

int main() {
	
//	int num,n;
//	while(cin >> num){
//		int a[1001] = {}; //hash表
//		while(num --){
//			cin >> n;
////			a[1] = 0
//			a[n] = 1;
//		}
//		for (int i = 1; i < 1001; i++){
//			if (a[i] == 1){
//				cout << i << endl;
//			}
//		}
//	}
	int num, n;
	while (cin >> num) {
		unordered_map<int, int> a(1001);
		while (num--) {
			cin >> n;
			a[n] = 1;
		}

		for (int i = 1; i < 1001; i++) {
			if (a[i] == 1) {
				cout << i << endl;
			}
		}
	}



	return 0;
}
