SHELL = /bin/sh
CC = g++
ALLEGRO_FLAGS = $$(pkg-config allegro-5 allegro_main-5 allegro_font-5 allegro_ttf-5 --libs --cflags)

build_and_run: clean run

clean:
	if [ -a ./build/main.o ]; then rm ./build/main.o; fi;

build/main.o:
	${CC} main.cpp -o build/main.o ${ALLEGRO_FLAGS}

run: build/main.o
	./build/main.o
