#OBJS specifies which files to compile as part of the project
OBJS = prog02.cpp

#CC specifies which compiler we're using
CC = g++

#INCLUDE_PATHS specifies the additional include paths we'll need
# in '/usr/local/include/GL' are the headers: freeglut.h, freeglut_ext.h, freeglut_std.h & glut.h
# in '/opt/X11/include/GL' are the same headers again
# in '/usr/local/include/glsdk' are the glload headers incl. gl_3_2_comp.h (but not getting found)
INCLUDE_PATHS = -I/usr/local/include

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -L/usr/local/lib

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS =  -lGLEW -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = prog02

#This is the target that compiles our executable
all:
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)