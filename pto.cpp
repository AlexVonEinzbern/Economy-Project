#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<random>

int N;
double m0, e, w, LN, B, wm, s, suma=0.;
double mi, mj, mi2, mj2, mil0, mjl0, l;
double x, nl, Pn, an, G;


using namespace std;

//Funci�n noahorro.

double noahorro(double m0){
	mi=m0/2.; //Cantidad de dinero del agente i suponiendo que ambos agentes inician con la misma cantidad de dinero. 
	mj=m0/2.; //Cantidad de dinero del agente j.
	mil0=m0/2.; //Cantidad de dinero del agente i teniendo en cuenta que l=0.
	mjl0=m0/2.; //Cantidad de dinero del agente j teniendo en cuenta que l=0.
	
	srand(time(NULL));
	default_random_engine generator;
	generator.seed(time(NULL));
	uniform_real_distribution<double>distribution(0,1);
	
	ofstream file;
	file.open("datos.dat"); 
	
	for(int i=0;i<N;i++){
		e=distribution(generator);
		mil0=e*(mil0+mjl0); 
		mjl0=(1.-e)*(mil0+mjl0);
		
		wm=(1./(m0/2.))*exp(-(1./(m0/2.))*mil0); //Distribucion de Gibbs cuando no se tiene en cuenta l.
        
        LN= log(wm);
		
		file<<mil0<<endl;
        file<<mjl0<<endl;
	}	
	file.close(); 
}


//Funcion ahorro.

double ahorro(double l){
	srand(time(NULL));
	default_random_engine generator;
	generator.seed(time(NULL));
	uniform_real_distribution<double>distribution(0,1);	
    
    ofstream file;
    file.open("datos2.dat");
    
    nl=1.+((3.*l)/(1.-l));
    
    for(int i=nl; i>0; i--){
         G+=(nl-1.);  //Funcion Gamma.
    }
      
    for (int i=0; i<N; i++){
    	e=distribution(generator);
        x=(mi)*B;
        B=1./(suma/N);
        an=pow(nl,nl)/G;
        Pn=an*pow(x,nl-1.)*exp(-nl*x);
          
        mi=(l*(mi))+(e*(1.-l))*(mi+mj);
		mj=(l*mj)+(1.-l)*(1.-e)*(mi+mj);
       
		suma+=mi;
        file<<x<<"  "<<Pn<<endl;   
    }
     file.close();
}


//Funcion main.

int main(){
	cout<<"**********Este es un programa de Econofisica**********"<<endl;
	cout<<"***************Universidad del Valle******************"<<endl;
	cout<<"***************Departamento de Fisica*****************"<<endl;
	cout<<"**********************@Autores************************/n"<<endl;
	cout<<"@Luis Miguel Gomez"<<endl;
	cout<<"@Mario Alexander Diaz"<<endl;
	cout<<"@Version 1.2/n"<<endl;
	cout<<"De el numero de experimentos. "<<endl;
	cin>>N;
	cout<<"De el valor de m0. "<<endl;
	cin>>m0;
	cout<<"ingrese el valor de l. "<<endl;
	cin>>l;
	
	if(l==0){
		noahorro(m0);
	}else{
		ahorro(l);
	}
return 0;
}
