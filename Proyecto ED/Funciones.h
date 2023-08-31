#pragma once

int INICIOSESION(char Clave[], char LogUsuario[], char LogContraseña[]) {

	ifstream lectura("DatosIniciodeSesion.txt", ios::in);//Abrimos el archivo en modo lectura
	bool UsuarioEncontrado = false;

	if (lectura.fail()) {

		MessageBox(NULL, "ERROR", "No se ha podido realizar la lectura", MB_OK);
		return 0;
	}

	else {

		while (!lectura.eof()) {  //En este ciclo leemos todo el documento de texto

			lectura >> ClaveUsuario;
			lectura.getline(Usuario, 50); //Leemos el usuario y la constraseña
			lectura.getline(Usuario, 50); //Leemos el usuario y la constraseña
			lectura >> Contraseña;

			if (strcmp(LogUsuario, Usuario) == 0 && strcmp(LogContraseña, Contraseña) == 0 && strcmp(Clave, ClaveUsuario) == 0) {

				return 1; //La contraseña es correcta
				UsuarioEncontrado = true;
			}

		}

		if (UsuarioEncontrado == false) {
			return 0;
		}


	}

}

//Heapsort
bool Reporte_Pacientes(HWND Ventana) {

	if (origen == NULL) { //Comprobamos si hay informacion en la lista ligada

		MessageBox(Ventana, "No hay pacientes registrados", "Error", MB_OK);
		return false;

	}

	else {

		aux = origen; //Punteros de Paciente
		int numero_de_pacientes = 0;

		while (aux != NULL) { //Ciclo para contar el numero de pacientes que hay en la lista ligada

			numero_de_pacientes = numero_de_pacientes + 1;
			aux = aux->next;

		}

		Paciente* pacientes = new Paciente[numero_de_pacientes]; //Arreglo

		aux = origen;

		for (int i = 0; i < numero_de_pacientes; i++) {

			pacientes[i] = *aux;

			aux = aux->next;

		}

		Heapsort(pacientes, numero_de_pacientes); //Mandamos a llamar la funcion del heapsort

		//Y una vez organizado el arreglo "pacientes"

		ofstream Reporte("Pacientes.TXT", ios::out|| ios::trunc); //Abrimos el objeto Datos

		if (Reporte.fail())
		{          //Si el objeto no se crea 
			MessageBox(Ventana, "No se pudo crear el reporte", "ERROR", MB_OK);

		}

		else
		{

			for (int i = 0; i < numero_de_pacientes; i++) {

				Reporte << "\n" << "Apellidos: " << pacientes[i].Apellidos << "\n";
				Reporte << "Nombre: " << pacientes[i].Nombre << "\n";
				Reporte << "Edad: " << pacientes[i].Edad << "\n";
				Reporte << "Fecha de nacimiento:" << pacientes[i].FechaNacimiento << "\n";
				Reporte << "Genero: " << pacientes[i].Genero << "\n";
				Reporte << "Primer medico que lo atendio: " << pacientes[i].Primermedico_que_lo_atendio << "\n";
				Reporte << "Referencia: " << pacientes[i].Referencia << "\n";
				Reporte << "Telefono: " << pacientes[i].Telefono << "\n";
			}

			//delete pacientes;
			return true;

		}

	}


}

bool Reporte_doctores(HWND Ventana,Doctor*arr) {

	ofstream Reporte("Doctores.TXT", ios::out|| ios::trunc); //Abrimos el objeto Datos

	if (Reporte.fail())
	{          //Si el objeto no se crea 
		MessageBox(Ventana, "No se pudo crear el reporte", "ERROR", MB_OK);

	}

	else
	{

		for (int i = 0; i <= Doctor::cantidad_de_doctores-1; i++) {
			
			Reporte << "\n" << "Cedula: " << arr[i].Cedula << "\n";
			Reporte << "Apellidos: " << arr[i].Apellidos << "\n";
			Reporte << "Nombre: " << arr[i].Nombre << "\n";
			Reporte <<"Celular: "<< arr[i].Celular << "\n";
			Reporte <<"Consultorio: "<< arr[i].Consultorio << "\n";
			Reporte <<"Dias en los que atiende el doctor: "<< arr[i].Dias_atencion << "\n";
			Reporte <<"Especialidad: "<< arr[i].Especialidad << "\n";
			
		}

		//delete pacientes;
		MessageBox(Ventana, "Reporte de doctores realizado", "Exito", MB_OK);
		return true;

	}
	

	return true;
}

bool Consultaporsemana(HWND vent,string Mes,char* Semana[]) {

	ofstream Reporte("Consultaporsemana.txt", ios::out|| ios::trunc); //Abrimos el objeto Datos

	if (Reporte.fail())
	{          //Si el objeto no se crea 
		MessageBox(vent, "No se pudo crear el reporte", "ERROR", MB_OK);

	}

	else
	{
		int semana = atoi(*Semana);
		int mes = 0;

		if (Mes == "enero") {
			mes = 1;
		}
		else if (Mes == "febrero") {
			mes = 2;
		}
		else if (Mes == "marzo") {
			mes = 3;
		}
		else if (Mes == "abril") {
			mes = 4;
		}
		else if (Mes == "mayo") {
			mes = 5;
		}
		else if (Mes == "junio") {
			mes = 6;
		}
		else if (Mes == "julio") {
			mes = 7;
		}
		else if (Mes == "agosto") {
			mes = 8;
		}
		else if (Mes == "septiembre") {
			mes = 9;
		}
		else if (Mes == "octubre") {
			mes = 10;
		}
		else if (Mes == "noviembre") {
			mes = 11;
		}
		else if (Mes == "diciembre") {
			mes = 12;
		}

		auxC = origenC;

		string FECHA_CITA;

		Reporte << "\n" << "MES: " << Mes << "\n";
		Reporte << "Semana no." << semana << ": " << "\n";
		Reporte << "FECHAS:" << "\n";

		while (auxC != NULL) {

			FECHA_CITA = auxC->Fecha;

			if (Comparacion_de_fechas(FECHA_CITA, mes, semana) == true) {
				Reporte << FECHA_CITA << "\n";
				Reporte << "Hora: " << auxC->Hora << "\n";
				Reporte << "Numero de cita: " << auxC->ID_c << "\n";
				Reporte << "Consultorio: " << auxC->Consultorio << "\n";
				Reporte << "Especialidad: " << auxC->Especialidad << "\n";
				Reporte << "Nombre del medico: " << auxC->Doctor << "\n";
				Reporte << "Nombre del paciente: " << auxC->Paciente << "\n";
				Reporte << "Telefono del Paciente: " << auxC->Celular << "\n";

				if (auxC->Estado_de_cita == 0) {
					Reporte << "Estado de la cita: " << "En espera" << "\n";
				}
				else if (auxC->Estado_de_cita == 1) {
					Reporte << "Estado de la cita: " << "Se llevo a cabo" << "\n";
				}
				else if (auxC->Estado_de_cita == 2) {
					Reporte << "Estado de la cita: " << "Cancelada" << "\n";
				}

				
			}

			auxC = auxC->nextC;
			

		}

			
		//delete pacientes;
		MessageBox(vent, "El archivo de la consulta se ha guardado", "Exito", MB_OK);
		return true;

	}


	//return true;


}

bool ConsultaporsemanayESPECIALIDAD(HWND vent, string Mes, char* Semana[],char* ESPECIALIDAD[]) {

	ofstream Reporte("ConsultaporsemanayESPECIALIDAD.txt", ios::out || ios::trunc); //Abrimos el objeto Datos

	if (Reporte.fail())
	{          //Si el objeto no se crea 
		MessageBox(vent, "No se pudo crear el reporte", "ERROR", MB_OK);

	}

	else
	{
		int semana = atoi(*Semana);
		int mes = 0;

		if (Mes == "enero") {
			mes = 1;
		}
		else if (Mes == "febrero") {
			mes = 2;
		}
		else if (Mes == "marzo") {
			mes = 3;
		}
		else if (Mes == "abril") {
			mes = 4;
		}
		else if (Mes == "mayo") {
			mes = 5;
		}
		else if (Mes == "junio") {
			mes = 6;
		}
		else if (Mes == "julio") {
			mes = 7;
		}
		else if (Mes == "agosto") {
			mes = 8;
		}
		else if (Mes == "septiembre") {
			mes = 9;
		}
		else if (Mes == "octubre") {
			mes = 10;
		}
		else if (Mes == "noviembre") {
			mes = 11;
		}
		else if (Mes == "diciembre") {
			mes = 12;
		}

		auxC = origenC;

		string FECHA_CITA;

		Reporte << "Especialidad" << ESPECIALIDAD << "\n";
		Reporte << "\n" << "MES: " << Mes << "\n";
		Reporte << "Semana no." << semana << ": " << "\n";
		Reporte << "FECHAS:" << "\n";

		while (auxC != NULL) {

			FECHA_CITA = auxC->Fecha;

			if (Comparacion_de_fechas(FECHA_CITA, mes, semana) == true) {

				if (strcmp(auxC->Especialidad, *ESPECIALIDAD) == 0) {//Si coinciden
					Reporte << FECHA_CITA <<"\n";
					Reporte << "Hora: " << auxC->Hora << "\n";
					Reporte << "Numero de cita: " << auxC->ID_c << "\n";
					Reporte << "Consultorio: " << auxC->Consultorio << "\n";
					Reporte << "Especialidad: " << auxC->Especialidad << "\n";
					Reporte << "Nombre del medico: " << auxC->Doctor << "\n";
					Reporte << "Nombre del paciente: " << auxC->Paciente << "\n";
					Reporte << "Telefono del Paciente: " << auxC->Celular << "\n";

					if (auxC->Estado_de_cita == 0) {
						Reporte << "Estado de la cita: " << "En espera" << "\n";
					}
					else if (auxC->Estado_de_cita == 1) {
						Reporte << "Estado de la cita: " << "Se llevo a cabo" << "\n";
					}
					else if (auxC->Estado_de_cita == 2) {
						Reporte << "Estado de la cita: " << "Cancelada" << "\n";
					}
				}

				
			}

			auxC = auxC->nextC;


		}


		//delete pacientes;
		MessageBox(vent, "El archivo de la consulta se ha guardado", "Exito", MB_OK);
		return true;

	}


	//return true;


}

bool ConsultaporMES(HWND vent, string Mes, char* Cedula[]){

	ofstream Reporte("ConsultaporMES.txt", ios::out || ios::trunc); //Abrimos el objeto Datos

	if (Reporte.fail())
	{          //Si el objeto no se crea 
		MessageBox(vent, "No se pudo crear el reporte", "ERROR", MB_OK);

	}

	else
	{
		
		int mes = 0;

		if (Mes == "enero") {
			mes = 1;
		}
		else if (Mes == "febrero") {
			mes = 2;
		}
		else if (Mes == "marzo") {
			mes = 3;
		}
		else if (Mes == "abril") {
			mes = 4;
		}
		else if (Mes == "mayo") {
			mes = 5;
		}
		else if (Mes == "junio") {
			mes = 6;
		}
		else if (Mes == "julio") {
			mes = 7;
		}
		else if (Mes == "agosto") {
			mes = 8;
		}
		else if (Mes == "septiembre") {
			mes = 9;
		}
		else if (Mes == "octubre") {
			mes = 10;
		}
		else if (Mes == "noviembre") {
			mes = 11;
		}
		else if (Mes == "diciembre") {
			mes = 12;
		}

		auxC = origenC;

		string FECHA_CITA;

		////
		
		Doctor* arr = arbol->Arreglo_del_arbol();//En un arreglo ponemos a los doctores
	
		int indice = Busqueda_BINARIA_CONSULTA_MES(vent, atoi(*Cedula), arr);
		
		////

		Reporte << "\n" << "MES: " << Mes << "\n";
		Reporte << "Doctor:" << arr[indice].Nombre<<arr[indice].Apellidos << ": " << "\n";
		Reporte << "FECHAS:" << "\n";

		while (auxC != NULL) {

			FECHA_CITA = auxC->Fecha;
			//Aqui quiero busqueda binaria para encontrar fechas

			if (Comparacion_de_MES(FECHA_CITA, mes) ==true ) {

				if (strcmp(arr[indice].Nombre, auxC->Doctor) == 0) {

					Reporte <<"\n"<< FECHA_CITA << "\n";
					Reporte <<"\n"<< "Hora: " << auxC->Hora << "\n";
					Reporte << "Numero de cita: " << auxC->ID_c << "\n";
					Reporte << "Consultorio: " << auxC->Consultorio << "\n";
					Reporte << "Especialidad: " << auxC->Especialidad << "\n";
					Reporte << "Nombre del medico: " << auxC->Doctor << "\n";
					Reporte << "Nombre del paciente: " << auxC->Paciente << "\n";
					Reporte << "Telefono del Paciente: " << auxC->Celular << "\n";

					if (auxC->Estado_de_cita == 0) {
						Reporte << "Estado de la cita: " << "En espera" << "\n";
					}
					else if (auxC->Estado_de_cita == 1) {
						Reporte << "Estado de la cita: " << "Se llevo a cabo" << "\n";
					}
					else if (auxC->Estado_de_cita == 2) {
						Reporte << "Estado de la cita: " << "Cancelada" << "\n";
					}
				}

			
			}
			
			auxC = auxC->nextC;


		}


		//delete pacientes;
		
		return true;

	}


	//return true;


}

int Busqueda_BINARIA_CONSULTA_MES(HWND vent, int cedula,Doctor* arr) {

	//En este punto el arreglo ya tiene los ID de las citas, y empezamos la busqueda binaria

	int inf, sup, mitad;
	inf = 0;
	sup = Doctor::cantidad_de_doctores;

	quickSort(arr, 0, Doctor::cantidad_de_doctores - 1);

	while (inf <= sup) {

		mitad = (inf + sup) / 2;

		if (atoi(arr[mitad].Cedula) == cedula) {
			return mitad;
		}
		if (atoi(arr[mitad].Cedula) > cedula) {

			sup = mitad;
			mitad = (inf + sup) / 2;

		}
		if (atoi(arr[mitad].Cedula) < cedula) {

			inf = mitad;
			mitad = (inf + sup) / 2;

		}

	}


	

}

int Busqueda_BINARIA(HWND vent,char *ID_CITA[]) {


	auxC = origenC;
	int cantidad_de_citas=0;

	while (auxC != NULL) {

		cantidad_de_citas++;
		auxC = auxC->nextC;
	}


	int* ID_citas = new int[cantidad_de_citas];

	auxC = origenC;

	for (int i = 0; i < cantidad_de_citas;i++) {

		ID_citas[i]=auxC->ID_c;

		auxC = auxC->nextC;
	}

	//En este punto el arreglo ya tiene los ID de las citas, y empezamos la busqueda binaria

	int inf, sup, mitad;
	inf = 0;
	sup = cantidad_de_citas;

	while (inf <= sup) {

		mitad = (inf + sup) / 2;

		if (ID_citas[mitad] == atoi(*ID_CITA)) {
			return mitad;
		}
		if (ID_citas[mitad] > atoi(*ID_CITA)) {
			
			sup = mitad;
			mitad = (inf + sup) / 2;

		}
		if (ID_citas[mitad] < atoi(*ID_CITA)) {

			inf = mitad;
			mitad = (inf + sup) / 2;

		}

	}
	
}

void ELIMINAR_LISTAS_LIGADAS() {

	aux = origen;

	while (aux != NULL && aux->next != NULL) { //Buscamos llegar al final de la lista

		aux = aux->next;

	}
	Paciente* aux2;
	while (aux != origen) { //Eliminamos de atras hacia adelante


		aux2 = aux; //Le damos a aux2 la direccion de nodo
		aux = aux->prev; //Nos movemos hacia atras
		delete aux2; //Eliminamos el nodo


	}
	delete aux; //Eliminamos el ultimo nodo


	auxC = origenC;
	while (auxC != NULL && auxC->nextC != NULL) { //Buscamos llegar al final de la lista

		auxC = auxC->nextC;

	}
	Citas* aux2_C;
	while (auxC != origenC) { //Eliminamos de atras hacia adelante


		aux2_C = auxC; //Le damos a aux2 la direccion de nodo
		auxC = auxC->prevC; //Nos movemos hacia atras
		delete aux2_C; //Eliminamos el nodo


	}
	delete auxC; //Eliminamos el ultimo nodo

	aux_esp = origen_esp;
	while (aux_esp != NULL && aux_esp->next_esp != NULL) { //Buscamos llegar al final de la lista

		aux_esp = aux_esp->next_esp;

	}
	Especialidad* aux2_esp;
	while (aux_esp != origen_esp) { //Eliminamos de atras hacia adelante


		aux2_esp = aux_esp; //Le damos a aux2 la direccion de nodo
		aux_esp = aux_esp->prev_esp; //Nos movemos hacia atras
		delete aux2_esp; //Eliminamos el nodo


	}
	delete aux_esp; //Eliminamos el ultimo nodo


}



bool Comparacion_de_fechas(string FECHA_CITA,int MES_INGRESADO,int SEMANA_INGRESADA) {

	//FECHA de las registradas
	string str_dia, str_mes;
	int dia, mes;

	int indice = 0;
	while (FECHA_CITA[indice] != ',') {

		indice++;

	}

	indice = indice + 2;
	int i_dia = indice;

	int cantidad_de_caracteres = 0;

	while (FECHA_CITA[i_dia] != ' ') {

		i_dia++;
		cantidad_de_caracteres++;
	}

	str_dia = FECHA_CITA.substr(indice, cantidad_de_caracteres);
	dia = atoi(str_dia.c_str());


	indice = indice + 5;
	int i_mes = indice;
	cantidad_de_caracteres = 0;
	while (FECHA_CITA[i_mes] != ' ') {

		i_mes++;
		cantidad_de_caracteres++;
	}

	str_mes = FECHA_CITA.substr(indice, cantidad_de_caracteres);

	if (str_mes == "enero") {
		mes = 1;
	}
	else if (str_mes == "febrero") {
		mes = 2;
	}
	else if (str_mes == "marzo") {
		mes = 3;
	}
	else if (str_mes == "abril") {
		mes = 4;
	}
	else if (str_mes == "mayo") {
		mes = 5;
	}
	else if (str_mes == "junio") {
		mes = 6;
	}
	else if (str_mes == "julio") {
		mes = 7;
	}
	else if (str_mes == "agosto") {
		mes = 8;
	}
	else if (str_mes == "septiembre") {
		mes = 9;
	}
	else if (str_mes == "octubre") {
		mes = 10;
	}
	else if (str_mes == "noviembre") {
		mes = 11;
	}
	else if (str_mes == "diciembre") {
		mes = 12;
	}

	if (mes == MES_INGRESADO) {

		if (SEMANA_INGRESADA == 1) {
			if (dia >= 1 && dia <= 7) {
				return true;
			}
		}
		else  if (SEMANA_INGRESADA == 2) {
			if (dia >= 8 && dia <= 14) {
				return true;
			}
		}
		else  if (SEMANA_INGRESADA == 3) {
			if (dia >= 15 && dia <= 21) {
				return true;
			}
		}
		else  if (SEMANA_INGRESADA == 4) {
			if (dia >= 22 && dia <= 28) {
				return true;
			}
		}
		else  if (SEMANA_INGRESADA == 5) {
			if (dia >= 29 && dia <= 31) {
				return true;
			}
		}
		else if (SEMANA_INGRESADA > 5) {
			return false;
		}
		
	}


}

bool Comparacion_de_MES(string FECHA_CITA, int MES_INGRESADO){

	//FECHA de las registradas
	string str_dia, str_mes;
	int dia, mes;

	int indice = 0;
	while (FECHA_CITA[indice] != ',') {

		indice++;

	}

	indice = indice + 2;
	int i_dia = indice;

	int cantidad_de_caracteres = 0;

	while (FECHA_CITA[i_dia] != ' ') {

		i_dia++;
		cantidad_de_caracteres++;
	}

	str_dia = FECHA_CITA.substr(indice, cantidad_de_caracteres);
	dia = atoi(str_dia.c_str());


	indice = indice + 5;
	int i_mes = indice;
	cantidad_de_caracteres = 0;
	while (FECHA_CITA[i_mes] != ' ') {

		i_mes++;
		cantidad_de_caracteres++;
	}

	str_mes = FECHA_CITA.substr(indice, cantidad_de_caracteres);

	if (str_mes == "enero") {
		mes = 1;
	}
	else if (str_mes == "febrero") {
		mes = 2;
	}
	else if (str_mes == "marzo") {
		mes = 3;
	}
	else if (str_mes == "abril") {
		mes = 4;
	}
	else if (str_mes == "mayo") {
		mes = 5;
	}
	else if (str_mes == "junio") {
		mes = 6;
	}
	else if (str_mes == "julio") {
		mes = 7;
	}
	else if (str_mes == "agosto") {
		mes = 8;
	}
	else if (str_mes == "septiembre") {
		mes = 9;
	}
	else if (str_mes == "octubre") {
		mes = 10;
	}
	else if (str_mes == "noviembre") {
		mes = 11;
	}
	else if (str_mes == "diciembre") {
		mes = 12;
	}

	if (mes == MES_INGRESADO) {

		return true;
	}

}

//VALIDACIONES

bool ValidacionLongitud(HWND vent, int caso) {

	switch (caso) {
	case 1: //Pacientes
	{
		bool identificador = true;

		HWND hEditBoxNOMBRE = GetDlgItem(vent, IDC_PACIENTE);
		HWND hEditBoxGENERO = GetDlgItem(vent, IDC_GENERO);
		HWND hEditBoxTELEFONO = GetDlgItem(vent, IDC_TELEFONO);
		HWND hEditBoxREFERENCIA = GetDlgItem(vent, IDC_REFERENCIA);
		HWND hEditBoxNACIMIENTO = GetDlgItem(vent, IDC_FECHA_NACIMIENTO);
		HWND hEditBoxEDAD = GetDlgItem(vent, IDC_EDAD);
		HWND hEditBoxPRIMER_MEDICO = GetDlgItem(vent, IDC_1er_medico);

		int longitud_Nom = GetWindowTextLength(hEditBoxNOMBRE); //Sacamos la longitud
		int longitud_Gen = GetWindowTextLength(hEditBoxGENERO); //Sacamos la longitud
		int longitud_Tel = GetWindowTextLength(hEditBoxTELEFONO); //Sacamos la longitud
		int longitud_Ref = GetWindowTextLength(hEditBoxREFERENCIA); //Sacamos la longitud
		int longitud_Nac = GetWindowTextLength(hEditBoxNACIMIENTO); //Sacamos la longitud
		int longitud_EDAD = GetWindowTextLength(hEditBoxEDAD); //Sacamos la longitud
		int longitud_1er_med = GetWindowTextLength(hEditBoxPRIMER_MEDICO); //Sacamos la longitud


		if (longitud_Nom <= 0 || longitud_Gen <= 0 || longitud_Tel <= 0 || longitud_Ref <= 0 || longitud_Nac <= 0 || longitud_EDAD <= 0 || longitud_1er_med <= 0) {
			MessageBox(vent, "Porfavor rellene los espacios vacios", "ERROR", MB_OK);
			return false;
		}
		else {

			return true;
		}
	}//FIN DEL CASO 1
	break;

		case 2: { //Medicos

			bool identificador = true;

			HWND hEditBoxCedula = GetDlgItem(vent, IDC_Cedula);
			HWND hEditBoxNombreDoc = GetDlgItem(vent, IDC_EDIT2);
			HWND hEditBoxAPELLIDOS = GetDlgItem(vent, IDC_APELLIDOS);
			HWND hEditBoxNumero_consultorio = GetDlgItem(vent, IDC_Consultorio);
			HWND hEditBoxNumero_celular = GetDlgItem(vent, IDC_NumCel);
			HWND hEditBoxEspecialidad = GetDlgItem(vent, IDC_Especialidad);
			HWND hEditBoxLunes = GetDlgItem(vent, IDC_E1);
			HWND hEditBoxMartes = GetDlgItem(vent, IDC_E2);
			HWND hEditBoxMiercoles = GetDlgItem(vent, IDC_E3);
			HWND hEditBoxJueves = GetDlgItem(vent, IDC_E4);
			HWND hEditBoxViernes = GetDlgItem(vent, IDC_E5);


			int longitud_Cedula = GetWindowTextLength(hEditBoxCedula); //Sacamos la longitud
			int longitud_Doctor = GetWindowTextLength(hEditBoxNombreDoc); //Sacamos la longitud
			int longitud_APELLIDOS = GetWindowTextLength(hEditBoxAPELLIDOS);
			int longitud_Consultorio = GetWindowTextLength(hEditBoxNumero_consultorio); //Sacamos la longitud
			int longitud_Celular = GetWindowTextLength(hEditBoxNumero_celular); //Sacamos la longitud
			int longitud_Especialidad = GetWindowTextLength(hEditBoxEspecialidad); //Sacamos la longitud

			int Longitud_LUNES = GetWindowTextLength(hEditBoxLunes); //Sacamos la longitud
			int Longitud_MARTES = GetWindowTextLength(hEditBoxMartes); //Sacamos la longitud
			int Longitud_MIERCOLES = GetWindowTextLength(hEditBoxMiercoles); //Sacamos la longitud
			int Longitud_JUEVES = GetWindowTextLength(hEditBoxJueves); //Sacamos la longitud
			int Longitud_VIERNES = GetWindowTextLength(hEditBoxViernes); //Sacamos la longitud

			if (longitud_Cedula <= 0 || longitud_Doctor <= 0 || longitud_APELLIDOS <= 0 || longitud_Celular <= 0 || longitud_Consultorio <= 0 || longitud_Especialidad <= 0 
				|| Longitud_LUNES <= 0|| Longitud_MARTES<=0|| Longitud_MIERCOLES<=0|| Longitud_JUEVES<=0|| Longitud_VIERNES<=0) {
				MessageBox(vent, "Porfavor rellene los espacios vacios", "ERROR", MB_OK);
				return false;
			}
			else {

				return true;
			}

		}

		case 3: { //Especialidades


			bool identificador = true;

			HWND hEditBoxEspecialidad = GetDlgItem(vent, ID_Especialidad);
			HWND hEditBoxDescripcion = GetDlgItem(vent, IDC_Descripcion);
		
			int longitud_Especialidad = GetWindowTextLength(hEditBoxEspecialidad); //Sacamos la longitud
			int longitud_Descripcion = GetWindowTextLength(hEditBoxDescripcion); //Sacamos la longitud
			


			if (longitud_Especialidad <= 0 || longitud_Descripcion <= 0) {
				MessageBox(vent, "Porfavor rellene los espacios vacios", "ERROR", MB_OK);
				return false;
			}
			else {

				return true;
			}

		}

		case 4: { //CITAS

			bool identificador = true;

			HWND hEditBoxEspecialidad = GetDlgItem(vent, IDC_Especialidad);
			HWND hEditBoxDoctor = GetDlgItem(vent, IDC_Doctor);
			HWND hEditBoxPaciente = GetDlgItem(vent, IDC_COMBO_Paciente);
			HWND hEditBoxCelular = GetDlgItem(vent, IDC_Celular);
			HWND hEditBoxConsultorio = GetDlgItem(vent, IDC_Consultorio);
			HWND hEditBoxDia = GetDlgItem(vent, IDC_Dia);
			HWND hEditBoxHora = GetDlgItem(vent, IDC_Hora);

			int longitud_Especialidad = GetWindowTextLength(hEditBoxEspecialidad); //Sacamos la longitud
			int longitud_Doctor = GetWindowTextLength(hEditBoxDoctor); //Sacamos la longitud
			int longitud_Paciente = GetWindowTextLength(hEditBoxPaciente); //Sacamos la longitud
			int longitud_Celular = GetWindowTextLength(hEditBoxCelular); //Sacamos la longitud
			int longitud_Consultorio = GetWindowTextLength(hEditBoxConsultorio); //Sacamos la longitud
			int longitud_Dia = GetWindowTextLength(hEditBoxDia); //Sacamos la longitud
			int longitud_Hora = GetWindowTextLength(hEditBoxHora); //Sacamos la longitud


			if (longitud_Especialidad <= 0 || longitud_Doctor <= 0 || longitud_Paciente <= 0 || longitud_Celular <= 0 || longitud_Consultorio <= 0 ||
				longitud_Dia <=0|| longitud_Hora<=0) {
				MessageBox(vent, "Porfavor rellene los espacios vacios", "ERROR", MB_OK);
				return false;
			}
			else {

				return true;
			}


		}

	}

}

int validar_nombre(char nombre[])
{

	int i;
	char espacio[2] = " ";

	if (strlen(nombre) == 0) { //No ingreso ningun caracter

		return 0;

	}

	for (i = 0; i < strlen(nombre); i++) // SRLEN te da el numero de caracteres que contiene la cadena "nombre"
	{
		if (!(nombre[i] >= 65 && nombre[i] <= 90
			|| nombre[i] >= 97 && nombre[i] <= 122
			|| nombre[i] == espacio[0] || nombre[i] >= 129 && nombre[i] <= 154
			|| nombre[i] >= 160 && nombre[i] <= 165 || nombre[i] == -19 || nombre[i] == 46
			|| nombre[i] == -23 || nombre[i] == -55 || nombre[i] == -31 || nombre[i] == -13
			|| nombre[i] == -6 || nombre[i] == -63 || nombre[i] == -51 || nombre[i] == -45
			|| nombre[i] == -38)) // del 65 al 90 son letras mayusculas, y del 97 al 122 son letras minusculas
		{

			return 0; //Si el usuario NO solo ingreso letras se retornara un 0
		}

	}
	return 1;//Si el usuario ingreso solo letras entonces se retorna el 1

}

int validar_nombreESPECIALIDAD(char nombre[])
{

	if (strlen(nombre) == 0) { //No ingreso ningun caracter

		return 0;

	}

	aux_esp = origen_esp;

	while(aux_esp != NULL) // SRLEN te da el numero de caracteres que contiene la cadena "nombre"
	{
		if (strcmp(nombre,aux_esp->especialidad)==0) //Si coincide
		{
			return 1;//Si el usuario ingreso 
			
		}
		aux_esp = aux_esp->next_esp;

	}
	
	return 0; //Si el usuario NO solo ingreso una especialidad registrada
}

int validar_numeroTEL(char numero[])
{
	int i;    //POSICION

	if (Doctor::cantidad_de_doctores > 0) {
		Doctor* arr = arbol->Arreglo_del_arbol();//En un arreglo ponemos a los doctores
		int indice;

		for (indice = 0; indice < Doctor::cantidad_de_doctores; indice++) {

			if (strcmp(arr[indice].Celular, numero) == 0) { //Si ya hay una cedula igual
				delete arr;
				return 2;
			}

		}

		delete arr;
	}


	if (strlen(numero) != 8 && strlen(numero) != 10 && strlen(numero) != 12) {

		return 0;

	}

	for (i = 0; i < strlen(numero); i++)
	{
		if (numero[i] == 45) //El numero 45 es el signo de negativo
		{
			return 0;
		}

		if (numero[i] == 46)//46 en el codigo ASCI es el punto "."
		{
			return 0;
		}

		if (!isdigit(numero[i]))//El numero 46 es un punto //El isdigit te da VERDADERO si es numero, en este caso si NO ES NUMERO hace lo siguiente
		{
			return 0;
		}

	}


	return 1;//Si se retorna 1 significa que la cadena ingresada solo contiene numeros
}

int validar_Paciente(char Paciente[]) {

	if (strlen(Paciente) == 0) { //No ingreso ningun caracter

		return 0;

	}

	aux = origen;

	while (aux != NULL)
	{
		if (strcmp(Paciente, aux->Nombre) == 0) //Si coincide
		{
			return 1;//Si el usuario ingreso un Paciente Registrado

		}
		aux = aux->next;

	}

	return 0; //Si el usuario NO solo ingreso un Paciente Registrado

}

int validar_HORARIO(char Horario[]) {

	if (strcmp(Horario ,"LIBRE")!= 0) {

		if (strlen(Horario) == 0) { //No ingreso ningun caracter

			return 0;

		}

		if (strlen(Horario) < 10) { //No ingreso ningun caracter

			return 0;

		}

	}
	return -1;
}

int validar_CEDULA(char Cedula[]) {

	int i;    //POSICION

	if (Doctor::cantidad_de_doctores > 0) {
		Doctor* arr = arbol->Arreglo_del_arbol();//En un arreglo ponemos a los doctores
		int indice;

		for (indice = 0; indice < Doctor::cantidad_de_doctores; indice++) {

			if (strcmp(arr[indice].Cedula, Cedula) == 0) { //Si ya hay una cedula igual
				delete arr;
				return 2;
		    }

		}

		delete arr;
	}


	if (strlen(Cedula) != 7 && strlen(Cedula) != 8 && strlen(Cedula) != 12) {

		return 0;

	}

	for (i = 0; i < strlen(Cedula); i++)
	{
		if (Cedula[i] == 45) //El numero 45 es el signo de negativo
		{
			return 0;
		}

		if (Cedula[i] == 46)//46 en el codigo ASCI es el punto "."
		{
			return 0;
		}

		if (!isdigit(Cedula[i]))//El numero 46 es un punto //El isdigit te da VERDADERO si es numero, en este caso si NO ES NUMERO hace lo siguiente
		{
			return 0;
		}

	}


	return 1;//Si se retorna 1 significa que la cadena ingresada solo contiene numeros

}

int validar_Doctor_seleccionado(char doctor[]) {

	if (Doctor::cantidad_de_doctores > 0) {
		Doctor* arr = arbol->Arreglo_del_arbol();//En un arreglo ponemos a los doctores
		int indice;

		for (indice = 0; indice < Doctor::cantidad_de_doctores; indice++) {



			if (doctor != arr[indice].Nombre) {
				return -1;
			}

		}

		delete arr;

	}

	return 0;
}



int validar_fecha_y_hora(string FECHA_ACTUAL, string HORA_ACTUAL, string FECHA_INGRESADA, string HORA_INGRESADA,int Consultorio_ingresado) {



	if (validar_fecha(FECHA_INGRESADA, FECHA_ACTUAL) == 0) { //SI YA PASO

		return 1;

	}

	//Si todo sale bien
	if (validar_fecha(FECHA_INGRESADA, FECHA_ACTUAL) == 5) { //La cita esta registrada para despues


		if (validar_fecha2(FECHA_INGRESADA, HORA_INGRESADA, Consultorio_ingresado) == 0) { //Alguna fecha se empalma

			return 0;

		}
		else if (validar_fecha2(FECHA_INGRESADA, HORA_INGRESADA, Consultorio_ingresado) == 4) { //No hay una diferencia de 1 hora al menos

			return 4;

		}
		else if (validar_fecha2(FECHA_INGRESADA, HORA_INGRESADA, Consultorio_ingresado) == 10) { //Todo salio correctamente

			return 10;

		}

		return 5; //Si no se dieron ninguno de los casos anteriores, entonces todo salio bien

	}

	else if (validar_fecha(FECHA_INGRESADA, FECHA_ACTUAL) == 2) { //Si estamos en el mismo dia

		if (validar_hora(HORA_INGRESADA, HORA_ACTUAL) == 0) { //Mandamos a llamar la funcion para validar que no se empalme

			return 2; //Ya paso la fecha

		}

		else if (validar_hora(HORA_INGRESADA, HORA_ACTUAL) == 2) { //YA PASO LA HORA DE HOY

			return 3;

		}

		else if (validar_hora(HORA_INGRESADA, HORA_ACTUAL) == 3) { //YA PASO LA HORA DE HOY

			return 3;

		}

		else if (validar_hora(HORA_INGRESADA, HORA_ACTUAL) == 5) { //Todo bien

			if (origenC == NULL) {
				return 5;
			}
			else {

				if (validar_fecha2(FECHA_INGRESADA, HORA_INGRESADA, Consultorio_ingresado) == 0) { //Alguna fecha se empalma

					return 0;

				}
				else if (validar_fecha2(FECHA_INGRESADA, HORA_INGRESADA, Consultorio_ingresado) == 4) { //No hay una diferencia de 1 hora al menos

					return 4;

				}
				else if (validar_fecha2(FECHA_INGRESADA, HORA_INGRESADA, Consultorio_ingresado) == 10) { //Todo salio correctamente

					return 10;

				}

				return 5; //Si no se dieron ninguno de los casos anteriores, entonces todo salio bien
			}
			

		}



	}

	




}

int validar_fecha2(string FECHA_INGRESADA, string HORA_INGRESADA, int Consultorio_ingresado) {

	//Despues de validar lo basico en la primera funcion de validar fecha, pasamos a comparar las demas fechas de las otras citas

	if (origenC != NULL && origenC->nextC != NULL) { //Si ya tenemos mas de 2 estructuras

		string HORA1;
		string HORA2;

		string FECHA1;
		string FECHA2;

		auxC = origenC;
		FECHA1 = auxC->Fecha;
		HORA1 = auxC->Hora;

		FECHA2 = auxC->nextC->Fecha;
		HORA2 = auxC->nextC->Hora;

		int Posicion_FECHA1 = 0;

#pragma region ORDENAMOS_LAS_ESTRUCTURAS

		auxC = origenC;

		//Contamos cuantas estructuras tenemos
		int Cant_de_estructuras = 0;

		while (auxC != NULL) {

			Cant_de_estructuras = Cant_de_estructuras + 1;

			auxC = auxC->nextC;

		}

		auxC = origenC;

		if (auxC != NULL && auxC->nextC != NULL) { //Si tenemos mas de una estrcurura
			//METODO BURBUJA


			for (int i = 0; i < Cant_de_estructuras; i++) {

				for (int j = 0; j < Cant_de_estructuras; j++) {

					if (auxC->nextC != NULL && validar_fecha_longdate(auxC->Fecha, auxC->nextC->Fecha) == 2) { //Si estamos en al misma fecha || La ultima condicion es para saber si no tienen el msimo ID


							//Pasamos ahora a comparar las horas de dichas fechas, para corroborar que no se empalman
						HORA2 = auxC->nextC->Hora;
						HORA1 = auxC->Hora;

						if (validar_hora_FORMATO_12(HORA1, HORA2) == 0) {

							if (auxC->Consultorio == auxC->nextC->Consultorio||atoi(auxC->Consultorio) == Consultorio_ingresado) { //Si estan en el mismo consultorio
								return 0; //Se empalma
							}
							else {
								return 10;
							}

						}
						else if (validar_hora_FORMATO_12(HORA1, HORA2) == 4) {

							return 4; //NO HAY UNA DIFERENCIA DE AL MENOS 1 HORA ENTRE CADA CITA

						}


					}

					auxC = auxC->nextC;
					/*
					if (aux->next != NULL) {
						aux = aux->next;
						aux = aux;

					}
					*/

				}

				auxC = origenC;


			}

		}

#pragma endregion

		return 10;

	}

	//En caso de ser apenas la segunda cita

	else if (origenC != NULL && origenC->nextC == NULL) { //Aqui vamos a comparar la hora ya registrada, con la hora

		string HORA1;
		string HORA2;

		string FECHA1;
		string FECHA2;

		//Igualamos las fechas que vamos a comparar para poderlas mandar como parametro
		FECHA2 = origenC->Fecha;
		FECHA1 = FECHA_INGRESADA;


		//ESTO es para ver si la cita del origen no es igual a la cita de la 2da estructura


		if (validar_fecha_longdate(FECHA1, FECHA2) == 2) { //Cuando retorna 2 significa que estas citas estan en el mismo dia

			//Pasamos ahora a comparar las horas de dichas fechas, para corroborar que no se empalman
			HORA2 = origenC->Hora;
			HORA1 = HORA_INGRESADA;

			if (validar_hora_FORMATO_12(HORA1, HORA2) == 0) {

				/*
				Mandamos a llamar la funcion con formato de 12 horas para converirlo a formato de 24 y comparar las horas
				Si son iguales las horas, se empalma la cita

				*/
				if (atoi(origenC->Consultorio) == Consultorio_ingresado) { //Si estan en el mismo consultorio
					return 0; //Se empalma
				}
				else {
					return 10;
				}

			}
			else if (validar_hora_FORMATO_12(HORA1, HORA2) == 4) {

				return 4; //NO HAY UNA DIFERENCIA DE AL MENOS 1 HORA ENTRE CADA CITA

			}
			else if (validar_hora_FORMATO_12(HORA1, HORA2) == 10) {

				return 10; //Todo salio bien

			}


		}

		else { //Si ninguna fecha se topa, entonces no hay citas que se empalmen

			return 10;
		}
	}

	else if (origenC == NULL) { //Si origen es igual NULL, no tenemos que comparar la fecha y hora que ninguna otra

		return 10; //Retornamos este numero, de que hemos terminado de validar

	}

}

string Dia_de_la_semana(string FECHA){

	string str_dia_semana;

	int indice = 0;
	while (FECHA[indice] != ',') {

		indice++;

	}

	str_dia_semana = FECHA.substr(0, indice); //Tomamos los caracteres de la posicion 0 a la 1

	return str_dia_semana;

}


int validar_fecha(string FECHA, string FECHA_ACTUAL) {

	//FECHA ACTUAL
	string str2_dia, str2_mes, str2_año,str2_dia_semana;
	int dia_A, mes_A, año_A;

	//FECHA INGRESADA
	string str_dia, str_mes, str_año,str_dia_semana;
	int dia, mes, año;


	int indice = 0;
	while (FECHA[indice] != ',') {

		indice++;

	}
	str_dia_semana = FECHA.substr(0, indice); //Tomamos los caracteres de la posicion 0 a la 1

	indice = indice + 2;
	int i_dia = indice;

	int cantidad_de_caracteres=0;

	while (FECHA[i_dia] != ' ') {

		i_dia++;
		cantidad_de_caracteres++;
	}

	str_dia = FECHA.substr(indice, cantidad_de_caracteres);
	dia = atoi(str_dia.c_str());

	if (cantidad_de_caracteres == 1) {
		indice = indice + 5;
	}
	else if (cantidad_de_caracteres == 2) {
		indice = indice + 6;
	}
	
	int i_mes = indice;
	cantidad_de_caracteres = 0;
	while (FECHA[i_mes] != ' ') {

		i_mes++;
		cantidad_de_caracteres++;
	}

	str_mes = FECHA.substr(indice, cantidad_de_caracteres);

	if (str_mes == "enero") {
		mes = 1;
	}
	else if (str_mes == "febrero") {
		mes = 2;
	}
	else if (str_mes == "marzo") {
		mes = 3;
	}
	else if (str_mes == "abril") {
		mes = 4;
	}
	else if (str_mes == "mayo") {
		mes = 5;
	}
	else if (str_mes == "junio") {
		mes = 6;
	}
	else if (str_mes == "julio") {
		mes = 7;
	}
	else if (str_mes == "agosto") {
		mes = 8;
	}
	else if (str_mes == "septiembre") {
		mes = 9;
	}
	else if (str_mes == "octubre") {
		mes = 10;
	}
	else if (str_mes == "noviembre") {
		mes = 11;
	}
	else if (str_mes == "diciembre") {
		mes = 12;
	}

	indice = indice + 9;
	
	str_año = FECHA.substr(indice, 4);
	año = atoi(str_año.c_str());



	
			//FECHA ACTUAL//
			//DIA

	str2_dia = FECHA_ACTUAL.substr(0, 2); //Tomamos los caracteres de la posicion 0 a la 1
	dia_A = atoi(str2_dia.c_str()); //.c_str extrae un puntero a un arreglo que contiene todos los "caracteres no nulos de la cadena"

	//MES
	str2_mes = FECHA_ACTUAL.substr(3, 2);//Tomamos los caracteres de la posicion 3 a la 4
	mes_A = atoi(str2_mes.c_str());//.c_str extrae un puntero a un arreglo que contiene todos los "caracteres no nulos de la cadena"

	//AÑO
	str2_año = FECHA_ACTUAL.substr(6);//Tomamos todos los caracteres a partir de la posicion 6
	año_A = atoi(str2_año.c_str());//.c_str extrae un puntero a un arreglo que contiene todos los "caracteres no nulos de la cadena"

			//COMPARAMOS


	if (año < año_A) {

		return 0;

	}
	else if (mes < mes_A && año == año_A) { //Si ingresa un mes menor al que estamos

		return 0;

	}
	else if (mes == mes_A && dia < dia_A) { //Esta fecha ya paso

		return 0;

	}
	else if (mes == mes_A && dia == dia_A && año == año_A) { // SI ESTAMOS EN EL MISMO DIA

		return 2; //Retornara 2, si estamos en el mismo dia

	}



	else if (mes > mes_A&& año == año_A || año > año_A) {

		return 5;

	}
	else if (mes == mes_A && dia > dia_A) {

		return 5;

	}



}

int validar_fecha_longdate(string FECHA, string FECHA_ACTUAL) {

	//FECHA ACTUAL
	string str2_dia, str2_mes, str2_año, str2_dia_semana;
	int dia_A, mes_A, año_A;

	//FECHA INGRESADA
	string str_dia, str_mes, str_año, str_dia_semana;
	int dia, mes, año;


	int indice = 0;
	while (FECHA[indice] != ',') {

		indice++;

	}
	str_dia_semana = FECHA.substr(0, indice); //Tomamos los caracteres de la posicion 0 a la 1

	indice = indice + 2;
	int i_dia = indice;

	int cantidad_de_caracteres = 0;

	while (FECHA[i_dia] != ' ') {

		i_dia++;
		cantidad_de_caracteres++;
	}

	str_dia = FECHA.substr(indice, cantidad_de_caracteres);
	dia = atoi(str_dia.c_str());

	if (cantidad_de_caracteres == 1) {
		indice = indice + 5;
	}
	else if (cantidad_de_caracteres ==2) {
		indice = indice + 6;
	}


	int i_mes = indice;
	cantidad_de_caracteres = 0;
	while (FECHA[i_mes] != ' ') {

		i_mes++;
		cantidad_de_caracteres++;
	}

	str_mes = FECHA.substr(indice, cantidad_de_caracteres);

	if (str_mes == "enero") {
		mes = 1;
	}
	else if (str_mes == "febrero") {
		mes = 2;
	}
	else if (str_mes == "marzo") {
		mes = 3;
	}
	else if (str_mes == "abril") {
		mes = 4;
	}
	else if (str_mes == "mayo") {
		mes = 5;
	}
	else if (str_mes == "junio") {
		mes = 6;
	}
	else if (str_mes == "julio") {
		mes = 7;
	}
	else if (str_mes == "agosto") {
		mes = 8;
	}
	else if (str_mes == "septiembre") {
		mes = 9;
	}
	else if (str_mes == "octubre") {
		mes = 10;
	}
	else if (str_mes == "noviembre") {
		mes = 11;
	}
	else if (str_mes == "diciembre") {
		mes = 12;
	}

	indice = indice + 9;

	str_año = FECHA.substr(indice, 4);
	año = atoi(str_año.c_str());




	//FECHA ACTUAL///////////////////////////////////////////////////
	//DIA

	int indice2 = 0;
	while (FECHA_ACTUAL[indice2] != ',') {

		indice2++;

	}
	str2_dia_semana = FECHA_ACTUAL.substr(0, indice2); //Tomamos los caracteres de la posicion 0 a la 1

	indice2 = indice2 + 2;
	int i_dia2 = indice2;

	cantidad_de_caracteres = 0;

	while (FECHA_ACTUAL[i_dia2] != ' ') {

		i_dia2++;
		cantidad_de_caracteres++;
	}

	str2_dia = FECHA_ACTUAL.substr(indice2, cantidad_de_caracteres);
	dia_A = atoi(str2_dia.c_str());


	if (cantidad_de_caracteres == 1) {
		indice2 = indice2 + 5;
	}
	else if (cantidad_de_caracteres == 2) {
		indice2 = indice2 + 6;
	}


	int i_mes2 = indice2;
	cantidad_de_caracteres = 0;
	while (FECHA_ACTUAL[i_mes2] != ' ') {

		i_mes2++;
		cantidad_de_caracteres++;
	}

	str2_mes = FECHA_ACTUAL.substr(indice2, cantidad_de_caracteres);

	if (str2_mes == "enero") {
		mes_A = 1;
	}
	else if (str2_mes == "febrero") {
		mes_A = 2;
	}
	else if (str2_mes == "marzo") {
		mes_A = 3;
	}
	else if (str2_mes == "abril") {
		mes_A = 4;
	}
	else if (str2_mes == "mayo") {
		mes_A = 5;
	}
	else if (str2_mes == "junio") {
		mes_A = 6;
	}
	else if (str2_mes == "julio") {
		mes_A = 7;
	}
	else if (str2_mes == "agosto") {
		mes_A = 8;
	}
	else if (str2_mes == "septiembre") {
		mes_A = 9;
	}
	else if (str2_mes == "octubre") {
		mes_A = 10;
	}
	else if (str2_mes == "noviembre") {
		mes_A = 11;
	}
	else if (str2_mes == "diciembre") {
		mes_A = 12;
	}

	indice2 = indice2 + 9;

	str2_año = FECHA_ACTUAL.substr(indice2, 4);
	año_A = atoi(str2_año.c_str());




	////////////////////////////////////////////////////////////////

			//COMPARAMOS


	if (año < año_A) {

		return 0;

	}
	else if (mes < mes_A && año == año_A) { //Si ingresa un mes menor al que estamos

		return 0;

	}
	else if (mes == mes_A && dia < dia_A) { //Esta fecha ya paso

		return 0;

	}
	else if (mes == mes_A && dia == dia_A && año == año_A) { // SI ESTAMOS EN EL MISMO DIA

		return 2; //Retornara 2, si estamos en el mismo dia

	}



	else if (mes > mes_A&& año == año_A || año > año_A) {

		return 5;

	}
	else if (mes == mes_A && dia > dia_A) {

		return 5;

	}


}

int validar_hora(string Hora, string Hora_ACTUAL) {

	char pm[6] = "p. m.";
	char am[6] = "a. m.";


	//HORA INGRESADA
	string str_hora, str_minutos, str_segundos, str_AMoPM;
	int hora, minutos, segundos;

	//HORA ACTUAL
	string str2_hora, str2_minutos, str2_segundos;
	int hora_A, minutos_A, segundos_A;



	//HORA INGRESADA//
	//HORA
	str_hora = Hora.substr(0, 2); //Tomamos los caracteres de la posicion 0 a la 1
	hora = atoi(str_hora.c_str()); //.c_str extrae un puntero a un arreglo que contiene todos los "caracteres no nulos de la cadena"

	//MINUTOS
	str_minutos = Hora.substr(3, 2);//Tomamos los caracteres de la posicion 3 a la 4
	minutos = atoi(str_minutos.c_str());//.c_str extrae un puntero a un arreglo que contiene todos los "caracteres no nulos de la cadena"

	// AM O PM???
	str_AMoPM = Hora.substr(9, 12);

	//Aqui haremos la hora en formato de 24 horas
	if (strcmp(str_AMoPM.c_str(), pm) == 0) {

		hora = hora + 12;

	}
	else if (strcmp(str_AMoPM.c_str(), am) == 0) {

		if (hora == 12) {

			hora = 0;

		}

	}

	//HORA ACTUAL//
	//HORA
	str2_hora = Hora_ACTUAL.substr(0, 2); //Tomamos los caracteres de la posicion 0 a la 1
	hora_A = atoi(str2_hora.c_str()); //.c_str extrae un puntero a un arreglo que contiene todos los "caracteres no nulos de la cadena"

	//MINUTOS
	str2_minutos = Hora_ACTUAL.substr(3, 4);//Tomamos los caracteres de la posicion 3 a la 4
	minutos_A = atoi(str2_minutos.c_str());//.c_str extrae un puntero a un arreglo que contiene todos los "caracteres no nulos de la cadena"


	if (hora == hora_A && minutos == minutos_A) { //Si se empalma la misma hora

		return 0;

	}
	else if (hora < hora_A) { //Esta hora de hoy ya paso

		return 2;

	}
	else if (hora == hora_A && minutos < minutos_A) { //Esta hora de hoy ya paso

		return 3;

	}

	///Casos en los que no pasa nada

	else if (hora == hora_A && minutos > minutos_A) { //Esta hora de hoy ya paso

		return 5; //Si retorna 5 no pasa nada

	}
	else if (hora > hora_A) { //Esta hora de hoy ya paso

		return 5; //Si retorna 5 no pasa nada

	}




}

int validar_hora_FORMATO_12(string Hora_1, string Hora_2) {

	char pm[6] = "p. m.";
	char am[6] = "a. m.";


	//HORA INGRESADA
	string str_hora, str_minutos, str_segundos, str_AMoPM;
	int hora, minutos, segundos;

	//HORA ACTUAL
	string str2_hora, str2_minutos, str2_segundos, str2_AMoPM;
	int hora_A, minutos_A, segundos_A;

	//HORA INGRESADA//
	//HORA
	str_hora = Hora_1.substr(0, 2); //Tomamos los caracteres de la posicion 0 a la 1
	hora = atoi(str_hora.c_str()); //.c_str extrae un puntero a un arreglo que contiene todos los "caracteres no nulos de la cadena"

	//MINUTOS
	str_minutos = Hora_1.substr(2, 2);//Tomamos los caracteres de la posicion 3 a la 4
	minutos = atoi(str_minutos.c_str());//.c_str extrae un puntero a un arreglo que contiene todos los "caracteres no nulos de la cadena"

	// AM O PM???
	str_AMoPM = Hora_1.substr(5, 4);

	//Aqui haremos la hora en formato de 24 horas
	if (strcmp(str_AMoPM.c_str(), pm) == 0) {

		hora = hora + 12;

	}
	else if (strcmp(str_AMoPM.c_str(), am) == 0) {

		if (hora == 12) {

			hora = 0;

		}

	}


	//HORA 2//
	//HORA
	str2_hora = Hora_2.substr(0, 2); //Tomamos los caracteres de la posicion 0 a la 1
	hora_A = atoi(str2_hora.c_str()); //.c_str extrae un puntero a un arreglo que contiene todos los "caracteres no nulos de la cadena"

	//MINUTOS
	str2_minutos = Hora_2.substr(2, 2);//Tomamos los caracteres de la posicion 3 a la 4
	minutos_A = atoi(str2_minutos.c_str());//.c_str extrae un puntero a un arreglo que contiene todos los "caracteres no nulos de la cadena"

	str2_AMoPM = Hora_2.substr(5, 4);

	//Aqui haremos la hora en formato de 24 horas
	if (strcmp(str2_AMoPM.c_str(), pm) == 0) {

		hora_A = hora_A + 12;
	}
	else if (strcmp(str2_AMoPM.c_str(), am) == 0) {

		if (hora == 12) {

			hora_A = 0;

		}

	}


	if (hora == hora_A && minutos == minutos_A) { //Si se empalma la misma hora

		return 0; //Si se empalma

	}
	else {

		int minutos_dia;
		int minutos_dia2;

		minutos_dia = (hora * 60) + minutos;
		minutos_dia2 = (hora_A * 60) + minutos_A;

		if (minutos_dia > minutos_dia2&& minutos_dia < minutos_dia2 + 20 || minutos_dia < minutos_dia2 && minutos_dia >minutos_dia2 - 20) {

			/*
			En este IF vemos si hay una diferencia de 1 hora entre cada cita, si no hay diferencia de al menos una hora retornamos 4
			*/

			return 4;
		}
		else {

			return 10;

		}



	}
	
	if (hora > hora_A) {
		return 5;
	}




}

int Validar_CITAS(HWND vent) {

	int contador_validaciones = 0; //Para saber que todo esta validado
	bool validar_espacios; //Identificador
	char cValidaciondeDATOS[50];

	validar_espacios = ValidacionLongitud(vent, 4); //Validamos el que no haya espacios vacios

	if (validar_espacios == false) { //Si no esta todo relleno
		return 0;
	}

	HWND hEditBoxEspecialidad = GetDlgItem(vent, IDC_Especialidad);
	HWND hEditBoxDoctor = GetDlgItem(vent, IDC_Doctor);
	HWND hEditBoxPaciente = GetDlgItem(vent, IDC_COMBO_Paciente);
	HWND hEditBoxCelular = GetDlgItem(vent, IDC_Celular);
	HWND hEditBoxConsultorio = GetDlgItem(vent, IDC_Consultorio);
	HWND hEditBoxDia = GetDlgItem(vent, IDC_Dia);

	//HWND hEditBoxHora = GetDlgItem(vent, IDC_Hora);
	HWND hEditBoxHora = GetDlgItem(vent, IDC_Hora);

	int longitud_Especialidad = GetWindowTextLength(hEditBoxEspecialidad); //Sacamos la longitud
	int longitud_Doctor = GetWindowTextLength(hEditBoxDoctor); //Sacamos la longitud
	int longitud_Paciente = GetWindowTextLength(hEditBoxPaciente); //Sacamos la longitud
	int longitud_Celular = GetWindowTextLength(hEditBoxCelular); //Sacamos la longitud
	int longitud_Consultorio = GetWindowTextLength(hEditBoxConsultorio); //Sacamos la longitud
	int longitud_Dia = GetWindowTextLength(hEditBoxDia); //Sacamos la longitud
	int longitud_Hora = GetWindowTextLength(hEditBoxHora); //Sacamos la longitud

	 //Validamos si las casillas tienen datos
	if (validar_espacios == false) {
		return 0;
	}

#pragma region VALIDACION DE FECHA Y HORA

	char ch_Validacion_Fecha[50] = "";
	char ch_Validacion_HORA[30] = "";
	char ch_Consultorio[5] = "";



	string str_FECHA_Ingresada;
	string str_FECHA_ACTUAL;
	string str_HORA_Ingresada;
	string str_HORA_ACTUAL;

	//Pasamos el texto de las casillas a las variables char
	GetWindowText(hEditBoxDia, ch_Validacion_Fecha, longitud_Dia + 1);
	GetWindowText(hEditBoxHora, ch_Validacion_HORA, longitud_Hora + 1);

	//Tomamos el consultorio ingresado
	GetWindowText(hEditBoxConsultorio, ch_Consultorio, longitud_Consultorio + 1);
	int Consultorio = atoi(ch_Consultorio);

	//Pasamos lo de las variables char a las variables string para poder usarlas en las siguientes funciones
	str_FECHA_Ingresada = ch_Validacion_Fecha; 
	str_HORA_Ingresada = ch_Validacion_HORA; 

	if (validar_espacios == false) {
		return 0;
	}

	else {

#pragma region Validaciones

		//Especialidad
		GetWindowText(hEditBoxEspecialidad, cValidaciondeDATOS, longitud_Especialidad + 1);
		if (validar_nombreESPECIALIDAD(cValidaciondeDATOS) == 0) {

			MessageBox(vent, "PorFavor ingrese un nombre de Especialidad Valido", "ERROR", MB_OK);
			return -1;
		}
		else {

			contador_validaciones = contador_validaciones + 1;

		}

		GetWindowText(hEditBoxDoctor, cValidaciondeDATOS, longitud_Doctor + 1);
		if (validar_nombre(cValidaciondeDATOS) == 0) {

			MessageBox(vent, "PorFavor ingrese un nombre", "ERROR", MB_OK);
			return -1;
		}
		else {

			contador_validaciones = contador_validaciones + 1;

		}

		GetWindowText(hEditBoxCelular, cValidaciondeDATOS, longitud_Celular + 1);
		if (validar_numeroTEL(cValidaciondeDATOS) == 0) {

			MessageBox(vent, "PorFavor ingrese un numero de 8 a 10 digitos", "ERROR", MB_OK);
			return -1;
		}
		else {

			contador_validaciones = contador_validaciones + 1;

		}

		GetWindowText(hEditBoxConsultorio, cValidaciondeDATOS, longitud_Consultorio + 1);
		if (atoi(cValidaciondeDATOS)>3 || atoi(cValidaciondeDATOS) < 1 || !isdigit(cValidaciondeDATOS[0])) {
			MessageBox(vent, "PorFavor ingrese un Consultorio 1, 2 o 3", "ERROR", MB_OK);
			return -1;
		}
		else {

			contador_validaciones = contador_validaciones + 1;

		}

		GetWindowText(hEditBoxPaciente, cValidaciondeDATOS, longitud_Dia + 1);
		if (validar_Paciente(cValidaciondeDATOS)==0) {
			MessageBox(vent, "PorFavor ingrese un Paciente Registrado", "ERROR", MB_OK);
			return -1;
		}
		else {

			contador_validaciones = contador_validaciones + 1;

		}

		GetWindowText(hEditBoxHora, cValidaciondeDATOS, longitud_Hora + 1);
		if (validar_HORARIO(cValidaciondeDATOS) == 0) {
			MessageBox(vent, "PorFavor ingrese uno de los horarios disponibles", "ERROR", MB_OK);
			return -1;
		}
		else {

			contador_validaciones = contador_validaciones + 1;

		}

#pragma endregion

		// FECHA_ACTUAL y HORA_ACTUAL son variables globales
		str_FECHA_ACTUAL = FECHA_ACTUAL; //Igualamos el arreglo char a un string para poderlo mandar como parametro
		str_HORA_ACTUAL = HORA_ACTUAL;

		//Si la FECHA YA PASO 

		if (validar_fecha_y_hora(FECHA_ACTUAL, HORA_ACTUAL, str_FECHA_Ingresada, str_HORA_Ingresada, Consultorio) == 10) { //Todo salio bien

			//Si llegamos a este punto las fechas y horas estan completamente validadas
			contador_validaciones = contador_validaciones + 1;
			

		}
		else if (validar_fecha_y_hora(FECHA_ACTUAL, HORA_ACTUAL, str_FECHA_Ingresada, str_HORA_Ingresada, Consultorio) == 5) { //Todo bien

			contador_validaciones = contador_validaciones + 1;

		}
		else if (validar_fecha_y_hora(FECHA_ACTUAL, HORA_ACTUAL, str_FECHA_Ingresada, str_HORA_Ingresada, Consultorio) == 4) { //Se necesita una hora de diferencia

			MessageBox(vent, "Tiene una cita en esta misma fecha, pero cambie la hora, se necesita 1 hora de diferencia por cita", "ERROR", MB_OK);
			return -1;

		}
		else if (validar_fecha_y_hora(FECHA_ACTUAL, HORA_ACTUAL, str_FECHA_Ingresada, str_HORA_Ingresada, Consultorio) == 0) { //Esta cita se empalma con otra

			MessageBox(vent, "Esta cita se empalma con otra", "ERROR", MB_OK);
			return -1;

		}
		else if (validar_fecha_y_hora(FECHA_ACTUAL, HORA_ACTUAL, str_FECHA_Ingresada, str_HORA_Ingresada, Consultorio) == 1) { //Esta fecha ya paso

			MessageBox(vent, "Esta fecha ya pasó", "ERROR", MB_OK);
			return -1;

		}

		else if (validar_fecha_y_hora(FECHA_ACTUAL, HORA_ACTUAL, str_FECHA_Ingresada, str_HORA_Ingresada, Consultorio) == 2) { //Esta ingresando el dia de hoy y la misma hora

			MessageBox(vent, "Esta ingresando el dia de hoy y la hora actual, haga una cita para mas tarde", "ERROR", MB_OK);
			return -1;

		}

		else if (validar_fecha_y_hora(FECHA_ACTUAL, HORA_ACTUAL, str_FECHA_Ingresada, str_HORA_Ingresada, Consultorio) == 3) { //Esta hora del dia de hoy ya paso

			MessageBox(vent, "Esta hora del dia de HOY ya pasó", "ERROR", MB_OK);
			return -1;

		}



	}



#pragma endregion


	if (contador_validaciones == 7) { //Si todo esta validado correctamente, ahora si pasamos la informacion a la estructura

				//Esta clase se utiliza para guardar la informacion temporalmente
		Citas* Clase_temporal_C = new Citas;

		//Volvemos a buscar la ultima estructura, ya que alteramos la posicion de aux durante las validaciones
		GetWindowText(hEditBoxEspecialidad, Clase_temporal_C->Especialidad, longitud_Especialidad + 1);
		GetWindowText(hEditBoxDoctor, Clase_temporal_C->Doctor, longitud_Doctor + 1);
		GetWindowText(hEditBoxPaciente, Clase_temporal_C->Paciente, longitud_Paciente + 1);
		GetWindowText(hEditBoxCelular, Clase_temporal_C->Celular, longitud_Celular + 1);
		GetWindowText(hEditBoxConsultorio, Clase_temporal_C->Consultorio, longitud_Consultorio + 1);
		GetWindowText(hEditBoxDia, Clase_temporal_C->Fecha, longitud_Dia + 1);
		GetWindowText(hEditBoxHora, Clase_temporal_C->Hora, longitud_Hora + 1);

		//Registrando
		ListasLigadas* Registro = NULL;
		Registro->AgregarCita(Clase_temporal_C->Fecha, Clase_temporal_C->Hora, Clase_temporal_C->Doctor
			, Clase_temporal_C->Especialidad, Clase_temporal_C->Paciente, Clase_temporal_C->Celular,
			Clase_temporal_C->Consultorio);

		//Eliminamos la clase temporal
		delete Clase_temporal_C;


		return 1; //Regresamos 1 de que hemos terminado de registrar

	}

     
#pragma endregion

}

int Validar_MEDICOS(HWND vent,int caso) {

	bool validar_espacios; //Identificador
	int contador_validaciones = 0; //Para saber que todo esta validado
	char cValidaciondeDATOS[50];

	validar_espacios = ValidacionLongitud(vent, 2); //Validamos el que no haya espacios vacios

	if (validar_espacios == false) { //Si no esta todo relleno
		return 0;
	}

	HWND hEditBoxCedula = GetDlgItem(vent, IDC_Cedula);
	HWND hEditBoxNombreDoc = GetDlgItem(vent, IDC_EDIT2);
	HWND hEditBoxAPELLIDOS = GetDlgItem(vent, IDC_APELLIDOS);
	HWND hEditBoxNumero_consultorio = GetDlgItem(vent, IDC_Consultorio);
	HWND hEditBoxNumero_celular = GetDlgItem(vent, IDC_NumCel);
	HWND hEditBoxEspecialidad = GetDlgItem(vent, IDC_Especialidad);

	HWND hEditBoxLunes = GetDlgItem(vent, IDC_E1);
	HWND hEditBoxMartes = GetDlgItem(vent, IDC_E2);
	HWND hEditBoxMiercoles = GetDlgItem(vent, IDC_E3);
	HWND hEditBoxJueves = GetDlgItem(vent, IDC_E4);
	HWND hEditBoxViernes = GetDlgItem(vent, IDC_E5);


	int longitud_Cedula = GetWindowTextLength(hEditBoxCedula); //Sacamos la longitud
	int longitud_Doctor = GetWindowTextLength(hEditBoxNombreDoc); //Sacamos la longitud
	int longitud_APELLIDOS = GetWindowTextLength(hEditBoxAPELLIDOS);
	int longitud_Consultorio = GetWindowTextLength(hEditBoxNumero_consultorio); //Sacamos la longitud
	int longitud_Celular = GetWindowTextLength(hEditBoxNumero_celular); //Sacamos la longitud
	int longitud_Especialidad = GetWindowTextLength(hEditBoxEspecialidad); //Sacamos la longitud

	int Longitud_LUNES = GetWindowTextLength(hEditBoxLunes); //Sacamos la longitud
	int Longitud_MARTES = GetWindowTextLength(hEditBoxMartes); //Sacamos la longitud
	int Longitud_MIERCOLES = GetWindowTextLength(hEditBoxMiercoles); //Sacamos la longitud
	int Longitud_JUEVES = GetWindowTextLength(hEditBoxJueves); //Sacamos la longitud
	int Longitud_VIERNES = GetWindowTextLength(hEditBoxViernes); //Sacamos la longitud

	 //Validamos si las casillas tienen datos
	if (validar_espacios == false) {
		MessageBox(vent, "Porfavor Rellene los campos Vacios", "ERROR", MB_OK);
		return -1;
	}

	if (caso == 1) { //En este caso tenemos que validar la cedula

		GetWindowText(hEditBoxCedula, cValidaciondeDATOS, longitud_Cedula + 1);
		if (validar_CEDULA(cValidaciondeDATOS) == 0) {

			MessageBox(vent, "PorFavor ingrese una Cedula de 7,8 o 10 digitos", "ERROR", MB_OK);
			return -1;
		}
		else if (validar_CEDULA(cValidaciondeDATOS) == 2)
		{

			MessageBox(vent, "Esta cedula ya existe", "ERROR", MB_OK);
			return -1;
		}
		else {

			contador_validaciones = contador_validaciones + 1;

		}
	}
	
	if (caso == 1) {
		GetWindowText(hEditBoxEspecialidad, cValidaciondeDATOS, longitud_Especialidad + 1);
		if (validar_nombreESPECIALIDAD(cValidaciondeDATOS) == 0) {

			MessageBox(vent, "PorFavor ingrese una especialidad", "ERROR", MB_OK);
			return -1;
		}
		else {

			contador_validaciones = contador_validaciones + 1;

		}
	}
	

	GetWindowText(hEditBoxNombreDoc, cValidaciondeDATOS, longitud_Doctor + 1);
	if (validar_nombre(cValidaciondeDATOS) == 0) {

		MessageBox(vent, "PorFavor ingrese un nombre correcto", "ERROR", MB_OK);
		return -1;
	}
	else {

		contador_validaciones = contador_validaciones + 1;

	}

	GetWindowText(hEditBoxAPELLIDOS, cValidaciondeDATOS, longitud_APELLIDOS + 1);
	if (validar_nombre(cValidaciondeDATOS) == 0) {

		MessageBox(vent, "PorFavor ingrese un Apellido correcto", "ERROR", MB_OK);
		return -1;
	}
	else {

		contador_validaciones = contador_validaciones + 1;

	}

	if (caso == 1) {
		GetWindowText(hEditBoxNumero_celular, cValidaciondeDATOS, longitud_Celular + 1);
		if (validar_numeroTEL(cValidaciondeDATOS) == 0) {

			MessageBox(vent, "PorFavor ingrese un numero de 8 a 10 digitos", "ERROR", MB_OK);
			return -1;
		}
		else if (validar_numeroTEL(cValidaciondeDATOS) == 2)
		{
			MessageBox(vent, "Este numero de celular ya esta registrado", "ERROR", MB_OK);
			return -1;
		}
		else {

			contador_validaciones = contador_validaciones + 1;

		}
	}
	

	GetWindowText(hEditBoxNumero_consultorio, cValidaciondeDATOS, longitud_Consultorio + 1);
	if (atoi(cValidaciondeDATOS) > 3 || atoi(cValidaciondeDATOS) < 1 || !isdigit(cValidaciondeDATOS[0])) {
		MessageBox(vent, "PorFavor ingrese un Consultorio 1, 2 o 3", "ERROR", MB_OK);
		return -1;
	}
	else {

		contador_validaciones = contador_validaciones + 1;

	}


	GetWindowText(hEditBoxLunes, cValidaciondeDATOS, Longitud_LUNES + 1);
	if (validar_HORARIO(cValidaciondeDATOS) == 0) {
		MessageBox(vent, "PorFavor ingrese uno de los horarios disponibles", "ERROR", MB_OK);
		return -1;
	}
	else {

		contador_validaciones = contador_validaciones + 1;

	}

	GetWindowText(hEditBoxMartes, cValidaciondeDATOS, Longitud_MARTES + 1);
	if (validar_HORARIO(cValidaciondeDATOS) == 0) {
		MessageBox(vent, "PorFavor ingrese uno de los horarios disponibles", "ERROR", MB_OK);
		return -1;
	}
	else {

		contador_validaciones = contador_validaciones + 1;

	}

	GetWindowText(hEditBoxMiercoles, cValidaciondeDATOS, Longitud_MIERCOLES + 1);
	if (validar_HORARIO(cValidaciondeDATOS) == 0) {
		MessageBox(vent, "PorFavor ingrese uno de los horarios disponibles", "ERROR", MB_OK);
		return -1;
	}
	else {

		contador_validaciones = contador_validaciones + 1;

	}

	GetWindowText(hEditBoxJueves, cValidaciondeDATOS, Longitud_JUEVES + 1);
	if (validar_HORARIO(cValidaciondeDATOS) == 0) {
		MessageBox(vent, "PorFavor ingrese uno de los horarios disponibles", "ERROR", MB_OK);
		return -1;
	}
	else {

		contador_validaciones = contador_validaciones + 1;

	}

	GetWindowText(hEditBoxViernes, cValidaciondeDATOS, Longitud_VIERNES + 1);
	if (validar_HORARIO(cValidaciondeDATOS) == 0) {
		MessageBox(vent, "PorFavor ingrese uno de los horarios disponibles", "ERROR", MB_OK);
		return -1;
	}
	else {

		contador_validaciones = contador_validaciones + 1;

	}



	if (caso == 1 && contador_validaciones == 11 || caso == 2 && contador_validaciones == 8) { //Si todo esta validado correctamente, ahora si pasamos la informacion a la estructura

		//Esta clase se utiliza para guardar la informacion temporalmente
		Doctor* Clase_temporal_D = new Doctor();

		GetWindowText(hEditBoxCedula, Clase_temporal_D->Cedula, longitud_Cedula + 1);
		GetWindowText(hEditBoxNombreDoc, Clase_temporal_D->Nombre, longitud_Doctor + 1);
		GetWindowText(hEditBoxAPELLIDOS, Clase_temporal_D->Apellidos, longitud_APELLIDOS + 1);
		GetWindowText(hEditBoxEspecialidad, Clase_temporal_D->Especialidad, longitud_Especialidad + 1);
		GetWindowText(hEditBoxNumero_consultorio, Clase_temporal_D->Consultorio, longitud_Consultorio + 1);

		strcpy(Clase_temporal_D->DirFileDoc, chDireccionDOC);

		GetWindowText(hEditBoxLunes, Clase_temporal_D->Lunes, Longitud_LUNES + 1);
		GetWindowText(hEditBoxMartes, Clase_temporal_D->Martes, Longitud_MARTES + 1);
		GetWindowText(hEditBoxMiercoles, Clase_temporal_D->Miercoles, Longitud_MIERCOLES + 1);
		GetWindowText(hEditBoxJueves, Clase_temporal_D->Jueves, Longitud_JUEVES + 1);
		GetWindowText(hEditBoxViernes, Clase_temporal_D->Viernes, Longitud_VIERNES + 1);
		GetWindowText(hEditBoxNumero_celular, Clase_temporal_D->Celular, longitud_Celular + 1);

		//Aqui vemos que dias atiende, y concatenamos la informacion en una variable
		char Dias_en_que_se_atiende[50] = "";

		//Comparamos las cadenas
		if (strcmp(Clase_temporal_D->Lunes, "LIBRE") != 0) { strcat_s(Dias_en_que_se_atiende, "LUNES"); }
		if (strcmp(Clase_temporal_D->Martes, "LIBRE") != 0) { strcat_s(Dias_en_que_se_atiende, ",MARTES"); }
		if (strcmp(Clase_temporal_D->Miercoles, "LIBRE") != 0) { strcat_s(Dias_en_que_se_atiende, ",MIERCOLES"); }
		if (strcmp(Clase_temporal_D->Jueves, "LIBRE") != 0) { strcat_s(Dias_en_que_se_atiende, ",JUEVES"); }
		if (strcmp(Clase_temporal_D->Viernes, "LIBRE") != 0) { strcat_s(Dias_en_que_se_atiende, ",VIERNES"); }
		strcpy_s(Clase_temporal_D->Dias_atencion, Dias_en_que_se_atiende); //Copiamos la cadena


		//Registrando el nuevo doctor
		if (caso == 1)
		{
			arbol->AgregarDoctor(Clase_temporal_D);
		}
		if (caso == 2)
		{
			arbol->ModificarNodo(Clase_temporal_D,Clase_temporal_D->Cedula);
		}
		
		
		//Eliminamos los punteros
		delete Clase_temporal_D;

		return 1; //Regresamos 1 de que hemos terminado de registrar

	

	}

}


void Poner_en_lista_horario(HWND Box_hora ,int caso) {

	switch (caso) {

		//Primeras horas
		case 1: {

			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c1);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c2);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c3);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c4);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c5);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c6);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c7);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c8);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c9);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c10);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c11);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c12);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c13);
		}
			  break;

		case 2: {

			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c13);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c14);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c15);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c16);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c17);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c18);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c19);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c20);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c21);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c22);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c23);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c24);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c25);
		}
			  break;

		case 3: {

			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c25);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c26);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c27);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c28);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c29);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c30);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c31);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c32);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c33);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c34);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c35);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c36);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c37);
		}
			break;

		case 4: {

			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c37);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c38);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c39);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c40);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c41);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c42);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c43);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c44);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c45);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c46);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c47);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c48);
			SendMessage(Box_hora, CB_INSERTSTRING, 0, (LPARAM)H_C.c49);

		}
			  break;


		case 5: {

			while (SendMessage(Box_hora, CB_GETCOUNT, NULL, NULL) != NULL) {

				SendMessage(Box_hora, CB_DELETESTRING, NULL, NULL);

			}
			
		}
	}



}

void Imprimir_Horarios(HWND vent) {

	HWND Box_hora = GetDlgItem(vent, IDC_Hora);

	while (SendMessage(Box_hora, CB_GETCOUNT, NULL, NULL) != NULL) {

		SendMessage(Box_hora, CB_DELETESTRING, NULL, NULL);

	}

	HWND CB_Doctor = GetDlgItem(vent, IDC_Doctor);
	char* temporal_doctor = new char[15];
	int cursel = SendMessage(CB_Doctor, CB_GETCURSEL, NULL, NULL); //Vemos la posicion de donde clickó en la lista
	SendMessage(CB_Doctor, CB_GETLBTEXT, cursel, (LPARAM)temporal_doctor);

	if (strcmp(temporal_doctor, "") == 1) { //Si la cadena no esta vacia

		Doctor* arr = arbol->Arreglo_del_arbol();//En un arreglo ponemos a los doctores
		int indice;

		HWND hComboDoctor = GetDlgItem(vent, IDC_Doctor);

		for (indice = 0; indice < Doctor::cantidad_de_doctores; indice++) {

			if (strcmp(arr[indice].Nombre, temporal_doctor) == 0) {

				HWND hFECHA;
				HWND Actualizar_horarios;
				Actualizar_horarios = GetDlgItem(vent, IDC_actualizar);
				hFECHA = GetDlgItem(vent, IDC_Dia);

				char ch_Fecha[40] = "";
				string DIA;
				string Horario;

				int longitud_Dia = GetWindowTextLength(hFECHA); //Sacamos la longitud


				GetWindowText(hFECHA, ch_Fecha, longitud_Dia + 1);


				DIA = Dia_de_la_semana(ch_Fecha);

#pragma region Verificar el DIA

				//Si el dia escogido, el doctor tiene libre
				if (DIA == "lunes" && arr[indice].Lunes == "LIBRE" || DIA == "martes" && arr[indice].Martes == "LIBRE"
					|| DIA == "miércoles" && arr[indice].Miercoles == "LIBRE" || DIA == "jueves" && arr[indice].Jueves == "LIBRE"
					|| DIA == "viernes" && arr[indice].Viernes == "LIBRE") {

					EnableWindow(Box_hora, false);
					EnableWindow(Actualizar_horarios, false);

				}
				//Si el dia escogido el doctor no tiene libre
				else if (DIA == "lunes" && arr[indice].Lunes != "LIBRE" || DIA == "martes" && arr[indice].Martes != "LIBRE"
					|| DIA == "miércoles" && arr[indice].Miercoles != "LIBRE" || DIA == "jueves" && arr[indice].Jueves != "LIBRE"
					|| DIA == "viernes" && arr[indice].Viernes != "LIBRE") {

						EnableWindow(Box_hora, true);
						EnableWindow(Actualizar_horarios, true);


						if (DIA == "lunes") {

							if (strcmp(arr[indice].Lunes,H.h1) ==0) {

								Poner_en_lista_horario(Box_hora, 1);

							}
							else if (strcmp(arr[indice].Lunes,H.h2)==0) {

								Poner_en_lista_horario(Box_hora, 2);

							}
							else if (strcmp(arr[indice].Lunes, H.h3)==0) {

									Poner_en_lista_horario(Box_hora, 3);

							}
							else if (strcmp(arr[indice].Lunes,H.h4)==0) {

								Poner_en_lista_horario(Box_hora, 4);

							}
							else if ((strcmp(arr[indice].Lunes, "LIBRE") == 0)) {

								Poner_en_lista_horario(Box_hora, 5);

							}

						}

						else if (DIA == "martes") {

								if ((strcmp(arr[indice].Martes, H.h1) == 0)) {

									Poner_en_lista_horario(Box_hora, 1);

								}
								else if ((strcmp(arr[indice].Martes, H.h2) == 0)) {

									Poner_en_lista_horario(Box_hora, 2);

								}
								else if ((strcmp(arr[indice].Martes, H.h3) == 0)) {

									Poner_en_lista_horario(Box_hora, 3);

								}
								else if ((strcmp(arr[indice].Martes, H.h4) == 0)) {

									Poner_en_lista_horario(Box_hora, 4);

								}
								else if ((strcmp(arr[indice].Martes, "LIBRE") == 0)) {

									Poner_en_lista_horario(Box_hora, 5);

								}
						}

						else if (DIA == "miércoles") {

							if ((strcmp(arr[indice].Miercoles, H.h1) == 0)) {

								Poner_en_lista_horario(Box_hora, 1);

							}
							else if ((strcmp(arr[indice].Miercoles, H.h2) == 0)) {

								Poner_en_lista_horario(Box_hora, 2);

							}
							else if ((strcmp(arr[indice].Miercoles, H.h3) == 0)) {

								Poner_en_lista_horario(Box_hora, 3);

							}
							else if ((strcmp(arr[indice].Miercoles, H.h4) == 0)) {

								Poner_en_lista_horario(Box_hora, 4);

							}
							else if ((strcmp(arr[indice].Miercoles, "LIBRE") == 0)) {

								Poner_en_lista_horario(Box_hora, 5);
								return;

							}

						}

						else if (DIA == "jueves") {

							if ((strcmp(arr[indice].Jueves, H.h1) == 0)) {

								Poner_en_lista_horario(Box_hora, 1);

							}
							else if ((strcmp(arr[indice].Jueves, H.h2) == 0)) {

								Poner_en_lista_horario(Box_hora, 2);

							}
							else if ((strcmp(arr[indice].Jueves, H.h3) == 0)) {

								Poner_en_lista_horario(Box_hora, 3);

							}
							else if ((strcmp(arr[indice].Jueves, H.h4) == 0)) {

								Poner_en_lista_horario(Box_hora, 4);

							}
							else if ((strcmp(arr[indice].Jueves, "LIBRE") == 0)) {

								Poner_en_lista_horario(Box_hora, 5);

							}

						}

						else if (DIA == "viernes") {

							if ((strcmp(arr[indice].Viernes, H.h1) == 0)) {

								Poner_en_lista_horario(Box_hora, 1);

							}
							else if ((strcmp(arr[indice].Viernes, H.h2) == 0)) {

								Poner_en_lista_horario(Box_hora, 2);

							}
							else if ((strcmp(arr[indice].Viernes, H.h3) == 0)) {

								Poner_en_lista_horario(Box_hora, 3);

							}
							else if ((strcmp(arr[indice].Viernes, H.h4) == 0)) {

								Poner_en_lista_horario(Box_hora, 4);

							}
							else if ((strcmp(arr[indice].Viernes, "LIBRE") == 0)) {

								Poner_en_lista_horario(Box_hora, 5);

							}

						}


				     }

			}

		}

	}

}

void imprirmir_foto_doctor(HWND vent) {

	HWND CB_Doctor = GetDlgItem(vent, IDC_Doctor);
	char* temporal_doctor = new char[15];
	int cursel = SendMessage(CB_Doctor, CB_GETCURSEL, NULL, NULL); //Vemos la posicion de donde clickó en la lista
	SendMessage(CB_Doctor, CB_GETLBTEXT, cursel, (LPARAM)temporal_doctor);

	Doctor* arr = arbol->Arreglo_del_arbol();//En un arreglo ponemos a los doctores
	int indice;

	if (strcmp(temporal_doctor, "") == 1) { //Si la cadena no esta vacia

		for (indice = 0; indice < Doctor::cantidad_de_doctores; indice++) {

			if (strcmp(arr[indice].Nombre, temporal_doctor) == 0) {

				HBITMAP fotoDOC = (HBITMAP)LoadImage(NULL, arr[indice].DirFileDoc, IMAGE_BITMAP, 80, 80, LR_LOADFROMFILE);
				HWND ID_DOC = GetDlgItem(vent, IDC_Foto_doc);
				SendMessage(ID_DOC, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)fotoDOC);

				//IMPRIMIR DIAS DE ATENCION
				HWND Dias_en_que_atiende = GetDlgItem(vent, IDC_ATENCION);
				SetWindowText(Dias_en_que_atiende, arr[indice].Dias_atencion);

				return;
			}

		}

	}

}

void Imprimir_consultorio_doctor(HWND vent) {

	HWND CB_Doctor = GetDlgItem(vent, IDC_Doctor);
	char* temporal_doctor = new char[15];
	int cursel = SendMessage(CB_Doctor, CB_GETCURSEL, NULL, NULL); //Vemos la posicion de donde clickó en la lista
	SendMessage(CB_Doctor, CB_GETLBTEXT, cursel, (LPARAM)temporal_doctor);

	Doctor* arr = arbol->Arreglo_del_arbol();//En un arreglo ponemos a los doctores
	int indice;

	if (strcmp(temporal_doctor, "") == 1) { //Si la cadena no esta vacia

		for (indice = 0; indice < Doctor::cantidad_de_doctores; indice++) {

			if (strcmp(arr[indice].Nombre, temporal_doctor) == 0) {

				HWND hComboConsultorio;
				hComboConsultorio = GetDlgItem(vent, IDC_Consultorio);
				SendMessage(hComboConsultorio, CB_ADDSTRING, 0, (LPARAM)arr[indice].Consultorio);
				
				return;
			}

		}

	}


}

void Guardar_informacion(HWND vent) {

	Guardar_info_pacientes(vent,origen);
	Guardar_info_especialidades(vent, origen_esp);
	Guardar_CITAS(vent, origenC);

	MessageBox(vent, "La información se ha guardado exitosamente", "Guardado Exitoso", MB_OK);

}

void Guardar_info_pacientes(HWND Ventana,Paciente *origen) {

		//Y una vez organizado el arreglo "pacientes"

		ofstream Pacientes("Informacion_pacientes.bin", ios::in |ios::trunc |ios::binary | ios::ate); //Abrimos el objeto Datos

		if (Pacientes.fail())
		{          //Si el objeto no se crea 
			MessageBox(Ventana, "No se pudo crear el reporte", "ERROR", MB_OK);
		}

		Paciente* t = origen;

		while (t != NULL) {

			Pacientes.write(reinterpret_cast <char*>(t), sizeof(Paciente));
			t = t->next;
		}

		Pacientes.close();

		return;
}

void Guardar_info_especialidades(HWND Ventana, Especialidad* origen) {

	ofstream Especialidades("Informacion_especialidades.bin", ios::in | ios::trunc | ios::binary | ios::ate); //Abrimos el objeto Datos

	if (Especialidades.fail())
	{          //Si el objeto no se crea 
		MessageBox(Ventana, "No se pudo crear el archivo", "ERROR", MB_OK);
	}

	Especialidad* t = origen_esp;

	while (t != NULL) {

		Especialidades.write(reinterpret_cast <char*>(t), sizeof(Especialidad));
		t = t->next_esp;
	}

	Especialidades.close();
	return;

}

void Guardar_CITAS(HWND Ventana, Citas* origen) {

	ofstream CITAS("Informacion_CITAS.bin", ios::in | ios::trunc | ios::binary | ios::ate); //Abrimos el objeto Datos

	if (CITAS.fail())
	{          //Si el objeto no se crea 
		MessageBox(Ventana, "No se pudo crear el archivo", "ERROR", MB_OK);
	}

	Citas* t = origenC;

	while (t != NULL) {

		CITAS.write(reinterpret_cast <char*>(t), sizeof(Citas));
		t = t->nextC;
	}

	CITAS.close();
	return;

}

//////////////

void Cargar_informacion(HWND vent) {

	cargarPacientes(vent);
	cargarEspecialidades(vent);
	cargarCITAS(vent);
}

void cargarPacientes(HWND vent) {

	ifstream miArchivo;

	miArchivo.open("Informacion_pacientes.bin", ios::in | ios::binary | ios::ate);
	/*
	  La propiedad ate nos situa al ultimo caracter escrito
	*/

	if (!miArchivo.is_open()) {
		MessageBox(NULL, "ERROR", "Usted no sirve para esto", MB_OK);
		return;
	}

	int size = miArchivo.tellg(); //Esto nos dira la cantidad de elementos en el archivo

	if (size == 0) { /*Como nos pusimos al final si este nos devuelve 0 entonces no hay info*/
		MessageBox(NULL, "Vacio", "No hay datos guardados", MB_OK);
		return;
	}

	for (int i = 0; i < (size / sizeof(Paciente)); i++) {


		if (origen == NULL) {
			origen = new Paciente;
			aux = origen;
			aux->prev = NULL;
		}
		else {
			while (aux->next != NULL)
				aux = aux->next;
			aux->next = new Paciente;
			aux->next->prev = aux;
			aux = aux->next;
		}

		/*Flujo de lectura*/
		Paciente* T = new Paciente; //Agenda Temporal


		miArchivo.seekg(i * sizeof(Paciente));

		miArchivo.read(reinterpret_cast<char*>(T), sizeof(Paciente));


		strcpy(aux->Nombre, T->Nombre);
		strcpy(aux->Apellidos, T->Apellidos);
		strcpy(aux->Edad, T->Edad);
		strcpy(aux->FechaNacimiento, T->FechaNacimiento);
		strcpy(aux->Genero, T->Genero);

		aux->ID = T->ID;
		/*aux->next= T->next;
		aux->prev = T->prev;*/

		strcpy(aux->Primermedico_que_lo_atendio, T->Primermedico_que_lo_atendio);

		strcpy(aux->Referencia, T->Referencia);
		strcpy(aux->Telefono, T->Telefono);

		/*Extraemos la informacion del temporal*/

		delete reinterpret_cast<char*>(T);
		/*
		  La unica manera de borrar esta interpretacion de datos es decirle al delete
		  que realmente borre una interpretacion de datos.
		*/

		aux->next = NULL;
		aux = origen;
	}
	miArchivo.close();
	MessageBox(vent, "Exito", "Cargado exitoso", MB_OK);
}

void cargarEspecialidades(HWND vent) {

	ifstream miArchivo;

	miArchivo.open("Informacion_Especialidades.bin", ios::in | ios::binary | ios::ate);
	/*
	  La propiedad ate nos situa al ultimo caracter escrito
	*/

	if (!miArchivo.is_open()) {
		MessageBox(NULL, "ERROR", "No se ha podido abrir el archivo de Especialidades", MB_OK);
		return;
	}

	int size = miArchivo.tellg(); //Esto nos dira la cantidad de elementos en el archivo

	if (size == 0) { /*Como nos pusimos al final si este nos devuelve 0 entonces no hay info*/
		MessageBox(NULL, "Vacio", "No hay datos guardados", MB_OK);
		return;
	}

	for (int i = 0; i < (size / sizeof(Especialidad)); i++) {


		if (origen_esp == NULL) {
			origen_esp = new Especialidad;
			aux_esp = origen_esp;
			aux_esp->prev_esp = NULL;
		}
		else {
			while (aux_esp->next_esp != NULL)
				aux_esp = aux_esp->next_esp;
			aux_esp->next_esp = new Especialidad;
			aux_esp->next_esp->prev_esp = aux_esp;
			aux_esp = aux_esp->next_esp;
		}

		/*Flujo de lectura*/
		Especialidad* T = new Especialidad; //Agenda Temporal


		miArchivo.seekg(i * sizeof(Especialidad));

		miArchivo.read(reinterpret_cast<char*>(T), sizeof(Especialidad));


		strcpy(aux_esp->especialidad, T->especialidad);
		strcpy(aux_esp->Descripcion, T->Descripcion);

		/*Extraemos la informacion del temporal*/

		delete reinterpret_cast<char*>(T);
		/*
		  La unica manera de borrar esta interpretacion de datos es decirle al delete
		  que realmente borre una interpretacion de datos.
		*/

		aux_esp->next_esp = NULL;
		aux_esp = origen_esp;
	}
	miArchivo.close();

}

void cargarCITAS(HWND vent) {

	ifstream miArchivo;

	miArchivo.open("Informacion_CITAS.bin", ios::in | ios::binary | ios::ate);
	/*
	  La propiedad ate nos situa al ultimo caracter escrito
	*/

	if (!miArchivo.is_open()) {
		MessageBox(NULL, "ERROR", "No se ha podido abrir el archivo de CITAS", MB_OK);
		return;
	}

	int size = miArchivo.tellg(); //Esto nos dira la cantidad de elementos en el archivo

	if (size == 0) { /*Como nos pusimos al final si este nos devuelve 0 entonces no hay info*/
		MessageBox(NULL, "Vacio", "No hay datos guardados en CITAS", MB_OK);
		return;
	}

	for (int i = 0; i < (size / sizeof(Citas)); i++) {


		if (origenC == NULL) {
			origenC = new Citas;
			auxC = origenC;
			auxC->prevC = NULL;
		}
		else {
			while (auxC->nextC != NULL)
				auxC = auxC->nextC;
			auxC->nextC = new Citas;
			auxC->nextC->prevC = auxC;
			auxC = auxC->nextC;
		}

		/*Flujo de lectura*/
		Citas* T = new Citas; //Agenda Temporal


		miArchivo.seekg(i * sizeof(Citas));

		miArchivo.read(reinterpret_cast<char*>(T), sizeof(Citas));


		strcpy(auxC->Celular, T->Celular);
		strcpy(auxC->Consultorio, T->Consultorio);
		strcpy(auxC->Doctor, T->Doctor);
		strcpy(auxC->Especialidad, T->Especialidad);
		strcpy(auxC->Fecha, T->Fecha);
		strcpy(auxC->Hora, T->Hora);
		auxC->ID_c =T->ID_c;
		
		auxC->Estado_de_cita = T->Estado_de_cita;
		strcpy(auxC->Paciente, T->Paciente);
		
		

		/*Extraemos la informacion del temporal*/

		delete reinterpret_cast<char*>(T);
		/*
		  La unica manera de borrar esta interpretacion de datos es decirle al delete
		  que realmente borre una interpretacion de datos.
		*/

		auxC->nextC = NULL;
		auxC = origenC;
	}
	miArchivo.close();
}


bool REGISTRAR_PACIENTES(HWND vent,int caso) {

#pragma region COSAS EN EL CASO DE QUE SE VAYA A MODIFICAR LOS DATOS DE UN PACIENTE

	int ID = 0; //Esta variable po defecto es 0 si no vamos a modificar el nombre del paciente

	if (caso == 2) { //Si vamos a editar la informacion del paciente

		HWND LB_Lista = GetDlgItem(vent, IDC_lista_nombres);
		char* nombre_seleccionado = new char[15];
		int cursel = SendMessage(LB_Lista, LB_GETCURSEL, NULL, NULL); //Vemos la posicion de donde clickó en la lista
		SendMessage(LB_Lista, LB_GETTEXT, cursel, (LPARAM)nombre_seleccionado);

		aux = origen;
		while (aux != NULL) {

			char nombre_registrado[60] = "";
			strcat(nombre_registrado, aux->Nombre); strcat(nombre_registrado, " ");
			strcat(nombre_registrado, aux->Apellidos);

			if (strcmp(nombre_seleccionado, nombre_registrado) == 0) {
			
				ID = aux->ID;
				break;
			}

			aux = aux->next;

		}
	}

#pragma endregion

	bool validar_espacios; //Identificador
	int contador_validaciones = 0; //Para saber que todo esta validado
	char cValidaciondeDATOS[50];

	validar_espacios = ValidacionLongitud(vent, 1); //Validamos el que no haya espacios vacios

	if (validar_espacios == false) { //Si no esta todo relleno
		return false;
	}

	//VALIDANDO
#pragma region Validando
//Identificadores
	HWND hEditBoxNOMBRE = GetDlgItem(vent, IDC_PACIENTE);
	HWND hEditBoxAPELLIDOS = GetDlgItem(vent, IDC_APPELIDOS);
	HWND hEditBoxGENERO = GetDlgItem(vent, IDC_GENERO);
	HWND hEditBoxTELEFONO = GetDlgItem(vent, IDC_TELEFONO);
	HWND hEditBoxREFERENCIA = GetDlgItem(vent, IDC_REFERENCIA);
	HWND hEditBoxNACIMIENTO = GetDlgItem(vent, IDC_FECHA_NACIMIENTO);
	HWND hEditBoxEDAD = GetDlgItem(vent, IDC_EDAD);
	HWND hEditBoxPRIMER_MEDICO = GetDlgItem(vent, IDC_1er_medico);

	//Longitud
	int longitud_Nom = GetWindowTextLength(hEditBoxNOMBRE); //Sacamos la longitud
	int longitud_Apellidos = GetWindowTextLength(hEditBoxAPELLIDOS);
	int longitud_Gen = GetWindowTextLength(hEditBoxGENERO); //Sacamos la longitud
	int longitud_Tel = GetWindowTextLength(hEditBoxTELEFONO); //Sacamos la longitud
	int longitud_Ref = GetWindowTextLength(hEditBoxREFERENCIA); //Sacamos la longitud
	int longitud_Nac = GetWindowTextLength(hEditBoxNACIMIENTO); //Sacamos la longitud
	int longitud_EDAD = GetWindowTextLength(hEditBoxEDAD); //Sacamos la longitud
	int longitud_1er_med = GetWindowTextLength(hEditBoxPRIMER_MEDICO); //Sacamos la longitud

#pragma region VALIDANDO

 //Validamos si las casillas tienen datos
	if (validar_espacios == false) {
		MessageBox(hVentanaREGISTROpacientes, "Porfavor Rellene los campos Vacios", "ERROR", MB_OK);
		return false;
	}

	GetWindowText(hEditBoxNOMBRE, cValidaciondeDATOS, longitud_Nom + 1);
	if (validar_nombre(cValidaciondeDATOS) == 0) {

		MessageBox(vent, "PorFavor ingrese un nombre", "ERROR", MB_OK);
		return false;
	}
	else {

		contador_validaciones = contador_validaciones + 1;

	}

	//Especialidad
	GetWindowText(hEditBoxAPELLIDOS, cValidaciondeDATOS, longitud_Apellidos + 1);
	if (validar_nombre(cValidaciondeDATOS) == 0) {

		MessageBox(vent, "PorFavor ingrese un apellido Valido", "ERROR", MB_OK);
		return -1;
	}
	else {

		contador_validaciones = contador_validaciones + 1;

	}

	GetWindowText(hEditBoxGENERO, cValidaciondeDATOS, longitud_Gen + 1);
	if (strcmp(cValidaciondeDATOS, "Masculino") != 0 && strcmp(cValidaciondeDATOS, "Femenino") !=0) {

		MessageBox(vent, "PorFavor ingrese Masculino o Femenino", "ERROR", MB_OK);
		return -1;
	}
	else {

		contador_validaciones = contador_validaciones + 1;

	}

	GetWindowText(hEditBoxTELEFONO, cValidaciondeDATOS, longitud_Tel + 1);
	if (validar_numeroTEL(cValidaciondeDATOS) == 0) {

		MessageBox(vent, "PorFavor ingrese un numero de 8 a 10 digitos", "ERROR", MB_OK);
		return -1;
	}
	else {

		contador_validaciones = contador_validaciones + 1;

	}

	GetWindowText(hEditBoxPRIMER_MEDICO, cValidaciondeDATOS, longitud_1er_med + 1);
	if (validar_Doctor_seleccionado(cValidaciondeDATOS) == 0) {

		MessageBox(vent, "PorFavor ingrese un doctor que este disponible", "ERROR", MB_OK);
		return -1;
	}
	else {

		contador_validaciones = contador_validaciones + 1;

	}



#pragma endregion

	if (contador_validaciones == 5) { //Si todo esta validado correctamente, ahora si pasamos la informacion a la estructura

		//Esta clase se utiliza para guardar la informacion temporalmente
		Paciente* Clase_temporal = new Paciente;

		//Volvemos a buscar la ultima estructura, ya que alteramos la posicion de aux durante las validaciones
		GetWindowText(hEditBoxNOMBRE, Clase_temporal->Nombre, longitud_Nom + 1);
		GetWindowText(hEditBoxAPELLIDOS, Clase_temporal->Apellidos, longitud_Apellidos + 1);
		GetWindowText(hEditBoxGENERO, Clase_temporal->Genero, longitud_Gen + 1);
		GetWindowText(hEditBoxTELEFONO, Clase_temporal->Telefono, longitud_Tel + 1);
		GetWindowText(hEditBoxREFERENCIA, Clase_temporal->Referencia, longitud_Ref + 1);
		GetWindowText(hEditBoxNACIMIENTO, Clase_temporal->FechaNacimiento, longitud_Nac + 1);
		GetWindowText(hEditBoxEDAD, Clase_temporal->Edad, longitud_EDAD + 1);
		GetWindowText(hEditBoxPRIMER_MEDICO, Clase_temporal->Primermedico_que_lo_atendio, longitud_1er_med + 1);


		ListasLigadas* Registro_Pacientes = NULL;
		Registro_Pacientes->AgregarPaciente(Clase_temporal->Nombre, Clase_temporal->Apellidos,
			Clase_temporal->Genero, Clase_temporal->Edad,
			Clase_temporal->FechaNacimiento, Clase_temporal->Telefono,
			Clase_temporal->Referencia, Clase_temporal->Primermedico_que_lo_atendio,caso,ID);



		//Eliminamos la clase temporal
		delete Clase_temporal;

		return true;
		

	}
}