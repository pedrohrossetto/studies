-- Consulta 1: Listar apartamentos, número e nome do prédio.
-- (JOIN: apartamentos, predios)
SELECT
    pr.nome AS "Nome do Prédio",
    a.numero AS "Número do Apto",
    a.area AS "Área (m²)"
FROM
    apartamentos AS a
JOIN
    predios AS pr ON a.id_predio = pr.codigo
ORDER BY
    pr.nome, a.numero;


-- Consulta 2: Listar os proprietários (CPF, Nome, %) do apartamento 201.
-- (JOIN: proprietarios, pessoas)
SELECT
    p.nome,
    p.cpf,
    pr.porcentagem
FROM
    proprietarios AS pr
JOIN
    pessoas AS p ON pr.id_pessoa = p.codigo
WHERE
    pr.id_apartamento = 201;


-- Consulta 3: Histórico de pagamentos do contrato de aluguel código 1.
-- (JOIN: valores, alugueis, pessoas)
SELECT
    p.nome AS "Nome Inquilino",
    v.data_vencimento,
    v.valor_pago,
    v.data_pagamento
FROM
    valores AS v
JOIN
    alugueis AS a ON v.id_aluguel = a.codigo
JOIN
    pessoas AS p ON a.id_pessoa = p.codigo
WHERE
    a.codigo = 1; -- Filtra pelo código do contrato