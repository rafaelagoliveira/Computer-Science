"""
Autômato finito determinístico
"""


def ler_alfabeto():
    """
    Ler o alfabeto
    """

    alfabeto = input('\nEntre com o alfabeto: ')
    return alfabeto.split(',')


def ler_numero_estados():
    """
    Ler os estados
    """

    estados = input('Entre com os estados: ')
    return estados.split(',')


# Lê o estado inicial
def ler_estado_inicial(estados):
    """
    Ler o estado inicial
    """

    while True:
        estado = input('Entre com o estado inicial: ')
        if estado in estados:
            return estado
        print('Digite um estado válido.')


def ler_estados_finais(estados):
    """
    Ler os estados finais
    """

    while True:
        estados_input = input('Entre com os estados de aceitação: ')
        estados_input = estados_input.split(',')
        if all(estado in estados for estado in estados_input):
            return estados_input
        print('Digite estados válidos.')


def ler_tabela_transicao(estados, alfabeto):
    """
    Ler a tabela de transição
    """

    tabela = {}

    for estado in estados:
        # Cria um dicionário vazio para cada estado na tabela de transição
        tabela[estado] = {}
        for simbolo in alfabeto:
            while True:
                # Lê as transições para cada par estado-símbolo
                transicao = input(f'Delta({estado},{simbolo}): ')
                if transicao == '-' or transicao in estados:
                    # Verifica se o estado de transição é válido ou se é '-' para representar ausência de transição
                    tabela[estado][simbolo] = transicao
                    break
                print('Digite um estado válido ou "-" para representar a ausência de transição.')
    return tabela


def verificar_palavra_valida(palavra, alfabeto):
    """
    Verificar se a palavra é válida
    """
    for simbolo in palavra:
        # Verifica se cada símbolo da palavra pertence ao alfabeto
        if simbolo not in alfabeto:
            return False
    return True


def verificar_aceitacao(palavra, tabela, estados_finais, estado_inicial):
    """
    Verificar aceitação da palavra
    """
    estado_atual = estado_inicial

    for simbolo in palavra:
        if estado_atual not in tabela or simbolo not in tabela[estado_atual]:
            # Verifica se há uma transição definida para o estado atual e símbolo atual
            return False
        estado_atual = tabela[estado_atual][simbolo]
        if estado_atual == '-':
            # Verifica se a transição leva ao estado '-' que representa ausência de transição
            return None

    return estado_atual in estados_finais


def main():
    """
    Funcão main
    """

    repetir = 0

    while repetir <= 2:
        alfabeto = ler_alfabeto()
        estados = ler_numero_estados()
        estado_inicial = ler_estado_inicial(estados)
        estados_finais = ler_estados_finais(estados)
        tabela = ler_tabela_transicao(estados, alfabeto)

        print('   ', end='')
        for simbolo in alfabeto:
            print(simbolo, end='  ')
        print()

        for estado in estados:
            print(f'{estado}|', end='')
            for simbolo in alfabeto:
                if simbolo in tabela[estado]:
                    print(f' {tabela[estado][simbolo]} ', end='')
            print()

        repetir = 1
        while repetir == 1:
            palavra = input('\nEntre com a palavra verificada: ')
            if not verificar_palavra_valida(palavra, alfabeto):
                print('Palavra possui símbolo inválido')
            else:
                verificador = verificar_aceitacao(palavra, tabela, estados_finais, estado_inicial)
                if verificador:
                    print('\nSucesso!')
                elif verificador is None:
                    print('\nAFD não é capaz de processar a palavra fornecida.')
                elif verificador is False:
                    print('\nPalavra não reconhecida!')

            while True:
                try:
                    repetir = int(input('\n1 - Nova palavra\n2 - Novo autômato\n3 - Sair\n--> '))
                    if repetir < 1 or repetir > 3:
                        raise ValueError
                    break
                except ValueError:
                    print('Entrada inválida. Por favor, digite um valor válido.')

    print('Programa encerrado.')


if __name__ == '__main__':
    main()
