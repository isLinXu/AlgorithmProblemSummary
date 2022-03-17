#include<bits/stdc++.h>
using namespace std;
int main() {
    int i=0;        //用于区分是原文还是密文
    string oritext;        //存放输入字符串
    vector<pair<char, char>> vec;    //利用pair记录加密解密规则
    vector<pair<char, char>>::iterator it;    //迭代器
    for(int i=0;i<26;i++) {    //将规则写入vector容器中
        if(i==25) {
            vec.push_back(make_pair('Z', 'a'));
            vec.push_back(make_pair('z', 'A'));
            continue;
        }
        vec.push_back(make_pair('A'+i, 'b'+i));
        vec.push_back(make_pair('a'+i, 'B'+i));
    }
    for(int i=0;i<10;i++) {
        if(i==9) {
            vec.push_back(make_pair('9', '0'));
            continue;
        }
        vec.push_back(make_pair('0'+i, '1'+i));
    }
    while(getline(cin, oritext)) {    //按照规则对输入字符串进行加密解密
        i++;    //每获取到一个字符串，i++
        if(i%2) {    //奇数为原文,进行加密操作
            for(int i=0;i<oritext.length();i++) {
                for(it=vec.begin();it!=vec.end();it++) {
                    if(oritext[i]==it->first) {
                        oritext[i] = it->second;
                        break;
                    }
                }
            }
            cout<<oritext<<endl;
        }
        else {    //偶数为密文，进行解密操作
            for(int i=0;i<oritext.length();i++) {
                for(it=vec.begin();it!=vec.end();it++) {
                    if(oritext[i]==it->second) {
                        oritext[i] = it->first;
                        break;
                    }
                }
            }
            cout<<oritext<<endl;
        }
    }
    return 0;
}
