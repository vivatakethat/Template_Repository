#include <json.hpp>
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
auto j3=json::parse("{\"happy\":true,\"pi\":3.14}");
//cout<<"[j]:\n"<<j<<endl;
//cout<<"[jj]:\n"<<jj<<endl;
//cout<<"[j2]\n"<<j2<<endl;
//string s= j.dump();
//string ss= j.dump(4);

//cout<<j2<<endl;


//cout<<jj<<endl;
/* 
cout<<jjj<<endl;
cout<<j2<<endl;
cout<<j3<<endl;
*/


/*-------------------------------------- */
// a way to express the empty array []
json empty_array_explicit = json::array();

// ways to express the empty object {}
json empty_object_implicit = json({});
json empty_object_explicit = json::object();

// a way to express an _array_ of key/value pairs [["currency", "USD"], ["value", 42.99]]
json array_not_object = json::array({ {"currency", "USD"}, {"value", 42.99} });

//cout<<empty_array_explicit<<endl;


json arr_j;
arr_j["list"] = { 1, 0, 2 };


cout<<arr_j["list"]<<endl;
  return 0;

}


