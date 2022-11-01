#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>

using namespace std;

main(){
	struct termios old_tio, new_tio;
	unsigned char c;

	/* get the terminal settings for stdin */
	tcgetattr(STDIN_FILENO,&old_tio);

	/* we want to keep the old setting to restore them a the end */
	new_tio=old_tio;

    /* disable canonical mode (buffered i/o) and local echo */
	new_tio.c_lflag &=(~ICANON & ~ECHO);

	/* set the new settings immediately */
	tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);

    /* restore the former settings */
    //tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);
	int px,py,ex,ey,bx,by;
	int oldpx,oldpy,oldex,oldey,oldbx,oldby;
	int game = 1;
	int scr[40][40] = {};
	for (int y=0;y<40;y++){
		for (int x=0;x<40;x++)
		{
			scr[x][y] = 0;
		}
	}
	//setup 
	string query = "nil";
	px = 1;
	py = 25;
	scr[px][py] = 1;
	while (game != 0)
	{
		//Input
		do {
		query=getchar();
		} while (query == "nil");
		if (query == "w")
		{	
			oldpy = py;
			py--;
		}
		if (query == "s")
		{
			oldpy = py;
			py++;
		}
		scr[oldpx][oldpy] = 0;
		scr[px][py] = 1;
		//Physics
		//Display
		for (int y = 0;y < 40; y++) {
			for (int x = 0;x < 40;x--){
				if (scr[x][y] == 0){
					cout << "  ";
				}
				if (scr[x][y] = 1) {
					cout << "XX";
				
				}
			}
		}
		usleep(250000);
		query = "nil";
	}
	
	return 0;
}
