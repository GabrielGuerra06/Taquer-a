#include <iostream>
#include <math.h>
using namespace std;

struct tacos{
float No;
string sabor[30]; 
int limones,cantidad;
char salsa[30];
int precios[30];
char bebidas[30];
};
int cantidad;
void LeerDatos(tacos *pArregloTacos);
void ImprimirDatos(tacos *pArregloTacos);
void FiltrarTacos(tacos *pArregloTacos);
void ModificarDatos(tacos *pArregloTacos);
void EliminarDatos(tacos *pArregloTacos);
/////////////////////////////////////////////////
int main() {
  int opc;
  bool flag=false;
  int continuar;
  tacos arregloTacos[10];
tacos *pArregloTacos = arregloTacos;
  do{
        
    cout<<endl;
      cout<<"--------------------------------------------------\n";
    cout<<"        Bienvenidos a TAQUERIA LOS GUERRAS \n";
 cout<<"--------------------------------------------------\n";
    
cout<<"\n--------------INSTRUCCIONES--------------\n";
  cout<<"1. Pedir orden al mesero \n";
  cout<<"2. Mostrar tu orden \n";
  cout<<"3. Buscar tacos por No. \n";
  cout<<"4. Modificar tu orden \n";
  cout<<"5. Eliminar tacos \n";
  cout<<"6. Salir de la taquería \n";
    cout<<"--------------------------------\n";
  cin>>opc;
  
  switch(opc){
    case 1: 
     LeerDatos(pArregloTacos);
      flag=true;
    break;
    case 2:
      if(flag==true){
    ImprimirDatos(pArregloTacos);
      }
      else{
        cout<<"ALTO AHÍ, primero debes pedir la orden \n";
      }
    break;
    case 3:
      if(flag==true){
      FiltrarTacos(pArregloTacos);
      }
      else{
        cout<<"ALTO AHÍ, primero debes pedir la orden \n";
      }
    break;
    case 4:
      if(flag==true){
      ModificarDatos(pArregloTacos);
      }
      else{
        cout<<"ALTO AHÍ, primero debes pedir la orden \n";
      }
       
    break;
    case 5:
      if(flag==true){
      EliminarDatos(pArregloTacos);
      }
      else{
        cout<<"ALTO AHÍ, primero debes pedir la orden \n";
      }
      
    break;
    case 6:
     cout<<"\n HASTA LUEGO VUELVA PRONTO";
    break;
    default:
    cout<<"INGRESA UNA OPCION VALIDA \n";
     
    break;
  }   
  }while(opc!=6);
  }
///////////////////////////////////////////////////


    void LeerDatos(tacos *pArregloTacos){
      cout<<"----------------MENU----------------\n";
      cout<<"\n Asada ---$15";
      cout<<"\n Pastor---$16";
      cout<<"\n Chorizo---$12";
      cout<<"\n Lengua---$20";
      cout<<"\n Suadero---$13";
      cout<<"\n Cabeza---$14";
      cout<<"\n Tripa---$15";
      cout<<"\n----------------------------------\n";
      cout<<"\n cuantas personas van a pedir? "<<endl;
      cin>>cantidad;
      for(int i=0; i<cantidad; i++){
        
        cin.ignore();
        pArregloTacos[i].No=i+1;
        cout<<"---------------------------\n";
        cout<<"Tu número de orden es: "<<pArregloTacos[i].No;
        cout<<"\n---------------------------\n";
        cout<<"\n Cuantos tacos va a querer?";
        cin>>pArregloTacos[i].cantidad;
        for(int j=0; j<pArregloTacos[i].cantidad; j++){
           cout<<"----Ingresa el sabor del taco "<<j+1<<" :";
        cin>>(pArregloTacos[i].sabor[j]);
        }
  
        cout<<"----Cuantos limones quieres para tus tacos: ";
        cin>>(pArregloTacos[i].limones);
           cout<<"----Ingresa la salsa para tus tacos ('verde'o'roja'): ";
        cin.ignore();
        cin.getline (pArregloTacos[i].salsa,30);
      for(int j=0; j<pArregloTacos[i].cantidad; j++){
         cout<<"\n ingresa el precio del taco "<<j+1<<" :";
        cin>>(pArregloTacos[i].precios[j]); 
      }
       
        }
      }
  
  void ImprimirDatos(tacos *pArregloTacos){
      for(int i=0; i<cantidad; i++){
      cout<<endl;
      cout<<"\n No. de orden: "<<pArregloTacos[i].No;
        for(int j=0; j<pArregloTacos[i].cantidad; j++){
      cout<<"\n ---------------Taco "<<j+1<<" :"<<pArregloTacos[i].sabor[j]<<"  $"<<pArregloTacos[i].precios[j];
          }
      cout<<"\n Limones: "<<pArregloTacos[i].limones;
      cout<<"\n Salsa del taco: "<<pArregloTacos[i].salsa;
      }
  }

void FiltrarTacos(tacos *pArregloTacos){
float filtro;
int cuenta=0;
bool encontro=false;
cout<<"Ingresa el No de orden: ";
cin>>filtro;

for(int i=0; i<cantidad;i++){
  if(filtro==pArregloTacos[i].No) {
     for(int j=0; j<pArregloTacos[i].cantidad; j++){
      cout<<"\n ---------------Taco "<<j+1<<" :"<<pArregloTacos[i].sabor[j]<<"  $"<<pArregloTacos[i].precios[j];
       cuenta+=pArregloTacos[i].precios[j];
          }
  encontro=true;
  cout<<"\n Limones: "<<pArregloTacos[i].limones<<"\n Numero de orden: "<<pArregloTacos[i].No<<"\n Salsa: "<<pArregloTacos[i].salsa<<"\n";
    cout<<"el total de su orden es: "<<cuenta<<"\n";}

else if(encontro==false){
cout<<" ";}
}
if(encontro==false){
  cout<<"\n No inexistente, ingrese otro \n";}
  }

void ModificarDatos(tacos *pArregloTacos){
   float filtro;
  float promedio=0;
bool encontro=false;
  string dato;
  string cambio;
  int cali;
  int numTaco;
  cout<<"Ingresa el No de orden a modificar datos";
cin>>filtro;

for(int i=0; i<cantidad;i++){
  if(filtro==pArregloTacos[i].No) {
  encontro=true;
  cout<<"\n Que dato quieres modificar? (sabor, limones, salsa, precios)";
    cin>>dato;
   
    if(dato=="sabor" || dato=="Sabor" || dato=="SABOR"){
      cout<<"que numero de taco quiere modificar? (0, "<<pArregloTacos[i].cantidad<<" )";
      cin>>numTaco;
      if(numTaco>0 && numTaco<=pArregloTacos[i].cantidad){
        cout<<"Ingresa el nuevo sabor del taco: ";
      cin>>pArregloTacos[i].sabor[numTaco];   
    cout<<"\n Su nuevo sabor es: "<<pArregloTacos[i].sabor[numTaco];
      }
      else{
        cout<<"Numero de taco no permitido";
      }
      }
      

    else if(dato=="limones" || dato=="Limones" || dato=="LIMONES"){
    cout<<"Ingresa la nueva cantidad de limones del alumno";
    cin>>pArregloTacos[i].limones;   
    cout<<"\n Su nueva cantidad de limones es: "<<pArregloTacos[i].limones;}

    else if(dato=="salsa" || dato=="Salsa" || dato=="SALSA"){
    cout<<"Ingresa la nueva salsa del alumno: ";
    cin>>pArregloTacos[i].salsa;   
    cout<<"\n Su nueva salsa es: "<<pArregloTacos[i].salsa;}

else if(encontro==false){
cout<<" ";}
}
 }
}
void EliminarDatos(tacos *pArregloTacos){
  float filtro;
  string dato, cambio;
  int cali, opcion, numTaco;
  
  
for(int i=0; i<1;i++){
  cout<<"Ingresa el No de orden";
cin>>filtro;
  if(filtro==pArregloTacos[i].No) {
  
    cout<<" \n 1. Eliminar un taco \n 2. Eliminar la orden completa";
    cin>>opcion;
    if(opcion==1){
      cout<<"que numero de taco quiere modificar? (0, "<<pArregloTacos[i].cantidad<<" )";
      cin>>numTaco;
      if(numTaco>=0 && numTaco<=pArregloTacos[i].cantidad){
        pArregloTacos[i].sabor[numTaco]="";
        cout<<"Taco eliminado";
    }
      }
    else if(opcion==2){
     cout<<"\n Usuario eliminado";
    *pArregloTacos[i].sabor="";
    pArregloTacos[i].limones=0;
    pArregloTacos[i].No=0;
    *pArregloTacos[i].salsa=0; 
    }
    else{
      cout<<"Opcion incorrecta";
    }
}
  else{
    cout<<"Número de orden incorrecto";
  }
  }
  }



