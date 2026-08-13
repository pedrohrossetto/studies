struct Produto{
 string nome;
 int quantidade;
 Produto(string n, int q){
 nome=n;
 quantidade=q;
 }
};
int main(void){
 Fila f;
 const int tamFila=30;
 inicializaF(&f, tamFila);
 enfileiraF(&f, Produto("melao", 10));
 enfileiraF(&f, Produto("melancia", 5));
 enfileiraF(&f, Produto("abacaxi", 6));
 enfileiraF(&f, Produto("melancia", 3));
 enfileiraF(&f, Produto("melao", 2));
 desenfileiraF(&f);
 desenfileiraF(&f);
 desenfileiraF(&f);
 enfileiraF(&f, Produto("melao", 10));
 enfileiraF(&f, Produto("melancia", 5));
 enfileiraF(&f, Produto("abacaxi", 6));
 cout << "\nFila: {tamanho = " << f.tam << ", total = " << f.total << "}\n";
 mostraF(&f);
 combinarF(&f);
 cout << "\nFila: {tamanho = " << f.tam << ", total = " << f.total << "}\n";
 mostraF(&f);
 destroiF(&f);
 return EXIT_SUCCESS;
}
