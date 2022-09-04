#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct Nodo{
    int edad;
    string nombre;
    Nodo *izq;
    Nodo *der;
};

void menu(vector<Nodo> personas);
Nodo *crearNodo(int edad, string nombre);
void insertarNodo(Nodo *&arbol, int n, string nombre);
void mostrarArbol(Nodo *arbol, int contador);
bool buscarNodo(Nodo *arbol, int n);
void mostrarMenores(Nodo *arbol, int contador);
void mostrarMayores(Nodo *arbol, int contador);

Nodo *arbol = NULL;

int main() {

    vector <Nodo> personas;
    Nodo persona;
    string nombreArchivo = "C://Users//juanf//OneDrive//Desktop//Taller3//data.csv";
    ifstream archivo(nombreArchivo.c_str());
    string linea;
    string nombre, apellido, sexo, estadoCivil,edad;

  	while (getline(archivo, linea))
	{
		stringstream input_stringstream(linea);
		getline(input_stringstream, nombre, ',');
        getline(input_stringstream, apellido, ',');
		getline(input_stringstream, sexo, ',');
		getline(input_stringstream, estadoCivil, ',');
		getline(input_stringstream, edad, ',');
        persona.edad = stoi(edad); 
        persona.nombre = nombre; 
        personas.push_back(persona);  
	}

    menu(personas);

    return 0;
}

Nodo *crearNodo(int n, string nombre){
    Nodo *nuevoNodo = new Nodo();

    nuevoNodo->edad = n;
    nuevoNodo->nombre = nombre;
    nuevoNodo->der = NULL;
    nuevoNodo->izq = NULL;

    return nuevoNodo;
}

void insertarNodo(Nodo *&arbol, int n, string nombre){

    if(arbol == NULL){
        Nodo *nuevoNodo = crearNodo(n, nombre);
        arbol = nuevoNodo;
    }else{
        int valorEdad = arbol->edad;

        if( n < valorEdad){
            insertarNodo(arbol->izq, n, nombre);
        }else{
            insertarNodo(arbol->der, n, nombre);
        }
    }
}

void mostrarArbol(Nodo *arbol, int contador){
    if(arbol == NULL){
        return;
    }else{
        mostrarArbol(arbol->der, contador+1);

        for(int i = 0 ; i < contador; i++){
            cout << "           ";
        }

        cout << arbol->nombre << endl;
        mostrarArbol(arbol->izq, contador+1);
    }
}

bool buscarNodo(Nodo *arbol, int n){

    if(arbol == NULL){
        return false;
    }else if(arbol->edad == n){
        return true;
    }else if(n < arbol->edad){
        return buscarNodo(arbol->izq, n);
    }else{
        return buscarNodo(arbol->der, n);
    }
}

void mostrarMenores(Nodo *arbol, int contador){
    if(arbol == NULL){
        return;
    }else{
        mostrarArbol(arbol->izq, contador+1);

        for(int i = 0 ; i < contador; i++){
            cout << "           ";
        }

        cout << arbol->nombre << endl;
    }
}

void mostrarMayores(Nodo *arbol, int contador){
    if(arbol == NULL){
        return;
    }else{
        mostrarArbol(arbol->der, contador+1);

        for(int i = 0 ; i < contador; i++){
            cout << "           ";
        }

        cout << arbol->nombre << endl;
    }
}


void menu(vector<Nodo> personas){

    int dato, opcion, cont = 0;
    string nombre;

    do{
        cout << " MENU " << endl;
        cout << " 1. Llenar arbol" << endl;
        cout << " 2. Mostrar el arbol completo" << endl;
        cout << " 3. Buscar edad en el arbol" << endl;
        cout << " 4. Mostrar familia menor que la tia" << endl;
        cout << " 5. Mostrar familia mayor que la tia" << endl;
        cout << " 6. Salir" << endl;
        cout << "-> ";
        cin >> opcion;

        switch (opcion) {
            case 1:

                for(int i = 0 ; i < personas.size();i++){
                    insertarNodo(arbol, personas[i].edad,personas[i].nombre);
                }

                cout << "Nodos llenados con exito" << endl;
                system("pause");
                break;

            case 2: cout << "\nArbol completo :\n\n" << endl;
                    mostrarArbol(arbol, cont);
                    cout << "\n";
                    system("pause");
                    break;

            case 3: cout << "\nDigite la edad :";
                    cin >> dato;
                    if(buscarNodo(arbol,dato)){
                        cout << "La edad existe" << endl;
                    }else{
                        cout << "La edad NO existe" << endl;
                    }
                    cout << "\n";
                    break;

            case 4:
                mostrarMenores(arbol,cont);
                break;
            case 5:
                mostrarMayores(arbol, cont);
                break;
        }

        system("cls");
    }while(opcion != 6);
}