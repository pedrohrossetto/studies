BEGIN;

-- 1. predios e pessoas
INSERT INTO predios (codigo, nome, endereco, cep) VALUES
(1, 'Edifício Central', 'Rua das Flores, 100', '11111222'),
(2, 'Residencial Aurora', 'Avenida Principal, 500', '33333444');

INSERT INTO pessoas (codigo, nome, cpf) VALUES
(10, 'Marcos Oliveira', '11111111111'), -- Proprietário 1
(11, 'Beatriz Lima', '22222222222'),  -- Proprietária 2
(12, 'Carlos Souza', '33333333333'),   -- Inquilino 1
(13, 'Diana Rocha', '44444444444');  -- Inquilina 2

-- 2. apartamentos (associados aos prédios)
INSERT INTO apartamentos (codigo, numero, area, id_predio) VALUES
(101, 10, 50.5, 1), -- Apto 10 do Prédio 1
(102, 20, 65.0, 1), -- Apto 20 do Prédio 1
(201, 10, 80.0, 2); -- Apto 10 do Prédio 2

-- 3. proprietarios (associados a pessoas e apartamentos)
INSERT INTO proprietarios (id_pessoa, id_apartamento, porcentagem) VALUES
(10, 101, 100.00), -- Marcos 100% dono Apto 101
(11, 102, 100.00), -- Beatriz 100% dona Apto 102
(10, 201, 50.00),  -- Marcos 50% dono Apto 201
(11, 201, 50.00);  -- Beatriz 50% dona Apto 201

-- 4. alugueis (associados a apartamentos e inquilinos)
INSERT INTO alugueis (codigo, duracao, valor_aluguel, data_inicio, dia_vencimento, id_apartamento, id_pessoa) VALUES
(1, 12, 1500.00, '2024-01-10', 10, 101, 12), -- Apto 101 alugado para Carlos
(2, 24, 2200.00, '2024-03-05', 5, 201, 13);  -- Apto 201 alugado para Diana

-- 5. valores (parcelas dos alugueis)
INSERT INTO valores (codigo, id_aluguel, valor_pago, data_vencimento, data_pagamento) VALUES
(1001, 1, 1500.00, '2024-11-10', '2024-11-08'), -- Aluguel 1 (pago)
(1002, 1, 0.00, '2024-12-10', NULL),            -- Aluguel 1 (a vencer)
(2001, 2, 2200.00, '2024-11-05', '2024-11-05'), -- Aluguel 2 (pago)
(2002, 2, 0.00, '2024-12-05', NULL);            -- Aluguel 2 (a vencer)

COMMIT;