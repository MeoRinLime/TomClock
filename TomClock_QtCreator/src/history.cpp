#include "history.h"

History::History()
{

}
QDate History::getDate(){
    return date;
}

QString History::getName(){
    return name;
}

int History::getNumOfTomato(){
    return numOfTomato;
}

QTime History::getTotalTime(){
    return totalTime;
}

void History::setDate(QDate Date){
    date=Date;
}

void History::setName(QString Name){
    name=Name;
}

void History::setNumOfTomato(int n){
    numOfTomato=n;
}

void History::setTotalTime(QTime t){
    totalTime=t;
}
