#include "roulette.h"
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<fstream>
using namespace std;
string roulette::color(int i){
if(i==0) return "green";
if(1<=i<=10)
	if(i%2==0) return "black";
	else return "red";
if(11<=i<=18)
	if(i%2==0) return "red";
	else return "black";
if(19<=i<=28)
	if(i%2==0) return "black";
	else return "red";
if(29<=i<=36)
	if(i%2==0) return "red";
	else return "black";
}
