CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

TARGET  = library_system
SRCS    = main.cpp Item.cpp Book.cpp Magazine.cpp DVD.cpp \
          Person.cpp Member.cpp Admin.cpp \
          BorrowRecord.cpp Library.cpp FileManager.cpp
OBJS    = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: all
	./$(TARGET)

.PHONY: all clean run
