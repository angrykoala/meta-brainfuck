# Basic Makefile
# by @angrykoala

CXX = g++
CPPFLAGS = -Wall -O1 -std=c++11 -g

ASTYLE_FLAGS = --style=java --break-closing-brackets --align-pointer=name --delete-empty-lines --indent-col1-comments --unpad-paren -n -Q

EXE = meta_brainfuck

BIN_DIR = bin
INCLUDE_DIR = include
SRC_DIR = src

SRC = $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/*/*.cpp)
INC = $(wildcard $(INCLUDE_DIR)/*.hpp $(INCLUDE_DIR)/*/*.hpp)


main: $(BIN_DIR)/ $(BIN_DIR)/$(EXE)


.PHONY: clean
clean:
	rm -rf $(BIN_DIR)

.PHONY: astyle
astyle:
	astyle $(ASTYLE_FLAGS) $(SRC) $(INC)

#print makefile variable (for makefile debug purposes)
.PHONY: print-%
print-%  : ; @echo $* = $($*)

$(BIN_DIR)/$(EXE): $(SRC) $(INC)
	$(CXX) -o $@ $(SRC) $(CPPFLAGS) -I $(INCLUDE_DIR)

$(BIN_DIR)/:
	mkdir $(BIN_DIR)



# $(ODIR)/:
# 	mkdir $(ODIR)
#
#
# .PHONY: main
# main: $(BDIR)/ $(ODIR)/ bin/DCmC
# #compile tests binaries
# .PHONY: test
# test: $(BDIR)/ $(ODIR)/ $(TEST_H) bin/main_test
# #astyle for all code (.cpp and .h)

# #clean obj and bin directories as well as *~ files
