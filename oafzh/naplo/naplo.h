#ifndef NAPLO_H_INCLUDED
#define NAPLO_H_INCLUDED

#include <vector>
#include <string>
#include <fstream>
using namespace std;


struct par {
    string targy;
    int jegy;
    par(string t, int j) {
        targy = t;
        jegy = j;
    }
};

struct tanulo {
    string nev;
    vector<par> osztalyzatok;
    tanulo* next;
    tanulo(){
        next=NULL;
    }
};

class Naplo {
private:
    tanulo* head;
public:
    Naplo(const std::string& osztnev);
    ~Naplo();
    friend ostream& operator<< (ostream &s, const Naplo& n);
    friend ifstream& operator>> (ifstream &s, Naplo& n);
    void Beszur(const std::string& tkod, const std::string& targy, int jegy);
    enum Exceptions {ROSSZJEGY};
    void Torol(const std::string& tkod);
    Naplo(const Naplo&n);
    void Fordit();
    void Dolgozat(const Naplo& doga);
};

#endif // NAPLO_H_INCLUDED
