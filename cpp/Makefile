CXX = clang++
CXXFLAGS = -std=c++11 -Wall -Werror

.SECONDARY:

build:
	@mkdir build

build/%: %.cc build
	@$(CXX) $(CXXFLAGS) $< -o $@

run-%: build/%
	@./$<
