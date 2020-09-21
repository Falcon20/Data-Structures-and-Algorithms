// Problem link - https://practice.geeksforgeeks.org/problems/trie-insert-and-search/0
// Video tutorial - https://www.youtube.com/watch?v=0k79LqIaHyQ&t=494s
#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct TrieNode
{
  struct TrieNode *children[26] ;
  bool isEndOfWord;
};

struct TrieNode *getNode()
{
    struct TrieNode *pNode = new TrieNode;
    pNode->isEndOfWord = false;
    for(int i = 0;i<26;i++)
    pNode->children[i] = NULL;
    return pNode;
}

void insert(TrieNode *root, string str)
{
  TrieNode *pCrawl = root;
  for(int i =0;str[i];i++)
  {
      int idx = str[i] - 97;
      if(pCrawl->children[idx] == NULL)
      {
          pCrawl->children[idx] = getNode();
      }
      pCrawl = pCrawl->children[idx];
  }
  pCrawl->isEndOfWord = true;
  
}

bool search(TrieNode *root, string str)
{
  TrieNode *pCrawl = root;
  for(int i=0;str[i];i++)
  {
      int idx = str[i] - 97;
      if(pCrawl->children[idx] == NULL)
      {
          return false;
      }
      pCrawl = pCrawl->children[idx];
  }
 return  (pCrawl && pCrawl->isEndOfWord);
    
}

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    vector<string>v(n);
	    for(int i =0;i<n;i++)
	    cin>>v[i];
	    string str;
	    cin>>str;
	    TrieNode *root = getNode();
	    for(int i = 0;i<n;i++)
	    insert(root, v[i]);
	    cout<<search(root, str)<<"\n";
	}
	return 0;
}
