#include <iostream>
#include "lit_ecrit.h"
#include "utilitaires.h"
#include "cmath"
using namespace std;



t_EntierLong conversion(int b){
 t_EntierLong e{}; //initialisation a zero de tous les chiffres
  if (b<0)//nombre negatif
{e.negatif=true;
b=-b;//on rend le nombre positif pour la suite
}
 int ok = log10(b);
 int sizing=(ok % 10)+1;//nombre de chiffres du nombre
 


for (int i=0;i<sizing;i++)//remplissage des chiffres

{ 
    if(i==0){//cas du chiffre le plus significatif, on divise par une puissance de 10, et on récupère la partie entière
    int numberaouter = int(b/pow(10, sizing-1-i));
    e.chiffres[sizing-1-i]=numberaouter;}
    else {//cas des autres chiffres, on divise par une puissance de 10, et on récupère le reste de la division par 10
    
    e.chiffres[sizing-1-i]=int(b/pow(10, sizing-1-i))%10;}
    }
 return e;
}


bool testégalité(t_EntierLong d, t_EntierLong e) {

if (d.negatif!=e.negatif){//les signes sont differents

    return false;
}

for (int i=0;i< MAXCHIFFRES;i++)//on compare chaque chiffre
{ if (d.chiffres[i]!=e.chiffres[i])
{ return false;}
}

return true;//les deux nombres sont égaux
}
bool testgrandeur(t_EntierLong d, t_EntierLong e){

for (int i=MAXCHIFFRES-1;i>=0;i--)//on compare chaque chiffre du plus significatif au moins significatif entre d et e
{ if (d.chiffres[i]<e.chiffres[i])
 {
return false;}
 else if(d.chiffres[i]>e.chiffres[i])
{
return true;}
}


return true;//les deux nombres sont égaux on retuurn true
}