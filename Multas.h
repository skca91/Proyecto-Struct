class Multas
{
        public:
                Multas(){}
                int Codigo_multa;
                char Descripcion_delito[20];
                float Monto;
                int Total_Registros(int);
};
int  Multas::Total_Registros(int Nbytes)
{
        FILE *fp;
        int n;
        fp = fopen("Multas.dat","rb");
          if(!fp){
                 cout<<"Error de apertura"<<endl;
                 fclose(fp);
          }

          fseek(fp,0,2);
          n = ftell(fp)/Nbytes;
          fclose(fp);
          return n;

}