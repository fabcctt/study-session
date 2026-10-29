# Common rules for Cycle 1. Each project lists its own modules.
.DEFAULT_GOAL := all
CC := gcc
CXX := g++
AR := ar
CPPFLAGS += -D_POSIX_C_SOURCE=200809L -D_DEFAULT_SOURCE
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -g -O0 -fno-omit-frame-pointer
CXXFLAGS ?= -std=c++17 -Wall -Wextra -Wpedantic -g -O0 -fno-omit-frame-pointer
CFLAGS += -pthread
CXXFLAGS += -pthread
LDLIBS += -pthread

ifneq ($(wildcard main.cpp),)
EXT := cpp
COMPILER = $(CXX)
COMPILE_FLAGS = $(CXXFLAGS)
else
EXT := c
COMPILER = $(CC)
COMPILE_FLAGS = $(CFLAGS)
endif

MODULE_SOURCES ?= $(TOPIC).$(EXT)
MODULE_OBJECTS := $(addprefix build/,$(MODULE_SOURCES:.$(EXT)=.o))
TEST_SOURCE := $(wildcard tests.$(EXT))
EXAMPLE_INPUT := $(or $(wildcard example.in),/dev/null)
PRE_EXT := $(if $(filter cpp,$(EXT)),ii,i)
BUILD_RULES := Makefile ../topic.mk

.PHONY: all run smoke test clean preprocess assembly symbols disassemble elf debug sanitize
all: build/demo $(if $(TEST_SOURCE),build/tests)

build:
	mkdir -p build

build/%.o: %.$(EXT) $(BUILD_RULES) | build
	$(COMPILER) $(CPPFLAGS) $(COMPILE_FLAGS) -MMD -MP -c $< -o $@

# Assertions must remain active even when the caller supplies -DNDEBUG.
build/tests.o: tests.$(EXT) $(BUILD_RULES) | build
	$(COMPILER) $(CPPFLAGS) $(COMPILE_FLAGS) -UNDEBUG -MMD -MP -c $< -o $@

build/demo: build/main.o $(MODULE_OBJECTS)
	$(COMPILER) $(LDFLAGS) $^ $(LDLIBS) -o $@

ifneq ($(TEST_SOURCE),)
build/tests: build/tests.o $(MODULE_OBJECTS)
	$(COMPILER) $(LDFLAGS) $^ $(LDLIBS) -o $@
test: build/tests
	./build/tests
sanitize: | build
	$(COMPILER) $(CPPFLAGS) $(COMPILE_FLAGS) -UNDEBUG -fsanitize=address,undefined $(TEST_SOURCE) $(MODULE_SOURCES) $(EXTRA_SOURCES) $(LDLIBS) -o build/sanitized_tests
	ASAN_OPTIONS=detect_leaks=1:halt_on_error=1 UBSAN_OPTIONS=halt_on_error=1 ./build/sanitized_tests
else
test:
	@echo "No test suite in this project. Use 'make smoke' to run the example."
	@exit 2
sanitize: | build
	$(COMPILER) $(CPPFLAGS) $(COMPILE_FLAGS) -fsanitize=address,undefined main.$(EXT) $(MODULE_SOURCES) $(EXTRA_SOURCES) $(LDLIBS) -o build/sanitized_demo
	ASAN_OPTIONS=detect_leaks=1:halt_on_error=1 UBSAN_OPTIONS=halt_on_error=1 ./build/sanitized_demo < $(EXAMPLE_INPUT)
endif

run: build/demo
	./build/demo
smoke: build/demo
	./build/demo < $(EXAMPLE_INPUT)
preprocess: | build
	$(COMPILER) $(CPPFLAGS) $(COMPILE_FLAGS) -E main.$(EXT) -o build/main.$(PRE_EXT)
	set -e; $(foreach source,$(MODULE_SOURCES),$(COMPILER) $(CPPFLAGS) $(COMPILE_FLAGS) -E $(source) -o build/$(basename $(source)).$(PRE_EXT);)
assembly: | build
	set -e; $(foreach source,$(MODULE_SOURCES),$(COMPILER) $(CPPFLAGS) $(COMPILE_FLAGS) -S $(source) -o build/$(basename $(source)).s;)
symbols: all
	nm -C build/main.o $(MODULE_OBJECTS) $(EXTRA_OBJECTS)
disassemble: all
	objdump -d -S -C build/demo
elf: all
	readelf -h -l -S build/demo
debug: build/demo
	gdb -q build/demo
clean:
	rm -rf -- build

-include $(wildcard build/*.d)
