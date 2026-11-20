CC = clang
CFLAGS = -I./lib
CFLAGS += -std=c99 -O2 -Wall -g -Wextra -DCGLM_USE_ANONYMOUS_STRUCT=1
LDFLAGS = -L./lib
LDFLAGS += -lglfw3 -lopengl32 -lgdi32 -luser32 -lshell32 -lkernel32
SRC = $(wildcard src/*.c) $(wildcard src/*/*.c)

all:
	@echo "Building With: $(CC)"
	@echo "CFLAGS: $(CFLAGS)"
	@echo "LDFLAGS: $(LDFLAGS)"
	@echo "Source Files: $(SRC)"
	@$(CC) -o OpenSource.exe $(SRC) $(CFLAGS) $(LDFLAGS)