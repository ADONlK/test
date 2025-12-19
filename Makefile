CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
TARGET = calculator
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

test: $(TARGET)
	@echo "Creating test input file..."
	@echo "5 1 2 + 4 * + 3 -" > input.txt
	@echo "2 3 * 4 +" >> input.txt
	@echo "10 2 /" >> input.txt
	@echo "Running calculator..."
	./$(TARGET)
	@echo -e "\nResults:"
	@cat output.txt

.PHONY: all clean test