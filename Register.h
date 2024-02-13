//
// Created by schir on 13/02/2024.
//

#ifndef TODOLIST_REGISTER_H
#define TODOLIST_REGISTER_H

#include <list>
#include <iostream>
#include <curses.h>
#include <string>
#include "Activity.h"
using namespace std;

class Register {
public:
    //COSTRUTTORE
    Register(string name);

    //GETTER
    list<Activity> getReg() const;
    const string &getName() const;

    //SETTER
    void setReg(const list<Activity> &reg);
    void setName(const string &name);

    //SEARCH DAYBASED
    list<Activity> search_activity_daybased (Date d); //funzione che mi ricerca il giorno nel registro

    //ADD_ACTIVITY
    void add_activity(const Activity& activity){
        reg.push_back(activity);
    }

    //DISPLAY
    int display_register(Date d, list<Activity> result);


private:
    list<Activity> reg;
    string name;
};

#endif //TODOLIST_REGISTER_H
