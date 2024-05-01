# O simbolo ‘%’ pega o stem (tronco) do nome. Exemplo: helloWorld.o = helloWorld.
# O caracter '@' suprime a impressao em tela dos comandos.
# A variavel automatica '$@' pega o nome do target.
# A variavel automatica '$<' pega o nome do primeiro pre-requisito.
# A variável automatica '$^' lista todos os pre-requisitos do target.


# LD_LIBRARY_PATH=/home/thiago/Projects/Librarys
# C_INCLUDE_PATH=/home/thiago/Projects/Headers/**:/usr/include/**
# CPATH=/home/thiago/Projects/Headers/**:/usr/include/**
# CPLUS_INCLUDE_PATH=/home/thiago/Projects/Headers/**:/usr/include/**
# PATH=/home/thiago/bin:/usr/local/bin:/usr/bin:/bin


#
# Variables to control Makefile operation
#
PROJECT_NAME=ReadingHistory
SOURCE_FILES=$(wildcard ./Sources/*.cpp)
HEADER_FILES=$(wildcard ./Headers/*.h)
OBJECT_FILES=$(subst .cpp,.o,$(subst Sources,Object_Files,$(SOURCE_FILES)))
COMPILER=g++
COMPILER_FLAGS=-c -fPIC
RM=rm -rf
STD=-std=c++20
LIBRARYS=-lcurl
PATH_HEADERS=-I ./Headers/

#
# Compilation and linking
#
all: objFolder $(PROJECT_NAME)

$(PROJECT_NAME): $(OBJECT_FILES)
	@ echo '     Building binary $@ using g++ linker.'
	@ echo '    ' $(COMPILER) $(STD) -g -Wall $(LIBRARYS) $^ -o $@
	@ echo ' '
	@ echo '     Finished building binary: $@.'
	@ echo ' '

./Object_Files/%.o: ./Sources/%.cpp
	@ echo '     Building target $< using g++ compiler.'
	@ echo '    ' $(COMPILER) $(STD) $(COMPILER_FLAGS) $(PATH_HEADERS) $< -o $@
	@ echo ' '

./Object_Files/main.o: ./Sources/main.cpp
	@ echo '     Building target $< using g++ compiler.'
	@ echo '    ' $(COMPILER) $(STD) $(COMPILER_FLAGS) $(PATH_HEADERS) $< -o $@
	@ echo ' '

objFolder:
	@ echo ' '
	@ echo '     Create Object_Files directory.'
	@ echo ' '
	@ mkdir -p Object_Files
	@ echo '     Source files.: ' $(SOURCE_FILES)
	@ echo '     Headers files: ' $(HEADER_FILES)
	@ echo '     Object files.: ' $(OBJECT_FILES)
	@ echo ' '
	@ echo ' '
	@ echo ' '

clean:
	@ echo '     Delete Object_Files directory and $(PROJECT_NAME) file.'
	@ echo ' '
	@ $(RM) ./Object_Files/*.o $(PROJECT_NAME) *~
	@ rmdir Object_Files