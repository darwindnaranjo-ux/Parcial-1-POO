//Librerias y/o bibliotecas
#include <iostream>
#include <string>
#include <iomanip>

//Permite usar elementos de la librería estándar sin colocar std::
using namespace std;

//Funcion principal
int main() {
	
	//Declaracion de Variables
	int tipo_cliente;
	float monto;
	int plazo;
	bool codeudor;
	float interes;
	float total;
	
	
	//titulo
	cout << "          --- Prestamos Bancolombia ---  " << endl << endl;
	
	//explicacion en pantalla
	cout <<" Bienvenido... Solicite aqui el prestamo que desea adquirir." << endl << " Rellene el formulario acontinuacion: " << endl << endl;
	
	//preguntas en pantalla, recoleccion de datos
	cout << "   Seleccione una opcion (Ocupacion) " << endl << "1. Estudiante " << endl << "2. Empleado" << endl;
	cout << "3. Pensionado" << endl << "4. Desempleado" << endl;
	
	cout << "-  Ingresa un numero entre 1 y 4 segun tu ocupacion: ";
	
	while (true) { //VALIDACIÓN DE ENTRADA TIPO_DE_CLIENTE
		cin >> tipo_cliente;
		
		if(cin.fail()) { //Si ingresan un numero correcatmnete devuelve fail
			cin.clear(); //Quitamos el estado de error del cin
			cin.ignore(1000,'\n'); //Borra lo que quedó escrito en el bufer milcaracteres o hasta un enter
			cout << endl <<"\aEntrada inválida. No puedes ingresar letras." << endl << "-  Ingresa un numero entre 1 y 4: ";
			continue;
		}
		
		if(tipo_cliente >=1 && tipo_cliente <=4)
					break; //sale cuando ya se cumplio la condicion correcta
		
		cout << endl <<"\aError. Número fuera de rango" << endl << "-  Ingresa un numero entre 1 a 4: ";
	}
	
	cout << endl << "- Montos limites para clientes: " << endl << endl;
	cout << " Estudiante: desde 2.000.000 sin codeudor hasta 5.000.000 con codeudor." <<endl;
	cout << " Empleado: desde 5.000.000 sin codeudor hasta 10.000.000 con codeudor." << endl;
	cout << " Pensionado: desde 3.000.000 sin codeudor hasta 7.000.000 con codeudor." << endl;
	cout << " Desempleado: hasta 2.000.000 con codeudor." << endl;
	cout << "- Ingrese el monto solicitado: " ;
	
	while (true) { //VALIDACION DE ENTRADA DEL MONTO_SOLICITADO
		cin >> monto;
		
		if(cin.fail()) { //Si ingresan un numero correcatmnete devuelve fail
			cin.clear(); //Quitamos el estado de error del cin
			cin.ignore(1000,'\n'); //Borra lo que quedó escrito en el bufer milcaracteres o hasta un enter
			cout << endl <<"\aEntrada inválida. No puedes ingresar letras." << endl << "-  Ingrese el monto solicitado: ";
			continue;
		}
		if(monto >= 1)
					break; //sale cuando ya se cumplio la condicion correcta
		
		cout<<"\aError. Número fuera de rango" << endl << "-  Ingrese el monto solicitado: ";
		
	}
	
	
	
	cout << "-  Ingrese el plazo en meses: ";
	
	while (true) { //VALIDACION DE ENTRADA DE CANTIDAD_DE_MESES
		cin >> plazo;
		
		if(cin.fail()) { //Si ingresan un numero correcatmnete devuelve fail
			cin.clear(); //Quitamos el estado de error del cin
			cin.ignore(1000,'\n'); //Borra lo que quedó escrito en el bufer milcaracteres o hasta un enter
			cout << endl <<"\aEntrada inválida. No puedes ingresar letras." << endl << "-  Ingrese el monto solicitado: ";
			continue;
		}
		if(plazo > 0)
					break; //sale cuando ya se cumplio la condicion correcta
		
		cout << endl <<"\aError. Número fuera de rango" << endl << "- Ingrese un numero positivo:  ";
		
	}
	
	
	
	cout << "- ¿Cuenta con un codeudor para respaldar el credito?" << endl << "-  Ingrese UNO (1) para Sí o marque CERO (0) para No: ";
	
	while (true) { //VALIDACION DE ENTRADA CODEUDOR
		cin >> codeudor;
		
		if(cin.fail()) { //Si ingresan un numero correcatmnete devuelve fail
			cin.clear(); //Quitamos el estado de error del cin
			cin.ignore(1000,'\n'); //Borra lo que quedó escrito en el bufer milcaracteres o hasta un enter
			cout << endl <<"\aEntrada inválida. Inténtalo de nuevo." << endl << "-  Ingrese UNO (1) para Sí o marque CERO (0) para No: ";
			continue;
		}
		if(codeudor == 0 || codeudor == 1)
					break; //sale cuando ya se cumplio la condicion correcta
		
		cout<<"\aError. Número fuera de rango" << endl << "-  Ingresa UNO (1) o CERO (0): ";
	}
	

	
	//switch - case para cada tipo de cliente
	switch(tipo_cliente){
		
	case 1: //Para estudiante
		
		//if- comprobar limite credito
		if(codeudor){
			
			if(monto > 5000000){
				
				cout << endl << " Prestamo rechazado. El monto es demasiado alto para calificar." << endl;
				return 0;
			
			}
		
		}else{
			
			if (monto > 2000000){
				
				cout << endl << " Prestamo rechazado. Sin codeudor, el monto es demasiado alto para calificar."<< endl;
				return 0;
				
			}
			
		}
		
		
		//validar plazos segun los montos
		if(plazo > 12 && monto <= 2000000){
			
			cout << endl << "Prestamo rechazado, plazo para pago es demasiado alto para el monto a adquirir." << endl;
			return 0;
			
		}else if( plazo >= 24 && monto > 2000000 && monto < 5000000){
			
			
			cout << endl << "Prestamo rechazado, plazo para pago es demasiado alto para el monto a adquirir." << endl;
			return 0;
			
		}
		
		
		//calculo para saber el monto total
		interes = monto * 0.06 * plazo;
		total = monto + interes;
		
		//Resultado en pantalla
		cout << fixed << setprecision(0);
		cout << endl << endl << "El prestamos solicitado por un monto de $" << 
			monto << " a un plazo de " << plazo << " meses es aprobado con una tasa del 6%" << endl <<
			"Total a pagar: $" << total << endl;
		
		break; //salir del switch - case
		
		
		
		/*----------------------------------------------------------*/
		
		
		
		
		
		
	case 2: //Para Empleado
		
		//if- comprobar limite credito
		if(codeudor){
			
			if(monto > 10000000){
				
				cout << endl << " Prestamo rechazado. El monto es demasiado alto para calificar." << endl;
				return 0;
				
			}
			
		}else{
			
			if (monto > 5000000){
				
				cout << endl << " Prestamo rechazado. Sin codeudor, el monto es demasiado alto para calificar."<< endl;
				return 0;
				
			}
			
		}
		
		
		//validar plazos segun los montos
		if(plazo > 24 && monto <= 2000000){
			
			cout << endl << "Prestamo rechazado, plazo para pago es demasiado alto para el monto a adquirir." << endl;
			return 0;
			
		}else if( plazo > 48 && monto > 5000000 && monto < 10000000){
			
			
			cout << endl << "Prestamo rechazado, plazo para pago es demasiado alto para el monto a adquirir." << endl;
			return 0;
			
		}
		
		
		
		//calculo para saber el monto total
		if(plazo > 36){
			
			interes = monto * 0.085 * plazo;
			
		}else{
			
			interes = monto * 0.07 * plazo;
		}
		
		if(codeudor){
			
			interes -= (interes*0.1);
			
		}
		
		total = monto + interes;
		
		//Resultado en pantalla		
		
		if(plazo > 36){
			cout << fixed << setprecision(0);
		cout << endl << endl << "El prestamos solicitado por un monto de $" << 
			monto << " a un plazo de " << plazo << " meses es aprobado con una tasa del 8.5%" << endl <<
			"Total a pagar: $" << total << endl;;
		}else{cout << fixed << setprecision(0);
			                cout << endl << endl << "El prestamos solicitado por un monto de $" <<    monto << " a un plazo de " << plazo << " meses es aprobado con una tasa del 7%" << endl <<				                        "Total a pagar: $" << total;
		}	break; //salir del switch - case
		
		
		
		
		/*----------------------------------------------------------*/
		
		
		
		
		
	case 3: //Para Pensionado
		
		//if- comprobar limite credito
		if(codeudor){
			
			if(monto > 7000000){
				
				cout << endl << " Prestamo rechazado. El monto es demasiado alto para calificar." << endl;
				return 0;
				
			}
			
		}else{
			
			if (monto > 3000000){
				
				cout << endl << " Prestamo rechazado. Sin codeudor, el monto es demasiado alto para calificar."<< endl;
				return 0;
				
			}
			
		}
		
		
		//validar plazos segun los montos
		if(plazo > 24 && monto <= 3000000){
			
			cout << endl << "Prestamo rechazado, plazo para pago es demasiado alto para el monto a adquirir." << endl;
			return 0;
			
		}else if( plazo > 36 && monto > 3000000 && monto < 7000000){
			
			
			cout << endl << "Prestamo rechazado, plazo para pago es demasiado alto para el monto a adquirir." << endl;
			return 0;
			
		}
		
		
		//calculo para saber el monto total
		interes = monto * 0.04 * plazo;
		if(codeudor){
			
			interes -= interes * 0.1;
		}
		total = monto + interes;
		
		
		//Resultado en pantalla		
		cout << fixed << setprecision(0);
		cout << endl << endl << "El prestamos solicitado por un monto de $" << 
			monto << " a un plazo de " << plazo << " meses es aprobado con una tasa del 4%" << endl <<
			"Total a pagar: $" << total;
		
		break; //salir del switch - case
		
		
		
		/*----------------------------------------------------------*/
		
		
		
	case 4: //Para Desempleado
		
		//if- comprobar limite credito
		if(codeudor){
			
			if(monto > 2000000){
				
				cout << endl << " Prestamo rechazado. El monto es demasiado alto para calificar." << endl;
				return 0;
				
			}
			
		}else{
			
			cout << endl << "Pago rechazado. No cuenta con codeudor." << endl;
			return 0;
			
			}
			
		
		
		
		//validar plazos segun los montos
		if(plazo > 12 && monto <= 2000000){
			
			cout << endl << "Prestamo rechazado, plazo para pago es demasiado alto para el monto a adquirir." << endl;
			return 0;
			
		}
		
		
		//calculo para saber el monto total
		interes = monto * 0.08 * plazo;
		total = monto + interes;
		
		
		//Resultado en pantalla		
		cout << fixed << setprecision(0);
		cout << endl << endl << "El prestamos solicitado por un monto de $" << 
			monto << " a un plazo de " << plazo << " meses es aprobado con una tasa del 8%" << endl <<
			"Total a pagar: $" << total;
		
		break; //salir del switch - case
		
	}
	
	
	
	
	
	
	return 0;
	
}
