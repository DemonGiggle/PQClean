# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra

# Variables for extra include folders and external static libraries
EXTRA_INCLUDES = -I../common -I../crypto_sign/dilithium5/clean
EXTERNAL_LIBS = -L../crypto_sign/dilithium5/clean -ldilithium5_clean

# Source files and object files
SRC = \
	  dilithium5_workbench.c \
	  ../common/fips202.c \
  	  ../common/randombytes.c

OBJ = $(SRC:.c=.o)

# Target executable
TARGET = workbench

# Build target
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(EXTRA_INCLUDES) $(EXTERNAL_LIBS) -o $(TARGET)

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) $(EXTRA_INCLUDES) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: clean
