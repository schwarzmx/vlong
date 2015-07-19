SOURCES=$(wildcard *.cc)
OBJECTS=$(SOURCES:.cc=.o)
DEPS=$(SOURCES:.cc=.d)
BINS=$(SOURCES:.cc=)

CFLAGS+=-MMD
CXXFLAGS+=-MMD -Wall -O3 -std=c++11

all: $(BINS)

.PHONY: clean

clean:
		$(RM) $(OBJECTS) $(DEPS) $(BINS)

-include $(DEPS)