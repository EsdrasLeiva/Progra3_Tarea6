#include <iostream>
#include <list>
#include <fstream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include "Pais.h"
#include "Evaluador.h"
#include "NodoNario.h"

using namespace std;

//Escribe "pais" en un achivo con nombre "nombre_archivo" en la posicion "posicion"
//Nota: Se deben poder agregar varios registros en un solo archivo

int TAMANO_DE_REGISTRO = 25;

void escribir(string nombre_archivo, Pais*pais, int posicion)
{
    ofstream out(nombre_archivo.c_str(), ios::in | ios::out);
    if(!out.is_open())
        out.open(nombre_archivo.c_str());

    out.seekp(posicion*TAMANO_DE_REGISTRO);
    out.write(pais->nombre.c_str(),20);
    out.write((char*)&pais->habitantes,4);
    out.write((char*)&pais->hablan_espanol,1);

    out.close();
}

//Devuelve un pais previamente escrito (con la funcion escribir()) en el archivo con nombre "nombre_archivo" en la posicion "posicion"
//Nota: Se deben poder leer varios registros de un archivo
Pais* leer(string nombre_archivo, int posicion)
{
    ifstream in(nombre_archivo.c_str());
    in.seekg(posicion*TAMANO_DE_REGISTRO);

    char nombre[20];
    int habitantes;
    bool hablan_espanol;

    in.read(nombre,20);
    in.read((char*)&habitantes,4);
    in.read((char*)&hablan_espanol,1);

    return new Pais(nombre,habitantes,hablan_espanol);
}

//Devuelve suma de habitantes de paises que hablan espanol en el archivo con nombre "nombre_archivo"
//Nota: Los registros se deben de haber guardado previamente con la funcion escribir()
int contarHispanohablantes(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str(), ios::ate);
    int cantidad_habitantes_espanol = in.tellg()/TAMANO_DE_REGISTRO;
    in.close();

    double suma = 0;
    for(int i=0; i<cantidad_habitantes_espanol; i++)
    {
        suma+=leer(nombre_archivo, i)->habitantes;
    }
    return suma/cantidad_habitantes_espanol;
}

//Devuelve un set que contenga los numeros fibonacci.
//La cantidad de numeros que contiene se determina por el parametro "cantidad"
set<int> getNumerosFibonacci(int cantidad)
{
    set<int>respuesta;
    return respuesta;
}

//Devuelve la cantidad de letras mayusculas presentes en "a" y "b"
int contarMayusculas(stack<char> a,queue<char> b)
{
    return -1;
}

//Devuelve la cantidad de llaves repetidas en "mi_multimapa"
//Nota: No devuelve la cantidad de repeticines
int contarLLavesRepetidas(multimap<string,string>mi_multimapa)
{
    return -1;
}

//Devuelve true si y solo si "buscado" existe en el arbol nario "raiz"
bool existe(NodoNario* raiz,int buscado)
{
    return false;
}

//Busca el valor "buscado" en el arbol "raiz" y lo reemplaza con "reemplazo"
void buscarYReemplazar(NodoNario* raiz, int buscado, int reemplazo)
{

}

//Devuelve un vector que contenga la siguiente secuencia binaria:
//00000001
//00000010
//00000100
//00001000
//00010000
//00100000
//01000000
//10000000
vector<char> obtenerSecuencia()
{
    vector<char>respuesta;
    return respuesta;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

