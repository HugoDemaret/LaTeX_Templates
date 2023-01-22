bool est_col(graph G, etiquetage L){
  if (G.size() != L.size())
    return false;
  for(int i = 0; i<L.size(); ++i){
    for (int j = 0; j<L.size(); ++j){
      if((L.at(i) == L.at(j)) && G[i][j] == 1)
        return false;
    }
  }
  return true;
}