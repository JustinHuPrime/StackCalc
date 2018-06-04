CC := g++
OPTIONS := -std=c++17 -Wall -O3
LDFLAGS := -lncursesw -L/home/justin/Personal/Programming/ZootronUtilsCpp/ -lzutil
INCLUDES := -I /home/justin/Personal/Programming/ZootronUtilsCpp/
OBJS := main.o ui.o numberStack.o
EXENAME := stackcalc
.PHONY: all clean run remake rerun

all: ${OBJS}
	${CC} -o ${EXENAME} ${OPTIONS} ${OBJS} ${LDFLAGS}

run: all
	./${EXENAME}

%.o: %.cpp
	${CC} ${OPTIONS} -c $*.cpp ${INCLUDES}

clean:
	rm -rf *.o ${EXENAME}

remake: clean all

rerun: remake run
