#######################################################################################################
#                                                                                                     #
#     Author: Ali Umar                                                                                #
#     Date: July 8, 2023                                                                              #
#     Some build scripts & utilities for this Mushroom Fighter game.							      #
#     Please note I am a windows user and don't intend on switching to linux fully.                   #
#     lol. Default shell will be cmd.exe. I will be primarily using Raylib for                        #
#     graphics. Also I don't care about incremental builds. I am gonna compile every src file         #
#     at the same time every time :)                                                                  #
#                                                                                                     #
#######################################################################################################

.PHONY: build

SHELL       :=  cmd

BUILD_DIR   :=  build
INC_DIR     :=  include
SRC_DIR     :=  src
LIB_DIR     :=  lib

INC			:= -Iinclude -Iinclude\raylib
LIB         :=  -lraylib -lopengl32 -lgdi32 -lwinmm

COMPILER    :=  gcc 

SRC_FILES   :=  src\main.c

run : build
	build\main

build : 
	@IF NOT EXIST $(BUILD_DIR) ( MD build ) 
	@gcc $(SRC_FILES)  -Llib $(LIB) $(INC) -o $(BUILD_DIR)\main.exe 

setup : 
	@IF NOT EXIST $(BUILD_DIR) ( MD build ) 
	@IF NOT EXIST $(INC_DIR) ( MD include include\raylib ) 
	@IF NOT EXIST $(LIB_DIR) ( MD lib ) 

clean :
	@IF NOT EXIST $(BUILD_DIR) ( ECHO Nothing to clean. ) 
	@IF EXIST $(BUILD_DIR) ( RMDIR /s /q $(BUILD_DIR) & ECHO Successfully deleted build directory. ) 
