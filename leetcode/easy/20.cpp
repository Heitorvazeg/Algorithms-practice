/*Implementação de pilha para solução*/

class Solution {
public:
    bool isValid(string s) {        
        std::map<char, char> map = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        std::stack<char> pilha;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                pilha.push(s[i]);

            } else {
                if (pilha.empty()) {
                    return false;
                } 
                char topo = pilha.top();
                pilha.pop();

                if (topo != map[s[i]]) {
                    return false;
                }
            }
        }
        return pilha.empty();
    };
};