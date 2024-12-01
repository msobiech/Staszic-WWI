#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int tab[1000001];
int pom[1000001];
set<int>a;
int inv = 0;
int scal(int p, int s, int k)
{
    int inv = 0;

    int i = p;
    int j = s;
    int t = p;
    while(i <= s-1 && j<=k){
        if(tab[i]<=tab[j]){
            pom[t]=tab[i];i++;
        }
        else{
            pom[t]=tab[j];j++;
            inv = inv+(s-i);
        }
        t++;
    }


    while (i <= s-1)
        pom[t++] = tab[i++];
    while (j<=k)
        pom[t++] = tab[j++];
    for (i = p; i <= k; i++)
        tab[i] = pom[i];

    return inv;
}

int mergesort(int lewy, int prawy)
{
    int inv = 0;
	if(prawy>lewy){
        int srodek = (prawy+lewy)/2;
        inv+=mergesort(lewy, srodek);
        inv+=mergesort(srodek+1, prawy);
        inv+=scal(lewy, srodek+1, prawy);

	}
	return inv;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n;

	cin>>n;
	for(int i=0;i<n;i++){
        cin>>tab[i];
    }
	int odp = mergesort(0,n-1);
	cout << odp;

	return 0;
}