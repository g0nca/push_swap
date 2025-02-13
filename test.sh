#!/bin/bash

# Definição de cores e negrito
VERMELHO='\033[1;31m'
VERDE='\033[1;32m'
AZUL='\033[1;34m'
BRANCO='\033[1;37m'
AMARELO='\033[1;33m'
MAGENTA='\033[1;35m'
RESET='\033[0m'

# Verifica se os argumentos foram fornecidos
if [ $# -ne 2 ]; then
    echo -e "${VERMELHO}Erro: ${BRANCO}Você deve fornecer dois argumentos.${RESET}"
    echo -e "${VERDE}Uso correto: $0 ${BRANCO}<quantidade de execuções> <quantidade de números>${RESET}"
    exit 1
fi

# Argumentos fornecidos
quantidade_execucoes=$1
quantidade_numeros=$2

# Função para gerar números aleatórios únicos
gerar_numeros() {
    # Gera números aleatórios únicos entre 1 e 1000
    seq -10000 10000 | shuf -n $quantidade_numeros
}

# Função para executar o push_swap com a lista de números gerados
executar_push_swap() {
    # Gera os números aleatórios
    numeros=$(gerar_numeros)

    # Executa o push_swap com os números gerados e captura o output
    movimentos=$(./push_swap $numeros)

    # Conta o número de movimentos (palavras no output)
    movimentos_count=$(echo "$movimentos" | wc -w)
    
    # Retorna o número de movimentos
    echo $movimentos_count
}

# Contadores para execuções com menos de 600, 700 e 5500 movimentos
menos_600=0
menos_700=0
menos_5500=0

excedeu_700=0
excedeu_5500=0
excedeu_12=0  # Novo contador para execuções com mais de 12 movimentos (para 5 números)

# Função para imprimir os movimentos coloridos
imprimir_com_cor() {

    # Verifica a quantidade de números para determinar a cor
    if [ $quantidade_numeros -eq 100 ]; then
        # Para 100 números:
        if [ $movimentos -lt 600 ]; then
            echo -e "${VERDE}MOVIMENTOS: $movimentos${RESET}"  # Verde para abaixo de 600
        elif [ $movimentos -ge 600 ] && [ $movimentos -le 700 ]; then
            echo -e "${MAGENTA}MOVIMENTOS: $movimentos${RESET}"  # Magenta para entre 600 e 700
        else
            echo -e "${VERMELHO}MOVIMENTOS: $movimentos${RESET}"  # Vermelho para acima de 700
        fi
    else
        # Para mais de 100 números:
        if [ $movimentos -lt 5500 ]; then
            echo -e "${VERDE}MOVIMENTOS: $movimentos${RESET}"  # Verde para abaixo de 5500
        else
            echo -e "${VERMELHO}MOVIMENTOS: $movimentos${RESET}"  # Vermelho para acima de 5500
        fi
    fi
}

# Loop para executar o push_swap o número de vezes especificado
for i in $(seq 1 $quantidade_execucoes)
do
    echo -e "🛠️${AZUL}  </Execução> $i:${RESET}"
    
    # Chama a função de execução e armazena o número de movimentos
    movimentos=$(executar_push_swap)
    
    imprimir_com_cor $movimentos
    
    # Verifica se a execução ultrapassou 700 movimentos para 100 números e exibe a mensagem em vermelho
    if [ $quantidade_numeros -eq 100 ] && [ $movimentos -gt 700 ]; then
    	echo -e "${VERMELHO}Execução $i ultrapassou 700 movimentos com $quantidade_numeros números! (${movimentos} movimentos)${RESET}"
        ((excedeu_700++))
    fi
    if [ $quantidade_numeros -eq 500 ] && [ $movimentos -gt 5500 ]; then
    	echo -e "${VERMELHO}Execução $i ultrapassou 5500 movimentos com $quantidade_numeros números! (${movimentos} movimentos)${RESET}"
        ((excedeu_5500++))
    fi
    
    # Nova verificação para 5 números
    if [ $quantidade_numeros -eq 5 ] && [ $movimentos -gt 12 ]; then
        echo -e "${VERMELHO}Execução $i ultrapassou 12 movimentos com $quantidade_numeros números! (${movimentos} movimentos)${RESET}"
        ((excedeu_12++))
    fi

    # Conta execuções com menos de 600, 700 e 5500 movimentos
    if [ $movimentos -lt 600 ]; then
        menos_600=$((menos_600 + 1))
    fi
    
    if [ $movimentos -lt 700 ]; then
        menos_700=$((menos_700 + 1))
    fi

    if [ $movimentos -lt 5500 ]; then
        menos_5500=$((menos_5500 + 1))
    fi

    echo "---------------------"
done

# Adiciona a verificação para exibir as execuções com menos de 600 e 700 movimentos somente se a quantidade de números for <= 150
if [ $quantidade_numeros -le 150 ] && [ $quantidade_numeros -gt 15 ]; then
    echo -e "${BRANCO}Execuções com menos de ${VERDE}600 ${BRANCO}movimentos: $menos_600${RESET}"
    echo -e "${BRANCO}Execuções com menos de ${AMARELO}700 ${BRANCO}movimentos: $menos_700${RESET}"
fi

# Adiciona a verificação para exibir as execuções com menos de 5500 movimentos somente se a quantidade de números for > 150 e <= 500
if [ $quantidade_numeros -gt 150 ] && [ $quantidade_numeros -le 500 ]; then
    echo -e "${BRANCO}Execuções com menos de ${VERDE}5500${BRANCO} movimentos: $menos_5500${RESET}"
fi

# Exibe as mensagens sobre execuções que ultrapassaram os limites de movimentos
if [ $quantidade_numeros -eq 100 ]; then
    echo -e "${BRANCO}Execuções com mais de ${VERMELHO}700${BRANCO} movimentos (para 100 números): $excedeu_700${RESET}"
fi

if [ $quantidade_numeros -gt 500 ]; then
    echo -e "${BRANCO}Execuções com mais de ${VERMELHO}5500${BRANCO} movimentos (para 500 números): $excedeu_5500${RESET}"
fi

# Exibe a mensagem para execuções com mais de 12 movimentos (para 5 números)
if [ $quantidade_numeros -le 15 ]; then
    echo -e "${BRANCO}Execuções com mais de ${VERMELHO}12${BRANCO} movimentos (para 5 números): $excedeu_12${RESET}"
fi
