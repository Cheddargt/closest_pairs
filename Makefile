all:
	gcc closest.c -o closest -lm
	gcc genpoints.c -o genpoints -lm

clean:g
	rm -f closest;
	rm -f genpoints;
