#include <iostream>
#include <stdio.h>
#include <string.h>
#include "auxiliarbus.h"
#include "structurabus.h"
#define MAX 100
using namespace std;

/*Bus Regiter*/
/*Create*/
void addBus(Colectivo bus);
/*Read*/
void showBus(int pos);
int isBus(char id[]);
void startBus(int pos);
// Colectivo getBus(int pos);
Colectivo dameUnBus(int i);
/*Update*/
void updateBus(Colectivo bus, int pos);
/*Delete*/
void deleteBus(int pos);
/*Menu User*/
int menuBus();
void startBuses();
/*Archivos User*/
FILE *BusesRegistration;
void saveBus();
void readBus();
int calcUltRegBus(FILE *archivo_bus);

/*Menu Archivo Principal*/
void menuPrincipal();
int principal();

void addBus(Colectivo bus)
{
    Buses[lastRegBus] = bus;
    lastRegBus++;
}

void showBus(int pos)
{
    gotoxy1(60, 5);
    cout << "Bus David #: " << Buses[pos].busId << endl;
    gotoxy1(60, 6);
    cout << "Placa: " << Buses[pos].busPlate << endl;
    gotoxy1(60, 7);
    cout << "Año: " << Buses[pos].busYear << endl;
    gotoxy1(60, 8);
    cout << "Capacidad: " << Buses[pos].Capacity << endl;
    gotoxy1(60, 9);
    cout << "Motor: " << Buses[pos].busMotor << endl;
    gotoxy1(60, 10);
    cout << "Trasmision: " << Buses[pos].busTransmission << endl;
    gotoxy1(60, 11);
    cout << "Model de Llantas: " << Buses[pos].busWheel << endl;
    gotoxy1(60, 12);
    cout << "Trabajadores: " << Buses[pos].busjobs << endl;
    gotoxy1(60, 13);
    cout << "KM Recorridos: " << Buses[pos].busKM << endl;
}

Colectivo dameUnBus(int pos)
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

void updateBus(Colectivo bus, int pos)
{
    Buses[pos] = bus;
}

void deleteBus(int pos)
{
    if (pos == lastRegBus)
    {
        gotoxy1(60, 5);
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
    strcpy(Buses[pos].busMotor, "");
    strcpy(Buses[pos].busTransmission, "");
    strcpy(Buses[pos].busWheel, "");
    strcpy(Buses[pos].busjobs, "");
    Buses[pos].busKM = 0.00;
}

int menuBus()
{
    int op;

    gotoxy1(60, 5);
    cout << " Informacion administrativa - Transporte David\n";
    gotoxy1(71, 6);
    cout << "Cantidad de registros: " << lastRegBus << endl;
    gotoxy1(60, 9);
    cout << " 1. Agregar Informacion de Bus\n";
    gotoxy1(60, 10);
    cout << " 2. Mantenimiento Bus \n";
    gotoxy1(60, 11);
    cout << " 3. Editar Bus \n";
    gotoxy1(60, 12);
    cout << " 4. Eliminar Bus \n";
    gotoxy1(60, 13);
    cout << " 5. Mostrar Bus \n";
    gotoxy1(60, 14);
    cout << " 6. Salir \n";
    gotoxy1(60, 15);
    cout << " Digite la opcion: ";
    gotoxy1(79, 15);
    cin >> op;
    return op;
}

void startBuses()
{
    int op, pos, resp;
    char busId[5];
    Colectivo bus;
    do
    {
        system("cls||clear");

        op = menuBus();
        switch (op)
        {
        case 1:
            system("cls || clear");
            gotoxy1(60, 5);
            cout << "Bus David #:";
            gotoxy1(60, 6);
            cout << "Placa: ";
            gotoxy1(60, 7);
            cout << "Año: ";
            gotoxy1(60, 8);
            cout << "Capacidad: ";
            gotoxy1(60, 9);
            cout << "Motor: ";
            gotoxy1(60, 10);
            cout << "Trasmision: ";
            gotoxy1(60, 11);
            cout << "Modelo de Llantas: ";
            gotoxy1(60, 12);
            cout << "Trabajadores: ";
            gotoxy1(60, 13);
            cout << "KM Recorridos: ";
            gotoxy1(73, 5);
            scanf(" %[^\n]", bus.busId);
            gotoxy1(67, 6);
            scanf(" %[^\n]", bus.busPlate);
            gotoxy1(66, 7);
            cin >> bus.busYear;
            gotoxy1(71, 8);
            cin >> bus.Capacity;
            gotoxy1(67, 9);
            scanf(" %[^\n]", bus.busMotor);
            gotoxy1(72, 10);
            scanf(" %[^\n]", bus.busTransmission);
            gotoxy1(79, 11);
            scanf(" %[^\n]", bus.busWheel);
            gotoxy1(74, 12);
            scanf(" %[^\n]", bus.busjobs);
            gotoxy1(75, 13);
            cin >> bus.busKM;
            addBus(bus);
            system("pause");

            break;

        case 2:
            system("cls||clear");
            gotoxy1(71, 5);
            cout << "Mantenimiento de Bus\n";
            gotoxy1(60, 7);
            cout << "Cambio de Aceite: 5000 kms\n";
            gotoxy1(60, 8);
            cout << "Cambio de filtro de Aceite: 5000 kms\n";
            gotoxy1(60, 9);
            cout << "Cambio de filtro de Combustible: 10000 kms\n";
            gotoxy1(60, 10);
            cout << "Cambio de filtro de Aire: 40000 kms\n";
            gotoxy1(60, 11);
            cout << "Engrase General: 2000 kms\n";
            gotoxy1(60, 12);
            cout << "Engrase de Patentes: 40000 kms\n";
            gotoxy1(60, 13);
            cout << "Ajuste de Embrague: 7200 kms\n";
            gotoxy1(60, 14);
            cout << "Mantenimiento Sistema Eléctrico: 25000 kms\n";
            gotoxy1(60, 15);
            cout << "Scanner al Sistema Electronico: 65000 kms\n";
            gotoxy1(60, 16);
            cout << "Rotacion de Llantas: 30000 kms\n";
            gotoxy1(60, 17);
            cout << "Cambio de Llantas: 75000 kms\n";
            gotoxy1(60, 18);
            cout << "Revision de Niveles de Aceite de Diferencial: 14400 kms\n";
            gotoxy1(60, 19);
            cout << "Revision de Niveles de Aceite de Caja/Transmision: 14400 kms\n";
            gotoxy1(60, 20);
            cout << "Revision de Revisión de Yugos y Cruz Cardánica: 4000 kms\n";
            gotoxy1(60, 21);
            cout << "Revision de Fricciones: 28800 kms\n";
            gotoxy1(60, 22);
            cout << "Revision de Alineación y Balanceo: 57600 kms\n";
            gotoxy1(60, 22);
            cout << "Revision de Imprevisto al Motor: 7200 kms\n";
            system("pause");
            break;

        case 3:
            system("cls||clear");
            gotoxy1(60, 4);
            cout << "Escribe el # a buscar: ";
            scanf(" %[^\n]", busId);
            pos = isBus(busId);
            showBus(pos);
            gotoxy1(60, 14);
            cout << "DATOS A EDITAR\n";
            gotoxy1(60, 15);
            cout << "Bus David #:";
            gotoxy1(60, 16);
            cout << "Placa: ";
            gotoxy1(60, 17);
            cout << "Año: ";
            gotoxy1(60, 18);
            cout << "Capacidad: ";
            gotoxy1(60, 19);
            cout << "Motor: ";
            gotoxy1(60, 20);
            cout << "Trasmision: ";
            gotoxy1(60, 21);
            cout << "Modelo de Llantas: ";
            gotoxy1(60, 22);
            cout << "Trabajadores: ";
            gotoxy1(60, 23);
            cout << "KM Recorridos: ";
            gotoxy1(73, 15);
            scanf(" %[^\n]", bus.busId);
            gotoxy1(67, 16);
            scanf(" %[^\n]", bus.busPlate);
            gotoxy1(66, 17);
            cin >> bus.busYear;
            gotoxy1(71, 18);
            cin >> bus.Capacity;
            gotoxy1(67, 19);
            scanf(" %[^\n]", bus.busMotor);
            gotoxy1(72, 20);
            scanf(" %[^\n]", bus.busTransmission);
            gotoxy1(79, 21);
            scanf(" %[^\n]", bus.busWheel);
            gotoxy1(74, 22);
            scanf(" %[^\n]", bus.busjobs);
            gotoxy1(75, 23);
            cin >> bus.busKM;
            updateBus(bus, pos);
            gotoxy1(60, 23);
            cout << "Registro actualizado...\n";
            system("pause");
            break;
        case 4:
            system("cls||clear");
            if (lastRegBus == 0)
            {
                gotoxy1(60, 5);
                cout << "No hay nada que eliminar\n";
                system("pause");
                break;
            }
            gotoxy1(60, 5);
            cout << "Escribe el # del Bus: ";
            cin >> busId;
            pos = isBus(busId);
            bus = dameUnBus(pos);
            gotoxy1(60, 6);
            cout << "Realmente deseas eliminar el Bus #" << bus.busId << "?\n";
            gotoxy1(60, 7);
            cout << "Escribe 1 para SI o 2 para NO: ";
            gotoxy1(91, 7);
            cin >> resp;
            if (resp == 1)
            {
                deleteBus(pos);
                gotoxy1(60, 9);
                cout << "Registro Eliminado... \n";
            }
            else
            {
                gotoxy1(60, 9);
                cout << "Operaciòn cancelada.... \n";
            }
            system("pause");
            break;
        case 5:
            system("cls||clear");
            gotoxy1(60, 4);
            cout << "Escribe el # a buscar: ";
            scanf(" %[^\n]", busId);
            pos = isBus(busId);
            showBus(pos);
            system("pause");
            break;
        case 6:
            break;
        default:
            system("clear||cls");
            cout << "Opcion invalida \n";
            system("pause");
            break;
        }
    } while (op != 6);
    saveBus();
}

void saveBus()
{
    BusesRegistration = fopen("Bus.bin", "wb");
    fwrite(Buses, sizeof(Colectivo), lastRegBus, BusesRegistration);
    fclose(BusesRegistration);
}

void readBus()
{
    BusesRegistration = fopen("Bus.bin", "rb");
    if (BusesRegistration == NULL)
    {
        return;
    }
    lastRegBus = calcUltRegBus(BusesRegistration);
    fread(Buses, sizeof(Colectivo), MAX, BusesRegistration);
    fclose(BusesRegistration);
}

int calcUltRegBus(FILE *archivo_bus)
{
    int tam_archivo_bus, num_Buses;

    fseek(archivo_bus, 0, SEEK_END);
    tam_archivo_bus = ftell(archivo_bus);
    rewind(archivo_bus);

    num_Buses = tam_archivo_bus / sizeof(Colectivo);
    return num_Buses;
}