#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<fstream>

#include "bj.h"
#include "roulette.h"
#include "slot.h"
using namespace std;

//1----------------------------------------------------
int menu(char);
int match(int []);
void result(float,int,char);
float slotmenu(char);
float slotpunt(int,char);
bool ofpunt(float);
void ofvinc(float,char);
//2----------------------------------------------------
float roulmenu(char);
float roulpunt(int,char);
char roulgame(char);
void estr(roulette);
void switchgame(float,char,roulette,char);
int insn(char);
bool roulm(int,roulette);
int scdoz(char);
bool mdoz(int,roulette);
string scrn(char);
bool mrn(string,roulette);
string scpd(char);
bool mpd(string,roulette);
string scab(char);
bool mab(string,roulette);
//3----------------------------------------------------
float bjmenu(char);
string com(char);
//void psballo(char);
//void bsballo(float,char);		TUTTI IN
//void lose(char);				LANGUAGE
//void draw(float,char);
//void win(float,char);
float bjpunt(int,char);
//4----------------------------------------------------
int addbbi(int,int);
int refreshd(int,int);
//5----------------------------------------------------
float pokermenu(char);
float pkpunt(int,char);
bool readp(float&);
bool readv(float&);
//6----------------------------------------------------
bool resetp();
bool resetv();


//language----------------------------------------------------
void errorvinc(char);
void nvalidch(char);
void lanmenu(char);
void lanslotmenu(char);
void punt(char);
void ruleslot(char);
void ansplay(char);
void lanroulmenu(char);
void lanroulpunt(char);
void lanroulgame(char);
void laninsn(char);
void lanscdoz(char);
void lanscrn(char);
void lanscpd(char);
void lanscab(char);
void lanbjmenu(char);
void lanbjpunt(char);
void lancom(char);
void lanpokermenu(char);
void lanblind(char);
void pkrules(char);

//slot--------------------------------------------------------------------------------------------------------------

int menu(char l){
int s;
lanmenu(l);
cin>>s;
return s;
}

float slotmenu(char l){
int slot;
float p;
lanslotmenu(l);
cin>>slot;
p=slotpunt(slot,l);
return p;
}

float slotpunt(int ss,char l){
string ans;
float p;
switch(ss){
case 1: punt(l);
		cin>>p;
		break;
		
case 2: ruleslot(l);
		do{
		ansplay(l);
		cin>>ans;
		}while(ans!="si" && ans!="yes" && ans!="y" && ans!="no");
		if(ans=="si" || ans=="yes" || ans=="y"){
		punt(l);
		cin>>p;
		}
		else return 0;
		break;
		
case 0: return 0;
		break;
		
default: nvalidch(l); break;
}
return p;
}

void result(float p,int c,char l){
switch(l){
case 'i':	if(c==6) {cout<<endl<<"COMPLIMENTI HAI OTTENUTO 4 NUMERI UGUALI HAI VINTO "<<p*200<<" EURO"; ofvinc(p*200,l);}
			else if(c==3) {cout<<endl<<"COMPLIMENTI HAI OTTENUTO 3 NUMERI UGUALI HAI VINTO "<<p*7.5<<" EURO"; ofvinc(p*7.5,l);}
			else if(c==2) {cout<<endl<<"COMPLIMENTI HAI OTTENUTO 2 COPPIE DI NUMERI UGUALI HAI VINTO "<<p*10<<" EURO"; ofvinc(p*10,l);}
			else if(c==1) {cout<<endl<<"COMPLIMENTI HAI OTTENUTO UNA COPPIA DI NUMERI UGUALI HAI VINTO "<<p*1.5<<" EURO"; ofvinc(p*1.5,l);}
			else cout<<endl<<"RITENTA SARAI PIU FORTUNATO";
			break;
			
default:	if(c==6) {cout<<endl<<"CONGRATULATIONS YOU GOT 4 EQUAL NUMBERS YOU WON "<<p*200<<" POUNDS"; ofvinc(p*200,l);}
			else if(c==3) {cout<<endl<<"CONGRATULATIONS YOU GOT 3 EQUAL NUMBERS YOU WON "<<p*7.5<<" POUNDS"; ofvinc(p*7.5,l);}
			else if(c==2) {cout<<endl<<"CONGRATULATIONS YOU GOT 2 COUPLES OF EQUAL NUMBERS YOU WON "<<p*10<<" POUNDS"; ofvinc(p*10,l);}
			else if(c==1) {cout<<endl<<"CONGRATULATIONS YOU GOT A COUPLE OF EQUAL NUMBERS YOU WON "<<p*1.5<<" POUNDS"; ofvinc(p*1.5,l);}
			else cout<<endl<<"RETRY YOU WILL BE MORE LUCKY";
			break;
}
}

int match(int vett[]){
int c=0;
for(int i=0;i<3;i++)
	for(int j=i+1;j<4;j++)
		if(vett[i]==vett[j])
		c++;
cout<<endl;
cout<<endl<<"		"<<vett[0]<<"		"<<vett[1]<<"		"<<vett[2]<<"		"<<vett[3];
cout<<endl;
return c;
}

bool ofpunt(float p){
ofstream on("data\\puntate.txt", ios::out | ios::app);
if(!on.good()) return false;
on<<p<<endl;
on.clear();
on.close();
return true;
}

void ofvinc(float v,char l){
ofstream on("data\\vincite.txt", ios::out | ios::app);
if(!on.good()) errorvinc(l);
on<<v<<endl;
on.clear();
on.close();
}

//roulette-----------------------------------------------------------------------------------------------------------

float roulmenu(char l){
int roul;
float p;
lanroulmenu(l);
cin>>roul;
p=roulpunt(roul,l);
return p;
}

float roulpunt(int rs,char l){
string ans;
float p;
switch(rs){
case 1: punt(l);
		cin>>p;
		break;
		
case 2: lanroulpunt(l);
		do{
		ansplay(l);
		cin>>ans;
		}while(ans!="si" && ans!="yes" && ans!="y" && ans!="no");
		if(ans=="si" || ans=="yes" || ans=="y"){
		punt(l);
		cin>>p;
		}
		else return 0;
		break;
		
case 0: return 0;
		break;
		
default: nvalidch(l); break;
}
return p;
}

char roulgame(char l){
char s;
do{
lanroulgame(l);
cin>>s;
}while(s!='a' && s!='b' && s!='c' && s!='d' && s!='e' && s!='f' && s!='g' && s!='h' && s!='i' && s!='o');
return s;
}

void estr(roulette r,char l){
string color;
cout<<endl<<"				"<<r.getn();
color=r.getcol(r.getn());
switch(l){
case 'i':	if(color=="red") color="rosso";
			else if(color=="black") color="nero";
			else color="verde";
default:	;
}
cout<<"		"<<color<<endl;
}

void switchgame(float p,char g,roulette r,char l){
int va,vb[2],vc[3],vd[4],ve[6];
bool match=false;
int doz;
string rn,pd,ab;
switch (g){

case 'a': 	va=insn(l);
			match=roulm(va,r);
			estr(r,l);
			switch(l){
			case 'i':	if(match) {cout<<endl<<"COMPLIMENTI HAI VINTO "<<p*36<<" EURO"<<endl; ofvinc(p*36,l);} else cout<<endl<<"RITENTA SARAI PIU FORTUNATO"<<endl; break;
			default:	if(match) {cout<<endl<<"CONGRATULATIONS YOU WON  "<<p*36<<" POUNDS"<<endl; ofvinc(p*36,l);} else cout<<endl<<"RETRY YOU WILL BE MORE LUCKY"<<endl; break;
			}
			break;
			
case 'b': 	for(int i=0;i<2;i++)
			vb[i]=insn(l);
			for(int i=0;i<2;i++)
			match=roulm(vb[i],r);
			estr(r,l);
			switch(l){
			case 'i':	if(match) {cout<<endl<<"COMPLIMENTI HAI VINTO "<<p*18<<" EURO"<<endl; ofvinc(p*18,l);} else cout<<endl<<"RITENTA SARAI PIU FORTUNATO"<<endl; break;
			default:	if(match) {cout<<endl<<"CONGRATULATIONS YOU WON  "<<p*18<<" POUNDS"<<endl; ofvinc(p*18,l);} else cout<<endl<<"RETRY YOU WILL BE MORE LUCKY"<<endl; break;
			}
			break;
			
case 'c': 	for(int i=0;i<3;i++)
			vc[i]=insn(l);
			for(int i=0;i<3;i++)
			match=roulm(vc[i],r);
			estr(r,l);
			switch(l){
			case 'i':	if(match) {cout<<endl<<"COMPLIMENTI HAI VINTO "<<p*12<<" EURO"<<endl; ofvinc(p*12,l);} else cout<<endl<<"RITENTA SARAI PIU FORTUNATO"<<endl; break;
			default:	if(match) {cout<<endl<<"CONGRATULATIONS YOU WON  "<<p*12<<" POUNDS"<<endl; ofvinc(p*12,l);} else cout<<endl<<"RETRY YOU WILL BE MORE LUCKY"<<endl; break;
			}
			break;
			
case 'd': 	for(int i=0;i<4;i++)
			vd[i]=insn(l);
			for(int i=0;i<4;i++)
			match=roulm(vd[i],r);
			estr(r,l);
			switch(l){
			case 'i':	if(match) {cout<<endl<<"COMPLIMENTI HAI VINTO "<<p*9<<" EURO"<<endl; ofvinc(p*9,l);} else cout<<endl<<"RITENTA SARAI PIU FORTUNATO"<<endl; break;
			default:	if(match) {cout<<endl<<"CONGRATULATIONS YOU WON  "<<p*9<<" POUNDS"<<endl; ofvinc(p*9,l);} else cout<<endl<<"RETRY YOU WILL BE MORE LUCKY"<<endl; break;
			}
			break;
			
case 'e': 	for(int i=0;i<6;i++)
			ve[i]=insn(l);
			for(int i=0;i<6;i++)
			match=roulm(ve[i],r);
			estr(r,l);
			switch(l){
			case 'i':	if(match) {cout<<endl<<"COMPLIMENTI HAI VINTO "<<p*6<<" EURO"<<endl; ofvinc(p*6,l);} else cout<<endl<<"RITENTA SARAI PIU FORTUNATO"<<endl; break;
			default:	if(match) {cout<<endl<<"CONGRATULATIONS YOU WON  "<<p*6<<" POUNDS"<<endl; ofvinc(p*6,l);} else cout<<endl<<"RETRY YOU WILL BE MORE LUCKY"<<endl; break;
			}
			break;
			
case 'f': 	doz=scdoz(l);
			match=mdoz(doz,r);
			estr(r,l);
			switch(l){
			case 'i':	if(match) {cout<<endl<<"COMPLIMENTI HAI VINTO "<<p*3<<" EURO"<<endl; ofvinc(p*3,l);} else cout<<endl<<"RITENTA SARAI PIU FORTUNATO"<<endl; break;
			default:	if(match) {cout<<endl<<"CONGRATULATIONS YOU WON  "<<p*3<<" POUNDS"<<endl; ofvinc(p*3,l);} else cout<<endl<<"RETRY YOU WILL BE MORE LUCKY"<<endl; break;
			}
			break;
			
case 'g': 	rn=scrn(l);
			match=mrn(rn,r);
			estr(r,l);
			switch(l){
			case 'i':	if(match) {cout<<endl<<"COMPLIMENTI HAI VINTO "<<p*2<<" EURO"<<endl; ofvinc(p*2,l);} else cout<<endl<<"RITENTA SARAI PIU FORTUNATO"<<endl; break;
			default:	if(match) {cout<<endl<<"CONGRATULATIONS YOU WON  "<<p*2<<" POUNDS"<<endl; ofvinc(p*2,l);} else cout<<endl<<"RETRY YOU WILL BE MORE LUCKY"<<endl; break;
			}
			break;
			
case 'h': 	pd=scpd(l);
			match=mpd(pd,r);
			estr(r,l);
			switch(l){
			case 'i':	if(match) {cout<<endl<<"COMPLIMENTI HAI VINTO "<<p*2<<" EURO"<<endl; ofvinc(p*2,l);} else cout<<endl<<"RITENTA SARAI PIU FORTUNATO"<<endl; break;
			default:	if(match) {cout<<endl<<"CONGRATULATIONS YOU WON  "<<p*2<<" POUNDS"<<endl; ofvinc(p*2,l);} else cout<<endl<<"RETRY YOU WILL BE MORE LUCKY"<<endl; break;
			}
			break;
			
case 'i': 	ab=scab(l);
			match=mab(ab,r);
			estr(r,l);
			switch(l){
			case 'i':	if(match) {cout<<endl<<"COMPLIMENTI HAI VINTO "<<p*2<<" EURO"<<endl; ofvinc(p*2,l);} else cout<<endl<<"RITENTA SARAI PIU FORTUNATO"<<endl; break;
			default:	if(match) {cout<<endl<<"CONGRATULATIONS YOU WON  "<<p*2<<" POUNDS"<<endl; ofvinc(p*2,l);} else cout<<endl<<"RETRY YOU WILL BE MORE LUCKY"<<endl; break;
			}
			break;
			
case 'o':	break;
}
}

int insn(char l){
int n;
do{
laninsn(l);
cin>>n;
}while(n<0 || n>36);
return n;
}

bool roulm(int n,roulette r){
if(n==r.getn()) return true;
}

int scdoz(char l){
int r;
do{
lanscdoz(l);
cin>>r;
}while(r<=0 || r>=4);
return r;
}

bool mdoz(int doz,roulette r){
if(doz==1)
for(int i=1;i<13;i++)
if(i==r.getn()) return true;
else continue;

if(doz==2)
for(int i=13;i<25;i++)
if(i==r.getn()) return true;
else continue;

if(doz==3)
for(int i=25;i<37;i++)
if(i==r.getn()) return true;
else continue;
}

string scrn(char l){
string rn;
do{
lanscrn(l);
cin>>rn;
}while(rn!="rosso" && rn!="nero" && rn!="red" && rn!="black" && rn!="r" && rn!="b" && rn!="n");
if(rn=="rosso" || rn=="red" || rn=="r") rn="red";
else rn="black";
return rn;
}

bool mrn(string rn,roulette r){
if(rn==r.getcol(r.getn()))
return true;
else
return false;
}


string scpd(char l){
string pd;
do{
lanscpd(l);
cin>>pd;
}while(pd!="pari" && pd!="dispari" && pd!="even" && pd!="odd" && pd!="p"  && pd!="d" && pd!="e" && pd!="o");
return pd;
}

bool mpd(string pd,roulette r){
if(pd=="pari" || pd=="even" || pd=="p" || pd=="e") {if(r.getn()%2==0) return true;}
else if(r.getn()%2==1) return true;
}


string scab(char l){
string ab;
do{
lanscab(l);
cin>>ab;
}while(ab!="basso" && ab!="alto" && ab!="lower" && ab!="higher" && ab!="b" && ab!="a" && ab!="l" && ab!="h");
return ab;
}

bool mab(string ab,roulette r){
if(ab=="basso" || ab=="lower" || ab=="b" || ab=="l")
for(int i=1;i<19;i++)
if(i==r.getn()) return true;

if(ab=="alto" || ab=="higher" || ab=="a" || ab=="h")
for(int i=19;i<37;i++)
if(i==r.getn()) return true;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------

float bjmenu(char l){
int bj;
float p;
lanbjmenu(l);
cin>>bj;
p=bjpunt(bj,l);
return p;
}

float bjpunt(int sbj,char l){
string ans;
float p;
switch(sbj){
case 1: do{
		punt(l);
		cin>>p;
		}while(p<=0);
		break;
		
case 2: lanbjpunt(l);
		do{
		ansplay(l);
		cin>>ans;
		}while(ans!="si" && ans!="yes" && ans!="y" && ans!="no");
		if(ans=="si" || ans=="yes" || ans=="y"){
		do{
		punt(l);
		cin>>p;
		}while(p<=0);
		}
		else return 0;
		break;
		
case 0: return 0;
		break;
default: nvalidch(l);
}
return p;
}

string com(char l){
string s;
do{
lancom(l);
cin>>s;
}while(s!="chiedere" && s!="raddoppiare" && s!="stare" && s!="c" && s!="r" && s!="s" && s!="call" && s!="double" && s!="stay" && s!="d" );
return s;
}

//poker------------------------------------------------------------------------------------------------------------------------------------------
float pokermenu(char l){
int pk;
float p;
lanpokermenu(l);
cin>>pk;
p=pkpunt(pk,l);
return p;
}

float pkpunt(int spk,char l){
string ans;
float p;
switch(spk){
case 1: lanblind(l);
		cin>>p;
		break;
		
case 2: pkrules(l);
		do{
		ansplay(l);
		cin>>ans;
		}while(ans!="si" && ans!="yes" && ans!="y" && ans!="no");
		if(ans=="si" || ans=="yes" || ans=="y"){
		lanblind(l);
		cin>>p;
		}
		else return -1;
		break;
		
case 0: return -1;
		break;
default: nvalidch(l);
}
return p;
}

int addbbi(int bbi,int n){
if(bbi+1==n) return 0;
else return bbi+1;
}

int refreshd(int d,int nplyr){
if(d+1==nplyr) return 0;
else return d+1;
} 
//-----------------------------------------------------------------------------------------------------------------------------------------------
bool readp(float& totp){
float p;
ifstream in("data\\puntate.txt");
if(!in.good()) return false;
while(!in.eof()){
in>>p;
totp+=p;
}
totp-=p;
in.clear();
in.close();
return true;
}

bool readv(float& totv){
float v;
ifstream in("data\\vincite.txt");
if(!in.good()) return false;
while(!in.eof()){
in>>v;
totv+=v;
}
totv-=v;
in.clear();
in.close();
return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------
bool resetp(){
ifstream in("data\\puntate.txt", ios::out | ios::trunc);
if(!in.good()) {in.clear();
				in.close(); 
				return false;}
in.clear();
in.close(); 
return true;
}

bool resetv(){
ifstream in("data\\vincite.txt", ios::out | ios::trunc);
if(!in.good()) {in.clear();
				in.close(); 
				return false;}
in.clear();
in.close(); 
return true;
}
