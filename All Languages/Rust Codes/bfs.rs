use std::collections::VecDeque;
type Graph = Vec<Vec<usize>>;

// BFS
fn bfs(graph: &Graph, start: usize) -> Vec<usize> {
    let mut visited = vec![false; graph.len()];
    let mut queue = VecDeque::new();
    let mut order = Vec::new();

    visited[start] = true;
    queue.push_back(start);

    while let Some(node) = queue.pop_front() {
        order.push(node);

        for &next in &graph[node] {
            if !visited[next] {
                visited[next] = true;
                queue.push_back(next);
            }
        }
    }

    return order;

}

fn main() {
    let graph = vec![
        vec![1, 2],
        vec![0, 3, 4],
        vec![0, 5],
        vec![1],
        vec![1, 5],
        vec![2, 4],
    ];

    let order = bfs(&graph, 0);
    println!("{:?}", order); // [0, 1, 2, 3, 4, 5]
}
