
BEGIN;

INSERT INTO medicos (id_crm_medico, id_especialidade_principal, salario) VALUES
(12345, 1, 15000.00), 
(54321, 2, 12500.00), 
(98765, 3, 17000.00);

INSERT INTO especialidades (id_especialidade, nome_especialidade) VALUES
(1, 'Cardiologia'),
(2, 'Ortopedia'),
(3, 'Neurologia');

INSERT INTO pacientes (id_paciente, nome_paciente, rg_paciente, cpf_paciente, nascimento_paciente) VALUES
(1, 'Pedro Henrique', '1234567890', '11122233344', '2003-03-15'),
(2, 'Henrique Pedro', '1234567899', '55566677788', '1989-11-20');

INSERT INTO leitos (id_leito, descricao, numero_quarto, andar) VALUES
(101, 'Leito A, Quarto 10', 10, 1),
(102, 'Leito B, Quarto 10', 10, 1),
(201, 'Leito A, Quarto 20 (UTI)', 20, 2);

INSERT INTO medicos_especialidades (id_crm_medico, id_especialidade) VALUES
(12345, 1), -- Dr. Cardiologista na sua especialidade principal
(54321, 2), -- Dra. Ortopedista na sua especialidade principal
(54321, 1), -- Dra. Ortopedista também é Cardiologista
(98765, 3); -- Dr. Neurologista
COMMIT;