.PHONY:all

all:main

VPATH=./sort-and-optimization


objs = $(shell ls ./sort-and-optimization | grep .cpp|xargs)

main:$(objs)
	g++  $^ -o $@

.PHONY:clean

clean:
	rm main
