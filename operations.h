#include <iostream>
#include "entierlong.h"
using namespace std;
extern bool addit_overflow;// bool pour indiquer un dépassement de capacité quand on teste la fct ds une boucle
t_EntierLong addit(t_EntierLong d, t_EntierLong e);
t_EntierLong soustra(t_EntierLong d, t_EntierLong e);
t_EntierLong addit_any(t_EntierLong d, t_EntierLong e);
t_EntierLong soustra_any(t_EntierLong d, t_EntierLong e);
t_EntierLong multi(t_EntierLong d, t_EntierLong e);
bool detect_le_1 (t_EntierLong d);
void division(t_EntierLong d, t_EntierLong e);
bool test_pareil(t_EntierLong d,t_EntierLong e);