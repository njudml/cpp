INC_DIR:= ./
SRCS:=$(wildcard ./*.cc)
OBJS:= $(patsubst %.cc, %.o, $(SRCS))
LIBS:= -lpthread

CXX:=g++

CXXFLAGS:= -w -g -std=c++11 $(addprefix -I, $(INC_DIR)) $(LIBS)

EXE:=./a.out

$(EXE):$(SRCS)
		$(CXX) $^ -o $@ $(CXXFLAGS)

clean:
		rm -rf $(EXE)

