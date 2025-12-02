create table vendas (
codigo_venda integer not null,
data_venda date not null,
valor_venda numeric(10,2) not null default 0,
primary key(codigo_venda)
);

select * from vendas;

create table creditos (
numero integer not null,
venda integer not null,
valor numeric(10,2) not null,
primary key (numero,venda),
foreign key (venda) references vendas (codigo_venda)
);

alter table creditos
add data_vencimento date not null

select * from creditos;


insert into vendas (codigo_venda,data_venda,valor_venda)
values 
(3, '2025-02-02', 102.53),
(4, '2025-02-02', 21.53)



insert into creditos
values
(1,1,10.2,'2025-06-21'),
(2,1,210.2,'2025-03-19'),
(3,2,50.2,'2025-04-01'),
(4,2,140.2,'2025-02-27')


update creditos set data_vencimento = '2025-12-03' where creditos.venda = 1

select vendas.codigo_venda, vendas.data_venda, creditos.numero, creditos.valor 
from vendas join creditos
	on vendas.codigo_venda = creditos.venda


select vendas.data_venda, sum(vendas.valor_venda) as valor_venda_sum, sum(creditos.valor) as creditos_sum 
from vendas join creditos
	on vendas.codigo_venda = creditos.numero
group by vendas.data_venda
order by vendas.data_venda

select * from creditos;
select * from vendas;

select vendas.codigo_venda, vendas.data_venda, creditos.numero, creditos.valor 
from vendas left join creditos
	on vendas.codigo_venda = creditos.venda
