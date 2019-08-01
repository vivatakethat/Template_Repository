#include<iostream>
#include<vector>
#include <json.hpp>


using json = nlohmann::json;
using namespace std;

int main()
{

// create an array using push_back
json j;
j.push_back("foo");
j.push_back(1);
j.push_back(true);

// also use emplace_back
j.emplace_back(1.78);

// iterate the array
for (json::iterator it = j.begin(); it != j.end(); ++it) {
  std::cout << *it << '\n';
}


return 0;


}