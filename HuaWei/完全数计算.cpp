// 完全数计算

//C++
#include <iostream>
#include <math.h>

using namespace std;

bool is_prime(int p) {
	for (int i = 2; i < sqrt(p); i++)
		if (p % i == 0)
			return false;
	return true;
}


// 如果p是质数，且2^p-1也是质数，那么（2^p-1）X2^（p-1）便是一个完全数
int main() {
	int n;
	while (cin >> n) {
		int count = 0;
		for (int p = 2; p < sqrt(n); p++) {
			long int t = pow(2, p) - 1;
			if (is_prime(p) && is_prime(t) ) {
				int perfect_num = pow(2, p - 1) * t;
				if ( perfect_num > 0 && perfect_num < n )
					count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}


