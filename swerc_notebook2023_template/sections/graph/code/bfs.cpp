void BFS(graph G, int x){
    qe.push_back(x);
    visited[x] = 1;
    while(!qe.empty()){
        int v = qe.front();
        qe.pop_front();
        for(auto value : G.at(v)){
            if (visited[value] != 1){
                qe.push_back(value);
                visited[value] = 1;
            }
        }
    }
}