#ifndef TREE_H_
#define TREE_H_

#include <list>

template <typename TYPE>
class Tree
{
public:
    struct Node
    {
        typedef std::list<Node*> Children;
        typedef typename Children::iterator Iterator;
        typedef typename Children::const_iterator CIterator;

        TYPE value;
        Children children;

        Node(const TYPE& value) : value(value) {}
    };

    typedef typename Node::Children Children;
    typedef typename Node::Iterator Iterator;
    typedef typename Node::CIterator CIterator;

    explicit Tree(const TYPE& value) { m_root = new Node(value); }
    virtual ~Tree()
    {
        Clear();
        delete m_root;
    }

    Node* GetRoot() { return m_root; }
    const Node* GetRoot() const { return m_root; }

    static Node* Append(Node* node, const TYPE& value)
    {
        Node* child = new Node(value);
        node->children.push_back(child);
        return child;
    }

    void Clear() { Clear(m_root); }

private:
    void Clear(Node* node)
    {
        Children& children = node->children;
        for (Iterator it = children.begin(); it != children.end(); ++it) {
            Clear(*it);
        }
        children.clear();

        if (node != m_root) { delete node; }
    }

private:
    Node* m_root;
};

#endif // !TREE_H_
