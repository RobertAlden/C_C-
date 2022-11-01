#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <math.h>
using namespace std;

void print(int a, int b){}

main(){
	srand (time(NULL));
	string passphrase;
	string display;
	int max = 100;
	char answer[8];
	cout << "Enter passphrase less than 8 characters long: ";
	cin >> passphrase;
	cout << "Display Attempts and progress?: Y/N ";
	cin >> display;
	int leng = passphrase.length();
	passphrase.copy(answer, 8);
	char population[max][leng+1];
	char nextpop[max][leng+1];
	int generation = 0;
	int score = 0;
	int best = 0;
	int pos;
	int success =0;
	int sum = 0;
	int sim;
	int mean;
	int cross;
	for (int i = 0; i < max; i++){
		for (int w = 0;w<leng+1;w++){
				nextpop[i][w] = 32;
		}
	}
	for (int i = 0; i < max; i++){
		for (int w = 0;w<leng+1;w++){
				population[i][w] = 48;
		}
	}
	while (generation < 100000){
		score = 0;
		if (generation >= 0) {
			for (int i = 0; i < max; i++){
				population[i][0] = 48;
			}
		}
		
		for (int i = 0; i < max; i++){
			for (int w = 0;w<leng;w++){
				if (population[i][0] == 48){
					if ((1+rand()%2) == 1){				
				
						population[i][w+1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[rand()%26];
				
					}else{
					
						population[i][w+1] = "abcdefghijklmnopqrstuvwxyz"[rand()%26];
				
					}
				}
			}
		}
		if (generation > 0){
			for (int i = 0; i < max; i=i+3){
				for (int q = 0;q< max;q++) {
					if (nextpop[q][0] == 42){
						for (int w=0;w<leng;w++){
							population[i][w+1] = nextpop[q][w+1];
						
						}
						population[i][0] = 48;	
						nextpop[q][0] = 32;
						break;
					}
				}
			}
		}
		for (int i = 0; i < max; i++){
			for (int w = 0;w<leng;w++){
				if (population[i][w+1] == answer[w]) population[i][0] += 1;
			}
		}
		best = 0;
		for (int i = 0; i < max; i++){
			if (population[i][0]-48 > score){
				score = population[i][0]-48;
				best = i;
			}
		}
		pos = 0;
		
		for (int i = 0; i < max; i++){
			if ((population[i][0]-48) > 0){
				
					nextpop[pos][0] = population[i][0];
					
				for (int w = 0;w<leng;w++){
						
					nextpop[pos][w+1] = population[i][w+1];
					
				}
				
				pos++;
			}
		}
		if (display == "Y")
		{
		cout << "Raw Population:" << endl;
		for (int i = 0; i < max; i++){
			if (i % 10 == 0) {
				cout << "\n" <<"line " << i << ": ";
				
			}
			if (i == 0) cout<< " ";
			for (int w = 0;w<leng;w++)
			{
				cout << population[i][w+1];
			}
			cout << ":" << population[i][0];
			cout << " ";
		}
		cout << endl;
		cout << "Best scores of population:" << endl;
		for (int i = 0; i < max; i++){
			if (nextpop[i][0] != 32){
				if (i % 10 == 0) {
					cout << "\n" <<"line " << i << ": ";
				
				}
				if (i == 0) cout<< " ";
			
				for (int w = 0;w<leng;w++)
				{
					cout << nextpop[i][w+1];
				}
			
				cout << ":" << nextpop[i][0];
				cout << " ";
			}
		}
		cout << endl;
		cout << "Best match of generation #" << generation <<" is " << score << "/" << leng << " at "<< best << "." << endl;
		
		
		cout << "Beginning reproduction: " << endl;
		}
		success = 0;
		for (int i = 0; i < max; i++){
			if (population[i][0] > 48){
				success++;
				
			}
		}
		sum = 0;
		for (int i = 0; i < max; i++){
			sum += (population[i][0] - 48);
		}
		mean = sum / success;
		for (int i = 0; i < max; i=i+2){
			if (nextpop[i][0] > 48 && nextpop[i][0]-48 > mean){
				if (nextpop[i+1][0] > 48){
					for (int r=0;(r<nextpop[i][0]-48);r++){
					switch (rand()% 7){
					case 0:
					cross = 1 + rand()%leng;
					for (int w = 0;w<leng;w++){
						if (w < cross) {
							nextpop[pos][w+1] = nextpop[i][w+1];
						} else {
							nextpop[pos][w+1] = nextpop[i+1][w+1];
						}
					}
					nextpop[pos][0] = 42;
					if (pos < max) pos++;
					break;
					case 1:
					for (int w = 0;w<leng;w++){
						if (w % 2 == 0) {
							nextpop[pos][w+1] = nextpop[i][w+1];
						} else {
							nextpop[pos][w+1] = nextpop[i+1][w+1];
						}
					}
					nextpop[pos][0] = 42;
					if (pos < max) pos++;
					break;
					case 2:
					cross = 1 + rand()%leng;
					for (int w = 0;w<leng;w++){
						if (w < cross) {
							nextpop[pos][w+1] = nextpop[i+1][w+1];
						} else {
							
							nextpop[pos][w+1] = nextpop[i][w+1];
						}
					}
					nextpop[pos][0] = 42;
					if (pos < max) pos++;
					break;
					case 3:
					for (int w = 0;w<leng;w++){
						if (w % 2 == 0) {
							nextpop[pos][w+1] = nextpop[i+1][w+1];
						} else {
							
							nextpop[pos][w+1] = nextpop[i][w+1];
						}
					}
					nextpop[pos][0] = 42;
					if (pos < max) pos++;
					break;
					case 4:
					for (int w = 0;w<leng;w++){
						if (w == 0 || w == leng) {
							nextpop[pos][w+1] = nextpop[i+1][w+1];
						} else {
							
							nextpop[pos][w+1] = nextpop[i][w+1];
						}
					}
					nextpop[pos][0] = 42;
					if (pos < max) pos++;
					break;
					case 5:
					for (int w = 0;w<leng;w++){
						if (w == 0 || w == leng) {
							nextpop[pos][w+1] = nextpop[i][w+1];
						} else {
							nextpop[pos][w+1] = nextpop[i+1][w+1];
							
						}
					}
					nextpop[pos][0] = 42;
					if (pos < max) pos++;
					break;
					case 6:
					int n = (1+rand()% leng);
					nextpop[pos][n] = nextpop[pos][n]++;
					break;					
					}
					}
				}
					
			}
		}	
		
		if (display == "Y") {
		cout << "Children of successful attempts: " << endl;
		for (int i = 0; i < max; i++){
			if (nextpop[i][0] != 32){
				if (i % 10 == 0) {
					cout << "\n" <<"line " << i << ": ";
				}
				if (i == 0) cout<< " ";
			
				for (int w = 0;w<leng;w++)
				{
					cout << nextpop[i][w+1];
				}
			
				cout << ":" << nextpop[i][0];
				cout << " ";
			}
		}
		cout << endl;
		}
		
		cout << "----------G:" << generation << "-------B:"<< score << "/" << leng << "-------M:"<< mean <<"---------S:"<< sum << "--------" <<endl;
		if (score == leng){
				cout << "Match found after " << generation << " generations." << endl;
			if (display == "N" || display == "Y") {
				for (int i = 0; i < max; i++){
			if (i % 10 == 0) {
				cout << "\n" <<"line " << i << ": ";
				
			}
			if (i == 0) cout<< " ";
			for (int w = 0;w<leng;w++)
			{
				cout << population[i][w+1];
			}
			cout << ":" << population[i][0];
			cout << " ";
		}
		
		cout << endl;
		cout << "Best match of generation #" << generation <<" is " << score << "/" << leng << " at "<< best << "." << endl;
		cout << "Total possible random assemblies of letters with your word's length: " << pow(52,leng) << endl;
		cout << "I found it using a procedural algorithm in approximately " << generation * max << " tries." << endl;
		cout << "I took " << ((generation * max) / pow(52,leng) )*100 << "% of the attempts that random generation would." << endl;
			}
			break;
		}
		generation++;
		//cin.get();
		
	}
	return 0;
}
