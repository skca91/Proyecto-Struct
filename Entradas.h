#include"Pagos.h"

class Entradas
{
        public:
                Entradas(){}
                char Huella[6];
                int Codigo_delito;
				Fecha fechaEntrada;
                int Num_dias;
                int Total_Registros(int);
};
int  Entradas::Total_Registros(int Nbytes)
{
        FILE *fp;
        int n;
        fp = fopen("Entradas.dat","rb");
          if(!fp){
                 cout<<"Error de apertura"<<endl;
                 fclose(fp);
          }

          fseek(fp,0,2);
          n = ftell(fp)/Nbytes;
          fclose(fp);
          return n;

}