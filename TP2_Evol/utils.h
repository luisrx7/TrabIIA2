void imprime_matriz(int *grafo, int vert);

int* init_dados(char *nome, int *n,int *lig);

struct info init_data(char *filename, int *mat);

pchrom init_pop(struct info);

void print_pop(pchrom, struct info);

chrom get_best(pchrom, struct info, chrom);

void write_best(chrom, struct info);

void init_rand();

int random_l_h(int, int);

float rand_01();

int flip();
