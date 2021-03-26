f1 = "01-preproc.c" 
f2 = "02-data-types.c"
f3 = "03-qualifiers.c" 
f4 = "04-predefDS.c" 

curr = $(f4)

exec:  
	gcc $(curr) -c -o obj.o
	gcc obj.o -o exec.out
	./exec.out
	
debug:
	gcc $(curr) -g -o debug-exec.out
	./debug-exec.out

f3:
	gcc $(f3) 03-qualifiers-test.c -o exec.out
	./exec.out

dbdf3:
	gcc -g  $(f3) 03-qualifiers-test.c -o exec.out
	./exec.out

clean:
	rm ./*.o
	rm ./*.out
