#include <iostream>
#include "lit_ecrit.h"
#include "operations.h"
#include "utilitaires.h"

#include "cmath"
using namespace std;
bool addit_overflow = false;

t_EntierLong addit(t_EntierLong d, t_EntierLong e){//addition de deux entier long de meme signe
t_EntierLong numbere{};//initialisation a zero de tous les chiffres
int addi;


if (d.negatif!=e.negatif)//verification que les deux nombres sont de meme signe
{cout<<"entrez des nombres du meme signe";



    return numbere;}


for (int i=0;i<= MAXCHIFFRES-1;i++)//addition chiffre par chiffre

{  addi=d.chiffres[i]+e.chiffres[i];//somme des deux chiffres
    
    if (i==MAXCHIFFRES-1 && addi+numbere.chiffres[i]>=10)//gestion du dépassement de capacité
    {cout<<"deppassement de capacite";
       addit_overflow = true;
       break;
    }
    
    
    if (addi+numbere.chiffres[i]<10)//pas de retenue
   { 
        numbere.chiffres[i]=numbere.chiffres[i]+addi;   }//cas sans retenue
   
   else if (numbere.chiffres[i]+addi>=10)//cas avec retenue
    {numbere.chiffres[i]=(numbere.chiffres[i]+addi)%10;
    numbere.chiffres[i+1]+=1;}

    



}
if (d.negatif && e.negatif)//les deux nombres sont negatifs
{numbere.negatif=true;}
else{numbere.negatif=false;}//les deux nombres sont positifs
return numbere;}

t_EntierLong soustra(t_EntierLong d, t_EntierLong e){
t_EntierLong numbere{};//initialisation a zero de tous les chiffres
int retenue=0;//retenue pour la soustraction

if (testgrandeur(d,e)==false || d.negatif!=e.negatif)//verification que |d|>=|e| et que les deux nombres sont de meme signe
{cout<<"entrez des nombres tel que |d|=>|e|et de meme signe"<<endl;



    return numbere;}

for (int i=0;i<= MAXCHIFFRES-1;i++)//soustraction chiffre par chiffre
{ 
    
    if(d.chiffres[i]>=e.chiffres[i])//no retenue
 {numbere.chiffres[i]=d.chiffres[i]-e.chiffres[i]-retenue;
retenue=0;}
  else{numbere.chiffres[i]=d.chiffres[i]+10-e.chiffres[i]-retenue;
retenue=1;}//cas avec retenue
}

if(d.negatif && e.negatif==true)//les deux nombres sont negatifs
{numbere.negatif=true;}//
else{numbere.negatif=false;}//les deux nombres sont positifs

return numbere;
}

t_EntierLong addit_any(t_EntierLong d, t_EntierLong e){//addition de deux entier long de signe quelconque

if (d.negatif==e.negatif)//les deux nombres sont de meme signe
{return addit(d,e);}

else if(d.negatif==true && testgrandeur(d,e)==true)//d est negatif et |d|>|e|
{ e.negatif=true;
    return soustra(d,e);
}
else if(d.negatif==true && testgrandeur(d,e)==false)//d est negatif et |d|<|e|
{d.negatif=false;
return soustra(e,d);}
else if(e.negatif==true&& testgrandeur(d,e)==true)//e est negatif et |d|>|e|
{e.negatif=false;
return soustra(d,e);}
else{ d.negatif=true;//e est negatif et |d|<|e|
 return   soustra(e,d);
}
}

t_EntierLong soustra_any(t_EntierLong d, t_EntierLong e){//soustraction de deux entier long de signe quelconque

    if (d.negatif==e.negatif && testgrandeur(d,e)==true)//les deux nombres sont de meme signe et |d|>=|e|
    {return soustra(d,e);}
    else if ((d.negatif)==(e.negatif)&&e.negatif==false&& testgrandeur(d,e)==false)//les deux nombres sont de meme signe et positif et |d|<|e|
    {d.negatif=e.negatif=true;
    return soustra(e,d);}
    else if ((d.negatif)==(e.negatif)&&e.negatif==true&& testgrandeur(d,e)==false)//les deux nombres sont de meme signe et negatif et |d|<|e|
    {d.negatif=e.negatif=false;
    return soustra(e,d);}
    else if(d.negatif==true&& e.negatif==false)//d est negatif et e est positif
    { e.negatif=true;
        return addit(d,e);}
    else{//d est positif et e est negatif
        e.negatif=false;
        return addit(d,e);
    }
  return d;   
}
t_EntierLong multi(t_EntierLong d, t_EntierLong e){//multiplication de deux entier long de signe positif
t_EntierLong resultat{};//initialisation a zero de tous les chiffres
t_EntierLong décompteur{};//entier long servant a décrémenter e
décompteur.chiffres[0]=1;//initialisation de décompteur a 1

if (detect_le_1(e)==true)//cas ou e==1
{return d;}
resultat=d;//initialisation du resultat a d
while(detect_le_1(e)==false)//tant que e>1
{
resultat=addit(resultat,d);//ajout de d au resultat
e=soustra(e,décompteur);//decrementation de e de 1
}
return resultat;
}

bool detect_le_1 (t_EntierLong d)//detection si d est egal a 1
{bool condi=false;//condition pour verifier si d est egal a 1
    for (int i=MAXCHIFFRES-1;i>=1;i--)//verification que tous les chiffres sauf le moins significatif sont nuls
{if(d.chiffres[i]!=0){condi=true;}}
if(d.chiffres[0]==1&&condi==false)//le chiffre le moins significatif est 1 et les autres sont nuls
{return true;}//d est égal à 1
return false;//d n'est pas egal a 1
}


void division(t_EntierLong d, t_EntierLong e)//division de deux entier long positifs

{t_EntierLong en_cours;//entier long servant a stocker les multiples de e
 int compteur=1;//compteur du quotient
    if (d.negatif!=e.negatif)//verification que les deux nombres sont de meme signe
    {cout<<"entrez des nombres du meme signe"<<endl;}
 if (e.negatif==true)//verification que e et d sont positif, on verifie que e car la condition d avant assure qu ils sont de meme signe
 {cout<<"entrez des nombres postifs"<<endl;}

 if (testgrandeur(d,e)==false)//cas ou d<e
{cout<<"le quotient est 0 et le reste est"<<endl;
    afficheEntierLong(d);}

if (testégalité(d,e)==true)//cas ou d==e
{cout<<"le quotient est 1 et le reste est 0"<<endl;
    }
en_cours=e;//initialisation de en_cours a e
while(testgrandeur(d,en_cours)==true && test_pareil(d,en_cours)==false)//tant que en_cours<d
{compteur+=1;//incrementation du quotient
    en_cours=addit(en_cours,e);//ajout de e à en_cours
 
}
t_EntierLong reste=soustra(d,en_cours);//calcul du reste
cout<<"le quotient est"<< compteur<<endl;
cout<<"le reste est"<<endl;
afficheEntierLong(reste);

}


bool test_pareil(t_EntierLong d, t_EntierLong e)//la meme fonction que testégalité, j'avais oublié que j'avais fait testégalité
{bool vali= true;
    for (int i=0;i<= MAXCHIFFRES-1;i++)
{if (d.chiffres[i]!=e.chiffres[i])
{vali=false;}}
return vali; }