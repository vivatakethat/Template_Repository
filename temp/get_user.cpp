#include <iostream>  
#include <pwd.h>  
#include <sys/types.h>  
#include <stddef.h>  
#include <string>  
#include <list>  
using namespace std;  
  
void GetUser(list<string>& lsUser);  
  
int main()  
{  
    list<string> lsUser;  
    GetUser(lsUser);  
  
    cout << "all user name in current computer:" << endl;  
  
    list<string>::iterator it;  
    for (it = lsUser.begin(); it != lsUser.end(); it++)  
    {  
        cout << it->c_str()<< endl;  
    }  
  
    return 0;  
}  
  
void GetUser(list<string>& lsUser)  
{  
    struct passwd* pstPwd = NULL;  
    setpwent();  
  
    while ( (pstPwd = getpwent()) != NULL )  
    {  
        lsUser.push_front(pstPwd->pw_name);  
    }  
  
    endpwent();  
}  
