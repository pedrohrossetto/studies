#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<cstring>
#include<ctime>

using namespace std;


main()
{
    int menu;
    system ("chcp 1252");

    srand(time(NULL));

    do
    {
        system("cls");
        cout << "-------MENU-------" << endl;
        cout << "0 - Encerrar o programa" << endl;
        cout << "1 - Vender ingresso" << endl;
        cout << "2 - Mostrar total vendido" << endl;
        cout << "3 - Mostrar o total de torcedores" << endl;
        cout << "4 - Encerrar partida" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);


        switch (menu)
        {
        case 0:
            cout << "Programa finalizado.";
            break;

        case 1:
        {
            ofstream escreve ("exemplo_16.txt", ios::app);
            string cat,pos, qnt;
            do
            {
                cout<<"Qual torcedor voce é?"<< endl;
                cout << "1 - Sócios Proprietários" << endl;
                cout << "2 - Sócios Contribuintes" << endl;
                cout << "3 - Idosos e Estudantes" << endl;
                cout << "4 - Demais torcedores" << endl;
                cout << "Sua escolha: ";
                getline(cin,cat);
                fflush(stdin);
            }
            while(!(cat=="1"||cat=="2"||cat=="3"||cat=="4")); //força a entrar no parametro
            escreve << cat << " ";

            do
            {
                cout<<"Qual posição desejas?"<< endl;
                cout << "1 - Camarote " << endl;
                cout << "2 - Cadeira Central" << endl;
                cout << "3 - Cadeira Lateral" << endl;
                cout << "4 - Aquibancada" << endl;
                cout << "Sua escolha: ";
                getline(cin,pos);
                fflush(stdin);

            }
            while(!(pos=="1"||pos=="2"||pos=="3"||pos=="4")); //força a entrar no parametro
            escreve <<pos<<" ";

            cout<<"Quantos ingressos desejas? "<<endl;
            getline(cin,qnt);
            fflush(stdin);
            escreve <<qnt<<endl;
            cout<<"Compra realizada com sucesso!"<<endl;
            cout<<"Retornando ao Menu..."<<endl;
            escreve.close();
            system("pause");
            break;
        }


        case 2:
        {
            char vet[100];
            int i=0;
            float mostrar[100];
            float x,y,z;
            float total = 0;
            ifstream ler("exemplo_16.txt");
            if(ler.is_open())

                while(!ler.eof())
                {
                    ler.getline(vet, sizeof(vet)); //lê toda a linha ou até atingir o tamanho
                    if(vet[0]== '1')
                    {
                        x = 0;
                    }
                    if(vet[0]== '2'|| vet[0]=='3')
                    {
                        x = 0.5;
                    }
                    else if(vet[0]== '4')
                    {
                        x = 1;
                    }

                    if(vet[2]== '1')
                    {
                        y = 350;
                    }
                    else if(vet[2]== '2')
                    {
                        y = 160;
                    }
                    else if(vet[2]== '3')
                    {
                        y = 125;
                    }
                    else if(vet[2]== '4')
                    {
                        y = 98;
                    }

                    z = vet[4] - '0';
                    mostrar[i]=x*y*z;
                    cout <<"cliente "<<i<<":R$"<<mostrar[i]<<endl;
                    total += mostrar[i];
                    i++;
                }
            cout <<"total vendido: R$"<<total<<endl;
            ler.close();
            system("pause");
            break;
        }
        case 3:
        {
            char vet[100];
            float mostrar[100];
            float total,z;
            int i=0;
            ifstream ler("exemplo_16.txt");
            if(ler.is_open())
                while(!ler.eof())
                {
                    ler.getline(vet, sizeof(vet)); //lê toda a linha ou até atingir o tamanho
                    z = vet[4] - '0';
                    mostrar[i]=z;
                    total += mostrar[i];
                    i++;
                }
            cout <<"total de torcedores no estadio: "<<total<<endl;
            ler.close();

            system("pause");
            break;
        }
        case 4:
        {
            ofstream escreve ("exemplo_16.txt", ios::out|ios::trunc);
            escreve.close();
            cout<<"partida finalizada com sucesso!!"<<endl;
            system("pause");
            break;

        }



        }
    }
    while(menu != 0);







}































