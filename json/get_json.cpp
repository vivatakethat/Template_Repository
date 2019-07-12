#include<iostream>
#include"/home/takethat/github_repository/json/single_include/nlohmann/json.hpp"
using namespace std;
using json=nlohmann::json;

int main()
{
    json j;  //创建json类
    cin>>j;   //从cin读入json对象
    cout<<j;  //输出序列化的json
    return 0;
}

