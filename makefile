# -*- mode:make -*-

DIRSRC	:= src/
DIROBJ	:= obj/
DIREXE	:= exe/

CXX 	:= gcc
CXXFLAGS:= -Wall

SRC	:= $(wildcard $(DIRSRC)*.c)
OBJ	:= $(patsubst $(DIRSRC)%.c, $(DIROBJ)%.o, $(SRC))
EXE	:= $(patsubst $(DIROBJ)%.o, $(DIREXE)%, $(OBJ))

all: $(EXE)

# Linking
$(DIREXE)%: $(DIROBJ)%.o
	@$(CXX) $< -o $@
	@echo $@ compiled and linked

# Compilation
$(DIROBJ)%.o: $(DIRSRC)%.c
	@$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

.SECONDARY: $(wildcard obj/*.o)

clean:
	@$(RM) $(DIROBJ)* $(DIREXE)*
	@echo "Directories "$(DIROBJ)" and "$(DIREXE)" cleaned"

#Webgraphy
#1. http://mrbook.org/tutorials/make/
#2. http://www.puxan.com/web/blog/HowTo-Write-Generic-Makefiles
#3. http://stackoverflow.com/questions/15189704/makefile-removes-object-files-for-no-reason <-- drived me crazy!
