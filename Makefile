TARGET = reflectiontest
SRCS = main.cpp \
testmodel.cpp \
reflection.cpp

OBJS = $(SRCS:%.cpp=%.o)
CXX = /usr/bin/g++
CXXFLAGS = -O2 -g -Wall
INCLUDES = -I. \
-I/home/asoatstore/tpp/boost/1.35_x64/include/boost-1_35
LDFLAGS = -ldl -lbfd -L/home/asoatstore/tpp/boost/1.35_x64/lib -L/usr/lib64

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(notdir $(OBJS)) -o $@ $(LDFLAGS)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $<

clean:
	rm -f $(OBJS) $(TARGET)
