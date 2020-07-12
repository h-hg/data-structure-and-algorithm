#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef struct SplayNode *Tree;
typedef int ElementType;
struct SplayNode
{
    Tree parent; //该结点的父节点，方便操作
    ElementType val; //结点值
    Tree lchild;
    Tree rchild;
    SplayNode(int val=0) //默认构造函数
    {
        parent=NULL;
        lchild=rchild=NULL;
        this->val=val;
    }
};
 
bool search(Tree &,ElementType);
Tree *search_val(Tree&,ElementType,Tree&);
bool insert(Tree &,ElementType);
Tree left_single_rotate(Tree&,Tree);
Tree right_single_rotate(Tree &,Tree );
void LR_rotate(Tree&,Tree );
void RL_rotate(Tree&,Tree );
void right_double_rotate(Tree&,Tree );
void left_double_rotate(Tree&,Tree );
void SplayTree(Tree &,Tree);
void up(Tree &,Tree );
Tree *Find_Min(Tree &);
void remove(Tree &,ElementType);
 
//查找函数，带调整功能
//参数:根结点，需要查找的val
//返回:true or false
bool search(Tree &root,ElementType val)
{
    
    Tree parent=NULL;
    Tree *temp=NULL;
    temp=search_val(root,val, parent);
    if (*temp && *temp!=root)
    {
        SplayTree(root,*temp);
        return true;
    }
    return false;
}
 
//具体的查找函数
//参数:根，需要查找的val,父节点指针
//成功:返回其结点
//失败：返回其引用,方便后面的插入操作
Tree *search_val(Tree &root,ElementType val,Tree &parent)
{
    if (root==NULL)
        return &root;
    if (root->val>val)
        return search_val(root->lchild,val,parent=root);
    else if(root->val<val)
        return search_val(root->rchild,val,parent=root);
    return &root;
}
 
//插入函数
//参数：根，需要插入的val
//返回:true or false
bool insert(Tree &root,ElementType val)
{
    Tree *temp=NULL;
    Tree parent=NULL;
    //先查找，如果成功则无需插入，否则返回该结点的引用。
    temp=search_val(root,val,parent);
    
    if (*temp==NULL) //需要插入数据
    {
        Tree node=new SplayNode(val);
        *temp=node; //因为是引用型，所以这里直接赋值，简化了很多了。
        node->parent=parent; //设置父节点。
        return true;
    }
    return false;
}
//单左旋操作
//参数:根，旋转结点(旋转中心)
//返回:当前子树中的新根
Tree left_single_rotate(Tree &root,Tree node)
{
    if (node==NULL)
        return NULL;
    Tree parent=node->parent; //其父结点
    Tree grandparent=parent->parent; //其祖父结点
    parent->rchild=node->lchild; //设置其父节点的右孩子
    if (node->lchild) //如果有左孩子则更新node结点左孩子的父节点信息
        node->lchild->parent=parent;
    node->lchild=parent; //更新node结点的左孩子信息
    parent->parent=node; //更新原父节点的信息
    node->parent=grandparent;
    
    if (grandparent) //更新祖父孩子结点的信息
    {
        
        if (grandparent->lchild==parent)
            grandparent->lchild=node;
        else
            grandparent->rchild=node;
    }
    else //不存在祖父节点，则原父节点为根，那么旋转后node为根
        root=node;
    return node;
}
//单右旋操作
//参数:根，旋转结点(旋转中心)
//返回:当前子树中的新根
Tree right_single_rotate(Tree &root,Tree node)
{
    if (node==NULL)
        return NULL;
    Tree parent,grandparent;
    parent=node->parent;
    grandparent=parent->parent;
    parent->lchild=node->rchild;
    if (node->rchild)
        node->rchild->parent=parent;
    node->rchild=parent;
    parent->parent=node;
    node->parent=grandparent;
    if (grandparent)
    {
        if (grandparent->lchild==parent)
            grandparent->lchild=node;
        else
            grandparent->rchild=node;
    }
    else
        root=node;
    return node;
 
}
//双旋操作（LR型），于AVL树类似
//参数：根，最后将变成子树根结点的结点
void LR_rotate(Tree &root,Tree node)
{
    left_single_rotate(root,node); //先左
    right_single_rotate(root,node);//后右
}
//双旋操作（RL型），于AVL树类似
//参数：根，最后将变成子树根结点的结点
void RL_rotate(Tree&root,Tree node)
{
    right_single_rotate(root,node); //先右后左
    left_single_rotate(root,node);
}
 
//两次单右旋操作
//参数：根，最后将变成子树根结点的结点
void right_double_rotate(Tree &root,Tree node)
{
    right_single_rotate(root,node->parent); //先提升其父节点
    right_single_rotate(root,node);         //最后提升自己
}
//两次单左旋操作
//参数：根，最后将变成子树根结点的结点
void left_double_rotate(Tree &root,Tree node)
{
    left_single_rotate(root,node->parent);
    left_single_rotate(root,node);
}
//Splay调整操作
void SplayTree(Tree &root,Tree node)
{
    while (root->lchild!=node && root->rchild!=node && root!=node) //当前结点不是根，或者不是其根的左右孩子，则根据情况进行旋转操作
        up(root, node);
    if (root->lchild==node) //当前结点为根的左孩子，只需进行一次单右旋
        root=right_single_rotate(root, node);
    else if(root->rchild==node) //当前结点为根的右孩子，只需进行一次单左旋
        root=left_single_rotate(root, node);
}
 
//根据情况，选择不同的旋转方式
void up(Tree &root,Tree node)
{
    Tree parent,grandparent;
    int i,j;
    parent=node->parent;
    grandparent=parent->parent;
    i=grandparent->lchild==parent ? -1:1;
    j=parent->lchild==node ?-1:1;
    if (i==-1 && j==-1) //AVL树中的LL型
        right_double_rotate(root, node);
    else if(i==-1 && j==1) //AVL树中的LR型
        LR_rotate(root, node);
    else if(i==1 && j==-1) //AVL树中的RL型
        RL_rotate(root, node);
    else                    //AVL树中的RR型
        left_double_rotate(root, node);
}
 
//操作当前子树的最小结点
//返回:其最小结点的引用
Tree *Find_Min(Tree &root)
{
    if (root->lchild)
        return Find_Min(root->lchild);
    return &root;
}
 
//删除操作
void remove(Tree &root,ElementType val)
{
    Tree parent=NULL;
    Tree *temp;
    Tree *replace;
    Tree replace2;
    temp=search_val(root,val, parent); //先进行查找操作
    if(*temp) //如果查找到了
    {
        if (*temp!=root) //判断是否是根结点，不是根结点，则需要调整至根结点
            SplayTree(root, *temp);
        
        //调制根结点或者本来就是根结点后进行删除，先查看是否有替代元素
        if (root->rchild)
        {
            //有替代元素
            replace=Find_Min(root->rchild); //找到替换元素
            root->val=(*replace)->val;  //替换
            if ((*replace)->lchild==NULL) //左子树为空
            {
                replace2=*replace;
                *replace=(*replace)->rchild; //重接其右孩子
                delete replace2;
                
            }
            else if((*replace)->rchild==NULL) //右子树为空
            {
                replace2=*replace;
                *replace=(*replace)->lchild; //重接其左孩子
                delete replace2;
            }
        }
        else
        {
            //无替代元素，则根直接移向左子树，不管左子树是否为空都可以处理
            replace2=root;
            root=root->lchild;
            delete replace2;
        }
    }
}
 
//前序
void PreOrder(Tree root)
{
    if (root==NULL)
        return;
    printf("%d ",root->val);
    PreOrder(root->lchild);
    PreOrder(root->rchild);
}
//中序
void InOrder(Tree root)
{
    if (root==NULL)
        return;
    InOrder(root->lchild);
    printf("%d ",root->val);
    InOrder(root->rchild);
}
int main()
{
    Tree root=NULL;
    insert(root, 11);
    insert(root, 7);
    insert(root, 18);
    insert(root, 3);
    insert(root, 9);
    insert(root, 16);
    insert(root, 26);
    insert(root, 14);
    insert(root, 15);
    
    search(root,14);
    printf("查找14:\n");
    printf("前序:");
    PreOrder(root);
    printf("\n");
    printf("中序:");
    InOrder(root);
    printf("\n");
    
//    remove(root,16);
//    remove(root,26);
//    remove(root,11);
    remove(root,16);
    printf("删除16:\n");
    printf("前序:");
    PreOrder(root);
    printf("\n");
    printf("中序:");
    InOrder(root);
    printf("\n");
    return 0;
}
/* 版权声明：本文为CSDN博主「zthgreat」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/u014634338/article/details/49586689 */