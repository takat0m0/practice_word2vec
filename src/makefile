TARGET=main

CC=g++
INCLUDE=-I../include/ -I../data_structure/
DEBUG=
OPT= -Wall $(DEBUG) -std=c++11
OBJS= main.o\
 updater.o\
 Huffman.o

$(TARGET).out:$(OBJS)
	$(CC) $(INCLUDE) $(OPT) $(OBJS) -o $(TARGET).out

.cpp.o:
	$(CC) $(INCLUDE) $(OPT) -c $<
