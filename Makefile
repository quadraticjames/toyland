SRC_D=src
BUILD_D=build
PARSE=bison
LEX=flex

all: build
	$(PARSE) -d -o $(SRC_D)/parse.tab.c $(SRC_D)/parse.y
	$(LEX) -o $(SRC_D)/lex.yy.c $(SRC_D)/lex.l
	cc $(SRC_D)/*.c -o $(BUILD_D)/lcc
	
build:
	mkdir -p build

clean:
	rm -f build/*
	rm -f src/parse.tab.h src/parse.tab.c src/lex.yy.c
