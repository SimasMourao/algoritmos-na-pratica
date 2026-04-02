def busca_binaria (vetor, item):
    baixo = 0;
    alto = len(vetor) -1;

    while baixo <= item:
        meio = (baixo + alto) // 2;
        chute = vetor[meio];
            
        if chute == item:
            return meio;
        
        if chute > item:
            alto = meio -1;
        
        else:
            baixo = meio + 1;
    return None;

minha_lista = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11];
item = int(input("Digite um número: "));
print("O número {} está no índice {}".format(item, busca_binaria(minha_lista, item)));

