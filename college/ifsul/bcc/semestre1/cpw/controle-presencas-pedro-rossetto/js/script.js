// Dicionário principal para controle do código
let participantes = {};

const form_inscricao = document.getElementById("form_inscricao");
const form_presenca = document.getElementById("form_presenca");
const lista_inscritos = document.getElementById("lista_inscritos");
const lista_presentes = document.getElementById("lista_presentes");

form_inscricao.addEventListener("submit", handleInscricaoSubmit);
form_presenca.addEventListener("submit", handlePresencaSubmit);

function handleInscricaoSubmit(event) {
  event.preventDefault();

  const form_data = new FormData(event.target);
  const nome = form_data.get("name");
  const email = form_data.get("email").toLowerCase().trim();

  if (participantes[email]) {
    alert("Email já cadastrado!");
    return;
  }

  const nome_formatado = nome
    .toLowerCase()
    .split(/\s+/)
    .map((word) => word.charAt(0).toUpperCase() + word.slice(1))
    .join(" ");

  participantes[email] = {
    nome: nome_formatado,
    presente: false,
  };

  const novo_item_inscrito = document.createElement("li");
  novo_item_inscrito.textContent = `Nome: ${nome_formatado}, Email: ${email}`;
  novo_item_inscrito.id = email;

  lista_inscritos.appendChild(novo_item_inscrito);

  event.target.reset();
  alert("Inscrição realizada com sucesso!");
}

function handlePresencaSubmit(event) {
  event.preventDefault();

  const form_data = new FormData(event.target);
  const email = form_data.get("email").toLowerCase().trim();

  const participante = participantes[email];

  if (!participante) {
    alert("Email não encontrado na lista de inscritos.");
    return;
  }

  if (participante.presente) {
    alert("Presença já registrada para esse email!");
    return;
  }

  participante.presente = true;

  // Usamos o email para encontrar o elemento pelo ID.
  const item_para_mover = document.getElementById(email);

  if (item_para_mover) {
    item_para_mover.remove();
  }

  const novo_item_presente = document.createElement("li");
  novo_item_presente.textContent = `Nome: ${participante.nome}, Email: ${email}`;

  lista_presentes.appendChild(novo_item_presente);

  event.target.reset();
  alert("Presença registrada com sucesso!");
}
