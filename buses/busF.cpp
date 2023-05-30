#include <iostream>
#include <stdio.h>
#include <string.h>
#include "../auxiliar.h"
#define MAX 100
using namespace std;

typedef struct {
    char busId[5];
    char busPlate[8];
    int busYear;
    int Capacity;
    char busmotor[50];
    char bustransmission[50];
    char busWheel[10];
    char busjobs[50];
    float busKM;
}Bus; 

Bus Buses[MAX];

int lastRegBus = 0;

/*Bus Regiter*/
/*Create*/
void addBus(Bus bus);
/*Read*/
void showBus(int pos);
int isBus(char id[]);
void showBuses();
void startBus(int pos);
Bus getBus(int pos);
/*Update*/
void updateBus(Bus bus, int pos);
/*Delete*/
void deleteBus(int pos);
/*Menu User*/
int menuBus();
void StartBuses();
/*Archivos User*/
FILE *BusesRegistration;
void saveBus();
void readBus();
int calcUltRegBus(FILE *archivo_bus);

/*Menu Archivo Principal*/
void menuPrincipal();
int principal();

void addBus(Bus bus)
{
    Buses[lastRegBus] = bus;
    lastRegBus++;
}

void showBus(int pos)
{
    gotoxy(60, 5);
    cout << "Bus David #: " << Buses[pos].busId << endl;
    gotoxy(60, 6);
    cout << "Placa: " << Buses[pos].busPlate << endl;
    gotoxy(60, 7);
    cout << "Año: " << Buses[pos].busYear << endl;
    gotoxy(60, 8);
    cout << "Capacidad: " << Buses[pos].Capacity << endl;
    gotoxy(60, 9);
    cout << "Motor: " << Buses[pos].busmotor << endl;
    gotoxy(60, 10);
    cout << "Trasmisión: " << Buses[pos].bustransmission << endl;
    gotoxy(60, 11);
    cout << "Model de Llantas: " << Buses[pos].busWheel << endl;
    gotoxy(60, 12);
    cout << "Trabajadores " << Buses[pos].busjobs << endl;
    gotoxy(60, 13);
    cout << "KM Recorridos " << Buses[pos].busKM << endl;
}

Bus obtBus(int pos)
{
    return Buses[pos];
}

int isBus(char num[])
{
    int posicion = 0;
    for (int i = 0; i < lastRegBus; i++)
    {
        if (strcmp(num, Buses[i].busId) == 0)
        {
            posicion = i;
            break;
        }
    }
    return posicion;
}

void showBuses()
{
    system("cls||clear");
    if (lastRegBus == 0)
    {
        gotoxy(60, 5);
        cout << "No hay registros\n";
        return;
    }
    for (int i = 0; i < lastRegBus; i++)
    {
        gotoxy(60, 4);
        cout << "=========================\n";
        showBus(i);
    }
    cout << "Ultimo registro...\n";
}

void updateBus(Bus bus, int pos)
{
    Buses[pos] = bus;
}

void deleteBus(int pos)
{
    if (pos == lastRegBus)
    {
        gotoxy(60, 5);
        cout << "No hay registro\n";
        return;
    }
    for (int i = pos; i < lastRegBus - 1; i++)
    {
        Buses[i] = Buses[i + 1];
    }
    lastRegBus--;
    startBus(lastRegBus);
}

void startBus(int pos)
{
    strcpy(Buses[pos].busId, "");
    strcpy(Buses[pos].busPlate, "");
    Buses[pos].busYear = 0;
    Buses[pos].Capacity = 0;
    strcpy(Buses[pos].busmotor, "");
    strcpy(Buses[pos].bustransmission, "");
    strcpy(Buses[pos].busWheel, "");
    strcpy(Buses[pos].busjobs, "");
    Buses[pos].busKM = 0.00;
}

int menuBus()
{
    int op;

    gotoxy(60, 5);
    cout << " Informacion administrativa - Transporte David\n";
    gotoxy(71, 6);
    cout << "Cantidad de registros: " << lastRegBus << endl;
    gotoxy(60, 9);
    cout << " 1. Agregar Informacion de Bus\n";
    gotoxy(60, 10);
    cout << " 2. Mantenimiento Bus \n";
    gotoxy(60, 11);
    cout << " 3. Editar Bus \n";
    gotoxy(60, 12);
    cout << " 4. Eliminar Bus \n";
    gotoxy(60, 13);
    cout << " 5. Buscar Bus \n";
    gotoxy(60, 14);
    cout << " 6. Mostrar todos los Buses \n";
    gotoxy(60, 15);
    cout << " 7. Salir \n";
    gotoxy(60, 16);
    cout << " Digite la opcion: ";
    gotoxy(79, 16);
    cin >> op;
    return op;
}

void StartBuses()
{
    int op, pos, resp;
    char busId[5];
    Bus bus;
    readBus();
    do
    {
        system("cls||clear");

        op = menuBus();
        switch (op)
        {
        case 1:
            system("cls || clear");
            gotoxy(60, 5);
            cout << "Bus David #:";
            gotoxy(60, 6);
            cout << "Placa: ";
            gotoxy(60, 7);
            cout << "Año: ";
            gotoxy(60, 8);
            cout << "Capacidad: ";
            gotoxy(60, 9);
            cout << "Motor: ";
            gotoxy(60, 10);
            cout << "Trasmision: ";
            gotoxy(60, 11);
            cout << "Modelo de Llantas: ";
            gotoxy(60, 12);
            cout << "Trabajadores: ";
            gotoxy(60, 13);
            cout << "KM Recorridos: ";
            gotoxy(73, 5);
            scanf(" %[^\n]", bus.busId);
            gotoxy(67, 6);
            scanf(" %[^\n]", bus.busPlate);
            gotoxy(65, 7);
            cin >> bus.busYear;
            gotoxy(71, 8);
            cin >> bus.Capacity;
            gotoxy(67, 9);
            scanf(" %[^\n]", bus.busmotor);
            gotoxy(72, 10);
            scanf(" %[^\n]", bus.bustransmission);
            gotoxy(79, 11);
            scanf(" %[^\n]", bus.busWheel);
            gotoxy(74, 12);
            scanf(" %[^\n]", bus.busjobs);
            gotoxy(75, 13);
            cin >> bus.busKM;
            addBus(bus);
            system("pause");

            break;

        case 2:
            system("cls||clear");
            gotoxy(71, 5);
            cout << "Mantenimiento de Bus\n";
            gotoxy(60, 7);
            cout << "Cambio de Aceite: 5000 kms\n";
            gotoxy(60, 8);
            cout << "Cambio de filtro de Aceite: 5000 kms\n";
            gotoxy(60, 9);
            cout << "Cambio de filtro de Combustible: 10000 kms\n";
            gotoxy(60, 10);
            cout << "Cambio de filtro de Aire: 40000 kms\n";
            gotoxy(60, 11);
            cout << "Engrase General: 2000 kms\n";
            gotoxy(60, 12);
            cout << "Engrase de Patentes: 40000 kms\n";
            gotoxy(60, 13);
            cout << "Ajuste de Embrague: 7200 kms\n";
            gotoxy(60, 14);
            cout << "Mantenimiento Sistema Eléctrico: 25000 kms\n";
            gotoxy(60, 15);
            cout << "Scanner al Sistema Electronico: 65000 kms\n";
            gotoxy(60, 16);
            cout << "Rotacion de Llantas: 30000 kms\n";
            gotoxy(60, 17);
            cout << "Cambio de Llantas: 75000 kms\n";
            gotoxy(60, 18);
            cout << "Revision de Niveles de Aceite de Diferencial: 14400 kms\n";
            gotoxy(60, 19);
            cout << "Revision de Niveles de Aceite de Caja/Transmision: 14400 kms\n";
            gotoxy(60, 20);
            cout << "Revision de Revisión de Yugos y Cruz Cardánica: 4000 kms\n";
            gotoxy(60, 21);
            cout << "Revision de Fricciones: 28800 kms\n";
            gotoxy(60, 22);
            cout << "Revision de Alineación y Balanceo: 57600 kms\n";
            gotoxy(60, 22);
            cout << "Revision de Imprevisto al Motor: 7200 kms\n";
            system("pause");
            break;

        case 3:
            system("cls||clear");
            gotoxy(60, 4);
            cout << "Escribe el # a buscar: ";
            scanf(" %[^\n]", busId);
            pos = isBus(busId);
            showBus(pos);
            gotoxy(60, 13);
            cout << "DATOS A EDITAR\n";
            gotoxy(60, 14);
            cout << "Bus David #:";
            gotoxy(60, 15);
            cout << "Placa: ";
            gotoxy(60, 16);
            cout << "Año: ";
            gotoxy(60, 17);
            cout << "Capacidad: ";
            gotoxy(60, 18);
            cout << "Motor: ";
            gotoxy(60, 19);
            cout << "Trasmision: ";
            gotoxy(60, 20);
            cout << "Modelo de Llantas: ";
            gotoxy(60, 21);
            cout << "Trabajadores: ";
            gotoxy(60, 22);
            cout << "KM Recorridos: ";
            gotoxy(73, 14);
            scanf(" %[^\n]", bus.busId);
            gotoxy(68, 15);
            scanf(" %[^\n]", bus.busPlate);
            gotoxy(65, 16);
            cin >> bus.busYear;
            gotoxy(71, 17);
            cin >> bus.Capacity;
            gotoxy(67, 18);
            scanf(" %[^\n]", bus.busmotor);
            gotoxy(72, 19);
            scanf(" %[^\n]", bus.bustransmission);
            gotoxy(79, 20);
            scanf(" %[^\n]", bus.busWheel);
            gotoxy(74, 21);
            scanf(" %[^\n]", bus.busjobs);
            gotoxy(75, 22);
            cin >> bus.busKM;
            updateBus(bus, pos);
            gotoxy(60, 23);
            cout << "Registro actualizado...\n";
            system("pause");
            break;
        case 4:
            system("cls||clear");
            if (lastRegBus == 0)
            {
                gotoxy(60, 5);
                cout << "No hay nada que eliminar\n";
                system("pause");
                break;
            }
            gotoxy(60, 5);
            cout << "Escribe el # del Bus: ";
            cin >> busId;
            pos = isBus(busId);
            bus = getBus(pos);
            gotoxy(60, 6);
            cout << "¿Realmente deseas eliminar el Bus #" << bus.busId << "?\n";
            gotoxy(60, 7);
            cout << "Escribe 1 para SI o 2 para NO: ";
            gotoxy(91, 7);
            cin >> resp;
            if (resp == 1)
            {
                deleteBus(pos);
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
        case 5:
            system("cls||clear");
            gotoxy(60, 5);
            cout << "Escribe el # a buscar: ";
            scanf(" %[^\n]", busId);
            pos = isBus(busId);
            showBus(pos);
            system("pause");
            break;
        case 6:
            system("cls||clear");
            showBuses();
            system("pause");
            break;
        case 7:
            break;
        default:
            system("clear||cls");
            cout << "Opcion invalida \n";
            system("pause");
            break;
        }
    } while (op != 7);
    saveBus();
}

void saveBus()
{
    BusesRegistration = fopen("datos.bin", "wb");
    fwrite(Buses, sizeof(Bus), lastRegBus, BusesRegistration);
    fclose(BusesRegistration);
}

void readBus()
{
    BusesRegistration = fopen("datos.bin", "rb");
    if (BusesRegistration == NULL)
    {
        return;
    }
    lastRegBus = calcUltRegBus(BusesRegistration);
    fread(Buses, sizeof(Bus), MAX, BusesRegistration);

    fclose(BusesRegistration);
}

int calcUltRegBus(FILE *archivo_bus)
{
    int tam_archivo_bus, num_Buses;

    fseek(archivo_bus, 0, SEEK_END);
    tam_archivo_bus = ftell(archivo_bus);
    rewind(archivo_bus);

    num_Buses = tam_archivo_bus / sizeof(Bus);
    return num_Buses;
}