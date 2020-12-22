BIN = proof store

CFLAGS ?= -Og -ggdb

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) -o $* $^

clean:
	rm -f $(BIN)
.PHONY: clean
