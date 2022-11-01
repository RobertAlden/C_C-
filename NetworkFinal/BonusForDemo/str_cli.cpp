#include "myunp.h"
#include "pong.h"
/*
This is largely adapted from the Talk Project but should not really need much modification going forward.
*/
void
str_cli(FILE *fp, int sockfd)
{
	char	sendline[MAXLINE], recvline[MAXLINE]; //These are the buffers that the client uses to send and recieve data

	Display d(dwidth,dheight);	//Instantiates the graphics library from console_graphics.h, this object should be called to draw anything

	int update_rate = int((dwidth+dheight) * 1.5); //Limits the rate at which the client loops in milliseconds. Setting this to be 
	// faster is fine, but there is a point at the console will constantly be displaying new characters which causes a flickering effect.
	//Should be set to whatever the server uses.
	char input = ' ';	//This is the variable that is read for the keypress for input purposes
	char &input_ref = input; //This reference is passed to a thread which constantly checks for input so that the main loop does not stop
	thread inputThread(getInput,ref(input_ref)); // to wait for input.

	int gameState = 1; //Simply keep the loop running until the exit button is hit.
	int cli_id = -1;

	auto wait_update_timer = chrono::steady_clock::now();
	while (((chrono::steady_clock::now() - wait_update_timer) / chrono::milliseconds(1)) < 2) {};
	read(sockfd, recvline, MAXLINE);
	cli_id = int(recvline[0]);
	cout << "I am client " << cli_id << endl;

	while (gameState){
		auto update_timer = chrono::steady_clock::now(); //Timer variable to manage loop rate

		sendline[0] = char(cli_id);
		sendline[1] = input;
		//cout << sendline[0] << sendline[1] << sendline[2] << endl;
		//if (input != ' ') {
			write(sockfd, sendline, strlen(sendline)); //Sends the keypress to server.
		//}

		read(sockfd, recvline, MAXLINE); //Checks for new screen data from server.
		string data = string(recvline);

		d.loadScreen(d.screenDecode(data)); // decompresses and loads the screen data into its display array.
		cout << cli_id << endl;
		d.draw(); //Draws the display array

		if (input == 'q'){
			gameState = 0;
			d.Exit();
			return;
		}
		input = ' '; //Clears input.
		while (((chrono::steady_clock::now() - update_timer) / chrono::milliseconds(1)) < update_rate) {
			//Waits for the timer to limit loop rate.
		}
		cout << "\033[2J\033[1;1H"; //ANSI escape code to clear screen and reset cursor to top left.
	}

	input_flag = 1; //Tells the other thread to stop looping.
	inputThread.join(); // Joins input thread.
}
