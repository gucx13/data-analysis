#
# setup control
#
TOP     := $(shell pwd)/
OBJ     := $(TOP)obj/
BIN     := $(TOP)bin/
SRC     := $(TOP)src/
INCLUDE  := $(TOP)include/

CPP     = g++
CPPFLAGS = -O -Wall -fPIC -I$(INCLUDE)

############## Make Executables ####################################
all:	VolCub

VolCub	: $(patsubst $(SRC)%.cc,$(OBJ)%.o,$(wildcard $(SRC)*.cc))
	$(CPP) $^ $(CPPLIBS) -o $(BIN)$(notdir $@)
	@echo

######################################################
$(OBJ)%.o : 	$(SRC)%.cc
	$(CPP)  $(CPPFLAGS) -c $(SRC)$(notdir $<) -o $(OBJ)$(notdir $@)
	@echo	

.PHONY:clean
clean:
	rm -f $(OBJ)*.o 
	rm -f $(BIN)*
