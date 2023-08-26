CXX=g++
LD=g++
FLAGS=-std=c++11 -Wextra -Wall -ansi
DIR_SRC=src
DIR_INC=inc
DIR_LIB=lib
DIR_BIN=bin
DIR_OBJ=obj
RUNPATH=./lib/SFML-2.1/lib
SRC=$(foreach dir,$(DIR_SRC),$(wildcard $(dir)/*.cpp))
OBJ=$(foreach obj,$(SRC), $(addprefix $(DIR_OBJ)/, $(notdir $(obj:.cpp=.o))))
EXE=Application

-include $(OBJ:.o=.d)

ifdef DEBUG
DEBUGD=-d
DEBUGG=-g
endif

INC=-I$(DIR_INC)

INC+=-I$(DIR_LIB)/SFML-2.1/include
LIB=-L$(DIR_LIB)/SFML-2.1/lib -lsfml-graphics$(DEBUGD) -lsfml-window$(DEBUGD) -lsfml-system$(DEBUGD) -lsfml-audio$(DEBUGD) -lsfml-network$(DEBUGD)

default_target: all

all: $(DIR_BIN)/$(EXE)

$(DIR_BIN)/$(EXE): $(OBJ)
	$(LD) -o $@ $^ $(LIB) -Wl,-rpath=$(RUNPATH)
	
$(DIR_OBJ)/%.o: $(DIR_SRC)/%.cpp
	$(CXX) $(FLAGS) -c $(INC) $< $(DEBUGG) -o $@

run:
	$(DIR_BIN)/$(EXE)

clean:
	@rm -rf $(DIR_BIN)/$(EXE) $(DIR_OBJ)/*.o $(DIR_OBJ)/*.d
