CC  := g++
SRCDIR := src
OBJDIR := obj
OBJ := $(addprefix $(OBJDIR)/, sudoku_solver.o)
EXE := sudoku_solver

.PHONY: clean

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $< -O2 -g -c -o $@

all: $(OBJ)
	$(CC) $(OBJ) -O2 -g -o $(EXE)

clean:
	rm -rf $(EXE) $(OBJ)
