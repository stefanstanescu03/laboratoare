CC = gcc
CFLAGS = -Wall -g

SOURCES = ./Sources
DEST = ./Builds/mainBuild

OBJ = $(shell find $(SOURCES) -name *.c)

$(DEST): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

run: $(DEST)
	$(DEST)

clear: $(DEST)
	rm -f $(DEST)