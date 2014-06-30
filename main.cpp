#include <iostream>
#include <map>
#include <vector>

using namespace std;

//Aresta
typedef struct _caminho{	
	char destino;
	int distancia;
}Caminho;


//Grafo
map< char, vector<Caminho> > mapa;

void inserirCaminho(char origem, char destino, int distancia){
	Caminho temp;
	temp.destino = destino;
	temp.distancia = distancia;

	mapa[origem].push_back(temp);

	temp.destino = origem;
	temp.distancia = distancia;
	mapa[destino].push_back(temp);
}

int main(){

	char origem, destino;
	int distancia;

	while(cin >> origem >> destino >> distancia){
		inserirCaminho(origem,destino,distancia);
	}

	map< char, vector<Caminho> >::iterator it; 
	for(it = mapa.begin();it != mapa.end();it++){
		vector<Caminho> adjacencias = it->second;
		vector<Caminho>::iterator vit;
		for(vit = adjacencias.begin(); vit != adjacencias.end() ; vit++){
			cout << it->first << " " << vit->destino << " " << vit->distancia << endl;
		}
		cout << endl;
	}
	return 0;
}