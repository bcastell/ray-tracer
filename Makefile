MODULES = core main samplers shapes

CXX = g++
CXXFLAGS = -std=c++11 -Wall $(addprefix -Isrc/, $(MODULES))

BUILD_DIR = build

SRC = $(foreach module_dir, $(addprefix src/, $(MODULES)), $(wildcard $(module_dir)/*.cpp))
OBJ = $(addprefix $(BUILD_DIR)/, $(notdir $(SRC:.cpp=.o)))
DEP = $(OBJ:.o=.d)

EXE = ray-tracer

.PHONY: all
all: $(BUILD_DIR) $(BUILD_DIR)/$(EXE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

-include $(DEP)

$(BUILD_DIR)/%.o: src/core/%.cpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

$(BUILD_DIR)/%.o: src/main/%.cpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

$(BUILD_DIR)/%.o: src/samplers/%.cpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

$(BUILD_DIR)/%.o: src/shapes/%.cpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)