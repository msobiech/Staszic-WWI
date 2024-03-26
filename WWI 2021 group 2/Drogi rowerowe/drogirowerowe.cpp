#include <iostream>
#include <vector>
using namespace std;


const int MAXN = 5e5+5;

vector<int> G[MAXN]; //lista sąsiedztwa grafu
vector<int> T[MAXN]; //lista sąsiedztwa grafu transponowanego
vector<int> S[MAXN]; //lista sasiedztwa grafu silnych spojnych
bool vis[MAXN]; //tablica odwiedzenia DFS_post
vector<int> post; //vector w którym zapisuję kolejność postorder
int scc[MAXN]; //tablica, w której wierzchołkom przypisuje numer ich silnie spójnej, jeśli jest 0 to wierzchołek jeszcze nie ma silnie spójnej
int licznik = 1; //zmienna do numerowania silnie spójnych
int ilewspj[MAXN];// tablica, w ktorej zapisuje wielkosc spojnych
int dyn[MAXN];//tablica, w ktorej zapisuje wartosci ile spojna o id x ma dostepnych wierzcholkow

void DFS_post (int v){ //DFS wyznaczenia kolejności postorder

    vis[v] = true;
    for(auto i: G[v]){
        if(!vis[i])
            DFS_post(i);
    }
    post.push_back(v); // wychodzimy z wierzchołka, czyli trzeba dopisac go do xvectora post
}

void DFS_scc (int v){ //DFS na grafie transponowanym, "wciąga" do silnie spójnej
    scc[v] = licznik; //ustawiamy silnie spójną wierzchołka v na licznik
    ilewspj[licznik]++;
    for(auto i: T[v]){
        if(vis[i] && !scc[i]) //sprawdzamy, czy odwiedzony post i nie ma silnie spójnej - czyli można z i przejść do v
            DFS_scc(i);
    }
}
void DFS_dyn (int v){ //DFS na grafie silnych spojnych liczy
    dyn[v]=0;
    for(int i = 0;i<S[v].size();i++){
        DFS_dyn(S[v][i]);
        dyn[v]+=dyn[S[v][i]];
        //cout << "Ustawiam " << v << " na "<< dyn[v] << endl;
    }
    dyn[v]+=ilewspj[v];
}


int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    //czytamy dane i konstruujemy graf i graf transponowany
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        G[a].push_back(b);
        T[b].push_back(a);
    }
    //przetwarzamy kolejne wierzchołki
    for(int i = 1; i <= n; i++){
        if(!vis[i]){ //sprawdzenie, czy wierzchołek nie był przerobiony
            DFS_post(i); //generowanie vectora post
            while(!post.empty()){ //idziemy w kolejności odwrotnej postorder - od końca vectora post
                int tmp = post[post.size() - 1];
                post.pop_back(); //wyrzucamy ostatni element
                if(scc[tmp] == 0){//jeśli nie ma silnie spójnej, to ją wyznaczamy
                    DFS_scc(tmp);
                    licznik++; //wyznaczyliśmy nową silnie spójną, kolejna ma mieć kolejny nr - zwiększamy licznik
                }
            }
            //teraz vector post jest pusty i wszystko co na nim było jest przerobione i ma swoją silnie spójną
        }
    }
    //teraz mamy wyznaczone silnie spójne c:
    licznik--;//od teraz licznik wskazuje ile mam spojnych
    //cout << endl;
    //cout << licznik << endl;
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<G[i].size();j++){
            if(scc[G[i][j]]!=scc[i]){
                S[scc[i]].push_back(scc[G[i][j]]);
                //cout << "Lacze " << scc[i] << " z " << scc[G[i][j]] << endl;
            }
        }
    }
    for(int i = 1;i<=licznik;i++){
        //cout << dyn[i] << endl;
        dyn[i]=-1;
        //cout << ilewspj[scc[i]]-1<< endl;
    }
    for(int i = 1;i<=licznik;i++){
        //cout << dyn[i] << endl;
        if(dyn[i]==-1){
            DFS_dyn(i);
        }
        //cout << ilewspj[scc[i]]-1<< endl;
    }
    for(int i = 1;i<=n;i++){
        cout << dyn[scc[i]]-1 << endl;
    }


}