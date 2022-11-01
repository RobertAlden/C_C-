ALL: client server
client: tcpcli01.cpp str_cli.cpp
	g++ -pthread -std=c++11 -o client tcpcli01.cpp
server: tcpservMultiClient.cpp
	g++ -pthread -std=c++11 -o server tcpservMultiClient.cpp 
clean:
	rm ./client ./server
