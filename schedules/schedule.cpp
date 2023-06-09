#include <iostream>
#include <stdio.h>
#include <string.h>
#include "auxiliarsche.h"
#include "structuraSche.h"
#define MAX 100
using namespace std;

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
Colectivo BuscaBus(int pos);
int hayBus(char num1[]);
/*Delete*/
void deleteSchedule(int pos);
/*Statsbus*/
void startSchedule(int pos);
/*Show*/
void showSchedule(int pos);
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

Colectivo BuscaBus(int pos)
{
    return Buses[pos];
}

int hayBus(char num1[])
{
    int posicion1 = 0;
    for (int i = 0; i < lastRegBus; i++)
    {
        if (strcmp(num1, Buses[i].busId) == 0)
        {
            posicion1 = i;
            break;
        }
    }
    return posicion1;
}

void deleteSchedule(int pos)
{
    if (pos == lastRegSche)
    {
        gotoxy2(60, 5);
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
    gotoxy2(60, 5);
    cout << "Horario Id #: " << Calendar[pos].horarioId << endl;
    gotoxy2(60, 6);
    cout << "Bus David #: " << Calendar[pos].busId << endl;
    gotoxy2(60, 7);
    cout << "Origen: " << Calendar[pos].origen << endl;
    gotoxy2(60, 8);
    cout << "Destino: " << Calendar[pos].destino << endl;
    gotoxy2(60, 9);
    cout << "Hora Salida: " << Calendar[pos].hora_origen << endl;
    gotoxy2(60, 10);
    cout << "Hora Llegada: " << Calendar[pos].hora_destino << endl;
}

int MenuSchedule()
{
    int op;

    gotoxy2(60, 5);
    cout << " Itinerario - Transporte David\n";
    gotoxy2(60, 6);
    cout << "Cantidad de registros: " << lastRegSche << endl;
    gotoxy2(60, 9);
    cout << " 1. Agregar Horario";
    gotoxy2(60, 10);
    cout << " 2. Editar Horario \n";
    gotoxy2(60, 11);
    cout << " 3. Eliminar Horario \n";
    gotoxy2(60, 12);
    cout << " 4. Mostrar Horario \n";
    gotoxy2(60, 13);
    cout << " 5. Salir \n";
    gotoxy2(60, 16);
    cout << " Digite la opcion: ";
    gotoxy2(79, 16);
    cin >> op;
    return op;
}

void Schedule()
{
    int op, pos, resp;
    char scheid[5], busId[5];
    char *busNum;
    schedule Horario;
    Colectivo bus;
    readSchedule();
    do
    {
        system("cls||clear");

        op = MenuSchedule();
        switch (op)
        {
        case 1:
            system("cls || clear");
            gotoxy2(60, 4);
            cout << "Escribe el # del Bus: ";
            cin >> busId;
            pos = hayBus(busId);
            bus = BuscaBus(pos);
            busNum = bus.busId;
            Horario.busId = busNum;
            gotoxy2(60, 5);
            cout << "Horario ID:";
            gotoxy2(60, 6);
            cout << "Bus David #: ";
            gotoxy2(60, 7);
            cout << "Origen: ";
            gotoxy2(60, 8);
            cout << "Destino: ";
            gotoxy2(60, 9);
            cout << "Hora Salida: ";
            gotoxy2(60, 10);
            cout << "Hora Llegada: ";
            gotoxy2(72, 5);
            scanf(" %[^\n]", Horario.horarioId);
            gotoxy2(75, 6);
            cout << Horario.busId;
            gotoxy2(68, 7);
            scanf(" %[^\n]", Horario.origen);
            gotoxy2(69, 8);
            scanf(" %[^\n]", Horario.destino);
            gotoxy2(73, 9);
            scanf(" %[^\n]", Horario.hora_origen);
            gotoxy2(74, 10);
            scanf(" %[^\n]", Horario.hora_destino);
            addSchedule(Horario);
            system("pause");
            break;

        case 2:
            system("cls||clear");
            gotoxy2(60, 4);
            cout << "Escribe el Id del Destino a buscar: ";
            scanf(" %[^\n]", scheid);
            pos = searchSchedule(scheid);
            showSchedule(pos);
            gotoxy2(60, 12);
            cout << "DATOS A EDITAR\n";
            gotoxy2(60, 13);
            cout << "Horario ID:";
            gotoxy2(60, 14);
            cout << "Bus David #: ";
            gotoxy2(60, 15);
            cout << "Origen: ";
            gotoxy2(60, 16);
            cout << "Destino: ";
            gotoxy2(60, 17);
            cout << "Hora Salida: ";
            gotoxy2(60, 18);
            cout << "Hora Llegada: ";
            gotoxy2(72, 13);
            scanf(" %[^\n]", Horario.horarioId);
            gotoxy2(73, 14);
            scanf(" %[^\n]", Horario.busId);
            gotoxy2(69, 15);
            scanf(" %[^\n]", Horario.origen);
            gotoxy2(69, 16);
            scanf(" %[^\n]", Horario.destino);
            gotoxy2(73, 17);
            scanf(" %[^\n]", Horario.hora_origen);
            gotoxy2(74, 18);
            scanf(" %[^\n]", Horario.hora_destino);
            editSchedule(Horario, pos);
            gotoxy2(60, 20);
            cout << "Registro actualizado...\n";
            system("pause");
            break;

        case 3:
            system("cls||clear");
            if (lastRegSche == 0)
            {
                gotoxy2(60, 5);
                cout << "No hay nada que eliminar\n";
                system("pause");
                break;
            }
            gotoxy2(60, 5);
            cout << "Escribe el Id del Horario: ";
            scanf(" %[^\n]", scheid);
            pos = searchSchedule(scheid);
            Horario = GetSchedule(pos);
            gotoxy2(60, 6);
            cout << "¿Realmente deseas eliminar el itinerario #" << Horario.horarioId << "?\n";
            gotoxy2(60, 7);
            cout << "Escribe 1 para SI o 2 para NO: ";
            gotoxy2(91, 7);
            cin >> resp;
            if (resp == 1)
            {
                deleteSchedule(pos);
                gotoxy2(60, 9);
                cout << "Registro Eliminado... \n";
            }
            else
            {
                gotoxy2(60, 9);
                cout << "Operaciòn cancelada.... \n";
            }
            system("pause");
            break;

        case 4:
            system("cls||clear");
            gotoxy2(60, 4);
            cout << "Escribe el # a buscar: ";
            scanf(" %[^\n]", scheid);
            pos = searchSchedule(scheid);
            showSchedule(pos);
            system("pause");
            break;
        case 5:
         break;
        }
    } while (op != 5);
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
    lastRegSche = calcUltRegSchedule(ScheduleRegistration);
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