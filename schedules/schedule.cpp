#include <iostream>
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