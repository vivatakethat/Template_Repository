#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <linux/hdreg.h>
#include <parted/parted.h>
#include <asm/byteorder.h>
#include <linux/fs.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <vector>
#include <string>
int main()
{
    FILE *out = NULL;
    char buffer[1024];
    memset(&buffer, 0x00, sizeof(buffer));
    int n_Size = 0;
    out = popen("eval getent passwd {$(awk '/^UID_MIN/ {print $2}' /etc/login.defs)..$(awk '/^UID_MAX/ {print $2}' /etc/login.defs)} | wc -l | awk 1 ORS=' '", "r"); //get count of normal user
    fgets(buffer, sizeof(buffer), out);
    if (out == NULL)
    {
        printf("%d  peopen call fail, error\n", __LINE__);
    }
    else
    {
        fgets(buffer, sizeof(buffer), out);
        //std::cout<<"buffer:"<<buffer<<std::endl;
        n_Size = atoi(buffer);
        //printf("debug, line=%d  , n_Size=%d\n",__LINE__,n_Size);
        memset(&buffer, 0x00, sizeof(buffer));
        pclose(out);
        out = NULL;
    }
    out = popen("getent passwd 0 | wc -l | awk 1 ORS=' '", "r"); //get count of normal user
    fgets(buffer, sizeof(buffer), out);
    if (out == NULL)
    {
        printf("%d  peopen call fail, error\n", __LINE__);
    }
    else
    {
        fgets(buffer, sizeof(buffer), out);
        //std::cout<<"buffer:"<<buffer<<std::endl;
        n_Size += atoi(buffer);
        //printf("debug, line=%d  , n_Size=%d\n",__LINE__,n_Size);
        memset(&buffer, 0x00, sizeof(buffer));
        pclose(out);
        out = NULL;
    }
    //printf("debug: n_Size=%d\n",n_Size);
    std::vector<std::string> rt_Vec(n_Size); //Consructor n_Size Object;
    //  out=popen("fdisk -l | grep 'Disk model' | wc -l | sed 's/[[:blank:]]*//' | awk 1 ORS=' ' ","r");
    // out = popen("chage -l $USER   | awk 1 ORS=' '", "r");
    char t_Command[1000];
    for (int i = 1; i < n_Size; i++)
    {
        //  printf("i=%d, n_Size + 1=%d\n",i,n_Size);
        sprintf(t_Command, "eval getent passwd {$(awk '/^UID_MIN/ {print $2}' /etc/login.defs)..$(awk '/^UID_MAX/ {print $2}' /etc/login.defs)} | cut -d: -f1 | sed -n %dp | awk 1 ORS=' '", i);
        //std::cout<<"debug: t_Command="<<t_Command<<std::endl;
        out = popen(t_Command, "r"); //Get User Name with pipe
        fgets(buffer, sizeof(buffer), out);
        if (out == NULL)
        {
            printf("%d  peopen call fail, error\n", __LINE__);
            continue;
        }
        else
        {
            fgets(buffer, sizeof(buffer), out);
            //   std::cout<<"debug:buffer="<<buffer<<std::endl;
            // usleep(100);
            rt_Vec[i] = buffer;
            memset(&buffer, 0x00, sizeof(buffer));
            memset(&t_Command, 0x00, sizeof(t_Command));
            pclose(out);
            out = NULL;
        }
    }
  //Get whether has root account
  out = popen("grep -i root /etc/passwd | awk 1 ORS=' '", "r");
  fgets(buffer, sizeof(buffer), out);
  if (out == NULL)
  {
    printf("%d  peopen call fail, error\n", __LINE__);
  }
  else
  {
    fgets(buffer, sizeof(buffer), out);
    if (buffer == "\n")
    {
      printf("Current OS has no 'root' account\n");
    }
    else
    {
      rt_Vec[0]= "root";
    }
  }

 for (int i = 0; i < n_Size; i++)
 {
     std::cout<<rt_Vec[i]<<std::endl;
 }
    if ((access("/home/takethat/.config/google-chrome/Default/History1", F_OK)) != -1)
    {
        printf("文件 /home/takethat/.config/google-chrome/Default/History1 存在.\n");
    }
    else
    {
        printf("文件 /home/takethat/.config/google-chrome/Default/History1 不存在.\n");
    }
    if (access("/home/takethat/.config/google-chrome/Default/History1", R_OK) != -1)
    {
        printf("/home/takethat/.config/google-chrome/Default/History有可读权限\n");
    }
    else
    {
        printf("/home/takethat/.config/google-chrome/Default/History 不可读.\n");
    }
    return 0;
}