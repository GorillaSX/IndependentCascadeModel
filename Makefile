CC = g++
RM = rm -rf
CFLAGS = -c -Wall -I -D_DEBUG
diffuse: main.o community.o node.o neighbor.o
	$(CC) $^ -o $@
main.o: main.cpp
	$(CC) $(CFLAGS) $^
community.o: community.cpp
	$(CC) $(CFLAGS) $^
node.o: node.cpp
	$(CC) $(CFLAGS) $^
neighbor.o: neighbor.cpp
	$(CC) $(CFLAGS) $^
clean:
	$(RM) diffuse *.o *.gch
