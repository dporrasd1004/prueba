#include <iostream>
#include <string>
#include <cstdlib>
#include "frase.h"

#include <fstream>

using namespace std;
// Metodo para limpiar pantalla
void limpiar2() { cout << "\033[2J\033[0;0H"; }
// Metodo para esperar se presion una tecla para continuar
void esperar2() {
    char w;
    do {
        cout << "Presione S y Enter para Salir..."; cin >> w;
    } while (toupper(w) != 'S');

}
Frase::Frase(){
  //Palabra();
}
void Frase::iniArchivo(){
   cout<<"Inicializando Archivo de texto"<<endl;
   ofstream of;
   of.open("datos.txt");
   of.close();
   esperar2();
}
void Frase::agregarFrases(){
       char fraseEntrada3[318];
       string fraseEntrada,fraseEntrada1,fraseEntrada2;
       bool sigue=true;
       ofstream of("datos.txt",ios::app);        
       cout<<"[1] Typee 1 para salir"<<endl;
       cout<<"[2] Typee 2 para guardar"<<endl;       
       cout<<"Typee la frase y presione enter para generar una lineanueva\n";
        while (sigue==true){
               cout << ": "<<endl;
               cin.getline(fraseEntrada3,318);
               fraseEntrada2=fraseEntrada3;  
               if ((fraseEntrada2=="1") || (fraseEntrada2=="2")) {sigue=false; }
               else {
                  if (fraseEntrada2.length()>212){
                  fraseEntrada1=fraseEntrada2.substr(0,106)+"\n";  
                  fraseEntrada=fraseEntrada+fraseEntrada1; 
                  fraseEntrada1=fraseEntrada2.substr(107,211)+"\n"; 
                  fraseEntrada=fraseEntrada+fraseEntrada1;
                  fraseEntrada1=fraseEntrada2.substr(212,318); 
               }
               else if ((fraseEntrada2.length()>200) && (fraseEntrada2.length()<213)){
                  fraseEntrada1=fraseEntrada2.substr(0,106)+"\n";  
                  fraseEntrada1=fraseEntrada2.substr(107,211); 
               }
               else{
                  fraseEntrada1=fraseEntrada2.substr(0,106);  
               }
               fraseEntrada=fraseEntrada+fraseEntrada1+"\n"; 
               }
        }
        if (fraseEntrada2=="2") of << fraseEntrada;
        of.close();
        cout<<"-----Se han agregado las frases al archivo-----"<<endl;
        esperar2();
}
void Frase::convertirarchivo(){
      int vuelta=0; 
      int inicio=0;
      int tam=0;
      int tam2=0;
      int cantCaracteres=104;
      string fraseEntrada,fraseEntrada2,fraseSalida,fraseF;
      ifstream fe("datos.txt");
      while(!fe.eof()) {
           getline(fe, fraseEntrada); 
           if (fraseEntrada.length()>cantCaracteres){
             vuelta=fraseEntrada.length()/cantCaracteres; 
             tam=fraseEntrada.length();
             tam2=fraseEntrada.length()-(4*cantCaracteres);
             fraseSalida="";
             for (int i=0; i<vuelta; i++){
                if (i==(vuelta-1)){
                  fraseEntrada2=fraseEntrada.substr(0,cantCaracteres);
                  fraseSalida=fraseSalida+fraseEntrada2+"\n";
                  fraseEntrada2=fraseEntrada.substr(cantCaracteres,tam2);
                }
                else {
                  fraseEntrada2=fraseEntrada.substr(0,cantCaracteres);
                  fraseEntrada=fraseEntrada.substr(cantCaracteres,fraseEntrada.length());
                }
                fraseSalida=fraseSalida+fraseEntrada2+"\n";
              
             }
             fraseF=fraseF+fraseSalida;
        
           } else fraseF=fraseF+fraseEntrada+"\n";
           
       }
       cout<< fraseF << endl;
       fe.close();
       ofstream of;
       of.open("datos.txt");
       of << fraseF;
       of.close();
       esperar2();
       
}
void Frase::leerArchivo(){
   //convertirarchivo();
   string fraseEntrada;
   char fraseEntrada1[106];
      ifstream fe("datos.txt");
      while(!fe.eof()) {
           fe.getline(fraseEntrada1, 106,'\n'); // lee la linea de 80 caracteres y lo guarda en la variable fraseEntrada \n paraindicar fin delinea
           cout<< fraseEntrada1 << endl;
       }
       fe.close();
       esperar2();
   
}
void Frase::cuentaPalabra(){
     char fraseEntrada1[106];
     string fraseEntrada;
     string palabra, num2;
     int numero=0;
     cout<<"Ingrese la palabra a buscar: ";
     cin>>palabra;
     ifstream fe("datos.txt");
       while(!fe.eof()) {
           fe.getline(fraseEntrada1, 106,'\n');
           fraseEntrada=fraseEntrada1;
           if (buscarPalabra(fraseEntrada,palabra)==true) numero=numero+1;
           fraseEntrada=fraseEntrada1;
       }
       fe.close();
       num2=numero;
       cout<<"LA palabra '"+palabra+"' aparece: ";
       cout<<numero;
       cout<<" veces en el archivo"<<endl;
       esperar2();
}
void Frase::buscaPalabra(){
      char frase[106];
      string fraseEntrada;
      string palabra;
      bool encontrado=false;
      int numero=0;
       cout<<"Ingrese la palabra a buscar: ";
       cin>>palabra;
       ifstream fe("datos.txt");
       while(!fe.eof()) {
           fe.getline(frase, 106,'\n');
           fraseEntrada=frase;
           if (buscarPalabra(fraseEntrada,palabra)==true) {
              numero=numero+1;
              cout<<"Encontrada en linea:";
              cout<<numero;
              cout<<" "<<fraseEntrada<<endl;
              encontrado=true;
           }
       }
       if (encontrado==false) cout<<"No se encontraron coincidencias "<<endl;
       fe.close();
       esperar2();
}
void Frase::reemplazar(){
  char frase[106];
  string fraseEntrada, fraseF;
  string palabra,palabra2;
  bool encontrado=false;
  int numero=0;
  cout<<"Typee la palabra a buscar: ";             
  cin>>palabra;
  cout<<"Typee la palabra de reemplazo: ";
  cin>>palabra2;
  ifstream fe("datos.txt");
  while(!fe.eof()) {             
    fe.getline(frase, 106,'\n');
    fraseEntrada=frase;                    
    if (buscarPalabra(fraseEntrada,palabra)==true) {
      fraseF=fraseF+sustituyePalabra(fraseEntrada,palabra,palabra2)+"\n"; 
                      encontrado=true;
                  }
    else{ fraseF=fraseF+fraseEntrada+"\n"; }
  }
  fe.close();
  if (encontrado==false) cout<<"No se encontraron coincidencias "<<endl;
  else {
      ofstream of;
      of.open("datos.txt");
      of << fraseF;
      of.close();
      cout<<"Procesado...."<<endl;
  }
  esperar2();
}
void Frase::encriptaFrases(){
  char fraseEntrada1[106];
  string fraseEntrada;
  ifstream fe("datos.txt");
  while(!fe.eof()) {
     fe.getline(fraseEntrada1, 106,'\n');
     if (string(fraseEntrada1).length()!=0)
     fraseEntrada=fraseEntrada+encriptar(fraseEntrada1)+"\n";
  }
  fe.close();
  ofstream of;
  of.open("datos.txt");
  of<< fraseEntrada;
  of.close();
  cout<<"Texto del Archivo fue encriptado"<<endl;
  esperar2();
}
void Frase::desencriptaFrases(){
  char fraseEntrada1[106];
  string fraseEntrada;
  ifstream fe("datos.txt");
  while(!fe.eof()) {
      fe.getline(fraseEntrada1, 106,'\n'); 
      if (string(fraseEntrada1).length()!=0)
      fraseEntrada=fraseEntrada+desencriptar(fraseEntrada1)+"\n";
  }
  fe.close();
  ofstream of; 
  of.open("datos.txt");
  of << fraseEntrada;
  of.close();
  cout<<"Informacion del archivo fue desencriptado"<<endl;
  esperar2();
}
void Frase::alineaDerecha(){
   char Entrada[106];
   string fraseEntrada,control;
   ifstream fe("datos.txt");
   while(!fe.eof()) {

      fe.getline(Entrada, 106,'\n');
      control=Entrada;
      if(control.empty()==true) {}
      else {fraseEntrada+=Derecha(Entrada)+"\n";}
      
    }
    fe.close();
    ofstream of;
    of.open("datos.txt");
    of<< fraseEntrada;
    of.close();
    cout<<"Jutificado el texto del archivo"<<endl;
    esperar2();
}
void Frase::alineaIzquierda(){
   char fraseEntrada1[106]; 
   string fraseEntrada,control;
   ifstream fe("datos.txt");
   while(!fe.eof()) {
       fe.getline(fraseEntrada1, 106,'\n');
       control=fraseEntrada1;
       if(control.empty()==true) {}
       else{fraseEntrada+=Izquierda(fraseEntrada1)+"\n";}
    }
    fe.close();
    ofstream of;
    of.open("datos.txt");
    of<< fraseEntrada;
    of.close();
    cout<<"Alineacion a la Izquierda Realizada"<<endl;
    esperar2();
}
void Frase::alineaCentro(){
  char fraseEntrada1[106];
  string fraseEntrada;
  ifstream fe("datos.txt");
  while(!fe.eof()) {
      fe.getline(fraseEntrada1, 106,'\n');
      fraseEntrada+=Centro(fraseEntrada1)+"\n";
   }
   fe.close();
   ofstream of;
   of.open("datos.txt");
   of<< fraseEntrada;
   of.close();
   cout<<"Archivo Justificado al Centro..."<<endl;
   esperar2();
}
void Frase::justificaFrase(){
  char fraseEntrada1[106];
  string fraseEntrada,control;
  ifstream fe("datos.txt");
  while(!fe.eof()) {
      fe.getline(fraseEntrada1, 106,'\n');
      control=fraseEntrada1;
       if(control.empty()==true) {}
       else{
         fraseEntrada+=Justificado(fraseEntrada1)+"\n";
       }
  }
  fe.close();
  ofstream of;
  of.open("datos.txt");
  of<< fraseEntrada;
  of.close();
  cout<<"Archivo Justificado"<<endl;
  esperar2();
} 
