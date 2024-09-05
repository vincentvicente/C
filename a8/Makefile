all: run

run: Hashtable.o LinkedList.o
	gcc -g Hashtable.c LinkedList.c Main.c -o main

test: test_suite

Hashtable.o: Hashtable.c Hashtable_easy.h
	gcc -c -Wall -g Hashtable.c -o Hashtable.o

LinkedList.o: LinkedList.c LinkedList_easy.h 
	gcc -c -Wall -g LinkedList.c -o LinkedList.o

GTEST_DIR_A = ${HOME}/src/googletest-release-1.8.0/googletest
GOOGLE_TEST_LIB = ${HOME}/lib/gtest/libgtest.a
GOOGLE_TEST_INCLUDE = ${HOME}/src/googletest-release-1.8.0/googletest/include/

GTEST_DOWNLOAD = ${HOME}/src/googletest-release-1.8.0/

USER_DIR = .

CPPFLAGS += -isystem $(GTEST_DIR_A)/include

CXXFLAGS += -g -Wall -Wextra -pthread

GTEST_HEADERS = $(GTEST_DIR_A)/include/gtest/*.h \
                $(GTEST_DIR_A)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR_A)/src/*.cc $(GTEST_DIR_A)/src/*.h $(GTEST_HEADERS)

release-1.8.0.tar.gz : 

${GTEST_DIR_A}/src/gtest-all.cc: release-1.8.0.tar.gz
	mkdir -p ${HOME}/src
	cp release-1.8.0.tar.gz ${HOME}/src/
	tar -xzmf ${HOME}/src/release-1.8.0.tar.gz -C ${HOME}/src/

gtest_main.o : $(GTEST_DIR)/src/gtest_main.cc
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc


$(GOOGLE_TEST_LIB): ${GTEST_DIR_A}/src/gtest-all.cc
	g++ -isystem ${GTEST_DIR_A}/include -I${GTEST_DIR_A} \
		-pthread -c ${GTEST_DIR_A}/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o
	mkdir -p ~/lib/gtest/
	mv libgtest.a ~/lib/gtest/

lib: LinkedList_easy.h LinkedList.c Assert007.c Assert007.h
	gcc -g LinkedList.c Assert007.c

test_hashtable.o : test_hashtable.cc
	g++ -c -Wall -I $(GOOGLE_TEST_INCLUDE) test_hashtable.cc \
		-o test_hashtable.o

test_suite: $(GOOGLE_TEST_LIB) test_hashtable.o Hashtable.o LinkedList.o
	g++ -o test_suite test_hashtable.o Hashtable.o LinkedList.o \
		 -L${HOME}/lib/gtest -lgtest -lpthread

clean: 
	rm -rf *~ main
	rm -rf *~ test_suite
	rm -rf *~ *.o

