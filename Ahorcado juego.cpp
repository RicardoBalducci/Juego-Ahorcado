#include <iostream>//nos permita obtener e imprimir valores en pantalla
#include <stdlib.h>//libreria estandar de entrada y salida de datos
#include <string.h>//biblioteca para manipular cadenas.
using namespace std;

string palabra_original;//declaramos variable string que contenga la palabra 

string palabra_mostrar;//se mostrara la cadena al finalizar

int intentos;//cantidad de intentos que tiene la persona para adivinar
char regreso;
void mostrar();//metodo que muestra la cantidad de intentos y la palabra a mostrar
void ingresar(char x);//metodo que retorna un caracter esto para comprobar si coincide con algun caracter de la palabra
void inicializar ();//metodo donde se almacena la palabra y desarrolla el juego


int main(){
	cout<<"\n\n---------------Bienvenidos al Juego del Ahorcado--------------";//aqui damos como primera pautas las reglas y condiciones del juego
	cout<<"\n\n--------------------------Condicion------------------------------";
	cout<<"\n\n-------------------Cuenta con 6 intentos----------------------";
	cout<<"\n\n---------------------Si acierta ganara------------------------";
	cout<<"\n\n-----------------Espero tenga mucha suerte--------------------";
	
	inicializar();//empezamos con el metodo de inicialización
	
	mostrar();//posteriormente empezamos el juego mostrando los intentos y la cantidad de letras que conforma la palabra

		while (intentos >0 && palabra_mostrar!= palabra_original){//creamos un While que nos indica que se repetira mientas que los intentos sean mayores a 0 y si la palabra a mostrar es diferente de la palabra original
			char letra;//declaramos una variable llama letra
			cout<<"\nIngrese una letra: ";//pedimos a la persona que la ingrese
			cin>>letra;//se almacena en la variable
			ingresar(letra);//la letra ingresada pasa por el metodo ingresar()
			mostrar();//posteriormente se muestra
			
			if (palabra_mostrar == palabra_original)//para finalizar el juego usamos un if que, en caso de que la palabra_mostrar sea igual a la palabra_original finaliza el juego
			{
				cout<<"\nFelicidades!";
				cout<<"\nDesea realizar un nuevo Juego (S/N)";//indicamos si desea volver a jugar
				cin>>regreso;
					if (regreso == 'S' || regreso == 's')//y en caso de ser asi
					{
						system("pause");//pausamos el programa
						system("cls");//limpiamos la pantalla
						return main();//se inicia de nuevo
					}
			}
		}
}

void mostrar(){//aplicacion del metodo mostrar
	cout<< "\n\nIntentos: "<<intentos<<endl; //nos indica la cantidad de intentos que tenemos
	cout<<palabra_mostrar<<endl;//nos muestra la palabra oculta
}

void inicializar (){//aplicación del metodo inicializar
	intentos = 6;//indicamos la cantidad de intentos
	
	//pedimos que la palabra que se introduzca se almacene en la variable palabra_original y pasamos a pausar y limpiar la pantalla
	cout<<"\n\n\nintroduzca una palabra: ";
	cin>> palabra_original;
	system("pause");
	system("cls");

	for(int i =0; i <palabra_original.length();i++){ //por medio de un bucle for, recorremos toda la palabra 
			if(palabra_original [i] >= 'A' && palabra_original [i] <= 'Z' ) //verificamos que todos los caracteres coincidan con todas las letras del abecedario
			{
				palabra_original[i] = 32;
			}
	}
	
	for(int i =0; i <palabra_original.length();i++){// utilizamos un bucle for para recorrer la palabra original
		if(palabra_original [i] >= 'a' && palabra_original [i] <= 'z' ){//mediante un if recorremos todos los caracteres
			palabra_mostrar+= '*';//y cada caracter es cambiado por _
		}
		else
		{
			palabra_mostrar+=palabra_original [i];
		}
	}
}
void ingresar(char x){//metodo de ingresar con parametro char x
		bool fallidos = true;//en caso de que no coincida la letra de la palabra_mostrar con una letra de la palabra_original la variable fallidos sera verdadera
		int fallido= 0;
		for (int i=0; i<palabra_original.length();i++){ //recorremos la palabra usando for
			if  (x== palabra_original[i]){//si la palabra coincide con una letra de la palabra_original
				fallidos = false;//fallidos pasa a ser false 
				palabra_mostrar[i]=x;//y la letra a mostrar cambia por x
		 	}
		}
		if(fallidos) {//si llega a ver fallidos llega a cumplirse
			intentos--;//disminuye la cantidad de intentos
			cout<<"\nLa letra "<<x<<" no se encuentra en la palabra";//se indica la letra que no corresponde a la palabra 
			cout<<"\nIntentos Fallidos: "<<++fallido;//se muestra la cantidad de fallos restantes
		}
		
		if(intentos < 1){//si la cantidad de intentos llega a ser menos a 1
			cout<<"\n\n Total de Intentos Fallidos: "<<fallido;//se muestra la cantidad de intentos fallidos
			cout<<"\nLa palabra era "<<palabra_original;
			cout<<"\nLo siento, Fin del juego";
		}	
}
