// 记负均正

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n ;

	while ( cin >> n) {
		string str;

		//负数的个数
		int num1 = 0;
		int num2 = 0;
		int num = 0;
		double sum = 0.0;
		double avg = 0.0;
		for ( int i = 0; i < n ; i++) {
			cin >> str;
			num = atoi(str.c_str());
			if ( num == 0 ) {
				continue;
			} else if ( num < 0 ) { //负数的个数
				num1++;
			} else {
				num2++;
				sum += num;
			}
		}
		if ( sum > 0) {
			avg = sum / num2;
		}
		printf("%d %.1lf\n", num1, avg);
	}
	return 0;
}


