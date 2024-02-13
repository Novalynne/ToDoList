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
void Register::display_register(Date d, list<Activity> result){
    initscr();
    cbreak();
    noecho();

    int height, width, start_y, start_x;
    height = 100;
    width = 300;
    start_x = start_y = 10;

    WINDOW * win= newwin(height,width, start_y, start_x);
    refresh();

    char c= '*';
    int i=5;
    box(win, (int)c, (int)c);
    mvwprintw(win, 2, 2, "Attività registrate nel giorno: %d %d %d  ", d.getDay(), d.getMonth(), d.getYear());
    mvwprintw(win, 3, 1, "---------------------------------------------------\n");
    list<Activity>::iterator itr;
    for (itr = result.begin(); itr != result.end(); itr++){
        mvwprintw(win, i, 1, "Descrizione: %s", (*itr).getDescription().c_str());
        mvwprintw(win, i+1, 1, "Tempo di inizio: %d : %d", (*itr).getBeginTimeH(), (*itr).getBeginTimeM());
        mvwprintw(win, i+2, 1, "Tempo di fine: %d : %d", (*itr).getEndTimeH(),(*itr).getEndTimeM());
        i=i+3;
    }
    mvwprintw(win, i+1, 1, "Hai visualizzato tutte le attività del giorno!");
    getch();
    endwin();
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