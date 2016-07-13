GEN_SRC := MutualExclusion.cpp mutualexclusion_constants.cpp mutualexclusion_types.cpp
GEN_OBJ := $(patsubst %.cpp,%.o, $(GEN_SRC))

THRIFT_DIR := /usr/local/include/thrift
BOOST_DIR := /usr/local/include

INC := -I$(THRIFT_DIR) -I$(BOOST_DIR)

.PHONY: all clean

all: coordinator client

%.o: %.cpp
	$(CXX) -std=c++11 -Wall -DHAVE_INTTYPES_H -DHAVE_NETINET_IN_H $(INC) -c $< -o $@

coordinator: coordinator.o $(GEN_OBJ)
	$(CXX) $^ -o $@ -L/usr/local/lib -lthrift -lthriftnb -levent

client: client.o $(GEN_OBJ)
	$(CXX) $^ -o $@ -L/usr/local/lib -lthrift -lpthread

clean:
	$(RM) *.o coordinator client


