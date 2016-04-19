.PHONY:all

all:main

VPATH=./sort-and-optimization


objs = $(shell ls ./sort-and-optimization | grep .cpp|xargs)

main:$(objs)
	g++  $^ -o $@
%.o:%.cpp
	g++ -c $< -o $@	
