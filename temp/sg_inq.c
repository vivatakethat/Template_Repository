#include<error.h>
#include<error.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
#include<sys/ioctl.h>
#define BUFSIZE (0xc000 + 0x80) 
char buff[BUFSIZE]; 
int main(int argc, char *argv[]) 
{ 
	   int sg_fd; 
	      int ret; 
	         int len; 
		    if (argc != 2) { 
			         fprintf(stderr, "Usage: %s \n", argv[0]); 
				      exit(1); 
				         } 
		       sg_fd = sg_cmds_open_device(argv[1], O_RDONLY, 1); 
		          if (sg_fd < 0) { 
				        fprintf(stderr, "sg_inq: error opening file: %s : %s\n", argv[1], strerror(error)); 
					       exit(1); 
					           } 
			      memset(buff, 0, sizeof(buff)); 
			          ret = sg_ll_inquiry(sg_fd, 0, 1, 0x80, buff, 252, 1, 1); 
				      if (ret == 0) { 
					             char obuff[BUFSIZE]; 
						            len = (buff[2] << 8) + buff[3] + 4; 
							           memset(obuff, 0, sizeof(obuff)); 
								          len -= 4; 
									         memcpy(obuff, buff+4, len); 
										        printf("Unit serial number: %s\n", obuff); 
											    } 
				          sg_cmds_close_device(sg_fd); 
					       return 0; 
}
