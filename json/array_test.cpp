#include<iostream>
#include<vector>
#include <json.hpp>


using json = nlohmann::json;
using namespace std;

int main()
{
 
std::array<unsigned long,4> c_array {{1, 2, 3, 4}};
json j_array(c_array);
// [1, 2, 3, 4]

cout<<j_array[1]<<endl;

    return 0;



}