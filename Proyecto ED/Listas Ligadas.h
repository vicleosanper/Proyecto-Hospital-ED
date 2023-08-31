#pragma once

class ListasLigadas {

public:

	void AgregarPaciente(char Nombre[],char Apellidos[], char Genero[], char Edad[], char FechaNacimiento[], char Telefono[], char Referencia[], char Primermedico_que_lo_atendio[],int caso,int ID) {//EL ID es en caso de vayamos a modificar

		switch (caso) {

			case 1: //NUEVO PACIENTE
			{
				if (origen == NULL) {

					origen = new Paciente(Nombre, Apellidos, Genero, Edad, FechaNacimiento, Telefono, Referencia, Primermedico_que_lo_atendio);
					aux = origen;
					aux->prev = NULL; //NULL por que es la primera estructura, y no hay nada antes de ella
					aux->next = NULL;

				}

				else {

					aux = origen;

					while (aux->next != NULL) { //Hasta que nos topemos con el final
						aux = aux->next;
					}

					aux->next = new Paciente(Nombre, Apellidos, Genero, Edad, FechaNacimiento, Telefono, Referencia, Primermedico_que_lo_atendio);
					aux->next->prev = aux;
					aux->next->next = NULL;
					aux = aux->next;

				}

			}
			break;

			case 2: // Modificar
			{

				aux = origen;

				while (aux->ID != ID) { //Hasta que nos topemos con el ID del paciente que vamos a modificar
					aux = aux->next;
				}

				strcpy(aux->Nombre, Nombre);
				strcpy(aux->Apellidos, Apellidos);
				strcpy(aux->Genero, Genero);
				strcpy(aux->Telefono, Telefono);
				strcpy(aux->Referencia, Referencia);
				strcpy(aux->FechaNacimiento, FechaNacimiento);
				strcpy(aux->Edad, Edad);
				strcpy(aux->Primermedico_que_lo_atendio, Primermedico_que_lo_atendio);
			}

		}

		

	}

	void AgregarCita(char Fecha[], char Hora[], char Doctor[], char Especialidad[], char Paciente[], char Celular[], char Consultorio[]) {

		if (origenC == NULL) {

			origenC = new Citas(Fecha, Hora, Doctor, Especialidad, Paciente, Celular, Consultorio);
			auxC = origenC;
			auxC->prevC = NULL; //NULL por que es la primera estructura, y no hay nada antes de ella
			auxC->nextC = NULL;

		}

		else {

			auxC = origenC;

			while (auxC->nextC != NULL) { //Hasta que nos topemos con el final
				auxC = auxC->nextC;
			}

			auxC->nextC = new Citas(Fecha, Hora, Doctor, Especialidad, Paciente, Celular, Consultorio);
			auxC->nextC->prevC = auxC;
			auxC->nextC->nextC = NULL;
			auxC = auxC->nextC;

		}


	}

	void AgregarEspecialidad(char especialidad[],char descripcion[]) {

		if (origen_esp == NULL) {

			origen_esp = new Especialidad(especialidad, descripcion);
			aux_esp = origen_esp;
			aux_esp->prev_esp = NULL; //NULL por que es la primera estructura, y no hay nada antes de ella
			aux_esp->next_esp = NULL;

		}

		else {

			aux_esp = origen_esp;

			while (aux_esp->next_esp != NULL) { //Hasta que nos topemos con el final
				aux_esp = aux_esp->next_esp;
			}

			aux_esp->next_esp = new Especialidad(especialidad, descripcion);
			aux_esp->next_esp->prev_esp = aux_esp;
			aux_esp->next_esp->next_esp = NULL;
			aux_esp = aux_esp->next_esp;

		}



	}

	friend class Pacientes;
	friend class Citas;

};