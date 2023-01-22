#include <vector>

//DFS
bool visite(int sommet, int couleur, vector<int>& etiquetage,
            const vector<vector<bool>>& graphe) {
  // On etiquette le sommet avec la couleur donnee
  etiquetage[sommet] = couleur;

  // On parcourt tous les sommets adjacents au sommet courant
  for (int i = 0; i < graphe.size(); i++) {
    if (graphe[sommet][i]) {
      // Si le sommet est adjacent et n'a pas encore ete etiquete
      if (etiquetage[i] == -1) {
        // On visite recursivement le sommet avec l'autre couleur
        visite(i, 1 - couleur, etiquetage, graphe);
      }
      // Si le sommet est adjacent et a deja ete etiquete
      else if (etiquetage[i] == couleur) {
        // Le graphe n'est pas 2-coloriable, on peut retourner n'importe quoi
        etiquetage.clear();
        return false;
      }
    }
  }
  return true;
}

vector<int> deux_col(const vector<vector<bool>>& graphe) {
  // Initialisation de l'etiquetage a -1
  vector<int> etiquetage(graphe.size(), -1);

  // On commence par le sommet 0
  bool deux_coloriable = visite(0, 0, etiquetage, graphe);

  if(!deux_coloriable){
    cout << "Le graphe n'est pas deux coloriable" << endl;
  }

  // Si on a parcouru tout le graphe sans trouver de contradiction, on retourne l'etiquetage
  return etiquetage;
}