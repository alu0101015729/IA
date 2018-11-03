#include"busqueda.hpp"

busqueda::busqueda(){}


void busqueda::adicionarNodoAListaAbierta(nodo nodo){
 int indice = 0;
 float costo = nodo.costeTotal;
 while ((listaAbierta->size() > indice) && (costo < listaAbierta[indice].CosteTotal)){
  indice++;
 }
 listaAbierta->push_back(nodo);
}

std::vector<nodo> busqueda::encontrarCamino(int x,int y){
    std::pair<int,int> posTileInicial;
    posTileInicial.first=0;
    posTileInicial.second=0;
    std::pair<int,int> posTileFinal;
    posTileFinal.first=x;
    posTileFinal.second=y;

    listaAbierta->clear();
    listaCerrada->clear();

    nodo *nodoFinal = new nodo(NULL, NULL, posTileFinal.first,posTileFinal.second, 0);
    nodo *nodoInicial = new nodo(NULL, nodoFinal, posTileInicial.first,posTileInicial.second, 0);

    // se adiciona el nodo inicial
    adicionarNodoAListaAbierta(*nodoInicial);
    while (listaAbierta->size() > 0){
     //   nodo nodoActual = listaAbierta[listaAbierta->size() - 1]; error no se cual es
        // si es el nodo Final
        if (nodoActual.esIgual(*nodoFinal)){
            List<Vector2> mejorCamino = new List<Vector2>();
            while (nodoActual != null){
                mejorCamino.Insert(0, nodoActual.Posicion);
                nodoActual = nodoActual.NodoPadre;
            }
            //return mejorCamino;
        }
        listaAbierta.Remove(nodoActual);
    }
}


private List<Nodo> encontrarNodosAdyacentes(Nodo nodoActual, Nodo nodoFinal)
{
List<Nodo> nodosAdyacentes = new List<Nodo>();
Int32 X = nodoActual.GrillaX;
Int32 Y = nodoActual.GrillaY;
Boolean arribaIzquierda = true;
Boolean arribaDerecha = true;
Boolean abajoIzquierda = true;
Boolean abajoDerecha = true;

//Izquierda
if ((X > 0) && (!motor.Mapa.tileMapLayers[0].obtenerTile(X - 1, Y).Colision))
{
 nodosAdyacentes.Add(new Nodo(nodoActual, nodoFinal, new Vector2(X - 1, Y), costoIrDerecho + nodoActual.costoG));
}
else
{
 arribaIzquierda = false;
 abajoIzquierda = false;
}

//Derecha
if ((X < motor.Mapa.NumXTiles - 1) && (!motor.Mapa.tileMapLayers[0].obtenerTile(X + 1, Y).Colision))
{
 nodosAdyacentes.Add(new Nodo(nodoActual, nodoFinal,
 new Vector2(X + 1, Y), costoIrDerecho + nodoActual.costoG));
}
else
{
 arribaDerecha = false;
 abajoDerecha = false;
}

//Arriba
if ((Y > 0) && (!motor.Mapa.tileMapLayers[0].obtenerTile(X, Y - 1).Colision))
{
 nodosAdyacentes.Add(new Nodo(nodoActual, nodoFinal,
 new Vector2(X, Y - 1), costoIrDerecho + nodoActual.costoG));
}
else
{
 arribaIzquierda = false;
 arribaDerecha = false;
}

// Abajo
if ((Y < motor.Mapa.NumYTiles - 1) && (!motor.Mapa.tileMapLayers[0].obtenerTile(X, Y + 1).Colision))
{
 nodosAdyacentes.Add(new Nodo(nodoActual, nodoFinal,
 new Vector2(X, Y + 1), costoIrDerecho + nodoActual.costoG));
}
else
{
 abajoIzquierda = false;
 abajoDerecha = false;
}

 return nodosAdyacentes;
 }
}
