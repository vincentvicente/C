# Lab 9: Knock-Knock Client/Server  
### Course: CS5008
### Instructor: Drew Jelani 
### Name: Qiyuan Zhu
### Date: 04/11/2024

## Who did I work with?
### Only myself

## How long did it take you to finish?
### About 2.5 hours

## Sample run
### server
```
[vincentvicenteqy@login-students lab9]$ make run_echo_server
./echo_server
Listening on file descriptor 3, port 1234
Waiting for connection...
Connection made: client_fd=4
Read 6 chars
===
hello

Got repetition count from client
===
3

Repeat 1/3
Repeat 2/3
Repeat 3/3
Done.

Read 4 chars
===
bye

Got repetition count from client
===
2

Repeat 1/2
Repeat 2/2
Done.

Got terminating signal from client...Closing connection.
```

### client
```
[vincentvicenteqy@login-students lab9]$ make run_echo_client
gcc echo_client.c -o echo_client
./echo_client
Enter your message: hello

SENDING: hello

How many times to repeat?
3

FROM SERVER:
hello

hello

hello

Enter your message: bye

SENDING: bye

How many times to repeat?
2

FROM SERVER:
bye

bye

Enter your message: x

SENDING: x

Connection terminates.
```

