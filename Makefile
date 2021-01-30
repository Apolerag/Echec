CC=g++
CFLAGS=-I$(HEADDIR) -g -Wall -pedantic -Os
DEPS = $(wildcard *.h)
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)
EXEC=Echec


all: $(EXEC)

clean:
	rm -f *.o 

veryclean: clean
	rm -f $(EXEC)

doc:
	doxygen Doxyfile

cleandoc:
	rm -rf doc/ 

cleanAll: veryclean cleandoc



%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
