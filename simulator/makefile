comp = diff
case1 = 15
case2 = 2
case3 = 4
case4 = 15
case5 = _1
case6 = _3
single_cycle: *.o
	gcc *.o -o single_cycle -O3
*.o: *.c
	gcc -c *.c
.PHONY: clean
clean:
	rm -f *.o *.bin *.rpt
.PHONY: decode
decode:
	cp ../hidden_testcase/$(case1)/*.bin ../decoder
	../decoder/./decoder
.PHONY: testcase
testcase: *.o
	gcc *.o -o single_cycle -O3
	cp ../testcase/*.bin ../simulator
	single_cycle.exe
.PHONY: tsn
tsn: *.o
	gcc *.o -o single_cycle -O3
	cp ../hidden_testcase/$(case1)/*.bin ../simulator
	single_cycle.exe
	$(comp) snapshot.rpt ../hidden_testcase/$(case1)/snapshot.rpt
.PHONY: ter
ter: *.o
	gcc *.o -o single_cycle -O3
	cp ../hidden_testcase/$(case1)/*.bin ../simulator
	single_cycle.exe
	$(comp) error_dump.rpt ../hidden_testcase/$(case1)/error_dump.rpt
.PHONY: test2
test2: *.o
	gcc *.o -o single_cycle -O3
	cp ../hidden_testcase/$(case2)/*.bin ../simulator
	./single_cycle
	$(comp) snapshot.rpt ../hidden_testcase/$(case2)/snapshot.rpt
	$(comp) error_dump.rpt ../hidden_testcase/$(case2)/error_dump.rpt
	rm -f *.bin *.rpt
	cp ../hidden_testcase/$(case3)/*.bin ../simulator
	./single_cycle
	$(comp) snapshot.rpt ../hidden_testcase/$(case3)/snapshot.rpt
	$(comp) error_dump.rpt ../hidden_testcase/$(case3)/error_dump.rpt
	rm -f *.bin *.rpt
	cp ../hidden_testcase/$(case4)/*.bin ../simulator
	./single_cycle
	$(comp) snapshot.rpt ../hidden_testcase/$(case4)/snapshot.rpt
	$(comp) error_dump.rpt ../hidden_testcase/$(case4)/error_dump.rpt
	rm -f *.bin *.rpt
	cp ../hidden_testcase/$(case5)/*.bin ../simulator
	./single_cycle
	$(comp) snapshot.rpt ../hidden_testcase/$(case5)/snapshot.rpt
	$(comp) error_dump.rpt ../hidden_testcase/$(case5)/error_dump.rpt
	rm -f *.bin *.rpt
	cp ../hidden_testcase/$(case6)/*.bin ../simulator
	./single_cycle
	$(comp) snapshot.rpt ../hidden_testcase/$(case6)/snapshot.rpt
	$(comp) error_dump.rpt ../hidden_testcase/$(case6)/error_dump.rpt
	rm -f *.bin *.rpt
