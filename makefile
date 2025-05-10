# Programme à créer
PROG = CYsinge

# Sources
SRC = main.c animal.c interface.c gestion_fichier.c variantes.c

# Règle par défaut : compile et exécute
all: $(PROG)
	./$(PROG)

# Compilation du programme
$(PROG): $(SRC) animal.h interface.h gestion_fichier.h variantes.h couleurs.h
	gcc -Wall -o $(PROG) $(SRC)

# Nettoyage
clean:
	rm -f $(PROG)
