# Pseudocódigo: Menu Interativo com Ponteiros

## Definições Globais
**Bibliotecas:** Entrada/Saída, Manipulação de String, Matemática, Arquivos

---

## Algoritmo Principal (Main)

**Início**
    // 1. Declaração de Variáveis Locais
    Variável booleana: `rodando` <- VERDADEIRO
    Variável caractere: `opcao` <- ' '

    // 2. Definição de Ponteiros (Apontam para as variáveis acima)
    Ponteiro para booleano: `ptrRodando` <- Endereço de `rodando`
    Ponteiro para caractere: `ptrOpcao` <- Endereço de `opcao`
    
    // Constante de texto
    Texto: `titulo` <- "MENU PRINCIPAL"

    // 3. Loop Principal
    **Enquanto** (Valor apontado por `ptrRodando` for VERDADEIRO) **faça**:
        
        // Limpar tela (opcional)
        ExecutarComando("limpar tela")

        // Chamada de Funções passando parâmetros
        Chamar Função `ExibirMenu(titulo)`
        
        // Passa o ENDEREÇO para que a função altere a variável original
        Chamar Função `LerOpcao(ptrOpcao)` 
        
        // Passa ENDEREÇOS para processar lógica e controle do loop
        Chamar Função `ProcessarEscolha(ptrOpcao, ptrRodando)`

        // Pausa para leitura antes de limpar a tela novamente
        **Se** (Valor apontado por `ptrRodando` for VERDADEIRO) **então**:
            Escrever "Pressione ENTER para voltar..."
            AguardarInputDoUsuario()
        **Fim Se**

    **Fim Enquanto**

    Retornar 0
**Fim Algoritmo**

---

## Procedimentos e Funções Auxiliares

### Função ExibirMenu(texto: titulo)
**Início**
    Escrever "=================================="
    Escrever titulo
    Escrever "=================================="
    Escrever "[1] - Executar Tarefa 1"
    Escrever "[2] - Executar Tarefa 2"
    Escrever "[0] - Sair"
    Escrever "=================================="
**Fim Função**

### Função LerOpcao(ponteiro_char: pOpcao)
**Início**
    Escrever "> Escolha uma opcao: "
    
    // Lê o input e salva diretamente no endereço de memória
    Ler input do usuário -> Salvar em (Valor apontado por `pOpcao`)
    
    Chamar Função `LimparBuffer()`
**Fim Função**

### Função LimparBuffer()
**Início**
    // Remove caracteres 'lixo' ou 'enter' que sobraram na entrada
    **Enquanto** (próximo caractere na entrada NÃO for QuebraDeLinha) **faça**:
        Ignorar caractere
    **Fim Enquanto**
**Fim Função**

### Função ProcessarEscolha(ponteiro_char: pOpcao, ponteiro_bool: pRodando)
**Início**
    Escrever "----------------------------------"
    
    // Avalia o VALOR guardado no endereço apontado
    **Escolha Caso** (Valor apontado por `pOpcao`):
    
        **Caso '1':**
            Chamar Função `ExecutarTarefa1()`
            Parar
            
        **Caso '2':**
            Chamar Função `ExecutarTarefa2()`
            Parar
            
        **Caso '0':**
            Escrever "Encerrando..."
            // Altera a variável de controle do loop original via ponteiro
            (Valor apontado por `pRodando`) <- FALSO
            Parar
            
        **Caso Padrão:**
            Escrever "Opção Inválida!"
            Parar
            
    **Fim Escolha**
**Fim Função**

### Função ExecutarTarefa1()
**Início**
    Escrever "Executando lógica da Tarefa 1..."
    // Lógica específica do exercício...
**Fim Função**

### Função ExecutarTarefa2()
**Início**
    Escrever "Executando lógica da Tarefa 2..."
    // Lógica específica do exercício...
**Fim Função**