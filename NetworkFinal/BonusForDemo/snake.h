#include "console_graphics.h"

class SnakeHead: public GameObject {
public:
	int team;
	int dir;
	char val;
	int timer;
	int d_timer;
	int length;
	
	int body_x[50];
	int body_y[50];

	SnakeHead(int _t,char _v) {
		length = 2;
		team = _t;
		val = _v;
		d_timer = 10;
		timer = d_timer;
		if (team == 0) {
			x = 4;
			y = 1;
			dir = 1;
		} else if (team == 1) {
			x = dwidth - 5;
			y = dheight - 2;
			dir = 3;
		}
		for (int i = 1; i < 50; i++) {
			body_x[i] = -1;
			body_y[i] = -1;
		}
		body_x[0] = x-1;
		body_x[1] = x-2;
		body_y[0] = y;
		body_y[1] = y;
	}

	virtual void getInput(char _i, int cli) {
		char input = _i;
		if (cli == team) {
			switch (input) {
				case 'w':
					moveBody();
					y -= 1;
					dir = 0;
					
				break;
				case 's':
					moveBody();
					y += 1;
					dir = 2;
					
				break;
				case 'a':
					moveBody();
					x -= 1;
					dir = 3;
					
				break;
				case 'd':
					moveBody();
					x += 1;
					dir = 1;
					
				break;
			}
		}
	};

	virtual void update() {
		timer--;
		if (timer == 0) {
			moveBody();
			switch (dir) {
				case 0:
					y -= 1;
				break;
				case 2:
					y += 1;
				break;
				case 3:
					x -= 1;
				break;
				case 1:
					x += 1;
				break;
			}
			
		}
	}

	virtual void draw(Display d) {
		d.point(round(x),round(y),val);
		for (int i = 0; i < length; i++) {
			d.point(round(body_x[i]),round(body_y[i]),val);
		}
	}

	void moveBody() {
		timer = d_timer;

		for (int i = 1; i < 50; i++) {
			if ((x == body_x[i]) && (y == body_y[i])){
				length = 2;
				if (team == 0) {
					x = 4;
					y = 1;
					dir = 1;
				} else if (team == 1) {
					x = dwidth - 5;
					y = dheight - 2;
					dir = 3;
				}
				for (int i = 1; i < 50; i++) {
					body_x[i] = -1;
					body_y[i] = -1;
				}
				body_x[0] = x-1;
				body_x[1] = x-2;
				body_y[0] = y;
				body_y[1] = y;
			}
		}


		GameObject * f = objs[2];
		float b_x = f->get_x();
		float b_y = f->get_y();

		if ((x == b_x) && (y == b_y)) {
			length += 2;
			f->set_x(2 + rand() % dwidth - 3);
			f->set_y(2 + rand() % dheight - 3);
		}

		for (int i = 49; i > 0 ; i--) {
			body_x[i] = body_x[i-1];
			body_y[i] = body_y[i-1];
		}
		body_x[0] = x;
		body_y[0] = y;
	}
};

class Food: public GameObject {
public:
	char val;

	Food(char _v) {
		x = dwidth/2;
		y =  dheight/2;
		val = _v;
	}

	virtual void getInput(char _i, int cli) {};

	virtual void update() {
	}

	virtual void draw(Display d) {
		d.point(round(x),round(y),val);
	}

};
