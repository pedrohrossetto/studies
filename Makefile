# Syntax-check every C++ file (does not link). Usage: make check
CXX ?= g++
CXXFLAGS ?= -std=c++17 -fsyntax-only -w
SOURCES := $(shell git ls-files '*.cpp')

.PHONY: check
check:
	@fail=0; for f in $(SOURCES); do $(CXX) $(CXXFLAGS) "$$f" 2>/dev/null || { echo "FAIL $$f"; fail=$$((fail+1)); }; done; \
	echo "$$fail of $(words $(SOURCES)) files failed"
