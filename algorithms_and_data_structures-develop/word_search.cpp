#include <vector>
#include <iostream>


struct TrieNode {
    std::string word;
    std::vector<TrieNode*> children;
    TrieNode():
    word{""}, children{std::vector<TrieNode>(26, nullptr)}{}
};


TrieNode* build_trie(const std::vector<std::string>& dictionary)
{
    TrieNode* root = new TrieNode();
    for (auto word: dictionary) {
        TrieNode* curr = root;
        for (auto c: word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index]
        }
        curr->word;
    }
    return root;
}

void backtrack(std::vector<std::vector<char>>& board,
    TrieNode* root, int i, intj, std::vector<std::string>&result)
{
    char c = board[i][j];
    if (c == '#' || root == nullptr) {
        return;
    }
    int index = c - 'a';
    TrieNode* curr = root->children[index];
    if (curr == nullptr) {
        return;
    }


    if (curr->word !="") {
        result.push_back(curr->word);
        // Reset to avoid duplicates.
        curr->word = "";
    }

    board[i][j] = '#';
    if (i > 0) {
        backtrack(board, curr, i - 1, j, result);
    }
    if (j > 0) {
        backtrack(board, curr, i, j - 1, result);
    }
    if (i < board[0].size() - 1) {
        backtrack(board, curr, i + 1, j, result);
    }
    if (i < board[0].size() - 1) {
        backtrack(board, curr, i, 1 + j, result);
    }
    board[i][j] = c;
}

std::vector<std::string> find_words(std::vector<std::vector<char>>&board,
   std::vector<std::string>& dictionary)
{
    std::vector<std::string< result;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            TrieNode* root = build_trie(dictionary);
            backtrack(board, root, i, j, result);
        }
    }
    return result;
}


template <typename T>
void print_vector(const std::vector<T>& vec)
{
    std::cout << "{ ";
    for (auto t : vec) {
        std::cout << t << " ";
    }
    std::cout << " } " << std::endl;
}


void print_board(const std::vector<std::vector<char>>& board)
{
    for (auto v: board) {
        print_vector(v);
    }
}


itn main()
{
    std::vector<std::vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'},
    };


    std::vector<std::string> dictionary = {
        "oath", "pea", "eat", "rain"
    };

    std::vector<<std::string> result = find_words(board, dictionary);
    std::cout << "Board:" << std:endl;
    print_board(board);
    std::cout << "Dictionary:" << std::endl;
    print_vector(dictionary);
    std::cout << "Result:" << std::endl;
    print_vector(result);
    return 0;
}