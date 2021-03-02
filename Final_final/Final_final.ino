#include <LiquidCrystal.h>
#include "keypad_shield.h"

#define BOT_RIGHT  0
#define BOT_UP     1
#define BOT_DOWN   2
#define BOT_LEFT   3
#define BOT_SELECT 4
#define BOT_NONE   5

#define liberado True;

int clave[3]= {0,0,0};

int indice_clave = 0; //Para recorrer la clave
int boton=5; // Seteamos el boton en none
int caracter_actual;

LiquidCrystal lcd(8,9,4,5,6,7);

//Funciones
void Ingresar_clave(int arreglo[]);
bool chequear_clave(int clave,int clave_check);

void setup()
{
    lcd.begin(16,2); 
    lcd.clear();
    lcd.setCursor(0,0);
    Ingresar_clave(clave);
    lcd.clear();
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print("Clave guardada");
    lcd.setCursor(0,1);
    lcd.print("BLOQUEADO");
    delay(2000);
    lcd.clear();
}

void loop()
{
    int clave_check[3]= {0,0,0};
    Ingresar_clave(clave_check);

    bool coincide=chequear_clave(clave,clave_check);
    lcd.setCursor(0,0);
    if(coincide==true)
    {
        lcd.clear();
        lcd.print("Clave Correcta");
        delay(2000);
        lcd.setCursor(0,1);
        lcd.print("LIBERADO");
    }
    else
    {
        lcd.clear();
        lcd.print("Clave Incorrecta");
    }
    delay(2000);
    lcd.clear();
}

//Chequea si es correcta
bool chequear_clave(int clave[],int clave_check[])
{
    if( clave[0]==clave_check[0] && clave[1]==clave_check[1] && clave[2]==clave_check[2])
        return true;
    else
        return false;
}

//Solicita la clave
void Ingresar_clave(int clave[])
{
    //clave_check[3]={0,0,0};
    lcd.setCursor(0,0);
    indice_clave=0;
    lcd.print("Ingrese clave:");
    lcd.setCursor(0,1);
    lcd.cursor();
    lcd.blink();
    do
    {
        delay(200);
        Serial.flush();
        boton=read_LCD_buttons();
        switch(boton)
        {
        case BOT_LEFT: //Si presionamos el boton izquierdo
            if(indice_clave==0)
            {
                indice_clave=2;
                lcd.setCursor(indice_clave,1);
            }
            else
            {
                indice_clave--;
                lcd.setCursor(indice_clave,1);
            }

            break;
        case BOT_RIGHT: //Si presionamos el boton derecho
            if(indice_clave==2)
            {
                indice_clave=0;
                lcd.setCursor(indice_clave,1);
            }
            else
                indice_clave++;
            lcd.setCursor(indice_clave,1);
            break;

        case BOT_UP:
            if(clave[indice_clave]==9)
            {
                clave[indice_clave]=0;
                lcd.setCursor(indice_clave,1);
                lcd.print(clave[indice_clave]);
            }
            else
            {
                clave[indice_clave]++;
                lcd.setCursor(indice_clave,1);
                lcd.print(clave[indice_clave]);
            }
            break;
        case BOT_DOWN:
            if(clave[indice_clave]==0)
            {
                clave[indice_clave]=9;
                lcd.setCursor(indice_clave,1);
                lcd.print(clave[indice_clave]);
            }
            else
            {
                clave[indice_clave]--;
                lcd.setCursor(indice_clave,1);
                lcd.print(clave[indice_clave]);
            }
            break;
        }
    }
    while(boton!=BOT_SELECT);

}
