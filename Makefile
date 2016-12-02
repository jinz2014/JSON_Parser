SRCS	= test.c sanity.c twine.c ptrvec.c json.c 
#xml.c ksh.c
CFLAGS  = -std=c99
OBJS	= $(SRCS:.c=.o)

test:	$(OBJS)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(OBJS) $(LIBS)
clean:
	rm -f $(ME)
	rm -f $(OBJS)
	rm -f $(DOCS)
tags:
	etags $(SRCS)

json.o:		json.c sanity.h twine.h ptrvec.h json.h
test.o:		test.c sanity.h json.h 
ptrvec.o:	ptrvec.c sanity.h ptrvec.h
sanity.o:	sanity.c sanity.h
twine.o:	twine.c sanity.h twine.h

.SUFFIXES:	.c .h .o 
