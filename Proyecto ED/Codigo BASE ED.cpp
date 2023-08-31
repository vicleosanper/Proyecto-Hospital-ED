#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream> //Para guardar los datos
#include "resource.h"
#include <cctype>
#include <string.h>
#include <string>
#include <time.h>

#pragma warning(disable:4996)


//IMAGEN DEL DOCTOR
HBITMAP hBitmap;
HWND himagen;
char chDireccionDOC[MAX_PATH] = " "; //VARIABLES PARA VALIDAR
bool fotoagregada;

bool hay_informacion_de_doctores = false;

//TIME
#define TM_RELOJ 3000
time_t tiempo = time(NULL);//variables donde guardo el valor de la funcion time.
struct tm* tlocal; //estructura donde obtengo el tiempo
char FECHA_ACTUAL[15]; //ARREGLO PARA TENER LA FECHA DE MANERA GLOBAL
char HORA_ACTUAL[15];

//CAMBIAR NOMBRE HANDLERS

//Reporte de los pacientes Heap Sort
//Reporte de los doctores Quick Sort

using namespace std;

//IDENTIFICADORES DE VENTANAS
HWND hVentanaIniciodeSesion;
HWND hVentanaPRINCIPAL;
HWND hVentanaREGISTROpacientes;
HWND hVentanaREGISTROcitas;
HWND hVentanaREGISTROdemedicos;
HWND hVentanaREGISTROespecialidades;
HWND hVentanaBUSCARpacientes;

HWND hVentanaCONSULTAcitas_MEDICOS_mes;
HWND hVentanaCONSULTAcitas_semana;
HWND hVentanaCONSULTAcitas_especialidad_semana;

HWND hVentanaConsulta_CITAS;
HWND hVentanaConsulta_CITAS_Doctor_mes;

HWND hVentanaBUSCARmedicos;

//VARIABLES
int NUMEROCITA = 1;
int Numero_pacientes;

HINSTANCE hGlobalInstance;//Instancia global para crear dialogos

//ESTRUCTURAS y CLASES
struct Horarios {

	char h1[25] = "8:00 a. m. - 12:00 p. m.";
	char h2[25] = "12:00 p. m. - 4:00 p. m.";
	char h3[25] = "4:00 p. m. - 8:00 p. m.";
	char h4[25] = "8:00 p. m. - 12:00 a. m.";

}H;

struct Horarios_cita {

#pragma region HORAS

	char c1[30] = "8:00 a. m.";
	char c2[30] = "8:20 a. m.";
	char c3[30] = "8:40 a. m.";
	char c4[30] = "9:00 a. m.";
	char c5[30] = "9:20 a. m.";
	char c6[30] = "9:40 a. m.";
	char c7[30] = "10:00 a. m.";
	char c8[30] = "10:20 a. m.";
	char c9[30] = "10:40 a. m.";
	char c10[30] = "11:00 a. m.";
	char c11[30] = "11:20 a. m.";
	char c12[30] = "11:40 a. m.";
	char c13[30] = "12:00 p. m.";
	char c14[30] = "12:20 p. m.";
	char c15[30] = "12:40 p. m.";
	char c16[30] = "01:00 p. m.";
	char c17[30] = "01:20 p. m.";
	char c18[30] = "01:40 p. m.";
	char c19[30] = "02:00 p. m.";
	char c20[30] = "02:20 p. m.";
	char c21[30] = "02:40 p. m.";
	char c22[30] = "03:00 p. m.";
	char c23[30] = "03:20 p. m.";
	char c24[30] = "03:40 p. m.";
	char c25[30] = "04:00 p. m.";
	char c26[30] = "04:20 p. m.";
	char c27[30] = "04:40 p. m.";
	char c28[30] = "05:00 p. m.";
	char c29[30] = "05:20 p. m.";
	char c30[30] = "05:40 p. m.";
	char c31[30] = "06:00 p. m.";
	char c32[30] = "06:20 p. m.";
	char c33[30] = "06:40 p. m.";
	char c34[30] = "07:00 p. m.";
	char c35[30] = "07:20 p. m.";
	char c36[30] = "07:40 p. m.";
	char c37[30] = "08:00 p. m.";
	char c38[30] = "08:20 p. m.";
	char c39[30] = "08:40 p. m.";
	char c40[30] = "09:00 p. m.";
	char c41[30] = "09:20 p. m.";
	char c42[30] = "09:40 p. m.";
	char c43[30] = "10:00 p. m.";
	char c44[30] = "10:20 p. m.";
	char c45[30] = "10:40 p. m.";
	char c46[30] = "11:00 p. m.";
	char c47[30] = "11:20 p. m.";
	char c48[30] = "11:40 p. m.";
	char c49[30] = "12:00 a. m.";

#pragma endregion

}H_C;

class Paciente {

	public:
	int ID;
	char Nombre[40];
	char Apellidos[40];
	char Genero[15];
	char Edad[10];
	char FechaNacimiento[20];
	char Telefono[12];
	char Referencia[30];
	char Primermedico_que_lo_atendio[30];
    
	Paciente* prev;
	Paciente* next;

	Paciente() {};

	Paciente(char Nombre[],char Apellidos[], char Genero[], char Edad[], char FechaNacimiento[], char Telefono[], char Referencia[], char Primermedico_que_lo_atendio[]) {

		prev = NULL; next = NULL;

		strcpy_s(this->Nombre,Nombre);
		strcpy_s(this->Apellidos, Apellidos);
		strcpy_s(this->Genero, Genero);
		strcpy_s(this->Edad, Edad);
		strcpy_s(this->FechaNacimiento, FechaNacimiento);
		strcpy_s(this->Telefono, Telefono);
		strcpy_s(this->Genero, Genero);
		strcpy_s(this->Referencia, Referencia);
		strcpy_s(this->Primermedico_que_lo_atendio, Primermedico_que_lo_atendio);

		if (aux != NULL) { //El aux estara situado en el ultimo nodo creado, o si es el primero valdra NULO
			this->ID = aux->ID + 1; //Al ID del Nodo anterior le sumamos 1
		}
		

	}

	~Paciente() {};

	friend class ListasLigadas;
	friend class ArbolH_paciente;

}*origen, *aux;

class Citas {

	public:

	int ID_c;
	char Fecha[50];
	char Hora[30];
	char Doctor[25];
	char Especialidad[25];
	char Paciente[25];
	char Celular[15];
	char Consultorio[10];
	int Estado_de_cita;
	char Motivo_cancelacion[60];

	Citas* nextC, * prevC;

	Citas() {};
	Citas(char Fecha[], char Hora[], char Doctor[], char Especialidad[], char Paciente[], char Celular[], char Consultorio[]) {
	
		prevC = NULL; nextC = NULL;

		strcpy_s(this->Fecha, Fecha);
		strcpy_s(this->Hora,Hora);
		strcpy_s(this->Doctor, Doctor);
		strcpy_s(this->Especialidad, Especialidad);
		strcpy_s(this->Paciente, Paciente);
		strcpy_s(this->Consultorio, Consultorio);
		strcpy_s(this->Celular, Celular);

		this->Estado_de_cita = 0; //La cita no esta cancelada en un inicio
		
	
		if (auxC != NULL) { //El aux estara situado en el ultimo nodo creado, o si es el primero valdra NULO
			this->ID_c = auxC->ID_c + 1; //Al ID del Nodo anterior le sumamos 1
		}
	
	};

	friend class ListasLigadas;

	~Citas() {};
	

}*origenC,*auxC;

#include "Arbol de Doctores.h"

#include "Listas Ligadas.h"

#include"Funciones de arbol heap (Pacientes).h"

//Funciones
char LongitudClave[30];
char LongitudUsuario[30];
char LongitudContraseña[30];
char ClaveUsuario[30];
char Usuario[50];
char Contraseña[30];

//Funciones para el arbol heap y quicksort
void Heapsort(Paciente* arr, int tamaño);
void heapify(Paciente* arr, int n, int i);
void swap(Paciente* arr_raiz, Paciente* arr);

void quickSort(Doctor* arr, int left, int right);
void swap_Doctores(Doctor* Destino, Doctor* nodo);
void Poner_en_lista_horario(HWND Box_hora, int caso);
void Imprimir_Horarios(HWND vent);
void imprirmir_foto_doctor(HWND vent);
void Guardar_info_pacientes(HWND Ventana,Paciente*);

//Cargar informacion
void Cargar_informacion(HWND vent);
void cargarPacientes(HWND vent);
void cargarEspecialidades(HWND vent);
void cargarCITAS(HWND vent);

bool REGISTRAR_PACIENTES(HWND vent,int caso);
bool Consultaporsemana(HWND vent, string Mes, char* Semana[]);
bool ConsultaporMES(HWND vent, string Mes,char* Cedula[]);
bool ConsultaporsemanayESPECIALIDAD(HWND vent, string Mes, char* Semana[],char* ESPECIALIDAD[]);

bool Comparacion_de_fechas(string FECHA_CITA, int MES_INGRESADO, int SEMANA_INGRESADA);
bool Comparacion_de_MES(string FECHA_CITA, int MES_INGRESADO);

int validar_fecha_longdate(string FECHA, string FECHA_ACTUAL);
void Guardar_info_especialidades(HWND Ventana, Especialidad* origen);
void Guardar_informacion(HWND vent);
void Guardar_CITAS(HWND Ventana, Citas* origen);


//VALIDACIONES
void ELIMINAR_LISTAS_LIGADAS();
int validar_nombre(char nombre[]);
bool ValidacionLongitud(HWND hWnd,int caso);
bool Reporte_Pacientes(HWND Ventana);
bool Reporte_doctores(HWND Ventana,Doctor*arr);
int Busqueda_BINARIA(HWND vent, char* ID_CITA[]);

int validar_fecha_y_hora(string FECHA_ACTUAL, string HORA_ACTUAL, string FECHA_INGRESADA, string HORA_INGRESADA, int Consultorio_ingresado);
int validar_fecha(string FECHAS, string FECHA_ACTUAL);
int validar_fecha2(string FECHA_INGRESADA, string HORA_INGRESADA, int Consultorio_ingresado);
int validar_hora(string Hora, string Hora_ACTUAL);
int validar_hora_FORMATO_12(string Hora_1, string Hora_2);
int validar_nombreESPECIALIDAD(char nombre[]);
int validar_numeroTEL(char numero[]);
int validar_Paciente(char Paciente[]);
int validar_HORARIO(char Horario[]);
int Validar_MEDICOS(HWND vent, int caso);
int validar_CEDULA(char Cedula[]);
int Busqueda_BINARIA_CONSULTA_MES(HWND vent, int cedula, Doctor* arr);

void Imprimir_consultorio_doctor(HWND vent);

int Validar_CITAS(HWND vent);


//IDENTIFICADORES PARA BOTONES EN VENTANA DE MEDICOS
#pragma region IDENTIFICADORES/Resgitro de Medicos

HWND hbtnENTRADA1 = GetDlgItem(hVentanaREGISTROdemedicos, IDC_E1);
HWND hbtnENTRADA2 = GetDlgItem(hVentanaREGISTROdemedicos, IDC_E2);
HWND hbtnENTRADA3 = GetDlgItem(hVentanaREGISTROdemedicos, IDC_E3);
HWND hbtnENTRADA4 = GetDlgItem(hVentanaREGISTROdemedicos, IDC_E4);
HWND hbtnENTRADA5 = GetDlgItem(hVentanaREGISTROdemedicos, IDC_E5);
HWND hbtnSALIDA1 = GetDlgItem(hVentanaREGISTROdemedicos, IDC_SALIDA1);
HWND hbtnSALIDA2 = GetDlgItem(hVentanaREGISTROdemedicos, IDC_SALIDA2);
HWND hbtnSALIDA3 = GetDlgItem(hVentanaREGISTROdemedicos, IDC_SALIDA3);
HWND hbtnSALIDA4 = GetDlgItem(hVentanaREGISTROdemedicos, IDC_SALIDA4);
HWND hbtnSALIDA5 = GetDlgItem(hVentanaREGISTROdemedicos, IDC_SALIDA5);
#pragma endregion

int INICIOSESION(char Clave[], char LogUsuario[], char LogContraseña[]);

BOOL CALLBACK FuncionVentanaIniciodeSesion(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK FuncionVentanaPRINCIPAL(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK FuncionVentanaREGISTROpacientes(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK FuncionVentanaREGISTROcitas(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK FuncionVentanaREGISTROdemedicos(HWND, UINT, WPARAM,LPARAM);
BOOL CALLBACK FuncionVentanaREGISTROespecialidades(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK FuncionVentanaBUSCARpacientes(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK FuncionVentanaConsultaporsemana(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK FuncionVentanaConsultaCITAS(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK FuncionVentanaConsultaCITASDOCTORmes(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK FuncionVentanaConsultaCITASespecialidadSEMANA(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK FuncionVentanaBUSCARmedicos(HWND, UINT, WPARAM, LPARAM);

//Funcion Principal
int WINAPI WinMain(HINSTANCE Hinst, HINSTANCE HinstPrev, PSTR cmdLine, int cmdShow) {

	
	hVentanaIniciodeSesion = CreateDialog(Hinst, MAKEINTRESOURCE(IDD_INICIO), NULL, FuncionVentanaIniciodeSesion);

	MSG msg; //MENSAJE
	ZeroMemory(&msg, sizeof(MSG));
	ShowWindow(hVentanaIniciodeSesion, SW_SHOW);


	while (GetMessage(&msg, 0, 0, 0)) {

		TranslateMessage(&msg); //Traduce el mensaje
		DispatchMessage(&msg); //Envia el mensaje traducido el procedimiento de ventana de la ventana desde la que procede el mensaje

	}

	return (int)msg.wParam;
	//return 0;

}

BOOL CALLBACK FuncionVentanaIniciodeSesion(HWND vent, UINT mensaje, WPARAM wParam, LPARAM lParam) {

	switch (mensaje) {

		case WM_INITDIALOG: {

			if (hay_informacion_de_doctores == true) {

				Doctor::cantidad_de_doctores = Doctor::cantidad_de_doctores +1;

				//Doctor* arr = arbol->Arreglo_del_arbol();//En un arreglo ponemos a los doctores
				//int indice = 0;

				//while (atoi(arr[indice].Cedula)!= NULL) {

				//	Doctor::cantidad_de_doctores++;
				//	indice++;

				//}

			}
		}

	case WM_COMMAND: {

		if (LOWORD(wParam) == ID_Ingresar && HIWORD(wParam) == BN_CLICKED) { //Cuando se pulse el boton de INGRESAR

			int longitud;

			HWND hClave = GetDlgItem(vent, IDC_CLAVE);
			longitud = GetWindowTextLength(hClave); //Sacamos la longitud
			GetWindowText(hClave, LongitudClave, longitud + 1); //Lo guardamos en LongitudUsuario lo que se ingreso

			HWND hUsuario = GetDlgItem(vent, IDD_lbNombre);
			longitud = GetWindowTextLength(hUsuario); //Sacamos la longitud
			GetWindowText(hUsuario, LongitudUsuario, longitud + 1); //Lo guardamos en LongitudUsuario lo que se ingreso

			HWND hContraseña = GetDlgItem(vent, IDD_Contra);
			longitud = GetWindowTextLength(hUsuario); //Sacamos la longitud
			GetWindowText(hContraseña, LongitudContraseña, longitud + 1); //Lo guardamos en LongitudUsuario lo que se ingreso


			if (INICIOSESION(LongitudClave,LongitudUsuario, LongitudContraseña) == 1) {

				
				hVentanaPRINCIPAL = CreateDialog(hGlobalInstance, MAKEINTRESOURCE(IDD_VentanaPrincipal), NULL, FuncionVentanaPRINCIPAL);
				ShowWindow(hVentanaPRINCIPAL, SW_SHOW); //Enseñamos la ventana
				//DestroyWindow(vent);
			
			}
			else if (INICIOSESION(LongitudClave,LongitudUsuario, LongitudContraseña) == 0) {

				MessageBox(vent, "ERROR", "El nombre o la contraseña es incorrecto", MB_OK);

			}

		}
		else if (LOWORD(wParam) == IDD_SALIR && HIWORD(wParam) == BN_CLICKED) { //Cuando se pulse el boton de INGRESAR

			DestroyWindow(vent);

		}

	} //FIN DEL WM_COMMAND

	case WM_CLOSE:
		break;

	case WM_DESTROY:
		PostQuitMessage(120);
		break;

	default:
		break;


	}

	return FALSE;

}

BOOL CALLBACK FuncionVentanaPRINCIPAL(HWND vent, UINT mensaje, WPARAM wParam, LPARAM lParam) {

	switch (mensaje)
	{

		case WM_INITDIALOG: {
			
			Cargar_informacion(vent);
			
			char direccion[MAX_PATH] = "";
			char LOGO[MAX_PATH] = "";

			GetCurrentDirectory(MAX_PATH, direccion);

			strcat(LOGO, direccion);
			strcat(LOGO, "\\IMAGENES BITMAP\\LOGO.bmp");

			HBITMAP foto1 = (HBITMAP)LoadImage(NULL, LOGO, IMAGE_BITMAP, 150, 150, LR_LOADFROMFILE);
			HWND ID1 = GetDlgItem(vent, IDC_IMAGEN);
			SendMessage(ID1, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)foto1);
		}

		case WM_COMMAND: {

			if (LOWORD(wParam) == IDM_SALIR && HIWORD(wParam) == BN_CLICKED) { //SALIR

					Guardar_informacion(vent);
					delete arbol;

					ELIMINAR_LISTAS_LIGADAS();


				DestroyWindow(vent);
			}

			else if (LOWORD(wParam) == IDReg_PACIENTE && HIWORD(wParam) == BN_CLICKED) {

				if (hVentanaREGISTROpacientes == NULL) {

					hVentanaREGISTROpacientes = CreateDialog(hGlobalInstance, MAKEINTRESOURCE(IDD_REGISTROPAC), NULL, FuncionVentanaREGISTROpacientes);
					ShowWindow(vent, SW_HIDE);
					ShowWindow(hVentanaREGISTROpacientes, SW_SHOW);//Enseñamos la ventana

				}

				else {

					ShowWindow(vent, SW_HIDE);
					ShowWindow(hVentanaREGISTROpacientes, SW_SHOW);//Enseñamos la ventana

				}
				

			}

			else if (LOWORD(wParam) == ID_REGISTROS_REGISTRODECITAS && HIWORD(wParam) == BN_CLICKED) {


				if (arbol->raiz == NULL || origen == NULL ) { //Si no hay doctores o Pacientes

					MessageBox(vent, "No ha registrado doctores o pacientes", "Atencion", MB_OK);

				}

				else if (hVentanaREGISTROcitas==NULL) {

					hVentanaREGISTROcitas = CreateDialog(hGlobalInstance, MAKEINTRESOURCE(IDD_REGISTROCITAS), NULL, FuncionVentanaREGISTROcitas);
					ShowWindow(vent, SW_HIDE);
					ShowWindow(hVentanaREGISTROcitas, SW_SHOW);//Enseñamos la ventana
				}
				else {
					ShowWindow(vent, SW_HIDE);
					ShowWindow(hVentanaREGISTROcitas, SW_SHOW);//Enseñamos la ventana
				}
				

			}

			else if (LOWORD(wParam) == ID_REGISTROS_REGISTRODEMEDICOS && HIWORD(wParam) == BN_CLICKED) {

				if (hVentanaREGISTROdemedicos == NULL) {

					hVentanaREGISTROdemedicos = CreateDialog(hGlobalInstance, MAKEINTRESOURCE(IDD_REGISTROmed), NULL, FuncionVentanaREGISTROdemedicos);
					ShowWindow(vent, SW_HIDE);
					ShowWindow(hVentanaREGISTROdemedicos, SW_SHOW);//Enseñamos la ventana

				}
				else {

					ShowWindow(vent, SW_HIDE);
					ShowWindow(hVentanaREGISTROdemedicos, SW_SHOW);//Enseñamos la ventana

				}
				

			}

			else if (LOWORD(wParam) == ID_REGISTROS_REGISTROSDEESPECIALIDADES && HIWORD(wParam) == BN_CLICKED) {

				if (hVentanaREGISTROespecialidades == NULL) {

					hVentanaREGISTROespecialidades = CreateDialog(hGlobalInstance, MAKEINTRESOURCE(IDD_REGISTROesp), NULL, FuncionVentanaREGISTROespecialidades);

					ShowWindow(vent, SW_HIDE);
					ShowWindow(hVentanaREGISTROespecialidades, SW_SHOW);//Enseñamos la ventana

				}

				else {

					ShowWindow(vent, SW_HIDE);
					ShowWindow(hVentanaREGISTROespecialidades, SW_SHOW);//Enseñamos la ventana

				}
				

			}

			else if (LOWORD(wParam) == ID_CONSULTASporsemana && HIWORD(wParam) == BN_CLICKED) {


				if (hVentanaCONSULTAcitas_semana  == NULL) {

					hVentanaCONSULTAcitas_semana = CreateDialog(hGlobalInstance, MAKEINTRESOURCE(IDD_Consulta_porsemana), NULL, FuncionVentanaConsultaporsemana);

					ShowWindow(vent, SW_HIDE);
					ShowWindow(hVentanaCONSULTAcitas_semana, SW_SHOW);//Enseñamos la ventana

				}

				else {

					ShowWindow(vent, SW_HIDE);
					ShowWindow(hVentanaCONSULTAcitas_semana, SW_SHOW);//Enseñamos la ventana

				}
				

			}

			else if (LOWORD(wParam) == ID_CONSULTASDECITAS_medicomes && HIWORD(wParam) == BN_CLICKED) {
                  
				if (hVentanaCONSULTAcitas_MEDICOS_mes == NULL) {

					hVentanaCONSULTAcitas_MEDICOS_mes = CreateDialog(hGlobalInstance, MAKEINTRESOURCE(IDD_CONSULTA_MedicoMes), NULL, FuncionVentanaConsultaCITASDOCTORmes);

					ShowWindow(vent, SW_HIDE);
					ShowWindow(hVentanaCONSULTAcitas_MEDICOS_mes, SW_SHOW);//Enseñamos la ventana

				}

				else {

					ShowWindow(vent, SW_HIDE);
					ShowWindow(hVentanaCONSULTAcitas_MEDICOS_mes, SW_SHOW);//Enseñamos la ventana

				}
			

			}

			else if (LOWORD(wParam) == ID_CONSULTASDECITAS_PORESPECIALIDADsemana && HIWORD(wParam) == BN_CLICKED) {

				if (hVentanaCONSULTAcitas_especialidad_semana == NULL) {

					hVentanaCONSULTAcitas_especialidad_semana = CreateDialog(hGlobalInstance, MAKEINTRESOURCE(IDD_Consulta_semana_especialidad), NULL, FuncionVentanaConsultaCITASespecialidadSEMANA);

					ShowWindow(vent, SW_HIDE);
					ShowWindow(hVentanaCONSULTAcitas_especialidad_semana, SW_SHOW);//Enseñamos la ventana

				}

				else {

					ShowWindow(vent, SW_HIDE);
					ShowWindow(hVentanaCONSULTAcitas_especialidad_semana, SW_SHOW);//Enseñamos la ventana

				}
			
			}

			else if (LOWORD(wParam) == ID_CONSULTASDECITAS_CITASENPANTALLA && HIWORD(wParam) == BN_CLICKED) { //Citas

				if (hVentanaConsulta_CITAS == NULL) {

					hVentanaConsulta_CITAS = CreateDialog(hGlobalInstance, MAKEINTRESOURCE(IDD_ConsultaCITAS), NULL, FuncionVentanaConsultaCITAS);

					ShowWindow(vent, SW_HIDE);
					ShowWindow(hVentanaConsulta_CITAS, SW_SHOW);//Enseñamos la ventana

				}

				else {

					ShowWindow(vent, SW_HIDE);
					ShowWindow(hVentanaConsulta_CITAS, SW_SHOW);//Enseñamos la ventana

				}

			}

			else if (LOWORD(wParam) == ID_DOCTORES_BUSCAR && HIWORD(wParam) == BN_CLICKED) {

				if (hVentanaBUSCARmedicos == NULL) {

					hVentanaBUSCARmedicos = CreateDialog(hGlobalInstance, MAKEINTRESOURCE(IDD_BUSCAR_medicos), NULL, FuncionVentanaBUSCARmedicos);

					ShowWindow(vent, SW_HIDE);
					ShowWindow(hVentanaBUSCARmedicos, SW_SHOW);//Enseñamos la ventana

				}

				else {

					ShowWindow(vent, SW_HIDE);
					ShowWindow(hVentanaBUSCARmedicos, SW_SHOW);//Enseñamos la ventana

				}

			}

			else if (LOWORD(wParam) == ID_PACIENTES_BUSCAR && HIWORD(wParam) == BN_CLICKED) {

				if (hVentanaBUSCARpacientes == NULL) {

					hVentanaBUSCARpacientes = CreateDialog(hGlobalInstance, MAKEINTRESOURCE(IDD_BUSCAR_Pacientes), NULL, FuncionVentanaBUSCARpacientes);

					ShowWindow(vent, SW_HIDE);
					ShowWindow(hVentanaBUSCARpacientes, SW_SHOW);//Enseñamos la ventana

				}

				else {

					ShowWindow(vent, SW_HIDE);
					ShowWindow(hVentanaBUSCARpacientes, SW_SHOW);//Enseñamos la ventana

				}

			}

	    }

		break;

		case WM_CLOSE:
		break;

		case WM_DESTROY:
		PostQuitMessage(120);
		break;

		default:
		break;
	}

	return FALSE;

}

BOOL CALLBACK FuncionVentanaREGISTROpacientes(HWND vent, UINT mensaje, WPARAM wParam, LPARAM lParam) {

	switch (mensaje)
	{

		case WM_INITDIALOG:{

			HWND Genero = GetDlgItem(vent, IDC_GENERO);

			SendMessage(Genero, CB_ADDSTRING, 0, (LPARAM)"Masculino");
			SendMessage(Genero, CB_ADDSTRING, 0, (LPARAM)"Femenino");

			HWND Combobox_DOCTORES = GetDlgItem(vent, IDC_1er_medico);

			if (Doctor::cantidad_de_doctores > 0) {
				Doctor* arr = arbol->Arreglo_del_arbol();//En un arreglo ponemos a los doctores
				int indice;

				for (indice = 0; indice < Doctor::cantidad_de_doctores; indice++) {

					SendMessage(Combobox_DOCTORES, CB_ADDSTRING, 0, (LPARAM)arr[indice].Nombre);

				}

				delete arr;
			}

		}

		case WM_COMMAND: {

			 if (LOWORD(wParam) == IDCANCEL && HIWORD(wParam) == BN_CLICKED) { //Cancelar

				ShowWindow(vent, SW_HIDE);
				ShowWindow(hVentanaPRINCIPAL, SW_SHOW);

			 }

			 if (LOWORD(wParam) == IDC_REPORTE && HIWORD(wParam) == BN_CLICKED) { //Generar reporte

				bool Exito_reporte = Reporte_Pacientes(vent);

				if (Exito_reporte == true) {
					MessageBox(vent, "Reporte realizado con exito", "Exito",MB_OK);
					
				}
				else {
					MessageBox(vent, "No hay pacientes registrados", "Aviso", MB_OK);
				}

			 }

			 if (LOWORD(wParam) == IDOK && HIWORD(wParam) == BN_CLICKED) { //Registrar

				 bool exito = false;
				exito = REGISTRAR_PACIENTES(vent,1);

				if (exito == true) {

					MessageBox(hVentanaREGISTROpacientes, "Paciente Registrado", "Exito", MB_OK);

					DestroyWindow(hVentanaREGISTROpacientes);
					hVentanaREGISTROpacientes = NULL; //El puntero va a apuntar a NULO

					ShowWindow(hVentanaPRINCIPAL, SW_SHOW);

				}
				else {

					break;

				}



			 }//FIN DEL IF
				break;

			default:
			break;
		}

		case WM_DESTROY:
			//PostQuitMessage(120);
			break;

		
	}
	return FALSE;
}

BOOL CALLBACK FuncionVentanaREGISTROcitas(HWND vent, UINT mensaje, WPARAM wParam, LPARAM lParam) {

	switch (mensaje) {

		case WM_INITDIALOG: {

			SetTimer(vent, TM_RELOJ, 1000, NULL); //SET TIMER

			//Ponemos por defecto, inaccesible el hecho de poner hora
			HWND Box_hora;
			HWND Actualizar_horarios;
			Actualizar_horarios = GetDlgItem(vent, IDC_actualizar);
			Box_hora = GetDlgItem(vent, IDC_Hora);
			EnableWindow(Box_hora, false);
			EnableWindow(Actualizar_horarios, false);

			#pragma region COMBO BOX
			HWND hComboPaciente;
			hComboPaciente = GetDlgItem(vent, IDC_COMBO_Paciente);

			HWND hComboEspecialidad = GetDlgItem(vent, IDC_Especialidad);

			aux = origen;//Paciente
			aux_esp = origen_esp;
			//auxD = origenD;//Doctor

			while (aux != NULL) { //Ciclo para mostrar pacientes

				SendMessage(hComboPaciente, CB_ADDSTRING, 0, (LPARAM)aux->Nombre);

				aux = aux->next;

			}

			while (aux_esp != NULL) { //Ciclo para mostrar especialidades

				SendMessage(hComboEspecialidad, CB_ADDSTRING, 0, (LPARAM)aux_esp->especialidad);

				aux_esp = aux_esp->next_esp;

			}


			SendMessage(hComboPaciente, CB_SETCURSEL, 0, NULL);

			#pragma endregion
			

		}

		 case WM_COMMAND: {

			 if (LOWORD(wParam) == ID_REGISTRAR && HIWORD(wParam) == BN_CLICKED) { //Registrar

				 int Validacion;

				 Validacion = Validar_CITAS(vent);

				 if (Validacion == -1) {

					 break;

				 }
				 else if (Validacion == 0) {

					 MessageBox(vent, "Por favor rellene los espacios vacios", "Atencion", MB_OK);
					 break;
				 }
				 else if (Validacion == 1 || Validacion == 5) {

					 MessageBoxA(vent, "Cita registrada exitosamente", "Registrado", MB_OK);

					 DestroyWindow(vent);
					 hVentanaREGISTROcitas = NULL; //El puntero va a apuntar a NULO
					 ShowWindow(hVentanaPRINCIPAL, SW_SHOW);

				 }

			 }

			 else if (LOWORD(wParam) == IDC_Especialidad && HIWORD(wParam) == CBN_SELENDOK)
			 {
				 HWND hComboDoctor = GetDlgItem(vent, IDC_Doctor);

				 SetWindowText(hComboDoctor, "");

				 while (SendMessage(hComboDoctor, CB_GETCOUNT, NULL, NULL) != NULL) {

					 SendMessage(hComboDoctor, CB_DELETESTRING, NULL, NULL);

				 }

				 HWND CB_Especialidad = GetDlgItem(vent, IDC_Especialidad);
				 char* temporal_especialidad = new char[15];
				 int cursel = SendMessage(CB_Especialidad, CB_GETCURSEL, NULL, NULL); //Vemos la posicion de donde clickó en la lista
				 SendMessage(CB_Especialidad, CB_GETLBTEXT, cursel, (LPARAM)temporal_especialidad);

				 if (strcmp(temporal_especialidad, "")==1) { //Si la cadena no esta vacia

					 Doctor* arr = arbol->Arreglo_del_arbol();//En un arreglo ponemos a los doctores
					 int indice;

					 for (indice = 0; indice < Doctor::cantidad_de_doctores; indice++) {

						 if (strcmp(arr[indice].Especialidad, temporal_especialidad) == 0) {

							 SendMessage(hComboDoctor, CB_ADDSTRING, 0, (LPARAM)arr[indice].Nombre);

						 }

					 }

				 }
			 }

			 else if (LOWORD(wParam) == IDC_Doctor && HIWORD(wParam) == CBN_SELENDOK ||
				 LOWORD(wParam) == IDC_actualizar && HIWORD(wParam) == BN_CLICKED) //Si selecciona un doctor
			      {
					 HWND Horarios = GetDlgItem(vent, IDC_Hora);
					 HWND Consultorios = GetDlgItem(vent, IDC_Consultorio);

					 while (SendMessage(Horarios, CB_GETCOUNT, NULL, NULL) != NULL) {
						 SendMessage(Horarios, CB_DELETESTRING, NULL, NULL);
					 }
					 while (SendMessage(Consultorios, CB_GETCOUNT, NULL, NULL) != NULL) {
						 SendMessage(Consultorios, CB_DELETESTRING, NULL, NULL);
					 }

					     imprirmir_foto_doctor(vent);
						 Imprimir_Horarios(vent);
						 Imprimir_consultorio_doctor(vent);


			      }

			else if (LOWORD(wParam) == IDCANCEL && HIWORD(wParam) == BN_CLICKED) { //Cancelar

					DestroyWindow(vent);
					hVentanaREGISTROcitas = NULL; //El puntero va a apuntar a NULO
					ShowWindow(hVentanaPRINCIPAL, SW_SHOW);

			}
		 }
			break;

		 case WM_TIMER: { //Aqui es todo lo que se lleva a cabo con el tiempo

			 tlocal = localtime(&tiempo); //estructura donde obtengo el tiempo
			 strftime(FECHA_ACTUAL, 11, "%d/%m/%Y", tlocal);//formato para guardar la fecha obtenido en *tlocal como dd/mm/yyyy

			 strftime(HORA_ACTUAL, 11, "%H:%M:%S", tlocal); //EN FORMATO DE 24 HORAS


		 }

			 break;
 
			case WM_DESTROY:
				break;
				
			case WM_CLOSE:
				KillTimer(vent, TM_RELOJ);
			//PostQuitMessage(120);
			break;

		   default:
			break;
		

				  
	}

	return FALSE;

}

BOOL CALLBACK FuncionVentanaREGISTROdemedicos(HWND vent, UINT mensaje, WPARAM wParam, LPARAM lParam) {

	switch (mensaje)
	{
		case WM_INITDIALOG: {

			fotoagregada = false;
			
			HWND hComboConsultorio;
			hComboConsultorio = GetDlgItem(vent, IDC_Consultorio);
			SendMessage(hComboConsultorio, CB_ADDSTRING, 0, (LPARAM)"1");
			SendMessage(hComboConsultorio, CB_ADDSTRING, 0, (LPARAM)"2");
			SendMessage(hComboConsultorio, CB_ADDSTRING, 0, (LPARAM)"3");
			SendMessage(hComboConsultorio, CB_SETCURSEL, 0, NULL);

			//ENTRADA
			#pragma region COMBOBOX
			HWND hCombo1;
			hCombo1 = GetDlgItem(vent, IDC_E1);  
			SendMessage(hCombo1, CB_ADDSTRING, 0, (LPARAM)"LIBRE");//Lista desplegable 
			SendMessage(hCombo1, CB_ADDSTRING, 0, (LPARAM)H.h1);
			SendMessage(hCombo1, CB_ADDSTRING, 0, (LPARAM)H.h2);
			SendMessage(hCombo1, CB_ADDSTRING, 0, (LPARAM)H.h3);
			SendMessage(hCombo1, CB_ADDSTRING, 0, (LPARAM)H.h4);
			SendMessage(hCombo1, CB_SETCURSEL, 0, NULL);

			HWND hCombo2;
			hCombo2 = GetDlgItem(vent, IDC_E2);
			SendMessage(hCombo2, CB_ADDSTRING, 0, (LPARAM)"LIBRE");//Lista desplegable 
			SendMessage(hCombo2, CB_ADDSTRING, 0, (LPARAM)H.h1);
			SendMessage(hCombo2, CB_ADDSTRING, 0, (LPARAM)H.h2);
			SendMessage(hCombo2, CB_ADDSTRING, 0, (LPARAM)H.h3);
			SendMessage(hCombo2, CB_ADDSTRING, 0, (LPARAM)H.h4);
			SendMessage(hCombo2, CB_SETCURSEL, 0, NULL);

			HWND hCombo3;
			hCombo3 = GetDlgItem(vent, IDC_E3);
			SendMessage(hCombo3, CB_ADDSTRING, 0, (LPARAM)"LIBRE");//Lista desplegable 
			SendMessage(hCombo3, CB_ADDSTRING, 0, (LPARAM)H.h1);
			SendMessage(hCombo3, CB_ADDSTRING, 0, (LPARAM)H.h2);
			SendMessage(hCombo3, CB_ADDSTRING, 0, (LPARAM)H.h3);
			SendMessage(hCombo3, CB_ADDSTRING, 0, (LPARAM)H.h4);
			SendMessage(hCombo3, CB_SETCURSEL, 0, NULL);

			HWND hCombo4;
			hCombo4 = GetDlgItem(vent, IDC_E4);
			SendMessage(hCombo4, CB_ADDSTRING, 0, (LPARAM)"LIBRE");//Lista desplegable 
			SendMessage(hCombo4, CB_ADDSTRING, 0, (LPARAM)H.h1);
			SendMessage(hCombo4, CB_ADDSTRING, 0, (LPARAM)H.h2);
			SendMessage(hCombo4, CB_ADDSTRING, 0, (LPARAM)H.h3);
			SendMessage(hCombo4, CB_ADDSTRING, 0, (LPARAM)H.h4);
			SendMessage(hCombo4, CB_SETCURSEL, 0, NULL);

			HWND hCombo5;
			hCombo5 = GetDlgItem(vent, IDC_E5);
			SendMessage(hCombo5, CB_ADDSTRING, 0, (LPARAM)"LIBRE");//Lista desplegable 
			SendMessage(hCombo5, CB_ADDSTRING, 0, (LPARAM)H.h1);
			SendMessage(hCombo5, CB_ADDSTRING, 0, (LPARAM)H.h2);
			SendMessage(hCombo5, CB_ADDSTRING, 0, (LPARAM)H.h3);
			SendMessage(hCombo5, CB_ADDSTRING, 0, (LPARAM)H.h4);
			SendMessage(hCombo5, CB_SETCURSEL, 0, NULL);

			#pragma endregion

			HWND ComboBox_Especialidad = GetDlgItem(vent, IDC_Especialidad);

			aux_esp = origen_esp;

			while (aux_esp != NULL) { //Ciclo para mostrar especialidades

				SendMessage(ComboBox_Especialidad, CB_ADDSTRING, 0, (LPARAM)aux_esp->especialidad);

				aux_esp = aux_esp->next_esp;

			}

		}

		case WM_COMMAND: {

			if (LOWORD(wParam) == IDC_BUTTON1 && HIWORD(wParam) == BN_CLICKED) { //AGREGAR FOTO


				OPENFILENAME ofn; //ESTRUCTURA 
				ZeroMemory(&ofn, sizeof(ofn));


				ofn.hwndOwner = vent;
				ofn.lStructSize = sizeof(ofn);
				ofn.lpstrFile = chDireccionDOC;
				ofn.nMaxFile = MAX_PATH;
				ofn.lpstrDefExt = "txt";
				ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_NOCHANGEDIR;
				ofn.lpstrFilter = "Text Files\0*.txt\0All Files\0*.*\0";

				if (GetOpenFileName(&ofn)) { //Nos regresara un valor verdadero al elegir una imagen y dar en aceptar

					himagen = GetDlgItem(vent, IDC_FOTO);
					hBitmap = (HBITMAP)LoadImage(NULL, chDireccionDOC, IMAGE_BITMAP, 150, 150, LR_LOADFROMFILE);
					SendMessage(himagen, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap);
					fotoagregada = true;

				}

			}

			if (LOWORD(wParam) == IDOK && HIWORD(wParam) == BN_CLICKED) { 

				int Validacion;

				Validacion = Validar_MEDICOS(vent,1);

				if (Validacion == -1) {

					break;

				}
				else if (Validacion == 0) {

					MessageBox(vent, "Por favor rellene los espacios vacios", "Atencion", MB_OK);
					break;
				}
				else if (Validacion == 1 || Validacion == 5) {

					MessageBox(hVentanaREGISTROcitas, "Doctor Registrado", "Exito", MB_OK);

					DestroyWindow(vent);
					hVentanaREGISTROdemedicos = NULL; //El puntero va a apuntar a NULO
					ShowWindow(hVentanaPRINCIPAL, SW_SHOW);

				}


			}

			if (LOWORD(wParam) == ID_Reporte_medicos && HIWORD(wParam) == BN_CLICKED) {

				Doctor *arr = arbol->Arreglo_del_arbol();
				quickSort(arr, 0, Doctor::cantidad_de_doctores - 1);
				Reporte_doctores(vent, arr);
				delete arr;
			}

			if (LOWORD(wParam) == IDCANCEL && HIWORD(wParam) == BN_CLICKED) { //Cancelar

				DestroyWindow(vent);
				hVentanaREGISTROdemedicos = NULL; //El puntero va a apuntar a NULO
				ShowWindow(hVentanaPRINCIPAL, SW_SHOW);

			}

		}
			break;

		case WM_DESTROY:
			
			break;

		default:
			break;
	}

	return FALSE;

}

BOOL CALLBACK FuncionVentanaREGISTROespecialidades(HWND vent, UINT mensaje, WPARAM wParam, LPARAM lParam) {

	switch (mensaje)
	{
		case WM_INITDIALOG: {

			HWND ELIMINAR = GetDlgItem(vent, IDC_ELIMINAR);
			
			EnableWindow(ELIMINAR, false);

			SetDlgItemText(vent, IDC_descripcion_especialidad, "");

			HWND ListBox_Editar_Nombre = GetDlgItem(vent, IDC_Nueva_especialidad);
			HWND ListBox_Editar_Descripcion = GetDlgItem(vent, IDC_EDIT3);
			HWND btn_Confirmar = GetDlgItem(vent, IDC_CONFIRMAR);

			EnableWindow(ListBox_Editar_Nombre, false);
			EnableWindow(ListBox_Editar_Descripcion, false);
			EnableWindow(btn_Confirmar, false);

			HWND ListBox_Especialidades =  GetDlgItem(vent, IDC_COMBO1);

			aux_esp = origen_esp;

			while (aux_esp != NULL) {

				SendMessage(ListBox_Especialidades, CB_ADDSTRING, 0, (LPARAM)aux_esp->especialidad);
				aux_esp = aux_esp->next_esp;
			}

		}


		case WM_COMMAND: {

			if (LOWORD(wParam) == ID_REGISTRAR && HIWORD(wParam) == BN_CLICKED) {

				bool validar_espacios; //Identificador
				int contador_validaciones = 0; //Para saber que todo esta validado
				char cValidaciondeDATOS[50];

				validar_espacios = ValidacionLongitud(vent, 3); //Validamos el que no haya espacios vacios

				if (validar_espacios == false) { //Si no esta todo relleno
					break;
				}

				contador_validaciones = 1;

				HWND hEspecialidad = GetDlgItem(vent, ID_Especialidad);
				HWND hDescripcion = GetDlgItem(vent, IDC_Descripcion);

				int longitud_Especialidad = GetWindowTextLength(hEspecialidad);
				int longitud_Descripcion = GetWindowTextLength(hDescripcion);


				if (contador_validaciones == 1) { //Si todo esta validado correctamente, ahora si pasamos la informacion a la estructura

					//Esta clase se utiliza para guardar la informacion temporalmente
					Especialidad* Clase_temporal_E = new Especialidad();

					GetWindowText(hEspecialidad, Clase_temporal_E->especialidad, longitud_Especialidad + 1);
					GetWindowText(hDescripcion, Clase_temporal_E->Descripcion, longitud_Descripcion + 1);

					//Registrando el nueva especialidad
					ListasLigadas* Registro = NULL;
					Registro->AgregarEspecialidad(Clase_temporal_E->especialidad,Clase_temporal_E->Descripcion);

					//Eliminamos los punteros
					delete Clase_temporal_E;

					MessageBox(hVentanaREGISTROcitas, "Especialidad Registrada", "Exito", MB_OK);

					DestroyWindow(vent);
					hVentanaREGISTROespecialidades = NULL; //El puntero va a apuntar a NULO
					ShowWindow(hVentanaPRINCIPAL, SW_SHOW);

				}



			}

			else if (LOWORD(wParam) == IDCANCEL_esp && HIWORD(wParam) == BN_CLICKED) { //Cancelar

				hVentanaREGISTROespecialidades = NULL;

				DestroyWindow(vent);
				ShowWindow(hVentanaPRINCIPAL, SW_SHOW);
			}

			//Combobox
			else if (LOWORD(wParam) == IDC_COMBO1 && HIWORD(wParam) == CBN_SELENDOK) {

				HWND ELIMINAR = GetDlgItem(vent, IDC_ELIMINAR);
				HWND btn_Confirmar = GetDlgItem(vent, IDC_CONFIRMAR);
				EnableWindow(ELIMINAR, true);
				EnableWindow(btn_Confirmar, true);

				HWND ListBox_Editar_Nombre = GetDlgItem(vent, IDC_Nueva_especialidad);
				HWND ListBox_Editar_Descripcion = GetDlgItem(vent, IDC_EDIT3);
				EnableWindow(ListBox_Editar_Nombre, true);
				EnableWindow(ListBox_Editar_Descripcion, true);
				

				HWND CB_Especialidad = GetDlgItem(vent, IDC_COMBO1);
				char* temporal_especialidad = new char[30];
				int cursel = SendMessage(CB_Especialidad, CB_GETCURSEL, NULL, NULL); //Vemos la posicion de donde clickó en la lista
				SendMessage(CB_Especialidad, CB_GETLBTEXT, cursel, (LPARAM)temporal_especialidad);

				aux_esp = origen_esp;

				while (aux_esp != NULL) {
				
					if (strcmp(aux_esp->especialidad, temporal_especialidad) == 0) {

						SetDlgItemText(vent, IDC_descripcion_especialidad, aux_esp->Descripcion);
					
						break;
					}
					else {
						aux_esp = aux_esp->next_esp;
					}
					

				}

				

			}

			else if (LOWORD(wParam) == IDC_CONFIRMAR && HIWORD(wParam) == BN_CLICKED) { //Confirmar

				HWND CB_Especialidad = GetDlgItem(vent, IDC_COMBO1);
				char* temporal_especialidad = new char[30];
				int cursel = SendMessage(CB_Especialidad, CB_GETCURSEL, NULL, NULL); //Vemos la posicion de donde clickó en la lista
				SendMessage(CB_Especialidad, CB_GETLBTEXT, cursel, (LPARAM)temporal_especialidad);

				aux_esp = origen_esp;

				while(aux_esp!=NULL) {
				
					if (strcmp(aux_esp->especialidad, temporal_especialidad) == 0) {

						HWND Nueva_especialidad = GetDlgItem(vent, IDC_Nueva_especialidad);
						HWND Nueva_Descripcion = GetDlgItem(vent, IDC_EDIT3);

						int longitud_Especialidad = GetWindowTextLength(Nueva_especialidad); //Sacamos la longitud
						int longitud_Descripcion = GetWindowTextLength(Nueva_Descripcion); //Sacamos la longitud

						GetWindowText(Nueva_especialidad, aux_esp->especialidad, longitud_Especialidad + 1);
						GetWindowText(Nueva_Descripcion, aux_esp->Descripcion, longitud_Descripcion + 1);


						//LIMPIAMOS LA LISTA
						
						while (SendMessage(CB_Especialidad, CB_GETCOUNT, NULL, NULL) != NULL) {

							SendMessage(CB_Especialidad, CB_DELETESTRING, NULL, NULL);

						}

						//Llenamos la lista con lso pacientes que no fueron eliminados
						aux_esp = origen_esp;
						while (aux_esp != NULL) {

							SendMessage(CB_Especialidad, CB_ADDSTRING, 0, (LPARAM)aux_esp->especialidad);
							aux_esp = aux_esp->next_esp;

						}

						MessageBox(vent, "Edicion completada", "Aviso", MB_OK);

						HWND ListBox_Editar_Nombre = GetDlgItem(vent, IDC_Nueva_especialidad);
						HWND ListBox_Editar_Descripcion = GetDlgItem(vent, IDC_EDIT3);
						HWND btn_Confirmar = GetDlgItem(vent, IDC_BUTTON1);

						SetDlgItemText(vent, IDC_descripcion_especialidad, "");
						SetDlgItemText(vent, IDC_Nueva_especialidad, "");
						SetDlgItemText(vent, IDC_EDIT3, "");

						EnableWindow(ListBox_Editar_Nombre, false);
						EnableWindow(ListBox_Editar_Descripcion, false);
						EnableWindow(btn_Confirmar, false);

						

						break;

					}
					else {
						aux_esp = aux_esp->next_esp;
					}
					
				}
				

			}

			else if (LOWORD(wParam) == IDC_ELIMINAR && HIWORD(wParam) == BN_CLICKED) { //Eliminar

				HWND CB_Especialidad = GetDlgItem(vent, IDC_COMBO1);
				char* Especialidad_seleccionada = new char[15];
				int cursel = SendMessage(CB_Especialidad, CB_GETCURSEL, NULL, NULL); //Vemos la posicion de donde clickó en la lista
				SendMessage(CB_Especialidad, CB_GETLBTEXT, cursel, (LPARAM)Especialidad_seleccionada);

				aux_esp = origen_esp;
				while (aux_esp != NULL) {

					char Especialidad_registrada[60] = "";
					strcat(Especialidad_registrada, aux_esp->especialidad);

					if (strcmp(Especialidad_seleccionada, Especialidad_registrada) == 0) {

						//Hacemos todo el proceso para eliminar al paciente

						if (aux_esp->prev_esp == NULL && aux_esp->next_esp == NULL) {
							delete aux_esp;
							aux_esp = origen_esp = NULL;
						}
						else if (aux_esp->next_esp == NULL) {
							aux_esp->prev_esp->next_esp = NULL;
							delete aux_esp;
						}
						else if (aux_esp->prev_esp == NULL) {
							origen_esp = origen_esp->next_esp;
							origen_esp->prev_esp = NULL;
							delete aux_esp;
						}
						else {
							aux_esp->next_esp->prev_esp = aux_esp->prev_esp;
							aux_esp->prev_esp->next_esp = aux_esp->next_esp;
							delete aux_esp;
						}

						//Limpiamos la lista
						aux_esp = origen_esp;
						while (SendMessage(CB_Especialidad, CB_GETCOUNT, NULL, NULL) != NULL) {

							SendMessage(CB_Especialidad, CB_DELETESTRING, NULL, NULL);

						}

						//Llenamos la lista con lso pacientes que no fueron eliminados
						aux_esp = origen_esp;
						while (aux_esp != NULL) {

							char nombre_especialidad[60] = ""; strcat(nombre_especialidad, aux_esp->especialidad);

							SendMessage(CB_Especialidad, CB_ADDSTRING, 0, (LPARAM)nombre_especialidad);
							aux_esp = aux_esp->next_esp;

						}

						SetWindowText(CB_Especialidad, "");

						break;

					}

					aux_esp = aux_esp->next_esp;

				}

			}


		}
		 break;

		case WM_DESTROY:
			//PostQuitMessage(120);
			break;

		default:
			break;
	}

	return FALSE;

}

BOOL CALLBACK FuncionVentanaBUSCARpacientes(HWND vent, UINT mensaje, WPARAM wParam, LPARAM lParam) {

	switch (mensaje)
	{
		case WM_INITDIALOG: {

			aux = origen;

			HWND hListaAgenda = GetDlgItem(vent, IDC_lista_nombres);

			HWND ELIMINAR = GetDlgItem(vent, IDC_BUTTON2);
			EnableWindow(ELIMINAR, false);

			while (aux != NULL) {

				char nombre_paciente[60] = ""; strcat(nombre_paciente, aux->Nombre); strcat(nombre_paciente, " ");
				strcat(nombre_paciente, aux->Apellidos);

				SendMessage(hListaAgenda, LB_ADDSTRING, 0, (LPARAM)nombre_paciente);
				aux = aux->next;

			}

			HWND hEditBoxNOMBRE = GetDlgItem(vent, IDC_PACIENTE);
			HWND hEditBoxAPELLIDOS = GetDlgItem(vent, IDC_APPELIDOS);
			HWND hEditBoxGENERO = GetDlgItem(vent, IDC_GENERO);
			HWND hEditBoxTELEFONO = GetDlgItem(vent, IDC_TELEFONO);
			HWND hEditBoxREFERENCIA = GetDlgItem(vent, IDC_REFERENCIA);
			HWND hEditBoxNACIMIENTO = GetDlgItem(vent, IDC_FECHA_NACIMIENTO);
			HWND hEditBoxEDAD = GetDlgItem(vent, IDC_EDAD);
			HWND hEditBoxPRIMER_MEDICO = GetDlgItem(vent, IDC_1er_medico);

			EnableWindow(hEditBoxNOMBRE, false);
			EnableWindow(hEditBoxAPELLIDOS, false);
			EnableWindow(hEditBoxGENERO, false);
			EnableWindow(hEditBoxTELEFONO, false);
			EnableWindow(hEditBoxREFERENCIA, false);
			EnableWindow(hEditBoxNACIMIENTO, false);
			EnableWindow(hEditBoxEDAD, false);
			EnableWindow(hEditBoxPRIMER_MEDICO, false);

		}

		case WM_COMMAND: {

			if (LOWORD(wParam) == IDC_BUTTON1 && HIWORD(wParam) == BN_CLICKED) { //BUSCAR

				aux = origen;

				char nombre_paciente[60] = "";

				HWND hNOMBRE = GetDlgItem(vent, IDC_EDIT1);
				HWND hLista = GetDlgItem(vent, IDC_lista_nombres);

				int longitud_NOMBRE = GetWindowTextLength(hNOMBRE); //Sacamos la longitud
				GetWindowText(hNOMBRE, nombre_paciente, longitud_NOMBRE + 1);
				
				HWND hLISTA = GetDlgItem(vent, IDC_lista_nombres);

				while (SendMessage(hLISTA, LB_GETCOUNT, NULL, NULL) != NULL) {

					SendMessage(hLISTA, LB_DELETESTRING, NULL, NULL);

				}

				while (aux != NULL) {

					char nombre_registrado[60] = "";
					strcat(nombre_registrado, aux->Nombre); strcat(nombre_registrado, " ");
					strcat(nombre_registrado, aux->Apellidos);

					if (strcmp(nombre_paciente,nombre_registrado)==0) {

						while (SendMessage(hLista, CB_GETCOUNT, NULL, NULL) != NULL) {

							SendMessage(hLista, CB_DELETESTRING, NULL, NULL);

						}

						SendMessage(hLista, LB_ADDSTRING, 0, (LPARAM)nombre_paciente);
						break;
					}
					aux = aux->next;

				}


			}

			else if (LOWORD(wParam) == IDC_BUTTON2 && HIWORD(wParam) == BN_CLICKED) { //ELIMINAR

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
					
						//Hacemos todo el proceso para eliminar al paciente

						if (aux->prev == NULL && aux->next == NULL) {
							delete aux;
							aux = origen = NULL;
						}
						else if (aux->next == NULL) {
							aux->prev->next = NULL;
							delete aux;
						}
						else if (aux->prev == NULL) {
							origen = origen->next;
							origen->prev = NULL;
							delete aux;
						}
						else {
							aux->next->prev = aux->prev;
							aux->prev->next = aux->next;
							delete aux;
						}

						//Limpiamos la lista
						aux = origen;
						while (SendMessage(LB_Lista, LB_GETCOUNT, NULL, NULL) != NULL) {

							SendMessage(LB_Lista, LB_DELETESTRING, NULL, NULL);

						}

						//Llenamos la lista con lso pacientes que no fueron eliminados
						aux = origen;
						while (aux != NULL) {

							char nombre_paciente[60] = ""; strcat(nombre_paciente, aux->Nombre); strcat(nombre_paciente, " ");
							strcat(nombre_paciente, aux->Apellidos);

							SendMessage(LB_Lista, LB_ADDSTRING, 0, (LPARAM)nombre_paciente);
							aux = aux->next;

						}

						break;

					} 

					aux = aux->next;

				}

				

			}

			else if (LOWORD(wParam) == IDC_BUTTON3 && HIWORD(wParam) == BN_CLICKED) { //CAMBIAR

					REGISTRAR_PACIENTES(vent, 2);

					HWND LB_Lista = GetDlgItem(vent, IDC_lista_nombres);

					//Hacemos todo el proceso para eliminar al paciente
					//Limpiamos la lista
					aux = origen;
					while (SendMessage(LB_Lista, LB_GETCOUNT, NULL, NULL) != NULL) {

						SendMessage(LB_Lista, LB_DELETESTRING, NULL, NULL);

					}

					//Llenamos la lista con lso pacientes que no fueron eliminados
					aux = origen;
					while (aux != NULL) {

						char nombre_paciente[60] = ""; strcat(nombre_paciente, aux->Nombre); strcat(nombre_paciente, " ");
						strcat(nombre_paciente, aux->Apellidos);

						SendMessage(LB_Lista, LB_ADDSTRING, 0, (LPARAM)nombre_paciente);
						aux = aux->next;

					}

					break;

			}

			else if (LOWORD(wParam) == IDC_lista_nombres && HIWORD(wParam) == LBN_SELCHANGE) {// ListBox
			

				HWND hEditBoxNOMBRE = GetDlgItem(vent, IDC_PACIENTE);
				HWND hEditBoxAPELLIDOS = GetDlgItem(vent, IDC_APPELIDOS);
				HWND hEditBoxGENERO = GetDlgItem(vent, IDC_GENERO);
				HWND hEditBoxTELEFONO = GetDlgItem(vent, IDC_TELEFONO);
				HWND hEditBoxREFERENCIA = GetDlgItem(vent, IDC_REFERENCIA);
				HWND hEditBoxNACIMIENTO = GetDlgItem(vent, IDC_FECHA_NACIMIENTO);
				HWND hEditBoxEDAD = GetDlgItem(vent, IDC_EDAD);
				HWND hEditBoxPRIMER_MEDICO = GetDlgItem(vent, IDC_1er_medico);

				EnableWindow(hEditBoxNOMBRE, true);
				EnableWindow(hEditBoxAPELLIDOS, true);
				EnableWindow(hEditBoxGENERO, true);
				EnableWindow(hEditBoxTELEFONO, true);
				EnableWindow(hEditBoxREFERENCIA, true);
				EnableWindow(hEditBoxNACIMIENTO, true);
				EnableWindow(hEditBoxEDAD, true);
				EnableWindow(hEditBoxPRIMER_MEDICO, true);


				HWND ELIMINAR = GetDlgItem(vent, IDC_BUTTON2);
				EnableWindow(ELIMINAR, true);


				HWND Genero = GetDlgItem(vent, IDC_GENERO);

				SendMessage(Genero, CB_ADDSTRING, 0, (LPARAM)"Masculino");
				SendMessage(Genero, CB_ADDSTRING, 0, (LPARAM)"Femenino");

				HWND Combobox_DOCTORES = GetDlgItem(vent, IDC_1er_medico);

				if (Doctor::cantidad_de_doctores > 0) {
					Doctor* arr = arbol->Arreglo_del_arbol();//En un arreglo ponemos a los doctores
					int indice;

					for (indice = 0; indice < Doctor::cantidad_de_doctores; indice++) {

						SendMessage(hEditBoxPRIMER_MEDICO, CB_ADDSTRING, 0, (LPARAM)arr[indice].Nombre);

					}

					delete arr;
				}

			} 

			else if (LOWORD(wParam) == IDCANCEL && HIWORD(wParam) == BN_CLICKED) { //CANCELAR

					hVentanaBUSCARpacientes = NULL;

					DestroyWindow(vent);
					ShowWindow(hVentanaPRINCIPAL, SW_SHOW);

				

			}

			else if (LOWORD(wParam) == IDC_MOSTRAR_TODO && HIWORD(wParam) == BN_CLICKED) { //BUSCAR

				aux = origen;

				HWND hListaAgenda = GetDlgItem(vent, IDC_lista_nombres);

				while (SendMessage(hListaAgenda, LB_GETCOUNT, NULL, NULL) != NULL) {

					SendMessage(hListaAgenda, LB_DELETESTRING, NULL, NULL);

				}

				HWND ELIMINAR = GetDlgItem(vent, IDC_BUTTON2);
				EnableWindow(ELIMINAR, false);

				while (aux != NULL) {

					char nombre_paciente[60] = ""; strcat(nombre_paciente, aux->Nombre); strcat(nombre_paciente, " ");
					strcat(nombre_paciente, aux->Apellidos);

					SendMessage(hListaAgenda, LB_ADDSTRING, 0, (LPARAM)nombre_paciente);
					aux = aux->next;

				}


			}

		}
				   break;

		case WM_DESTROY:
			break;

		default:
			break;
	}

	return FALSE;

}

BOOL CALLBACK FuncionVentanaConsultaporsemana(HWND vent, UINT mensaje, WPARAM wParam, LPARAM lParam) {


	switch (mensaje)
	{
		case WM_INITDIALOG: {

			aux = origen;

			HWND hComboBox_MES = GetDlgItem(vent, IDC_COMBO1);
			HWND hComboBox_SEMANA = GetDlgItem(vent, IDC_COMBO2);

			HWND hACEPTAR = GetDlgItem(vent, IDOK);
			EnableWindow(hACEPTAR, false);

			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"enero");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"febrero");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"marzo");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"abril");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"mayo");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"junio");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"julio");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"agosto");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"septiembre");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"octubre");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"noviembre");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"diciembre");

			SendMessage(hComboBox_SEMANA, CB_INSERTSTRING, 0, (LPARAM)"1");
			SendMessage(hComboBox_SEMANA, CB_INSERTSTRING, 0, (LPARAM)"2");
			SendMessage(hComboBox_SEMANA, CB_INSERTSTRING, 0, (LPARAM)"3");
			SendMessage(hComboBox_SEMANA, CB_INSERTSTRING, 0, (LPARAM)"4");
			SendMessage(hComboBox_SEMANA, CB_INSERTSTRING, 0, (LPARAM)"5");
			

		}
			break;

		case WM_COMMAND: {

			if (LOWORD(wParam) == IDC_COMBO1 && HIWORD(wParam) == CBN_SELENDOK ||
				LOWORD(wParam) == IDC_COMBO2 && HIWORD(wParam) == CBN_SELENDOK) {

				HWND btn_ACEPTAR = GetDlgItem(vent, IDOK);
				HWND CB_Semana = GetDlgItem(vent, IDC_COMBO2);

				EnableWindow(btn_ACEPTAR, true);
				EnableWindow(CB_Semana, true);


			}

			else if (LOWORD(wParam) == IDOK && HIWORD(wParam) == BN_CLICKED) {

				HWND CB_MES = GetDlgItem(vent, IDC_COMBO1); //MES
				HWND CB_Semana = GetDlgItem(vent, IDC_COMBO2); //Semana

				char* temporal_MES = new char[30];
				char* temporal_Semana = new char[30];

				

				int cursel_mes = SendMessage(CB_MES, CB_GETCURSEL, NULL, NULL); //Vemos la posicion de donde clickó en la lista
				int cursel_semana = SendMessage(CB_Semana, CB_GETCURSEL, NULL, NULL); //Vemos la posicion de donde clickó en la lista

				SendMessage(CB_MES, CB_GETLBTEXT, cursel_mes, (LPARAM)temporal_MES);
				SendMessage(CB_Semana, CB_GETLBTEXT, cursel_semana, (LPARAM)temporal_Semana);

				string s_MES = temporal_MES; //Lo pasamos a un string para poder compararlo en la funcion

				

				if (Consultaporsemana(vent, s_MES, &temporal_Semana) == true) {
					MessageBox(vent, "El archivo de la consulta por SEMANA se ha guardado", "Exito", MB_OK);
				}
				else {
					MessageBox(vent, "El archivo de la consulta por SEMANA NO se ha guardado", "Error", MB_OK);
				}


			}
		
			else if (LOWORD(wParam) == IDCANCEL && HIWORD(wParam) == BN_CLICKED) {


				hVentanaCONSULTAcitas_semana = NULL;

				DestroyWindow(vent);
				ShowWindow(hVentanaPRINCIPAL, SW_SHOW);

			}

		}
		
			break;

		case WM_DESTROY:
			break;

		default:
			break;
	}

	return FALSE;


}

BOOL CALLBACK FuncionVentanaConsultaCITAS(HWND vent, UINT mensaje, WPARAM wParam, LPARAM lParam) {

	switch (mensaje)
	{
		case WM_INITDIALOG: {

			aux = origen;

			HWND hbtn_Cancelada = GetDlgItem(vent, IDC_BUTTON1);
			HWND hbtn_Realizada = GetDlgItem(vent, IDC_BUTTON2);
			HWND EditBOX_Motivodecancelacion = GetDlgItem(vent, IDC_EDIT1);
			SetWindowText(EditBOX_Motivodecancelacion, "");
			
			EnableWindow(hbtn_Cancelada, false);
			EnableWindow(hbtn_Realizada, false);

			HWND ComboBox_ID_CITAS = GetDlgItem(vent, IDC_COMBO1);
			
			auxC = origenC;
			char ID_CITA[2];

			while (auxC != NULL) {

				_itoa(auxC->ID_c, ID_CITA, 10);

					SendMessage(ComboBox_ID_CITAS, CB_ADDSTRING, 0, (LPARAM)ID_CITA);

					auxC = auxC->nextC;
			}


		}
					  break;

		case WM_COMMAND: {

			 if (LOWORD(wParam) == IDC_SALIR && HIWORD(wParam) == BN_CLICKED) { //Salir de la ventana

				 hVentanaConsulta_CITAS = NULL;

				 DestroyWindow(vent);
				 ShowWindow(hVentanaPRINCIPAL, SW_SHOW);

			 }

			 if (LOWORD(wParam) == IDC_COMBO1 && HIWORD(wParam) == CBN_SELENDOK) { //Selecciona un ID

					 HWND Motivo = GetDlgItem(vent, IDC_EDIT1);
					 SetWindowText(Motivo, "");

					 HWND Listbox_infoCITA = GetDlgItem(vent, IDC_LIST1);

					 while (SendMessage(Listbox_infoCITA, LB_GETCOUNT, NULL, NULL) != NULL) {

						 SendMessage(Listbox_infoCITA, LB_DELETESTRING, NULL, NULL);

					 }

					 HWND Combobox_ID = GetDlgItem(vent, IDC_COMBO1);

					 char* temporal_IDCITA = new char[10];
					 int cursel = SendMessage(Combobox_ID, CB_GETCURSEL, NULL, NULL); //Vemos la posicion de donde clickó en la lista
					 SendMessage(Combobox_ID, CB_GETLBTEXT, cursel, (LPARAM)temporal_IDCITA);

					 int ID_de_cita = Busqueda_BINARIA(vent, &temporal_IDCITA);

					 auxC = origenC;

					 while (auxC != NULL) {

						 if (auxC->ID_c == ID_de_cita) { //Si el ID  de la cita coincide

							 HWND hbtn_Cancelada = GetDlgItem(vent, IDC_BUTTON1);
							 HWND hbtn_Realizada = GetDlgItem(vent, IDC_BUTTON2);
							 EnableWindow(hbtn_Cancelada, true);
							 EnableWindow(hbtn_Realizada, true);
							 
							 SendMessage(Listbox_infoCITA, LB_INSERTSTRING, 0, (LPARAM)auxC->Paciente);
							 SendMessage(Listbox_infoCITA, LB_INSERTSTRING, 0, (LPARAM)"Paciente");
							 SendMessage(Listbox_infoCITA, LB_INSERTSTRING, 0, (LPARAM)"");

							 SendMessage(Listbox_infoCITA, LB_INSERTSTRING, 0, (LPARAM)auxC->Consultorio);
							 SendMessage(Listbox_infoCITA, LB_INSERTSTRING, 0, (LPARAM)"Consultorio");
							 SendMessage(Listbox_infoCITA, LB_INSERTSTRING, 0, (LPARAM)"");

							 SendMessage(Listbox_infoCITA, LB_INSERTSTRING, 0, (LPARAM)auxC->Hora);
							 SendMessage(Listbox_infoCITA, LB_INSERTSTRING, 0, (LPARAM)"Hora");
							 SendMessage(Listbox_infoCITA, LB_INSERTSTRING, 0, (LPARAM)"");

							 SendMessage(Listbox_infoCITA, LB_INSERTSTRING, 0, (LPARAM)auxC->Especialidad);
							 SendMessage(Listbox_infoCITA, LB_INSERTSTRING, 0, (LPARAM)"Especialidad del doctor");
							 SendMessage(Listbox_infoCITA, LB_INSERTSTRING, 0, (LPARAM)"");

							 SendMessage(Listbox_infoCITA, LB_INSERTSTRING, 0, (LPARAM)auxC->Doctor);
							 SendMessage(Listbox_infoCITA, LB_INSERTSTRING, 0, (LPARAM)"Doctor");
							 SendMessage(Listbox_infoCITA, LB_INSERTSTRING, 0, (LPARAM)"");
							
							 SendMessage(Listbox_infoCITA, LB_INSERTSTRING, 0, (LPARAM)auxC->Fecha);
							 SendMessage(Listbox_infoCITA, LB_INSERTSTRING, 0, (LPARAM)"Fecha");
							 SendMessage(Listbox_infoCITA, LB_INSERTSTRING, 0, (LPARAM)"");

							 if (auxC->Estado_de_cita == 2) {
								 HWND CANCELADO = GetDlgItem(vent, IDC_Estadodecita);
								 SetWindowText(CANCELADO, "Cita CANCELADA");
							 }
							 else if (auxC->Estado_de_cita == 1) {

									 HWND CANCELADO = GetDlgItem(vent, IDC_Estadodecita);
									 SetWindowText(CANCELADO, "Cita Realizada");
							 }
							 else if (auxC->Estado_de_cita == 0) {

								 HWND CANCELADO = GetDlgItem(vent, IDC_Estadodecita);
								 SetWindowText(CANCELADO, "Cita en espera");
							 }


							 Doctor* arr = arbol->Arreglo_del_arbol();//En un arreglo ponemos a los doctores
							 int indice;

							 for (indice = 0; indice < Doctor::cantidad_de_doctores; indice++) {

								 if (strcmp(auxC->Doctor, arr[indice].Nombre) == 0) {
									 break;
								 }

							 }

							 HBITMAP fotoDOC = (HBITMAP)LoadImage(NULL, arr[indice].DirFileDoc, IMAGE_BITMAP, 120, 120, LR_LOADFROMFILE);
							 HWND ID_DOC = GetDlgItem(vent, IDC_FOTO);
							 SendMessage(ID_DOC, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)fotoDOC);
						

							 break;
						 }
						 auxC = auxC->nextC;
					 }
					 

			 }

			 if (LOWORD(wParam) == IDC_BUTTON1 && HIWORD(wParam) == BN_CLICKED) { //Boton CANCELADA

				 //Primero verificaremos si el editcontrol tiene algo
				 char Motivo[60];
				 HWND EditBOX_Motivodecancelacion = GetDlgItem(vent, IDC_EDIT1);
				 int longitud_Motivo = GetWindowTextLength(EditBOX_Motivodecancelacion); //Sacamos la longitud
				 GetWindowText(EditBOX_Motivodecancelacion, Motivo, longitud_Motivo + 1);

				 if (strcmp(Motivo, "") == 0) { //Si la cadena no tiene nada

					 MessageBox(vent, "Agregue el motivo de la cancelacion", "Atencion", MB_OK);

				 }
				 else {

					 HWND Combobox_ID = GetDlgItem(vent, IDC_COMBO1);

					 char* temporal_IDCITA = new char[10];
					 int cursel = SendMessage(Combobox_ID, CB_GETCURSEL, NULL, NULL); //Vemos la posicion de donde clickó en la lista
					 SendMessage(Combobox_ID, CB_GETLBTEXT, cursel, (LPARAM)temporal_IDCITA);

					 auxC = origenC;

					 while (auxC != NULL) {

						 if (auxC->ID_c == atoi(temporal_IDCITA)) {

							 auxC->Estado_de_cita = 2;
							 strcpy(auxC->Motivo_cancelacion, Motivo);

							 MessageBox(vent, "Cita en estado CANCELADO", "Aviso", MB_OK);
							 break;
						 }
						 auxC = auxC->nextC;
					 }

				 }

				

			 }

			 if (LOWORD(wParam) == IDC_BUTTON2 && HIWORD(wParam) == BN_CLICKED) { //Boton REALIZADA

				 HWND Combobox_ID = GetDlgItem(vent, IDC_COMBO1);

				 char* temporal_IDCITA = new char[10];
				 int cursel = SendMessage(Combobox_ID, CB_GETCURSEL, NULL, NULL); //Vemos la posicion de donde clickó en la lista
				 SendMessage(Combobox_ID, CB_GETLBTEXT, cursel, (LPARAM)temporal_IDCITA);

				 auxC = origenC;

				 while (auxC != NULL) {

					 if (auxC->ID_c == atoi(temporal_IDCITA)) {
						 auxC->Estado_de_cita = 1;
						 MessageBox(vent, "Cita en estado Realizado", "Aviso", MB_OK);
						 break;
					 }
					 auxC = auxC->nextC;
				 }

			 }


		}

				   break;

		case WM_DESTROY:
			break;

		default:
			break;
	}

	return FALSE;

}

BOOL CALLBACK FuncionVentanaConsultaCITASDOCTORmes(HWND vent, UINT mensaje, WPARAM wParam, LPARAM lParam) {

	switch (mensaje)
	{
		case WM_INITDIALOG: {

			aux = origen;

			HWND hComboBox_MES = GetDlgItem(vent, IDC_COMBO1);
			HWND hComboBox_DOCTOR = GetDlgItem(vent, IDC_COMBO2);

			HWND hACEPTAR = GetDlgItem(vent, IDOK);
			EnableWindow(hACEPTAR, false);

			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"enero");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"febrero");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"marzo");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"abril");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"mayo");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"junio");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"julio");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"agosto");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"septiembre");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"octubre");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"noviembre");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"diciembre");


			Doctor* arr = arbol->Arreglo_del_arbol();//En un arreglo ponemos a los doctores
			int indice;

			for (indice = 0; indice < Doctor::cantidad_de_doctores; indice++) {

				SendMessage(hComboBox_DOCTOR, CB_ADDSTRING, 0, (LPARAM)arr[indice].Cedula);

			}

			delete arr;

		}
						  break;

	case WM_COMMAND: {

		if (LOWORD(wParam) == IDC_COMBO1 && HIWORD(wParam) == CBN_SELENDOK ||
			LOWORD(wParam) == IDC_COMBO2 && HIWORD(wParam) == CBN_SELENDOK) {

			HWND btn_ACEPTAR = GetDlgItem(vent, IDOK);

			EnableWindow(btn_ACEPTAR, true);

			HWND CB_DOCTOR = GetDlgItem(vent, IDC_COMBO2); //Doctor
			HWND NOMBRE = GetDlgItem(vent, IDC_Doctor);
			
			char* temporal_Doctor = new char[30];

			int cursel_doctor = SendMessage(CB_DOCTOR, CB_GETCURSEL, NULL, NULL); //Vemos la posicion de donde clickó en la lista

			SendMessage(CB_DOCTOR, CB_GETLBTEXT, cursel_doctor, (LPARAM)temporal_Doctor);

			Doctor* arr = arbol->Arreglo_del_arbol();//En un arreglo ponemos a los doctores

			for (int i = 0; i < Doctor::cantidad_de_doctores; i++) {

				if (strcmp(arr[i].Cedula, temporal_Doctor) == 0) {

					SetWindowText(NOMBRE, arr[i].Nombre);

				}

			}


		}

		else if (LOWORD(wParam) == IDOK && HIWORD(wParam) == BN_CLICKED) {

			HWND CB_MES = GetDlgItem(vent, IDC_COMBO1); //MES
			HWND CB_DOCTOR = GetDlgItem(vent, IDC_COMBO2); //Doctor
			HWND NOMBRE = GetDlgItem(vent, IDC_Doctor);

			char* temporal_MES = new char[30];
			char* temporal_Doctor = new char[30];
			

			int cursel_mes = SendMessage(CB_MES, CB_GETCURSEL, NULL, NULL); //Vemos la posicion de donde clickó en la lista
			int cursel_doctor = SendMessage(CB_DOCTOR, CB_GETCURSEL, NULL, NULL); //Vemos la posicion de donde clickó en la lista

			SendMessage(CB_MES, CB_GETLBTEXT, cursel_mes, (LPARAM)temporal_MES);
			SendMessage(CB_DOCTOR, CB_GETLBTEXT, cursel_doctor, (LPARAM)temporal_Doctor);

			

			string s_MES = temporal_MES; //Lo pasamos a un string para poder compararlo en la funcion

			if (ConsultaporMES(vent, s_MES, &temporal_Doctor) == true) {
				MessageBox(vent, "El archivo de la consulta por MES se ha guardado", "Exito", MB_OK);
			}
			else {
				MessageBox(vent, "El archivo de la consulta por MES NO se ha guardado", "Error", MB_OK);
			}

			hVentanaCONSULTAcitas_MEDICOS_mes = NULL;

			DestroyWindow(vent);
			ShowWindow(hVentanaPRINCIPAL, SW_SHOW);

		}

		else if (LOWORD(wParam) == IDCANCEL && HIWORD(wParam) == BN_CLICKED) {


			hVentanaCONSULTAcitas_MEDICOS_mes = NULL;

			DestroyWindow(vent);
			ShowWindow(hVentanaPRINCIPAL, SW_SHOW);

		}

	}

				   break;

	case WM_DESTROY:
		break;

	default:
		break;
	}

	return FALSE;

}

BOOL CALLBACK FuncionVentanaConsultaCITASespecialidadSEMANA(HWND vent, UINT mensaje, WPARAM wParam, LPARAM lParam) {

	switch (mensaje)
	{
		case WM_INITDIALOG: {

			aux = origen;

			HWND hComboBox_MES = GetDlgItem(vent, IDC_COMBO1);
			HWND hComboBox_SEMANA = GetDlgItem(vent, IDC_COMBO2);
			HWND hCombobox_especialidad = GetDlgItem(vent, IDC_COMBO3);

			HWND hACEPTAR = GetDlgItem(vent, IDOK);
			EnableWindow(hACEPTAR, false);

			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"enero");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"febrero");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"marzo");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"abril");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"mayo");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"junio");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"julio");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"agosto");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"septiembre");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"octubre");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"noviembre");
			SendMessage(hComboBox_MES, CB_INSERTSTRING, 0, (LPARAM)"diciembre");

			SendMessage(hComboBox_SEMANA, CB_INSERTSTRING, 0, (LPARAM)"1");
			SendMessage(hComboBox_SEMANA, CB_INSERTSTRING, 0, (LPARAM)"2");
			SendMessage(hComboBox_SEMANA, CB_INSERTSTRING, 0, (LPARAM)"3");
			SendMessage(hComboBox_SEMANA, CB_INSERTSTRING, 0, (LPARAM)"4");
			SendMessage(hComboBox_SEMANA, CB_INSERTSTRING, 0, (LPARAM)"5");

			aux_esp = origen_esp;

			while (aux_esp != NULL) {

				SendMessage(hCombobox_especialidad, CB_INSERTSTRING, 0, (LPARAM)aux_esp->especialidad);
				aux_esp = aux_esp->next_esp;
			}


		}
					  break;

	case WM_COMMAND: {

		if (LOWORD(wParam) == IDC_COMBO1 && HIWORD(wParam) == CBN_SELENDOK ||
			LOWORD(wParam) == IDC_COMBO2 && HIWORD(wParam) == CBN_SELENDOK) {

			HWND CB_ESPECIALIDAD = GetDlgItem(vent, IDC_COMBO3);
			HWND btn_Aceptar = GetDlgItem(vent, IDOK);

			EnableWindow(CB_ESPECIALIDAD, true);
			EnableWindow(btn_Aceptar, true);


		}

		else if (LOWORD(wParam) == IDOK && HIWORD(wParam) == BN_CLICKED) {

			HWND CB_MES = GetDlgItem(vent, IDC_COMBO1); //MES
			HWND CB_Semana = GetDlgItem(vent, IDC_COMBO2); //Semana
			HWND CB_ESPECIALIDAD = GetDlgItem(vent, IDC_COMBO3);

			char* temporal_MES = new char[30];
			char* temporal_Semana = new char[30];
			char* temporal_Especialidad = new char[30];


			int cursel_mes = SendMessage(CB_MES, CB_GETCURSEL, NULL, NULL); //Vemos la posicion de donde clickó en la lista
			int cursel_semana = SendMessage(CB_Semana, CB_GETCURSEL, NULL, NULL); //Vemos la posicion de donde clickó en la lista
			int cursel_ESPECIALIDAD = SendMessage(CB_ESPECIALIDAD, CB_GETCURSEL, NULL, NULL); //Vemos la posicion de donde clickó en la lista

			SendMessage(CB_MES, CB_GETLBTEXT, cursel_mes, (LPARAM)temporal_MES);
			SendMessage(CB_Semana, CB_GETLBTEXT, cursel_semana, (LPARAM)temporal_Semana);
			SendMessage(CB_ESPECIALIDAD, CB_GETLBTEXT, cursel_ESPECIALIDAD, (LPARAM)temporal_Especialidad);

			string s_MES = temporal_MES; //Lo pasamos a un string para poder compararlo en la funcion
			

			if (ConsultaporsemanayESPECIALIDAD(vent, s_MES, &temporal_Semana, &temporal_Especialidad) == true) {
				MessageBox(vent, "El archivo de la consulta por SEMANA se ha guardado", "Exito", MB_OK);

				delete temporal_MES;
				delete temporal_Semana;
				delete temporal_Especialidad;

			}
			else {
				MessageBox(vent, "El archivo de la consulta por SEMANA NO se ha guardado", "Error", MB_OK);
			}


		}

		else if (LOWORD(wParam) == IDCANCEL && HIWORD(wParam) == BN_CLICKED) {


			hVentanaCONSULTAcitas_especialidad_semana = NULL;

			DestroyWindow(vent);
			ShowWindow(hVentanaPRINCIPAL, SW_SHOW);

		}

	}

				   break;

	case WM_DESTROY:
		break;

	default:
		break;
	}

	return FALSE;

}

BOOL CALLBACK FuncionVentanaBUSCARmedicos(HWND vent, UINT mensaje, WPARAM wParam, LPARAM lParam) {

	switch (mensaje)
	{
		case WM_INITDIALOG: {

			strcpy(chDireccionDOC , "");
			HWND Combobox_CEDULA = GetDlgItem(vent, IDC_Cedula);

			if (Doctor::cantidad_de_doctores>0) {
				Doctor* arr = arbol->Arreglo_del_arbol();//En un arreglo ponemos a los doctores
				int indice;

				for (indice = 0; indice < Doctor::cantidad_de_doctores; indice++) {

					SendMessage(Combobox_CEDULA, CB_ADDSTRING, 0, (LPARAM)arr[indice].Cedula);

				}
				
				delete arr;
			}

			HWND hNOMBRE = GetDlgItem(vent, IDC_EDIT2); EnableWindow(hNOMBRE, false);
			HWND hAPELLIDOS = GetDlgItem(vent, IDC_APELLIDOS); EnableWindow(hAPELLIDOS, false);
			HWND hCONSULTORIO = GetDlgItem(vent, IDC_Consultorio); EnableWindow(hCONSULTORIO, false);
			HWND hCELULAR = GetDlgItem(vent, IDC_NumCel); EnableWindow(hCELULAR, false);
			HWND hESPECIALIDAD = GetDlgItem(vent, IDC_Especialidad); EnableWindow(hESPECIALIDAD, false);
			HWND btnFOTO = GetDlgItem(vent, IDC_BUTTON1); EnableWindow(btnFOTO, false);
			HWND Combobox_LUNES = GetDlgItem(vent, IDC_E1); EnableWindow(Combobox_LUNES, false);
			HWND Combobox_MARTES = GetDlgItem(vent, IDC_E2); EnableWindow(Combobox_MARTES, false);
			HWND Combobox_MIERCOLES = GetDlgItem(vent, IDC_E3); EnableWindow(Combobox_MIERCOLES, false);
			HWND Combobox_JUEVES = GetDlgItem(vent, IDC_E4); EnableWindow(Combobox_JUEVES, false);
			HWND Combobox_VIERNES = GetDlgItem(vent, IDC_E5); EnableWindow(Combobox_VIERNES, false);
			HWND BTNAceptar = GetDlgItem(vent, IDOK2); EnableWindow(BTNAceptar, false);
			HWND BTNEliminar = GetDlgItem(vent, IDC_BUTTON3); EnableWindow(BTNEliminar, false);

		}

		case WM_COMMAND: {

			if (LOWORD(wParam) == IDC_BUTTON1 && HIWORD(wParam) == BN_CLICKED) { //AGREGAR FOTO


				OPENFILENAME ofn; //ESTRUCTURA 
				ZeroMemory(&ofn, sizeof(ofn));


				ofn.hwndOwner = vent;
				ofn.lStructSize = sizeof(ofn);
				ofn.lpstrFile = chDireccionDOC;
				ofn.nMaxFile = MAX_PATH;
				ofn.lpstrDefExt = "txt";
				ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_NOCHANGEDIR;
				ofn.lpstrFilter = "Text Files\0*.txt\0All Files\0*.*\0";

				if (GetOpenFileName(&ofn)) { //Nos regresara un valor verdadero al elegir una imagen y dar en aceptar

					himagen = GetDlgItem(vent, IDC_FOTO);
					hBitmap = (HBITMAP)LoadImage(NULL, chDireccionDOC, IMAGE_BITMAP, 150, 150, LR_LOADFROMFILE);
					SendMessage(himagen, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap);
					fotoagregada = true;

				}

			}


			if (LOWORD(wParam) == IDOK2 && HIWORD(wParam) == BN_CLICKED) { //ACEPTAR

				int Validacion;

				Validacion = Validar_MEDICOS(vent,2);

				if (Validacion == -1) {

					break;

				}
				else if (Validacion == 0) {

					MessageBox(vent, "Por favor rellene los espacios vacios", "Atencion", MB_OK);
					break;
				}
				else if (Validacion == 1 || Validacion == 5) {

					MessageBox(hVentanaREGISTROcitas, "Doctor Registrado", "Exito", MB_OK);

					DestroyWindow(vent);
					hVentanaBUSCARmedicos = NULL; //El puntero va a apuntar a NULO
					ShowWindow(hVentanaPRINCIPAL, SW_SHOW);

				}

				


			}

			else if (LOWORD(wParam) == IDC_Cedula && HIWORD(wParam) == CBN_SELENDOK) { //Combobox ESPECIALIDAD

				HWND hNOMBRE = GetDlgItem(vent, IDC_EDIT2); EnableWindow(hNOMBRE, true);
				HWND hAPELLIDOS = GetDlgItem(vent, IDC_APELLIDOS); EnableWindow(hAPELLIDOS, true);
				HWND hCONSULTORIO = GetDlgItem(vent, IDC_Consultorio); EnableWindow(hCONSULTORIO, true);
				HWND hCELULAR = GetDlgItem(vent, IDC_NumCel); EnableWindow(hCELULAR, true);
				HWND hESPECIALIDAD = GetDlgItem(vent, IDC_Especialidad); EnableWindow(hESPECIALIDAD, true);
				HWND btnFOTO = GetDlgItem(vent, IDC_BUTTON1); EnableWindow(btnFOTO, true);
				HWND Combobox_LUNES = GetDlgItem(vent, IDC_E1); EnableWindow(Combobox_LUNES, true);
				HWND Combobox_MARTES = GetDlgItem(vent, IDC_E2); EnableWindow(Combobox_MARTES, true);
				HWND Combobox_MIERCOLES = GetDlgItem(vent, IDC_E3); EnableWindow(Combobox_MIERCOLES, true);
				HWND Combobox_JUEVES = GetDlgItem(vent, IDC_E4); EnableWindow(Combobox_JUEVES, true);
				HWND Combobox_VIERNES = GetDlgItem(vent, IDC_E5); EnableWindow(Combobox_VIERNES, true);
				HWND BTNAceptar = GetDlgItem(vent, IDOK2); EnableWindow(BTNAceptar, true);
				HWND BTNEliminar = GetDlgItem(vent, IDC_BUTTON3); EnableWindow(BTNEliminar, true);

				HWND hCombobox_CEDULA = GetDlgItem(vent, IDC_Cedula);
				char* temporal_CEDULA = new char[15];
				int cursel = SendMessage(hCombobox_CEDULA, CB_GETCURSEL, NULL, NULL); //Vemos la posicion de donde clickó en la lista
				SendMessage(hCombobox_CEDULA, CB_GETLBTEXT, cursel, (LPARAM)temporal_CEDULA);

				Doctor* arr = arbol->Arreglo_del_arbol();//En un arreglo ponemos a los doctores
				int indice;

				for (indice = 0; indice < Doctor::cantidad_de_doctores; indice++) {

					if (strcmp(arr[indice].Cedula, temporal_CEDULA) == 0 ) {

						

						HWND hComboConsultorio;
						hComboConsultorio = GetDlgItem(vent, IDC_Consultorio);
						while (SendMessage(hComboConsultorio, CB_GETCOUNT, NULL, NULL) != NULL) {
							SendMessage(hComboConsultorio, CB_DELETESTRING, NULL, NULL);
						}

						
						SendMessage(hComboConsultorio, CB_ADDSTRING, 0, (LPARAM)"1");
						SendMessage(hComboConsultorio, CB_ADDSTRING, 0, (LPARAM)"2");
						SendMessage(hComboConsultorio, CB_ADDSTRING, 0, (LPARAM)"3");
						SendMessage(hComboConsultorio, CB_SETCURSEL, 0, NULL);

						//ENTRADA
#pragma region COMBOBOX
						HWND hCombo1;
						hCombo1 = GetDlgItem(vent, IDC_E1);

						while (SendMessage(hCombo1, CB_GETCOUNT, NULL, NULL) != NULL) {
							SendMessage(hCombo1, CB_DELETESTRING, NULL, NULL);
						}

						SendMessage(hCombo1, CB_ADDSTRING, 0, (LPARAM)"LIBRE");//Lista desplegable 
						SendMessage(hCombo1, CB_ADDSTRING, 0, (LPARAM)H.h1);
						SendMessage(hCombo1, CB_ADDSTRING, 0, (LPARAM)H.h2);
						SendMessage(hCombo1, CB_ADDSTRING, 0, (LPARAM)H.h3);
						SendMessage(hCombo1, CB_ADDSTRING, 0, (LPARAM)H.h4);
						SendMessage(hCombo1, CB_SETCURSEL, 0, NULL);

						HWND hCombo2;
						hCombo2 = GetDlgItem(vent, IDC_E2);

						while (SendMessage(hCombo2, CB_GETCOUNT, NULL, NULL) != NULL) {
							SendMessage(hCombo2, CB_DELETESTRING, NULL, NULL);
						}

						SendMessage(hCombo2, CB_ADDSTRING, 0, (LPARAM)"LIBRE");//Lista desplegable 
						SendMessage(hCombo2, CB_ADDSTRING, 0, (LPARAM)H.h1);
						SendMessage(hCombo2, CB_ADDSTRING, 0, (LPARAM)H.h2);
						SendMessage(hCombo2, CB_ADDSTRING, 0, (LPARAM)H.h3);
						SendMessage(hCombo2, CB_ADDSTRING, 0, (LPARAM)H.h4);
						SendMessage(hCombo2, CB_SETCURSEL, 0, NULL);

						HWND hCombo3;
						hCombo3 = GetDlgItem(vent, IDC_E3);

						while (SendMessage(hCombo3, CB_GETCOUNT, NULL, NULL) != NULL) {
							SendMessage(hCombo3, CB_DELETESTRING, NULL, NULL);
						}

						SendMessage(hCombo3, CB_ADDSTRING, 0, (LPARAM)"LIBRE");//Lista desplegable 
						SendMessage(hCombo3, CB_ADDSTRING, 0, (LPARAM)H.h1);
						SendMessage(hCombo3, CB_ADDSTRING, 0, (LPARAM)H.h2);
						SendMessage(hCombo3, CB_ADDSTRING, 0, (LPARAM)H.h3);
						SendMessage(hCombo3, CB_ADDSTRING, 0, (LPARAM)H.h4);
						SendMessage(hCombo3, CB_SETCURSEL, 0, NULL);

						HWND hCombo4;
						hCombo4 = GetDlgItem(vent, IDC_E4);

						while (SendMessage(hCombo4, CB_GETCOUNT, NULL, NULL) != NULL) {
							SendMessage(hCombo4, CB_DELETESTRING, NULL, NULL);
						}

						SendMessage(hCombo4, CB_ADDSTRING, 0, (LPARAM)"LIBRE");//Lista desplegable 
						SendMessage(hCombo4, CB_ADDSTRING, 0, (LPARAM)H.h1);
						SendMessage(hCombo4, CB_ADDSTRING, 0, (LPARAM)H.h2);
						SendMessage(hCombo4, CB_ADDSTRING, 0, (LPARAM)H.h3);
						SendMessage(hCombo4, CB_ADDSTRING, 0, (LPARAM)H.h4);
						SendMessage(hCombo4, CB_SETCURSEL, 0, NULL);

						HWND hCombo5;
						hCombo5 = GetDlgItem(vent, IDC_E5);

						while (SendMessage(hCombo5, CB_GETCOUNT, NULL, NULL) != NULL) {
							SendMessage(hCombo5, CB_DELETESTRING, NULL, NULL);
						}

						SendMessage(hCombo5, CB_ADDSTRING, 0, (LPARAM)"LIBRE");//Lista desplegable 
						SendMessage(hCombo5, CB_ADDSTRING, 0, (LPARAM)H.h1);
						SendMessage(hCombo5, CB_ADDSTRING, 0, (LPARAM)H.h2);
						SendMessage(hCombo5, CB_ADDSTRING, 0, (LPARAM)H.h3);
						SendMessage(hCombo5, CB_ADDSTRING, 0, (LPARAM)H.h4);
						SendMessage(hCombo5, CB_SETCURSEL, 0, NULL);

						//Imprimimos los datos del doctor

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

						SetWindowText(hEditBoxNombreDoc, arr[indice].Nombre);
						SetWindowText(hEditBoxAPELLIDOS, arr[indice].Apellidos);
						SetWindowText(hEditBoxNumero_consultorio, arr[indice].Consultorio);
						SetWindowText(hEditBoxNumero_celular, arr[indice].Celular);


						HWND ListBox_Especialidades = GetDlgItem(vent, IDC_Especialidad);

						while (SendMessage(ListBox_Especialidades, CB_GETCOUNT, NULL, NULL) != NULL) {
							SendMessage(ListBox_Especialidades, CB_DELETESTRING, NULL, NULL);
						}

						aux_esp = origen_esp;

						while (aux_esp != NULL) {

							SendMessage(ListBox_Especialidades, CB_ADDSTRING, 0, (LPARAM)aux_esp->especialidad);
							aux_esp = aux_esp->next_esp;
						}
						SetWindowText(hEditBoxEspecialidad, arr[indice].Especialidad);

						SetWindowText(hEditBoxLunes, arr[indice].Lunes);
						SetWindowText(hEditBoxMartes, arr[indice].Martes);
						SetWindowText(hEditBoxMiercoles, arr[indice].Miercoles);
						SetWindowText(hEditBoxJueves, arr[indice].Jueves);
						SetWindowText(hEditBoxViernes, arr[indice].Viernes);



						HBITMAP fotoDOC = (HBITMAP)LoadImage(NULL, arr[indice].DirFileDoc, IMAGE_BITMAP, 120, 120, LR_LOADFROMFILE);
						HWND ID_DOC = GetDlgItem(vent, IDC_FOTO);
						SendMessage(ID_DOC, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)fotoDOC);

						delete temporal_CEDULA;
						delete arr;

						break;
					}

				}
				

				//delete arr;


			}


			else if (LOWORD(wParam) == IDCANCEL3 && HIWORD(wParam) == BN_CLICKED) { //CANCELAR

				hVentanaBUSCARmedicos = NULL;

				DestroyWindow(vent);
				ShowWindow(hVentanaPRINCIPAL, SW_SHOW);

			}

			else if (LOWORD(wParam) == IDC_BUTTON3 && HIWORD(wParam) == BN_CLICKED) { //ELIMINAR NODOD

				HWND hCombobox_CEDULA = GetDlgItem(vent, IDC_Cedula);
				char* temporal_CEDULA = new char[15];
				int cursel = SendMessage(hCombobox_CEDULA, CB_GETCURSEL, NULL, NULL); //Vemos la posicion de donde clickó en la lista
				SendMessage(hCombobox_CEDULA, CB_GETLBTEXT, cursel, (LPARAM)temporal_CEDULA);

				arbol->ELIMINAR(arbol->raiz, atoi(temporal_CEDULA));

				MessageBox(vent, "Doctor eliminado", "Aviso", MB_OK);

				hVentanaBUSCARmedicos = NULL;

				DestroyWindow(vent);
				ShowWindow(hVentanaPRINCIPAL, SW_SHOW);

			}

		}
				   break;

		case WM_DESTROY:
			break;

		default:
			break;
	}

	return FALSE;

}






#include "Funciones.h"