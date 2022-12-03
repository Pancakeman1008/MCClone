srcs := $(shell find src -name *.cc)
objs := $(srcs:src/%.cc=build/%.o)
deps := $(objs:.o=.d)

CXXFLAGS ?= -Werror -pedantic -Wall -Wextra Wconversion
CXXFLAGS += -MMD -MP -Iinc -std=c++20

LDFLAGS +=

game: $(objs)
	$(CXX) $(LDFLAGS) o $@ $^

build/%.o: src/%.cc
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -r game build

-include $(deps)