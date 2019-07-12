#include </home/takethat/github_repository/json/single_include/nlohmann/json.hpp>
#include<iostream>
using  namespace std;

// for convenience
using json = nlohmann::json;

int main()
{
// create object from string literal
json j = "{ \"happy\": true, \"pi\": 3.141 }"_json;
json jj = "{ \"happy\": true, \"pi\": 3.141 }";
string jjj="{ \"happy\": true, \"pi\": 3.141 }";

// or even nicer with a raw string literal
auto j2 = R"(
  {
    "happy": true,
    "pi": 3.141
  }
)"_json;

auto j3=json::parse("{\"happy\":true,\"pi\":3.14}");
//cout<<"[j]:\n"<<j<<endl;
//cout<<"[jj]:\n"<<jj<<endl;
//cout<<"[j2]\n"<<j2<<endl;
//string s= j.dump();
//string ss= j.dump(4);
/*
cout<<j<<endl;
cout<<jj<<endl;
cout<<jjj<<endl;
cout<<j2<<endl;
cout<<j3<<endl;
*/

string s=j.dump(4);
cout<<s<<endl;
  return 0;

}


