# Projeto: Exchange de Criptomoedas
- Nome: Henrique Bassan Rebechi
- Ra: 22.223.083-1
## Descrição
Este projeto é uma aplicação de linha de comando para gerenciar uma exchange de criptomoedas. O sistema permite que administradores realizem operações como cadastro de investidores, consulta de saldo e extrato de investidores, além de operações em criptomoedas. O sistema é desenvolvido em linguagem C e utiliza arquivos de dados para armazenar informações sobre investidores, saldos e transações.

## Funcionalidades

- Cadastro de novo investidor: Permite registrar um novo investidor com nome, CPF e senha. Cada investidor inicia com saldo zero.
  
- Login de investidor: O sistema valida o CPF e a senha para permitir o acesso ao menu principal.
- Consulta de saldo: O administrador pode consultar o saldo atual de um investidor usando o CPF.
- Consulta de extrato: O administrador pode visualizar o histórico de transações de um investidor.
- Cadastro de criptomoeda: Permite adicionar novas criptomoedas com informações como cotação inicial, taxa de compra e taxa de venda.
- Atualização de cotação: O administrador pode atualizar a cotação de criptomoedas existentes.
- Registro de transações: Permite registrar uma transação, que ajusta o saldo do investidor e registra a transação no extrato.
- Exclusão de investidor e criptomoeda: Permite excluir investidores e criptomoedas do sistema.

# Como Usar

- Tela Inicial: Ao iniciar o programa, você verá a opção de Registrar Novo Investidor ou Efetuar Login. Escolha uma dessas opções para prosseguir.

- Menu Principal: Após fazer login, o menu principal do sistema será exibido com as seguintes opções:

1. Cadastrar Novo Investidor
2. Excluir Investidor
3. Cadastrar Criptomoeda
4. Excluir Criptomoeda
5. Consultar Saldo do Investidor
6. Consultar Extrato do Investidor
7. Atualizar Cotação de Criptomoedas
8. Registrar Transação
9. Sair
    
- Registrar Transação: Na opção Registrar Transação, você pode especificar o CPF do investidor, a descrição da transação e o valor. O saldo será ajustado e a transação será registrada no extrato.

- Consultar Saldo e Extrato: Use as opções Consultar Saldo e Consultar Extrato para visualizar o saldo atual e o histórico de transações de um investidor específico.
