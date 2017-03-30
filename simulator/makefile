single_cycle: *.o
	gcc *.o -o single_cycle 
*.o: *.c
	gcc -c *.c
clean:
	rm -f *.o
test:
	cp ../hidden_testcase/bubble_sort/*.bin ../../simulator