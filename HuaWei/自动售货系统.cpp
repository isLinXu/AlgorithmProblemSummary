// 自动售货系统

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Goods {
	private:
		string name;
		int price;
		int num;

	public:
		Goods() {
			name = "NONE";
			price = 0;
			num = 0;
		}
		Goods(string str, int i, int j) {
			name = str;
			price = i;
			num = j;
		}
		void Init(int j) {
			num = j;
		}
		string& NAME() {
			return name;
		}
		int& PRICE() {
			return price;
		}
		int& NUM() {
			return num;
		}
		void addGoods(int i = 1) {
			num += i;
		}
		void reduceGoods(int i = 1) {
			num -= i;
		}
};


class SavingBox {
	private:
		unordered_map<int, int> coins;
	public:
		SavingBox() {
			coins[1] = 0;
			coins[2] = 0;
			coins[5] = 0;
			coins[10] = 0;
		}
		SavingBox(unordered_map<int, int>& index) {
			for (auto iter = index.begin(); iter != index.end(); iter++) {
				coins[iter->first] = iter->second;
			}
		}
		unordered_map<int, int>& COINS() {
			return coins;
		};
		void Init(unordered_map<int, int>& index) {
			for (auto iter = index.begin(); iter != index.end(); iter++) {
				coins[iter->first] = iter->second;
			}
		}
		void addCoin(int i, int j = 1) {
			coins[i] += j;
		}
		void reduceCoin(int i, int j = 1) {
			coins[i] -= j;
		}
		int getCoinNum(int i) {
			if (coins.count(i)) {
				return coins[i];
			} else {
				throw ("输入错误");
			}
		}
};


class VendingSystem {
	private:
		vector<string> names = {"A1", "A2", "A3", "A4", "A5", "A6"};
		vector<int> prices = {2, 3, 4, 5, 8, 6};
		vector<Goods> shops;
		vector<int> coins = {1, 2, 5, 10};
		SavingBox box;
		int balance;  // 投币余额

	public:
		VendingSystem() {
			for (int i = 0; i < 6; i++) {
				shops.push_back(Goods(names[i], prices[i], 0));
			}
			unordered_map<int, int> index;
			for (int k = 0; k < int(coins.size()); k++) {
				index[coins[k]] = 0;
			}
			box = SavingBox(index);
			balance = 0;
		}
		void Run(string str) {
			if (str[0] == 'r') {
				Init(str);
			} else if (str[0] == 'p') {
				Pay(str);
			} else if (str[0] == 'b') {
				Buy(str);
			} else if (str[0] == 'c') {
				Change();
			} else if (str[0] == 'q') {
				Query(str);
			} else {
				throw ("输入错误");
			}
		}
		void Init(string str) {
			balance = 0;

			// 22-18-21-21-7-20 3-23-10-6
			str = str.substr(2, str.size() - 2);
			string initGoodCmd = str.substr(0, str.find(' '));
			string initBoxCmd = str.substr(str.find(' ') + 1, str.size() - str.find(' ') - 1);

			vector<int> nums;
			int i = 0, j = 0;
			while (j < int(initGoodCmd.size())) {
				if (initGoodCmd[j] == '-') {
					nums.push_back(atoi(initGoodCmd.substr(i, j - i).c_str()));
					i = j + 1;
				}
				j++;
			}
			nums.push_back(atoi(initGoodCmd.substr(i, j - i).c_str()));
			for (int k = 0; k < 6; k++) {
				shops[k].Init(nums[k]);
			}

			nums.clear();
			i = 0, j = 0;
			while (j < int(initBoxCmd.size())) {
				if (initBoxCmd[j] == '-') {
					nums.push_back(atoi(initBoxCmd.substr(i, j - i).c_str()));
					i = j + 1;
				}
				j++;
			}
			nums.push_back(atoi(initBoxCmd.substr(i, j - i).c_str()));
			unordered_map<int, int> index;
			for (int k = 0; k < int(coins.size()); k++) {
				index[coins[k]] = nums[k];
			}
			box.Init(index);

			cout << "S001:Initialization is successful" << endl;
		}
		void Pay(string str) {
			//获取面额
			int money = atoi(str.substr(2, str.size() - 2).c_str());
			if (!count(coins.begin(), coins.end(), money)) {
				cout << "E002:Denomination error" << endl;
				return;
			}
			if (money == 5 || money == 10) {
				if ((box.getCoinNum(1) + box.getCoinNum(2) * 2) < money) {
					cout << "E003:Change is not enough, pay fail" << endl;
					return;
				}
			}
			//查询剩余商品数量
			bool flag = true;
			for (auto shop : shops) {
				if (shop.NUM() > 0) {
					flag = false;
					break;
				}
			}
			if (flag) {
				cout << "E005:All the goods sold out" << endl;
				return;
			}
			// 投币成功
			balance += money;
			box.addCoin(money);
			cout << "S002:Pay success,balance=" << balance << endl;
		}
		void Buy(string str) {
			string name = str.substr(2, str.size() - 1);
			if (!count(names.begin(), names.end(), name)) {
				cout << "E006:Goods does not exist" << endl;
				return;
			}
			Goods& shop = shops[distance(names.begin(), find(names.begin(), names.end(), name))];
			if (shop.NUM() == 0) {
				cout << "E007:The goods sold out" << endl;
				return;
			}
			if (shop.PRICE() > balance) {
				cout << "E008:Lack of balance" << endl;
				return;
			}
			//购买成功
			shop.reduceGoods();
			balance -= shop.PRICE();
			cout << "S003:Buy success,balance=" << balance << endl;
		}
		void Change() {
			if (balance == 0) {
				cout << "E009:Work failure" << endl;
				return;
			}
			vector<int> info(coins.size());
			for (int i = coins.size() - 1; i >= 0; i--) {
				int coin = coins[i];
				while (balance >= coin && box.getCoinNum(coin) > 0) {
					balance -= coin;
					box.reduceCoin(coin);
					info[i]++;
				}
			}
			for (int i = 0; i < int(info.size()); i++) {
				cout << coins[i] << " yuan coin number=" << info[i] << endl;
			}
		}
		void Query(string str) {
			if (str == "q 0") {
				// 根据商品数量从大到小排序
				vector<Goods> shops_ = shops;
				sort(shops_.begin(), shops_.end(), cmp);
				for (auto shop : shops_) {
					cout << shop.NAME() << " " << shop.PRICE() << " " << shop.NUM() << endl;
				}
				return;
			}
			if (str == "q 1") {
				for (int coin : coins) {
					cout << coin << "yuan coin number=" << box.getCoinNum(coin) << endl;
				}
				return;
			}
			cout << "E010:Parameter error" << endl;
		}
		static bool cmp(Goods g1, Goods g2) {
			return g2.NUM() < g1.NUM();
		}
};



int main() {
	string str;
	vector<string> cmds;
	VendingSystem sys;

	while (getline(cin, str)) {
		int i = 0, j = 0;
		cmds.clear();
		while (j < int(str.size())) {
			if (str[j] == ';') {
				cmds.push_back(str.substr(i, j - i));
				i = j + 1;
			}
			j++;
		}
		for (unsigned int i = 0; i < cmds.size(); i++) {
			//cout << cmds[i] << endl;
			sys.Run(cmds[i]);
		}
	}
}

