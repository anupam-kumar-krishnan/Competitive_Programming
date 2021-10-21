package main

import "fmt"

func exist(board {][]byte, word string) bool {
	visited := make([][]bool, len(board))
	for i := range visited {
			visited[i] = make([]bool, len(board[i]))
	}
	for i := range board {
			for j := range board[i] {
					if existRec(i, j, board, visited, word) {
							return true
					}
			}
	}
	return false
}

func existRec(i, j int, board [][]byte, visited [][]bool, word string) bool {
	if len(word) == 0 {
			return true
	}
	if i < 0 || i >= len(board) || j < 0 || j >= len(board[i]) {
			return false
	}
	if visited[i][j] || board[i][j] != word[0] {
			return false
	}
	
	visited[i][j] = true
	defer func() {visited[i][j] = false}()
	
	return existRec(i+1, j, board, visited, word[1:]) ||
			existRec(i-1, j, board, visited, word[1:]) ||
			existRec(i, j+1, board, visited, word[1:]) ||
			existRec(i, j-1, board, visited, word[1:])
}

func main() {
	fmt.Println(exist([][]byte{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}}, "ABCCED"))
}
