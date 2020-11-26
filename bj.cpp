#include "bj.h"
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<fstream>
using namespace std;

bj::bj(){
for(int i=0;i<52;i++)
mazzo[i].cod=i;

for(int i=0;i<13;i++)
mazzo[i].seme="cuori";
for(int i=13;i<26;i++)
mazzo[i].seme="quadri";
for(int i=26;i<39;i++)
mazzo[i].seme="fiori";
for(int i=39;i<52;i++)
mazzo[i].seme="picche";


for(int i=0;i<52;i++)
switch(i%13){
case 0: mazzo[i].nome="A"; mazzo[i].val=11;break;
case 1: mazzo[i].nome="2"; mazzo[i].val=2;break;
case 2: mazzo[i].nome="3"; mazzo[i].val=3;break;
case 3: mazzo[i].nome="4"; mazzo[i].val=4;break;
case 4: mazzo[i].nome="5"; mazzo[i].val=5;break;
case 5: mazzo[i].nome="6"; mazzo[i].val=6;break;
case 6: mazzo[i].nome="7"; mazzo[i].val=7;break;
case 7: mazzo[i].nome="8"; mazzo[i].val=8;break;
case 8: mazzo[i].nome="9"; mazzo[i].val=9;break;
case 9: mazzo[i].nome="10"; mazzo[i].val=10;break;
case 10: mazzo[i].nome="J"; mazzo[i].val=10;break;
case 11: mazzo[i].nome="Q"; mazzo[i].val=10;break;
case 12: mazzo[i].nome="K"; mazzo[i].val=10;break;
}


srand((unsigned)time(NULL));
for(int i=0;i<12;i++)
n[i]=rand()%52;
for(int i=0;i<11;i++)
for(int j=i+1;j<12;j++)
rmdp(n[i],n[j]);

for(int i=0;i<7;i++)
mbanc[i]=-1;
mbanc[0]=n[0];
mbanc[1]=n[1];

for(int i=0;i<7;i++)
mplay[i]=-1;
mplay[0]=n[2];
mplay[1]=n[3];
}

void bj::rmdp(int a1,int& b2){
if(a1==b2) {b2++;}
}

void bj::banco(char l){
string ings;
switch(l){
case 'i':	cout<<endl<<"				<<<BANCO>>>"<<endl;
			cout<<endl<<"			      Carta nascosta";
			cout<<endl<<"				 "<<mazzo[mbanc[1]].nome<<" "<<mazzo[mbanc[1]].seme;
			break;

default:	if     (mazzo[mbanc[1]].seme=="cuori") ings="hearts";
			else if(mazzo[mbanc[1]].seme=="quadri") ings="diamonds";
			else if(mazzo[mbanc[1]].seme=="fiori") ings="clubs";
			else								ings="spades";
			cout<<endl<<"				<<<HOUSE>>>"<<endl;
			cout<<endl<<"			        Hidden Card";
			cout<<endl<<"				 "<<mazzo[mbanc[1]].nome<<" "<<ings;
			break;
}
}

void bj::dplayer(int c,char l){
string ings;
switch(l){
case 'i':	cout<<endl<<endl<<"			     <<<LA TUA MANO>>>"<<endl;
			for(int i=0;i<c;i++)
			cout<<endl<<"				 "<<mazzo[mplay[i]].nome<<" "<<mazzo[mplay[i]].seme;
			break;

default:	cout<<endl<<endl<<"			      <<<YOUR CARDS>>>"<<endl;
			for(int i=0;i<c;i++){
			if     (mazzo[mplay[i]].seme=="cuori") ings="hearts";
			else if(mazzo[mplay[i]].seme=="quadri") ings="diamonds";
			else if(mazzo[mplay[i]].seme=="fiori") ings="clubs";
			else								ings="spades";
			cout<<endl<<"				 "<<mazzo[mplay[i]].nome<<" "<<ings;
			}
			break;
}
}

void bj::dbanco(int c,char l){
string ings;
switch(l){
case 'i':	cout<<endl<<endl<<"				<<<BANCO>>>"<<endl;
			for(int i=0;i<c;i++)
			cout<<endl<<"				 "<<mazzo[mbanc[i]].nome<<" "<<mazzo[mbanc[i]].seme;
			break;

default:	cout<<endl<<endl<<"				<<<HOUSE>>>"<<endl;
			for(int i=0;i<c;i++){
			if     (mazzo[mbanc[i]].seme=="cuori") ings="hearts";
			else if(mazzo[mbanc[i]].seme=="quadri") ings="diamonds";
			else if(mazzo[mbanc[i]].seme=="fiori") ings="clubs";
			else								ings="spades";
			cout<<endl<<"				 "<<mazzo[mbanc[i]].nome<<" "<<ings;
			}
			break;
}
}

void bj::dmazzo(){
for(int i=0;i<52;i++)
cout<<mazzo[i].cod<<"  "<<mazzo[i].nome<<"  "<<mazzo[i].seme<<"  "<<mazzo[i].val<<endl;
}

int bj::vplay(int c){
int v=0;
for(int i=0;i<c;i++)
v+=mazzo[mplay[i]].val;
return v;
}

void bj::addcardp(int c){
mplay[c]=n[c+2];
}

int bj::vbanc(int c){
int v=0;
for(int i=0;i<c;i++)
v+=mazzo[mbanc[i]].val;
return v;
}

void bj::addcardb(int cb,int cp){
mbanc[cb]=n[cp+cb];
}

bool bj::fxap(int c){
bool tf=false;
for(int i=0;i<c;i++)
if(mplay[i]==0 || mplay[i]==13 || mplay[i]==26 || mplay[i]==39)
if(mazzo[mplay[i]].val==1) continue;
else{
mazzo[mplay[i]].val=1;
tf=true;
}
return tf;
}

bool bj::fxab(int c){
bool tf=false;
for(int i=0;i<c;i++)
if(mbanc[i]==0 || mbanc[i]==13 || mbanc[i]==26 || mbanc[i]==39)
if(mazzo[mbanc[i]].val==1) continue;
else{
mazzo[mbanc[i]].val=1;
tf=true;
}
return tf;
}
