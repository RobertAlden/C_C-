#include "myunp.h"
#include <sys/time.h>
#include "pong.h"
#include <fcntl.h>

// This is largely unchanged from its initial form. 
int
main(int argc, char **argv) {
	int					master_socket, new_socket, connfd;
	pid_t				childpid;
	socklen_t			clilen;
	struct sockaddr_in	cliaddr, servaddr;

	int max_clients = 2;
	int cur_clients = 0;
	int client_socket[max_clients];
	int opt = 1;
	int activity, valread , sd, addrlen;   
    int max_sd;   

	master_socket = socket(AF_INET, SOCK_STREAM, 0);
	setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));
	fd_set readfds; // Uses a set of file descriptors assigned to each socket
	// Allows for multiple clients to talk and not get messages mixed up.

	timeval t;
	t.tv_sec = 1;

	char message[] = "You've connected! \r\n";  

	char *pBuffer;
	pBuffer = (char*)calloc(MAXLINE, sizeof(char));
	
	
	char send_buf[MAXLINE]; //Communication buffers for clients.

	Display d(dwidth,dheight); //Instantiates the graphics library from console_graphics.h, this object should be called to draw anything
	int update_rate = int((dwidth+dheight) * 1.5); // milliseconds

	char input[max_clients]; //This is the variable that is read for the keypress for input purposes, it is set by the client, and will need to be changed
	// going forward for multiple clients.

	//Creation of game objects. Refer to the bottom of console_graphics.h for more info on how objects are handled.
	GameObject * b = new Ball(dwidth/2,dwidth/2,1.5,'1'); //Actual creation of object.
	objs.push_back(b); // Addition of object to objs vector. IMPORTANT. If the object is not added to the vector using this push_back() function,
	// it is not automatically handled, otherwise you have to manually call it's functions in the game loop.
	GameObject * p1 = new Paddle(dwidth/4,20,0,'2');
	objs.push_back(p1);
	GameObject * p2 = new Paddle(dwidth - dwidth/4,20,1,'3');
	objs.push_back(p2);



	for (int i = 0; i < max_clients; i++) {    //Initializes client resources
		client_socket[i] = 0;
		input[i] = ' ';
	}

	bzero(&servaddr, sizeof(servaddr)); //Socket setup
	servaddr.sin_family      = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port        = htons(SERV_PORT);

	bind(master_socket, (SA *) &servaddr, sizeof(servaddr));

	listen(master_socket, max_clients);

	int gameState = 1;
	while (gameState) { //Simply keep the loop running until the exit button is hit.
		
		auto update_timer = chrono::steady_clock::now(); //Timer for loop speed regulation.
		FD_ZERO(&readfds);   //resets file descriptor set (fds)

		FD_SET(master_socket, &readfds);  // adds server's socket to fds
		max_sd = master_socket;   
 
		for (int i = 0 ; i < max_clients; i++) {   
			sd = client_socket[i];   
			if(sd > 0)   
				FD_SET( sd , &readfds);   
			if(sd > max_sd)   
				max_sd = sd;  
		}
		
		activity = select(max_sd + 1, &readfds, NULL, NULL, &t); //detects activity on one of the sockets in the fds
		
		
		if (FD_ISSET(master_socket, &readfds)) {   // if the servers scoket has activity, it means there is a new client connecting.
			new_socket = accept(master_socket,(SA *) &servaddr, (socklen_t*)&addrlen);
		
			//add new socket to array of sockets  
			for (int i = 0; i < max_clients; i++) {   
				//if position is empty  
				if (client_socket[i] == 0) {   
					client_socket[i] = new_socket;   
					printf("Adding to list of sockets as %d\n" , i);   
					cur_clients++;

					sd = client_socket[i]; 
					send_buf[0] = char(i+1);
					send_buf[1] = 0;
					write(sd, send_buf, sizeof(send_buf));
					break;   
				}   
			}   
		}   
		
		if (cur_clients == max_clients) { // Halts the game till all players connect.
			for (int i = 0; i < cur_clients; i++) {   
				sd = client_socket[i];   
				if (FD_ISSET(sd , &readfds)) { 	
					read(sd, pBuffer, MAXLINE); //Reads the receive buffer for client keypresses.
					input[i] = pBuffer[1];
					printf("%i:%s\n",i+1 , pBuffer);
				}
			}
			d.clear(); //Clears display array.

			for (int i = 0; i < objs.size(); i++) { //This is the object handling array, it automatically calls the main functions for all the objects.
				for (int c = 0; c < cur_clients; c++) {
					(*objs[i]).getInput(input[c],c);
				}
				(*objs[i]).update();
				(*objs[i]).draw(d);
			}
			string data = d.screenEncode(); // Compresses display array using simple algorithm, refer to console_grpahics.h for details.

			for(int i = 0; i < data.size(); i++) {
				send_buf[i] = data[i]; //Copying display data to send buffer.
			}
			send_buf[data.size()] = '\n'; // Appends a null character to end of buffer.
			for (int i = 0; i < cur_clients; i++) {
					sd = client_socket[i];  
					write(sd, send_buf, sizeof(send_buf)); // Sends data to clients. Should be the same data to all clients.
			} 
			memset(send_buf, 0, sizeof(send_buf));
			
			while (delete_queue.size() > 0) { // This is the object deletion queue. If an object has its deletion method called, 
				// it is not immediately destroyed but is added to this queue to make sure there aren't any dead references left around
				// in the main objs vector.
				for (int k = 0; k < objs.size();k++) {
					if (objs.at(k) == delete_queue.front()) {
						objs.erase(objs.begin()+k);
						delete_queue.erase(delete_queue.begin());
						k--;
					}
				}		
			}
			if (input[0] == 'q') {
				gameState = 0;
				d.Exit();
				for (int i = 0; i < cur_clients; i++) {
					sd = client_socket[i];  
					close( sd );   
					client_socket[i] = 0;
				} 
			}
			for (int i = 0; i < cur_clients; i++) {   
				input[i] = ' ';
			}
			while (((chrono::steady_clock::now() - update_timer) / chrono::milliseconds(1)) < update_rate) {};
		}	
	} 

}

