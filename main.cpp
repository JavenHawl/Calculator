#include <iostream>
#include <string>
#include <iomanip>

#include "jiafa.cpp"
#include "jianfa.cpp"
#include "chengfa.cpp"
#include "chufa.cpp"

double num1,num2,result;
using namespace std;

int main()
{
    char s[1000],a[500],b[500];
    int sig=0,n;
    cin>>s;             //输入算式

    for (int i=0;s[i]!='\0';i++) //判断输入格式
        if (s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
            sig++,n=i;

    if (sig==1)   //判断运算符是否唯一
    {
        for (int j=0,i=0;s[j];j++)  //读取第一个数
        {
            if ((s[j]>='0' && s[j]<='9' )|| s[j]=='.')
                a[i++]=s[j];
            else
                break;
        }
        for (int j=n,i=0;s[j];j++)  //读取第二个数
        {
            if ((s[j]>='0' && s[j]<='9' )|| s[j]=='.')
                b[i++]=s[j];
        }

        num1=atof (a);
        num2=atof (b);

        switch (s[n])   //判断运算符并运算
        {
            case '+':result=jiafa(num1,num2);break;
            case '-':result=jianfa(num1,num2);break;
            case '*':result=chengfa(num1,num2);break;
            case '/':result=chufa(num1,num2);break;
            default:break;
        }
        cout << num1 << s[n] << num2 << "=" << std::setprecision(4)<<result;    //输出结果
    }
    else 
        cout<<"输入错误！";





    return 0;
}











/*
find_package(iostream REQUIRED)
find_package(iomanip REQUIRED)
find_package(string REQUIRED)

add_custom_command(
    TARGET ${CMAKE_PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_PROJECT_NAME} -E copy_directory
            "${PROJECT_SOURCE_DIR/assets}"
            "$<TARGET_FILE_DIR:${CAMKE_PROJECT_NAME}>/assets")

add_custom_command(
    TARGET ${CMAKE_PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_PROJECT_NAME} -E copy_directory
            "${PROJECT_SOURCE_DIR/shader}"
            "$<TARGET_FILE_DIR:${CAMKE_PROJECT_NAME}>/shader")



*/