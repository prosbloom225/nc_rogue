CC=g++
CFLAGS=-std=c++11 -Wall -g  -Wno-unused-variable
INC=-I./src
LIB=-lncurses -lpanel -lmenu
SRCDIR=src
OBJDIR=obj
TARGET=bin/main
SRCEXT=cpp
RM=rm

SOURCES=$(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS=$(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
DIRS=$(shell find $(SRCDIR) -type d)
DIR=$(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(DIRS))

all: dir $(TARGET)


$(TARGET): $(OBJECTS)
	@echo " Linking.. "
	@echo " $(CC) $^ -o $(TARGET) $(INC)"; $(CC) $^ -o $(TARGET) $(LIB)

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(OBJDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning.. "
	@echo " $(RM) -r $(OBJDIR) $(TARGET)"; $(RM) -r $(OBJDIR) $(TARGET)

test:
	@echo "Testing.. "
	@echo $(OBJECTS)

dir: 
	@echo "Preparing filestructure.. "
	@echo "mkdir -p $(DIR)"; mkdir -p $(DIR)
