#include <iostream>
using namespace std;
const int MAXN = 2e5+1;
struct element{
    element* nextelement;
    element* previouselement;
    int value;//value of current element
};

element* question[MAXN];
element* start;
element* ending;
int len;

element* addtostart(int x){
    element* element1 = new element;
    element1->value = x;
    element1->previouselement = element1;
    if(len!=0){
        element1->nextelement = start;
    }
    else {
        element1->nextelement = element1;
    }
    (*element1).nextelement -> previouselement = element1;
    start = element1;
    if(!len){
        ending = element1;
    }
    len++;
    return element1;
}

void deletefromstart(){
    len--;
    if(len==0){
        start = nullptr;
        ending = start;
    }
    else{
        ((*start).nextelement)->previouselement=(*start).nextelement;
        start = (*start).nextelement;
    }

}

void deleteelement(element* todelete){
    if(todelete!=start && todelete !=ending){
        element* next = (*todelete).nextelement;
        element* prev = (*todelete).previouselement;
        next->previouselement = prev;
        prev->nextelement = next;
        len--;
    }
    else if(todelete == start){
        deletefromstart();
    }
    else if(len!=1){
        len--;
        (*ending).previouselement->nextelement=(*ending).previouselement;
        ending = (*ending).previouselement;
    }
    else{
        start = nullptr;
        len = 0;
        ending = start;
    }
    delete todelete;
}

element* addelementrightafter(element* elementtoaddafter, int x){
    len++;
    element* element1 = new element;
    if(elementtoaddafter!=ending){
        //cout << "not ending\n";
        element* next = (*elementtoaddafter).nextelement;
        element1->value = x;
        element1->previouselement = elementtoaddafter;
        element1->nextelement = next;
        elementtoaddafter->nextelement=element1;
        next->previouselement=element1;
    }
    else{
        //cout << "ending\n";
        element1->value = x;
        element1->previouselement = elementtoaddafter;
        element1->nextelement = element1;
        ending = element1;
        elementtoaddafter->nextelement=element1;
    }
    return element1;
}
int main(){
    start = nullptr;
    ending = start;
    len = 0;
    int q;
    cin >> q;
    for(int i = 1;i<=q;i++){
        char task;
        cin >> task;
        if(task=='>'){
            int x;
            cin >> x;
            question[i]=addtostart(x);
            //cout << i << " " << question[i] << endl;
        }
        else if(task=='<'){
            deletefromstart();
        }
        else if(task=='-'){
            int it;
            cin >> it;
            deleteelement(question[it]);
        }
        else{
            int it,x;
            cin >> x >> it;
           // cout << it << " " <<  question[it] << endl;
            //cout << (*question[it]).value << endl;
            question[i] = addelementrightafter(question[it],x);
        }
        //if(start!=nullptr)cout << (*start).value << " " << (*ending).value << endl;
    }
    element* i;
    if(start == nullptr && ending == start && len == 0){
        //cout << "EMPTY\n";
        return 0;
    }
    for(i = start;i!=ending;){
        cout << (*i).value << " ";
        i = (*i).nextelement;
    }
    cout << (*i).value;
}