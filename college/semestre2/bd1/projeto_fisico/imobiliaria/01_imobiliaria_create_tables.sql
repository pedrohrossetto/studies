-- Remove tabelas anteriores em ordem de dependência
DROP TABLE IF EXISTS valores;
DROP TABLE IF EXISTS alugueis;
DROP TABLE IF EXISTS proprietarios;
DROP TABLE IF EXISTS apartamentos;
DROP TABLE IF EXISTS predios;
DROP TABLE IF EXISTS pessoas;

-- 1. Tabelas Independentes
CREATE TABLE predios (
  codigo INTEGER NOT NULL,
  nome TEXT NOT NULL,
  endereco TEXT NOT NULL,
  cep CHAR(8) NOT NULL,
  complemento TEXT,
  PRIMARY KEY (codigo)
);

CREATE TABLE pessoas (
  codigo INTEGER NOT NULL,
  nome TEXT NOT NULL,
  cpf CHAR(11) NOT NULL UNIQUE,
  PRIMARY KEY (codigo)
);

-- 2. Tabelas Dependentes (Nível 1)
CREATE TABLE apartamentos (
  codigo INTEGER NOT NULL,
  numero INTEGER NOT NULL,
  area DOUBLE PRECISION NOT NULL,
  id_predio INTEGER NOT NULL,
  
  PRIMARY KEY (codigo),
  
  -- Garante que o número do apto é único por prédio
  CONSTRAINT uk_apartamentos_predio_num UNIQUE (id_predio, numero),
  
  CONSTRAINT fk_apartamentos_predios
    FOREIGN KEY (id_predio) 
    REFERENCES predios (codigo)
);

-- 3. Tabelas Dependentes (Nível 2)
CREATE TABLE proprietarios (
  id_pessoa INTEGER NOT NULL,
  id_apartamento INTEGER NOT NULL,
  porcentagem NUMERIC(5, 2) NOT NULL 
    CHECK (porcentagem > 0 AND porcentagem <= 100),
  
  -- Chave Primária Composta
  PRIMARY KEY (id_pessoa, id_apartamento),
  
  CONSTRAINT fk_proprietarios_pessoas
    FOREIGN KEY (id_pessoa) 
    REFERENCES pessoas (codigo),
  CONSTRAINT fk_proprietarios_apartamentos
    FOREIGN KEY (id_apartamento) 
    REFERENCES apartamentos (codigo)
);

CREATE TABLE alugueis (
  codigo BIGINT NOT NULL,
  duracao INTEGER NOT NULL, -- (meses)
  multa NUMERIC(4, 2) NOT NULL DEFAULT 0,
  juros NUMERIC(4, 2) NOT NULL DEFAULT 0,
  valor_aluguel NUMERIC(10, 2) NOT NULL DEFAULT 0,
  taxa_adm NUMERIC(4, 2) NOT NULL DEFAULT 0,
  data_inicio DATE NOT NULL,
  dia_vencimento SMALLINT NOT NULL 
    CHECK (dia_vencimento >= 1 AND dia_vencimento <= 31),
  id_apartamento INTEGER NOT NULL,
  id_pessoa INTEGER NOT NULL, -- Inquilino
  
  PRIMARY KEY (codigo),
  
  CONSTRAINT fk_alugueis_apartamentos
    FOREIGN KEY (id_apartamento) 
    REFERENCES apartamentos (codigo),
  CONSTRAINT fk_alugueis_pessoas
    FOREIGN KEY (id_pessoa) 
    REFERENCES pessoas (codigo)
);

-- 4. Tabelas Dependentes (Nível 3)
CREATE TABLE valores (
  codigo BIGINT NOT NULL,
  id_aluguel BIGINT NOT NULL,
  data_pagamento DATE, -- NULL se não foi pago
  valor_pago NUMERIC(10, 2) NOT NULL DEFAULT 0,
  data_vencimento DATE NOT NULL,
  
  PRIMARY KEY (codigo),
  
  CONSTRAINT fk_valores_alugueis
    FOREIGN KEY (id_aluguel) 
    REFERENCES alugueis (codigo)
);