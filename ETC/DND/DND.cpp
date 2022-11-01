#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <math.h>
#include <time.h>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
using namespace std;

int main(){
	
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

	//cout << "\u25A0";
    // Start predefining stuff here
	enum state {START, ACTIVE, EXIT};
	enum mapmode {WORLD, LOCAL};
	state gameState = START;
	mapmode map = WORLD;
    int input,topog, localx, localy , worldx, worldy;
	int spawn = 0;
     // array :[x] [y]
    int world[40][40] = {};
    int local[40][40] = {};
	int x,y;
    string query = "nil";
    // No more defining stuff.
    //Initialize
    srand (time(NULL));
    for (int v=0;v<40;v++){
        for (int h=0;h<40;h++)
        {
			world[v][h] = 0;
        }
    }
	world[0][0] = 0;
    //End Initialize
    //WorldGen
    int gridx = 19;
    int gridy = 19;
	int dir;
	int lookfor;
	world[gridx][gridy] = 1;
	world[gridx+1][gridy] = 1;
	world[gridx][gridy+1] = 1;
	world[gridx+1][gridy+1] = 1;
	for (int z = 0;z < 5+rand()%12;z++){
		for (int q=0;q < 50+rand()%50;q++){
			dir = rand()%4;
			switch (dir) {
				case 0:
					if (gridx < 39) gridx += 1;
				break;
				case 1:
					if (gridx > 0) gridx -= 1;
				break;
				case 2:
					if (gridy > 0) gridy -= 1;
				break;
				case 3:
				if (gridy < 39) gridy += 1;
				break;
			}
			world[gridx][gridy] = 1;
		}
	gridx = 19;
	gridy = 19;
	}
	for (int z = 0;z < 5+rand()%10;z++){
		for (int q=0;q < 10+rand()%25;q++){
			dir = rand()%4;
			switch (dir) {
				case 0:
					if (gridx < 39) gridx += 1;
				break;
				case 1:
					if (gridx > 0) gridx -= 1;
				break;
				case 2:
					if (gridy > 0) gridy -= 1;
				break;
				case 3:
					if (gridy < 39) gridy += 1;
				break;
			}
		world[gridx][gridy] = 1;
		}
	gridx = rand()%40;
	gridy = rand()%40;
	}
	for (int y = 0;y < 40;y++){ //beach generation
		for (int x=0;x < 40;x++){
			if (world[x][y] == 1){
				world[x][y] = 500;
				if (y+1 <= 39) if (world[x][y+1] == 0) world[x][y+1] = rand()%200;
				if (y-1 >= 0) if (world[x][y-1] == 0) world[x][y-1] = rand()%200;
				if (x+1 <= 39) if (world[x+1][y] == 0) world[x+1][y] = rand()%200;
				if (x-1 >= 0) if (world[x-1][y] == 0) world[x-1][y] = rand()%200;
				if (y+1 <= 39 && x+1 <= 39) if (world[x+1][y+1] == 0) world[x+1][y+1] = rand()%200;
				if (y-1 >= 0 && x-1 >= 0) if (world[x-1][y-1] == 0) world[x-1][y-1] = rand()%200;
				if (y+1 <= 39 && x-1 >= 0) if (world[x-1][y+1] == 0) world[x-1][y+1] = rand()%200;
				if (y-1 >= 0 && x+1 <= 39) if (world[x+1][y-1] == 0) world[x+1][y-1] = rand()%200;
				
			}
		}
	}
	for (int v=0;v<40;v++){ // mountains
		for (int h=0;h<40;h++){
			if (world[v][h] == 500){
				if (rand()%200 < 10) world[v][h] = 2500 + rand()%500;
			}
		}
	}
	
	for (int z = 0;z < 40;z++){ //forest spreading
		for (int q=0;q < 40;q++){
			if (world[z][q] == 500){
				if (rand()%200 < 20) world[z][q] = 1500+ rand()%500;
			}
		}
	}
	for (int v=0;v<40;v++){ // lakes
		for (int h=0;h<40;h++){
			if (world[v][h] == 500){
				if (world[v][h-1] == 500) if (world[v+1][h-1] == 500) if (world[v-1][h] == 500) if (world[v][h+1] == 500) if (rand()%200 < 25) world[v][h] = 300;
			}
		}
	}
	for (int v=0;v<40;v++){ // plains
		for (int h=0;h<40;h++){
			if (world[v][h] == 500){
				world[v][h] = 500 + 1 + rand()%500;
			}
		}
	}
	
	//EndWorldGen
	gameState = ACTIVE;
	while (gameState = ACTIVE){
		//Display
		if (map ==  WORLD){
			cout << "  0 1 2 3 4 5 6 7 8 9 101112131415161718192021222324252627282930313233343536373839" << endl;
			for (int v=0;v<40;v++){
				cout << setw(2) << v;
				for (int h=0;h<40;h++){
					//cout << "\033[1;31mbold red text\033[0m\n";
					local[v][h] = rand()%100;
					if ((lookfor == 1) && (worldx == h) && (worldy == v)) { 
							cout << "\033[31;41;1m[]\033[0m";
					}

					else if (world[v][h] == 0) cout << "\033[44;1;34m\u2248\u2248\033[0m"; //water
					else if (world[v][h] - 2500 > 0) cout << "\033[47;1;30m\u0394\u25b2\033[0m"; //mountains
					else if (world[v][h] - 1500 > 0) cout << "\033[32;42;1m\u2660\u2660\033[0m"; //forest
					else if (world[v][h] - 500 > 0) cout << "\033[42;1;32m\u2592\u2592\033[0m"; // default grass
					else if (world[v][h] == 300) cout << "\033[46;1;36m\u2248\u2248\033[0m"; // lakes
					else if (world[v][h] < 300) cout << "\033[43;1;33m\u2591\u2591\033[0m"; //beach
					//else if (world[v][h-1] < 300) cout << world[v][h-1]; //beach
					else cout << world[v][h];
		
				}
				cout << endl;
			}
		}
		if (map == LOCAL){
			srand(world[y][x]);
			for (int v=0;v<40;v++){
				for (int h=0;h<40;h++){
					local[v][h] = rand()%10000;
					if (localx == h && localy == v) {
						cout << "\033[41;31;5m[]\033[0m";
					}
					
					else if (world[y][x] == 0){
						cout << "\033[44;1;37m\u2248\u2248\033[0m";
					}
					
					else if (world[y][x] - 2500 > 0) {//mountains
						//cout << "\033[47;1;30m\u0394\u25b2\033[0m"; //mountains
						if (local[v][h] > 9500) cout << "\033[47;1;30m\u0394\u25b2\033[0m"; //forest
						else if (local[v][h] <= 9500) cout << "\033[47;1;30m\u2591\u2592\033[0m"; // default gravel
						else cout << world[v][h];
					}
					
					else if (world[y][x] - 1500 > 0) {//forest
						if (local[v][h] >= 9000) cout << "\033[31;42;1m\u2660\u2660\033[0m"; // red tree
						else if (local[v][h] >= 8000) cout << "\033[42;1;32m\u2663\u2663\033[0m"; //  green tree
						else if (local[v][h] >= 7000) cout << "\033[33;42;1m\u2660\u2660\033[0m"; // yellow tree
						else if (local[v][h] <= 6999) cout << "\033[42;1;32m\u2592\u2592\033[0m"; // default grass
						else cout << local[v][h];
						//else cout << "\033[33;42;1m\u2663\u2663\033[0m"; //forest
						//else cout << world[v][h];
					}
				
					else if (world[y][x] - 500 > 0) {//plains
						if (local[v][h] > 9500) cout << "\033[32;42;1m\u2660\u2660\033[0m"; //green trees
						else if (local[v][h] <= 9500) cout << "\033[42;1;32m\u2592\u2592\033[0m"; // default grass
						else cout << world[v][h];
					}
					else if (world[y][x] == 300) { //lakes
						cout << "\033[46;1;37m\u2248\u2248\033[0m";
					}
					else if (world[y][x] < 300) {
						 if (local[v][h] <= 5000) cout << "\033[43;1;33m\u2591\u2591\033[0m"; //beach;
						 else if (local[v][h] >= 5000) cout << "\033[43;1;33m\u2592\u2592\033[0m"; //beach;
						
					}
				}
				cout<<endl;
			}
		}
	cout << endl;
	//EndDisplay
	//Input
	
	if (query == "q"){
		//cout << worldx << " " << worldy << endl;
		//cout << "enter command: ";
		do {
		query=getchar();
		} while (query == "q");
	}
	//EndInput
	
	//ApplyInput
	if (query == "l")
	{
		worldx = 19;
		worldy = 19;
		lookfor = 1;
	}
	if (query == "c")
	{
		cout << worldx << " " << worldy << endl;
		lookfor = 0;
	}
	/*
	if (query == "k"){
		map = LOCAL;
		cout << "Enter X coordinate: " << endl;
		cin >> x;
		cout << "Enter Y coordinate: " << endl;
		cin >> y;
	}
	*/
	if (query == "m"){
		map = WORLD;
	}
	if (query == "t"){
		if (spawn == 0 && lookfor == 1) {
		map = LOCAL;
		spawn = 1;
		x = worldx;
		y = worldy;
		localx = 19;
		localy = 19;
		lookfor = 0;
		//int worldx = x;
		//int worldy = y;
		} else
		{ 
		cout << "you have already spawned!";
		}
	}
	if (spawn == 1){
		if (query == "w") {
			if (localy - 1 < 0){
				y--;
				localy = 39;
		} 
		else 
			{
			localy--;
			}
		}
	
		if (query == "s") {
			if (localy + 1 > 39){
				y++;
				localy = 0;
			} 
			else 
			{
			localy++;
			}
		}
		if (query == "a") {
			if (localx - 1 < 0){
				x--;
				localx = 39;
			} 
			else 
			{
				localx--;
			}
		}
		if (query == "d") {
			if (localx + 1 > 39){
				x++;
				localx = 0;
			} 
			else 
			{
				localx++;
			}
		}
	}
	
	if (lookfor == 1){
		if (query == "w") worldy--;
		if (query == "s") worldy++;
		if (query == "a") worldx--;
		if (query == "d") worldx++;
	}
	//End ApplyInput

	//Logic

	//EndLogic

	//Update
	query = "q"; //clears input for next loop
	cout << "\033[2J\033[1;1H";
	//End Update
	}
	return 0;
};








