#ifndef BJ_H
#define BJ_H

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<fstream>
using namespace std;

struct carta{
int cod;
string nome;
string seme;
int val;
};

class bj{
private:
	carta mazzo[52];
	int mbanc[7],mplay[7];
	void rmdp(int,int&);
public:
	bj();
	int n[12];
	void banco(char);
	void dmazzo();
	void dplayer(int,char);
	void dbanco(int,char);
	int vplay(int);
	void addcardp(int);
	int vbanc(int);
	void addcardb(int,int);
	bool fxap (int);
	bool fxab (int);
};

#endif
