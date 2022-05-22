all: sock fif mesq

sock: p1_sock.c p2_sock.c
	gcc -o p1s p1_sock.c 
	gcc -o p2s p2_sock.c

fif: p1_fifo.c p2_fifo.c
	gcc -o f1s p1_fifo.c
	gcc -o f2s p2_fifo.c

mesq: p1_mesq.c p2_mesq.c
	gcc -o m1s p1_mesq.c
	gcc -o m2s p2_mesq.c