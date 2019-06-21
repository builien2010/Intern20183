# AutoComplete : xong 

class TrieNode():
    def __init__(self):
        self.children = {}
        self.last = False

class Trie():
    def __init__(self):
        self.root = TrieNode()
        self.word_list = [] # danh sách các từ gợi ý

    def insert(self, key):
        node = self.root
        
        for a in list(key):
            if not node.children.get(a):
                node.children[a] = TrieNode()
            
            node = node.children[a]
        
        node.last = True 
    
    def formTrie(self, keys):
        for key in keys:
            self.insert(key)
    
    def search(self, key):
        
        node = self.root

        found = True

        for a in list(key):
            if not node.children.get(a):
                found =  False
                break 
            node = node.children[a]

        return found and node and node.last
    
    def recommend(self, node, prefix):
        if node.last:
            self.word_list.append(prefix)
        
        for a, n in node.children.items():
            self.recommend(n, prefix + a)
    
    def printAuto(self, query):

        node = self.root 
        found = True 
        temp_word = ''

        for a in list(query):
            if not node.children.get(a):
                found = False 
                break 

            node = node.children[a]


        if found ==  False:
            return 0
        elif node.last and not node.children:
            return -1 
        
        self.recommend(node, query)

        for s in self.word_list:
            print(s)
        return 1


with open('words_alpha.txt') as f:
    keys = f.readlines()  

t = Trie() 
 
t.formTrie(keys) 
 
comp = t.printAuto("aaaah") 
  
if comp == -1: 
    print("Tiền tố có trong Trie và không có gợi ý nào khác \n") 
elif comp == 0: 
    print("Không có gợi ý nào với tiền tố này\n") 





