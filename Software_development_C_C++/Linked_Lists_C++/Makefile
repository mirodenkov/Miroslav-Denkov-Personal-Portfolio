# Makefile

PRODUCT       := Linked++
TEST_EXE      := Linked++TEST

# All .cpp in product/
ALL_PROD_SRCS := $(wildcard product/*.cpp)
# Library sources only (exclude your app’s main.cpp)
PROD_SRCS     := $(filter-out product/main.cpp,$(ALL_PROD_SRCS))

# All test files under test/
TEST_SRCS     := $(wildcard test/*.cpp)

# Headers (for dependency tracking)
HEADERS       := $(wildcard product/*.h) $(wildcard test/*.h)

# Compiler flags
CPPFLAGS      := -Iproduct -Itest
CXXFLAGS      := -Wall -Werror -Wextra -pedantic -ggdb -O0 $(CPPFLAGS)

# Linker flags for GoogleTest / GoogleMock
LDFLAGS       := -pthread -lgtest -lgmock_main -lgmock

CXX           := g++

.PHONY: all test clean

# Default target: build your real application
all: $(PRODUCT)

$(PRODUCT): $(ALL_PROD_SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Build the test runner (only library code + test/*.cpp)
$(TEST_EXE): $(PROD_SRCS) $(TEST_SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# test always runs clean first, then rebuilds test runner, then executes it
test: clean $(TEST_EXE)
	@echo "==> Running all tests…"
	@./$(TEST_EXE)

clean:
	@rm -f $(PRODUCT) $(TEST_EXE)
