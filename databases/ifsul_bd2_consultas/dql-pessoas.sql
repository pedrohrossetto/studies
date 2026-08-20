SELECT f_testa_atribuicao('2024-03-11', 3);

-- Extrai dia do ano e mês do retorno da função
SELECT (f_testa_atribuicao('2023-09-04', 3)).p_diaano,
       (f_testa_atribuicao('2023-09-04', 3)).p_mes;

-- Extrai apenas o dia informado no parâmetro para o código 1
SELECT (f_testa_atribuicao('2023-09-04', 1)).p_dia;



SELECT codigo, 
       nome, 
       (f_testa_atribuicao('2023-09-04', codigo)).*
FROM pessoas
WHERE nascimento IS NOT NULL;





SELECT codigo,
       nome,
       CASE tipo_pessoa
           WHEN 'f' THEN 'Funcionário'
           WHEN 'c' THEN 'Cliente'
           ELSE 'Não Informado'
       END AS categoria,
       tipo_pessoa
FROM pessoas;


SELECT codigo, 
       nome, 
       EXTRACT(MONTH FROM nascimento) AS mes_nascimento
FROM pessoas
WHERE codigo = 2;


SELECT '2025-09-04'::date - '2025-09-03'::date AS diferenca_dias;