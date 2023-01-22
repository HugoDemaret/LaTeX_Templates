int min_couleur_possible(int gphe, int* etiquetage, int taille, int sommet) {
  bool col[taille];
  for (int i = 0; i < taille; i++) {
    col[i] = false;
  }
  for (int i = 0; i < taille; i++) {
    if (gphe[sommet][i] == 1 && etiquetage[i] != -1) {
      col[etiquetage[i]] = true;
    }
  }
  int count = 0;
  while (col[count]) {
    count++;
  }
  return count;
}