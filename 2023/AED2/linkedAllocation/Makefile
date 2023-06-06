# Diretórios
PROGRAMS := programs
BIN := bin
INCLUDE := include
LIB := lib
OBJ := obj
SRC := src

# Flags de compilação
FLAGS := -Wall -Wextra -pedantic -lm
LIBRARIES := -lgfx -lSDL -lSDL_gfx -lSDL_ttf

# Alvo padrão
all: lib program

# Compilação da biblioteca
lib: \
	$(OBJ)/Node.o \
	$(OBJ)/GraphicInterface.o \
	$(OBJ)/MemoryManager.o \
	$(OBJ)/ListAvaliableBlocks.o \
	$(OBJ)/ListAllocatedBlocks.o \
	
	ar -rcs $(LIB)/libmemorymanager.a $(OBJ)/*.o

# Compilação do programa principal
program: $(BIN)/main

# Compilação dos arquivos de objeto
$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc -c $< -I $(INCLUDE) -I gfx $(FLAGS) -o $@

# Compilação o programa principal
$(BIN)/%: $(PROGRAMS)/%.c
	gcc $< $(OBJ)/*.o -I $(INCLUDE) -L gfx $(LIBRARIES) $(FLAGS) -g -o $@

# Executar o programa
run:
	$(BIN)/main

# Limpar arquivos gerados
clean:
	rm -rf $(BIN)/* $(LIB)/* $(OBJ)/*

# Limpar todos os executáveis
clean_all_exe:
	rm -rf $(BIN)/*

# Debug
debug:
	gdb $(BIN)/main	

# Facilitar o desenvolvimento
dev:
	make clean
	make all
	make run