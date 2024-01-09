/*Pilha * push (Pilha *p, int valor){
    Pilha * novoP = (Pilha *)malloc(sizeof(Pilha));
    if(novoP == NULL){
        printf("[ERRO].\n");
        exit(1);
    }

    novoP->topo = valor;
    novoP->next = p;
    return novoP;
}

int pop (Pilha *p){
    Pilha *temp = p;
    int valor;

    if(p->topo == NULL){
        printf("PILHA VAZIA.\n");
        exit(1);
    }

    valor = p->topo;
    p = p->next;
    free(temp);

    return valor;
}


int calcular(char string[]){
    //INICIALIZAR A PILHA
    Pilha *p = NULL;
    int i, numero, op1, op2, res;

    for(i = 0; string[i] != '\0'; i++){
        if(isdigit(string[i])){
            numero = atoi(&string[i]);
            push(&p, numero);
        } else {
            op2 = pop(&p);
            op1 = pop(&p);
            
        }
    }


}*/