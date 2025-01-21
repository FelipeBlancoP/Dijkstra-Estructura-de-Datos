#include <iostream>
using namespace std;
#include <fstream>
#include <vector>
bool cargarArchivoMatriz(vector<vector<int>>& matriz,int& tamanoMatriz, string nombreArchivo){
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
        for(int i = 0;i<tamanoMatriz;i++){
            if(getline(archivo,linea)){
                int numero = 0;
                int columna = 0;
                for(int j = 0;j<=linea.size();j++)
                if(j <linea.size)
            }
        }
        
        return true;
    }
    cout<<"Tamaño de la matriz incorrecto. Modifique el txt"<<endl;
    return false;

}


int main(){
    vector<vector<int>> matriz;
    int tamanoMatriz = 0;
    if(cargarArchivoMatriz(matriz,tamanoMatriz,"Matriz.txt")){
        mostrarMatriz(Matriz,tamanoMatriz);
    }else{
        cout<<"Error al cargar la Matriz"<<endl;
    }
    cout<<"Hola Mundo"<<endl;
    return 0;
}