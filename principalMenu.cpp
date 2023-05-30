#include<iostream>
#include "buses/FuncionBus.cpp"
#include "tickets/ticket.cpp"
#include "schedules/schedule.cpp"
#include "users/user.cpp"
#include "auxiliar.h"
using namespace std;


int MenuP();
void StartPrincipal();

int MenuP()
{
    int op;

    gotoxy(75, 6);
    cout << "Transporte David\n";
    gotoxy(60, 9);
    cout << " 1. Información Administrativa\n";
    gotoxy(60, 10);
    cout << " 2. Informacion Usuario\n";
    gotoxy(60, 11);
    cout << " 3. Tickets \n";
    gotoxy(60, 12);
    cout << " 4. Itinerario Bus\n";
    gotoxy(60, 13);
    cout << " 5. Salir \n";
    gotoxy(60, 15);
    cout << " Digite la opcion: ";
    gotoxy(79, 15);
    cin >> op;
    return op;
}

void StartPrincipal()
{
    int op;
    do
    {
        system("cls||clear");

        op = MenuP();
        switch (op)
        {
        case 1: StartBuses();
                break;
        case 2: startUse();
            break;
        case 3: StartTicket();
            break;
        case 4: Schedule();
            break;
        case 5:
            cout<< "Gracias por preferirnos, Vuelva pronto\n";
            break;
        }
    }
    while(op != 5);
}