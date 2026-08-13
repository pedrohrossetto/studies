var cartasJ1 = [];
var cartasJ2 = [];

function addCarta() {
    let nome = document.querySelector("#txtNomeCarta").value;
    let dano = document.querySelector("#numDanoCarta").value;

    if (nome.trim() == "") {
        alert("Campo nome obrigatorio");
        return;
    }

    dano = parseInt(dano);
    if (isNaN(dano)) {
        alert("Campo dano obrigatorio e precisa ser numérico!!");
        return;
    }

    if (dano < 1 || dano > 100) {
        alert("Valor inválido!! Dano deve ser entre 1 e 100");
        return;
    }

    alert("Adicionando carta...");

    let jogador = document.querySelector("#selJogador").value;
    let carta = `${nome} - ${dano}`;

    let li = document.createElement("li");
    li.textContent = carta;

    let opt = document.createElement("option");
    opt.value = dano;
    opt.textContent = carta;  


    switch (jogador) {
        case "jog1":
            cartasJ1[cartasJ1.length] = carta;
            carregarCartasJ1()
            break;
        case "jog2":
            cartasJ2[cartasJ2.length] = carta;
            carregarCartasJ2()
            break;
    }
}

function batalhaJogadores() {
    let cartaJogador1 = document.querySelector("#cartaJ1").value;
    let cartaJogador2 = document.querySelector("#cartaJ2").value;

    if (cartaJogador1 == "" || cartaJogador2 == "") {
        alert("O cadastro e seleção de cartas dos 2 jogadores é obrigatório");
        return;
    }

    let danoJ1 = parseInt(cartaJogador1);
    let danoJ2 = parseInt(cartaJogador2);
    alert(`Dano Jogador 1: ${danoJ1} - Dano Jogador 2: ${danoJ2}`);
    // danoJ1 = parseInt(danoJ1[1]);
    // danoJ2 = parseInt(danoJ2[1]);

    let res;
    let elementoResultado = document.querySelector("#resultadoBatalha");

    if (danoJ1 > danoJ2) {
        res = "Jogador 1 venceu a rodada";
        elementoResultado.style.color = "green";
    } else if (danoJ2 > danoJ1) {
        res = "Jogador 2 venceu a rodada";
        elementoResultado.style.color = "blue";
    } else {
        res = "Rodada empatou!!";
        elementoResultado.className = "corVermelha";
    }

    elementoResultado.innerHTML = res;
}

document.querySelector("#btnAddCarta").addEventListener("click", addCarta);
document.querySelector("#btnBatalha").addEventListener("click", batalhaJogadores);

function carregarCartasJ1() {
    for ( let i=0; i < cartasJ1.length; i++){
        let carta = cartasJ1[i];

        let dano = carta[i].split(" - ")[1];



    document.querySelector("#listaJogador1").appendChild(li);
    document.querySelector("#cartaJ1").appendChild(opt);   

}
}

function carregarCartasJ2() {
    for ( let i=0; i < cartasJ2.length; i++){
        let carta = cartasJ2[i];
        let cartaDano = 

    document.querySelector("#listaJogador2").appendChild(li);
    document.querySelector("#cartaJ2").appendChild(opt);   

}
}
