#include "pos.h"
using namespace std;

int main() {
    init();
    char res = naprzod();
    if(res!='b'){
        prawo();
        prawo();
        res = naprzod();
    }
    while(res=='b'){
        res = naprzod();
    }
    if(res=='d'){
        prawo();
        prawo();
        res = naprzod();
    }
    prawo();
    res = naprzod();
    if(res!='b'){
        prawo();
        prawo();
        res=naprzod();
    }
    while(res=='b'){
        res = naprzod();
    }
    if(res=='d'){
        prawo();
        prawo();
        res = naprzod();
    }
    int d = 1;
    res = naprzod();
    while(res == 'd'){
        res = naprzod();
        d++;
    }
    int b = 1;
    while(res == 'b'){
        res = naprzod();
        b++;
    }
    prawo();
    prawo();
    naprzod();
    if(b>d){
        szukaj();
    }
    else{
        res = naprzod();
        while(res == 'd'){
            res = naprzod();
        }
        while(res=='b'){
            res = naprzod();
        }
        prawo();
        prawo();
        naprzod();
        szukaj();

    }

    return 0;
}