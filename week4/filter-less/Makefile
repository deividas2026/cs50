filter:	filter.c helpers.c helpers.h bmp.h 
	@gcc -g -o filter filter.c helpers.c -lm

run:
	@./filter -g ./images/tower.bmp ./images/tower.bmp.g
	@./filter -s ./images/tower.bmp ./images/tower.bmp.s
	@./filter -r ./images/tower.bmp ./images/tower.bmp.r
	@./filter -b ./images/tower.bmp ./images/tower.bmp.b

clean:
	@rm filter
	@rm ./images/tower.bmp.g
	@rm ./images/tower.bmp.s
	@rm ./images/tower.bmp.r
	@rm ./images/tower.bmp.b
