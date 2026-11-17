from typing import TypedDict, List, Optional

# 1. Definição do Esquema de Tipos para o Endereço
class EndereçoSchema(TypedDict):
    numero_rua: Optional[int]
    rua: str
    bairro: str
    cidade: str
    estado: str
    pais: str
    cep: str

# 2. Definição do Esquema de Tipos para a Pessoa
class PessoaSchema(TypedDict):
    nome: str
    sobrenome: str
    nome_completo: str
    idade: Optional[int]
    cpf: str
    interesses: List[str]
    endereco: EndereçoSchema

# 3. População do Dicionário seguindo estritamente a tipagem
nome_val = "Pedro"
sobrenome_val = "Carvalho"

Pessoa: PessoaSchema = {
    "nome": nome_val,
    "sobrenome": sobrenome_val,
    "nome_completo": f"{nome_val} {sobrenome_val}",
    "idade": 28,
    "cpf": "123.456.789-00",
    "interesses": ["Python", "Estruturas de Dados"],
    "endereco": {
        "numero_rua": 105,
        "rua": "Av. Paulista",
        "bairro": "Bela Vista",
        "cidade": "São Paulo",
        "estado": "SP",
        "pais": "Brasil",
        "cep": "01311-000"
    }
}


Pessoa["idade"]
Pessoa["endereco"]["rua"]
Pessoa["interesses"][0]
Pessoa["interesses"].append("Vôleio")
Pessoa["interesses"]


