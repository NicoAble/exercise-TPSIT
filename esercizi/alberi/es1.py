import random 

class Node():
    def __init__(self, key):
        self.key=key
        self.left=None
        self.right=None

    def insert(self, key):
        if self.key!=None:
            if key>self.key:
                if self.right is None:
                    self.right=Node(key)
                else: self.right.insert(key)
            elif key<self.key:
                if self.left is None:
                    self.left=Node(key)
                else: self.left.insert(key)
            
    def printTree(self, level=0):
        if self.right is not None:
            self.right.printTree(level+1)
        print('\t' * level + f"livello {level}: {self.key}")
        if self.left is not None:
            self.left.printTree(level+1)
    
    def ricercaDicotomica(self, key):
        if key>self.key:
            if self.right==None:
                return f"Nodo {key} non trovato"
            return self.right.ricercaDicotomica(key)
        elif key<self.key:
            if self.left is None:
                return f"Nodo {key} non trovato"
            return self.left.ricercaDicotomica(key)
        else:
            return f"nodo {key} trovato"

    def calcoloAltezza(self):
        if self.right is None: AltezzaDestra=-1 
        else: AltezzaDestra=self.right.calcoloAltezza()
        if self.left is None: AltezzaSinistra=-1 
        else: AltezzaSinistra=self.left.calcoloAltezza()
        return 1 + max(AltezzaDestra, AltezzaSinistra)
        
      
def main():
    lista_key=list(range(0, 40, 5))
    random.shuffle(lista_key) #mescola la lista
    print(lista_key)
    root=Node(lista_key[0])
    for key in lista_key[1:]:
        root.insert(key)
    root.printTree()
    print(root.ricercaDicotomica(15))
    print(root.calcoloAltezza())

if __name__=="__main__":
    main()