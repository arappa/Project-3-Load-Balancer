CXX = g++

CXXFLAGS = -std=c++17 -Wall

SRCS = main.cpp loadbalancer.cpp requestqueue.cpp request.cpp server.cpp

OBJS = $(SRCS:.cpp=.o)

EXEC = loadbalancer

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(OBJS) $(EXEC)

