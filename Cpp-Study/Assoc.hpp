#ifndef ASSOC_H_
#define ASSOC_H_

#include <stdexcept>

template <typename KEY, typename VALUE>
class Assoc
{
public:
    struct Node
    {
        KEY key;
        VALUE value;
        Node* left;
        Node* right;

        Node(const KEY& key) : key(key), value(), left(NULL), right(NULL) {}
    };

    typedef Node* PNode;

public:
    Assoc() : m_root(NULL) {}
    virtual ~Assoc() { Clear(); }

private:
    PNode& FindNode(const KEY& key) { return const_cast<PNode&>(FindNode_(key)); }
    const PNode& FindNode(const KEY& key) const { return FindNode_(key); }

    const PNode& FindNode_(const KEY& key) const { return FindNode_(m_root, key); }
    const PNode& FindNode_(const PNode& node, const KEY& key) const
    {
        if (node == NULL) {
            return node;
        }

        if (key < node->key) {
            return FindNode_(node->left, key);
        } else if (node->key < key) {
            return FindNode_(node->right, key);
        } else {
            return node;
        }
    }

public:
    VALUE& operator[](const KEY& key)
    {
        PNode& node = FindNode(key);
        if (node == NULL) {
            node = new Node(key);
        }
        return node->value;
    }
    
    const VALUE& operator[](const KEY& key) const
    {
        const PNode& node = FindNode(key);
        if (node == NULL) {
            throw std::out_of_range("見つかりませんでした");
        }
        return node->value;
    }

    void Clear()
    {
        Clear(m_root);
        m_root = NULL;
    }

    void Clear(Node* node)
    {
        if (node == NULL) { return; }
        Clear(node->left);
        Clear(node->right);

        delete node;
    }

private:
    Node* m_root;

};

#endif // ASSOC_H_
