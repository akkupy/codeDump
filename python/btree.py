class BTreeNode:
    def __init__(self, leaf=True):
        self.leaf = leaf
        self.keys = []
        self.children = []

class BTree:
    def __init__(self, t):
        self.root = BTreeNode()
        self.t = t

    def insert(self, key):
        root = self.root
        if len(root.keys) == (2 * self.t) - 1:
            new_node = BTreeNode(leaf=False)
            new_node.children.append(root)
            self._split_child(new_node, 0)
            self._insert_non_full(new_node, key)
            self.root = new_node
        else:
            self._insert_non_full(root, key)

    def _insert_non_full(self, x, key):
        i = len(x.keys) - 1
        if x.leaf:
            x.keys.append(None)
            while i >= 0 and key < x.keys[i]:
                x.keys[i + 1] = x.keys[i]
                i -= 1
            x.keys[i + 1] = key
        else:
            while i >= 0 and key < x.keys[i]:
                i -= 1
            i += 1
            if len(x.children[i].keys) == (2 * self.t) - 1:
                self._split_child(x, i)
                if key > x.keys[i]:
                    i += 1
            self._insert_non_full(x.children[i], key)

    def _split_child(self, x, i):
        t = self.t
        y = x.children[i]
        z = BTreeNode(leaf=y.leaf)

        x.children.insert(i + 1, z)
        x.keys.insert(i, y.keys[t - 1])

        z.keys = y.keys[t:]
        y.keys = y.keys[:t - 1]

        if not y.leaf:
            z.children = y.children[t:]
            y.children = y.children[:t]

    def search(self, key, node=None):
        if node is None:
            node = self.root
        i = 0
        while i < len(node.keys) and key > node.keys[i]:
            i += 1
        if i < len(node.keys) and key == node.keys[i]:
            return node
        elif node.leaf:
            return None
        else:
            return self.search(key, node.children[i])

    def display(self, node=None, level=0):
        if node is None:
            node = self.root
        print("Level", level, ":", " ".join(str(key) for key in node.keys))
        level += 1
        if not node.leaf:
            for child in node.children:
                self.display(child, level)

# Demo
if __name__ == "__main__":
    btree = BTree(t=3)

    keys = [3, 7, 1, 8, 2, 4, 5, 6, 9, 10]
    for key in keys:
        btree.insert(key)

    print("B-Tree Structure:")
    btree.display()

    search_key = 5
    result = btree.search(search_key)
    if result:
        print(f"Key {search_key} found!")
    else:
        print(f"Key {search_key} not found.")
