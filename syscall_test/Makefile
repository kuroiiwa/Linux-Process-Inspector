# DO NOT TOUCH THIS
CC := $(NDK_PATH)/clang

# NOTE:
#   Use $(CC) instead of compiler name (e.g. gcc, clang).
#   Since your user-space program is simple, $(CC) is able to handle
#   everything. Do not use other executables for compiling/linking.

# ---------- Write the rest of Makefile below ----------

test: test.o
	$(CC) -Wall -lm -o test test.c

test.o: test.c
	$(CC) -Wall -lm -c test.c
