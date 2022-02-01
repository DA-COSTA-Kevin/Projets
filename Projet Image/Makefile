# Copyright Steve Chen 2020 <schen07@etud.u-pem.fr>
# Copyright Kévin Da Costa Moura 2020 <kdacos01@etud.u-pem.fr>
# Project in C : Image compress.
# Date : 22/11/2020. 

# Makefile of Project C

# EXECUTABLE FILE NAME
EXEC = Project

# SOURCE
SRCF = src/
SRC = Quadtree.c Position.c Math.c Graphic.c User.c File.c Main.c

# OBJECTS
OBJ = $(SRC:%.c=bin/%.o)

# COMPILATION 
CC = gcc
CFLAGS = -Wall -ansi
LDFLAGS = -lMLV -lm

# MAKE
all : $(EXEC)

$(EXEC) : $(OBJ)
	@$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
	@echo "Successful executable -> Project"

bin/%.o : $(SRCF)%.c
	@$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS) -I ./inc

# CLEAR EXECUTABLE FILE AND .o
clean :
	@rm -rf $(OBJ) $(EXEC) img/img.qtc img/img.qtn img/pos.txt
	@echo "Clean done."

.PHONY : clean
