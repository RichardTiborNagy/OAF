#include "naplo.h"

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Naplo::Naplo(const std::string& osztnev){
    head = new tanulo;
    head->nev = osztnev;
}

Naplo::~Naplo(){
    tanulo *p,*q;
    q = head;
    while(q!=NULL){
        p = q;
        q = q->next;
        delete p;
    }
}

ifstream& operator>> (ifstream& s, Naplo& n){
    tanulo* q = n.head;
    while (!s.fail()){
        string nev;
        int jegydb;
        s >> nev >> jegydb;
        if (s.fail()) continue;
        q->next = new tanulo;
        q = q->next;
        q->nev = nev;
        for (int i = 0; i < jegydb; ++i){
            string targynev;
            int jegy;
            s >> targynev >> jegy;
            par p(targynev, jegy);
            q->osztalyzatok.push_back(p);
        }
    }
    return s;
}

ostream& operator<< (ostream& s, const Naplo& n){
    s << n.head->nev << " naplo tartalma:" << endl << endl;
    tanulo* q;
    q = n.head->next;
    while (q!=NULL){
        s << "Tanulo: " << q->nev << endl;
        int atlag = 0;
        for (int i = 0; i < q->osztalyzatok.size(); ++i){
            s << "\t" << q->osztalyzatok[i].targy << " " << q->osztalyzatok[i].jegy <<endl;
            atlag += q->osztalyzatok[i].jegy;
        }
        if (atlag !=0 ) atlag /= q->osztalyzatok.size();
        s << "Atlaga: " << atlag << endl << endl;
        q = q->next;
    }
    return s;
}

void Naplo::Beszur(const std::string& tkod, const std::string& targy, int jegy){
    tanulo *q,*p;
    par x(targy, jegy);
    if (jegy > 5 || jegy < 1){
        throw ROSSZJEGY;
        return;
    }
    q = head;
    p = q->next;
    while (p != NULL && p->nev < tkod){
        q = p;
        p = p->next;
    }
    if (p == NULL){
        q->next = new tanulo;
        p = q->next;
        p->nev = tkod;
        p->osztalyzatok.push_back(x);
    } else if( p->nev == tkod){
        p->osztalyzatok.push_back(x);
    } else {
        tanulo * z = new tanulo;
        z->osztalyzatok.push_back(x);
        z->nev = tkod;
        z->next = p;
        q->next = z;
    }
}

void Naplo::Torol(const std::string& tkod){
    tanulo *q,*p;
    q = head;
    p = head->next;
    while (p != NULL && p->nev != tkod){
        q = p;
        p = p->next;
    }
    if (p == NULL) std::cout << tkod << " kodu tanulo torlese sikertelen!" << endl ;
    else {
        q->next = p->next;
        delete p;
    }
}

Naplo::Naplo(const Naplo&n){
    head = new tanulo;
    head->nev = n.head->nev;
    tanulo *q, *p;
    q = n.head->next;
    p = head;
    while (q != NULL){
        p->next = new tanulo;
        p = p->next;
        p->nev = q->nev;
        p->osztalyzatok = q->osztalyzatok;
        q = q->next;
    }
}

void Naplo::Fordit(){
    tanulo *p, *q;
    p = head->next;
    head->next = NULL;
    while (p!=NULL){
        q = p;
        p = p->next;
        q->next = head->next;
        head->next = q;
    }
}

void Naplo::Dolgozat(const Naplo& doga){
    tanulo *p, *q;
    p = doga.head->next;
    q = head->next;
    while (q != NULL && p!= NULL){
        if (q->nev < p->nev) {
            q = q->next;
        } else if (p->nev < q->nev){
            cout << "Hibas tanulo azonosito: " << p->nev << endl;
            p = p->next;
        } else if (p->nev == q->nev){
            Beszur(p->nev, p->osztalyzatok[0].targy, p->osztalyzatok[0].jegy);
            p = p->next;
            q = q->next;
        }
    }
    while (p != NULL){
        cout << "Hibas tanulo azonosito: " << p->nev << endl;
        p = p->next;
    }
}
