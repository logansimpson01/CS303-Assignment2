#pragma once
#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <cstddef>
#include <stdexcept>

template<typename Item_Type>
class Single_Linked_List {
private:
    struct Node {
        Item_Type data;
        Node* next;
        Node(const Item_Type& data_item, Node* next_val = nullptr) : data(data_item), next(next_val) {}
    };
    Node* head;
    Node* tail;
    size_t num_items;

public:
    Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

    // List operations
    void push_front(const Item_Type& item) {
        head = new Node(item, head);
        if (tail == nullptr) tail = head;
        num_items++;
    }

    void push_back(const Item_Type& item) {
        Node* new_node = new Node(item);
        if (tail != nullptr) tail->next = new_node;
        else head = new_node;
        tail = new_node;
        num_items++;
    }

    void pop_front() {
        if (empty()) throw std::runtime_error("List is empty");
        Node* old_head = head;
        head = head->next;
        delete old_head;
        if (head == nullptr) tail = nullptr;
        num_items--;
    }

    void pop_back() {
        if (empty()) throw std::runtime_error("List is empty");
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        }
        else {
            Node* current = head;
            while (current->next != tail) current = current->next;
            current->next = nullptr;
            delete tail;
            tail = current;
        }
        num_items--;
    }

    Item_Type& front() const {
        if (empty()) throw std::runtime_error("List is empty");
        return head->data;
    }

    Item_Type& back() const {
        if (empty()) throw std::runtime_error("List is empty");
        return tail->data;
    }

    bool empty() const {
        return head == nullptr;
    }

    void insert(size_t index, const Item_Type& item) {
        if (index == 0) {
            push_front(item);
        }
        else if (index >= num_items) {
            push_back(item);
        }
        else {
            Node* current = head;
            for (size_t i = 1; i < index; i++) {
                current = current->next;
            }
            current->next = new Node(item, current->next);
            num_items++;
        }
    }

    bool remove(size_t index) {
        if (index >= num_items) return false;
        if (index == 0) {
            pop_front();
        }
        else {
            Node* current = head;
            for (size_t i = 1; i < index; i++) {
                current = current->next;
            }
            Node* to_delete = current->next;
            current->next = to_delete->next;
            if (to_delete == tail) tail = current;
            delete to_delete;
            num_items--;
        }
        return true;
    }

    size_t find(const Item_Type& item) const {
        Node* current = head;
        size_t index = 0;
        while (current) {
            if (current->data == item) return index;
            current = current->next;
            index++;
        }
        return num_items;
    }

    size_t size() const {
        return num_items;
    }
};

#endif
