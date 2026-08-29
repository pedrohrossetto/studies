#include <iostream>
#include <fstream>
#include <cstdlib> // Necessário para a função system()

// ID Graphviz = endereço do nó (único). O valor só entra no label.
// Usar t->value como ID funde chaves repetidas e inventa ciclos.
static void generate_dot_recursive(BinTreeNode *t, std::ofstream &file) {
    if (t == nullptr) return;

    file << "    \"" << static_cast<const void*>(t) << "\" [label=\"" << t->value << "\"];\n";

    if (t->left_child != nullptr) {
        file << "    \"" << static_cast<const void*>(t) << "\" -> \""
             << static_cast<const void*>(t->left_child) << "\";\n";
        generate_dot_recursive(t->left_child, file);
    } else {
        file << "    \"null_l_" << static_cast<const void*>(t) << "\" [shape=point];\n";
        file << "    \"" << static_cast<const void*>(t) << "\" -> \"null_l_"
             << static_cast<const void*>(t) << "\";\n";
    }

    if (t->right_child != nullptr) {
        file << "    \"" << static_cast<const void*>(t) << "\" -> \""
             << static_cast<const void*>(t->right_child) << "\";\n";
        generate_dot_recursive(t->right_child, file);
    } else {
        file << "    \"null_r_" << static_cast<const void*>(t) << "\" [shape=point];\n";
        file << "    \"" << static_cast<const void*>(t) << "\" -> \"null_r_"
             << static_cast<const void*>(t) << "\";\n";
    }
}

// Função principal que exporta e executa o comando via shell
static void export_to_dot(BinTreeNode *root, const std::string &filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erro ao criar o arquivo DOT!\n";
        return;
    }

    file << "digraph BinaryTree {\n";
    file << "    node [shape=circle, style=filled, fillcolor=lightgreen];\n";

    if (root == nullptr) {
        file << "    \"Arvore Vazia\";\n";
    } else {
        generate_dot_recursive(root, file);
    }

    file << "}\n";
    file.close();

    // Incorpora o comando de shell para compilar o .dot em .png automaticamente
    std::string comando = "dot -Tpng " + filename + " -o " + filename + ".png";
    int resultado = system(comando.c_str());

    if (resultado == 0) {
        std::cout << "Imagem 'arvore.png' gerada com sucesso via Graphviz!\n";
    } else {
        std::cerr << "Erro ao executar o Graphviz. Verifique se o pacote está instalado no Linux.\n";
    }
}
