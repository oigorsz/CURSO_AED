if(q == NULL){
                    //NÃO POSSUI PAI, ENTÃO TRATA-SE DO NÓ RAIZ, OU SEJA LIBERA TUDO
                    p = liberar(p);
                    printf("REMOVEU O NO RAIZ\n");
                }else if(q->prim == p){
                    printf("REMOVEU O PRIMEIO FILHO DO PAI\n");
                    q->prim = p->prox; //CONECTA O PAI COM O PROXIMO IRMÃO, CASO ELE EXISTA
                    p->prox = NULL; //P PERDER A CONEXÃO COM OS IRMÃOS
                    p = liberar(p); //LIBERA OS DECENDENTES DE P SEM REMOVER OS SEUS IRMÃOS
                } else if(q->prim != p){
                     printf("REMOVEU UM FILHO NO MEIO OU FINAL\n");
                    // Desconectar p da árvore
                    for (r = q->prim; r->prox != NULL && r->prox != p; r = r->prox);
                    if (r->prox == p) {
                        // Se p não for o último filho de q
                        r->prox = p->prox;
                    }
                    // Liberar todos os descendentes de p
                    p->prim = liberar(p->prim);
                    // Liberar o próprio nó p
                    free(p->data);
                    free(p);
                }
            } else {
                printf("NOME NÃO EXISTENTE");
            }