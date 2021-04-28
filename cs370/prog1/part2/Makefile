INC=/usr/local/ssl/include/
LIB=/usr/local/ssl/lib/

all: main.c
	gcc -std=gnu99 -I$(INC) -L$(LIB) -o enc main.c -lcrypto -ldl

clean:
	rm -f enc
	clear
	ls
