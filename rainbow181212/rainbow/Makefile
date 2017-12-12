CC = g++ 
OBJ = GFpow.o Gauss.o  Compose.o  ntru_crypto_sha1.o ntru_crypto_msbyte_uint32.o ntru_crypto_hash.o ntru_crypto_sha2.o ntru_crypto_sha256.o rainbow.o 
LINKOBJ = GFpow.o Gauss.o  Compose.o ntru_crypto_sha1.o ntru_crypto_msbyte_uint32.o ntru_crypto_hash.o ntru_crypto_sha2.o ntru_crypto_sha256.o rainbow.o
LIBS = -L. -L/usr/lib
BIN = rainbow
CFLAGS = -c -Wall -I. 
RM = rm -f 

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after


clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CC) -O3 $(LINKOBJ) -o $(BIN) $(LIBS)

GFpow.o: GFpow.cpp
	$(CC) -c GFpow.cpp -o GFpow.o $(CFLAGS)

Compose.o: Compose.cpp 
	$(CC) -c Compose.cpp -o Compose.o $(CFLAGS)

Gauss.o: Gauss.cpp 
	$(CC) -c Gauss.cpp -o Gauss.o $(CFLAGS)

ntru_crypto_hash.o : ntru_crypto_hash.c 
	gcc -c ntru_crypto_hash.c -o ntru_crypto_hash.o $(CFLAGS)

ntru_crypto_sha1.o : ntru_crypto_sha1.c 
	gcc -c ntru_crypto_sha1.c -o ntru_crypto_sha1.o $(CFLAGS)

ntru_crypto_sha2.o : ntru_crypto_sha2.c 
	gcc -c ntru_crypto_sha2.c -o ntru_crypto_sha2.o $(CFLAGS)

ntru_crypto_sha256.o : ntru_crypto_sha256.c 
	gcc -c ntru_crypto_sha256.c -o ntru_crypto_sha256.o $(CFLAGS)

ntru_crypto_msbyte_uint32.o : ntru_crypto_msbyte_uint32.c 
	gcc -c ntru_crypto_msbyte_uint32.c -o ntru_crypto_msbyte_uint32.o $(CFLAGS)

rainbow.o : rainbow.cpp 
	$(CC) -c rainbow.cpp -o rainbow.o $(CFLAGS)
