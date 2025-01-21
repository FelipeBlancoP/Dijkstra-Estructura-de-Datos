#include <iostream>
using namespace std;
#include <fstream>
#include <vector>

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
        while(fila < tamanoMatriz && getline(archivo,linea)){
            int columna = 0;
            string numero = "";
            for(int i = 0;i <= linea.size();i++)
                if(i<linea.size() && linea[i] != ','){
                    numero += linea[i];
                }else{
                    matriz[fila][columna] = stoi(numero);
                    numero = "";
                    columna++;
                }
            }
            fila++;
        }
        archivo.close();
        return true;
    }
    cout<<"Tamaño de la matriz incorrecto. Modifique el txt"<<endl;
    return false;
}
//------------------------------------------------------------------------------------------------

//mostrar matriz----------------------------------------------------------------------------------
void mostrarMatriz(vector<vector<int>>& matriz,int& tamanoMatriz){

}
//------------------------------------------------------------------------------------------------


int main(){
    int tamanoMatriz = 0;
    vector<vector<int>> matriz;

    if(cargarArchivoMatriz(matriz,"Matriz.txt")){
        mostrarMatriz(Matriz,tamanoMatriz);
    }else{
        cout<<"Error al cargar la Matriz"<<endl;
    }
    cout<<"Hola Mundo"<<endl;
    return 0;
}