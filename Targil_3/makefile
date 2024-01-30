all: encode decode 

	
# Make main programs
# Link the object file with the static library to create the executable encode
encode: encode.o libencriptor.so
	gcc encode.o -o encode -L. -l encriptor -Wl,-rpath="$(PWD)"

decode: decode.o libencriptor.so
	gcc decode.o -o decode -L. -l encriptor -Wl,-rpath="$(PWD)"

# Make dependencis of main programs:
# Compile encode.c into encode.o
encode.o: encode.c libencriptor.so
	gcc -c encode.c 

# Compile decode.c into decode.o
decode.o: decode.c libencriptor.so
	gcc -c decode.c

# Create the shared library libencriptor.so
libencriptor.so: encriptor.o encriptor.h
	gcc -shared encriptor.o -o libencriptor.so

# Compile encriptor.c into encriptor.o
encriptor.o: encriptor.c encriptor.h 
	gcc -c -fpic encriptor.c


.PHONY: all clean

clean: 
	rm -f *.o *.a *.so encode decode
