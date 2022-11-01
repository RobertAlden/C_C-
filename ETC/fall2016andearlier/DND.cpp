#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <math.h>
#include <time.h>
#include <string>
using namespace std;

int main(){
	//cout << "\u25A0";
    // Start predefining stuff here
    enum state {START, ACTIVE, EXIT};
    enum mapmode {WORLD, LOCAL};
    state gameState = START;
    mapmode map = WORLD;
    int input,topog, localx, localy;
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
    //End Initialize
    //WorldGen
    int gridx = 19;
    int gridy = 19;
	int dir;
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
	for (int z = 0;z < 40;z++){ //beach generation
		for (int q=0;q < 40;q++){
			if (world[z][q] == 1){
				world[z][q] = 500;
				if (q+1 <= 39) if (world[z][q+1] == 0) world[z][q+1] = rand()%200;
				if (q-1 >= 0) if (world[z][q-1] == 0) world[z][q-1] = rand()%200;
				if (z+1 <= 39) if (world[z+1][q] == 0) world[z+1][q] = rand()%200;
				if (z-1 >= 0) if (world[z-1][q] == 0) world[z-1][q] = rand()%200;
				if (q+1 <= 39 && z+1 < 39) if (world[z+1][q+1] == 0) world[z+1][q+1] = rand()%200;
				if (q-1 >= 0 && z-1 > 0) if (world[z-1][q-1] == 0) world[z-1][q-1] = rand()%200;
				if (q+1 <= 39 && z-1 > 0) if (world[z-1][q+1] == 0) world[z-1][q+1] = rand()%200;
				if (q-1 <= 0 && z+1 < 39) if (world[z+1][q-1] == 0) world[z+1][q-1] = rand()%200;
				
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
	for (int v=0;v<40;v++){ // mountains
		for (int h=0;h<40;h++){
			if (world[v][h] == 500){
				world[v][h] = 500 + rand()%500;
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
				for (int h=1;h<41;h++){
					//cout << "\033[1;31mbold red text\033[0m\n";
					if (world[v][h-1] == 0) cout << "\033[44;1;34m\u2248\u2248\033[0m"; //water
					else if (world[v][h-1] - 2500 > 0) cout << "\033[47;1;30m\u0394\u25b2\033[0m"; //mountains
					else if (world[v][h-1] - 1500 > 0) cout << "\033[32;42;1m\u2660\u2660\033[0m"; //forest
					else if (world[v][h-1] - 500 > 0) cout << "\033[42;1;32m\u2592\u2592\033[0m"; // default grass
					else if (world[v][h-1] == 300) cout << "\033[46;1;36m\u2248\u2248\033[0m"; // lakes
					else if (world[v][h-1] < 200) cout << "\033[43;1;33m\u2591\u2591\033[0m"; //beach
					
					if (h % 40 == 0) cout << endl;
				}
			}
		}
		if (map == LOCAL){
			srand(world[y][x]);
			for (int v=0;v<40;v++){
				for (int h=0;h<40;h++){
					local[v][h] = rand()%100;
					if (localx == h && localy == v) {
						cout << "\033[31;5m[]\033[0m";
					}
					else if (world[y][x] == 0){
						cout << "\033[44;1;37m\u2248\u2248\033[0m";
					}
					else if (world[y][x] - 1500 > 0) {//forest
						if (local[v][h] >= 90) cout << "\033[31;42;1m\u2660\u2660\033[0m"; // red tree
						else if (local[v][h] >= 80) cout << "\033[42;1;32m\u2663\u2663\033[0m"; //  green tree
						else if (local[v][h] >= 70) cout << "\033[33;42;1m\u2660\u2660\033[0m"; // yellow tree
						if (local[v][h] <= 69) cout << "\033[42;1;32m\u2592\u2592\033[0m"; // default grass
						//else cout << "\033[33;42;1m\u2663\u2663\033[0m"; //forest
						//else cout << world[v][h];
					}
				
					else if (world[y][x] - 2500 > 0) {//mountains
				
					}
				
					else if (world[y][x] - 500 > 0) {//plains
						if (local[v][h] > 95) cout << "\033[32;42;1m\u2660\u2660\033[0m"; //forest
						else if (local[v][h] <= 95) cout << "\033[42;1;32m\u2592\u2592\033[0m"; // default grass
						else cout << world[v][h];
					}
					else if (world[y][x] == 300) { //lakes
						cout << "\033[46;1;37m\u2248\u2248\033[0m";
					}
					else if (world[y][x] < 200) {
			
					}
				}
				cout<<endl;
			}
		}
	cout << endl;
	//EndDisplay
	//Input
	if (query == "nil"){
		cout << "enter command: ";
		cin >> query;
	}
	//EndInput
	
	//ApplyInput
	if (query == "lookat"){
		map = LOCAL;
		cout << "Enter X coordinate: " << endl;
		cin >> x;
		cout << "Enter Y coordinate: " << endl;
		cin >> y;
	}
	if (query == "map"){
		map = WORLD;
	}
	if (query == "spawn"){
		if (spawn == 0) {
		map = LOCAL;
		spawn = 1;
		cout << "Enter X coordinate: " << endl;
		cin >> x;
		cout << "Enter Y coordinate: " << endl;
		cin >> y;
		localx = 19;
		localy = 19;
		//int worldx = x;
		//int worldy = y;
		} else
		{ 
		cout << "you have already spawned!";
		}
	}
	if (spawn == 1)
	{
		if (query == "w") localy--;
		if (query == "s") localy++;
		if (query == "a") localx--;
		if (query == "d") localx++;
	}
	//End ApplyInput

	//Logic

	//EndLogic

	//Update
	query = "nil"; //clears input for next loop

	//End Update
	}
	return 0;
}







