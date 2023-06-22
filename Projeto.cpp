#include <iostream>
#include <string>

using namespace std;

struct treenode {
    int number;
    string name;
    string type;
    int atack;
    int life;
    treenode* left;
    treenode* right;
};

typedef treenode *treenodeptr;

void newPokemon(treenodeptr &p, int nPokemon, string name, string type, int atack, int life) {
    if (p == NULL) {
        p = new treenode;
        p->number = nPokemon;
        p->name = name;
        p->type = type;
        p->atack = atack;
        p->life = life;
        p->left = NULL;
        p->right = NULL;
    } else if (nPokemon < p->number) {
        newPokemon(p->left, nPokemon, name, type, atack, life);
    } else {
        newPokemon(p->right, nPokemon, name, type, atack, life);
    }
}

treenodeptr tPesq(treenodeptr p, int x) {
    if (p == NULL)
        return NULL;
    else if (x == p->number) {
        cout << p->name << endl;
        cout << p->type << endl;
        cout << p->atack << endl;
        cout << p->life << endl;
        cout << endl;
        return p;
    } else if (x < p->number) {
        return tPesq(p->left, x);
    } else {
        return tPesq(p->right, x);
    }
}

void emOrdem(treenodeptr p) {
    if (p != NULL) {
        emOrdem(p->left);
        cout << p->number << endl;
        cout << p->name << endl;
        cout << p->type << endl;
        cout << p->atack << endl;
        cout << p->life << endl << endl;
        emOrdem(p->right);
    }
}

void pDestruir(treenodeptr &pokedex) {
    if (pokedex != NULL) {
        pDestruir(pokedex->left);
        pDestruir(pokedex->right);
        delete pokedex;
    }
    pokedex = NULL;
}

treenodeptr findMin(treenodeptr p) {
    while (p->left != NULL) {
        p = p->left;
    }
    return p;
}

void removePokemon(treenodeptr &p, int x) {
    if (p == NULL) 
        return;
    
    else if (x < p->number) 
        removePokemon(p->left, x);
    
    else if (x > p->number) 
        removePokemon(p->right, x);
    
    else {
        if (p->left == NULL && p->right == NULL) { //Folha
            delete p;
            p = NULL;
        }
        else if (p->left == NULL) { //No com apenas filho a direita
            treenodeptr temp = p;
            p = p->right;
            delete temp;
        }
        else if (p->right == NULL) { //No com apenas filho a esquerda
            treenodeptr temp = p;
            p = p->left;
            delete temp;
        }
        else { //No com dois filhos
            treenodeptr temp = findMin(p->right);
            p->number = temp->number;
            p->name = temp->name;
            p->type = temp->type;
            p->atack = temp->atack;
            p->life = temp->life;
            removePokemon(p->right, temp->number);
        }
    }
}

int main() {
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
    
    cout << "Bem Vindo!" << endl;
    
    do {
	cout << "Bem Vindo!" << endl << "-- MENU --" << endl;
        cout << "1 - Adicionar um pokemon a pokedex;" << endl; 
        cout << "2 - Remover um pokemon;" << endl;
        cout << "3 - Procurar um pokemon;" << endl;
        cout << "4 - Mostrar pokedex;" << endl;
        cout << "5 - Limpar pokedex." << endl;
        cout << "0 - Sair" << endl << endl;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 0:
                cout << "Obrigado por utilizar!" << endl << "Ate mais!" << endl;
                
                cin.ignore();
                break;
            
            case 1:
                do {
                    nPokemon++;
                    cout << "Digite abaixo os dados do pokemon:" << endl;
                    cout << "Nome: ";
                    cin >> name;
                    cin.ignore();
                    cout << "Tipo: ";
                    cin >> type;
                    cin.ignore();
                    cout << "Força do ataque: ";
                    cin >> atack;
                    cout << "Vida: ";
                    cin >> life;
                    newPokemon(pokedex, nPokemon, name, type, atack, life);
                    cout << "Pokedex atualizada!" << endl << endl;
                    cout << "0 - Sair do cadastro;" << endl << "1 - Adicionar outro pokemon." << endl << endl;
                    cin >> choiceaux;
                    cin.ignore();
                } while (choiceaux != 0);
                break;
            
            case 2:
                cout << "Digite o numero do pokémon a ser removido: ";
                
                cin >> pesq;
                removePokemon(pokedex, pesq);
                cout << "Pokedex atualizada!" << endl;
                cin.ignore();
                break;
            
            case 3:
                cout << "Digite o numero do pokemon na pokedex:" << endl;
                
                cin >> pesq;
                tPesq(pokedex, pesq);
                cin.ignore();
                break;
            
            case 4:
                cout << "Pokedex: " << endl;
                
                emOrdem(pokedex);
                break;
            
            case 5:
                cout << "Alerta!" << endl << "Tem certeza que deseja limpar a pokedex? " << endl;
                cout << "1 - Cancelar;" << endl << "2 - Continuar." << endl;
                
                int aux5;
                cin >> aux5;
                
                if (aux5 == 2) {
                    cout << "Deletando pokedex..." << endl;
                    
                    pDestruir(pokedex);
                    cout << "Pokedex limpa." << endl;
                }
                else
                    cout << "Operacao cancelada" << endl;
                
                cin.ignore();
                break;
            
            default:
                cout << "Opção inválida. Tente novamente." << endl;
                
                break;
        }
        cout << endl;
        
    } while (choice != 0);
    
    pDestruir(pokedex);
    
    return 0;
}
