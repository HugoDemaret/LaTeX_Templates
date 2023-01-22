int* glouton(graph gphe, int* numerotation, int taille) {
  int* couleurs = new int[taille];
  for (int i = 0; i < taille; i++) {
    couleurs[i] = -1;
  }
  for (int i = 0; i < taille; i++) {
    int k = numerotation[i];
    couleurs[k] = min_couleur_possible(gphe, couleurs, taille, k);
  }
  return couleurs;
}