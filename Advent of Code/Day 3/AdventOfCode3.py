import re
 


def extrair_mul(linha):
    # Expressão regular para identificar as instruções 'mul(X,Y)'
    padrao = r"mul\((\d{1,3}),(\d{1,3})\)"
    
    # Encontrar todas as correspondências na linha
    matches = re.finditer(padrao, linha)
    soma = 0

    for match in matches:
        x = int(match.group(1))
        y = int(match.group(2))
        resultado = x * y
        soma = resultado + soma
    return soma
def main():
    try:
        soma_total= 0
        with open("C:\\Users\\Lucas\\Documents\\Advent of Code\\Day 3\\input.txt", "r") as input_file:
            linhas = input_file.readlines()
            for linha in linhas:
                soma_total += extrair_mul(linha)
            print(f"Soma total: {soma_total}")
    except FileNotFoundError:
        print("Erro ao abrir o arquivo")

main()
