#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <math.h>
#include <time.h>


using namespace std;

const int size = 50;
const int mutation = 500; // x/1000000 chance.
const int submutation = 1500; // x/1000000 chance.
const int pcross = 600;

int leng = size;
char answer[size];
const int maxpop = 10*size;
int maxgeneration = 1000 * maxpop; 
char pop[maxpop][size];
char newpop[maxpop*2][size];
int fitness[maxpop];
int newfitness[maxpop*2];
int gen = 0;
int scorecoef = 10;
int sumfitness = 0;
void Initialize(){
	srand(time(NULL));
}

void Populate(){
	for (int i = 0;i < maxpop;i++){
		if (pop[i][0] == 0){
			for (int w = 0;w<leng;w++){
				if (rand()%2){
					pop[i][w] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[rand()%26];
				}else{
					pop[i][w] = "abcdefghijklmnopqrstuvwxyz"[rand()%26];
				}
			}
		}
	}
}
void Evaluate(int x){
	int score = 0;
	int fit = 0;
	for (int i = 0;i < leng;i++) {
		if (pop[x][i] == answer[i]) score = score + 1;
	}
	fit = score * score * scorecoef;
	fitness[x] = fit;
}

void EvalPop(){
	sumfitness = 0;
	for (int i =0;i<maxpop;i++){
		Evaluate(i);
	}
	for (int i = 0;i <maxpop; i++){
		sumfitness = sumfitness + fitness[i];
	}
}

void Transfer(){
	int place = 0;
	for (int i =0;i<maxpop;i++){
		if (fitness[i] > 0){
			for (int w = 0;w<leng;w++){
				newpop[place][w] = pop[i][w];
			}
			newfitness[place] = fitness[i];
			place++;
		}
	}
}
int Select(){
	int sel;
	int acc = 0;
	//int bar = rand()%sumfitness;
	while (acc < sumfitness) {
		sel = rand()%maxpop;
		acc += fitness[sel];
	}
	return sel;
}

void Crossover(){
	int m;
	int Parentx = Select();
	int Parenty = Select();
	int crossover;
	int place = 0;
	for (int i = 0;i< maxpop;i++){
		if (newpop[i][0] == 0) {
			place = i;
			break;
		}
	}

		
	if (1+rand()%1000 < pcross) {
		for (int i = 0; i < 1+rand()%5;i++){
			crossover = 1+rand()%(leng);
			for (int w = 0;w<leng;w++){
				if (w < crossover){
					newpop[place][w] = newpop[Parentx][w];
				} else {
					newpop[place][w] = newpop[Parenty][w];
				}
			}
		}
	} else {
				for (int w = 0;w<leng;w++){
					newpop[place][w] = newpop[Parentx][w];
				} 
			
				for (int w = 0;w<leng;w++){
					newpop[place+1][w] = newpop[Parenty][w];
				}
	}

	for (int i = 0;i<leng;i++){
		if (1+rand()%1000000 < submutation) {
			if ((rand()%100)>50){
				newpop[place][i] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[rand()%26];
			}else{
				newpop[place][i] = "abcdefghijklmnopqrstuvwxyz"[rand()%26];
			}
		}
	}
}
void Reproduction(){
	for (int i = 0;i<maxpop;i++){
		/*if (newfitness[i] > 0)*/ Crossover();
	}
}

void NextGen(){
	int place = 0;
	for (int i = 0;i < maxpop;i++){
			pop[i][0] = 0;
	}
	for (int i = 0;i < maxpop*2;i++){
		if (newfitness[i] == 0) {
			for (int w = 0;w < leng;w++){
				pop[place][w] = newpop[i][w];
			}
			place++;
		}
	}
	for (int i = 0;i < maxpop*2;i++){
			newpop[i][0] = 0;
	}
}

int Test(){
	for (int i = 0;i<maxpop;i++){
		if (fitness[i] >= leng*leng*scorecoef) {
			return i;
		}
	}
	return 0;
}

void Print(){
	cout << "POPULATION: " << endl;
	for (int i = 0;i<maxpop;i++){
		if (pop[i][0] != 0){
			cout << setw(3) << i << ":";
			for (int w = 0;w<leng;w++){
				cout << pop[i][w];
			}
			cout << ":"; 
			cout << setw(3) <<fitness[i];
			cout << "| ";
			if (i > 0 && i % 2 == 0) cout << endl;
		}
	}
	cout << endl;
	
	
}

void PrintBest(){
	int best = 0;
	int sum = 0;
	cout << "BEST: ";
	for (int i = 0;i<maxpop;i++){
		if (best < fitness[i]) best = i;
	}
	cout << setw(3) << best << ": ";
	for (int w = 0;w<leng;w++){
		cout << pop[best][w];
	}
	cout << "   ";
	cout << setw(2) << sqrt(fitness[best]/scorecoef) << "/" << setw(2) <<leng<< "  ";
	
	cout << "SUM: " << sumfitness <<" GEN: " << gen <<"|" << maxgeneration;
	/*for (int i = 0; i < fitness[best];i++){
		cout << "*";	
	}*/
	cout << endl;
}

void NewPrint(){
	cout << "GENE POOL" << endl;
	for (int i = 0;i<maxpop;i++){
		if (newpop[i][0] != 0){
		cout << setw(3) << i << ":";
		for (int w = 0;w<leng;w++){
			cout << newpop[i][w];
		}
		cout << ":"; 
		cout << setw(3) << newfitness[i];
		cout << " ";
		if (i > 0 && i % 10 == 9) cout << endl;
		}
	}
	cout << endl;
}

main (){
	cout.precision(5);
	string passphrase;
	cout << "Enter passphrase less than " << leng << " characters long: ";
	cin >> passphrase;
	leng = passphrase.length();
    passphrase.copy(answer, leng);
	int test;
	Initialize();
	while (gen < maxgeneration) {
	test = 0;
	Populate();
	EvalPop();
	Transfer();
	Reproduction();	
	NextGen();
	Populate();
	EvalPop();
	PrintBest();
	test = Test();
	
	if (test != 0) {
		Print();
		cout << "Got it in " << gen * maxpop-1 + test << " tries this attempt by generation " << gen << "." << endl;
		cout << "It's at location " << test << "." << endl;
		cout << "A totally random combination of letters of your phrases length would have a 1/" << pow(52,leng) << " chance of being correct." << endl;
		cout << "The chance a random series of attempts got it as fast as I did are: %" << (gen * maxpop-1 + test) / pow(52,leng) << endl;
		break;
	}
	
	gen++;
	}
	return 0;
}

