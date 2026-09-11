CREATE OR REPLACE FUNCTION f_testa_atribuicao(
    p_data DATE,
    p_pessoa INT,
    OUT p_dia INT,
    OUT p_mes INT,
    OUT p_ano INT,
    OUT p_diaano INT
)
AS $$
BEGIN
    -- 1. Atribuição direta do primeiro parâmetro ($1 / p_data)
    p_dia := EXTRACT(DAY FROM p_data);
    
    -- 2. Atribuição direta a partir de consulta de 1 linha
    p_mes := EXTRACT(MONTH FROM nascimento)
             FROM pessoas
             WHERE codigo = p_pessoa;
    
    -- 3. Atribuição múltipla com SELECT ... INTO (Ano e Dia do Ano)
    SELECT EXTRACT(YEAR FROM nascimento), 
           EXTRACT(DOY FROM nascimento)
      INTO p_ano, p_diaano
      FROM pessoas
     WHERE codigo = p_pessoa;
END;
$$ LANGUAGE plpgsql;