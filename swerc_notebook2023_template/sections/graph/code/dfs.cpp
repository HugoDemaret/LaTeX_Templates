void DFS(graph G, int x){
    visited[x] = 1;
    for (auto const& [key,value] : graph){
        if (visited[value] != 1){
            DFS(G,value);
        }
    }
}