#include "myunp.h"
#include "str_cli.cpp"
// This is largely unchanged from its initial form. 
int
main(int argc, char **argv)
{
	int					sockfd;
	struct sockaddr_in	servaddr;

	if (argc != 2) {
		printf("usage: tcpcli <IPaddress>");
		exit(1);
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

	connect(sockfd, (SA *) &servaddr, sizeof(servaddr));

	int choice;
	
	again:    
	cout << "----------------------------------------------------------------------------------" << endl;
    	cout << "Welcome to Pong. The controls to play the game are W and S for both players." << endl;
	cout << "We hope you enjoy the game." << endl;
    	cout << "Enter '1' to start the game." << endl;
    	cout << "Enter '2' to exit the game." << endl;
    	cout << "----------------------------------------------------------------------------------" << endl;
    	cin >> choice;
    
    	if(choice == 1) {
		str_cli(stdin, sockfd);		/* do it all */
	goto again;
	} else if(choice == 2) {
		cout << "Goodbye, thank you for playing!" << endl;
		exit(0);
   	}
	exit(0);
}
