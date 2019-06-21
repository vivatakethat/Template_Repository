#include"sysinfo.hpp"
#include<string>
int main()
{

  sysinfo s_i = get_sysinfo();
  std::cout <<"[OS]"<<  s_i.os<<std::endl;
  std::cout<<"[Architecture]"<<s_i.Architecture<<std::endl;
  std::cout <<"[CPU]"<< s_i.cpu << std::endl;
  std::cout <<"[RAW]"<< s_i.ram << std::endl;
  std::cout<<"[LinuxkernelVersion]:" << s_i.LinuxkernelVersion << std::endl;



  
return 0;
}
	 



