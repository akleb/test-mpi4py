CC   = mpicc
LINK = mpicc

CMAIN    = hello_world.c
CMAINOBJ = $(CMAIN:.c=.o)

.c.o:
	$(CC) -c $<

main : $(CMAINOBJ)
	$(LINK) -o $@ $^

clean :
	rm *.o
