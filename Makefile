CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

# Add DEBUG variable
DEBUG := -DDEBUG

all: llrec-test stack_test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test: llrec.o llrec-test.o
	$(CXX) $(CXXFLAGS) $(DEBUG) -o llrec-test llrec.o llrec-test.o

llrec-test.o: llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) $(DEBUG) -c llrec-test.cpp

stack_test: stack_test.o
	$(CXX) $(CXXFLAGS) $(DEBUG) -o stack_test stack_test.o

stack_test.o: stack_test.cpp stack.h
	$(CXX) $(CXXFLAGS) $(DEBUG) -c stack_test.cpp

clean:
	rm -f *.o llrec-test stack_test *~

.PHONY: clean_