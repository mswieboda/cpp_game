SHELL = /bin/sh
CC = g++
CC_FLAGS = -std=c++17 -Wall
ALLEGRO_FLAGS = $$(pkg-config allegro-5 allegro_main-5 allegro_font-5 allegro_ttf-5 allegro_image-5 allegro_primitives-5 --libs --cflags)
OUT_FILE = build/main.o
SOURCE_FILES = src/main.cpp src/Keys.cpp src/Box.cpp src/Scene.cpp src/SceneManager.cpp src/GameScene.cpp src/MainMenu.cpp src/Animation.cpp src/Animations.cpp src/Player.cpp src/ui/Button.cpp src/Map.cpp src/Tile.cpp src/AnimationsObj.cpp src/Ground.cpp

build_and_run: clean run

clean:
	if [ -a ./${OUT_FILE} ]; then rm ./${OUT_FILE}; fi;

build/main.o:
	${CC} ${SOURCE_FILES} -o ${OUT_FILE} ${ALLEGRO_FLAGS} ${CC_FLAGS}

run: build/main.o
	./${OUT_FILE}
