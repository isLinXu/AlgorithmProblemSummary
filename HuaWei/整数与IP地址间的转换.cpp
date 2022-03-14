// 整数与IP地址间的转换

#include <iostream>
using namespace std;

int main()
{
	long long int a,b,c,d;
	long long int num;
	
	while(scanf("%lld.%lld.%lld.%lld",&a,&b,&c,&d)!=EOF){
		cin>>num;
		cout<<(a<<24)+(b<<16)+(c<<8)+d<<endl;
		a = num>>24;
		num = num-(a<<24);
		b = num>>16;
		num = num-(b<<16);
		c = num>>8;
		d = num-(c<<8);
		cout<<a<<"."<<b<<"."<<c<<"."<<d<<endl;
	}
}
