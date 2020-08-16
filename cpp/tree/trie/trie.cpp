#include <bits/stdc++.h>

using namespace std;
const int ALPHABET_SIZE = 26;

class trieNode
{
public:
   bool isEndOfNode;
   trieNode *children[ALPHABET_SIZE];
};

trieNode *getNode()
{
   trieNode *pNode = new trieNode();
   pNode->isEndOfNode = NULL;
   for (int i = 0; i < ALPHABET_SIZE; i++)
   {
      pNode->children[i] = NULL;
   }
   return pNode;
}

void insert(trieNode *root, string key)
{
   trieNode *pCrawl;
   pCrawl = root;
   for (int i = 0; i < key.length(); i++)
   {
      int index = key[i] - 'a';
      if (pCrawl->children[index] == NULL)
      {
         pCrawl->children[index] = getNode();
      }
      pCrawl = pCrawl->children[index];
   }
   pCrawl->isEndOfNode = true;
}

bool search(trieNode *root, string key)
{
   trieNode *pCrawl = root;
   for (int i = 0; i < key.length(); i++)
   {
      int index = key[i] - 'a';
      if (pCrawl->children[index] == NULL)
      {
         return false;
      }
      pCrawl = pCrawl->children[index];
   }
   return (pCrawl != NULL && pCrawl->isEndOfNode);
}

int main()
{
   string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                    "bye", "their"};
   int n = sizeof(keys) / sizeof(keys[0]);

   trieNode *root = getNode();

   for (int i = 0; i < n; i++)
   {
      insert(root, keys[i]);
   }
   search(root, "rish") ? cout << "Yes\n" : cout << "Not Found\n";
   return 0;
}