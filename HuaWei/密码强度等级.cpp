// 密码强度等级

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i=0;
    int len=0;
    char str[300];
    while(cin>>str)
    {
        int score = 0;
        int length_char =0;
        int flag_char = 0;
        int lenath_Aa = 0;
        int flag_Aa = 0;
        int flag_a = 0;
        int flag_A = 0;
        int lenath_09 = 0;
        int flag_09 = 0;

        len=strlen(str);
        if(len <= 4)
        {
            score += 5;
        }
        else if(len >= 4 && len <= 8)
        {
            score += 10;
        }else if (len >= 8)
        {
            score += 25;
        }
        //printf("111 %d\n",score);
        //cout<<str<<endl;
        for(i=0;i<len;i++)
        {
            //cout<<str[i]<<endl;
            if(((str[i] >= 97 )&&(str[i] <= 122)) || ((str[i]>=65)&&(str[i] <= 90)))
            {
                lenath_Aa++;
                flag_Aa = 1;
                if((str[i] >= 97 )&&(str[i] <= 122))
                 flag_a = 1;
                else if((str[i]>=65)&&(str[i] <= 90))
                 flag_A = 1;
            }
            if( (str[i] >=48 ) && (str[i] <= 57))
            {
                lenath_09++;
                 flag_09 = 1;
            }
            //printf("%d %c\n",'{','{');
            //printf("%d %c\n",'~','~');
            if( ( (str[i]>=33) && (str[i] <= 47) ) || ( (str[i]>=58)&&(str[i] <= 64) ) ||  ( (str[i]>=91)&&(str[i] <= 96) ) ||  ( (str[i]>=123)&&(str[i] <= 126) ) )
            {
                length_char++;
                flag_char = 1;
            }

        }
        //AaZz
            if(lenath_Aa <= 0)
                ;
            else if(flag_Aa == 1)
            {
                if((flag_a & flag_A) == 0)
                    score += 10;
                else
                    score += 20;
            }
        //printf("222 %d\n",score);
        //num
            if(lenath_09 <= 0)
                ;
            else if(lenath_09 == 1)
                score += 10;
            else if(lenath_09 > 1)
                score += 20;

        //printf("333 %d\n",score);
        //char
            if(length_char <= 0)
                ;
            else if(length_char == 1)
                score += 10;
            else if(length_char > 1)
                score += 25;
       // printf("444 %d\n",score);
        //jiangli
        if(flag_Aa && flag_A && flag_a && flag_09 && flag_char)
        {
            score += 5;
        }
        else if(flag_Aa && flag_09 &&flag_char)
        {
            score += 3;
        }
        else if(flag_Aa && flag_09)
        {
            score += 2;
        }

        //printf("%d\n",score);
        if(score>=90)
        {
            cout<<"VERY_SECURE"<<endl;
        }else if(score>=80&&score<90)
            cout<<"SECURE"<<endl;
        else if(score>=70&&score<80)
            cout<<"VERY_STRONG"<<endl;
        else if(score>=60&&score<70)
            cout<<"STRONG"<<endl;
        else if(score>=50&&score<60)
            cout<<"AVERAGE"<<endl;
        else if(score>=25&&score<50)
            cout<<"WEAK"<<endl;
        else if(score>=0&&score<25)
            cout<<"VERY_WEAK"<<endl;

    }

    return 0;
}
