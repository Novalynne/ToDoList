
#include "Register.h"
#include "Activity.h"

/*
 * (3) Registro di attività che memorizza cosa si è fatto durante una giornata.
 *     Classe che rappresenta attività con descrizione, tempo inizio e fine.
 *     Classe registro che colleziona attività su base del giorno.
 *     Interfaccia semplice per mostrare il registro sulla base di un giorno fatta a scelta con:
            nCurses
            wxWidgets
            QT
 */
using namespace std;
int main() {
    Register aRegister("calendario");
    Date date1= Date(12, 3, 2023);
    Date date2= Date(6,10,2023);
    Date date3= Date(18,7,2023);
    if(date1.is_date_correct()){
        Activity act1 = Activity(18,30,17,00, "fare la spesa", date1);
        aRegister.add_activity(act1);
    }
    if(date2.is_date_correct()){
        Activity act5 = Activity(7,15,13,00, "università", date2);
        Activity act2 = Activity(17,30,20,30, "uscita con amiche", date2);
        aRegister.add_activity(act2);
        aRegister.add_activity(act5);
    }
    if(date3.is_date_correct()){
        Activity act3 = Activity(12,40,15,20, "pranzo in famiglia", date3);
        Activity act4 = Activity(18,25,21,00, "study time", date3);
        Activity act6 = Activity(21,30,24,00, "D&D", date3);
        aRegister.add_activity(act3);
        aRegister.add_activity(act4);
        aRegister.add_activity(act6);
    }
    list<Activity> result= aRegister.search_activity_daybased(date3);
    aRegister.display_register(date3, result);
}
