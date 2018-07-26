# Copyright 2018 Justin Hu
#
# This file is part of StackCalc.
#
# StackCalc is free software: you can redistribute it and / or modify it under
# the terms of the GNU General Public License as published by the Free Software
# Foundation, either version 3 of the License, or (at your option) any later
# version.
#
# StackCalc is distributed in the hope that it will be useful, but WITHOUT ANY
# WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
# A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along with
# StackCalc.  If not, see <https:#www.gnu.org/licenses/>.

CC := g++
OPTIONS := -std=c++17 -Wall -O3
LDFLAGS := -lncursesw
OBJS := main.o ui.o numberStack.o
EXENAME := stackcalc
.PHONY: all clean run remake rerun

all: ${OBJS}
	${CC} -o ${EXENAME} ${OPTIONS} ${OBJS} ${LDFLAGS}

run: all
	./${EXENAME}

%.o: %.cpp
	${CC} ${OPTIONS} -c $*.cpp

clean:
	rm -rf *.o ${EXENAME}

remake: clean all

rerun: remake run
