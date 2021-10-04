geoip: geoip.c
	gcc -o geoip geoip.c
	
clean: 
	rm geoip
run:	
	./geoip 8.8.8.8
	