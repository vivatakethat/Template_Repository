#include </home/takethat/github_repository/json/single_include/nlohmann/json.hpp>
#include<iostream>
using  namespace std;


// for convenience
using json = nlohmann::json;

int main()
{
 
json var;
json j;

//j["pi"] = 3.141;

//cout<<j["pi"] <<endl;

// instead, you could also write (which looks very similar to the JSON above)
json j2 = {
  {"pi", 3.141},
  {"happy", true},
  {"name", "Niels"},
  {"nothing", nullptr},
  {"answer", {
    {"everything", 42}
  }},
  {"list", {1, 0, 2}},
  {"object", {
    {"currency", "USD"},
    {"value", 42.99}
  }}
};

 
 cout<<j2["object"]["value"]<<endl;

    return 0;
}


