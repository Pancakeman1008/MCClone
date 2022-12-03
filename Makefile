srcs := $(shell find src -name *.cc)
objs := $(srcs:src/%.cc=build/%.o)
deps := $(objs:.o=.d)

CXXFLAGS ?= -O2 -Werror -pedantic -Wall -Wextra -Wconversion
CXXFLAGS += -MMD -MP -Iinc -std=c++20

LDFLAGS += -lglfw -lGLEW -lGL

game: $(objs)
	$(CXX) -o $@ $^ $(LDFLAGS)

build/%.o: src/%.cc
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -r game build

-include $(deps)