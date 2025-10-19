#include <iostream>
#include "lit_ecrit.h"
#include "utilitaires.h"
#include "operations.h"


using namespace std;

// If lit_ecrit.cpp declares functions like lire() / ecrire(), include its header here
// #include "lit_ecrit.h"

t_EntierLong grandNombre{};


int main() {
    t_EntierLong risult{};
    
    
    t_EntierLong verif{};
    t_EntierLong verif2{};
    afficheEntierLong(risult);
    addit_overflow=false;//remise a false pour la suite
    grandNombre.chiffres[19] = 1;
    
    afficheEntierLong(addit(conversion(200000000), conversion(90000000)));
    while (addit_overflow==false)
    { grandNombre=addit(grandNombre, grandNombre);
     
    }
    
    cout<<endl;
    afficheEntierLong(addit_any(conversion(-100), conversion(120)));
    afficheEntierLong(soustra_any(conversion(200), conversion(100)));
    afficheEntierLong(soustra_any(conversion(-240), conversion(-100)));
    afficheEntierLong(soustra_any(conversion(240), conversion(300)));
    afficheEntierLong(soustra_any(conversion(-240), conversion(-300)));
    afficheEntierLong(soustra_any(conversion(-240), conversion(300)));
    afficheEntierLong(soustra_any(conversion(240), conversion(-300)));
    afficheEntierLong(multi(conversion(456), conversion(767)));
    division(conversion(9567),conversion(9));

    addit_overflow=false;//remise a false pour la suite
    t_EntierLong fibionacci2{};
    fibionacci2.chiffres[0]=1;
    t_EntierLong fibonacci1{};
    for (int i=2;i<61;i++)
    { 
        if(addit_overflow==false){
    risult=addit(fibonacci1, fibionacci2);
    fibonacci1=fibionacci2;
    fibionacci2=risult;
      
    if(i==59||i==58||i==60){
        cout<<"le terme"<<i<<endl;
        afficheEntierLong(risult);
          cout<<endl;} 
    
          if(i==60){verif=risult;}

     if(i==59){verif2=risult;}          }}

     cout<<"soustraction du terme 60 et 59"<<endl;

    afficheEntierLong(soustra(verif,verif2));
    return 0;
}