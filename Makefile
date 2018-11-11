EXE  = game
SOURCES = main.cpp Politeness.cpp TerminalManager.cpp FileElement.cpp Directory.cpp RootDirectory.cpp Printer.cpp FileElementFactory.cpp TextFile.cpp
OBJS = $(subst .cpp,.o,$(SOURCES))
CC = g++

CPPFLAGS = -O2 -g -Wall -Wextra -Werror

run: $(EXE)
	./$(EXE)

$(EXE): $(OBJS) depend.d
	$(LINK.o) -o $@ $(OBJS)

please: CPPFLAGS += -DPOLITE
please: $(EXE)
	./$(EXE) please

debug: CPPFLAGS += -DDEBUG
debug: please

clean:
	rm -f $(OBJS) $(EXE) depend.d

depend.d:
	$(CC) -MM $(SOURCES) > depend.d

.PHONY: clean

-include depend.d
