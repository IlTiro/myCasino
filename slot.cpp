#include "slot.h"
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<fstream>
using namespace std;
slot::slot(){
srand((unsigned)time(NULL));
n1=rand()%10;
n2=rand()%10;
n3=rand()%10;
n4=rand()%10;
}
