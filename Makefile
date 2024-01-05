# Define compiler
CXX=g++

# Define flags
CXXFLAGS=-Iinclude -std=c++11 -Wall

# Define the target executable
TARGET=mainW

# Define object files
OBJ=main.o neuron.o utils.o matrix.o layer.o neuralnetwork.o

# Define header files
DEPS=include/neuron.h include/utils/utils.h include/layer.h include/neuron.h include/matrix.h include/neuralnetwork.h

# Define the rule for making the target
$(TARGET): $(OBJ)
	$(CXX) -o $@ $^
	del $(OBJ)

# Define how object files should be compiled from source files
%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

# Define clean rule
clean:
	rm -f $(OBJ) $(TARGET)

# Define rule for rebuilding the project
.PHONY: clean