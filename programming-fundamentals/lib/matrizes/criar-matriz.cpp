int** util_criarMatriz(int* linhas, int* colunas) {
    // Aloca o array vertical (linhas)
    int** mat = new int*[*linhas];
    
    // Cursor para percorrer e alocar cada linha
    int** pLinha = mat;
    int** fim = mat + *linhas;

    while (pLinha < fim) {
        *pLinha = new int[*colunas]; // Aloca a linha horizontal
        pLinha++;
    }
    return mat;
}