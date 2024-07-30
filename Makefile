CC=gcc
CFLAGS=-Wall -Wextra -Werror
INCLUDE = -I/include -I/munit
SRCS = src/bank_account.c tests/test_bank_account.c munit/munit.c
TARGET = test_bank_account_app

all: $(TARGET)

$(TARGET) : $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^ $(INCLUDE)

clean:
	rm -f testBankAccount