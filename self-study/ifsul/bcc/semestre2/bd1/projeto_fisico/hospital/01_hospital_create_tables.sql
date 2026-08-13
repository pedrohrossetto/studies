-- SQL para: 01_Hospital_Schema.sql
-- Remove as tabelas na ordem inversa de dependência (ou usa CASCADE)

DROP TABLE IF EXISTS atendimentos_medicos;
DROP TABLE IF EXISTS atendimentos;
DROP TABLE IF EXISTS leitos;
DROP TABLE IF EXISTS medicos_especialidades;
DROP TABLE IF EXISTS medicos;
DROP TABLE IF EXISTS especialidades;
DROP TABLE IF EXISTS pacientes_telefones;
DROP TABLE IF EXISTS pacientes;

CREATE TABLE pacientes (
  id_paciente INTEGER NOT NULL PRIMARY KEY,
  nome_paciente VARCHAR(100) NOT NULL,
  rg_paciente CHAR(10) NOT NULL UNIQUE,
  cpf_paciente CHAR(11) NOT NULL UNIQUE,
  nascimento_paciente DATE NOT NULL
);

CREATE TABLE especialidades (
  id_especialidade INTEGER NOT NULL PRIMARY KEY CHECK (id_especialidade > 0),
  nome_especialidade VARCHAR(30) NOT NULL
);

CREATE TABLE leitos (
  id_leito INTEGER NOT NULL PRIMARY KEY CHECK (id_leito > 0),
  descricao VARCHAR(100) NOT NULL,
  numero_quarto INTEGER NOT NULL CHECK (numero_quarto > 0),
  andar INTEGER NOT NULL
);

CREATE TABLE pacientes_telefones (
  id_paciente INTEGER NOT NULL,
  telefone CHAR(10) NOT NULL,
  
  -- Solução Lógica 1: PK Composta para permitir N telefones
  PRIMARY KEY(id_paciente, telefone), 
  
  -- Solução de Sintaxe: Adicionando a referência que faltava
  CONSTRAINT fk_telefones_paciente
    FOREIGN KEY(id_paciente) 
    REFERENCES pacientes(id_paciente)
);

-- Tabela 'Mãe' que também é 'Filha'
CREATE TABLE medicos (
  id_crm_medico INTEGER NOT NULL CHECK (id_crm_medico > 0),
  id_especialidade_principal INTEGER NOT NULL CHECK (id_especialidade_principal > 0),
  salario NUMERIC(10, 2) NOT NULL,
  PRIMARY KEY(id_crm_medico),
  
  -- Solução de Sintaxe: Adicionando a referência
  CONSTRAINT fk_medicos_especialidade
    FOREIGN KEY(id_especialidade_principal) 
    REFERENCES especialidades(id_especialidade)
);

-- Tabela de Junção (N-para-N)
CREATE TABLE medicos_especialidades (
  id_crm_medico INTEGER NOT NULL CHECK (id_crm_medico > 0),
  id_especialidade INTEGER NOT NULL CHECK (id_especialidade > 0),
  
  -- Solução Lógica 2: PK Composta para evitar duplicatas
  PRIMARY KEY (id_crm_medico, id_especialidade), 
  
  -- Solução de Sintaxe: Adicionando as referências
  CONSTRAINT fk_medespec_medico
    FOREIGN KEY (id_crm_medico) 
    REFERENCES medicos(id_crm_medico),
  CONSTRAINT fk_medespec_especialidade
    FOREIGN KEY (id_especialidade) 
    REFERENCES especialidades(id_especialidade)
);

-- Tabela Fato (junta várias FKs)
CREATE TABLE atendimentos (
  id_atendimento BIGINT NOT NULL CHECK (id_atendimento > 0),
  data_atendimento DATE NOT NULL,
  horario_atendimento TIME NOT NULL,
  id_paciente INTEGER NOT NULL CHECK (id_paciente > 0), 
  id_leito INTEGER NOT NULL CHECK (id_leito > 0),
  PRIMARY KEY(id_atendimento), -- Corrigido 'keY' para 'KEY'
  
  -- Solução de Sintaxe: Adicionando as referências
  CONSTRAINT fk_atendimento_paciente
    FOREIGN KEY(id_paciente) 
    REFERENCES pacientes(id_paciente),
  CONSTRAINT fk_atendimento_leito
    FOREIGN KEY(id_leito) 
    REFERENCES leitos(id_leito)
);

-- Tabela de Junção (N-para-N)
CREATE TABLE atendimentos_medicos (
  id_crm_medico INTEGER NOT NULL CHECK (id_crm_medico > 0),
  id_atendimento INTEGER NOT NULL CHECK (id_atendimento > 0),
  hora_visita TIME NOT NULL,
  is_responsavel BOOLEAN NOT NULL,
  
  -- Solução Lógica 2: PK Composta
  PRIMARY KEY (id_crm_medico, id_atendimento), 

  -- Solução de Sintaxe: Adicionando as referências
  CONSTRAINT fk_atendmed_medico
    FOREIGN KEY(id_crm_medico) 
    REFERENCES medicos(id_crm_medico),
  CONSTRAINT fk_atendmed_atendimento
    FOREIGN KEY(id_atendimento) 
    REFERENCES atendimentos(id_atendimento)
);