
namespace StringProcessing{
    struct Suffix_Tree{
        bool parent;
        Suffix_Tree* verticies[26];
        Suffix_Tree(bool _parent = true){
            parent = _parent;
            std::fill(verticies, verticies+26, nullptr);
        }
        void add_word(std::string &word, int pos = 0){
            if(pos >= word.length())
                return;
            if(verticies[word[pos]-'a'] == nullptr)
                verticies[word[pos]-'a'] = new Suffix_Tree(false);
            verticies[word[pos]-'a']->add_word(word, pos+1);
        }
        void log(int level = 0){
            for(int i = 0; i < 26; i++){
                if(verticies[i] != nullptr){
                    for(int j = 0; j < level; j++)
                        std::cout << "    ";
                    std::cout << (char)('a'+i) << std::endl;
                    verticies[i]->log(level+1);
                }
            }
        }
    };
    std::vector<int> kmp_preproces(std::string &str){
        std::vector<int> reset_table (str.length());
        fill(reset_table.begin(), reset_table.end(), -1);
        int j = -1;
        for(int i = 0; i < str.length(); i=i){
            for(j = j; j >= 0 && str[i] != str[j]; j = reset_table[j])
                continue;
            j++;
            i++;
            reset_table[i] = j;
        }
        return reset_table;
    }
    int kmp_find_first(std::string &to_read, std::string &to_find){
        std::vector<int> reset_table = kmp_preproces(to_find);
        for(int i = 0; i < to_read.size(); i++){
            int len = 0;
            int mem = i;
            for(int j = 0; j < to_find.size(); j++){
                if(to_read[i] == to_find[j]){
                    len++;
                    i++;
                }else{
                    i = mem + 1 + reset_table[j];
                    break;
                }
            }
            if(len == to_find.size())
                return mem;
        }
        return -1;
    }
    std::vector<int> kmp_find_multiple(std::string &to_read, std::string &to_find){
        std::vector<int> reset_table = kmp_preproces(to_find);
        std::vector<int> found;
        for(int i = 0; i < to_read.size(); i++){
            int len = 0;
            int mem = i;
            for(int j = 0; j < to_find.size(); j++){
                if(to_read[i] == to_find[j]){
                    len++;
                    i++;
                }else{
                    i = mem + 1 + reset_table[j];
                    break;
                }
            }
            if(len == to_find.size()){
                found.push_back(mem);
                i = mem + to_find.length() - reset_table[to_find.length()-1]-2;
            }

        }
        return found;
    }
}
