#!/bin/bash

function target() { # $1 = name
	gcc \
	$1.c \
	-o binaries/$1 \
	-O2 \
	-std=gnu99 \
	-s \
	-iquote ../src \
	`pkg-config --cflags --libs sdl2` \
	-lm
	 #-lopengl32 -lgdi32 -lwinmm

	./binaries/$1
}

if [ "$1" == "1" ]; then
	target "physics_demo"
fi

if [ "$1" == "2" ]; then
	target "physics_friction"
fi

if [ "$1" == "3" ]; then
	target "physics_movement"
fi

if [ "$1" == "4" ]; then
	target "physics_restitution"
fi

if [ "$1" == "5" ]; then
	target "physics_shatter"
fi
