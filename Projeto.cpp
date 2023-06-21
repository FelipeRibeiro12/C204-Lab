#include <iostream>
#include <string>

using namespace std;

struct treenode{
	int number;
    string name;
    string type;
    int atack;
    int life;
    treenode* left;
    treenode* right;
};


typedef treenode *treenodeptr;

// INSERE OS POKEMONS NA POKEDEX
void newPokemon(treenodeptr &p,  int nPokemon, string name, string type, int atack, int life){
    if (p == NULL){ // insere na raiz
    	p = new treenode;
  		p->number = nPokemon;
        p->name = name;
    	p->type = type;
    	p->atack = atack;
    	p->life = life;
        p->left = NULL;
        p->right = NULL;
    }
    else if (nPokemon < p->number) // insere na subarvore leftuerda
        newPokemon(p->left, nPokemon, name, type, atack, life);
    
    else // insere na subarvore righteita
        newPokemon(p->right, nPokemon, name, type, atack, life);
}

// Procura o valor inteiro na árvore
treenodeptr tPesq(treenodeptr p, int x){
    if (p == NULL) // elemento não encontrado
        return NULL;
    
    else if (x == p->number){ // elemento encontrado na raiz
        
        cout << p->name << endl;
        cout << p->type << endl;
        cout << p->atack << endl;
        cout << p->life << endl;
        cout << endl;
        
		return p;
	}
    
    else if (x < p->number) // procura na sub árvore esquerda
        return tPesq(p->left, x);
    
    else // procura na sub árvore direita
        return tPesq(p->right, x);
}

void emOrdem(treenodeptr p){
	
	
    if (p != NULL){
        emOrdem(p->left);

        cout << p->number << endl;
        cout << p->name << endl;
        cout << p->type << endl;
        cout << p->atack << endl;
        cout << p->life << endl;
        cout << endl;
        
        emOrdem(p->right);
    }
}

// DELETA A POKEDEX POR INTEIRO
void pDestruir(treenodeptr &pokedex){
	if (pokedex != NULL){ // Destrói os nós um por um de baixo pra cima
		pDestruir(pokedex->left);
		pDestruir(pokedex->right);
		delete pokedex;
	}
	pokedex = NULL;
}

// ´arvore binaria vazia e representada por uma variável ponteiro com conteúdo nulo
int main(){
	treenodeptr pokedex = NULL;
	
	int choice;
	int choiceaux;
	int nPokemon;
	
    string name;
    string type;
    int atack;
    int life;
    
    int pesq;
    
	nPokemon = 0;
	
    do{
        cout << "-- MENU --" << endl;
		cout << "1 para adicionar um pokemon a pokedex;" << endl; 
		cout << "2 para remover um pokemon;" << endl;
		cout << "3 para procurar um pokemon;" << endl;
		cout << "4 para ver os pokemons cadastrados:" << endl;
        cin >> choice;
        cin.ignore();

        switch (choice){
            case 1:
            	do{
            		nPokemon++;
					cout << "Digite abaixo os dados do pokemon:" << endl;
					cout << "Nome: ";
					cin >> name;
					cin.ignore();
                	cout << endl << "Tipo: ";
                	cin >> type;
                	cin.ignore();
                	cout << endl << "Forca do ataque: ";
                	cin >> atack;
                	cout << endl << "Vida: ";
                	cin >> life;
                	
                	newPokemon(pokedex, nPokemon, name, type, atack, life);
                	
                	cout << "Pokemon adicionado!" << endl;
                	cout << "0 para sair do cadastro;" << endl;
                	cout << "1 para adicionar outro pokemon a pokedex" << endl;
                	cin >> choiceaux;
                	cin.ignore();
                	
				}  while (choiceaux != 0);
                break;
            
            case 2:
                cout << "Digite o numero do pokémon a ser removido: ";
                cin >> pesq;
                //pokedex.RemovePokemon(pokedex, pesq);
                cin.ignore();
                break;
            
            case 3:
                cout << "Digite o numero do pokemon:" << endl;
                cin >> pesq;
                tPesq(pokedex, pesq);
                cin.ignore();
                break;
            
            case 4:
                cout << "Pokemons cadastrados: " << endl;
                emOrdem(pokedex);
                cout << endl;
                cout << endl;
                break;
            
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
                break;
        }

    }while (choice != 0);
    
    return 0;
}
