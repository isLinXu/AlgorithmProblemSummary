/*
查找兄弟单词
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//查找兄弟单词的函数接口，兄弟单词：单词的字母及其个数相同，但字母的排列顺序不全相同
int Search_Brother_Word(int num)
{
	string str; //字典里面的单词（小写英文字符）
	string word; //指定的单词
	vector <string> vec; //用一个向量来存储单词（形成单词字典）
	vector <string> vec_BW; //用一个向量来存储兄弟单词（形成兄弟单词字典），BW 代表 Brother Word
	int BW_index; //序号，用于查找指定单词的所有兄弟单词中序号所对应的兄弟单词（序号减一，因为从零开始）
	//输入单词，形成单词字典
	for (int i = 0; i < num; i++)
	{
		cin >> str;
		vec.push_back(str);
	}
	sort(vec.begin(), vec.end()); //输入的多个单词按字典序排列
	cin >> word; //指定单词，当然这个单词可能在、也可能不在原来的字典里面
	cin >> BW_index; //指定单词 word 的所有兄弟单词中排在第 BW_index 的单词对应序号 BW_index - 1
	//判断字典中的单词是否为指定单词的兄弟单词，若是，则将其写入兄弟单词向量 vec_BW
	string word_copy = word; //拷贝一份指定的单词，作为基准比较（字母顺序未变动）
	sort(word.begin(), word.end()); //指定的单词的字母按字典序排列
	//遍历单词字典，寻找指定单词的兄弟单词并记录在兄弟单词字典中
	for (int i = 0; i < vec.size(); i++)
	{
		//先判断字典中的单词的长度和指定单词的长度是否一致
		if (vec[i].size() == word.size())
		{
			//长度相同且字母顺序不同的单词，才可能是兄弟单词，这里反复用单词的拷贝来作为基准
			if (vec[i] != word_copy)
			{
				string copy = vec[i]; //提前拷贝一份字典中的单词，作为后续写入兄弟单词字典的样本（需要的话）
				sort(vec[i].begin(), vec[i].end()); //字典中的单词的字母按字典序排列
				//原本不相同的单词，经过字母排序后相同，才是互为兄弟单词
				if (vec[i] == word)
				{
					vec_BW.push_back(copy);
				}
			}
		}
	}
	//分类输出结果
	//兄弟单词字典为空
	if (vec_BW.size() == 0)
	{
		cout << 0 << endl;
	}
	//兄弟单词字典不为空，但待查找的兄弟单词不存在
	else if (((vec_BW.size() > 0) && (vec_BW.size() < BW_index)) || ((vec_BW.size() > 0) && (BW_index < 1)))
	{
		cout << vec_BW.size() << endl;
	}
	//兄弟单词字典不为空，且待查找的兄弟单词存在
	else if ((vec_BW.size() > 0) && (vec_BW.size() >= BW_index) && (BW_index >= 1))
	{
		cout << vec_BW.size() << '\n' << vec_BW[BW_index - 1] << endl;
	}
	return 0;
}
//主函数
int main()
{
	int num;
	while (cin >> num)
	{
		Search_Brother_Word(num);
	}
	return 0;
}
