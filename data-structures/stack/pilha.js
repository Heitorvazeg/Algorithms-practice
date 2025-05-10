class Pilha {
    constructor() {
        this.itens = [];
    }

    empilhar(elemento) {
        this.itens.push(elemento);
    }

    desempilhar() {
        if (this.itens.length === 0) {
            return "A pilha está vazia!";
        }
        this.itens.pop();
    }

    topo() {
        if (this.itens.length === 0) {
            return "A pilha está vazia!";
        }

        return this.itens[this.itens.length -1];
    }

    tamanho() {
        return this.itens.length;
    }

    exibir() {
        console.log(this.itens.join(", "));
    }
}

let pilha = new Pilha();

pilha.empilhar("prato_1");
pilha.empilhar("prato_2");
pilha.empilhar("prato_3");
pilha.exibir();
pilha.desempilhar();
pilha.exibir();
let tamanho = pilha.tamanho();
console.log(tamanho);
let topo = pilha.topo();
console.log(topo);