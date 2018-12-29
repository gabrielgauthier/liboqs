ENABLE_KEMS+=$(findstring ntru_hrss, $(KEMS_TO_ENABLE))
MAKE_FLAGS_KEM_NTRU_HRSS=

HEADERS_KEM_NTRU_HRSS=src/kem/ntru-hrss/kem_ntru_hrss.h
HEADERS_KEM+=$(HEADERS_KEM_NTRU_HRSS)

OBJECT_DIRS+=.objs/kem/ntru-hrss
OBJECTS_KEM_NTRU_HRSS=.objs/kem/ntru-hrss/kem_ntru_hrss.o
OBJECTS_KEM+=$(OBJECTS_KEM_NTRU_HRSS)

SRC_PREFIX=src/kem/ntru-hrss/upstream/Reference_Implementation/crypto_kem/ntruhrss701
SRCS_KEM_NTRU_HRSS=$(SRC_PREFIX)/cbd.c $(SRC_PREFIX)/fips202.c $(SRC_PREFIX)/ntrukem.c $(SRC_PREFIX)/owcpa.c $(SRC_PREFIX)/poly.c $(SRC_PREFIX)/verify.c
HEADERS=$(SRC_PREFIX)/api.h $(SRC_PREFIX)/cbd.h $(SRC_PREFIX)/owcpa.h $(SRC_PREFIX)/params.h $(SRC_PREFIX)/poly.h $(SRC_PREFIX)/verify.h
OBJS_KEM_NTRU_HRSS=$(SRCS_KEM_NTRU_HRSS:.c=.o)

TO_CLEAN+= $(OBJS_KEM_NTRU_HRSS)

.objs/kem/ntru-hrss/kem_ntru_hrss.o: headers src/kem/ntru-hrss/kem_ntru_hrss.c
	$(CC) -c src/kem/ntru-hrss/kem_ntru_hrss.c -o .objs/kem/ntru-hrss/kem_ntru_hrss.o $(CFLAGS)

ifneq (,$(findstring ntru_hrss, $(ENABLE_KEMS)))
UPSTREAMS+=kem_ntru_hrss_upstream
endif

src/kem/newsrc/kem/ntru-hrss/upstream/Reference_Implementation/crypto_kem/ntruhrss701/%.o: src/kem/ntru-hrss/upstream/Reference_Implementation/crypto_kem/ntruhrss701/%.c
	$(CC) -c -fPIC -O3 -std=c99 -march=native -o $@ $< -I$(OPENSSL_INCLUDE_DIR)

kem_ntru_hrss_upstream: $(OBJS_KEM_NTRU_HRSS)
	bash scripts/collect_objects.sh kem_ntru_hrss $(OBJS_KEM_NTRU_HRSS)
	bash scripts/symbols_global_rename.sh kem_ntru_hrss src/kem/ntru-hrss/symbols_global_rename.txt
#	bash scripts/symbols_local.sh kem_ntru_hrss src/kem/ntru-hrss/symbols_local.txt
