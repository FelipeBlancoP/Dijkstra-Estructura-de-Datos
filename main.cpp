#include <iostream>
using namespace std;
#include <fstream>
#include <vector>

//cargar matriz del archivo txt y colocar los numeros en la matriz-----------------------------
bool cargarArchivoMatriz(vector<vector<int>>& matriz,int& tamanoMatriz,string nombreArchivo){
    ifstream archivoLeer(nombreArchivo);
    if(!archivoLeer.is_open()){
        cout<<"No se abrio el archivo"<<endl;
        return false;
    }
    archivoLeer>>tamanoMatriz;
    archivoLeer.ignore();
    if(tamanoMatriz > 0 && tamanoMatriz <= 27){
        matriz = vector<vector<int>>(tamanoMatriz,vector<int>(tamanoMatriz));
        string linea;
        int fila = 0;
        while(fila < tamanoMatriz && getline(archivoLeer,linea)){
            int columna = 0;
            string numero = "";
            for(int i = 0;i < linea.size();i++){
                if(i<linea.size() && linea[i] != ','){
                    numero += linea[i];
                }else{
                    matriz[fila][columna] = stoi(numero);
                    numero = "";
                    columna++;
                }
            
            }
            if(!numero.empty()){
                matriz[fila][columna] = stoi(numero);
            }
            fila++;
        }
        archivoLeer.close();
        return true;
    }else{
        cout<<"Tamaño de la matriz incorrecto. Modifique el txt"<<endl;
        return false;
    }
    
}//--------------------------------------------------------------------------------------------


//mostrar matriz para ver si funciona--------------------------------
void imprimirMatriz(vector<vector<int>>& matriz,int& tamanoMatriz){
    for(int i = 0;i<tamanoMatriz;i++){
        for(int j = 0;j<tamanoMatriz;j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
}//------------------------------------------------------------------


//Clase Nodo--
class Nodo{
    public:
        char letra;
        int distancia;
    Nodo(char _letra){
        letra = _letra;
    }
};//----------


//letras correspondientes a cant nodos--------
vector<Nodo*> letrasNodos(int tamanoMatriz){
    vector<char> letras = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    vector<Nodo*> nodosUsar(tamanoMatriz);
    cout<<"Nodos: ";
    for(int i = 0;i<tamanoMatriz;i++){
        nodosUsar[i] = new Nodo(letras[i]);
    }
    for(int j = 0;j<tamanoMatriz;j++){
        cout<<nodosUsar[j]->letra<<" ";
    }
    cout<<endl;
    return nodosUsar;
}//-------------------------------------------


//control de error letra de nodo a buscar---------------
Nodo* nodoEsta(vector<Nodo*> nodosUsar,char letraNodo){
    for(int i = 0;i<nodosUsar.size();i++){
        if(nodosUsar[i]->letra == letraNodo){
            return nodosUsar[i];
        }
    }
    return nullptr;
}//-----------------------------------------------------


//encontrar camino mas corto al nodo buscado---------------------------------------
int nodoMenorDistancia(vector<bool>& visitados,vector<int>& distanciaMasCorta,int tamanoMatriz){
    int menor = 9999;
    int nodoMDistancia = -1;

    for(int i = 0;i<tamanoMatriz;i++){
        if(!visitados[i] && distanciaMasCorta[i] < menor){
            menor = distanciaMasCorta[i];
            nodoMDistancia = i;
        }
    }
    return nodoMDistancia;
}//---------------------------------------------------------------------------------


//preguntar por el nodo a buscar...------------------------------------------------------
void nodoABuscar(vector<vector<int>>& matriz,int tamanoMatriz,vector<Nodo*>& nodosUsar){
    char letraNodo;
    cout<<"Escriba la letra del Nodo al que quiera llegar: ";
    cin>>letraNodo;
    Nodo* nodoAEncontrar = nodoEsta(nodosUsar,letraNodo);
    while(!nodoAEncontrar){
        cin.ignore();
        cout<<"Error. Ingrese correctamente la letra."<<endl;
        cout<<"Escriba la letra del Nodo al que quiera llegar: ";
        cin>>letraNodo;
        nodoAEncontrar = nodoEsta(nodosUsar,letraNodo);
    }
    vector<bool> visitados(tamanoMatriz);
    for(int i = 0;i <tamanoMatriz;i++){
        visitados[i] = false;
    }
    vector<int> distanciaMasCorta(tamanoMatriz);
    for(int i = 0;i <tamanoMatriz;i++){
        distanciaMasCorta[i] = 9999;
    }
    vector<int> ruta(tamanoMatriz);
    for(int i = 0;i <tamanoMatriz;i++){
        ruta[i] = -9999;
    }
    distanciaMasCorta[0] = 0;

    Nodoarbol* arbol = new NodoArbol(nodosUsar[0]->letra);
    

    for(int i = 0;i<tamanoMatriz-1; i++){
        int nodoMDistancia = nodoMenorDistancia(visitados,distanciaMasCorta,tamanoMatriz);
        if(nodoMDistancia == -1){
            break;
        }else{
            visitados[nodoMDistancia] = true;
            for(int nodoAdyacente = 0;nodoAdyacente <tamanoMatriz;nodoAdyacente++){
                if(matriz[nodoMDistancia][nodoAdyacente] != 0 && !visitados[nodoAdyacente]){
                    int nuevaDistancia = distanciaMasCorta[nodoMDistancia]+matriz[nodoMDistancia][nodoAdyacente];
                    if(nuevaDistancia < distanciaMasCorta[nodoAdyacente]){
                        distanciaMasCorta[nodoAdyacente] = nuevaDistancia;
                        ruta[nodoAdyacente] = nodoMDistancia;
                    }
                }
            }
        }
    }
    int nodoDestino = nodoAEncontrar->letra - 'A';
    cout<<"Distancia mas corta al Nodo: "<<nodoAEncontrar->letra<<" es "<<distanciaMasCorta[nodoDestino]<<endl;

    
}//--------------------------------------------------------------------------------------


//MAIN=======
int main(){
    int tamanoMatriz = 0;
    vector<vector<int>> matriz;

    if(cargarArchivoMatriz(matriz,tamanoMatriz,"Matriz.txt")){
        //imprimirMatriz(matriz,tamanoMatriz);
        vector<Nodo*> nodosUsar = letrasNodos(tamanoMatriz);
        nodoABuscar(matriz,tamanoMatriz,nodosUsar);
    }else{
        cout<<"Error al cargar la Matriz"<<endl;
    }
    return 0;
}//==========