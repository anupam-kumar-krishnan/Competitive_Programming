class Solution {
    public List<String> findWords(char[][] board, String[] words) {
        TrieNode root = new TrieNode();
        for (String s : words) root.add(s, 0);
        Set<String> res = new HashSet<>();
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                find(board, i, j, root.next[board[i][j] - 'a'], res);
            }
        }
        return new ArrayList<>(res);
    }
    
    private void find(char[][] board, int i, int j, TrieNode root, Set<String> res) {
        if (root == null) return;
        if (root.word != null) res.add(root.word);
        char c = board[i][j];
        board[i][j] = 'z' + 1;
        if (i > 0) find(board, i - 1, j, root.next[board[i - 1][j] - 'a'], res);
        if (j > 0) find(board, i, j - 1, root.next[board[i][j - 1] - 'a'], res);
        if (i < board.length - 1) find(board, i + 1, j, root.next[board[i + 1][j] - 'a'], res);
        if (j < board[0].length - 1) find(board, i, j + 1, root.next[board[i][j + 1] - 'a'], res);        
        board[i][j] = c;
    }
    
    class TrieNode {
        TrieNode[] next = new TrieNode[27];
        String word;
        public void add(String s, int index) {
            char c = s.charAt(index);
            if (next[c - 'a'] == null) next[c - 'a'] = new TrieNode();
            if (index + 1 < s.length()) next[c - 'a'].add(s, index + 1);
            else next[c - 'a'].word = s;
        }
    }
}
