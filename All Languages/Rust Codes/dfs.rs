

// DFS
fn dfs(graph: &Vec<Vec<i32>>, start: i32, visited: &mut Vec<bool>) {
    visited[start as usize] = true;
    println!("{}", start);
    for i in 0..graph[start as usize].len() {
        if graph[start as usize][i] == 1 && !visited[i] {
            dfs(graph, i as i32, visited);
        }
    }
}


fn main() {
    let graph = vec![
        vec![0, 1, 1, 0, 0, 0],
        vec![1, 0, 0, 1, 1, 0],
        vec![1, 0, 0, 0, 1, 0],
        vec![0, 1, 0, 0, 1, 1],
        vec![0, 1, 1, 1, 0, 1],
        vec![0, 0, 0, 1, 1, 0],
    ];
    let mut visited = vec![false; graph.len()];
    dfs(&graph, 0, &mut visited);
}

