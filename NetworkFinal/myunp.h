#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define SERV_PORT 9877
#define MAXLINE 4096
#define SA struct sockaddr
#define LISTENQ 1024