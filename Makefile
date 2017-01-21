# définition des cibles particulières
.PHONY: clean
  
# désactivation des règles implicites
.SUFFIXES:

# Repertoire des fichiers sources
#srcdir = /src       
# Repertoire des include
#includedir = ./header   
# Repertoire des librairies
#libdir = ./lib      
# l'executable
EXEC = main.a
# Commande pour effacer un fichier
RM = rm 
# compilateur C++
CXX = g++
#
# paramétres à passer au compilateur C++
CXXFLAGS = -pedantic -Wall -Wextra 
#
# paramétres à passer au compilateur pour l'édition des liens
#LDFLAGS = 

# all
all: main.o Zfraction.o  
		$(CXX) main.o Zfraction.o -o $(EXEC) $(CXXFLAGS)
#
main.o: main.cpp Zfraction.h
		$(CXX) main.cpp -o main.o -c $(CXXFLAGS)
#
Zfraction.o: Zfraction.cpp Zfraction.h
		$(CXX) Zfraction.cpp -o Zfraction.o -c $(CXXFLAGS)
 
# suppression des fichiers temporaires
clean:
			$(RM) -rf *.o
#          
# suppression de tous les fichiers, sauf les sources,
# en vue d'une reconstruction complète
mrproper: clean
	$(RM) -rf $(EXEC)    
#          
#
