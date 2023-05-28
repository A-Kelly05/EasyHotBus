#include <iostream>
<<<<<<< HEAD
#include <stdio.h>
#include <string.h>
#include "../auxiliar.h"
#include "../buses/bus.cpp"
#define MAX 100
using namespace std;

typedef struct
{
    char horarioId[5];
    char* busId;
    char origen[10];
    char destino[10];
    char hora_origen[5];
    char hora_destino[5];
}schedule;

schedule Calendar[MAX];
int lastRegSche = 0;

/*Agregar*/
void addSchedule(schedule Horario);
/*Editar*/
void editSchedule(schedule Horario, int pos);
/*Is Bus*/
int searchSchedule(char cale[]);
/*get Schedule*/
schedule GetSchedule(int pos);
/*Delete*/
void deleteSchedule(int pos);
/*Statsbus*/
void startSchedule(int pos);
/*Show*/
void showSchedule(int pos);
void showSchedules();
/*Menu*/
int MenuSchedule();
void Schedule();
/*File*/
FILE *ScheduleRegistration;
void saveSchedule();
void readSchedule();
int calcUltRegSchedule(FILE *archivo_Schedule);

void addSchedule(schedule Horario)
{
    Calendar[lastRegSche] = Horario;
    lastRegSche++;
}

void editSchedule(schedule Horario, int pos)
{
    Calendar[pos] = Horario;
}

int searchSchedule(char cale[])
{
    int posicion = 0;
    for (int i = 0; i < lastRegSche; i++)
    {
        if (strcmp(cale, Calendar[i].horarioId) == 0)
        {
            posicion = i;
            break;
        }
    }
    return posicion;
}

schedule GetSchedule(int pos)
{
    return Calendar[pos];
}

void deleteSchedule(int pos)
{
  if (pos == lastRegSche)
    {
        gotoxy(60, 5);
        cout << "No hay registro\n";
        return;
    }
    for (int i = pos; i < lastRegSche - 1; i++)
    {
        Calendar[i] = Calendar[i + 1];
    }
    lastRegSche--;
    startSchedule(lastRegSche);
}

void startSchedule(int pos)
{
    strcpy(Calendar[pos].horarioId, "");
    strcpy(Calendar[pos].busId, "");
    strcpy(Calendar[pos].origen, "");
    strcpy(Calendar[pos].destino, "");
    strcpy(Calendar[pos].hora_origen, "");
    strcpy(Calendar[pos].hora_destino, "");
}

void showSchedule(int pos)
{
    gotoxy(60, 5);
    cout << "Horario Id #: " << Calendar[pos].horarioId << endl;
    gotoxy(60, 6);
    cout << "Bus David #: " << Calendar[pos].busId<< endl;
    gotoxy(60, 7);
    cout << "Origen: " << Calendar[pos].origen<< endl;
    gotoxy(60, 8);
    cout << "Destino: " << Calendar[pos].destino << endl;
    gotoxy(60, 9);
    cout << "Hora Salida: " << Calendar[pos].hora_origen<< endl;
    gotoxy(60, 10);
    cout << "Hora Llegada: " << Calendar[pos].hora_destino<< endl;
}

void showSchedules()
{
    system("cls||clear");
    if (lastRegSche == 0)
    {
        gotoxy(60, 5);
        cout << "No hay registros\n";
        return;
    }
    for (int i = 0; i < lastRegSche; i++)
    {
        gotoxy(60, 4);
        cout << "=========================\n";
        showSchedule(i);
    }
    cout << "Ultimo registro...\n";
}

int MenuSchedule()
{
    int op;

    gotoxy(60, 5);
    cout << " Itinerario - Transporte David\n";
    gotoxy(71, 6);
    cout << "Cantidad de registros: " << lastRegSche << endl;
    gotoxy(60, 9);
    cout << " 1. Agregar Horario";
    gotoxy(60, 10);
    cout << " 2. Editar Horario \n";
    gotoxy(60, 11);
    cout << " 3. Eliminar Horario \n";
    gotoxy(60, 12);
    cout << " 4. Mostrar Horario \n";
    gotoxy(60, 13);
    cout << " 5. Mostrar todos los Horarios \n";
    gotoxy(60, 14);
    cout << " 6. Salir \n";
    gotoxy(60, 16);
    cout << " Digite la opcion: ";
    gotoxy(79, 16);
    cin >> op;
    return op;
}

void Schedule()
{
    int op, pos, resp;
    char ScheduleId[5], scheid[5], busId[5];
    char* busNum;
    schedule Horario;
     Bus bus;
    readSchedule();
    do
    {
        system("cls||clear");

        op = MenuSchedule();
        switch (op)
        {
        case 1:
            system("cls || clear");
            cout << "Escribe el # del Bus: ";
            cin >> busId;
            pos = isBus(busId);
            bus = getBus(pos);
            busNum = bus.busId;
            Horario.busId = busNum;
            gotoxy(60, 5);
            cout << "Horario ID:";
            gotoxy(60, 6);
            cout << "Bus David #: ";
            gotoxy(60, 7);
            cout << "Origen: ";
            gotoxy(60, 8);
            cout << "Destino: ";
            gotoxy(60, 9);
            cout << "Hora Salida: ";
            gotoxy(60, 10);
            cout << "Hora Llegada: ";
            gotoxy(73, 5);
            scanf(" %[^\n]", Horario.horarioId);
            gotoxy(75, 6);
            cout << Horario.busId;
            gotoxy(69, 7);
            scanf(" %[^\n]", Horario.destino);
            gotoxy(70, 8);
            scanf(" %[^\n]", Horario.origen);
            gotoxy(74, 9);
            scanf(" %[^\n]", Horario.hora_origen);
            gotoxy(76, 10);
            scanf(" %[^\n]", Horario.hora_destino);
            addSchedule(Horario);
            system("pause");
            break;

        case 2:
            system("cls||clear");
            gotoxy(60, 4);
            cout << "Escribe el Id del Destino a buscar: ";
            scanf(" %[^\n]", scheid);
            pos = searchSchedule(scheid);
            showSchedule(pos);
            gotoxy(60, 12);
            cout << "DATOS A EDITAR\n";
            gotoxy(60, 13);
            cout << "Horario ID:";
            gotoxy(60, 14);
            cout << "Bus David #: ";
            gotoxy(60, 15);
            cout << "Origen: ";
            gotoxy(60, 16);
            cout << "Destino: ";
            gotoxy(60, 17);
            cout << "Hora Salida: ";
            gotoxy(60, 18);
            cout << "Hora Llegada: ";
            gotoxy(73, 13);
            scanf(" %[^\n]", Horario.horarioId);
            gotoxy(75, 14);
           scanf(" %[^\n]", Horario.busId);
            gotoxy(69, 15);
            scanf(" %[^\n]", Horario.destino);
            gotoxy(70, 16);
            scanf(" %[^\n]", Horario.origen);
            gotoxy(74, 17);
            scanf(" %[^\n]", Horario.hora_origen);
            gotoxy(76, 18);
            scanf(" %[^\n]", Horario.hora_destino);
            editSchedule(Horario, pos);
            gotoxy(60, 20);
            cout << "Registro actualizado...\n";
            system("pause");
            break;

        case 3:
            system("cls||clear");
            if (lastRegSche == 0)
            {
                gotoxy(60, 5);
                cout << "No hay nada que eliminar\n";
                system("pause");
                break;
            }
            gotoxy(60, 5);
            cout << "Escribe el Id del Horario: ";
            scanf(" %[^\n]", scheid);
            pos = searchSchedule(scheid);
            Horario = GetSchedule(pos);
            gotoxy(60, 6);
            cout << "¿Realmente deseas eliminar el itinerario #" << Horario.horarioId << "?\n";
            gotoxy(60, 7);
            cout << "Escribe 1 para SI o 2 para NO: ";
            gotoxy(91, 7);
            cin >> resp;
            if (resp == 1)
            {
                deleteSchedule(pos);
                gotoxy(60, 9);
                cout << "Registro Eliminado... \n";
            }
            else
            {
                gotoxy(60, 9);
                cout << "Operaciòn cancelada.... \n";
            }
            system("pause");
            break; 
        
        case 4:
             system("cls||clear");
            gotoxy(60, 5);
            cout << "Escribe el # a buscar: ";
            scanf(" %[^\n]", scheid);
            pos = searchSchedule(scheid);
            showSchedule(pos);
            system("pause");
            break;
        case 5:
          system("cls||clear");
            showSchedules();
            system("pause");
            break;
        
        }
    } while (op != 6);
    saveSchedule();

}

void saveSchedule()
{
    ScheduleRegistration = fopen("schedule.bin", "wb");
    fwrite(Calendar, sizeof(schedule), lastRegSche, ScheduleRegistration);
    fclose(ScheduleRegistration);
}

void readSchedule()
{
    ScheduleRegistration = fopen("schedule.bin", "rb");
    if (ScheduleRegistration == NULL)
    {
        return;
    }
    lastRegSche= calcUltRegSchedule(ScheduleRegistration);
    fread(Calendar, sizeof(schedule), MAX, ScheduleRegistration);

    fclose(ScheduleRegistration);
}

int calcUltRegSchedule(FILE *archivo_Schedule)
{
    int tam_archivo_shcedule, num_schedule;

    fseek(archivo_Schedule, 0, SEEK_END);
    tam_archivo_shcedule = ftell(archivo_Schedule);
    rewind(archivo_Schedule);

    num_schedule = tam_archivo_shcedule / sizeof(schedule);
    return num_schedule;
}

=======
#include <string.h>
#include <stdio.h>

struct horario
{
    char busId[20];
    char schedule[20];
};

horario horarios[100];
int numHorarios = 0;

void addHorario(const char* busId, const char* schedule){
    if(numHorarios < 100){
        strcpy(horarios[numHorarios].busId, busId);
        strcpy(horarios[numHorarios].schedule, schedule);
        numHorarios++;
        printf("Horario agregado correctamente\n\n");
    }
    else{
        printf("No se puede agregar mas horarios, Capacidad maxima alcanzada.\n\n");   
    }
}

void editHorario(int pos, const char* schedule){
    strcpy(horarios[pos].schedule, schedule);
    printf("Horario editado correctamente\n\n");
}

void mostrarHorario(int pos){
    printf("Horario #%d\n", pos + 1);
    printf("Bus: %s\n", horarios[pos].busId);
    printf("Horario: %s\n\n", horarios[pos].schedule);
}

void mostrarTodosLosHorarios(){
    if (numHorarios == 0){
        printf("No hay horarios registrados\n\n");
        return;
    }

    for (int i = 0; i < numHorarios; i++){
        mostrarHorario(i);
    }
}

void mostrarHorarioEspecifico(const char* busId)
{
    int encontrado = 0;
    for (int i = 0; i < numHorarios; i++){
        if (strcmp(horarios[i].busId, busId) == 0){
            mostrarHorario(i);
            encontrado = 1;
        }
    }

    if (!encontrado){
        printf("No se encontró el horario para el bus %s\n\n", busId);
    }
}

int menuHorario(){
    int opcion;
    printf("=== Menu Horario de Buses ===\n");
    printf("1. Agregar Horario\n");
    printf("2. Editar Horario\n");
    printf("3. Mostrar Horario Especifico\n");
    printf("4. Mostrar Todos los Horarios\n");
    printf("5. Salir\n");
    printf("Ingrese su opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

void menuPrincipal(){
    int opcion;
    char busId[20];
    char schedule[20];
    do{
        opcion = menuHorario();
        switch (opcion){
        case 1:
            printf("Agregar Horario\n");
            printf("Ingrese el ID del bus: ");
            scanf("%s", busId);
            printf("Ingrese el horario: ");
            scanf("%s", schedule);
            addHorario(busId, schedule);
            break;
        case 2:
            if (numHorarios == 0){
                printf("No hay horarios registrados\n\n");
                break;
            }
            printf("Editar Horario\n");
            printf("Ingrese el ID del bus: ");
            scanf("%s", busId);
            for (int i = 0; i < numHorarios; i++) {
                if (strcmp(horarios[i].busId, busId) == 0){
                printf("Ingrese el nuevo horario: ");
                    scanf("%s", schedule);
                    editHorario(i, schedule);
                    break;
                }
            }
            break;
        case 3:
            if (numHorarios == 0){
                printf("No hay horarios registrados\n\n");
                break;
            }
            printf("Mostrar Horario Especifico\n");
            printf("Ingrese el ID del bus: ");
            scanf("%s", busId);
            mostrarHorarioEspecifico(busId);
            break;
        case 4:
            printf("Mostrar Todos los Horarios\n");
            mostrarTodosLosHorarios();
            break;
        case 5:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opción no valida. Intente nuevamente.\n\n");
            break;
        }
    } while (opcion != 5);
}

int main(){
    menuPrincipal();
    return 0;
} 
>>>>>>> fe72c65323a2e253f8039234b3aa8eb50f38190f
