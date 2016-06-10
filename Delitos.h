
class Delitos
{
        public:
                Delitos(){}
                int Codigo_delito;
                char Descripcion_delito[20];
                int Gravedad;
                int Total_Registros(int);
};

int  Delitos::Total_Registros(int Nbytes)
{
        FILE *fp;
        int n;
        fp = fopen("Delitos.dat","rb");
          if(!fp){
                 cout<<"Error de apertura"<<endl;
                 fclose(fp);
          }

          fseek(fp,0,2);
          n = ftell(fp)/Nbytes;
          fclose(fp);
          return n;

}
