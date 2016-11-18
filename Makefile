CC=g++
CFLAGS=-std=c++11 -Wall -g
INC=-I.
LIB=-lncurses
SRCDIR=src
OBJDIR=obj
TARGET=bin/main
SRCEXT=cpp

SOURCES=$(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS=$(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o))


$(TARGET): $(OBJECTS)
	@echo " Linking... "
	@echo " $(CC) $^ -o $(TARGET) $(INC)"; $(CC) $^ -o $(TARGET) $(LIB)

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(OBJDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning.. "
	@echo " $(RM) -r $(OBJDIR) $(TARGET)"; $(RM) -r $(OBJDIR) $(TARGET)

