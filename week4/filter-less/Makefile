filter:	filter.c helpers.c helpers.h bmp.h 
	@gcc -g -o filter filter.c helpers.c -lm

run:
	@./filter -g ./images/tower.bmp ./images/tower.bmp.grayscale
	@./filter -s ./images/tower.bmp ./images/tower.bmp.sepia

clean:
	@rm filter
	@rm ./images/tower.bmp.grayscale
	@rm ./images/tower.bmp.sepia
