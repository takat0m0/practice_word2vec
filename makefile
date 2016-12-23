make_dir:
	mkdir bin
	mkdir obj
clean:
	rm -rf ./bin
	rm -rf ./obj
	make -f makefile make_dir

move:
	mv ./src/*.o ./obj
	mv ./src/*.out ./bin


all:
	make clean
	cd src; make -f makefile; cd ../
	make -f makefile move
