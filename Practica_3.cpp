#include <iostream>
#include <string>

using namespace std;

struct Plano{
    float x;
    float y;
};

string Cuadrante(float x, float y){
    if(x>0 && y>0){
        return "Primer cuadrante";
    }else if(x<0 && y>0){
        return "Segundo cuadrante";
    }else if(x<0 && y<0){
        return "Tercer cuadrante";
    }else if(x>0 && y<0){
        return "Cuarto cuadrante";
    }else if(x==0 && y!=0){
        return "Sobre el eje Y";
    }else if(x!=0 && y==0){
        return "Sobre el eje X";
    }else{
        return "En el origen";
    }
}

void Linea(Plano puntos[], int n){
    if(n<2){
        cout<<"Se necesitan al menos dos puntos para determinar una linea."<<endl;
        return;
    }

    float x1=puntos[0].x;
    float y1=puntos[0].y;
    float x2=puntos[1].x;
    float y2=puntos[1].y;

    float A=y2-y1;
    float B=x1-x2;
    float C=x2*y1-x1*y2;

    cout<<"La ecuacion de la linea es: "<<A<<"x + "<<B<<"y + "<<C<<" = 0"<<endl;

    for (int i=2; i<n; ++i){
        float x=puntos[i].x;
        float y=puntos[i].y;
        if(A*x+B*y+C!=0){
            cout<<"El punto ("<<x<<", "<<y<<") no pertenece a la misma línea."<<endl;
        }else{
            cout<<"El punto ("<<x<<", "<<y<<") pertenece a la misma linea."<<endl;
        }
    }
}

int main(){
    int n;
    cout<<"Ingrese el numero de puntos: ";
    cin>>n;
    Plano p[n];
    for(int i=0; i<n; i++){
        cout<<"Ingrese el punto "<<i+1<<" en x: ";
        cin>>p[i].x;
        cout<<"Ingrese el punto "<<i+1<<" en y: ";
        cin>>p[i].y;
        cout<<"El punto ("<<p[i].x<<", "<<p[i].y<<") se encuentra en el "<<Cuadrante(p[i].x, p[i].y)<<"."<<endl;
    }

    Linea(p, n);

    return 0;
}
