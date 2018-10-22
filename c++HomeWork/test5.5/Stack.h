//
// Created by 刘元林 on 2018/10/16.
//

#ifndef TEST5_5_STACK_H
#define TEST5_5_STACK_H

#include <iostream>

using namespace std;
typedef int Item;

typedef struct node {
    Item data;
    struct node *pNext;
} Node, *pNode;

class STACK {
public:
    int size;
    pNode Top;
    pNode Buttom;
public:
    STACK(pNode node, Item data);

public:
    bool Push(pNode node, Item data);

    bool Pop();

    bool visit();

    bool IsEmpty();

    int Stack_size();

    Item GetTOpData();

    bool ClearStack();

    bool DestroyStack();
};

STACK::STACK(pNode node, Item data) {
    node = new Node;
    if (node == 0) {
        cout << "新建 失败" << endl;
        return;
    }
    this->Top = node;
    this->Buttom = node;
    this->size = 1;
    node->pNext = NULL;
    node->data = data;
    return;

}

// 进栈
bool STACK::Push(pNode node, Item data) {
    node = new Node;
    if (node == 0) {
        cout << "new 失败" << endl;
        return false;
    }
    node->pNext = this->Top;
    node->data = data;
    this->size++;
    this->Top = node;
    return true;
}

// 出栈
bool STACK::Pop() {
    if (!this->size) {
        cout << "栈到底了" << endl;
        this->Top = NULL;
        return false;
    }
    pNode node;
    Item data;
    data = this->Top->data;
    node = this->Top;
    this->size--;
    this->Top = this->Top->pNext;
    delete node;
    return true;
}

// 遍历站内的所有元素
bool STACK::visit() {
    int size = this->size;
    if (size == 0)
        cout << "the stack is empty";
    pNode node = this->Top;
    while (size--) {
        cout << node->data << " ";
        node = node->pNext;
    }
    cout << endl;
    return true;
}

// 返回栈的大小
int STACK::Stack_size() {
    return this->size;
}

//为空返回true
bool STACK::IsEmpty() {
    if (this->size == 0)
        return true;
    else
        return false;
}

// 获得栈顶元素
Item STACK::GetTOpData() {
    return this->Top->data;
}

// 清除栈
bool STACK::ClearStack() {
    cout << "clear stack ,so ";
    while (this->IsEmpty() == false) {
        this->Pop();
    }
    return true;
}

bool STACK::DestroyStack() {
    pNode node = NULL;
    if (this->IsEmpty() == false) {
        node = this->Top;
        this->Top = this->Top->pNext;
        delete node;
    }
    cout << "destroy stack" << endl;
    return true;
}

#endif //TEST5_5_STACK_H
