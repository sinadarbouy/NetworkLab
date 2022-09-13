Exercise I.a.1
 - actualAddr.sin_addr
 - actualAddr.sin_port
 - 0.0.0.0 5703  

Exercise I.a.2  
- the last byte for EOF so in c we allways need to plus one if we dont want to count EOF.  

Exercise I.a.3 ??
one of the parameters for send is connfd (that is called the connected descriptor) after handshake is complete it changed to connection id. so send methon use that id for connection after that SIGPIPE (is a synchronous signal that’s sent to a process) control the connection and by using MSG_NOSIGNAL flag (in linux) it not going to generate a SIGPIPE signal if the peer on a stream-oriented socket has closed the connection.

Exercise I.a.4
  - some time just there is a error on sending message like size of meessage (EMSGSIZE) so the client can try again so ther is no reasion  to terminate connection
  - but someerror like ENOMEM that couldent allocate memory needs time and refresh so its going to terminate socket first.
  - like permission just need to terminate the client user not the server app.

Exercise I.c.1
 - no the client2 didnt recive any thing and 
 - RecvQ changed to 2 (recvQ: Established: The count of bytes not copied by the user program connected to this socket.)

Exercise I.c.2
  - client two recive messages
  - the status of connection('client 1') in netstat changed to TIME_WAIT(TIME_WAIT: The socket is waiting after close to handle packets still in the network.)
  - then the connection of client 1 removed from netstat  

# Q10
Exercise I.c.4
  - one of the factors for RTT is 'Server response time' – The time taken for a target server to respond to a request depends on its processing capacity, the number of requests being handled and the nature of the request.

# Q11
Exercise I.d.2
the min time and max time between 10 to 30 increase but after that between 30 to 100 almost the same.(maybe thats because of some connection waiting for other closing status!!!)
for round trip the 'min time' does not change that much around 0.092647 ms but max time increase (more than lineary),
no we didnot get any errors
``` sh  
❯ ./client-multi 0.0.0.0 5703 10 255                                                                                     ─╯
Simulating 10 clients.
Establishing 10 connections...
  successfully initiated 10 connection attempts!
Connect timing results for 10 successful connections
  - min time: 0.125875 ms
  - max time: 0.224801 ms
  - average time: 0.165671 ms
 (0 connections failed!)
Roundtrip timing results for 10 connections for 255 round trips
  - min time: 10.999905 ms
  - max time: 116.072442 ms
  - average time: 63.419688 ms
 /home/cna/uni/network/NetworkLab/lab1_2 │ master ?3                                     root@DESKTOP-DDPP6EI │ 20:51:50 ─╮
❯ ./client-multi 0.0.0.0 5703 10                                                                                         ─╯
Simulating 10 clients.
Establishing 10 connections...
  successfully initiated 10 connection attempts!
Connect timing results for 10 successful connections
  - min time: 0.068520 ms
  - max time: 0.120448 ms
  - average time: 0.085977 ms
 (0 connections failed!)
Roundtrip timing results for 10 connections for 1 round trips
  - min time: 0.063101 ms
  - max time: 0.821444 ms
  - average time: 0.397992 ms
 /home/cna/uni/network/NetworkLab/lab1_2 │ master ?3                                     root@DESKTOP-DDPP6EI │ 20:52:15 ─╮
❯ ./client-multi 0.0.0.0 5703 30                                                                                         ─╯
Simulating 30 clients.
Establishing 30 connections...
  successfully initiated 30 connection attempts!
Connect timing results for 30 successful connections
  - min time: 4.135480 ms
  - max time: 1083.068896 ms
  - average time: 677.701511 ms
 (0 connections failed!)
Roundtrip timing results for 30 connections for 1 round trips
  - min time: 0.092647 ms
  - max time: 227.968956 ms
  - average time: 68.512136 ms
 /home/cna/uni/network/NetworkLab/lab1_2 │ master ?3                                     root@DESKTOP-DDPP6EI │ 20:52:54 ─╮
❯ ./client-multi 0.0.0.0 5703 50                                                                                         ─╯
Simulating 50 clients.
Establishing 50 connections...
  successfully initiated 50 connection attempts!
Connect timing results for 50 successful connections
  - min time: 4.207596 ms
  - max time: 1078.937514 ms
  - average time: 863.294189 ms
 (0 connections failed!)
Roundtrip timing results for 50 connections for 1 round trips
  - min time: 0.094466 ms
  - max time: 1756.368572 ms
  - average time: 379.478261 ms
 /home/cna/uni/network/NetworkLab/lab1_2 │ master ?3                                     root@DESKTOP-DDPP6EI │ 20:53:22 ─╮
❯ ./client-multi 0.0.0.0 5703 100                                                                                        ─╯
Simulating 100 clients.
Establishing 100 connections...
  successfully initiated 100 connection attempts!
Connect timing results for 100 successful connections
  - min time: 0.352046 ms
  - max time: 1027.467710 ms
  - average time: 924.697612 ms
 (0 connections failed!)
Roundtrip timing results for 100 connections for 1 round trips
  - min time: 0.047724 ms
  - max time: 75758.911129 ms
  - average time: 9546.720368 ms
 /home/cna/uni/network/NetworkLab/lab1_2 │ master ?3                            1m 17s │ root@DESKTOP-DDPP6EI │ 20:54:42 ─╮
❯ ./client-multi 0.0.0.0 5703 5                                                                                          ─╯
Simulating 5 clients.
Establishing 5 connections...
  successfully initiated 5 connection attempts!
Connect timing results for 5 successful connections
  - min time: 0.046671 ms
  - max time: 0.105885 ms
  - average time: 0.065734 ms
 (0 connections failed!)
Roundtrip timing results for 5 connections for 1 round trips
  - min time: 0.031649 ms
  - max time: 0.328205 ms
  - average time: 0.169955 ms
 /home/cna/uni/network/NetworkLab/lab1_2 │ master ?3                                     root@DESKTOP-DDPP6EI │ 20:55:06 ─╮
❯ ./client-multi 0.0.0.0 5703 5 10                                                                                       ─╯
Simulating 5 clients.
Establishing 5 connections...
  successfully initiated 5 connection attempts!
Connect timing results for 5 successful connections
  - min time: 0.039324 ms
  - max time: 0.093512 ms
  - average time: 0.055148 ms
 (0 connections failed!)
Roundtrip timing results for 5 connections for 10 round trips
  - min time: 0.860269 ms
  - max time: 2.731046 ms
  - average time: 1.840992 ms
```

Reduce the number of clients to 7
``` sh
 /home/cna/uni/network/NetworkLab/lab1_2 │ master ?3                                     root@DESKTOP-DDPP6EI │ 20:59:54 ─╮
❯ ./client-multi 0.0.0.0 5703 7 1000                                                                                     ─╯
Simulating 7 clients.
Establishing 7 connections...
  successfully initiated 7 connection attempts!
Connect timing results for 7 successful connections
  - min time: 0.056532 ms
  - max time: 0.113772 ms
  - average time: 0.072725 ms
 (0 connections failed!)
Roundtrip timing results for 7 connections for 1000 round trips
  - min time: 45.619758 ms
  - max time: 346.395837 ms
  - average time: 195.392769 ms
 /home/cna/uni/network/NetworkLab/lab1_2 │ master ?3                                     root@DESKTOP-DDPP6EI │ 21:00:07 ─╮
❯ ./client-multi 0.0.0.0 5703 7 5000                                                                                     ─╯
Simulating 7 clients.
Establishing 7 connections...
  successfully initiated 7 connection attempts!
Connect timing results for 7 successful connections
  - min time: 0.056541 ms
  - max time: 0.125599 ms
  - average time: 0.074184 ms
 (0 connections failed!)
Roundtrip timing results for 7 connections for 5000 round trips
  - min time: 230.207954 ms
  - max time: 1495.809968 ms
  - average time: 864.462709 ms
 /home/cna/uni/network/NetworkLab/lab1_2 │ master ?3                                     root@DESKTOP-DDPP6EI │ 21:00:18 ─╮
❯ ./client-multi 0.0.0.0 5703 7 10000                                                                                    ─╯
Simulating 7 clients.
Establishing 7 connections...
  successfully initiated 7 connection attempts!
Connect timing results for 7 successful connections
  - min time: 0.039357 ms
  - max time: 0.116656 ms
  - average time: 0.067023 ms
 (0 connections failed!)
Roundtrip timing results for 7 connections for 10000 round trips
  - min time: 422.942105 ms
  - max time: 2931.971961 ms
  - average time: 1688.642001 ms
```

``` sh
 /home/cna/uni/network/NetworkLab/lab1_2 │ master ?3                                     root@DESKTOP-DDPP6EI │ 21:00:26 ─╮
❯ ./client-multi 0.0.0.0 5703 100 10000                                                                                  ─╯
Simulating 100 clients.
Establishing 100 connections...
  successfully initiated 100 connection attempts!
  - conn 24 : error in recv() : Connection reset by peer
  - conn 25 : error in recv() : Connection reset by peer
  - conn 26 : error in recv() : Connection reset by peer
  - conn 27 : error in recv() : Connection reset by peer
  - conn 28 : error in recv() : Connection reset by peer
  - conn 29 : error in recv() : Connection reset by peer
  - conn 30 : error in recv() : Connection reset by peer
  - conn 31 : error in recv() : Connection reset by peer
  - conn 32 : error in recv() : Connection reset by peer
  - conn 33 : error in recv() : Connection reset by peer
  - conn 10 : error in recv() : Connection reset by peer
  - conn 11 : error in recv() : Connection reset by peer
  - conn 12 : error in recv() : Connection reset by peer
  - conn 13 : error in recv() : Connection reset by peer
  - conn 14 : error in recv() : Connection reset by peer
  - conn 15 : error in recv() : Connection reset by peer
  - conn 16 : error in recv() : Connection reset by peer
  - conn 17 : error in recv() : Connection reset by peer
  - conn 18 : error in recv() : Connection reset by peer
  - conn 19 : error in recv() : Connection reset by peer
  - conn 20 : error in recv() : Connection reset by peer
  - conn 21 : error in recv() : Connection reset by peer
  - conn 22 : error in recv() : Connection reset by peer
  - conn 23 : error in recv() : Connection reset by peer
  - conn 80 : error in recv() : Connection reset by peer
  - conn 81 : error in recv() : Connection reset by peer
  - conn 82 : error in recv() : Connection reset by peer
  - conn 83 : error in recv() : Connection reset by peer
  - conn 84 : error in recv() : Connection reset by peer
  - conn 85 : error in recv() : Connection reset by peer
  - conn 86 : error in recv() : Connection reset by peer
  - conn 87 : error in recv() : Connection reset by peer
  - conn 88 : error in recv() : Connection reset by peer
Connect timing results for 100 successful connections
  - min time: 1.058817 ms
  - max time: 1079.906396 ms
  - average time: 971.644789 ms
 (0 connections failed!)
Roundtrip timing results for 67 connections for 10000 round trips
  - min time: 426.407401 ms
  - max time: 113455.760293 ms
  - average time: 32479.831416 ms
```

# Q 12
Exercise I.d.3
we tried 1021 connection then we got Connection timed out after 2m 11s
``` sh
async connect() error: Connection timed out
```
