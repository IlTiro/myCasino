#ifndef ROULETTE_H
#define ROULETTE_H

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<fstream>
using namespace std;

struct nr{
int n;
string colore;
};

class roulette{
private:
	nr num[37];
	int n;
	string color(int);
public:
	roulette();
	int getn(){return n;}
	string getcol(int i){return num[i].colore;}
};

roulette::roulette(){
srand((unsigned)time(NULL));
for(int i=0;i<37;i++){
num[i].n=i;
num[i].colore=color(i);
}
n=rand()%37;
}

#endif
