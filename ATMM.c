#include<stdio.h>
int valida(float x)
{
	if(x>0){
	
	printf("La cantidad ingresada es valida: "); 
	if(x==0)
	      printf("La cantidad ingresada es 0, \nNo me hagas perder el tiempo.");
	      return 1;
	}else
	{
		printf("La cantidad ingresada es negativa, \nIngresa valores positivos.");
		return 101;
	}
	return 0;
}
      float retirarDinero(float saldo)
        { int retiro;
	        printf("Tu saldo es de %.2f.", saldo);
         
		do{
				printf("\nIngresa la cantidad que desea retirar sin exceder su saldo: ");
			scanf("%d", &retiro);
			if (retiro>saldo||retiro<0){
				printf("La cantidad es invalida, vuelve a intentarlo.");
			}
			}
			while(retiro>saldo||retiro<0);
			saldo=saldo-retiro;
			printf("Este es tu saldo despues de tu movimiento: %.2f", saldo);
			
			return saldo;
         }

float consultarSaldo(float saldo){
	
	printf("Tu saldo actual es de: %.2f", saldo);
	return saldo;
}

int pinSeguridad(){
	int pin, intento=0, pin2;
	printf("\nRegistre un PIN de seguridad: ");
	scanf("%d", &pin);
	while(intento<3){
		printf("\nIngresa tu PIN: ");
		scanf("%d", &pin2);
		
		if (pin==pin2){
			printf("\nEl PIN es correcto, bienvenido.");
			return 1;
		}
		else{
			printf("\nEl PIN es incorrecto, intento numero %d", intento+1);
		}
		intento++;
	}
	printf("\nCuenta bloqueada, has superado los intentos fallidos.");
	return 0;
	
	
}

int main(){
	float saldo[3]={1000, 2000, 3000}, deposito;
	int opc, v, retiro, cuenta;
	 if (!pinSeguridad()) {
        return 0;  
    }
    
    do{
    	printf("\nFavor de seleccionar la cuenta deseada: 0, 1 o 2 ");
    	scanf("%d", &cuenta);
    	if(cuenta<0||cuenta>3)
		{
    	printf("\nLa cuenta es invalida favor de seleccionar una cuenta existente!!");	
		}
	}
    while(cuenta<0||cuenta>3);
    
do{	
	printf("\n\nBienvenido a su cajero automatico.\n Por favor seleccione la opcion que desea.\n");
	printf(" 1) Consultar saldo\n 2) Depositar dinero.\n 3) Retirar dinero.\n 4) Salir.\n");
	scanf("%d", &opc);


	switch (opc) {
		
		case 1:
			saldo[cuenta]=consultarSaldo(saldo[cuenta]);
			break;
		case 2:
			printf("\n Ingresa la cantidad que deseas depositar: \n");
			scanf("%f", &deposito);
			v=valida(deposito);
			while(v!=1)
			{
				scanf("%f", &deposito);
				v= valida(deposito);
			}
			saldo[cuenta]=saldo[cuenta]+deposito;
			printf("\nTu nuevo saldo es: %.2f", saldo[cuenta]);
			break;	
		case 3:
		    saldo[cuenta]=retirarDinero(saldo[cuenta]);
		
			break;
	
	}
} while(opc>0&&opc<4);
	
	
	
	
	return 0;
}

