CXX = clang++
CXXFLAGS = -Wall -Werror

.SECONDARY:

build:
	@mkdir build

build/%: %.cpp build
	@$(CXX) $(CXXFLAGS) $< -o $@

run-%: build/%
	@./$<
