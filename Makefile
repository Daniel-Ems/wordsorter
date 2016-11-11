CPPFLAGS+= -Wall -Wextra -Wpedantic -Wextra -Wpedantic -Wwrite-strings 
CPPFLAGS+= -Wstack-usage=1024 -Wfloat-equal -Waggregate-return -Winline

CFLAGS+=-std=c11
CFLAGS+=-g
LDLIBS += -lm



BINARY = ws
OBJECT = ws.o sort.o

$(BINARY):$(OBJECT)
.PHONY: clean debug profile

$(BINARY): 

debug: CLFAGS+=-g
debug: $(BINARY)

profile: CFLAGS+=-pg
profile: LDFLAGS+=-pg
profile: $(BINARY)


clean:
	$(RM) $(BINARY) $(OBJECT)







