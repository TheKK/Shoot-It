 #
 # Author: KK <thumbd03803@gmail.com>
 #
 # Makefile
 #

CXX = clang++
CXXFLAG = -Wall -std=c++11 -g

SRC_PATH = $(PWD)/src

# Include flags
INCLUDE = -I $(PWD)/include
INCLUDE += $(shell pkg-config --cflags sdl2)
INCLUDE += $(shell pkg-config --cflags SDL2_image)
INCLUDE += $(shell pkg-config --cflags SDL2_ttf)

# Libs flags
LIB += $(shell pkg-config --libs sdl2)
LIB += $(shell pkg-config --libs SDL2_image)
LIB += $(shell pkg-config --libs SDL2_ttf)

# Object files
OBJ_PATH = $(PWD)/obj
OBJ = main.o \
      window.o \
      timer.o \
      titleScreen.o

OUT_EXE= shoot

all: $(OUT_EXE)
	@echo "===========[[Everything done!!]]============"

$(OUT_EXE): $(addprefix $(OBJ_PATH)/, $(OBJ))
	@echo "    LD    " $(notdir $@)
	@$(CXX) $(addprefix $(OBJ_PATH)/, $(OBJ)) $(CXXFLAG) $(LIB) -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp
	@echo "    CC    " $(notdir $@)
	@$(CXX) -c $< $(CXXFLAG) $(INCLUDE) -o $@

.PHONY: clean
clean:
	@rm -frv $(OBJ_PATH)/*.o $(OUT_EXE)
	@echo "===========[[Everything removed!!]]============"
