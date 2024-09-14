#include <iostream>
#include <string>
#include <fstream>
#define _MAX 1000

using namespace std;

class Data {
private:
    int dia;
    int mes;
    int ano;

public:
    void setDia(int dia) {
        this->dia = dia;
    }

    int getDia() const {
        return this->dia;
    }

    void setMes(int mes) {
        this->mes = mes;
    }

    int getMes() const {
        return this->mes;
    }

    void setAno(int ano) {
        this->ano = ano;
    }

    int getAno() const {
        return this->ano;
    }

    void setData(int dia, int mes, int ano) {
        if (dia > 31 || mes > 12 || ano > 2024 || dia < 0 || mes < 0 || ano < 0) {
            cout << "DATA INVALIDA" << endl;
        } else {
            setDia(dia);
            setMes(mes);
            setAno(ano);
        }
    }

    void lerData() {
        int d, m, a;

        cout << "Digite a data (dia): ";
        cin >> d;

        cout << "Digite a data (mes): ";
        cin >> m;

        cout << "Digite a data (ano): ";
        cin >> a;

        setData(d, m, a);
    }

    void escrever_tela() const {
        cout << getDia() << " / " << getMes() << " / " << getAno();
    }

    bool verificarMes(int mes) const {
        return this->mes == mes;
    }
};

class Pessoa {
private:
    Data nascimento;
    string nome;

public:
    Pessoa() {}

    void setNome(string nome) {
        this->nome = nome;
    }

    string getNome() const {
        return this->nome;
    }

    void setNascimento(Data nascimento) {
        this->nascimento = nascimento;
    }

    Data getNascimento() const {
        return this->nascimento;
    }

    void lerNome() {
        cout << "Digite o nome: ";
        cin >> nome;
    }

    void lerPessoa() {
        lerNome();
        nascimento.lerData();
    }

    virtual void escrever_tela() const {
        cout << "Nome: " << getNome() << endl;
        cout << "Data de nascimento: ";
        nascimento.escrever_tela();
        cout << endl;
    }

    virtual string getTipo() const {
        return "Pessoa";
    }

    virtual ~Pessoa() {}
};

class Aluno : public Pessoa {
private:
    int matricula;

public:
    Aluno() {}

    void setMatricula(int matricula) {
        this->matricula = matricula;
    }

    int getMatricula() const {
        return this->matricula;
    }

    void escrever_tela() const override {
        Pessoa::escrever_tela();
        cout << "Matricula: " << getMatricula() << endl;
    }

    string getTipo() const override {
        return "Aluno";
    }

    ~Aluno() override {}
};

class Professor : public Pessoa {
private:
    string titulacao;

public:
    Professor() {}

    void setTitulacao(string titulacao) {
        this->titulacao = titulacao;
    }

    string getTitulacao() const {
        return this->titulacao;
    }

    void escrever_tela() const override {
        Pessoa::escrever_tela();
        cout << "Titulacao: " << getTitulacao() << endl;
    }

    string getTipo() const override {
        return "Professor";
    }

    ~Professor() override {}
};

void cadastrarAluno(Aluno **alunos, int &indiceAluno);
void cadastrarProfessor(Professor **professores, int &indiceProfessor);
void listarAlunos(Aluno **alunos, int indiceAluno);
void listarProfessores(Professor **professores, int indiceProfessor);
void listarAniversariantesDoMes(Pessoa **pessoas, int indicePessoa);
void alterarAluno(Aluno **alunos, int indiceAluno);
void alterarProfessor(Professor **professores, int indiceProfessor);
void excluirAluno(Aluno **alunos, int &indiceAluno);
void excluirProfessor(Professor **professores, int &indiceProfessor);
void salvarDados(Aluno **alunos, int indiceAluno, Professor **professores, int indiceProfessor);
void carregarDados(Aluno **alunos, int &indiceAluno, Professor **professores, int &indiceProfessor);

int main() {
    Aluno *alunos[_MAX];
    Professor *professores[_MAX];
    Pessoa *pessoas[_MAX];
    int indiceAluno = 0;
    int indiceProfessor = 0;
    int indicePessoa = 0;
    int opcao;

    try {
        carregarDados(alunos, indiceAluno, professores, indiceProfessor);
    } catch (const exception &e) {
        cerr << "Erro ao carregar dados: " << e.what() << endl;
        return 1;
    }

    do {
        cout << "\n0 - Para Sair" << endl;
        cout << "1 - Cadastrar" << endl;
        cout << "2 - Listar" << endl;
        cout << "3 - Alterar" << endl;
        cout << "4 - Excluir" << endl;
        cout << "5 - Listar aniversariantes do m�s (alunos e professores)" << endl;
        cout << "Digite uma das opcoes: ";
        cin >> opcao;

        int subOpcao;
        switch (opcao) {
            case 0:
                cout << "\nObrigado por usar o programa!" << endl;
                break;

            case 1:
                cout << "0 - Reornar" << endl;
                cout << "1 - Aluno" << endl;
                cout << "2 - Professor" << endl;
                cout << "Digite uma das opcoes: ";
                cin >> subOpcao;
                if (subOpcao == 1) {
                    cadastrarAluno(alunos, indiceAluno);
                    pessoas[indicePessoa++] = alunos[indiceAluno - 1];
                } else if (subOpcao == 2) {
                    cadastrarProfessor(professores, indiceProfessor);
                    pessoas[indicePessoa++] = professores[indiceProfessor - 1];
                }
                break;

            case 2:
                cout << "0 - Reornar" << endl;
                cout << "1 - Aluno" << endl;
                cout << "2 - Professor" << endl;
                cout << "Digite uma das opcoes: ";
                cin >> subOpcao;
                if (subOpcao == 1) {
                    listarAlunos(alunos, indiceAluno);
                } else if (subOpcao == 2) {
                    listarProfessores(professores, indiceProfessor);
                }
                break;

            case 3:
                cout << "0 - Reornar" << endl;
                cout << "1 - Aluno" << endl;
                cout << "2 - Professor" << endl;
                cout << "Digite uma das opcoes: ";
                cin >> subOpcao;
                if (subOpcao == 1) {
                    alterarAluno(alunos, indiceAluno);
                } else if (subOpcao == 2) {
                    alterarProfessor(professores, indiceProfessor);
                }
                break;

            case 4:
                cout << "0 - Reornar" << endl;
                cout << "1 - Aluno" << endl;
                cout << "2 - Professor" << endl;
                cout << "Digite uma das opcoes: ";
                cin >> subOpcao;
                if (subOpcao == 1) {
                    excluirAluno(alunos, indiceAluno);
                } else if (subOpcao == 2) {
                    excluirProfessor(professores, indiceProfessor);
                }
                break;

            case 5:
                listarAniversariantesDoMes(pessoas, indicePessoa);
                break;

            default:
                cout << "Op��o inv�lida. Tente novamente." << endl;
                break;
        }
    } while (opcao != 0);

    try {
        salvarDados(alunos, indiceAluno, professores, indiceProfessor);
    } catch (const exception &e) {
        cerr << "Erro ao salvar dados: " << e.what() << endl;
        return 1;
    }

    return 0;
}

void cadastrarAluno(Aluno **alunos, int &indiceAluno) {
    if (indiceAluno >= _MAX) {
        cout << "Capacidade m�xima de alunos atingida." << endl;
        return;
    }
    try {
        alunos[indiceAluno] = new Aluno();
    } catch (const bad_alloc &e) {
        cerr << "Erro ao alocar mem�ria para aluno: " << e.what() << endl;
        return;
    }
    alunos[indiceAluno]->lerPessoa();
    int matricula;
    cout << "Digite a matr�cula do aluno: ";
    cin >> matricula;
    alunos[indiceAluno]->setMatricula(matricula);
    indiceAluno++;
}

void cadastrarProfessor(Professor **professores, int &indiceProfessor) {
    if (indiceProfessor >= _MAX) {
        cout << "Capacidade m�xima de professores atingida." << endl;
        return;
    }
    try {
        professores[indiceProfessor] = new Professor();
    } catch (const bad_alloc &e) {
        cerr << "Erro ao alocar mem�ria para professor: " << e.what() << endl;
        return;
    }
    professores[indiceProfessor]->lerPessoa();
    string titulacao;
    cout << "Digite a titula��o do professor (Especialista, Mestre, Doutor): ";
    cin >> titulacao;
    professores[indiceProfessor]->setTitulacao(titulacao);
    indiceProfessor++;
}

void listarAlunos(Aluno **alunos, int indiceAluno) {
    for (int i = 0; i < indiceAluno; ++i) {
        cout << "\nAluno " << i + 1 << ":" << endl;
        alunos[i]->escrever_tela();
    }
}

void listarProfessores(Professor **professores, int indiceProfessor) {
    for (int i = 0; i < indiceProfessor; ++i) {
        cout << "\nProfessor " << i + 1 << ":" << endl;
        professores[i]->escrever_tela();
    }
}

void listarAniversariantesDoMes(Pessoa **pessoas, int indicePessoa) {
    int mes_atual;
    cout << "Digite o n�mero do m�s atual: ";
    cin >> mes_atual;

    cout << "Aniversariantes do m�s " << mes_atual << ":" << endl;
    for (int i = 0; i < indicePessoa; ++i) {
        if (pessoas[i]->getNascimento().verificarMes(mes_atual)) {
            pessoas[i]->escrever_tela();
            cout << endl;
        }
    }
}

void alterarAluno(Aluno **alunos, int indiceAluno) {
    listarAlunos(alunos, indiceAluno);
    int pos;
    cout << "Digite o n�mero do aluno a ser alterado: ";
    cin >> pos;
    if (pos < 1 || pos > indiceAluno) {
        cout << "Aluno n�o encontrado." << endl;
        return;
    }
    alunos[pos - 1]->lerPessoa();
    int matricula;
    cout << "Digite a nova matr�cula do aluno: ";
    cin >> matricula;
    alunos[pos - 1]->setMatricula(matricula);
}

void alterarProfessor(Professor **professores, int indiceProfessor) {
    listarProfessores(professores, indiceProfessor);
    int pos;
    cout << "Digite o n�mero do professor a ser alterado: ";
    cin >> pos;
    if (pos < 1 || pos > indiceProfessor) {
        cout << "Professor n�o encontrado." << endl;
        return;
    }
    professores[pos - 1]->lerPessoa();
    string titulacao;
    cout << "Digite a nova titula��o do professor (Especialista, Mestre, Doutor): ";
    cin >> titulacao;
    professores[pos - 1]->setTitulacao(titulacao);
}

void excluirAluno(Aluno **alunos, int &indiceAluno) {
    listarAlunos(alunos, indiceAluno);
    int pos;
    cout << "Digite o n�mero do aluno a ser exclu�do: ";
    cin >> pos;
    if (pos < 1 || pos > indiceAluno) {
        cout << "Aluno n�o encontrado." << endl;
        return;
    }
    delete alunos[pos - 1];
    for (int i = pos - 1; i < indiceAluno - 1; ++i) {
        alunos[i] = alunos[i + 1];
    }
    indiceAluno--;
    alunos[indiceAluno] = nullptr;
}

void excluirProfessor(Professor **professores, int &indiceProfessor) {
    listarProfessores(professores, indiceProfessor);
    int pos;
    cout << "Digite o n�mero do professor a ser exclu�do: ";
    cin >> pos;
    if (pos < 1 || pos > indiceProfessor) {
        cout << "Professor n�o encontrado." << endl;
        return;
    }
    delete professores[pos - 1];
    for (int i = pos - 1; i < indiceProfessor - 1; ++i) {
        professores[i] = professores[i + 1];
    }
    indiceProfessor--;
    professores[indiceProfessor] = nullptr;
}

void salvarDados(Aluno **alunos, int indiceAluno, Professor **professores, int indiceProfessor) {
    ofstream arq("dados.txt");
    if (!arq) {
        throw runtime_error("N�o foi poss�vel abrir o arquivo de dados para escrita.");
    }

    arq << indiceAluno << " " << indiceProfessor << endl;

    for (int i = 0; i < indiceAluno; ++i) {
        arq << alunos[i]->getNome() << " "
            << alunos[i]->getNascimento().getDia() << " "
            << alunos[i]->getNascimento().getMes() << " "
            << alunos[i]->getNascimento().getAno() << " "
            << alunos[i]->getMatricula() << endl;
    }

    for (int i = 0; i < indiceProfessor; ++i) {
        arq << professores[i]->getNome() << " "
            << professores[i]->getNascimento().getDia() << " "
            << professores[i]->getNascimento().getMes() << " "
            << professores[i]->getNascimento().getAno() << " "
            << professores[i]->getTitulacao() << endl;
    }
}

void carregarDados(Aluno **alunos, int &indiceAluno, Professor **professores, int &indiceProfessor) {
    ifstream arq("dados.txt");
    if (!arq) {
        throw runtime_error("N�o foi poss�vel abrir o arquivo de dados para leitura.");
    }

    arq >> indiceAluno >> indiceProfessor;

    for (int i = 0; i < indiceAluno; ++i) {
        try {
            alunos[i] = new Aluno();
        } catch (const bad_alloc &e) {
            cerr << "Erro ao alocar mem�ria para aluno: " << e.what() << endl;
            return;
        }

        string nome;
        int dia, mes, ano, matricula;
        arq >> nome >> dia >> mes >> ano >> matricula;

        alunos[i]->setNome(nome);
        Data data;
        data.setData(dia, mes, ano);
        alunos[i]->setNascimento(data);
        alunos[i]->setMatricula(matricula);
    }

    for (int i = 0; i < indiceProfessor; ++i) {
        try {
            professores[i] = new Professor();
        } catch (const bad_alloc &e) {
            cerr << "Erro ao alocar mem�ria para professor: " << e.what() << endl;
            return;
        }

        string nome;
        int dia, mes, ano;
        string titulacao;
        arq >> nome >> dia >> mes >> ano >> titulacao;

        professores[i]->setNome(nome);
        Data data;
        data.setData(dia, mes, ano);
        professores[i]->setNascimento(data);
        professores[i]->setTitulacao(titulacao);
    }
}
