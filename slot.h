#ifndef SLOT_H
#define SLOT_H

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<fstream>
using namespace std;

class slot{
	private:
		int n1;
		int n2;
		int n3;
		int n4;
		
	public:
		slot();
		void setn1(int v){n1=v;}
		void setn2(int v){n2=v;}
		void setn3(int v){n3=v;}
		void setn4(int v){n4=v;}
		int getn1(){return n1;}
		int getn2(){return n2;}
		int getn3(){return n3;}
		int getn4(){return n4;}
};

#endif
