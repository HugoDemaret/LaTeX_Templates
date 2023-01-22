void tri_degre(graphe gphe, int taille) {
  std::stack<std::pair<int, int>> stack;
  stack.push(std::make_pair(0, taille - 1));
  while (!stack.empty()) {
    std::pair<int, int> p = stack.top();
    stack.pop();
    int low = p.first;
    int high = p.second;
    int pivot = gphe[high][1];
    int i = low - 1;
    for (int j = low; j < high; j++) {
      if (inputt[j][1] > pivot) {
        i++;
        std::swap(gphe[i], gphe[j]);
      }
    }
    std::swap(gphe[i + 1], gphe[high]);
    int pi = i + 1;
    if (pi - 1 > low) {
      stack.push(std::make_pair(low, pi - 1));
    }
    if (pi + 1 < high) {
      stack.push(std::make_pair(pi + 1, high));
    }
  }
}
int* welsh_powell(graphe gphe, int taille) {
  int deg[taille];
  degres_graphe(gphe, taille, deg);
  tri_selection2(deg, taille);
  int num[taille];
  for (int i = 0; i < taille; i++) {
    num[i] = deg[i][0];
  }
  return glouton(gr, num, taille);
}