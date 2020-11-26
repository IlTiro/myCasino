#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<fstream>

#include "functions.cpp"
#include "slot.h"
#include "slot.cpp"
#include "roulette.h"
#include "roulette.cpp"
#include "bj.h"
#include "bj.cpp"
#include "poker.h"
#include "poker.cpp"
#include "language.cpp"
using namespace std;

//1----------------------------------------------------
int menu(char);
int match(int []);
void result(float,int,char);//in language
float slotmenu(char);
float slotpunt(int);
bool ofpunt(float);
void ofvinc(float,char);
void esci(char);
//2----------------------------------------------------
float roulmenu(char);
float roulpunt(int,char);
char roulgame(char);
void estr(roulette);
void switchgame(float,char,roulette,char);
int insn();
bool roulm(int,roulette);
int scdoz();
bool mdoz(int,roulette);
string scrn();
bool mrn(string,roulette);
string scpd();
bool mpd(string,roulette);
string scab();
bool mab(string,roulette);
//3----------------------------------------------------
float bjmenu(char);
string com(char);
void psballo(char);
void bsballo(float,char);
void lose(char);
void draw(float,char);
void win(float,char);
float bjpunt(int,char);
//4----------------------------------------------------
int addbbi(int,int);
int refreshd(int,int);
//5----------------------------------------------------
float pokermenu(char);
float pkpunt(int);
bool readp(float&);
bool readv(float&);
void stats(float,float,char);//in language
//6----------------------------------------------------
string risp;
bool resetp();
bool resetv();
//7----------------------------------------------------
char chlan(char);//in language

//per language--------------------------------------
char l;
char cinlan();

void welcomec(char);
void welcomes(char);
void welcomer(char);
void welcomebj(char);
void welcomep(char);

void errorpunt(char);
void errorvinc(char);
void errorreadpunt(char);
void errorreadvinc(char);
void reset(char);
void errorresetpunt(char);
void errorresetvinc(char);
void errorblind(char);
void errorlang(char);

void contplay(char);
void contplayp(char);
void nvalidch(char);

void stats(float,float,char);

//lanslot--------------------------------------
void lanmenu(char);
void lanslotmenu(char);
void punt(char);
void ruleslot(char);
void ansplay(char);
void ofvinc(float,char);
//lanroulette--------------------------------------
void lanroulmenu(char);
void lanroulpunt(char);
void lanroulgame(char);
void laninsn(char);
void lanscdoz(char);
void lanscrn(char);
void lanscpd(char);
void lanscab(char);
void esci(char);
//lanblackjack--------------------------------------
void lanbjmenu(char);
void lanbjpunt(char);
void lancom(char);
void psballo(char);
void bsballo(float,char);
void lose(char);
void draw(float,char);
void win(float,char);
//lanpoker--------------------------------------
void lanpokermenu(char);
void lanblind(char);
void pkrules(char);

//main-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main(){
int scelta;
float p;
float totp=0,totv=0;
bool good;
//per slot----------------------------------------------
int c;
string ans;
bool ofs;
//per roulette------------------------------------------
char rt;
//la maggior parte in switchgame
//per Black Jack---------------------------------------
bool b,fxa=false;
string bjans;
//per Poker---------------------------------------
int nplyr=9,d,sb,bb,sbi,bbi,pp,cg;
bool giro,punt=true;
float pot=0;
//ch language----------------------------------------------------
char lang;
l=cinlan();

welcomec(l);
do{
scelta=menu(l);
switch(scelta){
	
case 1:	welcomes(l);
		p=slotmenu(l);
		do{
		slot g;
		int vett[4]={g.getn1(),g.getn2(),g.getn3(),g.getn4()};
		if(p<=0) {esci(l);break;}
		ofs=ofpunt(p);
		if(ofs==false) {errorpunt(l); break;}
		c=match(vett);
		result(p,c,l);
		contplay(l);
		cin>>ans;
		}while(ans=="si" || ans=="yes" || ans=="y");
		break;

case 2:	welcomer(l);
		p=roulmenu(l);
		if(p<=0) {esci(l);break;}
		rt=roulgame(l);
		do{
		roulette r;
		ofs=ofpunt(p);
		if(ofs==false) {errorpunt(l); break;}
		switchgame(p,rt,r,l);
		contplay(l);
		cin>>ans;
		}while(ans=="si" || ans=="yes" || ans=="y");
		break;

case 3:	welcomebj(l);
		p=bjmenu(l);
		do{
		if(p<=0) {esci(l);break;}
		ofs=ofpunt(p);
		bj bj;
		int vp=0,vb,cp=2,cb=2;
		bj.banco(l);
		do{
		bj.dplayer(cp,l);
		vp=bj.vplay(cp);
		if(vp>21)	{fxa=bj.fxap(cp);
					if(fxa==false){bj.dbanco(cb,l);psballo(l);break;}}
		else{
		bjans=com(l);
		if(bjans=="chiedere" || bjans=="raddoppio" || bjans=="c" || bjans=="r" || bjans=="call" || bjans=="double" || bjans=="d") {bj.addcardp(cp); cp++;}
		if(bjans=="raddoppio" || bjans=="r" || bjans=="double" || bjans=="d") {b=ofpunt(p);if(b==true)p*=2;
												else {errorpunt(l); break;}}
		}
		}while(bjans!="stare" && bjans!="s" && bjans!="stay");

		if(vp<=21){
		do{
		bj.dbanco(cb,l);
		vb=bj.vbanc(cb);
		if(vb>21) {fxa=bj.fxab(cb);
					if(fxa==false){bsballo(p,l);break;}
					else vb=bj.vbanc(cb);}
		if(vb>vp) {lose(l);break;}
		else if(vb==vp && vb<15) bj.addcardb(cb,cp);
		else if(vb==vp) {draw(p,l);break;}
		else if(vb<vp) bj.addcardb(cb,cp);
		cb++;
		}while(vb<=21);
		}
		contplay(l);
		cin>>ans;
		}while(ans=="si" || ans=="yes" || ans=="y");
		break;

case 4:	srand((unsigned)time(NULL));
		welcomep(l);
		sb=pokermenu(l);
		if(sb<=0) {esci(l);break;}
		bb=sb*2;
		d=rand()%nplyr;

		do{
		poker pk(l);
		d=refreshd(d,nplyr);
		pk.maxp=0; pot=0;
		punt=true;

		ofs=pk.sbb(sb,bb,d,sbi,bbi);
		if(ofs==false) errorblind(l);
		pp=addbbi(bbi,nplyr);

		for(int i=0;i<4;i++){
		switch(i){
		case 0:	break;
		case 3: pk.dturn();
		case 2: pk.drivr();
		case 1: pk.dflop();
		}
		if(i!=0) pot+=pk.calpot(pot);
		cout<<endl<<endl;system("pause");

		cg=0;
		do{
		pk.punt(pp,i,punt,cg);
		giro=pk.ctrlpunt();
		pk.rim=pk.contrim();
		cg++;
		}while(giro==false);

		if(pk.rim<2) {pk.win(pot);break;}
		else if(i==3) {pot+=pk.calpot(pot); pk.sd(pp); pk.calcwin(pot);}

		punt=false;
		pp=sbi;
		pk.maxp=0;
		}
		
		contplayp(l);
		cin>>ans;
		}while(ans=="si" || ans=="yes" || ans=="y");
		break;
	
case 5:	good=readp(totp);
		if(good==false){errorreadpunt(l); break;}
		good=readv(totv);
		if(good==false){errorreadvinc(l); break;}
		stats(totp,totv,l);
		totp=0; totv=0;
		break;
		
case 6: reset(l);
		cin>>risp;
		if(risp=="si" || risp=="yes" || risp=="y"){
		good=resetp();
		if(good==false){errorresetpunt(l); break;}
		good=resetv();
		if(good==false){errorresetvinc(l); break;}
		}
		break;
		
case 7:	lang=chlan(l);
		if(lang=='x') break;
		else{
		ofstream onlang ("data//lingua.txt", ios::out | ios::trunc);
		if(!onlang.good()) errorlang(l);
		onlang<<lang;
		onlang.clear();
		onlang.close();
		l=cinlan();
		welcomec(l);
		}
		break;
		
case 0:	break;

default: nvalidch(l); break;
}
}while(scelta!=0);
esci(l);
}
