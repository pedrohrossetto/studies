-- Remove a tabela caso já exista para recriá-la limpa
DROP TABLE IF EXISTS pessoas CASCADE;

-- Criação da tabela com a estrutura completa
CREATE TABLE pessoas (
    codigo INT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    tipo_pessoa CHAR(1), -- 'f' para Funcionário, 'c' para Cliente
    nascimento DATE
);