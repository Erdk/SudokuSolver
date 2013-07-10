CC  := gcc
SRCDIR := src
OBJDIR := obj
OBJ := $(addprefix $(OBJDIR)/, sudoku_solver.o)
EXE := sudoku_solver

.PHONY: clean

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	gcc $< -O2 -g -c -o $@

all: $(OBJ)
	gcc $(OBJ) -O2 -g -o $(EXE)

clean:
	rm -rf $(EXE) $(OBJ)
