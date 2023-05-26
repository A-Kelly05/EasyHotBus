#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "../auxiliar.h"

#define MAX 14
using namespace std;
typedef struct
{
    char id[5];
    char origen[50];
    char destino[50];
    float price;
} priceTicket;
typedef struct
{
    int day;
    int month;
    int year;
} date;
typedef struct
{
    char idF[5];
    date dateF;
    int horario;
    int cantT;
    priceTicket ticket;
    float total;

} factura;

factura Fact[500];
priceTicket PT[MAX];
int lastRegDestiny = 0;
int lastRegFact = 0;

/*Destino*/
void addDestiny(priceTicket destiny);
void editDestiny();
int searchDestiny(char id[]);
void ShowDestiny(int pos);
void ShowAll();
/*Factura*/
void addFactura(factura F);
int searchFactura(char id[]);
void printFactura(int pos, int pos1, float price);
/*Dia*/
void showDay(int pos);
void showDate(date thisDate);
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
    PT[lastRegDestiny]=destiny;
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
    gotoxy(60, 5);
    cout << "ID Destino: " << PT[pos].id << endl;
    gotoxy(60, 6);
    cout << "Origen: " << PT[pos].origen << endl;
    gotoxy(60, 7);
    cout << "Destino: " << PT[pos].destino << endl;
    gotoxy(60, 8);
    cout << "Precio Ticket: " << PT[pos].price << endl;
}
void ShowAll()
{
    system("cls||clear");
    if (lastRegDestiny == 0)
    {
        gotoxy(60, 5);
        cout << "No hay registros\n";
        return;
    }
    for (int i = 0; i < lastRegDestiny; i++)
    {
        gotoxy(60, 4);
        cout << "=========================\n";
        ShowDestiny(i);
    }
    cout << "Ultimo registro...\n";
}

void showDay(int pos)
{
    gotoxy(60, 5);
}

void showDate()
{
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
    gotoxy(60, 5);
    cout << " ID Factura " << Fact[pos].idF << endl;
    gotoxy(60, 6);
    cout << "Fecha: " << Fact[pos].dateF.day << "/" << Fact[pos].dateF.month << "/" << Fact[pos].dateF.year << endl;
    gotoxy(60, 7);
    cout << "ID destino " << Fact[pos].ticket.id << endl;
    gotoxy(60, 8);
    cout << " Horario: " << Fact[pos].horario << endl;
    gotoxy(60, 9);
    cout << "Origen:" << Fact[pos].ticket.origen << endl;
    gotoxy(60, 10);
    cout << "Destino: " << Fact[pos].ticket.destino << endl;
    gotoxy(60, 11);
    cout << "Cantidad de Ticket: " << Fact[pos].cantT << endl;
    gotoxy(60, 12);
    cout << "Precio individual:  " << Fact[pos].ticket.price << endl;
    gotoxy(60, 13);
    cout << "Total:" << Fact[pos].total << endl;
}

int menuTicket()
{
    int op;

    gotoxy(60, 5);
    cout << " Tickets - Transporte David\n";
    gotoxy(71, 6);
    cout << "Cantidad de Destinos: " << lastRegDestiny << endl;
    gotoxy(60, 9);
    cout << " 1. Agregar Destino";
    gotoxy(60, 10);
    cout << " 2. Editar Destino \n";
    gotoxy(60, 11);
    cout << " 3. Mostrar Destinos \n";
    gotoxy(60, 12);
    cout << " 4. Add Factura \n";
    gotoxy(60, 13);
    cout << " 5. Imprimir factura \n";
    gotoxy(60, 14);
    cout << " 6. Mostrar Ganacia Dia \n";
    gotoxy(60, 15);
    cout << " 7. Mostar Ganacia Fecha \n";
    gotoxy(60, 16);
    cout << " 8. Salir \n";
    gotoxy(60, 17);
    cout << " Digite la opcion: ";
    gotoxy(79, 17);
    cin >> op;
    return op;
}

void StartTicket()
{
    int op, pos, resp, pos1;
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
            gotoxy(60, 5);
            cout << "ID Destino:";
            gotoxy(60, 6);
            cout << "Origen: ";
            gotoxy(60, 7);
            cout << "Destino: ";
            gotoxy(60, 8);
            cout << "Precio Ticket Ind.: ";
            gotoxy(73, 5);
            scanf(" %[^\n]", destiny.id);
            gotoxy(67, 6);
            scanf(" %[^\n]", destiny.origen);
            gotoxy(65, 7);
            scanf(" %[^\n]", destiny.destino);
            gotoxy(71, 8);
            cin >> destiny.price;
            addDestiny(destiny);
            system("pause");
            break;

        case 2:
            system("cls||clear");
            gotoxy(60, 4);
            cout << "Escribe el Id del Destino a buscar: ";
            scanf(" %[^\n]", DestID);
            pos = searchDestiny(DestID);
            ShowDestiny(pos);
            gotoxy(60, 10);
            cout << "DATOS A EDITAR\n";
            gotoxy(60, 11);
            cout << "ID Destino:";
            gotoxy(60, 12);
            cout << "Origen: ";
            gotoxy(60, 13);
            cout << "Destino: ";
            gotoxy(60, 17);
            cout << "Precio Ticket: ";
            gotoxy(73, 11);
            scanf(" %[^\n]", destiny.id);
            gotoxy(69, 15);
            scanf(" %[^\n]", destiny.origen);
            gotoxy(70, 16);
            scanf(" %[^\n]", destiny.destino);
            gotoxy(77, 17);
            cin >> destiny.price;
            editDestiny(destiny, pos);
            gotoxy(60, 19);
            cout << "Registro actualizado...\n";
            system("pause");
            break;

        case 3:
            system("cls||clear");
            ShowAll();
            system("pause");
            break;
        
        case 4:
            int Cant,Price,Total;
            system("cls||clear");
            gotoxy(60, 3);
            cout << "Escribe el Id del destino al que se dirije: ";
            scanf(" %[^\n]", DestID);
            pos1 = searchDestiny(DestID);
            gotoxy(60, 5);
            cout << "ID Factura: ";
            gotoxy(60, 6);
            cout << "Fecha: ";
            gotoxy(60, 7);
            cout << "ID destino: ";
            gotoxy(60, 8);
            cout << "Horario: ";
            gotoxy(60, 9);
            cout << "Origen: ";
            gotoxy(60, 10);
            cout << "Destino: ";
            gotoxy(60, 11);
            cout << "Cantidad de Ticket:  ";
            gotoxy(60, 12);
            cout << "Precio individual:  ";
            gotoxy(60, 13);
            cout << "Total:";
            gotoxy(72, 5);
            scanf(" %[^\n]", F.idF);
            gotoxy(68, 6);
            scanf("%d/%d/%d", &F.dateF.day, &F.dateF.month, &F.dateF.year);
            gotoxy(73, 7);
            cout<< PT[pos1].id;
            gotoxy(70, 8);
            scanf(" %[^\n]", F.horario);
            gotoxy(70, 9);
            cout<< PT[pos1].origen;
            gotoxy(71, 10);
            cout<< PT[pos1].destino;
            gotoxy(81, 11);
            cin >> F.cantT;
            Cant=F.cantT;
            gotoxy(80, 12);
            cout<< PT[pos1].price;
            Price=PT[pos1].price;
            Total=Cant*Price;
            F.total = Total;
            gotoxy(80, 12);
            cout<<F.total;
            addFactura(F);
            system("pause");
            break;
        case 5:
            system("cls||clear");
            gotoxy(60, 4);
            cout << "Escribe el Id de la Factura: ";
            scanf(" %[^\n]", FactId);
            pos = searchDestiny(FactId);
            printFactura(pos);
            system("pause");
            break;
            
        
        }
    } while (op != 8);
    saveFactura();
    saveDestiny();
}
