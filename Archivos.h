#include"Delitos.h"
#include"Entradas.h"
#include"Fichado.h"
#include"Multas.h"


class Archivo
{
public:
	Fichado fichado, *Vfichado;
	Delitos delitos, *Vdelitos;
	Multas multas, *Vmultas;
	Pagos pagos, *Vpagos;
	Entradas entradas, *Ventradas;

	int nF, nD, nE, nM, nP;

	Archivo(){}
	void Generar_Archivos();
	void Delitos_Cometidos();
	void Delitos_cometidos_por_gravedad_1();
	void DelitosCometido();
	void Estadisticas();
	void Insercion();
	void Insercion2();
	void Insercion3();
	void Dar_Memoria();
	void Cargar();
	void Pago();
	void Reporte();
	void Mayor_delicuente();

};

void Archivo::Cargar()
{
	Fichado f;
	Delitos d;
	Entradas e;
	Multas m;
	Pagos p;
	int i=0;
	FILE *fpF, *fpD, *fpE,*fpM, *fpP;


	fpF = fopen("Fichados.dat","rb");
	fpD = fopen("Delitos.dat","rb");
	fpE = fopen("Entradas.dat","rb");
	fpM = fopen("Multas.dat","rb");
	fpP = fopen("Pagos.dat","rb");

	if(!fpF || !fpD ||  !fpE ||!fpM ||  !fpP){
		cout<<"ERROR DE APERTURA"<<endl;
		fclose(fpF);fclose(fpD);fclose(fpE);fclose(fpM);fclose(fpP);
	}else{
		fread(&f,sizeof(Fichado),1,fpF);
		while (!feof(fpF))
		{
			Vfichado[i]=f;
			i++;
			fread(&f,sizeof(Fichado),1,fpF);
		}
		i=0;
		fread(&d,sizeof(Delitos),1,fpD);
		while (!feof(fpD))
		{
			Vdelitos[i]=d;
			i++;
			fread(&d,sizeof(Delitos),1,fpD);
		}
		i=0;
		fread(&e,sizeof(Entradas),1,fpE);
		while (!feof(fpE))
		{
			Ventradas[i]=e;
			i++;
			fread(&e,sizeof(Entradas),1,fpE);
		}

		i=0;
		fread(&m,sizeof(Multas),1,fpM);
		while (!feof(fpM))
		{
			Vmultas[i]=m;
			i++;
			fread(&m,sizeof(Multas),1,fpM);
		}
		i=0;
		fread(&p,sizeof(Pagos),1,fpP);
		while (!feof(fpP))
		{
			Vpagos[i]=p;
			i++;
			fread(&p,sizeof(Pagos),1,fpP);
		}
	}
	fclose(fpF);fclose(fpD);fclose(fpE);fclose(fpM);fclose(fpP);
}
void Archivo::Generar_Archivos()
{
	char cad[100], *se;
	int cod;
	FILE *fp, *fpF, *fpD, *fpM, *fpP, *fpE;

	fp = fopen("Data.txt","r");
	fpF = fopen("Fichados.dat","wb");
	fpD = fopen("Delitos.dat","wb");
	fpM = fopen("Multas.dat","wb");
	fpP = fopen("Pagos.dat","wb");
	fpE = fopen("Entradas.dat","wb");

	if(!fp){
		cout<<"Error de apertura"<<endl;
		fclose(fp);
	}


	while(!feof(fp))
	{fgets(cad,100,fp);
	se = strtok(cad,",");
	cod = atoi(se);

	if(cod==1)
	{   
		se = strtok(NULL,",");
		strcpy(fichado.Huella,se);
		se = strtok(NULL,",");
		strcpy(fichado.Apellidos,se);
		se = strtok(NULL,",");
		strcpy(fichado.Nombres,se);
		se = strtok(NULL,",");
		strcpy(fichado.Direccion,se);
		fwrite(&fichado,sizeof(Fichado),1,fpF);
	}
	if(cod==2)
	{
		se = strtok(NULL,",");
		delitos.Codigo_delito = atoi(se);
		se = strtok(NULL,",");
		strcpy(delitos.Descripcion_delito,se);
		se = strtok(NULL,",");
		delitos.Gravedad = atoi(se);
		fwrite(&delitos,sizeof(Delitos),1,fpD);
	}
	if(cod==3)
	{
		se = strtok(NULL,",");
		multas.Codigo_multa = atoi(se);
		se = strtok(NULL,",");
		strcpy(multas.Descripcion_delito,se);
		se = strtok(NULL,",");
		multas.Monto = atof(se);
		fwrite(&multas,sizeof(Multas),1,fpM);
	}
	if(cod==4)
	{
		se = strtok(NULL,",");
		strcpy(pagos.Huella,se);
		se = strtok(NULL,",");
		pagos.Codigo_multa = atoi(se);
		se = strtok(NULL,",");
		pagos.fechaPagos.Dia= atoi(se);
		se = strtok(NULL,",");
		pagos.fechaPagos.Mes = atoi(se);
		se = strtok(NULL,",");
		pagos.fechaPagos.a= atoi(se);
		se = strtok(NULL,",");
		pagos.Monto_pagado = atof(se);
		fwrite(&pagos,sizeof(Pagos),1,fpP);
	}
	if(cod==5)
	{
		se = strtok(NULL,",");
		strcpy(entradas.Huella,se);
		se = strtok(NULL,",");
		entradas.Codigo_delito = atoi(se);
		se = strtok(NULL,",");
		entradas.fechaEntrada.Dia = atoi(se);
		se = strtok(NULL,",");
		entradas.fechaEntrada.Mes = atoi(se);
		se = strtok(NULL,",");
		entradas.fechaEntrada.a = atoi(se);
		se = strtok(NULL,",");
		entradas.Num_dias = atoi(se);
		fwrite(&entradas,sizeof(Entradas),1,fpE);
	}
	}
	cout<<"\n\t.............Generado los archivos.........!!!"<<endl;	
	fclose(fp); fclose(fpF);fclose(fpD);fclose(fpM);fclose(fpP);fclose(fpE);
}

void Archivo::Delitos_Cometidos()
{       
	char xHuella[6];
	cout<<"HUELLA: "<<endl;
	fflush(stdin);
	cin.getline(xHuella,6);

	int g=0;
	int enc=0,p=0,pos=0;
	pos=0;
	int i=0;
	enc=0;
	while(!enc && i<nF)
	{
		if(strcmpi(xHuella,Vfichado[i].Huella)==0){
			enc=1;
			pos=i;}
		else
			i++;
	}
	if(enc){

		for (int j=0;j<nE ;j++)
		{ 
			if(strcmpi(Vfichado[pos].Huella,Ventradas[j].Huella)==0)
			{
				for (int k=0;k<nD ;k++)
				{
					if(Ventradas[j].Codigo_delito==Vdelitos[k].Codigo_delito)
					{   
						cout<<"\n\t"<<Vfichado[pos].Apellidos<<" "<<Vfichado[pos].Nombres<<endl;    
						cout<<"\nDelito "<<i+1<<endl;
						cout<<"Codigo "<<Vdelitos[k].Codigo_delito<<endl;
						cout<<"Descripcion "<<Vdelitos[k].Descripcion_delito<<endl;
						cout<<"Gravedad "<<Vdelitos[k].Gravedad<<endl;
						cout<<"Dias de Pena "<<Ventradas[j].Num_dias<<endl;       
					}
				}

			}
		}


	}
	else
	{
		cout<<"LA HUELLA DEL CIUDADANO NO SE ENCUENTRA EN LOS ARCHIVOS"<<endl;
	}
}

void Archivo::Delitos_cometidos_por_gravedad_1()
{
	for(int i=0; i<nD;i++)
	{
		if(Vdelitos[i].Gravedad==1)
		{
			for(int j=0;j<nE;j++)
			{
				if(Vdelitos[i].Codigo_delito==Ventradas[j].Codigo_delito)
				{
					for(int k=0;k<nF;k++)
					{
						if(strcmpi(Vfichado[k].Huella,Ventradas[j].Huella)==0)
						{
							cout<<"\n"<<Vfichado[k].Apellidos<<" "<<Vfichado[k].Nombres<<" "<<Vfichado[k].Direccion<<endl;
						}
					}
				}
			}
		}
	}
}
void Archivo::DelitosCometido()
{
	int cont=0,j=0;

	for(int i=0;i<nE;i++)
	{   
		for(j=i;j<=nE;j++)
		{
			if(strcmpi(Ventradas[i].Huella,Ventradas[j].Huella)==0)
			{
				cont++;
			}
			if(strcmpi(Ventradas[i].Huella,Ventradas[j].Huella)!=0)
			{

				if(cont<=2)
				{
					for(int k=0;k<nF;k++)
					{
						if(strcmpi(Ventradas[i].Huella,Vfichado[k].Huella)==0)
						{
							for(int l=0;l<nD;l++)
							{
								if(Ventradas[i].Codigo_delito==Vdelitos[l].Codigo_delito)
								{
									if(Vdelitos[l].Gravedad==3)
									{
										cout<<" "<<Vfichado[k].Huella<<" "<<Vfichado[k].Apellidos<<" "<<Vfichado[k].Nombres<<" "<<Vfichado[k].Direccion<<" "<<Vdelitos[l].Gravedad<<endl;
									}
									if(Vdelitos[l].Gravedad==4)
									{
										cout<<" "<<Vfichado[k].Huella<<" "<<Vfichado[k].Apellidos<<" "<<Vfichado[k].Nombres<<" "<<Vfichado[k].Direccion<<" "<<Vdelitos[l].Gravedad<<endl;
									}
								}
							}
						}	
					}
					i=j;
					j=j-1;
				}
				cont=0;	
			}
		}
		i=j;
	}
}

void Archivo::Estadisticas()
{
	for(int i=0;i<nD;i++)
	{
		cout<<" "<<Vdelitos[i].Descripcion_delito<<" ";

		for(int j=0;j<nE;j++)
		{	/*cout<<"\t";*/
			if(Vdelitos[i].Codigo_delito==Ventradas[j].Codigo_delito )
			{
				cout<<"|";	
			}
		}
		for(int k=0;k<nM;k++)
		{ 
			if(strcmpi(Vdelitos[i].Descripcion_delito,Vmultas[k].Descripcion_delito)==0)
			{
				cout<<"|";	
			}
		}
		cout<<endl;
	}
}

void Archivo::Insercion()
{

	Entradas elem;
	int i, k, cg= nE/2;
	while (cg>=1)
	{
		for (i=cg;i<nE ;i++)
		{
			elem = Ventradas[i];
			k = i-cg;
			while (k>0 && strcmpi(elem.Huella,Ventradas[k].Huella)<0)
			{
				Ventradas[k + cg] = Ventradas[k];
				k-=cg;
			}
			Ventradas[k + cg] = elem;
		}
		cg = (int)cg/2;
	}
	/* 
	for(int i=0; i<nE;i++)
	{
	cout<<Ventradas[i].Huella<<endl;
	}*/

}
void Archivo::Insercion2()
{
	Fichado elem;
	int i, k, cg= nE/2;
	while (cg>=1)
	{
		for (i=cg;i<nE ;i++)
		{
			elem = Vfichado[i];
			k = i-cg;
			while (k>0 && strcmpi(elem.Apellidos,Vfichado[k].Apellidos)<0)
			{
				Vfichado[k + cg] = Vfichado[k];
				k-=cg;
			}
			Vfichado[k + cg] = elem;
		}
		cg = (int)cg/2;
	}

}
void Archivo::Insercion3()
{
	Delitos elem;
	int i, k, cg= nE/2;
	while (cg>=1)
	{
		for (i=cg;i<nE ;i++)
		{
			elem = Vdelitos[i];
			k = i-cg;
			while (k>0 && strcmpi(elem.Descripcion_delito,Vdelitos[k].Descripcion_delito)<0)
			{
				Vdelitos[k + cg] = Vdelitos[k];
				k-=cg;
			}
			Vdelitos[k + cg] = elem;
		}
		cg = (int)cg/2;
	}

}
void Archivo::Pago()
{
	FILE *fp;
	fp = fopen("Montos Pagados.txt","w");
	if(!fp)
	{
		cout<<"ERROR AL ABRIR EL ARCHIVO MONTOS PAGADOS.TXT";
		fclose(fp);
		return;
	}else{

		for (int i=0;i<nF ;i++)
		{
			for (int j=0;j<nP ;j++)
			{
				if(strcmpi(Vfichado[i].Huella,Vpagos[j].Huella)==0)
				{
					if(Vpagos[j].Monto_pagado!=0)
						fprintf(fp,"%s,%s,%2.f\n",Vfichado[i].Apellidos,Vfichado[i].Nombres,Vpagos[j].Monto_pagado);
				}
			}
		}
	}
	fclose(fp);
	cout<<"................Generado el archivo montos pagados............."<<endl;
}

void Archivo::Dar_Memoria()
{

	nM = multas.Total_Registros(sizeof(Multas));
	nP = pagos.Total_Registros(sizeof(Pagos));
	nF = fichado.Total_Registros(sizeof(Fichado));
	nD = delitos.Total_Registros(sizeof(Delitos));
	nE = entradas.Total_Registros(sizeof(Entradas));

	Vmultas = new Multas[nM];
	Vpagos = new Pagos[nP];
	Vfichado = new Fichado[nF];
	Vdelitos = new Delitos[nD];
	Ventradas = new Entradas[nE];
}

void Archivo::Reporte()
{
	FILE *fp;
	int cont=0;
	fp = fopen("Reporte.txt","w");
	if(!fp)
	{
		cout<<"ERROR AL ABRIR EL ARCHIVO MONTOS PAGADOS.TXT";
		fclose(fp);
		return;
	}else{
		fprintf(fp,"\t\t\tReporte de Delitos\n");
		fprintf(fp,"\t\t\tLista de Ciudadanos");
		for (int i=0;i<nD ;i++)
		{
			fprintf(fp,"\n\n\nDelitos: %s",Vdelitos[i].Descripcion_delito);
			fprintf(fp,"\nGravedad: %d\n\n",Vdelitos[i].Gravedad);
			fprintf(fp,"\nHuella   Apellidos     Nombre      Total Dias/Pena    Fecha/Ultimo Registro");
			fprintf(fp,"\n-----------------------------------------------------------------------------");
			for (int j=0;j<nE ;j++)
			{
				if(Vdelitos[i].Codigo_delito==Ventradas[j].Codigo_delito)
				{
					for (int k=0;k<nF ;k++)
					{
						if(strcmpi(Ventradas[j].Huella,Vfichado[k].Huella)==0){
							fprintf(fp,"\n%s    %s        %s        %d           %d/%d/%d", Vfichado[k].Huella, Vfichado[k].Apellidos, Vfichado[k].Nombres, Ventradas[j].Num_dias, Ventradas[j].fechaEntrada.Dia,Ventradas[j].fechaEntrada.Mes,Ventradas[j].fechaEntrada.a);
							cont++;
						}
					}
				}   
			}

			for(int l=0;l<nM;l++)
			{
				if(strcmpi(Vdelitos[i].Descripcion_delito,Vmultas[l].Descripcion_delito)==0)
				{
					for (int k=0;k<nP ;k++)
					{
						if(Vmultas[l].Codigo_multa==Vpagos[k].Codigo_multa)
						{
							for(int j=0;j<nF;j++)
							{
								if(strcmpi(Vpagos[k].Huella,Vfichado[j].Huella)==0)
								{
									fprintf(fp,"\n%s    %s        %s                       %d/%d/%d", Vfichado[j].Huella, Vfichado[j].Apellidos, Vfichado[j].Nombres, Vpagos[k].fechaPagos.Dia,Vpagos[k].fechaPagos.Mes,Vpagos[k].fechaPagos.a);
									cont++;
								}
							}
						}
					}
				}
			}
			fprintf(fp,"\n-----------------------------------------------------------------------------");
			fprintf(fp,"\n\t\t\t\t\t\t No. Total de Personas: %d",cont);
			cont=0;
		}
	}
	fclose(fp);
	cout<<"................Generado el archivo Reporte............."<<endl;
}

void Archivo::Mayor_delicuente()
{
	int cont=0,mayor=-1,j=0;
	char Huella[6];
	for(int i=0;i<nE;i++)
	{
		for(j=1;j<nE;j++)
		{
			if(strcmpi(Ventradas[i].Huella,Ventradas[j].Huella)==0)
			{
				cont++;
				for(int k=0;k<nD;k++)
				{
					if(Vdelitos[k].Codigo_delito==Ventradas[i].Codigo_delito)
					{
						for(int l=0;l<nM;l++)
						{
							if(strcmpi(Vdelitos[k].Descripcion_delito,Vmultas[l].Descripcion_delito)==0)
							{
								cont++;
							}
						}
					}
				}
			}
			if(strcmpi(Ventradas[i].Huella,Ventradas[j].Huella)!=0)
			{
				if(cont > mayor)
				{
					mayor = cont;
					strcpy(Huella,Ventradas[i].Huella);
				}
				i=j;
				j=j-1;
				cont=0;
			}
		}
		i=j;
	}
	for(int i=0;i<nF;i++)
	{
		if(strcmpi(Huella,Vfichado[i].Huella)==0)
		{
			cout<<""<<Vfichado[i].Apellidos<<" "<<Vfichado[i].Nombres<<" "<<Vfichado[i].Direccion<<endl;
		}
	}

}