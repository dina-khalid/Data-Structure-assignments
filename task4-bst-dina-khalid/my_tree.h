#include <iostream>

#ifndef MY_TREE_H
#define MY_TREE_H
#include <cassert>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

template <class T>

class MyTree{
    // tree node struct
    struct treeNode
    {
        T     item;
        treeNode  *left;
        treeNode  *right;
    };

private:
    treeNode* root= nullptr;
    int tSize=0;

    //private post order recursion that take parameter, so we can do recursion
    void post_rec(treeNode* p){

        if(p != NULL){
            post_rec(p -> left);
            post_rec(p->right);
                cout<<p->item<<" ";

    }}
    //private in order recursion that take parameter
    void in_rec(treeNode* p){
        if(p != NULL){
            in_rec(p->left);
            cout<< p->item<<" ";
            in_rec(p->right);
        }}


    //private preorder recursion that take parameter
    void pre_rec(treeNode* p){
        if(p != NULL){
            cout<< p->item<<" ";
            pre_rec(p -> left);
            pre_rec(p->right);
        }

    }
    //private recursive function that insert elements of vector in tree
    treeNode* insertForVec(vector<T> v, int start,int end){
        if(start>end)
            return NULL;

        int med= (start+end)/2;
        treeNode* p = newNode(v[med]);
        p -> left = insertForVec(v,start,med-1);
        p -> right = insertForVec(v,med+1,end);
        return p;
    }
    // make new node function
    treeNode* newNode(T val){
        treeNode* node=new treeNode;
        node-> item=val;
        node->right=node->left=NULL;
        return node;
    }

public:
    MyTree(){
        // initialize the tree
        root=NULL;
    }

    MyTree(vector<T> elements){
        root=NULL;
        sort(elements.begin(), elements.end());
        root= insertForVec(elements,0,elements.size()-1);
        tSize=elements.size();
    }


    bool search(T key){
        if(root == NULL)
            return false;
        treeNode* curr= root;
        //loop while we didn't reach a leaf
        while (curr != NULL){
            //if key = to current node data return true
            if (key == curr -> item)
                return true;
            //if key> current data go right
            if (key > curr -> item)
                curr = curr -> right;
            //else go left
            else
                curr = curr -> left;
        }
        //reach a leaf without return, so the element isn't in the tree
        return false;
    }

    void insert(T key){
        tSize++;
        treeNode *current;  //pointer to traverse the tree
        treeNode *trailCurrent; //pointer parent of current
        treeNode *newNode;  //pointer of new node

        newNode = new treeNode;
        assert(newNode != NULL);
        newNode->item = key;
        newNode->left = NULL;
        newNode->right = NULL;
        // if there is no root, insert in root
        if(root == NULL){
            root = newNode;
            }
        else
        {   //point at root
            current = root;
            //loop till reach a leaf
            while(current != NULL)
            {
                trailCurrent = current;

                if(current->item == key)
                {
//                    cout<<"Duplicate, This key already in the tree"<<endl;
                    return;
                }
                else
                if(current->item > key)
                    current = current->left;
                else
                    current = current->right;
            }//end while we reach the suitable leaf
            if(trailCurrent->item > key){
                trailCurrent->left = newNode;

            }
            else{
                trailCurrent->right = newNode;
           }

        }
    }



    void inorder_rec(){in_rec(root);
        cout<<endl;}

    void preorder_rec(){pre_rec(root);
        cout<<endl;}

    void postorder_rec(){post_rec(root);
        cout<<endl;}

    void inorder_it(){
       /*
        here we go to the max left of each node adding them all in a steak
        when we reach a leaf we print the top of the stack and go to its right and so on.
         */
        if(root == nullptr)
            return;//return if there is no tree
        stack<treeNode*> s;
        treeNode* curr=root;//current node
        bool done = 0;//flag tell us if we done
        while(!done) {
            if (curr != NULL) {
                //push each element at left in the stack
                s.push(curr);
                curr = curr -> left;
            }// we reach a leaf
            else{

                if (!s.empty()){
                    //print top element in the stack
                    curr=s.top();
                    s.pop();


                    cout<<curr -> item<<" ";


                    //go its right
                    curr = curr -> right;
                }
                else{
                    // when current is null and stack is empty
                    done=1;
                }
            }
        }
        cout<<endl;
    }

    void preorder_it(){
        /*
       here we loop over each node starting from root,
         print it add its right to the stack if exists, add its left to stack if exists

         return void
        */
        if(root == nullptr)
            return;
        stack<treeNode*> s;
        s.push(root);
        while(!s.empty()) {
            treeNode* curr=s.top();
            cout<< curr -> item<< " ";
            s.pop();
            if (curr -> right)
                s.push(curr->right);
            if (curr -> left)
                s.push(curr -> left);}
        cout<<endl;
    }

    void postorder_it(){
        if(root == nullptr){
            return;}
        //initialize 2 stacks
        stack<treeNode*> s1;
        stack<treeNode*> s2;
        //push root at first
        s1.push(root);
        treeNode* curr;
        while (!s1.empty()){
            curr=s1.top();
            s1.pop();
            s2.push(curr);
            //push its children if there was
            if(curr->left)
                s1.push(curr -> left);
            if (curr->right)
                s1.push(curr->right);
        }
        while (!s2.empty())
        {
            curr=s2.top();
            s2.pop();
            cout<<curr -> item<<" ";
        }
        cout<<endl;
    }



    void breadth_traversal(){
        if(root == NULL)
            return;
        queue <struct treeNode*>Q;
        //add root to the queue
        Q.push(root);
        while(!Q.empty()){
            // point at front of the queue
            struct treeNode* curr=Q.front();
            //pribt its data
            cout<< curr -> item<<" ";
            //add its children
            if(curr->left != NULL)
                Q.push(curr -> left);
            if (curr-> right != NULL)
                Q.push(curr -> right);
            Q.pop();
        }
        cout<<endl;}

    int size(){return tSize;}

    void remove(int element)
    /*
     Function get the place of the deleted node and uses another function to delete it*/
    {
        treeNode *curr;  //pointer to traverse the tree
        treeNode *trailCurr; //pointer behind current

        if(root == NULL)
        {
//            cout<<"No tree to delete from."<<endl;
            return;
        }
        if(root->item == element)
        {
            deleteNode(root);
            return;
        }

        trailCurr = root;

        if(root->item > element)
            curr = root->left;
        else
            curr = root->right;

        //search for the item to be deleted.
        while(curr != NULL)
        {
            if(curr->item == element)
                break;
            else
            {
                trailCurr = curr;
                if(curr->item > element)
                    curr = curr->left;
                else
                    curr = curr->right;
            }
        }// once the while is done, current points to either NULL or to the node to be deleted

        if(curr == NULL)
        //    cout<<"The delete item is not in the tree."<<endl;
            return;
        else if(trailCurr->item > element)
            deleteNode(trailCurr->left);
        else
            deleteNode(trailCurr->right);
    }

    void deleteNode(treeNode* &p)
    {
        treeNode *curr;    //pointer to current node

        treeNode *trailCurr;   //pointer to its parent
        treeNode *temp;        //temp pointer to delete a node
        // if the node is leaf delete it
        if(p->left == NULL && p->right == NULL)
        {
            delete p;
            p = NULL;
        }
        //if it only has a left branch
        //save the node, make its parent points to its child
        else if(p->left == NULL)
        {
            temp = p;
            p = p->right;
            delete temp;
        }
            //if it only has a right branch
            //save the node, make its parent points to its child
        else if(p->right == NULL)
        {
            temp = p;
            p = p->left;
            delete temp;
        }
        //else the node has 2 children
        // replace the node with the max value at the left
        else
        {
            curr = p->left;
            trailCurr = NULL;

            while(curr->right != NULL)
            {
                trailCurr = curr;
                curr = curr->right;
            }//end while

            p->item = curr->item;

            if(trailCurr == NULL) //current didn't change;

                p->left = curr->left;
            else
                trailCurr->right = curr->left;

            delete curr;
        }//end else
        tSize--;
    }//end deleteFromTree

};

#endif