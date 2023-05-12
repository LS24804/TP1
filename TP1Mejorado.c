#include <stdio.h>

double op1, op2, resul;
char simbolo;

/* La siguiente funcion obtiene el numero de Euler mediante la sucesion de Taylor, esto lo hace inicializando una variable "e", cuyo valor sera 1 (representando
    a 1/0! de la serie) y, luego otra variable "term", que representa cada uno de los terminos de la sucesion 1/1!, 1/2!, etc.
    Posteriormente, creamos un while con i = 1. El while lo que hace es por cada iteracion va a multiplicar "term" por 1/i, lo que nos ahorra el uso de
    factoriales ya que al hacerlo obtenemos el mismo resultado (ej.: term = 1/2, i=3: [1/2 * 1/3] = 1/6, que es igual a 1/3!), por lo tanto cada iteracion
    del while corresponde a un termino de la sucesion de Taylor, las cuales iremos sumando hasta que term sea < 10e-9 para obtener nuestra aproximacion!*/
    double euler(){
    double e = 1.0;
    double term = 1.0;
    double i = 1.0;

    while(term > 10e-9){
        term *= 1.0 / i;
        e += term;
        i++;
    }
    return e;
}

int main(void){

    printf("Ingrese la operacion que desea realizar (*, /, +, -, !, e [e^x]): \n");
    scanf(" %c", &simbolo);

    switch (simbolo) {
        case '+':
            printf("Ingrese el primer operando: \n");
            scanf("%lf", &op1);
            printf("Ingrese el segundo operando: \n");
            scanf("%lf", &op2);
            resul = op1+op2;
            printf("Resultado: %lf\n", resul);
            break;

        case '-':
            printf("Ingrese el primer operando: \n");
            scanf("%lf", &op1);
            printf("Ingrese el segundo operando: \n");
            scanf("%lf", &op2);
            resul = op1-op2;
            printf("Resultado: %lf\n", resul);
            break;

        case '*':
            printf("Ingrese el primer operando: \n");
            scanf("%lf", &op1);
            printf("Ingrese el segundo operando: \n");
            scanf("%lf", &op2);
            resul = op1*op2;
            printf("Resultado: %lf\n", resul);
            break;

        case '/':
            printf("Ingrese el primer operando: \n");
            scanf("%lf", &op1);
            printf("Ingrese el segundo operando: \n");
            scanf("%lf", &op2);
            if (op2 != 0) {
                resul = op1/op2;
                printf("Resultado: %lf\n", resul);
            } else {
                printf("Operacion NO Valida Division por Cero\n");
            }
            break;

        case '!':
            printf("Ingrese el operando: \n");
            scanf("%lf", &op1);
            factorial(op1);
            break;

        case 'e':{
            printf("Ingrese el operando: \n");
            scanf("%lf", &op1);
            double respaldo = op1;
            double e = euler();
            double potencia = 1.0;
            while(op1 > 0) {
                potencia *= e;
                op1--;
            }
            printf("El resueltado de e^%.2f es: %lf\n", respaldo, potencia);
            break;
        }
        default:
            printf("Operacion NO Valida\n");
            break;
    }

    return 0;
}
    int factorial(double op1){
        int i, k;
        int resultado = 1;
        int resultado2 = 1;
        if (simbolo == '!') {
            for(i = 1; i <= op1; i++){
                resultado = i*resultado;
            }
            printf("El factorial de %lf es: %d\n", op1, resultado);
        }
        return 0;
    }
