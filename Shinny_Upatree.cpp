// Proiect realizat de Alexandra Camarasan, Monica Burcusel, Rares Bunda

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    struct cadou{
    int euro, kg;
    float x,y;
    char nume[30];}cadou[100];
     cout << " *   *  ****  ***   ***   *   *"<<endl<<
         " ** **  *     *  *  *  *   * *"<<endl<<
         " * * *  ***   ***   ***     *"<<endl<<
         " *   *  *     * *   * *     *"<<endl<<
         " *   *  ****  *  *  *  *    *"<<endl<<


" ***   *  *  ***   *  ****  *****  *   *   **   **** "<<endl<<
"*   *  *  *  *  *  *  *       *    ** **  *  *  *"<<endl<<
"*      ****  ***   *  ****    *    * * *  ****  ****"<<endl<<
"*   *  *  *  * *   *     *    *    *   *  *  *     *"<<endl<<
 " ***   *  *  *  *  *  ****    *    *   *  *  *  ****"<<endl;


    cout<<"Cator copii trebuie sa livreze Mos Craciun cadouri? ";
    int n,i,a;
    cin>>n;
    for (i=0;i<n;i++){
        cout<<"Care este numele copilului? ";
        cin.get();
        cin.getline(cadou[i].nume,30);
        cout<<"Cat costa cadoul (in euro) ? ";
        cin>>cadou[i].euro;
        cout<<"Cat de greu este cadoul (in kg) ? ";
        cin>>cadou[i].kg;
        cout<<"Care sunt coordonatele copilului (x si y) ? ";
        cin>>cadou[i].x;
        cin>>cadou[i].y;
    }
    int raspuns=10;
    while(raspuns!=0){
        cout<<"=================================================================="<<endl;
        cout<<"Apasati tasta 1 pentru a afla care este cel mai cuminte copil"<<endl;
        cout<<"Apasati tasta 2 pentru a afla de cati reni are nevoie mosul"<<endl;
        cout<<"Apasati tasta 3 pentru a adauga un cadou in lista"<<endl;
        cout<<"Apasati tasta 4 pentru a elimina un cadou din lista"<<endl;
        cout<<"Apasati tasta 5 pentru a determina lungimea traseului mosului"<<endl;
        cout<<"Apasati tasta 0 pentru a iesi din program :("<<endl;
        cin>>raspuns;
        if(raspuns==1){
                int euromax= cadou[0].euro;
                if(n>1){
                for(i=1;i<n;i++){
                            if(cadou[i].euro>euromax) {(euromax=cadou[i].euro)&&(a=i);}}
                            }
                else a=0;
                cout<<"Copilul cel mai cuminte, adica cel care va primi cadoul cel mai scump, este "<<cadou[a].nume<<endl;

        }
        else if (raspuns==2){
            int nrreni;
            float totreni=0;
            for(i=0;i<n;i++){
                totreni=totreni+cadou[i].kg;
                }
            nrreni=ceil(totreni/100);
            if(nrreni>1)cout<<"Mosul are nevoie de "<<nrreni<<" reni"<<endl;
            else cout<<"Mosul are nevoie de un ren"<<endl;

        }
        else if (raspuns==3){
            cout<<"Oops! Ai uitat cumva de un cadou? Adauga-l acum in lista. Repede! Pana mosul nu pleaca fara acesta :O. Care este numele copilului?";
            cin.get();
            cin.getline(cadou[n].nume,30);
            cout<<"Cat costa cadoul (in euro)? Ai grija, mai uitucule! Sa nu fie prea scump >.< ";
            cin>>cadou[n].euro;
            cout<<"Cat de greu este cadoul (in kg) ? Pe mos deja il doare spatele!";
            cin>>cadou[n].kg;
            cout<<"Care sunt coordonatele copilului (x si y)?";
            cin>>cadou[n].x;
            cin>>cadou[n].y;
            n=n+1;
        }
        else if(raspuns==4){
            float a1,b;
            cout<<"Care sunt coordonatele copilului pe care il doriti eliminat?";
            cin>>a1>>b;
            int gasit = 0;
            for(i=0;i<n;i++){
                if ((cadou[i].x==a1)&&(cadou[i].y==b)) {
                    gasit=1;
                }
                else {
                     if (gasit != 0) {
                        // L-am gasit
                        cadou[i-1]=cadou[i];
                    }
                }

            }
           n=n-1;
        }
        else if(raspuns==5){

             for(i=0;i<n-1;i++){
                    for(int j=i+1;j<n;j++){
                        if(strcmp(cadou[i].nume,cadou[j].nume)>0){
                            swap (cadou[i].nume,cadou[j].nume);
                        }
                    }
                }
                float t=0;
                for(i=0;i<n-1;i++){
                    t=t+sqrt((cadou[i].x-cadou[i+1].x)*(cadou[i].x-cadou[i+1].x)+(cadou[i].y-cadou[i+1].y)*(cadou[i].y-cadou[i+1].y));
                }
                cout<<"Traseul total este "<<t<<endl;

        }
        else if(raspuns==0)cout<<"Ati ales sa iesiti"<<endl;
        else cout<<"Alegere invalida"<<endl;
    }

return 0;
}
