CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

SRC = src/main.cpp src/BitStream.cpp src/BPSKModulator.cpp src/AWGNChannel.cpp src/Statistics.cpp src/Simulation.cpp
OBJ = $(SRC:.cpp=.o)

TARGET = sim

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)