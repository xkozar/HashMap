CC=gcc
CXX=g++
CFLAGS=-std=c99 -pedantic -Wall -Wextra
CXXFLAGS=-std=c++11 -pedantic -Wall
LIB_FILES=htab_bucket_count.o htab_clear.o htab_find.o htab_foreach.o htab_free.o htab_hash_function.o htab_init.o htab_lookup_add.o htab_move.o htab_remove.o htab_size.o

all: wordcount wordcount-dynamic tail tail2


###############		BINARIES	##############
wordcount: wordcount.o io.o htab.a
	$(CC) $(CFLAGS) -o wordcount -static io.o wordcount.o htab.a

wordcount-dynamic: wordcount.o io.o htab.so
	$(CC) $(CFLAGS) -o wordcount-dynamic wordcount.o io.o htab.so

tail: tail.o
	$(CC) $(CFLAGS) tail.o -o tail

tail2: tail2.o
	g++ $(CXXFLAGS) tail2.o -o tail2
###########	LIBRARIES	############
#Static library
htab.a: $(LIB_FILES)
	ar crs htab.a $(LIB_FILES)
#Dynamic library
htab.so: $(LIB_FILES)
	$(CC) $(CFLAGS) -shared -o htab.so $(LIB_FILES)
############	.o 		###############
wordcount.o: wordcount.c
	$(CC) $(CFLAGS) -c wordcount.c

io.o: io.c io.h
	$(CC) $(CFLAGS) -c io.c

tail.o: tail.c
	$(CC) $(CFLAGS) -c tail.c

tail2.o: tail2.cc
	$(CXX) $(CXXFLAGS) -c tail2.cc

###########		LIB_FILES	#############
htab_bucket_count.o: htab_bucket_count.c
	$(CC) $(CFLAGS) -c -fPIC htab_bucket_count.c

htab_clear.o: htab_clear.c
	$(CC) $(CFLAGS) -c -fPIC htab_clear.c

htab_find.o: htab_find.c
	$(CC) $(CFLAGS) -c -fPIC htab_find.c

htab_foreach.o: htab_foreach.c
	$(CC) $(CFLAGS) -c -fPIC htab_foreach.c

htab_free.o: htab_free.c
	$(CC) $(CFLAGS) -c -fPIC htab_free.c

htab_hash_function.o: htab_hash_function.c
	$(CC) $(CFLAGS) -c -fPIC htab_hash_function.c

htab_init.o: htab_init.c
	$(CC) $(CFLAGS) -c -fPIC htab_init.c

htab_lookup_add.o: htab_lookup_add.c
	$(CC) $(CFLAGS) -c -fPIC htab_lookup_add.c

htab_move.o: htab_move.c
	$(CC) $(CFLAGS) -c -fPIC htab_move.c

htab_remove.o: htab_remove.c
	$(CC) $(CFLAGS) -c -fPIC htab_remove.c

htab_size.o: htab_size.c
	$(CC) $(CFLAGS) -c -fPIC htab_size.c

zip:
	zip xkozar02.zip *.c *.h *.cc Makefile
clean:
	rm -f *.o

clean-all: clean
	rm -f xkozar02.zip
	rm -f wordcount
	rm -f wordcount-dynamic
	rm -f tail
	rm -f tail2