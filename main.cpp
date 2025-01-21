#include <iostream>
using namespace std;
#include <fstream>
#include <vector>

//Clase Nodo----------------------------------------
class Nodo{
    public:
        char letra;
        int distancia;
    Nodo(char _letra){
        letra = _letra;
    }
};
//--------------------------------------------------

//cargar matriz del archivo txt y colocar los numeros en la matriz------------------------------------------
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
    
}
//------------------------------------------------------------------------------------------------

//mostrar matriz----------------------------------------------------------------------------------
void imprimirMatriz(vector<vector<int>>& matriz,int& tamanoMatriz){
    for(int i = 0;i<tamanoMatriz;i++){
        for(int j = 0;j<tamanoMatriz;j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
}
//------------------------------------------------------------------------------------------------

//letras------------------------------------------------------------------------------
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
}
//------------------------------------------------------------------------------------


int main(){
    int tamanoMatriz = 0;
    vector<vector<int>> matriz;

    if(cargarArchivoMatriz(matriz,tamanoMatriz,"Matriz.txt")){
        //imprimirMatriz(matriz,tamanoMatriz);
        vector<Nodo*> nodosUsar = letrasNodos(tamanoMatriz);
    }else{
        cout<<"Error al cargar la Matriz"<<endl;
    }
    return 0;
}