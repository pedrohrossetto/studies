CREATE TABLE insetos (
    codigo int primary key,
    nome text not null
);


create table culturas(
    codigo int primary key,
    descricao text not null

);


create table insetos_danos(
    valor_dano numeric(12,2) not null,
    inseto_codigo int not null,
    cultura_codigo int not null,
    foreign key (inseto_codigo) references insetos(codigo),
    foreign key (cultura_codigo) references culturas(codigo)
);


create table lancamentos(
    codigo bigserial primary key,
    data date not null,
    quantidade int not null,
    valor_dano numeric(12,2) not null,
    total_dano numeric(12,2) not null,
    inseto_codigo int not null,
    cultura_codigo int not null,
    foreign key (inseto_codigo) references insetos(codigo),
    foreign key (cultura_codigo) references culturas(codigo)

)


create function total_dano(data_inicio date, data_fim date, cultura_p int)
    returns numeric(12,2)
    as $$
    select sum(total_dano)
    from lancamentos
    where data between data_inicio and data_fim
    and cultura_codigo = cultura_p;
$$ language sql;


create function lancamentos_per_day(data_inicio date, data_fim date, cultura_p int, inseto_p int, qtd_p int)
-- retorna o número de lançamentos por dia para um inseto em uma cultura específica
    returns int
        as $$
            select count(*)
            from lancamentos
            where data between data_inicio and data_fim
            and cultura_codigo = cultura_p
            and inseto_codigo = inseto_p
            and quantidade = qtd_p;
        $$ language sql;

create function encontrar_cultura_mais_danificada(data_inicio date, data_fim date, out cultura_codigo int, out total_dano numeric(12,2))
-- retorna a cultura que teve maior dano total em um período específico e o respectivo valor
    as $$
    declare
        cur_danos cursor for
            select lancamentos.cultura_codigo, sum(lancamentos.total_dano)
            from lancamentos
            where lancamentos.data between data_inicio and data_fim
            group by lancamentos.cultura_codigo;

        cod int;
        soma numeric(12,2);
    begin
        total_dano := 0;

        open cur_danos;

        loop
            fetch cur_danos into cod, soma;
            exit when not found;

            if soma > total_dano then
                total_dano := soma;
                cultura_codigo := cod;
            end if;
        end loop;

        close cur_danos;
    end;
    $$ language plpgsql;
