//
// Created by schir on 13/02/2024.
//

#include "Register.h"
using namespace std;

//COSTRUTTORE
Register::Register(string name) : name(name) {}

//SEARCH DATE
list<Activity> Register::search_activity_daybased (Date d){
    list<Activity>::iterator itr;
    list<Activity> result;
    for(itr=reg.begin(); itr != reg.end(); itr++){
        if(d.is_equal(itr->getDate())){
            result.push_back(*itr);
        }
    }
    return result;
}

//DISPLAY
int Register::display_register(Date d, list<Activity> result){
    initscr();
    printw("Attività registrate nel giorno: %d %d %d \n", d.getDay(), d.getMonth(), d.getYear());
    printw("---------------------------------------------------\n");
    list<Activity>::iterator itr;
    for (itr = result.begin(); itr != result.end(); itr++){
        printw("Descrizione: %s\n", (*itr).getDescription().c_str());
        printw("Tempo di inizio: %d : %d\n", (*itr).getBeginTimeH(), (*itr).getBeginTimeM());
        printw("Tempo di fine: %d : %d\n", (*itr).getEndTimeH(),(*itr).getEndTimeM());
        printw("---------------------------------------------------\n");
    }
    printw("Hai visualizzato tutte le attività del giorno!");
    refresh();
    getch();
    endwin();
    return 0;
}
//DELETE_ACTIVITY
void Register::delete_activity(Activity activity) {
    list<Activity>::iterator itr;
    bool found=false;
    for(itr=reg.begin(); itr != reg.end(); itr++){
        if((*itr).is_equal(activity)){
            reg.erase(itr);
            found=true;
            itr=reg.end();
        }
    }
    if(found==false){
        cout<< "Error. Activity not found in your register" <<endl;
    }

}

//GETTER
list<Activity> Register::getReg() const {
    return reg;
}
const string &Register::getName() const {
    return name;
}

//SETTER
void Register::setReg(const list<Activity> &reg) {
    Register::reg = reg;
}
void Register::setName(const string &name) {
    Register::name = name;
}