#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/hdreg.h>

int 
main(int argc, 
		     char *argv[])
{
	    static struct hd_driveid hd;
	        int fd;

		    if (geteuid() >  0) {
			            printf("ERROR: Must be root to use\n");
				            exit(1);
					        }

		        if ((fd = open(argv[1], O_RDONLY|O_NONBLOCK)) < 0) {
				        printf("ERROR: Cannot open device %s\n", argv[1]);
					        exit(1);
						    }

			    if (!ioctl(fd, HDIO_GET_IDENTITY, &hd)) {
				            printf("Hard Disk Model: %.40s\n", hd.model);
					            printf("  Serial Number: %.20s\n", hd.serial_no);
						        } else if (errno == -ENOMSG) {
								        printf("No hard disk identification information available\n");
									    } else {
										            perror("ERROR: HDIO_GET_IDENTITY");
											            exit(1);
												        }
			            exit(0);
}
