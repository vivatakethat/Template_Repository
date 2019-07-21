//------------------------------------------------- 
// Without Boost LIB usage 
//------------------------------------------------- 
#include <sys/statvfs.h> 
#include <sys/sysinfo.h> 
#include<iostream>
#include<string>
using namespace std;
//------------------------------------------------- 
std::stringstream strStream; 
unsigned long hdd_size; 
unsigned long hdd_free; 
std::ostringstream strConvert; 
//--- 
struct sysinfo info; 
sysinfo(&info); 
//--- 
struct statvfs fsinfo; 
statvfs("/", &fsinfo); 
//--- 
//--- 
unsigned num_cpu = std::thread::hardware_concurrency(); 
//--- 
ifstream cpu_freq("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_cur_freq"); 
strStream << cpu_freq.rdbuf(); 
std::string cpufrequency = strStream.str(); 
//--- 
strStream.str(""); 
ifstream cpu_temp("/sys/class/thermal/thermal_zone0/temp"); 
strStream << cpu_temp.rdbuf(); 
strConvert<< fixed << setprecision(2) << std::stof(strStream.str()); 
std::string cputemp = strConvert.str(); 
//--- 
std::string mem_size = to_string((size_t)info.totalram *  (size_t)info.mem_unit); 
//--- 
hdd_size = fsinfo.f_frsize * fsinfo.f_blocks; 
hdd_free = fsinfo.f_bsize * fsinfo.f_bfree; 
//---             
std::cout << "CPU core number   ==" << num_cpu  << endl; 
std::cout << "CPU core speed   ==" << cpufrequency << endl; 
std::cout << "CPU temperature (C)  ==" << cputemp  << endl; 
//--- 
std::cout << "Memory size    ==" << mem_size  << endl; 
//--- 
std::cout << "Disk, filesystem size  ==" << hdd_size  << endl; 
std::cout << "Disk free space   ==" << hdd_free  << endl; 
//--- 
