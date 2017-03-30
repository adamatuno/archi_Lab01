comp = fc
single_cycle: *.o
	gcc *.o -o single_cycle 
*.o: *.c
	gcc -c *.c
.PHONY: clean
clean:
	rm -f *.o
.PHONY: test
test:
	cp ../hidden_testcase/multiply/*.bin ../simulator
	./single_cycle
	$(comp) snapshot.rpt ../hidden_testcase/multiply/snapshot.rpt
	$(comp) error_dump.rpt ../hidden_testcase/multiply/error_dump.rpt
	rm -f *.bin *.rpt
