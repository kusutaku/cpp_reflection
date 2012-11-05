TARGET = reflectiontest
SRCS = main.cpp \
testmodel.cpp \
reflection.cpp

OBJS = $(SRCS:%.cpp=%.o)
CXX = /usr/bin/g++
CXXFLAGS = -O2 -g -Wall
INCLUDES =
LDFLAGS =

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(notdir $(OBJS)) -o $@ $(LDFLAGS)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $<

clean:
	rm -f $(OBJS) $(TARGET)
