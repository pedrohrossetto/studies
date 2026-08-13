function bemVindo(){
    let nome = document.querySelector("#txtNome").value;
    alert("Bem-vindo(a) "+nome);
}
function calcularIdade(){
    let nome = document.querySelector("#txtNome").value;
    let anoNasc = document.querySelector("#txtAno").value;
    alert(nome+" você nasceu em "+anoNasc);
    let idade = 2025 - anoNasc;
    alert(nome + " você tem "+ idade + " anos");
}