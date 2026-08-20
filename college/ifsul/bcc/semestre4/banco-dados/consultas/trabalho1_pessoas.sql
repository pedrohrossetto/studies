-- Extrai o maior código da tabela de pessoas e adiciona +1


select max(codigo)+1 from pessoas;


/* Faça uma função que calcula a idade de uma pessoa. Deve-se passar como
parâmetro a data de nascimento. Se necessário, adapte o projeto para suportar a
data de nascimento.
*/

create or replace function fn_calcular_idade(p_date date, out idade int) 
	as $$ 
	begin
		if p_date > CURRENT_DATE
		then
			raise exception 'Data de Nascimento Inválida';
		END IF;
		idade := floor((CURRENT_DATE - p_date)/ 365);
	
	end;
	$$ language plpgsql;


select fn_calcular_idade('2003-11-03');
select fn_calcular_idade('2026-11-03');


/*
3. Na tabela de pessoas crie os seguintes campos:
tipo_pessoa, char(1) - F ou J
cpf - varchar(11)
cnpj - varchar(14)
*/


ALTER TABLE pessoas
ADD COLUMN tipo_pessoa char(1) NOT NULL DEFAULT 'F' CHECK (tipo_pessoa IN ('F', 'J')),
ADD COLUMN cpf varchar(11),
ADD COLUMN cnpj varchar(14);


select * from pessoas

/* 4. Faça uma função que retorna o cpf ou cnpj do cliente, baseado no seu tipo.  Deve-se usar como parâmetro o código do cliente. 
*/

create or replace function fn_buscar_documento(p_codigo int)
returns text
	as $$ 

	DECLARE
    v_tipo_pessoa CHAR(1);
    v_cpf VARCHAR(14);
    v_cnpj VARCHAR(18);
    v_resultado TEXT;
	
	begin
	
	if p_codigo is null
		then
			raise exception 'código inválido';
		END IF;
		
		SELECT tipo_pessoa, cpf, cnpj INTO v_tipo_pessoa, v_cpf, v_cnpj
			FROM pessoas WHERE codigo = p_codigo;
		
		IF NOT FOUND THEN
	        RAISE EXCEPTION 'Cliente com código % não encontrado', p_codigo;
	    END IF;
		
		IF v_tipo_pessoa = 'F' THEN
			v_resultado := v_cpf;
		ELSIF v_tipo_pessoa = 'J' THEN
			v_resultado := v_cnpj;
		ELSE
			v_resultado := 'Tipo de pessoa desconhecido';
		END IF;
		
		RETURN v_resultado;
	
	end;
	$$ language plpgsql;


-- Para testar, faça uma consulta que mostra: o nome da pessoa e a sua identificação, cpf ou cnpj.

select nome,
    tipo_pessoa,
    fn_buscar_documento(codigo) AS identificacao_documento
FROM pessoas;




















