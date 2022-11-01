#include "console_graphics.h"

class Particle: public GameObject {
public:
	float grav;
	float fric;

	int life;
	char val;


	Particle(int _x, int _y, int _l,char _v) {
		x = _x;
		y = _y;
		vx = ((rand() % 10) - 5) * .5;
		vy = ((rand() % 10) - 5) * .5;
		grav = 0.05;
		fric = .97;
		life = _l;
		val = _v + rand() % 3;
	}

	virtual void getInput(char _i, int cli) {};

	virtual void update() {
		x += vx;
		y += vy;
		vy += grav;

		vx *= fric;
		vy *= fric;

		life--;
		if (life == 0) {
			delete_queue.push_back(this);
		}
	}

	virtual void draw(Display d) {
		d.point(round(x),round(y),val);
	}
};


class Ball: public virtual GameObject {
public:
	float grav;
	float fric;
	float restitution;

	char val;

	virtual void getInput(char _i, int cli) {
		char input = _i;
		if (input != ' ') {
			switch (input) {
				case 'f':
					explode();
				break;
			}
		}
	}

	virtual void update() {
		


		if ((y + vy >= (dheight-1) - ceil(size/2)) || (y + vy <= 0 + ceil(size/2))) {
			vy = -vy * restitution;
		}
		if ((x + vx >= (dwidth-1) - ceil(size/2)) || (x + vx <= 0 + ceil(size/2))) {
			vx = -vx * restitution;
		}


		if ((x+vx < 4)){
			for (int i = 0; i < 50; i++) {
				GameObject * p = new Particle((int)x,(int)y, 50 + rand() % 60, '2'); 
				objs.push_back(p);
			}
			x = dwidth/2;
			y = dheight/2;
			int dir = rand() % 1000 - 500;
			vx = 2 * (dir > 0) - (dir < 0);
			vy = 0;
			//explode();
		}
		
		if ((x+vx > dwidth - 5)){
			for (int i = 0; i < 50; i++) {
				GameObject * p = new Particle((int)x,(int)y, 50 + rand() % 60, '2'); 
				objs.push_back(p);
			}
			x = dwidth/2;
			y = dheight/2;
			int dir = rand() % 1000 - 500;
			vx = 2 * (dir > 0) - (dir < 0);
			vy = 0;

			//explode();
		}
		

		x += vx;
		y += vy;
		vy += grav;

		vx *= fric;
		vy *= fric;

		/*if (abs(vx) < 0.01) {
			vy -= 0.3;
			if (y < 10) {
				explode();
			}
		}*/
	}

	void explode() {
		for (int i = 0; i < 50; i++) {
			GameObject * p = new Particle((int)x,(int)y, 50 + rand() % 60, '2'); 
			objs.push_back(p);
		}
		int dir = rand() % 1000 - 500;
		vx = 2 * (dir > 0) - (dir < 0);
		vy = 0;
		x = dwidth/2;
		y = dheight/2;
		//delete_queue.push_back(this);
	}

	Ball(int _x, int _y, float _s, char _v) {
		x = _x;
		y = _y;
		size = _s;
		int dir = rand() % 1000 - 500;
		vx = 2 * (dir > 0) - (dir < 0);
		vy = 0;
		grav = 0.0;
		fric = 1.0;
		restitution = 1;
		val = _v;
	}

	virtual void draw(Display d) {
		d.circle(round(x),round(y),size,val,true);
	}
};

class Paddle: public GameObject {
public:
	float fric;

	int team;

	int height;
	char val;

	virtual void getInput(char _i,int cli) {
		char input = _i;
		if (cli == team) {
			switch (input) {
				case 'w':
					y -= 3;
				break;
				case 's':
					y += 3;
				break;
			}
		}
	}

	virtual void update() {
		if ((y + vy >= (dheight-1) - height) || (y + vy <= 0 + height)) {
			vy = -vy * 0.01;
		}

		GameObject * b = objs[0];
		float b_x = b->get_x();
		float b_y = b->get_y();
		float b_vx = b->get_vx();
		float b_vy = b->get_vy();
		float b_size = b->get_size();
		
		if (round(b_x + b_vx + b_size/2) > x-1 && round(b_x + b_vx - b_size/2) < x+1 && b_y < y + height && b_y > y - height) {
			b->set_vx(-b->get_vx());
			b->set_vy(rand() % 4 - 2);
		}
		
		x += vx;
		y += vy;

		vx *= fric;
		vy *= fric;
	}

	virtual void draw(Display d) {
		d.line(x-1,y-height+1,x-1,y+height-1,val);
		d.line(x,y-height,x,y+height,val);
		d.line(x+1,y-height+1,x+1,y+height-1,val);
	}

	Paddle(int _x, int _y, int _team, char _v) {
		x = _x;
		y = _y;
		team = _team;
		height = 5;
		val = _v;
		fric = 1;
	}
};