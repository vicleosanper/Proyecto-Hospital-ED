#pragma once

void heapify(Paciente* arr, int n, int i)
{
	int largo = i; // Initialize largest as root 
	int izq = 2 * i + 1; // left = 2*i + 1 
	int der = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (izq < n && strcmp(arr[izq].Apellidos, arr[largo].Apellidos) > NULL)
		largo = izq;

	// If right child is larger than largest so far 
	if (der < n && strcmp(arr[der].Apellidos, arr[largo].Apellidos) >NULL)
		largo = der;

	// If largest is not root 
	if (largo != i)
	{
		swap(arr[i], arr[largo]);

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largo);
	}
}


void swap(Paciente* arr_raiz, Paciente* arr) {

	Paciente* temporal = new Paciente;

	strcpy_s(temporal->Apellidos, arr->Apellidos);
	strcpy_s(temporal->Nombre, arr->Nombre);
	strcpy_s(temporal->Edad, arr->Edad);
	strcpy_s(temporal->Primermedico_que_lo_atendio, arr->Primermedico_que_lo_atendio);
	strcpy_s(temporal->Genero, arr->Genero);
	strcpy_s(temporal->FechaNacimiento, arr->FechaNacimiento);
	strcpy_s(temporal->Referencia, arr->Referencia);
	strcpy_s(temporal->Telefono, arr->Telefono);


	strcpy_s(arr->Apellidos, arr_raiz->Apellidos);
	strcpy_s(arr->Nombre, arr_raiz->Nombre);
	strcpy_s(arr->Edad, arr_raiz->Edad);
	strcpy_s(arr->Primermedico_que_lo_atendio, arr_raiz->Primermedico_que_lo_atendio);
	strcpy_s(arr->Genero, arr_raiz->Genero);
	strcpy_s(arr->FechaNacimiento, arr_raiz->FechaNacimiento);
	strcpy_s(arr->Referencia, arr_raiz->Referencia);
	strcpy_s(arr->Telefono, arr_raiz->Telefono);


	strcpy_s(arr_raiz->Nombre, temporal->Nombre);
	strcpy_s(arr_raiz->Apellidos, temporal->Apellidos);
	strcpy_s(arr_raiz->Edad, temporal->Edad);
	strcpy_s(arr_raiz->Primermedico_que_lo_atendio, temporal->Primermedico_que_lo_atendio);
	strcpy_s(arr_raiz->Genero, temporal->Genero);
	strcpy_s(arr_raiz->FechaNacimiento, temporal->FechaNacimiento);
	strcpy_s(arr_raiz->Referencia, temporal->Referencia);
	strcpy_s(arr_raiz->Telefono, temporal->Telefono);

	delete temporal;

}


void Heapsort(Paciente* arr, int tamaño) {


	// Build heap (rearrange array) 
	for (int i = tamaño / 2 - 1; i >= 0; i--)
		heapify(arr, tamaño, i);

	// One by one extract an element from heap 
	for (int i = tamaño - 1; i >= 0; i--)
	{
		// Move current root to end 
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap 
		heapify(arr, i, 0);
	}


}

