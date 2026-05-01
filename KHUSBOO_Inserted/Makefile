var = $(patsubst %.c,%.o,$(wildcard *.c))

inverted.exe: $(var)
	gcc -o $@ $^

clean:
	rm -f *.o *.exe