#include <stdio.h>
#include <string.h>

#define MAX_RETIRO 5000.0

char numeroCuenta1[6] = "12345";
char nombre1[50] = "Juan Martinez";
float saldo1 = 10000.0;

char numeroCuenta2[6] = "67890";
char nombre2[50] = "Carlos Guaita";
float saldo2 = 5000.0;

char numeroCuenta3[6] = "11223";
char nombre3[50] = "Carlos Ruiz";
float saldo3 = 3000.0;

char cuentaIngresada[6];
int opcion;
float cantidad;
int operacionesRealizadas = 0;

char *nombreActual;
float *saldoActual;

int mostrarMenu() {
    printf("1. Consultar saldo\n");
    printf("2. Retirar dinero\n");
    printf("3. Depositar dinero\n");
    printf("4. Salir\n");
    printf("Seleccione una opcion: ");
    
    int opcion;
    scanf("%d", &opcion);
    getchar(); 
    return opcion;
}

int main() {
    printf("Bienvenido al cajero automatico\n");

    printf("Ingrese su numero de cuenta: ");
    fgets(cuentaIngresada, 6, stdin);
    cuentaIngresada[strcspn(cuentaIngresada, "\n")] = 0;

    if (strcmp(cuentaIngresada, numeroCuenta1) == 0) {
        nombreActual = nombre1;
        saldoActual = &saldo1;
    } else if (strcmp(cuentaIngresada, numeroCuenta2) == 0) {
        nombreActual = nombre2;
        saldoActual = &saldo2;
    } else if (strcmp(cuentaIngresada, numeroCuenta3) == 0) {
        nombreActual = nombre3;
        saldoActual = &saldo3;
    } else {
        printf("Cuenta no valida. Intente de nuevo.\n");
        return 1;
    }

    printf("Bienvenido %s, su saldo actual es $%.2f.\n", nombreActual, *saldoActual);

    while (1) {
        opcion = mostrarMenu(); 

        switch (opcion) {
            case 1: 
                printf("Su saldo actual es: $%.2f\n", *saldoActual);
                operacionesRealizadas++;
                break;

            case 2: 
                printf("Ingrese la cantidad que desea retirar $");
                if (scanf("%f", &cantidad) != 1) {
                    printf("Por favor, ingrese una cantidad valida.\n");
                    while(getchar() != '\n');
                    break;
                }

                if (cantidad < 0) {
                    printf("No se puede retirar una cantidad negativa.\n");
                } else if (cantidad > *saldoActual) {
                    printf("No tiene suficiente saldo para realizar esta operacion.\n");
                } else if (cantidad > MAX_RETIRO) {
                    printf("El monto maximo por transaccion es $5000.\n");
                } else {
                    *saldoActual -= cantidad;
                    printf("Retiro exitoso. Ha retirado $%.2f.\n", cantidad);
                    operacionesRealizadas++;
                }
                break;

            case 3: 
                printf("Ingrese la cantidad que quiere depositar $");
                if (scanf("%f", &cantidad) != 1) {
                    printf("Por favor, ingrese una cantidad valida.\n");
                    while(getchar() != '\n');
                    break;
                }

                if (cantidad <= 0) {
                    printf("El monto a depositar debe ser mayor que cero.\n");
                } else {
                    *saldoActual += cantidad;
                    printf("Deposito exitoso. Ha depositado $%.2f.\n", cantidad);
                    operacionesRealizadas++;
                }
                break;

            case 4: 
                printf("Saldo final: $%.2f\n", *saldoActual);
                printf("Operaciones realizadas: %d\n", operacionesRealizadas);
                printf("Gracias por usar el cajero automatico.\n");
                return 0;

            default:
                printf("Opcion no valida. Por favor, elija una opcion del menu.\n");
        }
    }

    return 0;
}
