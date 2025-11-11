SELECT
    nome_paciente AS "Nome do Paciente",
    nascimento_paciente AS "Data de Nascimento"
FROM
    pacientes
WHERE
    nascimento_paciente >= '2000-01-01';

SELECT
    p.nome_paciente,
    a.data_atendimento,
    a.id_leito
FROM
    atendimentos AS a
JOIN
    pacientes AS p ON a.id_paciente = p.id_paciente;


SELECT
    me.id_crm_medico,
    e.nome_especialidade
FROM
    especialidades AS e
JOIN
    medicos_especialidades AS me ON e.id_especialidade = me.id_especialidade
WHERE
    e.nome_especialidade = 'Cardiologia';