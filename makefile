#all: exec/escudo1.exe exec/escudo2.exe exec/escudo3.exe exec/alarma.exe exec/mikill.exe exec/entrada.exe exec/salida.exe exec/tuberia.exe exec/consumidor.exe exec/mimkfifo.exe exec/padre.exe exec/hijo.exe

all: $(patsubst src/%.cpp, exec/%.exe, ${wildcard src/*.cpp}) 

exec/%.exe: obj/%.o 
	@gcc $< -o $@
	@echo ""$@" compiled succesfully!"

obj/%.o: src/%.cpp
	@gcc -Wall -c $< -o $@


#See webgraphy num3
.SECONDARY: $(wildcard obj/*.o) 

#In case case we have a file called clean
.PHONY: clean

clean: cleanobj cleanexec
	@echo "Directories obj/*.o and exec/*.exe cleaned"

cleanobj: 
	@rm -f obj/*.o	

cleanexec: 
	@rm -f exec/*.exe
	
	
#Webgraphy
#1. http://mrbook.org/tutorials/make/
#2. http://www.puxan.com/web/blog/HowTo-Write-Generic-Makefiles
#3. http://stackoverflow.com/questions/15189704/makefile-removes-object-files-for-no-reason <-- drived me crazy!
