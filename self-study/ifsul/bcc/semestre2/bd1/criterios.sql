create table pessoas(

id_pessoa integer not null,
nome varchar (100) not null,
primary key (id_pessoa),
check(id_pessoa > 0)

);

select * from pessoas;