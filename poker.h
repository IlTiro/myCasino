#ifndef POKER_H
#define POKER_H

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<fstream>

using namespace std;

struct cart{
int cod;
string nome;
string seme;
int val;
};

struct player{
int ps;
int c1;
int c2;
float p;
int vm;
int kik;
};

class poker
{
private:
	int nplyr;
	float sb,bb;
	char l;
	int card[52];
	cart mazzo[52];
	int common[5];
	player plyr[9];
	bool ofpunt(float);
	void ofvinc(float);
	player plyrch(player,bool&);
	player swrisp(player,string,bool&);
	player swrisb(player,string,float,int,bool&);
	player preflop(player,int,bool&,int);
	player flop(player,int,bool&,int);
	player river(player,int,bool&,int);
	player turn(player,int,bool&,int);
	player swrisb(player,string,bool&);
	void clacvinc();
	player showdown(player,int);
	void dmano(cart[],int,player);
	int calcvm(cart[],int,player&);
	int calckik(cart[],int);
	void vinc(player,int,float,int);
public:
	poker(char);
	float maxp;
	int rim=0;
	bool sbb(float,float,int,int&,int&);
	void dflop();
	void drivr();
	void dturn();
	bool ctrlpunt();
	void punt(int,int,bool&,int);
	int contrim();
	float calpot(float);
	void win(float);
	void sd(int);
	void calcwin(float);
};

#endif
