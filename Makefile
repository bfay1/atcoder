CXX=         g++
CXXFLAGS=    -x c++ -g -O2 -std=c++20 \
	     -fsanitize=address -fsanitize=undefined \
	     -D_GLIBCXX_DEBUG -D_GLIBCXX_ASSERTIONS

default: task

task: task.cpp

PHONY += clean
clean:
	rm -rf task *.o a.out
	
PHONY += run
run:
	cat input.txt | ./task
	
.PHONY: $(PHONY)
