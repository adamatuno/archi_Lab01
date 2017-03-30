comp = fc
case1 = error3
case2 = seq
single_cycle: *.o
	gcc *.o -o single_cycle 
*.o: *.c
	gcc -c *.c
.PHONY: clean
clean:
	rm -f *.o
.PHONY: decode
decode:
	cp ../hidden_testcase/$(case1)/*.bin ../decoder
	../decoder/decoder.exe
.PHONY: test1
test1:
	cp ../hidden_testcase/$(case1)/*.bin ../simulator
	./single_cycle
	$(comp) snapshot.rpt ../hidden_testcase/$(case1)/snapshot.rpt
	$(comp) error_dump.rpt ../hidden_testcase/$(case1)/error_dump.rpt
	rm -f *.bin *.rpt
.PHONY: test2
test2:
	cp ../hidden_testcase/$(case1)/*.bin ../simulator
	./single_cycle
	$(comp) snapshot.rpt ../hidden_testcase/$(case1)/snapshot.rpt
	$(comp) error_dump.rpt ../hidden_testcase/$(case1)/error_dump.rpt
	rm -f *.bin *.rpt
	cp ../hidden_testcase/$(case2)/*.bin ../simulator
	./single_cycle
	$(comp) snapshot.rpt ../hidden_testcase/$(case2)/snapshot.rpt
	$(comp) error_dump.rpt ../hidden_testcase/$(case2)/error_dump.rpt
	rm -f *.bin *.rpt
