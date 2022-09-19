# Exercise I.a.1
yes we got the response immediately

### After connection
``` sh
Proto Recv-Q Send-Q Local Address           Foreign Address         State
tcp        0      0 localhost:51334         localhost:5717          ESTABLISHED
tcp        0      0 localhost:5717          localhost:51336         ESTABLISHED
tcp        0      0 localhost:5717          localhost:51334         ESTABLISHED
tcp        0      0 localhost:51336         localhost:5717          ESTABLISHED
```
### send message by first client
``` sh
Proto Recv-Q Send-Q Local Address           Foreign Address         State
tcp        0      0 localhost:51334         localhost:5717          ESTABLISHED
tcp        0      0 localhost:5717          localhost:51336         ESTABLISHED
tcp        0      0 localhost:39005         localhost:34778         ESTABLISHED
tcp        0      0 localhost:34778         localhost:39005         ESTABLISHED
tcp        0      0 localhost:39005         localhost:34776         ESTABLISHED
tcp        0      0 localhost:5717          localhost:51334         ESTABLISHED
tcp        0      0 localhost:34776         localhost:39005         ESTABLISHED
tcp        0      0 localhost:51336         localhost:5717          ESTABLISHED
tcp        0      0 localhost:34784         localhost:39005         TIME_WAIT
```
# Exercise I.a.2
``` sh
❯ ./client-multi 0.0.0.0 5703 100 10000 
Simulating 100 clients.
Establishing 100 connections...
  successfully initiated 100 connection attempts!
  - conn 71 : error in recv() : Connection reset by peer
  - conn 72 : error in recv() : Connection reset by peer
  - conn 73 : error in recv() : Connection reset by peer
  - conn 74 : error in recv() : Connection reset by peer
  - conn 11 : error in recv() : Connection reset by peer
  - conn 12 : error in recv() : Connection reset by peer
  - conn 13 : error in recv() : Connection reset by peer
  - conn 14 : error in recv() : Connection reset by peer
  - conn 15 : error in recv() : Connection reset by peer
  - conn 16 : connection closed by peer
  - conn 17 : connection closed by peer
  - conn 18 : connection closed by peer
  - conn 19 : connection closed by peer
  - conn 20 : connection closed by peer
  - conn 21 : connection closed by peer
  - conn 22 : error in recv() : Connection reset by peer
  - conn 23 : error in recv() : Connection reset by peer
  - conn 24 : error in recv() : Connection reset by peer
  - conn 25 : error in recv() : Connection reset by peer
  - conn 26 : error in recv() : Connection reset by peer
  - conn 53 : error in recv() : Connection reset by peer
  - conn 54 : error in recv() : Connection reset by peer
  - conn 55 : error in recv() : Connection reset by peer
  - conn 56 : error in recv() : Connection reset by peer
  - conn 57 : error in recv() : Connection reset by peer
  - conn 58 : error in recv() : Connection reset by peer
  - conn 59 : error in recv() : Connection reset by peer
  - conn 60 : error in recv() : Connection reset by peer
  - conn 61 : error in recv() : Connection reset by peer
  - conn 62 : error in recv() : Connection reset by peer
  - conn 63 : error in recv() : Connection reset by peer
  - conn 64 : error in recv() : Connection reset by peer
  - conn 65 : error in recv() : Connection reset by peer
  - conn 66 : error in recv() : Connection reset by peer
  - conn 67 : error in recv() : Connection reset by peer
  - conn 68 : error in recv() : Connection reset by peer
  - conn 69 : error in recv() : Connection reset by peer
  - conn 70 : error in recv() : Connection reset by peer
  - conn 75 : connection closed by peer
  - conn 76 : error in recv() : Connection reset by peer
  - conn 77 : error in recv() : Connection reset by peer
  - conn 78 : error in recv() : Connection reset by peer
  - conn 1 : connection closed by peer
  - conn 2 : connection closed by peer
  - conn 3 : connection closed by peer
  - conn 4 : connection closed by peer
  - conn 5 : connection closed by peer
  - conn 6 : connection closed by peer
  - conn 7 : connection closed by peer
  - conn 8 : connection closed by peer
  - conn 9 : connection closed by peer
  - conn 10 : connection closed by peer
  - conn 27 : error in recv() : Connection reset by peer
  - conn 28 : connection closed by peer
  - conn 29 : connection closed by peer
  - conn 30 : connection closed by peer
  - conn 31 : connection closed by peer
  - conn 32 : connection closed by peer
  - conn 33 : connection closed by peer
  - conn 34 : connection closed by peer
  - conn 35 : connection closed by peer
  - conn 36 : connection closed by peer
  - conn 37 : connection closed by peer
  - conn 38 : connection closed by peer
  - conn 39 : connection closed by peer
  - conn 40 : connection closed by peer
  - conn 41 : connection closed by peer
  - conn 42 : connection closed by peer
  - conn 43 : connection closed by peer
  - conn 44 : connection closed by peer
  - conn 45 : connection closed by peer
  - conn 46 : connection closed by peer
  - conn 47 : connection closed by peer
  - conn 48 : connection closed by peer
  - conn 49 : connection closed by peer
  - conn 50 : connection closed by peer
  - conn 51 : connection closed by peer
  - conn 52 : connection closed by peer
  - conn 79 : connection closed by peer
  - conn 80 : connection closed by peer
  - conn 81 : connection closed by peer
  - conn 82 : connection closed by peer
  - conn 83 : connection closed by peer
  - conn 84 : connection closed by peer
  - conn 85 : connection closed by peer
  - conn 86 : connection closed by peer
  - conn 87 : connection closed by peer
  - conn 88 : connection closed by peer
  - conn 89 : connection closed by peer
  - conn 90 : connection closed by peer
  - conn 91 : connection closed by peer
  - conn 92 : connection closed by peer
  - conn 93 : connection closed by peer
  - conn 94 : connection closed by peer
  - conn 95 : connection closed by peer
  - conn 96 : connection closed by peer
  - conn 97 : connection closed by peer
  - conn 98 : connection closed by peer
  - conn 99 : connection closed by peer
Connect timing results for 100 successful connections
  - min time: 0.679000 ms
  - max time: 1028.305300 ms
  - average time: 771.562654 ms
 (0 connections failed!)
Roundtrip timing results for 1 connections for 10000 round trips
  - min time: 147990.858000 ms
  - max time: 147990.858000 ms
  - average time: 147990.858000 ms
```
the average time for 100 successful connections is 25% less than previouse lab.

# Exercise I.a.3
Is it still possible to block the server using a single client? (Try it!)
the server may block for a long time (perhaps forever) waiting for the entire message to be received from the client; during that time, the server will not be able to respond to other clients. 
# Exercise I.a.4
yes, if we clone one of the connection the other connection is going to be close to. 
