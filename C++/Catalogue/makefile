# nom de l'executable produit
EXE = demo

# édition des liens
EDL = g++ -o
EDLFLAGS =

# compilation
COMP = g++ -c
COMPFLAGS = -DMAP -ansi -g -pedantic -Wall -std=c++11

# fichiers
REALISATIONS = $(wildcard *.cpp)
OBJETS = $(REALISATIONS:.cpp=.o)

#####################################################

all : $(EXE)

$(EXE) : $(OBJETS)
	@ echo "creation de l'éxecutable  $@"
	@ $(EDL) $(EDLFLAGS) $(EXE) $^


main.o : main.cpp
	@ echo "compilation pour $@"
	@ $(COMP) $(COMPFLAGS) $<

%.o : %.cpp %.h
	@ echo "compilation pour $@"
	@ $(COMP)  $(COMPFLAGS) $<

.PHONY: clean mrproper

clean :
	@ echo "suppression des fichiers .o"
	@ rm -f *.o

mrproper : clean
	@ echo "suppression de l'éxecutable $(EXE)"
	@ rm -f $(EXE)
