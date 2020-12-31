BIN = solution

CFLAGS ?= -Og -ggdb
CFLAGS := -Wall -Wextra -Wpedantic $(CFLAGS)

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) -o $* $^

clean:
	rm -f $(BIN)
.PHONY: clean
