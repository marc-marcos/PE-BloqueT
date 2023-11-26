#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <chrono>

struct s //node declaration
{
   int k;  
   s* lch;
   s* rch;
};

class SplayTree
{
public:
   s* RR_Rotate(s* k2)
   {
      s* k1 = k2->lch;
      k2->lch = k1->rch;
      k1->rch = k2;
      return k1;
   }

   s* LL_Rotate(s* k2)
   {
      s* k1 = k2->rch;
      k2->rch = k1->lch;
      k1->lch = k2;
      return k1;
   }

   s* Splay(int key, s* root)
   {
      if (!root)
         return nullptr;
      s header;
      header.lch = header.rch = nullptr;
      s* LeftTreeMax = &header;
      s* RightTreeMin = &header;
      while (1)
      {
         if (key < root->k)
         {
            if (!root->lch)
               break;
            if (key < root->lch->k)
            {
               root = RR_Rotate(root);
               if (!root->lch)
                  break;
            }
            RightTreeMin->lch = root;
            RightTreeMin = RightTreeMin->lch;
            root = root->lch;
            RightTreeMin->lch = nullptr;
         }
         else if (key > root->k)
         {
            if (!root->rch)
               break;
            if (key > root->rch->k)
            {
               root = LL_Rotate(root);
               if (!root->rch)
                  break;
            }
            LeftTreeMax->rch = root;
            LeftTreeMax = LeftTreeMax->rch;
            root = root->rch;
            LeftTreeMax->rch = nullptr;
         }
         else
            break;
      }
      LeftTreeMax->rch = root->lch;
      RightTreeMin->lch = root->rch;
      root->lch = header.rch;
      root->rch = header.lch;
      return root;
   }

   s* New_Node(int key)
   {
      s* p_node = new s;
      if (!p_node)
      {
         std::cerr << "Out of memory!\n";
         exit(1);
      }
      p_node->k = key;
      p_node->lch = p_node->rch = nullptr;
      return p_node;
   }

   s* Insert(int key, s* root)
   {
      static s* p_node = nullptr;
      if (!p_node)
         p_node = New_Node(key);
      else
         p_node->k = key;
      if (!root)
      {
         root = p_node;
         p_node = nullptr;
         return root;
      }
      root = Splay(key, root);
      if (key < root->k)
      {
         p_node->lch = root->lch;
         p_node->rch = root;
         root->lch = nullptr;
         root = p_node;
      }
      else if (key > root->k)
      {
         p_node->rch = root->rch;
         p_node->lch = root;
         root->rch = nullptr;
         root = p_node;
      }
      else
         return root;
      p_node = nullptr;
      return root;
   }

   s* Delete(int key, s* root)
   {
      s* temp;
      if (!root)
         return nullptr;
      root = Splay(key, root);
      if (key != root->k)
         return root;
      else
      {
         if (!root->lch)
         {
            temp = root;
            root = root->rch;
         }
         else
         {
            temp = root;
            root = Splay(key, root->lch);
            root->rch = temp->rch;
         }
         delete temp;
         return root;
      }
   }

   s* Search(int key, s* root)
   {
      return Splay(key, root);
   }

   void InOrder(s* root)
   {
      if (root)
      {
         InOrder(root->lch);
         std::cout << "key: " << root->k;
         if(root->lch)
            std::cout << " | left child: " << root->lch->k;
         if(root->rch)
            std::cout << " | right child: " << root->rch->k;
         std::cout << "\n";
         InOrder(root->rch);
      }
   }
};

int main()
{
    SplayTree st;
    s *root;
    root = nullptr;
    st.InOrder(root);
    int i, c;
    for (int j = 0; j < 1000000; j++)
    {
        int r = rand();
        root = st.Insert(r, root);
    }
    while (1)
    {
        std::cout << "1. Insert " << std::endl;
        std::cout << "2. Delete" << std::endl;
        std::cout << "3. Search" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> c;

        if (c == 1)
        {
            auto start_time = std::chrono::high_resolution_clock::now();
			for (int l = 0; l < 1000000; l++) {
           		 i = rand();
            	root = st.Insert(i, root);
			}
            auto end_time = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
            std::cout << "Time elapsed: " << duration.count() << " milliseconds\n";
        }
        else if (c == 2)
        {
            std::cin >> i;
            root = st.Delete(i, root);
        }
        else if (c == 3)
        {
            std::cin >> i;
            root = st.Search(i, root);
        }
        else if (c == 4)
        {
            break;
        }
        else
        {
            std::cout << "\nInvalid type! \n";
        }
    }
    std::cout << "\n";
    return 0;
}