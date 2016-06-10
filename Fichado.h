
class Fichado
{
        public:
                Fichado(){}
                char Huella[6];
                char Apellidos[20];
                char Nombres[20];
                char Direccion[20];
                int Total_Registros(int);
};
int  Fichado::Total_Registros(int Nbytes)
{
        FILE *fp;
        int n;
        fp = fopen("Fichados.dat","rb");
          if(!fp){
                 cout<<"Error de apertura"<<endl;
                 fclose(fp);
          }

          fseek(fp,0,2);
          n = ftell(fp)/Nbytes;
          fclose(fp);
          return n;

}