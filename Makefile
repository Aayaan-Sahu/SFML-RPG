OBJ=obj
BIN=bin
APP_NAME=Application

clean:
	rm $(OBJ)/*

.PHONY: clean

compile:
	python3 build.py compile

link:
	python3 build.py link

build:
	python3 build.py
	make clean

run: build
	$(BIN)/$(APP_NAME)

RUN:
	$(BIN)/$(APP_NAME)
