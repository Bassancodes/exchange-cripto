# Projeto Exchange de Criptomoedas

## Meu nome e minha matricula
- Henrique Bassan Rebechi – 22.223.083-1  

## Objetivo do Projeto
Ola professor!!! Esse projeto é uma simulação de uma plataforma de exchange de criptomoedas. O projeto tem as principais funcionalidades de uma carteira de criptomoedas, como cadastro, login, compra, venda, extrato e outras operações.

## Como Compilar e Executar
Para compilar:
```bash
gcc src/*.c -Iinclude -o exchange
```
Para rodar:
```bash
./exchange
```
A execução deve ser feita a partir da raiz do projeto. (demorei um pouco pra enxergar isso)

## Como Usar
1. **Login ou Cadastro:**
   - Ao iniciar o programa, o usuário escolhe se quer logar ou criar uma conta.

2. **Menu Principal:**
   - Ver saldo da carteira
   - Depositar reais
   - Comprar criptomoedas
   - Vender criptomoedas
   - Gerar extrato (em arquivo .txt)
   - Atualizar cotação das criptomoedas (entre -5% e +5%)
   - Sacar reais (com validação de senha)
   - Sair

3. **Armazenamento:**
   - Os dados dos usuários ficam salvos em `data/users.dat`
   - O extrato de cada usuário é salvo como `data/extrato_<CPF>.txt`

