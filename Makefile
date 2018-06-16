testMain.exe: ConfHandler.cc testMain.cc
	g++ -o testMain.exe ConfHandler.cc testmain.cc

clean: 
	rm testMain.exe

test: testMain.exe
	./testMain.exe

remake:clean testMain.exe
