CXX = clang++
DEBUG = -g
RELEASE = -O2
CXXFLAGS = -std=c++14 -Wall -Wpedantic -I../include
LINK = $(CXX)

CXXFLAGS += $(shell fltk-config --use-gl --use-images --cxxflags)
LDFLAGS  += $(shell fltk-config --use-gl --use-images --ldflags)
LDSTATIC = $(shell fltk-config --use-gl --use-images --ldstaticflags)

SOURCES = Graph.cpp GUI.cpp Window.cpp
OBJECTS := $(SOURCES:.cpp=.o)
STATIC_LIB = Graph_lib.a

.SUFFIXES: .o .cpp

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEBUG) -c $<

$(STATIC_LIB): $(OBJECTS)
	ar -rv $(STATIC_LIB) $(OBJECTS)
	$(RM) $(OBJECTS)

.PHONY: clean
clean:
	$(RM) $(STATIC_LIB)
	$(RM) $(OBJECTS)
