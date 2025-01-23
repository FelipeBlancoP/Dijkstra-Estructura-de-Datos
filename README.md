# Dijkstra-Estructura-de-Datos
Felipe Blanco               RUT: 21.301.314-9                  Estructura de Datos/Curso de Verano

Para ejecutar consola, colocar: g++ main.cpp -o main
Seguido de: ./main

Documentacion:

cargarArchivoMatriz()
+ Metodo para cargar la matriz leyendo un archivo txt y en caso de que el tamano no sea entre 1 a 26(26 solamente porque no se usa la letra ñ) retornara false y en caso de que no se pueda abrir el archivo retornara false tambien.

letrasNodos()
+ Metodo para asignarle una letra del abecedario a cada nodo respecto al tamano de la matriz y devuelve un vector de punteros a los nodos creados.

nodoEsta()
+ Metodo que busca si la letra buscada existe en el vector de nodos, si lo encuentra retorna el puntero al nodo correspondiente, sino, retorna nullptr.

nodoMneorDistancia()
+ Metodo que recibe por parametros la lista booleana visitados, lista de enteros que guarda la distancia mas corta desde el nodo inicial hasta cada nodo y el tamaño de la matriz, para recorrer todos los nodos que no hayan sido visitados y devuelve el indice del nodo que tenga menor distancia acumulada.

dijkstra()
+ metodo que recibe por parametros la matriz creada, el tamano de la matriz y el vector de los nodos que se usaran. Comienza desde el Nodo inicial A hasta el nodo buscado. Comienza inicializando las distancias a los nodos, los marca como no visitados y luego explora los nodos adyacentes actualizando las distancias mas cortas mientras encuentra caminos mas cortos, esto se repite hasta que todos los nodos hayan sido visitados. En este metodo se crea y utiliza un arbol de nodos(que se usara en imprimirCaminoMasCorto para imprimir el camino mas corto) donde cada nodo guarda un puntero al nodo desde el cual se llego a el y finalmente el metodo retorna el puntero al nodo destino.

imprimirCaminoMasCorto()
+ Metodo que utiliza el arbol de nodos creado en el metodo dijkstra recorriendolo hacia atras, guardando cada nodo en el vector camino para luego imprimirlos en orden desde el Nodo inicial hasta el nodo buscado.

