
typedef struct Conta * p_conta;


void inicializar(p_conta pConta[], int tamanho);


void cadastrar(p_conta pConta[], int posicao);


void imprimir(p_conta pConta[], int tamanho);


void atualizar(p_conta pConta[], int tamanho);


void saldoGeral(p_conta const *pConta, int i);


void depositar(p_conta pConta[], int tamanho);//?


void sacar(p_conta pConta[], int tamanho);


void listarContaUnica(p_conta pConta[], int tamanho);


int procurarConta();

void imprimirConta(p_conta const *pConta, int i);

