#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "auxiliarticket.h"
#include "structuraTikect.h"

#define MAX2 14
using namespace std;

factura Fact[500];
priceTicket PT[MAX2];
int lastRegDestiny = 0;
int lastRegFact = 0;

/*Destino*/

void addDestiny(priceTicket destiny);
void editDestiny();
int searchDestiny(char id[]);
void ShowDestiny(int pos);

/*Factura*/
void addFactura(factura F);
int searchFactura(char id[]);
void printFactura(int pos, int pos1, float price);

/*Dia*/
void showDate();

/*Archivo Factura*/
FILE *FacturaRegistration;
void saveFactura();
void readFactura();
int calcUltRegFactura(FILE *archivo_factura);

/*Archivo Destiny*/
FILE *DestinyRegistration;
void saveDestiny();
void readDestiny();
int calcUltRegDestiny(FILE *archivo_destiny);

/*Menu*/
int menuTicket();
void StartTicket();

void addDestiny(priceTicket destiny)
{
    PT[lastRegDestiny] = destiny;
    lastRegDestiny++;
}

void editDestiny(priceTicket destiny, int pos)
{
    PT[pos] = destiny;
}

int searchDestiny(char num[])
{
    int posicion = 0;
    for (int i = 0; i < lastRegDestiny; i++)
    {
        if (strcmp(num, PT[i].id) == 0)
        {
            posicion = i;
            break;
        }
    }
    return posicion;
}

void ShowDestiny(int pos)
{
    gotoxy3(60, 5);
    cout << "ID Destino: " << PT[pos].id << endl;
    gotoxy3(60, 6);
    cout << "Origen: " << PT[pos].origen << endl;
    gotoxy3(60, 7);
    cout << "Destino: " << PT[pos].destino << endl;
    gotoxy3(60, 8);
    cout << "Precio Ticket: " << PT[pos].price << endl;
}

void showDate()
{
    float monto = 0;
    Fecha fecha;
    gotoxy3(60, 4);
    cout << "Dime la fecha a buscar: ";
    scanf("%d/%d/%d", &fecha.day, &fecha.month, &fecha.year);
    for (int i = 0; i < lastRegFact; i++)
    {
        if (fecha.day == Fact[i].dateF.day && fecha.month == Fact[i].dateF.month && fecha.year == Fact[i].dateF.year)
        {
            monto += Fact[i].total;
        }
    }
    gotoxy3(60, 6);
    cout << "Monto C$: " << monto << endl;
}

void addFactura(factura F)
{
    Fact[lastRegFact] = F;
    lastRegFact++;
}
int searchFactura(char id[])
{

    int posicion = 0;
    for (int i = 0; i < lastRegFact; i++)
    {
        if (strcmp(id, Fact[i].idF) == 0)
        {
            posicion = i;
            break;
        }
    }
    return posicion;
}
void printFactura(int pos)
{
    gotoxy3(60, 5);
    cout << "ID Factura: " << Fact[pos].idF << endl;
    gotoxy3(60, 6);
    cout << "Fecha: " << Fact[pos].dateF.day << "/" << Fact[pos].dateF.month << "/" << Fact[pos].dateF.year << endl;
    gotoxy3(60, 7);
    cout << "ID destino " << Fact[pos].idD << endl;
    gotoxy3(60, 8);
    cout << "Horario: " << Fact[pos].horario << endl;
    gotoxy3(60, 9);
    cout << "Origen:" << Fact[pos].origenF << endl;
    gotoxy3(60, 10);
    cout << "Destino: " << Fact[pos].destinoF << endl;
    gotoxy3(60, 11);
    cout << "Cantidad de Ticket: " << Fact[pos].cantT << endl;
    gotoxy3(60, 12);
    cout << "Precio individual:  " << Fact[pos].priceDest << endl;
    gotoxy3(60, 13);
    cout << "Total:" << Fact[pos].total << endl;
}

int menuTicket()
{
    int op;

    gotoxy3(60, 5);
    cout << " Tickets - Transporte David\n";
    gotoxy3(71, 6);
    cout << "Cantidad de Destinos: " << lastRegDestiny << endl;
    gotoxy3(60, 9);
    cout << " 1. Agregar Destino";
    gotoxy3(60, 10);
    cout << " 2. Editar Destino \n";
    gotoxy3(60, 11);
    cout << " 3. Mostrar Destino \n";
    gotoxy3(60, 12);
    cout << " 4. Add Factura \n";
    gotoxy3(60, 13);
    cout << " 5. Imprimir factura \n";
    gotoxy3(60, 14);
    cout << " 6. Mostar Ganacia Fecha \n";
    gotoxy3(60, 15);
    cout << " 7. Salir \n";
    gotoxy3(60, 17);
    cout << " Digite la opcion: ";
    gotoxy3(79, 17);
    cin >> op;
    return op;
}

void StartTicket()
{
    int op, pos, pos1;
    char FactId[5];
    char DestID[5];
    priceTicket destiny;
    factura F;
    readFactura();
    readDestiny();
    do
    {
        system("cls||clear");

        op = menuTicket();
        switch (op)
        {
        case 1:
            system("cls || clear");
            gotoxy3(60, 5);
            cout << "ID Destino:";
            gotoxy3(60, 6);
            cout << "Origen: ";
            gotoxy3(60, 7);
            cout << "Destino: ";
            gotoxy3(60, 8);
            cout << "Precio Ticket: ";
            gotoxy3(72, 5);
            scanf(" %[^\n]", destiny.id);
            gotoxy3(68, 6);
            scanf(" %[^\n]", destiny.origen);
            gotoxy3(69, 7);
            scanf(" %[^\n]", destiny.destino);
            gotoxy3(75, 8);
            cin >> destiny.price;
            addDestiny(destiny);
            system("pause");
            break;

        case 2:
            system("cls||clear");
            gotoxy3(60, 4);
            cout << "Escribe el Id del Destino a buscar: ";
            scanf(" %[^\n]", DestID);
            pos = searchDestiny(DestID);
            ShowDestiny(pos);
            gotoxy3(60, 10);
            cout << "DATOS A EDITAR\n";
            gotoxy3(60, 11);
            cout << "ID Destino:";
            gotoxy3(60, 12);
            cout << "Origen: ";
            gotoxy3(60, 13);
            cout << "Destino: ";
            gotoxy3(60, 14);
            cout << "Precio Ticket: ";
            gotoxy3(72, 11);
            scanf(" %[^\n]", destiny.id);
            gotoxy3(68, 12);
            scanf(" %[^\n]", destiny.origen);
            gotoxy3(69, 13);
            scanf(" %[^\n]", destiny.destino);
            gotoxy3(75, 14);
            cin >> destiny.price;
            editDestiny(destiny, pos);
            gotoxy3(60, 19);
            cout << "Registro actualizado...\n";
            system("pause");
            break;

        case 3:
            system("cls||clear");
            gotoxy3(60, 4);
            cout << "Escribe el Id del Destino a buscar: ";
            scanf(" %[^\n]", DestID);
            pos = searchDestiny(DestID);
            ShowDestiny(pos);
            system("pause");
            break;
        case 4:
            system("cls||clear");
            gotoxy3(60, 3);
            cout << "Escribe el Id del destino al que se dirije: ";
            scanf(" %[^\n]", DestID);
            pos1 = searchDestiny(DestID);
            gotoxy3(60, 5);
            cout << "ID Factura: ";
            gotoxy3(60, 6);
            cout << "Fecha: ";
            gotoxy3(60, 7);
            cout << "ID destino: ";
            gotoxy3(60, 8);
            cout << "Horario: ";
            gotoxy3(60, 9);
            cout << "Origen: ";
            gotoxy3(60, 10);
            cout << "Destino: ";
            gotoxy3(60, 11);
            cout << "Cantidad de Ticket:  ";
            gotoxy3(60, 12);
            cout << "Precio individual:  ";
            gotoxy3(60, 13);
            cout << "Total:";
            gotoxy3(72, 5);
            scanf(" %[^\n]", F.idF);
            gotoxy3(67, 6);
            scanf("%d/%d/%d", &F.dateF.day, &F.dateF.month, &F.dateF.year);
            gotoxy3(73, 7);
            F.idD = PT[pos1].id;
            cout << F.idD;
            gotoxy3(69, 8);
            scanf(" %[^\n]", F.horario);
            gotoxy3(68, 9);
            F.origenF = PT[pos1].origen;
            cout << F.origenF;
            gotoxy3(69, 10);
            F.destinoF = PT[pos1].destino;
            cout << F.destinoF;
            gotoxy3(80, 11);
            cin >> F.cantT;
            gotoxy3(79, 12);
            F.priceDest = PT[pos1].price;
            cout << F.priceDest;
            F.total = F.cantT * F.priceDest;
            gotoxy3(67, 13);
            cout << F.total << endl;
            addFactura(F);
            system("pause");
            break;
        case 5:
            system("cls||clear");
            gotoxy3(60, 3);
            cout << "Escribe el Id de la Factura: ";
            scanf(" %[^\n]", FactId);
            pos = searchDestiny(FactId);
            printFactura(pos);
            system("pause");
            break;
        case 6:
            system("cls||clear");
            showDate();
            system("pause");
            break;
        }
    } while (op != 7);
    saveFactura();
    saveDestiny();
}

void saveDestiny()
{
    DestinyRegistration = fopen("destiny.bin", "wb");
    fwrite(PT, sizeof(priceTicket), lastRegDestiny, DestinyRegistration);
    fclose(DestinyRegistration);
}

void readDestiny()
{
    DestinyRegistration = fopen("destiny.bin", "rb");
    if (DestinyRegistration == NULL)
    {
        return;
    }
    lastRegDestiny = calcUltRegDestiny(DestinyRegistration);
    fread(PT, sizeof(priceTicket), MAX2, DestinyRegistration);

    fclose(DestinyRegistration);
}

int calcUltRegDestiny(FILE *archivo_destiny)
{
    int tam_archivo_Destiny, num_Destiny;

    fseek(archivo_destiny, 0, SEEK_END);
    tam_archivo_Destiny = ftell(archivo_destiny);
    rewind(archivo_destiny);

    num_Destiny = tam_archivo_Destiny / sizeof(priceTicket);
    return num_Destiny;
}

void saveFactura()
{
    FacturaRegistration = fopen("factura.bin", "wb");
    fwrite(Fact, sizeof(factura), lastRegFact, FacturaRegistration);
    fclose(FacturaRegistration);
}

void readFactura()
{
    FacturaRegistration = fopen("factura.bin", "rb");
    if (FacturaRegistration == NULL)
    {
        return;
    }
    lastRegFact = calcUltRegFactura(FacturaRegistration);
    fread(Fact, sizeof(factura), 500, FacturaRegistration);

    fclose(FacturaRegistration);
}

int calcUltRegFactura(FILE *archivo_factura)
{
    int tam_archivo_Factura, num_Factura;

    fseek(archivo_factura, 0, SEEK_END);
    tam_archivo_Factura = ftell(archivo_factura);
    rewind(archivo_factura);

    num_Factura = tam_archivo_Factura / sizeof(factura);
    return num_Factura;
}