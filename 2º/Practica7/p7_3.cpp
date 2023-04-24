
#include <iostream>

using namespace std;

int main()
{
    int Pmax, nObj, nObje;
    int *Vpesos;
    float *Vvalores;
    float **Matr; 
    float ValMax; 

    

    cout<<"Peso maximo de la mochila:"<<endl;
    cin>>Pmax;
    cout<<"Total de objetos:"<<endl;
    cin>>nObj;

    Vpesos = new int [nObj+1];
    Vvalores = new float [nObj+1];
    Matr = new float* [nObj+1]; 
    if(Matr == NULL){
        cout<<"Error al reservar memoria";
        return 0;
    }
    for(int i=0; i<=nObj; i++){
        Matr[i] = new float [Pmax+1];
        if(Matr[i] == NULL){
            cout<<"Error al reservar memoria";
            return 0;
        }
    }


    if(Vpesos == NULL || Vvalores == NULL){
        cout<<"Error al reservar memoria";
        return 0;
    }

    for(int i=1; i<=nObj; i++){   //DARLE VALORES AL VECTOR DE PESOS
        cout<<"Peso del objeto "<<i<<":"<<endl;
        cin>>Vpesos[i];
    }

    for(int i=1; i<=nObj; i++){ //DARLE VALORES AL VECTOR DE VALORES
        cout<<"Valor del objeto "<<i<<":"<<endl;
        cin>>Vvalores[i];
    }


    //PROGRAMACION DINAMICA

   for(int i=0; i<=Pmax; i++){  
        Matr[0][i] = 0;
    }
    for(int i=0; i<=nObj; i++){ 
        Matr[i][0] = 0;
    }

    for(int i=1; i<=nObj; i++){  
        for(int j=1; j<=Pmax; j++){
            if(Vpesos[i] > j){
                Matr[i][j] = Matr[i-1][j];
            }
            else{
               if(Matr[i-1][j] >= (Vvalores[i]+Matr[i-1][j-Vpesos[i]])){
                    Matr[i][j] = Matr[i-1][j];
               }
               else{
                    Matr[i][j] = Vvalores[i]+Matr[i-1][j-Vpesos[i]];
               }
            }

                 
        }
    }

    ValMax = Matr[nObj][Pmax];

    cout<<endl<<"Valor maximo que puede llevar: "<<ValMax;


    cout<<endl;
 
    
    cout<<"Objetos en la mochila:";  
    nObje = nObj;
    
    while(nObj != 0){
        
        if(Matr[nObj][Pmax] != Matr[nObj-1][Pmax]){
            
            Pmax = Pmax - Vpesos[nObj];
            Vpesos[nObj] = nObj;
            
        }
        else{
            Vpesos[nObj] = 0;
        }
    nObj = nObj - 1;
    }

    for(int i=1; i<=nObje; i++){ 
       if(Vpesos[i] != 0){
            cout<<" "<<Vpesos[i];
       }
    }

    
    return 0;
}
