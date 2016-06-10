#include"Fecha.h"

class Pagos
{
        public:
                Pagos(){}
                char Huella[6];
                int Codigo_multa;
				Fecha fechaPagos;
                float Monto_pagado;
                int Total_Registros(int);
};
 int  Pagos::Total_Registros(int Nbytes)
{
        FILE *fp;
        int n;
        fp = fopen("Pagos.dat","rb");
          if(!fp){
                 cout<<"Error de apertura"<<endl;
                 fclose(fp);
          }

          fseek(fp,0,2);
          n = ftell(fp)/Nbytes;
          fclose(fp);
          return n;

}