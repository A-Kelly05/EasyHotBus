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
	
	
} factura;


factura Fact[500];
priceTicket PT[MAX];
int lastRegDestiny = 0;
int lastRegFact = 0 ; 

/* declaramos las siguientes Funciones
1. add destiny
2. edit destiny
3. search destiny
4. print Factura
5. mostar monto del dia
6. mostrar monto por fecha*/

void addDestiny(priceTicket destiny);
void editDestiny();
int searchDestiny(char id[]);
void addFactura (factura F);
int searchFactura(char id[]);
void printFactura(int pos, int pos1,float price);
void showDay(int pos);
void showDate(date thisDate);


void addDestiny(priceTicket destiny)
{
	PT[lastRegDestiny] = destiny;
	lastRegDestiny++;
}

void editDestiny(priceTicket destiny, int pos)
{
	PT[pos] = destiny;
}

priceTicket getTicket(int pos)
{
    return PT[pos];
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

void showDay(int pos)
{
    gotoxy(60, 5);
    
}

void showDate()
{
 
}

void addFactura(factura F)
{
Fact[lastRegFact] = F ;
	lastRegFact++;

}
int searchFactura(char id[]){

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
void printFactura(int pos, int pos1,float price)
{
 gotoxy(60,5);
    cout << " ID Factura " << Fact[pos].idF << endl;
    gotoxy(60,6);
    cout << "Fecha: " << Fact[pos].dateF.day << "/" << Fact[pos].dateF.month << "/" << Fact[pos].dateF.year << endl;
    gotoxy(60,7); 
    cout << " Horario: " << Fact[pos].horario<< endl;
    gotoxy(60,8);
    cout << "Cantidad de  " << Fact[pos].cantT << endl;
    gotoxy(60,9);
    cout << "ID destino " << Fact[pos1].ticket.id << endl ; 
    gotoxy(60,10);
    cout << "Origen:" << Fact[pos1].ticket.origen << endl ; 
	 gotoxy(60,11);
    cout << "Destino: " << Fact[pos1].ticket.destino<< endl;
    gotoxy(60,12);
    cout << "Precio individual:  " << Fact[pos1].ticket.price<< endl;
    gotoxy(60,13);
    cout << "Total:" << price = Fact[pos1].ticket.price * Fact[pos].cantT;
}




