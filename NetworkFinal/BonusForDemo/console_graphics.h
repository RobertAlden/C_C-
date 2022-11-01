//console_graphics.h
#ifndef _GRAPHICS
#define _GRAPHICS


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <time.h>
#include <chrono>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <string>
#include <vector>
#include <thread>

using namespace std;
/*
ANSI Color Codes:
 E.G. "\033[44;1;34m\u2593\u2593\033[0m"
Name            BG  FG
Black           30  40
Red             31  41
Green           32  42
Yellow          33  43
Blue            34  44
Magenta         35  45
Cyan            36  46
White           37  47
Bright Black    90  100
Bright Red      91  101
Bright Green    92  102
Bright Yellow   93  103
Bright Blue     94  104
Bright Magenta  95  105
Bright Cyan     96  106
Bright White    97  107
*/
int input_flag = 0;
int dwidth = 40; //Default width and height, used to properly place game objects and run game logic despite varying sizes. 
int dheight = 40; //Just change these to make the display have more or less pixels.

void getInput(char &_i) { // This function is used in a separate thread to prevent I/O blocking. 
	//it lets the game run without waiting around for input every frame.
	while (true && !input_flag) {
		char i = getchar();
		_i = i;
	}
}

class Display { // This is the main display class. It has basic functions for drawing shapes and primitive pieces.
	//There are some private functions that the public functions use. They aren't intended to be used directly. 
	int width; // Display width and height.
	int height;
	char ** screen;

	struct termios old_tio, new_tio; // Terminal setting variables.
	unsigned char c;

	//The value argument in all these upcoming drawing functions is essentially the code assigned to a color. 
	//There is room for many more colors than already exist.
	// Define more as necessary, and tell the game objects to draw using them.

	void lineLow(int x1,int y1, int x2, int y2, char value) { //Intended for internal use of the Line function
		int dx = x2 - x1;
		int dy = y2 - y1;
		int yi = 1;
		if (dy < 0) {
			yi = -1;
			dy = -dy;
		}
		int D = 2*dy-dx;
		int y = y1;

		for (int x = x1; x <= x2;x++) {
			screen[x][y] = value;
			if (D > 0) {
				y += yi;
				D = D - 2*dx;
			}
			D = D + 2*dy;
		}
	}

	void lineHigh(int x1,int y1, int x2, int y2, char value) { //Intended for internal use of the Line function
		int dx = x2 - x1;
		int dy = y2 - y1;
		int xi = 1;
		if (dx < 0) {
			xi = -1;
			dx = -dx;
		}
		int D = 2*dx - dy;
		int x = x1;

		for (int y = y1; y <= y2; y++) {
			screen[x][y] = value;
			if (D > 0) {
				x += xi;
				D = D - 2*dy;
			}
			D = D + 2*dx;
		}
	}
public:
	void point(int x, int y, char value) { // Draws a single pixel at x,y
		for (int v=0;v<height;v++){
			for (int h=0;h<width;h++) {
				if (v == x && h == y) {
					screen[v][h] = value;
				}
			}
		}
	}
	float distance(int x1, int y1, int x2, int y2) { //Finds distance between two points, used in the circle function.
		return sqrt(((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)));
	}

	void circle(int x, int y, int r, char value, bool filled) { // Draws a circle with radius at x,y with radius. can be filled or just an outline.
		for (int v=0;v<height;v++){
			for (int h=0;h<width;h++) {
				if (filled == true) {
					if (round(distance(x,y,v,h)) <= r) {
						screen[v][h] = value;
					} 
				} else {
					if (round(distance(x,y,v,h)) == r) {
						screen[v][h] = value;
					} else if (round(distance(x,y,v,h)) < r) {
						screen[v][h] = '0';
					}
				}
			}
		}
	}

	void rectangle(int x1,int y1,int x2,int y2,char value,bool filled) { // Draws a rectangle with top-left corner at x1,y1, and bottom-right at
		// x2 and y2.
		for (int v=0;v<height;v++){
			for (int h=0;h<width;h++) {
				if ((h >= x1 && h <= x2) && (v >= y1 && v <= y2)) {
					screen[v][h] = value;
				}
				if (filled == false) {
					if ((h >= x1+1 && h <= x2-1) && (v >= y1+1 && v <= y2-1)) {
						screen[v][h] = '0';
					}	  
				}
			}
		}
	}

	

	void line(int x1, int y1, int x2, int y2, char value) { //This draws a nice line from x1,y1, to x2,y2.
		if (abs(y2-y1) < abs(x2 - x1)) {
			if (x1 > x2) {
				lineLow(x2,y2,x1,y1,value);
			} else {
				lineLow(x1,y1,x2,y2,value);
			}
		} else {
			if (y1 > y2) {
				lineHigh(x2,y2,x1,y1,value);
			} else {
				lineHigh(x1,y1,x2,y2,value);
			}
		}
	}

	void draw() { //Prints the screen array
		for (int y = 0;y < height;y++){
			for (int x=0;x < width;x++){
				switch (screen[x][y]) { // Define new colors in this switch statement. Refer to ansi escape codes at the top for colors.
					case '0':
						cout << "\033[30;1;30m\u2593\u2593\033[0m"; // Dark Grey
					break;
					case '1':
						cout << "\033[97;1;107m\u2593\u2593\033[0m"; // White
					break;
					case '2':
						cout << "\033[31;1;41m\u2593\u2593\033[0m"; // Red
					break;
					case '3':
						cout << "\033[32;1;42m\u2593\u2593\033[0m"; // Green
					break;
					case '4':
						cout << "\033[34;1;44m\u2593\u2593\033[0m"; // Blue
					break;
					case '5':
						cout << "\033[30;1;40m\u2593\u2593\033[0m"; // Dark Black
					break;

				}
			}
			cout << endl;
		}
	}
	void clear() { //Clears the display array
		for (int y = 0;y < height;y++){
			for (int x=0;x < width;x++){
				screen[x][y] = '0';
			}
		}
	}

	string screenEncode() { 
		/* 
		This is a simple compression algorithm to reduce message length for large display arrays.
		It just reads the array for adjacent identicle values and tallys them up and converts them into this format:

		input: 000000000000000000000000234555550000000000000000000000000000 
		end: [24]0234[5]5[28]0

		as you can see, there tends to be large chunks of similar pixels on a game,
		and this algorithm can reduce the data length by ~85% depending on how many colors are on screen.
		*/
		string screendata = "";
		for (int y = 0;y < height;y++){
			for (int x=0;x < width;x++){
				screendata += screen[x][y];
			}
		}
		int counter = 1;
		char prev = screendata[0];
		string output = "";
		for (int i = 1; i < screendata.size(); i++) {
			if (screendata[i] == prev) {
				counter+= 1;
			} else {
				if (counter > 1) {
					output += "[";
					output.append(to_string(counter));
					output += "]";
				}
				output += prev;
				counter = 1;
				prev = screendata[i];
			}
		}
		if (counter > 1) {
			output += "[";
			output.append(to_string(counter));
			output += "]";
		}
		output += prev;
		counter = 1;
		output += '\0';
		return output;
	}
	string screenDecode(string code) { 
		/*
			This simply undoes the above compression algorithm to a raw format.
		*/
		char index = code[0];
		int mode = 0;
		int quantity = 1;
		string value = "";
		string output = "";

		for (int i = 0; i < code.size(); i++) {
			if (code[i] == '[') {
				mode = 1;
			} else if (code[i] == ']') {
				mode = 0;
				quantity = stoi(value);
				value = "";
			} else {
				if (mode == 1) {
					value += code[i];
				} else {
					for (int n = 0; n < quantity; n++) {
						output += code[i];

					}
					quantity = 1;
				}
			} 
		}
		return output;
	}

	void loadScreen(string data) { //Copys a string of screen data into the array.
		for (int i = 0; i < data.size(); i++) {
			int _x = i % width;
			int _y = i / width;
			screen[_x][_y] = data[i];
		}
	}

	Display(int w, int h) { //Constructor
		srand (time(NULL));

		/* get the terminal settings for stdin */
		tcgetattr(STDIN_FILENO,&old_tio);

		/* we want to keep the old setting to restore them at the end */
		new_tio=old_tio;

	    /* disable canonical mode (buffered i/o) and local echo */
		new_tio.c_lflag &=(~ICANON & ~ECHO);

		/* set the new settings immediately */
		tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);

	    /* restore the former settings */
	    //tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);

		width = w;
		height = h;
		screen = new char*[height];
		for(int i = 0; i < height; i++)
		    screen[i] = new char[width];

		for (int v=0;v<height;v++){
			for (int h=0;h<width;h++) {
				screen[v][h] = '0';
			}
		}
	}
	void Exit() {
			//Reset terminal settings
		tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);
		cout << "Game Exited" << endl;
	}
};

/*
 This GameObject class is a sort of template class that all the other objects must follow some basic rules.

 They must all possess at least an empty definition of the virtual void functions:
 update()
 getInput()
 draw()

 also, any internal variables that need to be accessed from another object should be declared in the protected section,
 and a get and set function for that variable should be made.

 There might be a nicer way to do this, but it does work.
*/

class GameObject {
protected:
	float x;
	float y;

	float vx;
	float vy;

	float size;
		
public:
	virtual void update() = 0;
	virtual void getInput(char _i, int cli) = 0;
	virtual void draw(Display d) = 0;
	void printvals() {
		cout << this->x << "," << this->y << " " << this->vx << "," << this->vy << endl;
	}
	float get_x() {
		return this->x;
	}
	float get_y() {
		return this->y;
	}
	void set_x(float _x) {
		this->x = _x;
	}
	void set_y(float _y) {
		this->y = _y;
	}
	float get_vx() {
		return this->vx;
	}
	float get_vy() {
		return this->vy;
	}
	void set_vx(float _vx) {
		this->vx = _vx;
	}
	void set_vy(float _vy) {
		this->vy = _vy;
	}
	float get_size(){
		return this->size;
	}
	void set_size(float _s){
		this->size = _s;
	}
};

vector<GameObject*> objs; //These are the vectors that all the GameObject pointers live in, aas well as the one 
vector<GameObject*> delete_queue; // that handles deletion.

#endif