#pragma once
#include <fstream> //Para guardar los datos


class Doctor {

public:

	static int cantidad_de_doctores;

	Doctor* Padre;
	Doctor* izq;
	Doctor* der;

	char Cedula[15];
	char Nombre[40];
	char Apellidos[40];
	char Especialidad[30];
	char Consultorio[10];

	char Lunes[25];
	char Martes[25];
	char Miercoles[25];
	char Jueves[25];
	char Viernes[25];

	char Dias_atencion[50];
	char Celular[15];

	char DirFileDoc[MAX_PATH] = " ";

	Doctor() {};

	Doctor(char Cedula[], char Nombre[], char Apellidos[], char Especialidad[], char Consultorio[], char Lunes[], char Martes[], char Miercoles[], char Jueves[]
		, char Viernes[], char Dias_atencion[], char Celular[],char Direccion_foto[]) {

		izq = NULL; der = NULL, Padre = NULL;

		strcpy(this->Cedula, Cedula);
		strcpy(this->Nombre, Nombre);
		strcpy(this->Apellidos, Apellidos);
		strcpy(this->Especialidad, Especialidad);
		strcpy(this->Consultorio, Consultorio);
		strcpy(this->Lunes, Lunes);
		strcpy(this->Martes, Martes);
		strcpy(this->Miercoles, Miercoles);
		strcpy(this->Jueves, Jueves);
		strcpy(this->Viernes, Viernes);
		strcpy(this->Dias_atencion, Dias_atencion);
		strcpy(this->Celular, Celular);
		strcpy(this->DirFileDoc, Direccion_foto);

	}

	friend class Doctor_arbol;

};

int Doctor::cantidad_de_doctores = 0;

class Doctor_arbol {

public:

	Doctor* raiz;

	Doctor_arbol() {

		raiz = NULL;

		Doctor* temp = NULL;
		int size;
		fstream MiArchivo_DCOTORES;
		MiArchivo_DCOTORES.open("Informacion_DOCTORES.bin", ios::binary | ios::ate | ios::in);

		if (MiArchivo_DCOTORES.is_open())
		{
			size = MiArchivo_DCOTORES.tellg();
			MiArchivo_DCOTORES.seekg(0);

			for (int i = 0; i < size / sizeof(Doctor); i++)
			{

				Doctor* tempNode = new Doctor;
				MiArchivo_DCOTORES.read(reinterpret_cast<char*>(tempNode), sizeof(Doctor));

				tempNode->der = NULL;
				tempNode->izq = NULL;

				Insertar_Nodo_del_ARCHIVO(tempNode);
				//addNodeFromFile(node, tempNode);
				tempNode = NULL;
				delete reinterpret_cast<char*>(tempNode);
				hay_informacion_de_doctores = true;

			}

		}

		MiArchivo_DCOTORES.close();

	}

	void Insertar_Nodo_del_ARCHIVO(Doctor* tempNode)
	{
		Doctor* newNode = new Doctor;
		newNode = CrearNodo(tempNode, newNode);
		if (raiz == NULL)
		{
			raiz = newNode;
			raiz->der = NULL;
			raiz->izq = NULL;
			raiz->Padre = NULL;


			return;
		}

		AgregarDoctor_RECURSIVIDAD(&raiz, tempNode, NULL);
		return;
	}

	void AgregarDoctor(Doctor* temporal) {

		Doctor* Nuevo_doctor = new Doctor;
		Nuevo_doctor = CrearNodo(temporal, Nuevo_doctor);
		Nuevo_doctor->der = NULL;
		Nuevo_doctor->izq = NULL;

		if (raiz == NULL) {

			Doctor::cantidad_de_doctores++;
			raiz = Nuevo_doctor; //La raiz va a apuntar al nuevo doctor

		}
		else {

			AgregarDoctor_RECURSIVIDAD(&raiz, Nuevo_doctor, NULL);

		}

	}

	void AgregarDoctor_RECURSIVIDAD(Doctor** nodo, Doctor* nuevo_doctor, Doctor* Padre) {

		Doctor* nodo_temporal = *nodo;

		if (nodo_temporal == NULL) {

			Doctor::cantidad_de_doctores++;
			*nodo = nuevo_doctor; //Agregamos el doctor en donde el puntero no este apuntando a nada
			nodo_temporal = *nodo;
			nodo_temporal->Padre = Padre;

			return;

		}
		else {

			if (atoi(nuevo_doctor->Cedula) > atoi(nodo_temporal->Cedula)) { //atoi para pasar char a int

				AgregarDoctor_RECURSIVIDAD(&(nodo_temporal->der), nuevo_doctor, nodo_temporal);

			}
			if (atoi(nuevo_doctor->Cedula) < atoi(nodo_temporal->Cedula)) { //atoi para pasar char a int

				AgregarDoctor_RECURSIVIDAD(&(nodo_temporal->izq), nuevo_doctor, nodo_temporal);

			}


		}

		return;

	}

	Doctor* Arreglo_del_arbol() {

		Doctor* arr = new Doctor[Doctor::cantidad_de_doctores + 1]; //Creamso el arreglo, con la cantidad de doctores (El +1 es el que estamps intentando agregar)
		int indice = 0;
		Arbol_a_arreglo(raiz, arr, &indice);

		return arr;

	}

	void Arbol_a_arreglo(Doctor* nodo, Doctor* arr, int* indice) {

		if (nodo == NULL) {
			return;
		}

		TranferirNodo(arr + (*indice), nodo);
		(*indice)++;
		Arbol_a_arreglo(nodo->izq, arr, indice);
		Arbol_a_arreglo(nodo->der, arr, indice);

		return;

	}

	void TranferirNodo(Doctor* destino, Doctor* nodo) {

		strcpy(destino->Nombre, nodo->Nombre);
		strcpy(destino->Apellidos, nodo->Apellidos);
		strcpy(destino->Cedula, nodo->Cedula);
		strcpy(destino->Celular, nodo->Celular);
		strcpy(destino->Consultorio, nodo->Consultorio);
		strcpy(destino->Especialidad, nodo->Especialidad);
		strcpy(destino->Dias_atencion, nodo->Dias_atencion);
		strcpy(destino->Lunes, nodo->Lunes);
		strcpy(destino->Martes, nodo->Martes);
		strcpy(destino->Miercoles, nodo->Miercoles);
		strcpy(destino->Jueves, nodo->Jueves);
		strcpy(destino->Viernes, nodo->Viernes);
		strcpy(destino->DirFileDoc, nodo->DirFileDoc);

		//destino->Padre = nodo->Padre;

	}

	Doctor* CrearNodo(Doctor* Temporal, Doctor* Nuevo_Doctor) {

		strcpy(Nuevo_Doctor->Nombre, Temporal->Nombre);
		strcpy(Nuevo_Doctor->Apellidos, Temporal->Apellidos);
		strcpy(Nuevo_Doctor->Cedula, Temporal->Cedula);
		strcpy(Nuevo_Doctor->Celular, Temporal->Celular);
		strcpy(Nuevo_Doctor->Consultorio, Temporal->Consultorio);
		strcpy(Nuevo_Doctor->Dias_atencion, Temporal->Dias_atencion);
		strcpy(Nuevo_Doctor->Especialidad, Temporal->Especialidad);
		strcpy(Nuevo_Doctor->Lunes, Temporal->Lunes);
		strcpy(Nuevo_Doctor->Martes, Temporal->Martes);
		strcpy(Nuevo_Doctor->Miercoles, Temporal->Miercoles);
		strcpy(Nuevo_Doctor->Jueves, Temporal->Jueves);
		strcpy(Nuevo_Doctor->Viernes, Temporal->Viernes);
		strcpy(Nuevo_Doctor->DirFileDoc, Temporal->DirFileDoc);

		Nuevo_Doctor->Padre = Temporal->Padre;
		Nuevo_Doctor->der = Temporal->der;
		Nuevo_Doctor->izq = Temporal->izq;

		return Nuevo_Doctor;

	}

	void ModificarNodo(Doctor* temporal, char Cedula[]) {

		Doctor* Doctor_a_modificar = raiz;
		Doctor_a_modificar = BuscarNodo(&Doctor_a_modificar, atoi(Cedula));

		strcpy(Doctor_a_modificar->Apellidos, temporal->Apellidos);
		strcpy(Doctor_a_modificar->Cedula, temporal->Cedula);
		strcpy(Doctor_a_modificar->Celular, temporal->Celular);
		strcpy(Doctor_a_modificar->Consultorio, temporal->Consultorio);
		strcpy(Doctor_a_modificar->Dias_atencion, temporal->Dias_atencion);

		if (strcmp(temporal->DirFileDoc, "") != 0) {
			strcpy(Doctor_a_modificar->DirFileDoc, temporal->DirFileDoc);
		}

		strcpy(Doctor_a_modificar->Especialidad, temporal->Especialidad);

		strcpy(Doctor_a_modificar->Lunes, temporal->Lunes);
		strcpy(Doctor_a_modificar->Martes, temporal->Martes);
		strcpy(Doctor_a_modificar->Miercoles, temporal->Miercoles);
		strcpy(Doctor_a_modificar->Jueves, temporal->Jueves);
		strcpy(Doctor_a_modificar->Viernes, temporal->Viernes);

		strcpy(Doctor_a_modificar->Nombre, temporal->Nombre);

		/*	Doctor_a_modificar->der=temporal->der;
			Doctor_a_modificar->izq = temporal->izq;
			Doctor_a_modificar->Padre = temporal->Padre;*/



	}

	void ELIMINAR(Doctor* arbol, int Cedula) {

		if (arbol == NULL) {
			return; //No hago nada
		}
		else if (Cedula < atoi(arbol->Cedula)) { //El elemento esta por la izquierda del arbol

			ELIMINAR(arbol->izq, Cedula);

		}
		else if (Cedula > atoi(arbol->Cedula)) { //El elemento esta por la izquierda del arbol

			ELIMINAR(arbol->der, Cedula);

		}
		else {
			eliminarNODO(arbol);
		}


	}

	void eliminarNODO(Doctor* nodoELIMINAR) {

		if (nodoELIMINAR->izq && nodoELIMINAR->der)
		{
			Doctor* temporal_Nodo = minimo(nodoELIMINAR->der);
			/*tempNode->left->_father = node->right;
			tempNode->right->left = node->left;*/

			TranferirNodo(nodoELIMINAR, temporal_Nodo);
			eliminarNODO(temporal_Nodo);
		}

		else if (nodoELIMINAR->izq)
		{
			if (nodoELIMINAR->Padre)
			{
				if (nodoELIMINAR->Padre->izq == nodoELIMINAR)
				{
					nodoELIMINAR->Padre->izq = nodoELIMINAR->izq;
					nodoELIMINAR->izq->Padre = nodoELIMINAR->Padre;
					nodoELIMINAR->Padre = NULL;
					nodoELIMINAR->izq = NULL;
					nodoELIMINAR->der = NULL;
					Doctor::cantidad_de_doctores = Doctor::cantidad_de_doctores - 1;
					delete nodoELIMINAR;
					return;
				}

				else if (nodoELIMINAR->Padre->der == nodoELIMINAR)
				{
					nodoELIMINAR->Padre->der = nodoELIMINAR->izq;
					nodoELIMINAR->izq->Padre = nodoELIMINAR->Padre;
					nodoELIMINAR->Padre = NULL;
					nodoELIMINAR->izq = NULL;
					nodoELIMINAR->der = NULL;
					Doctor::cantidad_de_doctores = Doctor::cantidad_de_doctores - 1;
					delete nodoELIMINAR;
					return;
				}
			}

			this->raiz = nodoELIMINAR->izq;
			nodoELIMINAR->izq->Padre = NULL;
			nodoELIMINAR->izq = NULL;
			Doctor::cantidad_de_doctores = Doctor::cantidad_de_doctores - 1;
			delete nodoELIMINAR;

		}

		else if (nodoELIMINAR->der)
		{
			if (nodoELIMINAR->Padre)
			{
				if (nodoELIMINAR->Padre->izq == nodoELIMINAR)
				{
					nodoELIMINAR->Padre->izq = nodoELIMINAR->der;
					nodoELIMINAR->der->Padre = nodoELIMINAR->Padre;
					nodoELIMINAR->Padre = NULL;
					nodoELIMINAR->izq = NULL;
					nodoELIMINAR->der = NULL;
					Doctor::cantidad_de_doctores = Doctor::cantidad_de_doctores - 1;
					delete nodoELIMINAR;
					return;
				}
				else if (nodoELIMINAR->Padre->der == nodoELIMINAR)
				{
					nodoELIMINAR->Padre->der = nodoELIMINAR->izq;
					nodoELIMINAR->izq->Padre = nodoELIMINAR->Padre;
					nodoELIMINAR->Padre = NULL;
					nodoELIMINAR->izq = NULL;
					nodoELIMINAR->der = NULL;
					Doctor::cantidad_de_doctores = Doctor::cantidad_de_doctores - 1;
					delete nodoELIMINAR;
					return;
				}
			}

			this->raiz = nodoELIMINAR->der;
			nodoELIMINAR->der->Padre = NULL;
			Doctor::cantidad_de_doctores = Doctor::cantidad_de_doctores - 1;
			delete nodoELIMINAR;
		}

		else {
			if (nodoELIMINAR->Padre) {
				Doctor* temporal_Nodo = nodoELIMINAR->Padre;
				if (temporal_Nodo->der == nodoELIMINAR)
				{
					Doctor::cantidad_de_doctores = Doctor::cantidad_de_doctores - 1;
					delete nodoELIMINAR;
					temporal_Nodo->der = NULL;
					return;
				}
				if (temporal_Nodo->izq == nodoELIMINAR)
				{
					Doctor::cantidad_de_doctores = Doctor::cantidad_de_doctores - 1;
					delete nodoELIMINAR;
					temporal_Nodo->izq = NULL;
					return;
				}
			}
			else {
				Doctor::cantidad_de_doctores = Doctor::cantidad_de_doctores - 1;
				delete nodoELIMINAR;
				this->raiz = NULL;
				return;
			}
		}
	}

	void reemplazar(Doctor* arbol, Doctor* nuevo_nodo) {

		if (arbol->Padre) { //Si el arbol tiene padre

			//arbol->Padre hay que asignarle su nuevo hijo
			if (arbol->Padre->izq != NULL) {
				if (atoi(arbol->Cedula) == atoi(arbol->Padre->izq->Cedula)) {
					TranferirNodo(arbol->Padre->izq, nuevo_nodo);

				}
			}
			else if (arbol->Padre->der != NULL) {
				if (atoi(arbol->Cedula) == atoi(arbol->Padre->der->Cedula)) {
					TranferirNodo(arbol->Padre->der, nuevo_nodo);

				}
			}

		}
		if (nuevo_nodo) { //Si el nuevo nodo existe

			//Procedemos a asignarle su nuevo padre
			nuevo_nodo->Padre = arbol->Padre;

		}
	}

	Doctor* minimo(Doctor* arbol) {

		if (arbol == NULL) {
			return NULL;
		}
		if (arbol->izq) {
			minimo(arbol->izq);  //Buscamos la parte mas izquierda posible
		}
		else { //Si no tiene hijo izquierdo
			return arbol;
		}

	}

	Doctor* BuscarNodo(Doctor** Nodo, int cedula)
	{
		Doctor* temporal_Doctor = *Nodo;
		if (temporal_Doctor != NULL)
		{
			if (cedula < atoi(temporal_Doctor->Cedula))
				BuscarNodo(&temporal_Doctor->izq, cedula);
			else
			{
				if (cedula > atoi(temporal_Doctor->Cedula))
					BuscarNodo(&temporal_Doctor->der, cedula);
				else return temporal_Doctor;
			}
		}
		else return NULL;
	};

	void GuardarDoctor_RECURSIVIDAD(ofstream* Archivo_Doctores, Doctor* Nodo) {

		if (Nodo == NULL) {
			return;
		}

		Archivo_Doctores->write(reinterpret_cast<char*>(Nodo), sizeof(Doctor));

		GuardarDoctor_RECURSIVIDAD(Archivo_Doctores, Nodo->izq);
		GuardarDoctor_RECURSIVIDAD(Archivo_Doctores, Nodo->der);

		Doctor* Temporal_Padre = Nodo->Padre;
		delete Nodo;

		return;

	};

	~Doctor_arbol() {
	
		ofstream Archivo_Doctores;

		 Archivo_Doctores.open("Informacion_DOCTORES.bin", ios::out | ios::trunc | ios::binary | ios::ate);

		if (Archivo_Doctores.fail())
		{          //Si el objeto no se crea 
			MessageBox(NULL, "No se pudo crear el archivo de los DOCTORES", "ERROR", MB_OK);
		}

		GuardarDoctor_RECURSIVIDAD(&Archivo_Doctores, raiz);
	
		Archivo_Doctores.close();

	};

};



void swap_Doctores(Doctor* Destino, Doctor* nodo) {

	Doctor* temporal = new Doctor;

	strcpy(temporal->Nombre, nodo->Nombre);
	strcpy(temporal->Apellidos, nodo->Apellidos);
	strcpy(temporal->Cedula, nodo->Cedula);
	strcpy(temporal->Celular, nodo->Celular);
	strcpy(temporal->Consultorio, nodo->Consultorio);
	strcpy(temporal->Dias_atencion, nodo->Dias_atencion);
	strcpy(temporal->Especialidad, nodo->Especialidad);


	strcpy(nodo->Nombre, Destino->Nombre);
	strcpy(nodo->Apellidos, Destino->Apellidos);
	strcpy(nodo->Cedula, Destino->Cedula);
	strcpy(nodo->Celular, Destino->Celular);
	strcpy(nodo->Consultorio, Destino->Consultorio);
	strcpy(nodo->Dias_atencion, Destino->Dias_atencion);
	strcpy(nodo->Especialidad, Destino->Especialidad);

	strcpy(Destino->Nombre, temporal->Nombre);
	strcpy(Destino->Apellidos, temporal->Apellidos);
	strcpy(Destino->Cedula, temporal->Cedula);
	strcpy(Destino->Celular, temporal->Celular);
	strcpy(Destino->Consultorio, temporal->Consultorio);
	strcpy(Destino->Dias_atencion, temporal->Dias_atencion);
	strcpy(Destino->Especialidad, temporal->Especialidad);

	delete temporal;


}

void quickSort(Doctor* arr, int left, int right)
{
	int i = left, j = right;
	int p = atoi(arr[(left + right) / 2].Cedula);

	while (i <= j)
	{
		while (atoi(arr[i].Cedula) < p) i++;
		while (atoi(arr[j].Cedula) > p) j--;
		if (i <= j)
		{
			swap_Doctores((arr + i), (arr + j));
			//temp = arr[i];
			//arr[i] = arr[j];
			//arr[j] = temp;
			i++, j--;
		}
	}

	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}


class Especialidad {

public:
	char especialidad[30];
	char Descripcion[MAX_PATH];

	Especialidad* next_esp;
	Especialidad* prev_esp;

	Especialidad() {

		next_esp = NULL;
		prev_esp = NULL;

	}

	Especialidad(char Especialidad[],char descripcion[]) {

		strcpy(this->especialidad, Especialidad);
		strcpy(this->Descripcion, descripcion);

	}


}*origen_esp,*aux_esp;

Doctor_arbol* arbol = new Doctor_arbol; //Creamos el arbol



