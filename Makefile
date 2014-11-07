OPT = -std=c++11 -Wall
SRC = $(wildcard *.cpp)
OBJS = $(SRC:.cpp=.o)

all: Test

%.o: %.cpp
	g++ $(OPT) -c $< -o $@
	
Test: $(OBJS)
	g++ $(OPT) $^ -o $@
	./$@

clean:
	rm *.o
