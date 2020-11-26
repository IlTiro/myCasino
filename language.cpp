#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<fstream>

using namespace std;

//main--------------------------------------
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

//functions--------------------------------------
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


char cinlan(){
char l;
ifstream lan ("data\\lingua.txt");
lan>>l;
return l;
}

void welcomec(char l){
switch(l){
case 'i':	cout<<endl<<"<-----------------------------BENVENUTI AL CASINO----------------------------->"; break;
default:	cout<<endl<<"<----------------------------WELCOME TO THE CASINO---------------------------->"; break;
}
}

void welcomes(char l){
switch(l){
case 'i':	cout<<endl<<"<-----------------------------BENVENUTI ALLA SLOT----------------------------->"; break;
default:	cout<<endl<<"<-----------------------------WELCOME TO THE SLOT----------------------------->"; break;
}
}

void welcomer(char l){
switch(l){
case 'i':	cout<<endl<<"<---------------------------BENVENUTI ALLA ROULETTE---------------------------->"; break;
default:	cout<<endl<<"<---------------------------WELCOME TO THE ROULETTE---------------------------->"; break;
}
}

void welcomebj(char l){
switch(l){
case 'i':	cout<<endl<<"<---------------------------BENVENUTI AL BLACK JACK---------------------------->"; break;
default:	cout<<endl<<"<--------------------------WELCOME TO THE BLACK JACK--------------------------->"; break;
}
}

void welcomep(char l){
switch(l){
case 'i':	cout<<endl<<"<-----------------------------BENVENUTI AL POKER------------------------------->"; break;
default:	cout<<endl<<"<----------------------------WELCOME TO THE POKER------------------------------>"; break;
}
}

//------------------------------------------------------------------------------------------------------------------

void errorpunt(char l){
switch(l){
case 'i':	cout<<endl<<"ERRORE con la memorizzazione della puntata"; break;
default:	cout<<endl<<"ERROR with writing bet on file"; break;
}
}

void errorvinc(char l){
switch(l){
case 'i':	cout<<endl<<"ERRORE con la memorizzazione della vincita"; break;
default:	cout<<endl<<"ERROR with writing winning on file"; break;
}
}

void errorreadpunt(char l){
switch(l){
case 'i':	cout<<endl<<"ERRORE nella lettura delle puntata"; break;
default:	cout<<endl<<"ERROR with reading bet from file"; break;
}
}

void errorreadvinc (char l){
switch(l){
case 'i':	cout<<endl<<"ERRORE nella lettura delle vincite"; break;
default:	cout<<endl<<"ERROR with reading winnings from file"; break;
}
}

void reset (char l){
switch(l){
case 'i':	cout<<endl<<"Sei sicuro di voler resettare puntate e vincite? si/no  "; break;
default:	cout<<endl<<"Are you sure about reset bet and winnings? yes or y/no "; break;
}
}

void errorresetpunt(char l){
switch(l){
case 'i':	cout<<endl<<"ERRORE nel reset delle puntate"; break;
default:	cout<<endl<<"ERROR with resetting bet"; break;
}
}

void errorresetvinc (char l){
switch(l){
case 'i':	cout<<endl<<"ERRORE nel reset delle vincite"; break;
default:	cout<<endl<<"ERROR with resetting winnings"; break;
}
}

void errorblind(char l){
switch(l){
case 'i':	cout<<endl<<"ERRORE con la memorizzazione di piccolo o grande buio"; break;
default:	cout<<endl<<"ERROR with writing small or big blind on file"; break;
}
}

void errorlang (char l){
switch(l){
case 'i':	cout<<endl<<"ERRORE nella lettura della lingua"; break;
default:	cout<<endl<<"ERROR with reading language from file"; break;
}
}

//------------------------------------------------------------------------------------------------------------------

void contplay(char l){
cout<<endl;
switch(l){
case 'i':	cout<<endl<<"CONTINUARE A GIOCARE CON LA STESSA PUNTATA? si/no : "; break;
default:	cout<<endl<<"KEEP ON PLAYING WITH SAME BET? yes or y/no : "; break;
}
}

void contplayp(char l){
switch(l){
case 'i':	cout<<endl<<endl<<"CONTINUARE A GIOCARE A QUESTO TAVOLO? si/no : "; break;
default:	cout<<endl<<"KEEP ON PLAYING AT SAME TABLE? yes or y/no : "; break;
}
}

void nvalidch(char l){
switch(l){
case 'i':	cout<<endl<<"!-!-Scelta non valida-!-!"<<endl; break;
default:	cout<<endl<<"!-!-not valid choise-!-!"<<endl; break;
}
}

void stats(float totp,float totv,char l){
switch(l){
case 'i':	cout<<endl<<endl<<"SOLDI PUNTATI : "<<totp<<" EURO";
			cout<<endl<<"SOLDI VINTI : "<<totv<<" EURO";
			cout<<endl<<"percentuale vincite su puntate : "<<totv/totp*100<<" %"<<endl;
			cout<<endl<<endl; system("pause"); cout<<endl;
			break;

default:	cout<<endl<<endl<<"BETS : "<<totp; (totp<2) ? cout<<" POUND" : cout<<" POUNDS";
			cout<<endl<<"WINNINGS : "<<totv; (totp<2) ? cout<<" POUND" : cout<<" POUNDS";
			cout<<endl<<"winnings on bets : "<<totv/totp*100<<" %"<<endl;
			cout<<endl<<endl; system("pause"); cout<<endl;
			break;
}
}

//-------------------------------------------------------------------------------------------------------------------

void lanmenu(char l){
switch(l){
case 'i':	cout<<endl<<"1) Gioca alla Slot";
			cout<<endl<<"2) Gioca alla Roulette";
			cout<<endl<<"3) Gioca a Black Jack";
			cout<<endl<<"4) Gioca a Poker";
			cout<<endl<<"5) Statistiche";
			cout<<endl<<"6) Reset Statistiche";
			cout<<endl<<"7) Lingua";
			cout<<endl<<"0) Esci dal CASINO";
			cout<<endl<<"			        COSA VUOI FARE? :  ";
			break;

default:	cout<<endl<<"1) Play Slot";
			cout<<endl<<"2) Play Roulette";
			cout<<endl<<"3) Play Black Jack";
			cout<<endl<<"4) Play Poker";
			cout<<endl<<"5) Statistics";
			cout<<endl<<"6) Reset Statistics";
			cout<<endl<<"7) Language";
			cout<<endl<<"0) leave the CASINO";
			cout<<endl<<"			 WHAT DO YOU WANT TO DO? :  ";
			break;
}
}

void lanslotmenu(char l){
switch(l){
case 'i':	cout<<endl<<"Benvenuto alla Slot";
			cout<<endl<<"1) GIOCA";
			cout<<endl<<"2) Regole";
			cout<<endl<<"0) Esci da Slot : ";
			break;

default:	cout<<endl<<"Welcome to the Slot";
			cout<<endl<<"1) PLAY";
			cout<<endl<<"2) Rules";
			cout<<endl<<"0) Leave the Slot : ";
			break;
}
}

void punt(char l){
switch(l){
case 'i':	cout<<endl<<"Quanto vuoi puntare : "; break;
default:	cout<<endl<<"How much do you want to bet : "; break;
}
}

void ruleslot(char l){
switch(l){
case 'i':	cout<<endl<<endl<<"Se escono 4 numeri uguali vinci 200 VOLTE IL VALORE DELLA PUNTATA !-!";
			cout<<endl<<"Se escono 2 copie di numeri uguali vinci 10 VOLTE IL VALORE DELLA PUNTATA !-!";
			cout<<endl<<"Se escono 3 numeri uguali vinci 7,5 VOLTE IL VALORE DELLA PUNTATA !-!";
			cout<<endl<<"Se esce 1 copia di numeri uguali vinci 1,5 VOLTE IL VALORE DELLA PUNTATA !-!";
			break;

default:	cout<<endl<<endl<<"If you get 4 equal numbers, YOU GET 200 TIMES THE VALUE OF THE BET !-!";
			cout<<endl<<"If you get 2 couples of equal numbers, YOU GET 10 TIMES THE VALUE OF THE BET !-!";
			cout<<endl<<"If you get 3 equal numbers, YOU GET 7,5 TIMES THE VALUE OF THE BET !-!";
			cout<<endl<<"If you get 1 couple of equal numbers, YOU GET 1,5 TIMES THE VALUE OF THE BET !-!";
			break;
}
}

void ansplay(char l){
switch(l){
case 'i':	cout<<endl<<"GIOCARE? si/no : "; break;
default:	cout<<endl<<"PLAY? yes or y/no : "; break;
}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

void lanroulmenu(char l){
switch(l){
case 'i':	cout<<endl<<"Benvenuto alla Roulette";
			cout<<endl<<"1) GIOCA";
			cout<<endl<<"2) Regole";
			cout<<endl<<"0) Esci da Roulette : ";
			break;
			
default:	cout<<endl<<"Welcome to the Roulette";
			cout<<endl<<"1) PLAY";
			cout<<endl<<"2) Rules";
			cout<<endl<<"0) Leave the Roulette : ";
			break;
}
}

void lanroulpunt(char l){
switch(l){
case 'i':	cout<<endl<<"Puoi puntare su tutto cio che DESIDERI !-!-!"<<endl;
			cout<<endl<<"La puntata su UN numero paga 36 VOLTE IL VALORE DELLA PUNTATA !-!";
			cout<<endl<<"La puntata su DUE numeri paga 18 VOLTE IL VALORE DELLA PUNTATA !-!";
			cout<<endl<<"La puntata su TRE numeri paga 12 VOLTE IL VALORE DELLA PUNTATA !-!";
			cout<<endl<<"La puntata su QUATTRO numeri paga 9 VOLTE IL VALORE DELLA PUNTATA !-!";
			cout<<endl<<"La puntata su SEI numeri paga 6 VOLTE IL VALORE DELLA PUNTATA !-!";
			cout<<endl<<"La puntata su PRIMA/SECONDA/TERZA dozzina paga 3 VOLTE IL VALORE DELLA PUNTATA!";
			cout<<endl<<"Su COLORE,PARI/DISPARI,ALTO/BASSO pagano 2 VOLTE IL VALORE DELLA PUNTATA !";
			break;
			
default:	cout<<endl<<"The bet on 1 number pay 36 TIMES THE VALUE OF THE BET !-!";
			cout<<endl<<"The bet on 2 number pay 18 TIMES THE VALUE OF THE BET !-!";
			cout<<endl<<"The bet on 3 number pay 12 TIMES THE VALUE OF THE BET !-!";
			cout<<endl<<"The bet on 4 number pay 9 TIMES THE VALUE OF THE BET !-!";
			cout<<endl<<"The bet on 6 number pay 6 TIMES THE VALUE OF THE BET !-!";
			cout<<endl<<"The bet on FIRST/SECOND/THIRD dozen pay 3 TIMES THE VALUE OF THE BET !-!";
			cout<<endl<<"The bet on COLOR,EVEN/ODD,HIGHER/LOWER pay 2 TIMES THE VALUE OF THE BET !-!";
			break;
}
}

void lanroulgame(char l){
switch(l){
case 'i':	cout<<endl<<"Scegli la Tua Puntata"<<endl;
			cout<<endl<<"a) puntata su UN numero";
			cout<<endl<<"b) puntata su DUE numeri";
			cout<<endl<<"c) puntata su TRE numeri";
			cout<<endl<<"d) puntata su QUATTRO numeri";
			cout<<endl<<"e) puntata su SEI numeri";
			cout<<endl<<"f) puntata su PRIMA/SECONDA/TERZA dozzina";
			cout<<endl<<"g) puntate su COLORE";
			cout<<endl<<"h) puntate su PARI/DISPARI";
			cout<<endl<<"i) puntate su ALTO/BASSO";
			cout<<endl<<"o) per USCIRE";
			cout<<endl<<"Codice puntata scelta : ";
			break;
			
default:	cout<<endl<<"Choose your bet"<<endl;
			cout<<endl<<"a) Bet on ONE number";
			cout<<endl<<"b) Bet on TWO numbers";
			cout<<endl<<"c) Bet on THREE numbers";
			cout<<endl<<"d) Bet on FOUR numbers";
			cout<<endl<<"e) Bet on SIX numbers";
			cout<<endl<<"f) Bet on FIRST/SECOND/THIRD dozen";
			cout<<endl<<"g) Bet on COLOR";
			cout<<endl<<"h) Bet on EVEN/ODD";
			cout<<endl<<"i) Bet on HIGHER/LOWER";
			cout<<endl<<"o) EXIT";
			cout<<endl<<"Insert the letter corrispondent to your bet : ";
			break;
}
}

void laninsn(char l){
switch(l){
case 'i':	cout<<endl<<endl<<"Inserire un numero tra 0-36 : "; break;
default:	cout<<endl<<endl<<"Insert a number between 0-36 : "; break;
}
}

void lanscdoz(char l){
switch(l){
case 'i':	cout<<endl<<endl<<"Scegli la tua dozzna tra 1 (1-12)/ 2 (13-24) / 3 (25-36) : "; break;
default:	cout<<endl<<endl<<"Choose your dozen between 1 (1-12)/ 2 (13-24) / 3 (25-36) : "; break;
}
}

void lanscrn(char l){
switch(l){
case 'i':	cout<<endl<<endl<<"Scegli il tuo colore tra rosso o r / nero o n : "; break;
default:	cout<<endl<<endl<<"Choose your color between red or r / black or b : "; break;
}
}

void lanscpd(char l){
switch(l){
case 'i':	cout<<endl<<endl<<"Scegli tra pari o p / dispari o d : "; break;
default:	cout<<endl<<endl<<"Choose between even or e / odd or o : "; break;
}
}

void lanscab(char l){
switch(l){
case 'i':	cout<<endl<<endl<<"Scegli la tua meta di roulette tra basso o b (1-18)/ alto o a (19-36) : "; break;
default:	cout<<endl<<endl<<"Choose your half roulette between lower o l (1-18)/ higher o h (19-36) : "; break;
}
}

void esci(char l){
switch(l){
case 'i':	cout<<endl<<"Arrivederci"<<endl; break;
default:	cout<<endl<<"Goodbye"<<endl; break;
}
system("pause");
}

//black jack---------------------------------------------------------------------------------------------------------------------------------------------

void lanbjmenu(char l){
switch(l){
case 'i':	cout<<endl<<"Benvenuto a Black Jack";
			cout<<endl<<"1) GIOCA";
			cout<<endl<<"2) Regole";
			cout<<endl<<"0) Esci da Black Jack : ";
			break;

default:	cout<<endl<<"Welcome to the Black Jack";
			cout<<endl<<"1) PLAY";
			cout<<endl<<"2) Rules";
			cout<<endl<<"0) Leave the Black Jack : ";
			break;
}
}

void lanbjpunt(char l){
switch(l){
case 'i':	cout<<endl<<endl<<"GIOCA AL CARD GAME PIU AMATO NEI CASINO DI TUTTO IL MONDO";
			cout<<endl<<"Per vincere devi battere il banco a chi con le carte si avvicina piu a 21 senza superarlo";
			cout<<endl<<"tutti i numeri valgono la cifra sulla carta";
			cout<<endl<<"tutte le figure valgono 10";
			cout<<endl<<"L' asso vale 11 se la somma non supera 21 altrimenti il suo valore scende a 1";
			break;

default:	cout<<endl<<endl<<"PLAY AT THE MOST LIKED CARD GAME ALL AROUND THE WORLD";
			cout<<endl<<"For win you have to beat the house, who goes nearest to the score of 21 wins";
			cout<<endl<<"All numbers worth the digit on the card";
			cout<<endl<<"All figures worth 10 points";
			cout<<endl<<"The ace worth 11 if the sum of the points doesn't overcome 21"<<endl<<"otherwise the value is 1";
			break;
}
}

void lancom(char l){
switch(l){
case 'i':	cout<<endl<<endl<<"SCELTE :";
			cout<<endl<<endl<<"-	chiedere / c";
			cout<<endl<<"-	raddoppiare / r";
			cout<<endl<<"-	stare / s";
			cout<<endl<<endl<<"Cosa vuoi fare : ";
			break;

default:	cout<<endl<<endl<<"CHOISE :";
			cout<<endl<<endl<<"-	call / c";
			cout<<endl<<"-	double / d";
			cout<<endl<<"-	stay / s";
			cout<<endl<<endl<<"What do you want to do : ";
			break;
}
}

void psballo(char l){
switch(l){
case 'i':	cout<<endl<<endl<<"			       HAI SBALLATO"; break;
default:	cout<<endl<<endl<<"			         YOU BUSTED"; break;
}
lose(l);
}

void lose(char l){
switch(l){
case 'i':	cout<<endl<<endl<<"			      IL BANCO VINCE"; break;
default:	cout<<endl<<endl<<"			       THE HOUSE WON"; break;
}
}

void draw(float p,char l){
switch(l){
case 'i':	cout<<endl<<endl<<"			         PAREGGIO"; break;
default:	cout<<endl<<endl<<"			           DRAW"; break;
}
ofvinc(p,l);
}

void win(float p,char l){
switch(l){
case 'i':	cout<<endl<<endl<<"		   	     HAI VINTO "<<p*1.5<<" EURO"; break;
default:	cout<<endl<<endl<<"		   	     YOU WON "<<p*1.5<<" POUNDS"; break;
}
ofvinc(p*1.5,l);
}

void bsballo(float p,char l){
switch(l){
case 'i':	cout<<endl<<endl<<"			       IL BANCO HA SBALLATO"; break;
default:	cout<<endl<<endl<<"			      THE HOUSE BUSTED"; break;
}
win(p,l);
}
//LE SCRITTE TIPO <<BANCO>> O <<LE TUE CARTE>> SONO NELL BJ.CPP

void lanpokermenu(char l){
switch(l){
case 'i':	cout<<endl<<"1) GIOCA";
			cout<<endl<<"2) Regole";
			cout<<endl<<"0) Esci dal tavolo : ";
			break;

default:	cout<<endl<<"1) PLAY";
			cout<<endl<<"2) Rules";
			cout<<endl<<"0) Leave the table : ";
			break;
}
}

void lanblind(char l){
switch(l){
case 'i':	cout<<endl<<"Con che importo di small blind vuoi giocare? (si consiglia un valore basso) : "; break;
default:	cout<<endl<<"Which value of small blind do you want to play with?"<<endl<<"(a small value is raccomanded) : "; break;
}
}

void pkrules(char l){
switch(l){
case 'i':	cout<<endl<<endl<<"GIOCA AL CASH GAME PIU POPOLARE NEI CASINO DI TUTTO IL MONDO";
			cout<<endl<<"batti i tuoi avversari al tavolo con la combinazione di carte migliore";
			cout<<endl<<endl<<"			  PUNTEGGI MANO :";
			cout<<endl<<"			  Carta alta :	 0";
			cout<<endl<<"			  Copia :	 1";
			cout<<endl<<"			  Doppia copia : 2";
			cout<<endl<<"			  Tris :	 3";
			cout<<endl<<"			  Scala :	 4";
			cout<<endl<<"			  Colore :	 5";
			cout<<endl<<"			  Full House :	 6";
			cout<<endl<<"			  Poker :	 7";
			cout<<endl<<"			  Scala colore : 8";
			cout<<endl<<"			  Scala reale :	 9";
			cout<<endl<<endl<<"Se vengono giocate due mani con punteggi uguali vince quella con carte piu alte";
			cout<<endl<<endl<<"I bot non giocano tutti con lo stesso stile di gioco";
			cout<<endl<<endl<<"Il mazzo viene mescolato dopo ogni partita";
			cout<<endl<<endl<<"I bot possono cambiare stile di gioco";
			cout<<endl<<endl;
			system("pause");
			cout<<endl<<endl<<"SVOLGIMENTO DEL GIOCO :";
			cout<<endl<<"-	Ti verranno distribuite 2 carte";
			cout<<endl<<"-	Giro di puntate prima del flop";
			cout<<endl<<"-	Scoperte 3 carte comuni (FLOP)";
			cout<<endl<<"-	Giro di puntate prima del river";
			cout<<endl<<"-	Scoperta 1 carta comune (RIVER)";
			cout<<endl<<"-	Giro di puntate prima del turn";
			cout<<endl<<"-	Scoperta ultima carta comune (TURN)";
			cout<<endl<<"-	Giro di puntate prima dello showdown";
			cout<<endl<<"-	Scoperta delle carte avversarie e determinazione vincitore";
			cout<<endl<<endl;
			system("pause");
			cout<<endl<<endl<<"AZIONI :";
			cout<<endl<<"- fold  :  lascia le carte e abbandona la partita in corso";
			cout<<endl<<"- call  :  pareggia la puntata in corso e continua a giocare";
			cout<<endl<<"- raise :  rilancia la puntata in corso";
			cout<<endl<<"- check :  prima di una puntata puoi non puntare nulla e rimanere in gioco";
			cout<<endl<<"- bet   :  crea una puntata";
			cout<<endl<<endl;
			system("pause");
			cout<<endl<<endl<<"PUOI TROVARE MAGGIORI INFORMAZIONI ON-LINE";
			break;

default:	cout<<endl<<endl<<"PLAY AT THE MOST POPULAR CASH GAME OF THE WORLD";
			cout<<endl<<"Beat your enemys whith the best card combination";
			cout<<endl<<endl<<"			  CARDS COMBINATION :";
			cout<<endl<<"			  High card :	 0";
			cout<<endl<<"			  Copy :	 1";
			cout<<endl<<"			  Double copy : 2";
			cout<<endl<<"			  Tris :	 3";
			cout<<endl<<"			  Flush :	 4";
			cout<<endl<<"			  Color :	 5";
			cout<<endl<<"			  Full House :	 6";
			cout<<endl<<"			  Poker :	 7";
			cout<<endl<<"			  Straight flush : 8";
			cout<<endl<<"			  Royal flush :	 9";
			cout<<endl<<endl<<"If were played two equal card combinations the one with more valuable cards wins";
			cout<<endl<<endl<<"bots don't play with the same play style";
			cout<<endl<<endl<<"The deck is mixed after every match";
			cout<<endl<<endl;
			system("pause");
			cout<<endl<<endl<<"CONDUCT OF THE GAME :";
			cout<<endl<<"-	You 'll get 2 cards'";
			cout<<endl<<"-	First betting round before flop";
			cout<<endl<<"-	3 common cards were discovered (FLOP)";
			cout<<endl<<"-	Second betting round before river";
			cout<<endl<<"-	A common card was discovered (RIVER)";
			cout<<endl<<"-	Third betting round before turn";
			cout<<endl<<"-	A common card was discovered (TURN)";
			cout<<endl<<"-	Last betting round before showdown";
			cout<<endl<<"-	Showdown";
			cout<<endl<<endl;
			system("pause");
			cout<<endl<<endl<<"ACTIONS :";
			cout<<endl<<"- fold  :  leave the match";
			cout<<endl<<"- call  :  match the bet and continue";
			cout<<endl<<"- raise :  raise the current bet";
			cout<<endl<<"- check :  Before a bet you can continue to play without bet anything";
			cout<<endl<<"- bet   :  do a bet";
			cout<<endl<<endl;
			system("pause");
			cout<<endl<<endl<<"YOU CAN FIND MORE INFORMATIONS ON-LINE";
			break;
}
}

//TUTTO IL RESTO DELLE SCRITTE SUL POKER SI TROVANO IN POKER CPP

char chlan(char l){
char ans;
do{
switch(l){
case 'i':	cout<<endl<<"e) INGLESE";
			cout<<endl<<"i) ITALIANO";
			cout<<endl<<"x) Esci : ";
			cin>>ans;
			break;

default:	cout<<endl<<"e) ENGLISH";
			cout<<endl<<"i) ITALIAN";
			cout<<endl<<"x) Exit : ";
			cin>>ans;
			break;
}
}while(ans!='e' && ans!='i' && ans!='x');
return ans;
}
