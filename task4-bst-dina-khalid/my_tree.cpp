#include <iostream>
# include "my_tree.h"
using namespace std;

int main(int argc, char** argv){
    int treeSize;
    int numOp;
    int element;
    int x;
    vector<int> v;
    cin>>treeSize>>numOp;
    for(int i =0;i<treeSize;i++){
        cin>>element;
        v.push_back(element);}

    MyTree<int> tree= MyTree<int>(v);
    for (int i=0;i<numOp;i++){
        cin>>(x);
        switch (x) {
            case 1:
                cin>>element;
                tree.insert(element);
                break;
            case 2:
                cin>>element;
                cout<< tree.search(element)<<" "<<endl;

                break;
            case 3:
                cin>>element;
                if(element==1)
                    tree.inorder_rec();
                else if(element==2)
                    tree.inorder_it();

                break;
            case 4:
                cin>>element;
                if(element==1)
                    tree.preorder_rec();
                else if(element==2)
                    tree.preorder_it();

                break;
            case 5:
                cin>>element;
                if(element==1)
                    tree.postorder_rec();
                else if(element==2 || element ==3)
                    tree.postorder_it();

                break;
            case 6:
                tree.breadth_traversal();

                break;
            case 7:
                cout<<tree.size()<<" ";
                cout<<endl;
                break;
        }}
    return 0;
}