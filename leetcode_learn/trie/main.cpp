//  前缀树trie的实现
//  属于多叉树的一种特殊情况
#include<string>

class Trie {
public:
    struct TreeNode
    {
        bool bIsEnd;
        TreeNode* nextCar[26];

        TreeNode()
        {
            bIsEnd = false;
            for (int i = 0; i < 26; ++i)
                nextCar[i] = nullptr;
        }
        TreeNode(bool b) :bIsEnd(b)
        {
            for (int i = 0; i < 26; ++i)
                nextCar[i] = nullptr;
        }
        ~TreeNode()
        {
            for (int i = 0; i < 26; ++i)
            {
                if (nextCar[i])
                    delete nextCar[i];
            }
        }
    };
    TreeNode* HeadNullNode;
    /** Initialize your data structure here. */
    Trie() {
        HeadNullNode = new TreeNode();
    }

    virtual ~Trie()
    {
        delete HeadNullNode;
    }

    /** Inserts a word into the trie. */
    void insert(std::string word) {
        int length = word.size();
        TreeNode* pNode = HeadNullNode;
        for (int i = 0; i < length; ++i)
        {
            int pos = word[i] - 'a';
            if (pNode->nextCar[pos])
            {
                pNode = pNode->nextCar[pos];
                continue;
            }
            pNode->nextCar[pos] = new TreeNode();
            pNode = pNode->nextCar[pos];
        }
        pNode->bIsEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(std::string word) {
        int length = word.size();
        TreeNode* pNode = HeadNullNode;
        for (int i = 0; i < length; ++i)
        {
            int pos = word[i] - 'a';
            if (pNode->nextCar[pos])
            {
                pNode = pNode->nextCar[pos];
                continue;
            }
            return false;
        }
        if (pNode->bIsEnd)
            return true;
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix) {
        int length = prefix.size();
        TreeNode* pNode = HeadNullNode;
        for (int i = 0; i < length; ++i)
        {
            int pos = prefix[i] - 'a';
            if (pNode->nextCar[pos])
            {
                pNode = pNode->nextCar[pos];
                continue;
            }
            return false;
        }
        return true;
    }
};