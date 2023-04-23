# Compiler
CC = gcc

# Flags
CFLAGS = -Wall -g

# Sources folder
SOURCES = ./Sources

# Builds folder
BUILDS = ./Builds

# Get build number
BNUMBER = $(shell ls $(BUILDS) | wc -l)

# Create latest build's name
BNAME = build_$(BNUMBER)

# Find where the latest build should be placed
DEST = $(BUILDS)/$(BNAME)

# Get the last build
LATESTBUILD = $(shell ls $(BUILDS) | sort -V | tail -n 1)

# Get every .c file in Sources
OBJ = $(shell find $(SOURCES) -name *.c)

build: $(OBJ) 
	$(CC) -o $(DEST) $^ $(CFLAGS)

run: $(BUILDS)
	$^/$(LATESTBUILD)

delete: $(BUILDS)
	rm -f $^/$(LATESTBUILD)

clean: $(BUILDS)
	rm -f $^/*

