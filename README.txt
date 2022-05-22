According to the rubric provided with the assignment, a total of 6 programs were created.
The files for P1 are named as p1_fifo, p1_mesq, p1_sock.
The files for P2 are named as p2_fifo, p2_mesq, p2_sock.

Makefile was also made to build all the programs. After running make on the terminals,then executing p2s and then p1s in different terminals will show the output.
One terminal will print the Highest ID's among the group of strings and the other terminal will print 50 random strings (0-49).

--> The fifo files of the programs P1 and P2 are p1_fifo and p2_fifo respectively.

p1_fifo is used to create strings, each of length 5 as mentioned in the question. The function create is used to create a matrix that could store 50 such 
strings of length 5 each. The create function itself fills the matrix by generating 50 random strings.
The main function calls the create function so as to recieve the matrix. Then a special fifo file is created or in other words a pipe is created to make
required changes to it so that program P1 can successfully retrieve the highest ID amongst the five selected strings.
p2_fifo also creates a mkfifo file. A for loop is created and inside it at every iteration the file is opened for reading as well as for writing. After reading
the strings, the program checks whether the highest ID has been recorded or not, if not it throws a statement. When the ID is finally recorded the file is closed 
and the loop continues for every 5 strings read.


--> The message passing queues files of the programs P1 and P2 are p1_mesq and p2_mesq respectively.

In p1_mesq we firstly use create() function to create the matrix with 50 random strings. Objects obm and obr are also created for sending and recieving string and index.
A for loop is created so that the strings could be copied to the queue using strcpy.
Similar to p1_mesq, p2_mesq also has the objects obm and obr for the purpose defined above. 
The queue is firstly registered using ftok and then a loop runs. In the loop we first use msgget to get the message queue. Then for the ID we recieved, we use it to read the 
highest ID from the queue using msgrcv. Then the same ID is sent using msgsnd system call. Then at the end of the loop msgctl is used with the cmd value IPC_RMID so as to terminate
the current queue and a new could be created at the next iteration. This goes on until the loop ends.        


--> The socket files of the programs P1 and P2 are p1_sock and p2_sock respectively.

In p1_sock firstly the matrix of 50 random strings is created. Then a socket is created using socket() and the file handle is stored in an integer 's'. Then we firstly use inet_pton
to convert the address we provided to binary format and then connect is used to connect to the port. 
Then a loop is used to write the strings and then recieve the highest ID among that group of strings. Then the highest ID is printed on the terminal.
Once the loop ends the socket is closed and the program is terminated.
In p2_sock similar to p1_sock, a socket is created using socket() whose file handle is stored in so_id. 
setsockopt is used so that the address and port could be reused. Then bind is used to bind the socket and the address. 
Then we use listen and wait for a connection establishment. Then once we execute p1s, the connection is established using accept(). Then we read the strings and print them on the 
terminal. The highest ID is also sent back. Once the loop ends the socket is closed. 






