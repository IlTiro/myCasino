#include "poker.h"

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<fstream>
using namespace std;

//constructor
poker::poker(char ling){
nplyr=9;
int n=nplyr*2+7,app;

//inizializza mazzo
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
case 0: mazzo[i].nome="A"; mazzo[i].val=14;break;
case 1: mazzo[i].nome="2"; mazzo[i].val=2;break;
case 2: mazzo[i].nome="3"; mazzo[i].val=3;break;
case 3: mazzo[i].nome="4"; mazzo[i].val=4;break;
case 4: mazzo[i].nome="5"; mazzo[i].val=5;break;
case 5: mazzo[i].nome="6"; mazzo[i].val=6;break;
case 6: mazzo[i].nome="7"; mazzo[i].val=7;break;
case 7: mazzo[i].nome="8"; mazzo[i].val=8;break;
case 8: mazzo[i].nome="9"; mazzo[i].val=9;break;
case 9: mazzo[i].nome="10"; mazzo[i].val=10;break;
case 10: mazzo[i].nome="J"; mazzo[i].val=11;break;
case 11: mazzo[i].nome="Q"; mazzo[i].val=12;break;
case 12: mazzo[i].nome="K"; mazzo[i].val=13;break;
}

//creazione carte da pescare
for(int i=0;i<52;i++)
card[i]=i;

for(int i=0;i<51;i++)
for(int j=0;j<52;j++)
if(rand()%2==0)
{
app=card[i];
card[i]=card[j];
card[j]=app;
}

for(int i=0;i<52;i++)
if(rand()%2==0)
{
card[i]=card[51-i];
card[51-i]=card[i];

l=ling;
}

for(int i=0;i<5;i++)
common[i]=card[n-i-1];
//inizializza player
for(int i=0;i<nplyr;i++){
plyr[i].c1=card[i*2];
plyr[i].c2=card[i*2+1];
plyr[i].p=0;
plyr[i].ps=rand()%6;
if(plyr[i].ps==2 || plyr[i].ps==3) plyr[i].ps=1;
if(plyr[i].ps==4 || plyr[i].ps==5) plyr[i].ps=2;
plyr[i].vm=0;
plyr[i].kik=0;
}
}
//gestione files
bool poker::ofpunt(float p){
ofstream on("data\\puntate.txt", ios::out | ios::app);
if(!on.good()) return false;
on<<p<<endl;
return true;
}

void poker::ofvinc(float v){
ofstream on("data\\vincite.txt", ios::out | ios::app);
if(!on.good()) errorvinc(l);
on<<v<<endl;
}
//displayer
void poker::dflop(){
int n=3;
string c[n];
cout<<endl<<endl<<"                                    FLOP";
switch(l){
case 'i':	cout<<endl<<endl<<"			 "<<mazzo[common[0]].nome<<" "<<mazzo[common[0]].seme<<"  "<<mazzo[common[1]].nome<<" "<<mazzo[common[1]].seme<<"   "<<mazzo[common[2]].nome<<" "<<mazzo[common[2]].seme; break;
//cuori,quadri,fiori,picche da cambiare per lingua
default:	for(int i=0;i<n;i++)
			if(mazzo[common[i]].seme=="cuori") c[i]="hearts";
			else if(mazzo[common[i]].seme=="quadri") c[i]="diamonds";
			else if(mazzo[common[i]].seme=="fiori") c[i]="clubs";
			else c[i]="spades";
			cout<<endl<<endl<<"			 "<<mazzo[common[0]].nome<<" "<<c[0]<<"  "<<mazzo[common[1]].nome<<" "<<c[1]<<"   "<<mazzo[common[2]].nome<<" "<<c[2]; break;
}
}

void poker::drivr(){
string c;
cout<<endl<<endl<<"                                   RIVER";
switch(l){
case 'i':	cout<<endl<<endl<<"				   "<<mazzo[common[3]].nome<<" "<<mazzo[common[3]].seme; break;
//cuori,quadri,fiori,picche da cambiare per lingua
default:	if(mazzo[common[3]].seme=="cuori") c="hearts";
			else if(mazzo[common[3]].seme=="quadri") c="diamonds";
			else if(mazzo[common[3]].seme=="fiori") c="clubs";
			else c="spades";
			cout<<endl<<endl<<"				   "<<mazzo[common[3]].nome<<" "<<c; break;
}
}

void poker::dturn(){
string c;
cout<<endl<<endl<<"                                    TURN";
switch(l){
case 'i':	cout<<endl<<endl<<"				   "<<mazzo[common[4]].nome<<" "<<mazzo[common[4]].seme; break;
//cuori,quadri,fiori,picche da cambiare per lingua
default:	if(mazzo[common[3]].seme=="cuori") c="hearts";
			else if(mazzo[common[3]].seme=="quadri") c="diamonds";
			else if(mazzo[common[3]].seme=="fiori") c="clubs";
			else c="spades";
			cout<<endl<<endl<<"				   "<<mazzo[common[4]].nome<<" "<<c; break;
}}
//creazione dealer sb e bb
bool poker::sbb(float sbb,float bbb,int d,int& sbi,int& bbi){
bool tf=true;
sb=sbb;bb=bbb;
if(d==0) switch(l) {case 'i': cout<<endl<<endl<<"Sei il DEALER"; break;	
					default: cout<<endl<<endl<<"You are the DEALER"; break;}
else 	 switch(l) {case 'i': cout<<endl<<endl<<"il giocatore "<<d<<" e il DEALER"; break;
					default:  cout<<endl<<endl<<"Player "<<d<<" is the DEALER"; break;}

if(d+1==nplyr) {switch(l) {case 'i': cout<<endl<<endl<<"Sei il PICCOLO BUIO"; break;	
						   default: cout<<endl<<endl<<"You are the SMALL BLIND"; break;}
				plyr[0].p+=sb;tf=ofpunt(sb);sbi=0;}
else {switch(l) {case 'i': cout<<endl<<"il giocatore "<<d+1<<" e il PICCOLO BUIO"; break;	
				 default: cout<<endl<<"Player "<<d+1<<" is the SMALL BLIND"; break;}
	  plyr[d+1].p+=sb;sbi=d+1;}

if(d+2==nplyr) {switch(l) {case 'i': cout<<endl<<endl<<"Sei il GRANDE BUIO"; break;	
						   default: cout<<endl<<endl<<"You are the BIG BLIND"; break;}
				plyr[0].p+=bb;tf=ofpunt(bb);bbi=0;}
else if(d+2==nplyr+1) {switch(l) {case 'i': cout<<endl<<endl<<"il giocatore 1 e il GRANDE BUIO"; break;	
								  default: cout<<endl<<endl<<"Player 1 is the BIG BLIND"; break;}
					   plyr[1].p+=bb;bbi=1;}
else {switch(l) {case 'i': cout<<endl<<"il giocatore "<<d+2<<" e il GRANDE BUIO"; break;	
				 default: cout<<endl<<"Player "<<d+2<<" is the BIG BLIND"; break;}
	  plyr[d+2].p+=bb;bbi=d+2;}

maxp=bb;
return tf;
}

//main function
void poker::punt(int pp,int giro,bool& punt,int cg){
srand((unsigned)time(NULL));
for(int i=pp;i<nplyr;i++)
if(plyr[i].c1!=-1)
if(cg==0 || plyr[i].p!=maxp){
//cout<<endl<<endl<<"GIOCA IL GIOCATORE "<<i;
if(i==0) plyr[i]=plyrch(plyr[i],punt);
else switch(giro){
case 0: plyr[i]=preflop(plyr[i],i,punt,rand()); break;
case 1: plyr[i]=flop(plyr[i],i,punt,rand()); break;
case 2: plyr[i]=river(plyr[i],i,punt,rand()); break;
case 3: plyr[i]=turn(plyr[i],i,punt,rand()); break;
}
rim=contrim();
cout<<endl<<endl;
system("pause");
}
for(int i=0;i<pp;i++)
if(plyr[i].c1!=-1)
if(cg==0 || plyr[i].p!=maxp){
//cout<<endl<<endl<<"GIOCA IL GIOCATORE "<<i;
if(i==0) plyr[i]=plyrch(plyr[i],punt);
else switch(giro){
case 0: plyr[i]=preflop(plyr[i],i,punt,rand()); break;
case 1: plyr[i]=flop(plyr[i],i,punt,rand()); break;
case 2: plyr[i]=river(plyr[i],i,punt,rand()); break;
case 3: plyr[i]=turn(plyr[i],i,punt,rand()); break;
}
rim=contrim();
cout<<endl<<endl;
system("pause");
}
}
//showdown
void poker::sd(int pp){
for(int i=pp;i<nplyr;i++)
if(plyr[i].c1!=-1)
plyr[i]=showdown(plyr[i],i);

for(int i=0;i<pp;i++)
if(plyr[i].c1!=-1)
plyr[i]=showdown(plyr[i],i);
}
//controllo puntate tutte uguali
bool poker::ctrlpunt(){
bool tf=true;
for(int i=0;i<nplyr;i++){
if(plyr[i].c1!=-1)
if(plyr[i].p!=maxp) tf=false;}
return tf;
}
//controllo rimanenti
int poker::contrim(){
int c=0;
for(int i=0;i<nplyr;i++)
if(plyr[i].c1!=-1) c++;
return c;
}
//calcolo e display piatto
float poker::calpot(float pot){
float c=0;
for(int i=0;i<nplyr;i++){
c+=plyr[i].p;
plyr[i].p=0;
}
pot+=c;
switch(l){
case 'i':	cout<<endl<<endl<<"                         IL PIATTO AMMONTA A : "<<pot<<" EURO"; break;
default:	cout<<endl<<endl<<"                         THE POT AMMOUNTS TO : "<<pot<<" POUNDS"; break;
}
return c;
}
//scelta player
player poker::plyrch(player g,bool& punt){
string c[2];
string risp;
switch(l){
case 'i':	cout<<endl<<endl<<"			     <<<LA TUA MANO>>>"<<endl; break;
default:	cout<<endl<<endl<<"			      <<<YOUR CARDS>>>"<<endl; break;
}
//cuori,quadri,fiori,picche da cambiare per lingua
switch(l){
case 'i':	cout<<endl<<"				 "<<mazzo[g.c1].nome<<" "<<mazzo[g.c1].seme;
			cout<<endl<<"				 "<<mazzo[g.c2].nome<<" "<<mazzo[g.c2].seme; break;

default:	if(mazzo[g.c1].seme=="cuori") c[0]="hearts";
			else if(mazzo[g.c1].seme=="quadri") c[0]="diamonds";
			else if(mazzo[g.c1].seme=="fiori") c[0]="clubs";
			else c[0]="spades";
			
			if(mazzo[g.c2].seme=="cuori") c[1]="hearts";
			else if(mazzo[g.c2].seme=="quadri") c[1]="diamonds";
			else if(mazzo[g.c2].seme=="fiori") c[1]="clubs";
			else c[1]="spades";
			
			cout<<endl<<"				 "<<mazzo[g.c1].nome<<" "<<c[0];
			cout<<endl<<"				 "<<mazzo[g.c2].nome<<" "<<c[1]; break;
}
switch(l){
case 'i':	cout<<endl<<endl<<"AZIONI :"; break;
default:	cout<<endl<<endl<<"ACTIONS :"; break;
}
cout<<endl<<"-		fold / f ";
if(punt==true){cout<<endl<<"-		call / c ("<<maxp-g.p<<")";
			   cout<<endl<<"-		raise / r";}
else          {cout<<endl<<"-		check / ch";
			   cout<<endl<<"-		bet / b";}
if(punt==true){
do{
switch(l){
case 'i':	cout<<endl<<endl<<"Cosa fare : "; break;
default:	cout<<endl<<endl<<"What do you want to do : "; break;
}
cin>>risp;
}while(risp!="fold" && risp!="call" && risp!="raise" && risp!="f" && risp!="c" && risp!="r");
			 }
else{
do{
switch(l){
case 'i':	cout<<endl<<endl<<"Cosa fare : "; break;
default:	cout<<endl<<endl<<"What do you want to do : "; break;
}
cin>>risp;
}while(risp!="fold" && risp!="check" && risp!="bet" && risp!="f" && risp!="ch" && risp!="b");
}
g=swrisp(g,risp,punt);
return g;
}
//switch scelta player
player poker::swrisp(player g,string risp,bool& punt){
bool tf=true;
float alz;
if("fold"==risp || "f"==risp) g.c1=-1;
if("call"==risp || "c"==risp) {tf=ofpunt(maxp-g.p); g.p=maxp;}
if("raise"==risp || "r"==risp){
		do{ switch(l){
			case 'i':	cout<<endl<<endl<<"Di quanto vuoi aumentare la puntata attuale quotata a "<<maxp<<" : "; break;
			default:	cout<<endl<<endl<<"How much do you want to increase the current bet listed at "<<maxp<<" : "; break;
			}
		cin>>alz; }while(alz<sb/2);
		tf=ofpunt((maxp-g.p)+alz);
		maxp+=alz;
		g.p=maxp;
		}
if("check"==risp || "ch"==risp) ;
if("bet"==risp || "b"==risp) {
		switch(l){
		case 'i':	do{	cout<<endl<<endl<<"Quanto vuoi puntare : ";
					cin>>alz; }while(alz<sb*2); break;
		default:	do{	cout<<endl<<endl<<"How much do you want to bet : ";
					cin>>alz; }while(alz<sb*2); break;
		}
		tf=ofpunt(alz);
		maxp=alz;
		g.p=maxp;
		punt=true;
		}

if(tf==false) switch(l){
			  case 'i':	cout<<endl<<"ERRORE con la memorizzazione della puntata o rilancio"; break;
			  default:	cout<<endl<<"ERROR with writing bet or raise on file"; break;
			  }
return g;
}

//switchriposta per i bot
player poker::swrisb(player g,string risp,float alz,int i,bool& punt){
int sbb=sb*2;
srand((unsigned)time(NULL));
if(risp=="fold") g.c1=-1;
else if(risp=="call") g.p=maxp;
else if(risp=="raise") {if(rand()%2==0) alz+=rand()%sbb; else alz-=rand()%sbb;
						maxp+=alz; g.p=maxp;}
else if(risp=="bet")	{if(rand()%2==0) alz+=rand()%sbb; else alz-=rand()%sbb;
						maxp=alz; g.p=maxp; punt=true;}
else ;
switch(l){
case 'i':	cout<<endl<<endl<<"il giocatore "<<i<<" ha selezionato "<<risp; break;
default:	cout<<endl<<endl<<"Player "<<i<<" selected "<<risp; break;
}
if(risp=="raise") switch(l) {case 'i': cout<<" di "<<alz<<" EURO"; break;	
							 default: cout<<" the bet is raised of "<<alz<<" POUNDS"; break;}
else if(risp=="bet") switch(l) {case 'i': cout<<" la puntata e impostata a "<<maxp<<" EURO"; break;	
								default: cout<<" the bet was setted at "<<maxp;  (maxp<2) ? cout<<" POUND" : cout<<" POUNDS"; break;}
return g;
}

player poker::preflop(player g,int i,bool& punt,int rand){
player a=g;
int n=2,rnd=rand%5;
int val[n]{mazzo[g.c1].val,mazzo[g.c2].val};
string seme[n]{mazzo[g.c1].seme,mazzo[g.c2].seme};
if(g.p!=maxp){
if(val[0]==val[1]){if(rnd==0) g=swrisb(g,"raise",sb*2,i,punt); else g=swrisb(g,"call",0,i,punt);}
else if(seme[0]==seme[1]){if(rnd==0) g=swrisb(g,"raise",sb*2,i,punt); else g=swrisb(g,"call",0,i,punt);}
else if(val[0]-val[1]==1 || val[1]-val[0]==1) g=swrisb(g,"call",0,i,punt);
else if(val[0]>10 && val[1]>10) g=swrisb(g,"call",0,i,punt);
else if(rim<4) g=swrisb(g,"call",0,i,punt);

if(a.p==g.p)
switch(g.ps){
case 0: if(rnd==0) g=swrisb(g,"raise",sb*2,i,punt); else{ if(rnd==4) g=swrisb(g,"fold",0,i,punt); else g=swrisb(g,"call",0,i,punt);} break;
case 1: g=swrisb(g,"fold",0,i,punt); break;
case 2: if(maxp<sb*4){if(rnd==0) g=swrisb(g,"raise",sb*2,i,punt); else{ if(rnd==4) g=swrisb(g,"fold",0,i,punt); else g=swrisb(g,"call",0,i,punt);}} else g=swrisb(g,"fold",0,i,punt); break;
}
}
else g=swrisb(g,"call",0,i,punt);
return g;
}

player poker::flop(player g,int i,bool& punt,int rand){
player a=g;
int n=5,rnd=rand%5;
int val[n]{mazzo[g.c1].val,mazzo[g.c2].val,mazzo[common[0]].val,mazzo[common[1]].val,mazzo[common[2]].val};
string seme[n]{mazzo[g.c1].seme,mazzo[g.c2].seme,mazzo[common[0]].seme,mazzo[common[1]].seme,mazzo[common[2]].seme};

if(punt==true){

//colore
int c=0,q=0,f=0,p=0;
for(int i=0;i<n;i++)
if(seme[i]=="cuori")c++;
else if(seme[i]=="quadri")q++;
else if(seme[i]=="fiori")f++;
else p++;
if(c==5 || q==5 || f==5 || p==5) {if(maxp<sb*10) g=swrisb(g,"raise",sb*4,i,punt); else g=swrisb(g,"call",0,i,punt);}
else if(c==4 || q==4 || f==4 || p==4) g=swrisb(g,"call",0,i,punt);

//copie/tris/poker
if(a.p==g.p){
int com=0,hand=0,u=0;
for(int i=3;i<n-1;i++)
for(int j=i+1;j<n;j++)
if(val[i]==val[j]) com++;
if(val[0]==val[1]) hand++;
for(int i=0;i<n-1;i++)
for(int j=i+1;j<n;j++)
if(val[i]==val[j]) u++;

if(u>5) {if(maxp<sb*10) g=swrisb(g,"raise",sb*4,i,punt); else g=swrisb(g,"call",0,i,punt);}
else if(com==3) {if(hand==1) {if(val[0]>10) {if(maxp<sb*10) g=swrisb(g,"raise",sb*4,i,punt); else g=swrisb(g,"call",0,i,punt);}}}
else 	{if(u==4) {if(maxp<sb*10) g=swrisb(g,"raise",sb*4,i,punt); else g=swrisb(g,"call",0,i,punt);}
		else if(u==3) g=swrisb(g,"call",0,i,punt);
		}

//scale
if(a.p==g.p){
int app;
for(int i=0;i<n-1;i++)
for(int j=i+1;j<n;j++)
if(val[i]<val[j]){app=val[i];val[i]=val[j];val[j]=app;}

if(u==0){
if(val[0]-val[4]==4) {if(maxp<sb*10) g=swrisb(g,"raise",sb*4,i,punt); else g=swrisb(g,"call",0,i,punt);}
else if(val[1]-val[4]==3) g=swrisb(g,"call",0,i,punt);
else if(val[0]-val[3]==3) g=swrisb(g,"call",0,i,punt);
}
else if(u==1) if(val[0]-val[4]==3) g=swrisb(g,"call",0,i,punt);

		
if(a.p==g.p)
switch(g.ps){
case 0: if(rim<=4) {if(rnd==0) g=swrisb(g,"raise",sb*3,i,punt);else g=swrisb(g,"call",0,i,punt);} else {if(rnd==0) g=swrisb(g,"call",0,i,punt);else g=swrisb(g,"fold",0,i,punt);} break;
case 1: if(rim>2)g=swrisb(g,"fold",0,i,punt); else{g=swrisb(g,"call",0,i,punt); g.ps=0;} break;
case 2: if(rim<=4) {if(maxp<sb*4){if(rnd==4) g=swrisb(g,"fold",0,i,punt); else g=swrisb(g,"call",0,i,punt);} else g=swrisb(g,"fold",0,i,punt);} 
		else {if(maxp<sb*6) g=swrisb(g,"call",0,i,punt); else g=swrisb(g,"fold",0,i,punt);} break;
}}}
}

else{

//colore
int c=0,q=0,f=0,p=0;
for(int i=0;i<n;i++)
if(seme[i]=="cuori")c++;
else if(seme[i]=="quadri")q++;
else if(seme[i]=="fiori")f++;
else p++;
if(c==5 || q==5 || f==5 || p==5) {g=swrisb(g,"bet",sb*3,i,punt); cout<<endl<<"colore";}
else if(c==4 || q==4 || f==4 || p==4) g=swrisb(g,"bet",sb*2,i,punt);

//copie/tris/poker
if(a.p==g.p){
int com=0,hand=0,u=0;
for(int i=3;i<n-1;i++)
for(int j=i+1;j<n;j++)
if(val[i]==val[j]) com++;
if(val[0]==val[1]) hand++;
for(int i=0;i<n-1;i++)
for(int j=i+1;j<n;j++)
if(val[i]==val[j]) u++;

if(u>5) {g=swrisb(g,"bet",sb*3,i,punt); cout<<endl<<"poker";}
else if(com==3) {if(hand==1) {if(val[0]>10) {g=swrisb(g,"bet",sb*2,i,punt); cout<<endl<<"full";}}}
else 	{if(u==4) {g=swrisb(g,"bet",sb*3,i,punt); cout<<endl<<"full";}
		else if(u==3) g=swrisb(g,"bet",sb*2,i,punt);
		}

//scale
if(a.p==g.p){
int app;
for(int i=0;i<n-1;i++)
for(int j=i+1;j<n;j++)
if(val[i]<val[j]){app=val[i];val[i]=val[j];val[j]=app;}

if(u==0){
if(val[0]-val[4]==5) {g=swrisb(g,"bet",sb*3,i,punt);}
else if(val[1]-val[4]==4) g=swrisb(g,"bet",sb*2,i,punt);
else if(val[0]-val[3]==4) g=swrisb(g,"bet",sb*2,i,punt);
}
else if(u==1) if(val[0]-val[4]==4) g=swrisb(g,"bet",sb*2,i,punt);

if(a.p==g.p)
switch(g.ps){
case 0: if(rnd==0) g=swrisb(g,"bet",sb*2,i,punt); else g=swrisb(g,"check",0,i,punt); break;
case 1: if(rim>2)g=swrisb(g,"fold",0,i,punt); else{g=swrisb(g,"check",0,i,punt); g.ps=0;} break;
case 2: g=swrisb(g,"check",0,i,punt); break;
}}}
}
return g;
}

player poker::river(player g,int i,bool& punt,int rand){
player a=g;
int n=6,rnd=rand%5;
int val[n]{mazzo[g.c1].val,mazzo[g.c2].val,mazzo[common[0]].val,mazzo[common[1]].val,mazzo[common[2]].val,mazzo[common[3]].val};
string seme[n]{mazzo[g.c1].seme,mazzo[g.c2].seme,mazzo[common[0]].seme,mazzo[common[1]].seme,mazzo[common[2]].seme,mazzo[common[3]].seme};

if(punt==true){

//colore
int c=0,q=0,f=0,p=0;
for(int i=0;i<n;i++)
if(seme[i]=="cuori")c++;
else if(seme[i]=="quadri")q++;
else if(seme[i]=="fiori")f++;
else p++;
if(c>4 || q>4 || f>4 || p>4) {if(maxp<sb*10) g=swrisb(g,"raise",sb*4,i,punt); else g=swrisb(g,"call",0,i,punt);}
else if(g.ps==0 || g.ps==1) {if(c==4 || q==4 || f==4 || p==4) g=swrisb(g,"call",0,i,punt);}

//copie/tris/poker
if(a.p==g.p){
int com=0,hand=0,u=0;
for(int i=3;i<n-1;i++)
for(int j=i+1;j<n;j++)
if(val[i]==val[j]) com++;
if(val[0]==val[1]) hand++;
for(int i=0;i<n-1;i++)
for(int j=i+1;j<n;j++)
if(val[i]==val[j]) u++;

if(com==6) {if(mazzo[g.c1].val>12 || mazzo[g.c2].val>12) {if(rnd<2) g=swrisb(g,"raise",sb*4,i,punt); else g=swrisb(g,"call",0,i,punt);}}
else if(com>2) {if(hand==1) {if(mazzo[g.c1].val>10) {if(rnd<2) g=swrisb(g,"raise",sb*4,i,punt); else g=swrisb(g,"call",0,i,punt);}}}
else if(com==2) {if(u>3) g=swrisb(g,"call",0,i,punt);}
else{
if(u>5) {if(maxp<sb*10) g=swrisb(g,"raise",sb*4,i,punt); else g=swrisb(g,"call",0,i,punt);}
else if(u>3) {if(maxp<sb*10) g=swrisb(g,"raise",sb*4,i,punt); else g=swrisb(g,"call",0,i,punt);}
else if(g.ps==0 || g.ps==1) {if(u==3) {if(rnd<2) g=swrisb(g,"raise",sb*4,i,punt); else g=swrisb(g,"call",0,i,punt);}}}

//scale
if(a.p==g.p){
int app;
for(int i=0;i<n-1;i++)
for(int j=i+1;j<n;j++)
if(val[i]<val[j]){app=val[i];val[i]=val[j];val[j]=app;}
if(u==0){
if(val[0]-val[4]==4) {if(maxp<sb*10) g=swrisb(g,"raise",sb*4,i,punt); else g=swrisb(g,"call",0,i,punt);}
else if(val[1]-val[5]==4) {if(maxp<sb*10) g=swrisb(g,"raise",sb*4,i,punt); else g=swrisb(g,"call",0,i,punt);}
else if(g.ps==0 || g.ps==1){
if(val[0]-val[3]==3) g=swrisb(g,"call",0,i,punt);
else if(val[1]-val[4]==3) g=swrisb(g,"call",0,i,punt);
else if(val[2]-val[5]==3) g=swrisb(g,"call",0,i,punt);
}}
else if(u==1) {
if(val[0]-val[5]==4) {if(maxp<sb*10) g=swrisb(g,"raise",sb*4,i,punt); else g=swrisb(g,"call",0,i,punt);}
else if(g.ps==0 || g.ps==1){
if(val[0]-val[4]==3) g=swrisb(g,"call",0,i,punt);
else if(val[1]-val[5]==3) g=swrisb(g,"call",0,i,punt);
}}


if(a.p==g.p)
switch(g.ps){
case 0: if(rim<=3) {if(rnd==0) g=swrisb(g,"raise",sb*3,i,punt);else g=swrisb(g,"call",0,i,punt);} else {if(rnd==0) g=swrisb(g,"call",0,i,punt);else g=swrisb(g,"fold",0,i,punt);} break;
case 1: if(rim>2)g=swrisb(g,"fold",0,i,punt); else{g=swrisb(g,"call",0,i,punt); g.ps=0;} break;
case 2: if(rim<=3) {if(maxp<sb*4){if(rnd==4) g=swrisb(g,"fold",0,i,punt); else g=swrisb(g,"call",0,i,punt);} else g=swrisb(g,"fold",0,i,punt);} 
		else {if(maxp<sb*6) g=swrisb(g,"call",0,i,punt); else g=swrisb(g,"fold",0,i,punt);} break;
}}}
}

else{
//colore
int c=0,q=0,f=0,p=0;
for(int i=0;i<n;i++)
if(seme[i]=="cuori")c++;
else if(seme[i]=="quadri")q++;
else if(seme[i]=="fiori")f++;
else p++;
if(c>4 || q>4 || f>4 || p>4) g=swrisb(g,"bet",sb*3,i,punt);
else if(g.ps==0 || g.ps==1) {if(c==4 || q==4 || f==4 || p==4) g=swrisb(g,"bet",sb*2,i,punt);}

//copie/tris/poker
if(a.p==g.p){
int com=0,hand=0,u=0;
for(int i=3;i<n-1;i++)
for(int j=i+1;j<n;j++)
if(val[i]==val[j]) com++;
if(val[0]==val[1]) hand++;
for(int i=0;i<n-1;i++)
for(int j=i+1;j<n;j++)
if(val[i]==val[j]) u++;

if(com==6) {if(mazzo[g.c1].val>12 || mazzo[g.c2].val>12) g=swrisb(g,"bet",sb*3,i,punt);}
else if(com>2) {if(hand==1) {if(mazzo[g.c1].val>10) g=swrisb(g,"bet",sb*3,i,punt);}
else if(com==2) {if(u>3) g=swrisb(g,"bet",sb*2,i,punt);}
else{
if(u>5) g=swrisb(g,"bet",sb*3,i,punt);
else if(u>3) g=swrisb(g,"bet",sb*3,i,punt);
else if(g.ps==0 || g.ps==1) {if(u==3) g=swrisb(g,"bet",sb*2,i,punt);}}
}

//scale
if(a.p==g.p){
int app;
for(int i=0;i<n-1;i++)
for(int j=i+1;j<n;j++)
if(val[i]<val[j]){app=val[i];val[i]=val[j];val[j]=app;}

if(u==0){
if(val[0]-val[4]==4) g=swrisb(g,"bet",sb*3,i,punt);
else if(val[1]-val[5]==4) g=swrisb(g,"bet",sb*3,i,punt);
else if(g.ps==0 || g.ps==1){
if(val[0]-val[3]==3) g=swrisb(g,"bet",sb*2,i,punt);
else if(val[1]-val[4]==3) g=swrisb(g,"bet",sb*2,i,punt);
else if(val[2]-val[5]==3) g=swrisb(g,"bet",sb*2,i,punt);
}}
else if(u==1) {
if(val[0]-val[5]==4) g=swrisb(g,"bet",sb*3,i,punt);
else if(g.ps==0 || g.ps==1){
if(val[0]-val[4]==3) g=swrisb(g,"bet",sb*2,i,punt);
else if(val[1]-val[5]==3) g=swrisb(g,"bet",sb*2,i,punt);
}}

if(a.p==g.p)
switch(g.ps){
case 0: if(rnd<3) g=swrisb(g,"bet",sb*2,i,punt); else g=swrisb(g,"check",0,i,punt); break;
case 1: if(rim>2)g=swrisb(g,"fold",0,i,punt); else{g=swrisb(g,"check",0,i,punt); g.ps=0;} break;
case 2: g=swrisb(g,"check",0,i,punt); break;
}}}
}
return g;
}

player poker::turn(player g,int i,bool& punt,int rand){
player a=g;
int n=7,rnd=rand%5;
int val[n]{mazzo[g.c1].val,mazzo[g.c2].val,mazzo[common[0]].val,mazzo[common[1]].val,mazzo[common[2]].val,mazzo[common[3]].val,mazzo[common[4]].val};
string seme[n]{mazzo[g.c1].seme,mazzo[g.c2].seme,mazzo[common[0]].seme,mazzo[common[1]].seme,mazzo[common[2]].seme,mazzo[common[3]].seme,mazzo[common[4]].seme};

if(punt==true){
//colore
int c=0,q=0,f=0,p=0;

for(int i=0;i<n;i++)
if(seme[i]=="cuori")c++;
else if(seme[i]=="quadri")q++;
else if(seme[i]=="fiori")f++;
else p++;

if(c>4 || q>4 || f>4 || p>4) {if(maxp<sb*14) g=swrisb(g,"raise",sb*6,i,punt); else g=swrisb(g,"call",0,i,punt);}

//copie/tris/poker
if(a.p==g.p){
int com=0,hand=0,u=0;
for(int i=3;i<n-1;i++)
for(int j=i+1;j<n;j++)
if(val[i]==val[j]) com++;
if(val[0]==val[1]) hand++;

for(int i=0;i<n-1;i++)
for(int j=i+1;j<n;j++)
if(val[i]==val[j]) u++;

if(com>5) {if(mazzo[g.c1].val>12 || mazzo[g.c2].val>12) {if(rnd<2) g=swrisb(g,"raise",sb*6,i,punt); else g=swrisb(g,"call",0,i,punt);}}
else if(com>2) {if(hand==1) {if(mazzo[g.c1].val>10) {if(rnd<2) g=swrisb(g,"raise",sb*6,i,punt); else g=swrisb(g,"call",0,i,punt);}}}
else if(com==2) {if(u>3) g=swrisb(g,"call",0,i,punt);}
else{
if(u>5) {if(maxp<sb*14) g=swrisb(g,"raise",sb*6,i,punt); else g=swrisb(g,"call",0,i,punt);}
else if(u>3) {if(maxp<sb*14) g=swrisb(g,"raise",sb*6,i,punt); else g=swrisb(g,"call",0,i,punt);}}

//scale
if(a.p==g.p){
int app;
for(int i=0;i<n-1;i++)
for(int j=i+1;j<n;j++)
if(val[i]<val[j]){app=val[i];val[i]=val[j];val[j]=app;}

if(u==0){
if(val[0]-val[4]==4) {if(maxp<sb*14) g=swrisb(g,"raise",sb*6,i,punt); else g=swrisb(g,"call",0,i,punt);}
else if(val[1]-val[5]==4) {if(maxp<sb*14) g=swrisb(g,"raise",sb*6,i,punt); else g=swrisb(g,"call",0,i,punt);}
else if(val[2]-val[6]==4) {if(maxp<sb*14) g=swrisb(g,"raise",sb*6,i,punt); else g=swrisb(g,"call",0,i,punt);}
}
else if(u==1) {
if(val[0]-val[5]==4) {if(maxp<sb*14) g=swrisb(g,"raise",sb*6,i,punt); else g=swrisb(g,"call",0,i,punt);}
else if(val[1]-val[6]==4) {if(maxp<sb*14) g=swrisb(g,"raise",sb*6,i,punt); else g=swrisb(g,"call",0,i,punt);}
}
else if(u==2 || u==3){
if(val[0]-val[6]==4) {if(maxp<sb*14) g=swrisb(g,"raise",sb*6,i,punt); else g=swrisb(g,"call",0,i,punt);}
}

if(a.p==g.p)
switch(g.ps){
case 0: if(rnd==0) g=swrisb(g,"call",0,i,punt); else {if(maxp<sb*14) g=swrisb(g,"raise",sb*6,i,punt); else g=swrisb(g,"call",0,i,punt);} break;
case 1: if(rim>2)g=swrisb(g,"fold",0,i,punt); else{if(rnd==0) g=swrisb(g,"call",0,i,punt); else g=swrisb(g,"raise",sb*6,i,punt); g.ps=0;} break;
case 2: g=swrisb(g,"call",0,i,punt); break;
}}}
}

else{
//colore
int c=0,q=0,f=0,p=0;
for(int i=0;i<n;i++)
if(seme[i]=="cuori")c++;
else if(seme[i]=="quadri")q++;
else if(seme[i]=="fiori")f++;
else p++;

if(c>4 || q>4 || f>4 || p>4) g=swrisb(g,"bet",sb*4,i,punt);

//copie/tris/poker
if(a.p==g.p){
int com=0,hand=0,u=0;
for(int i=3;i<n-1;i++)
for(int j=i+1;j<n;j++)
if(val[i]==val[j]) com++;
if(val[0]==val[1]) hand++;
for(int i=0;i<n-1;i++)
for(int j=i+1;j<n;j++)
if(val[i]==val[j]) u++;

if(com>5) {if(mazzo[g.c1].val>12 || mazzo[g.c2].val>12) g=swrisb(g,"bet",sb*4,i,punt);}
else if(com>2) {if(hand==1) {if(mazzo[g.c1].val>10) g=swrisb(g,"bet",sb*4,i,punt);}}
else if(com==2) {if(u>3) g=swrisb(g,"bet",sb*4,i,punt);}
else{
if(u>5) g=swrisb(g,"bet",sb*4,i,punt);
else if(u>3) g=swrisb(g,"bet",sb*4,i,punt);}

//scale
if(a.p==g.p){
int app;
for(int i=0;i<n-1;i++)
for(int j=i+1;j<n;j++)
if(val[i]<val[j]){app=val[i];val[i]=val[j];val[j]=app;}

if(u==0){
if(val[0]-val[4]==4) g=swrisb(g,"bet",sb*4,i,punt);
else if(val[1]-val[5]==4) g=swrisb(g,"bet",sb*4,i,punt);
else if(val[2]-val[6]==4) g=swrisb(g,"bet",sb*4,i,punt);
}
else if(u==1) {
if(val[0]-val[5]==4) g=swrisb(g,"bet",sb*4,i,punt);
else if(val[1]-val[6]==4) g=swrisb(g,"bet",sb*4,i,punt);
}
else if(u==2 || u==3){
if(val[0]-val[6]==4) g=swrisb(g,"bet",sb*4,i,punt);
}


if(a.p==g.p)
switch(g.ps){
case 0: if(rnd==0) g=swrisb(g,"check",0,i,punt); else g=swrisb(g,"bet",sb*4,i,punt); break;
case 1: if(rim>2)g=swrisb(g,"fold",0,i,punt); else{if(rnd==0) g=swrisb(g,"check",0,i,punt); else g=swrisb(g,"bet",sb*4,i,punt); g.ps=0;} break;
case 2: g=swrisb(g,"check",0,i,punt); break;
}}}
}
return g;
}

player poker::showdown(player g,int i){
int n=7,vm=0;
int app;
string ap;
cart apc;

int val[n]{mazzo[g.c1].val,mazzo[g.c2].val,mazzo[common[0]].val,mazzo[common[1]].val,mazzo[common[2]].val,mazzo[common[3]].val,mazzo[common[4]].val};
int val1[n]{mazzo[g.c1].val,mazzo[g.c2].val,mazzo[common[0]].val,mazzo[common[1]].val,mazzo[common[2]].val,mazzo[common[3]].val,mazzo[common[4]].val};
string seme[n]{mazzo[g.c1].seme,mazzo[g.c2].seme,mazzo[common[0]].seme,mazzo[common[1]].seme,mazzo[common[2]].seme,mazzo[common[3]].seme,mazzo[common[4]].seme};
string seme1[n]{mazzo[g.c1].seme,mazzo[g.c2].seme,mazzo[common[0]].seme,mazzo[common[1]].seme,mazzo[common[2]].seme,mazzo[common[3]].seme,mazzo[common[4]].seme};
cart cod1[n]{mazzo[g.c1],mazzo[g.c2],mazzo[common[0]],mazzo[common[1]],mazzo[common[2]],mazzo[common[3]],mazzo[common[4]]};

//colore
int c=0,q=0,f=0,p=0;

for(int i=0;i<n;i++)
if(seme[i]=="cuori")c++;
else if(seme[i]=="quadri")q++;
else if(seme[i]=="fiori")f++;
else p++;
int k=0;

for(int i=0;i<n-1;i++)
for(int j=i+1;j<n;j++)
if(val[i]<val[j]){app=val1[i];val1[i]=val1[j];val1[j]=app;
				  ap=seme1[i];seme1[i]=seme1[j];seme1[j]=ap;
				  apc=cod1[i];cod1[i]=cod1[j];cod1[j]=apc;}

if(c>4 || q>4 || f>4 || p>4) {if(c>4){
							  cart color[c];
							  for(int i=0;i<n;i++)
							  if(cod1[i].seme=="cuori") {color[k]=cod1[i];k++;}
							  vm=calcvm(color,k,g);
							  }
							  else if(q>4){
							  cart color[q];
							  for(int i=0;i<n;i++)
							  if(cod1[i].seme=="quadri") {color[k]=cod1[i];k++;}
							  vm=calcvm(color,k,g);
							  }
							  else if(f>4){
							  cart color[f];
							  for(int i=0;i<n;i++)
							  if(cod1[i].seme=="fiori") {color[k]=cod1[i];k++;}
							  vm=calcvm(color,k,g);
							  }
							  else{
							  cart color[p];
							  for(int i=0;i<n;i++)
							  if(cod1[i].seme=="picche") {color[k]=cod1[i];k++;}
							  vm=calcvm(color,k,g);
							  }
							  }
//copie/tris/poker
int u=0,u1=0,u2=0;

for(int i=0;i<n-1;i++)
for(int j=i+1;j<n;j++)
if(val1[i]==val1[j]) u++;

if(u==9)	vm=7;

else
if(u>5)    {vm=6;
			for(int i=0;i<4;i++){
			for(int j=i+1;j<n;j++)
			if(val1[i]==val1[j]) u1++;
			if(u1==3) vm=7;
			u1=0;
			}
			}
		
else
if(u==5)   vm=6;

else
if(u==4)   vm=6;

if(vm<5){
if(u==3)   {vm=2;
			for(int i=0;i<5;i++){
			for(int j=i+1;j<n;j++)
			if(val1[i]==val1[j]) u1++;
			if(u1==2) vm=3;
			u1=0;
			}
			}

else
if(u==2)   vm=2;

else
if(u==1)   vm=1;

else	   vm=0;

//scale
u1=0;u=0;
for(int i=0;i<n-1;i++)
for(int j=i+1;j<n;j++)
if(val1[i]<val1[j]) {app=val1[i];val1[i]=val1[j];val1[j]=app;}

for(int i=0;i<n-1;i++)
for(int j=i+1;j<n;j++)
if(val[i]==val[j]) u++;

if(u==0)   {if(val1[0]-val1[4]==4) {vm=4; g.kik=val1[0];}
			else if(val1[1]-val1[5]==4) {vm=4; g.kik=val1[1];}
			else if(val1[2]-val1[6]==4) {vm=4; g.kik=val1[2];}
			else if(val1[0]==14 && val1[3]-val1[6]==3 && val1[3]==5) {vm=4; g.kik=val1[3];}
			}
else if(u==1){
			if(val1[0]-val1[5]==4) {vm=4; g.kik=val1[0];}					  
			else if(val1[1]-val1[6]==4) {vm=4; g.kik=val1[1];}
			else if(val1[0]==14 && val1[2]-val1[6]==3 && val1[2]==5) {vm=4; g.kik=val1[2];}
			}
			
else if(u==3 || u==2){
			if(val1[0]-val1[6]==4) {vm=4; g.kik=val1[0];}
			else if(val1[0]==14 && val1[1]-val1[6]==3 && val1[1]==5) {vm=4; g.kik=val1[1];}
			}
}

if(vm!=4 && vm!=5 && vm!=8)
g.kik=calckik(cod1,vm);
g.vm=vm;
dmano(cod1,i,g);

return g;
}

void poker::dmano(cart mano [],int i,player g){
string lanseme[7];
if(i!=0)
switch(l){
case 'i':	cout<<endl<<endl<<"Carte a disposizione del giocatore "<<i; break;
default:	cout<<endl<<endl<<"Cards of player "<<i; break;
}
else
switch(l){
case 'i':	cout<<endl<<endl<<"Le tue carte "<<i; break;
default:	cout<<endl<<endl<<"Your cards "<<i; break;
}
cout<<endl<<endl;
//cuori,quadri,fiori,picche da cambiare per lingua
for(int j=0;j<7;j++){
switch(l){
case 'i':	cout<<mano[j].nome<<" "<<mano[j].seme<<"   "; break;
default:	if(mano[j].seme=="cuori") lanseme[j]="hearts";
			else if(mano[j].seme=="quadri") lanseme[j]="diamonds";
			else if(mano[j].seme=="fiori") lanseme[j]="clubs";
			else lanseme[j]="spades";
			cout<<mano[j].nome<<" "<<lanseme[j]<<"   "; break;
}
}
if(i!=0)
switch(l){
case 'i':	cout<<endl<<endl<<"IL GIOCATORE "<<i<<" HA FATTO "; break;
default:	cout<<endl<<endl<<"PLAYER "<<i<<" HAVE DONE "; break;
}
else
switch(l){
case 'i':	cout<<endl<<endl<<"HAI FATTO "; break;
default:	cout<<endl<<endl<<"YOU HAVE DONE "; break;
}

switch(g.vm){
case 0: switch(l)  {case 'i':	cout<<"CARTA ALTA"; break;
					default:	cout<<"HIGH CARD"; break;} break;

case 1: switch(l)  {case 'i':	cout<<"COPPIA DI "; break;
					default:	cout<<"COUPLE OF "; break;} if(g.kik<11) cout<<g.kik;
															else if(g.kik==11) cout<<"J";
															else if(g.kik==12) cout<<"Q";
															else if(g.kik==13) cout<<"K";
															else cout<<"A"; break;
case 2: switch(l)  {case 'i':	cout<<"DOPPIA COPPIA"; break;
					default:	cout<<"TWO COUPLES"; break;} break;

case 3: switch(l)  {case 'i':	cout<<"TRIS DI "; break;
					default:	cout<<"TRIS OF "; break;}  if(g.kik<11) cout<<g.kik;
														   else if(g.kik==11) cout<<"J";
														   else if(g.kik==12) cout<<"Q";
														   else if(g.kik==13) cout<<"K";
														   else cout<<"A"; break;
case 4: switch(l)  {case 'i':	cout<<"SCALA AL "; break;
					default:	cout<<"STRAIGHT TO "; break;}	if(g.kik<11) cout<<g.kik;
																else if(g.kik==11) cout<<"J";
																else if(g.kik==12) cout<<"Q";
																else if(g.kik==13) cout<<"K";
																else cout<<"A"; break;
case 5: switch(l)  {case 'i':	cout<<"COLORE"; break;
					default:	cout<<"FLUSH"; break;} break;

case 6: cout<<"FULL HOUSE";break;

case 7: switch(l)  {case 'i':	cout<<"POKER DI "; break;
					default:	cout<<"POKER OF "; break;} if(g.kik<11) cout<<g.kik;
														   else if(g.kik==11) cout<<"J";
														   else if(g.kik==12) cout<<"Q";
														   else if(g.kik==13) cout<<"K";
														   else cout<<"A"; break;

case 8: if(g.kik!=14) {switch(l) {case 'i':	cout<<"SCALA COLORE AL "; break;
								  default:	cout<<"STRAIGHT FLUSH TO "; break;} if(g.kik<11) cout<<g.kik;
																				else if(g.kik==11) cout<<"J";
																				else if(g.kik==12) cout<<"Q";
																				else cout<<"K";}
		else switch(l) {case 'i':	cout<<"SCALA REALE!-!-! COMPLIMENTI"; break;
						default:	cout<<"ROYAL FLUSH!-!-! CONGRATULATIONS"; break;} break;
		break;
}
cout<<endl;
system("pause");
}

int poker::calcvm(cart color[],int k,player& g){
cart ap;
g.kik=color[0].val;
for(int i=0;i<k-1;i++)
for(int j=i+1;j<k;j++)
if(color[i].val<color[j].val) {ap=color[i];color[i]=color[j];color[j]=ap;}

if(k==5)	{if(color[0].val-color[4].val==4) return 8;}

else
if(k==6)	{if(color[0].val-color[4].val==4) return 8;
			 else if(color[1].val-color[5].val==4) {g.kik=color[1].val; return 8;}}
else
			{if(color[0].val-color[4].val==4) return 8;
			 else if(color[1].val-color[5].val==4) {g.kik=color[1].val; return 8;}
			 else if(color[2].val-color[6].val==4) {g.kik=color[2].val; return 8;}}
return 5;
}

int poker::calckik(cart mano[],int vm){
int kik=0,pp; cart ap;
for(int i=0;i<6;i++)
for(int j=i+1;j<7;j++)
if(mano[i].val<mano[j].val) {ap=mano[i];mano[i]=mano[j];mano[j]=ap;}

switch(vm){
case 0:	for(int i=0;i<7;i++)
		if(mano[i].val>kik) kik=mano[i].val;
		break;

case 1:	for(int i=0;i<6;i++)
		if(mano[i].val==mano[i+1].val) kik=mano[i].val;
		break;

case 2:	for(int i=6;i>0;i--)
		if(mano[i].val==mano[i-1].val) {kik=mano[i].val; pp=i;}
		for(int i=pp+1;i<6;i++)
		if(mano[i].val==mano[i+1].val) {kik+=mano[i].val; break;}
		break;

case 3:	for(int i=0;i<5;i++)
		if(mano[i].val==mano[i+1].val && mano[i].val==mano[i+2].val) kik=mano[i].val;
		break;

case 6:	for(int i=6;i>0;i--)
		if(mano[i].val==mano[i-1].val) kik=mano[i].val;
		for(int i=0;i<5;i++)
		if(mano[i].val==mano[i+1].val && mano[i].val==mano[i+2].val) kik+=mano[i].val;
		break;

case 7:	for(int i=0;i<4;i++)
		if(mano[i].val==mano[i+1].val && mano[i].val==mano[i+2].val && mano[i].val==mano[i+3].val) kik=mano[i].val;
}
return kik;
}

void poker::calcwin(float pot){
int max=-1,vin=1;
player g;
for(int i=0;i<nplyr;i++)
if(plyr[i].c1!=-1)
if(plyr[i].vm>max) {max=plyr[i].vm; g=plyr[i];}
else if(plyr[i].vm==max)   {if(plyr[i].kik>g.kik) g=plyr[i];
							else if(plyr[i].kik==g.kik) vin++;}
for(int i=0;i<nplyr;i++)
if(plyr[i].vm==max && plyr[i].kik==g.kik) vinc(plyr[i],vin,pot,i);
}

void poker::vinc(player g,int vin,float pot,int i){
if(i!=0)
switch(l){
case 'i':	cout<<endl<<endl<<"IL GIOCATORE "<<i<<" VINCE IL PIATTO CHE AMMONTA A "<<pot/vin<<" EURO"; break;
default:	cout<<endl<<endl<<"PLAYER "<<i<<" WINS THE POT THAT AMMOUNT TO "<<pot/vin<<" POUNDS"; break;
}
else{
switch(l){
case 'i':	cout<<endl<<endl<<"CONGRATULAZIONI HAI VINTO IL PIATTO CHE AMMONTA A "<<pot/vin<<" EURO"; break;
default:	cout<<endl<<endl<<"CONGRATULATIONS YOU WON THE POT THAT AMMOUNT TO "<<pot/vin<<" POUNDS"; break;
}
ofvinc(pot);
}
}
//vincita per abbandono altri giocatori
void poker::win(float pot){
for(int i=0;i<nplyr;i++)
if(plyr[i].c1!=-1)
if(i!=0)
switch(l){
case 'i':	cout<<endl<<endl<<"IL GIOCATORE "<<i<<" VINCE IL PIATTO CHE AMMONTA A "<<pot<<" EURO"; break;
default:	cout<<endl<<endl<<"PLAYER "<<i<<" WINS THE POT THAT AMMOUNT TO "<<pot<<" POUNDS"; break;
}
else{
switch(l){
case 'i':	cout<<endl<<endl<<"CONGRATULAZIONI HAI VINTO IL PIATTO CHE AMMONTA A "<<pot<<" EURO"; break;
default:	cout<<endl<<endl<<"CONGRATULATIONS YOU WON THE POT THAT AMMOUNT TO "<<pot<<" POUNDS"; break;
}
ofvinc(pot);
}
}
