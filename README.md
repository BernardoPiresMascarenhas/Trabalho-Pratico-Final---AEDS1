# Trabalho Prático Final - AEDS 1

Esse projeto em C++ é um sistema de cadastro e gerenciamento de pessoas, mais especificamente alunos e professores, em uma estrutura que simula o armazenamento e manipulação de dados de uma escola ou instituição de ensino. Ele inclui as seguintes funcionalidades principais:

# Classes Base e Herança
Pessoa: Classe base que contém informações comuns a todos, como o nome e a data de nascimento.
Aluno: Herda de Pessoa e adiciona o atributo matrícula.
Professor: Também herda de Pessoa e adiciona o atributo titulação (e.g., Especialista, Mestre, Doutor).
# Cadastro de Alunos e Professores
O sistema permite o cadastro de alunos e professores, solicitando nome, data de nascimento, e, no caso dos alunos, a matrícula, e dos professores, a titulação.
# Listagem
É possível listar todos os alunos e professores cadastrados. Isso é útil para visualizar as informações completas armazenadas.
# Edição e Exclusão
O usuário pode alterar os dados de um aluno ou professor já cadastrado ou excluir esses registros.
# Aniversariantes do Mês
O sistema possui uma função que permite listar os alunos e professores que fazem aniversário no mês especificado, tornando o código mais interativo e personalizado.
# Persistência de Dados
Os dados de alunos e professores são salvos em um arquivo (dados.txt) e carregados novamente ao abrir o programa. Isso é importante para manter o histórico das informações entre execuções.
# Estrutura
Utiliza um array estático com limite de 1000 registros, definido pela macro _MAX, o que pode ser suficiente para um sistema pequeno, mas não escalável para grandes volumes de dados. Cada índice no array guarda um ponteiro para um objeto Aluno ou Professor.
# Tratamento de Erros
O projeto lida com alguns erros, como alocações de memória e manipulação de arquivos, através de try/catch, o que melhora a robustez do sistema.
# Validação
Há validação simples de datas na classe Data para impedir que datas inválidas sejam inseridas.
Aplicabilidade:
Esse tipo de projeto é bastante útil em cenários onde se deseja gerenciar informações de forma simples e eficiente, como em sistemas de escolas, universidades, ou até cursos online, oferecendo funções básicas de gerenciamento de cadastro e dados históricos.

Se for expandido, ele poderia ser integrado a bancos de dados para uma gestão mais eficiente e permitir funcionalidades mais avançadas, como relatórios ou geração de estatísticas.
