# Copyright (c) 2020, Sayed Mohsen
# All rights reserved.

#....Searching Directories "vpath"
#form of the vpath directive : vpath pattern directories


#will look for All files ending in ‘.c’ in Src Folder
vpath %.c ./Src 

#will look for All files ending in ‘.c’ in Inc Folder
vpath %.h ./Inc



source_path = ./Src
include_path = ./Inc


#GNU Arm Embedded Toolchain

#C Compiler 
CC = arm-none-eabi-gcc


#==============================================================================
#                      Target Properties 
#==============================================================================

#Specify the name of the target CPU.
TARGET_CPU = -mcpu=cortex-m4	

#Specify the name of the target architecture.
TARGET_ARCH = -march=armv7e-m	


#==============================================================================
#                      Target Properties 
#==============================================================================
#Specify the name of the target CPU. 
LINK_TARGET = app.exe

#Specify the name of the Linker File Script .
LINKER_FILE = tm4c123gh6pm.lds

#Specify the name of the Map file.
MAP_FILE = app_map.map


#==============================================================================
#                      Compiler Flags
#-mthumb :Generate code for Thumb state.
#-c Compile and assemble, but do not link.
#-I adds include directory of header files.
#-O0:NoOptimization
#-save-temps:Do not delete intermediate files.
#
#https://gcc.gnu.org/onlinedocs/gcc/ARM-Options.html
#==============================================================================
CFLAGS :=  -mthumb -O0 -save-temps 	${TARGET_CPU} ${TARGET_ARCH}  -c -I $(include_path)

#==============================================================================
#                      Linker Flags
#-nostdlib :Do not use the standard system startup files or libraries when linking.
#-T script Use script as the linker script.
# 
#https://gcc.gnu.org/onlinedocs/gcc/Link-Options.html
#==============================================================================
LDFLAGS :=-nostdlib -T${LINKER_FILE} -Wl,-Map,${MAP_FILE}


#get Source Files Using Wildcard Function
#One use of the wildcard function is to get a list of all the C source files in a directory
#We can change the list of C source files into a list of object files by replacing the ‘.c’ suffix with ‘.o’ in the result

SOURCE =  $(subst $(source_path)/,,$(wildcard $(source_path)/*.c))

#generate Object Files from source files
OBJECTS = $(SOURCE:.c=.o) 

#To use this makefile to delete the executable file and all the object files from the directory.
CLEAN_FILES =  *.i *.map *.o *.s *.exe


#==============================================================================
#                      target Rules 
#==============================================================================

#Rule Syntax
#In general, a rule looks like this:

#targets : prerequisites
#	command

#bulids final excutable binary
all:$(LINK_TARGET)

# $@  and $^  are Automatic Variables	
# $@ --> target 
# $^ --> prerequisite


$(LINK_TARGET):$(OBJECTS)
				$(CC) $(LDFLAGS)  $^ -o $@


#pattern matching to match all object files with associated c files 
%.o : %.c
	$(CC) $(CFLAGS)  $^ -o $@

#delete all the object files and executables so that the directory is ‘clean’. 
clean:
	-rm $(CLEAN_FILES)