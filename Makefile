CC = gcc
COMPILER_FLAGS = -std=c99 -fstack-protector-all
LINKER_FLAGS = -lm 
EXEC_NAME = siguel
OBJECTS = main.o argumentos.o arquivos.o leitura_geo.o svg.o leitura_gry.o consultas.o util.o

all: $(EXEC_NAME)

siguel: $(OBJECTS) 
		$(CC) $(OBJECTS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(EXEC_NAME)

clean:
		rm -rf *.o siguel 
		rm -rf saida/*.txt
		rm -rf saida/*.svg
