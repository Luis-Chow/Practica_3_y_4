#include<iostream>
#include<cmath>
using namespace std;

struct Punto{
    int x, y;
};

int distancia(Punto a, Punto b){
    return round(sqrt(pow(b.x-a.x,2)+pow(b.y-a.y,2)));
}

void imprimirDistancias(Punto puntos[], int n, int npunto){
    cout<<"Distancias desde el punto ("<<puntos[npunto].x <<", "<< puntos[npunto].y <<"):"<<endl;
    for (int i = 0; i < n; i++){
        if(i != npunto){
            int dist=distancia(puntos[npunto], puntos[i]);
            cout<<"Hasta el punto ("<<puntos[i].x<<", "<<puntos[i].y<<"): "<<dist<<endl;
        }
    }
}

int main(){
    int limX1, limY1, limX2, limY2;
    cout<<"Introduce los limites del cuadrante (x1 y1 x2 y2): ";
    cin>>limX1>>limY1>>limX2>>limY2;

    int n;
    cout<<"Introduce el numero de puntos: ";
    cin>>n;

    Punto puntos[n];
    for (int i=0; i<n; i++){
        cout<<"Introduce el punto "<<i+1<<" (x y): ";
        cin>>puntos[i].x>>puntos[i].y;
    }

    int maxDistancia=0;
    for(int i=0; i<n; i++){
        if(puntos[i].x>=limX1 && puntos[i].x<=limX2 && puntos[i].y>=limY1 && puntos[i].y<=limY2){
            for(int j=i+1; j<n; j++) {
                if(puntos[j].x>=limX1 && puntos[j].x<=limX2 && puntos[j].y>=limY1 && puntos[j].y<=limY2) {
                    int dist=distancia(puntos[i], puntos[j]);
                    if(dist>maxDistancia){
                        maxDistancia=dist;
                    }
                }
            }
        }
    }

    cout<<"La distancia maxima encontrada es: "<<maxDistancia<<endl;

    int npunto;
    for(int i=0; i<n; i++){
        cout<<"Punto "<<i+1<<": ("<<puntos[i].x<<", "<<puntos[i].y<<")= "<<i<<endl;
    }
    
    cout<<"Introduce un punto para calcular las distancias (punto 1 = 0, punto 2 = 1, etc...): ";
    cin>>npunto;
    
    if(npunto>=0 && npunto<n){
        imprimirDistancias(puntos, n, npunto);
    }else{
        cout<<"punto numero "<<npunto<<" fuera de rango."<<endl;
    }

    return 0;
}