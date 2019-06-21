CC= g++  
CFLAGS= -g -D __linux__
  
getsystem: getsystem.o
	$(CC) -o getsystem getsystem.o

getsystem.o: client.cpp 
	$(CC) -c $(CFLAGS) -o getsystem.o client.cpp 
clean:
	rm -f getsystem  *.o 
