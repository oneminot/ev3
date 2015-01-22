EXTRADIR=../extra

IDIR =../incl
CC=arm-none-linux-gnueabi-gcc
CFLAGS=-I$(IDIR) -I$(EXTRADIR)

ODIR=../objs
LDIR =../lib
LIBS=-lpthread -lm

_DEPS = lms2012.h d_lcd.h MyLib.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = d_lcd.o MyLib.o program.o  
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

EDIR=../exe

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -g -Wall -c -o $@ $< $(CFLAGS) $(LIBS)

program: $(OBJ)
	$(CC) -g -Wall -o $(EDIR)/$@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(EDIR)/*.o *~ core $(INCDIR)/*~ 