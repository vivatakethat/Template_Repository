#include<iostream>
using namespace std;
struct sysinfo {
  std::string os;
  std::string cpu;
  std::string ram;
  std::string LinuxkernelVersion=NULL;
};

int main()
{
    

sysinfo take=sysinfo();
cout<<take.LinuxkernelVersion<<endl;

return 0;

}
