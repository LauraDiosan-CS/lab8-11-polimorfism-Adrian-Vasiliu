#pragma once
#include <vector>
#include <algorithm>
using namespace std;

template<class T>
class TemplateRepository {
 protected:
    vector<T> items;
 public:
    TemplateRepository<T>() = default;
    ~TemplateRepository() = default;
    vector<T> get_all();
    int get_size();
    int get_position(const T &);
    T get_item(int);
    void add(const T &);
    int remove(const T &);
    void update(const T &, const T &);
};

template<class T>
vector<T> TemplateRepository<T>::get_all() {
    return items;
}

template<class T>
int TemplateRepository<T>::get_size() {
    return items.size();
}

template<class T>
int TemplateRepository<T>::get_position(const T &item) {
    for (int i = 0; i < get_size(); i++)
        if (items[i] == item)
            return i;
    return -1;
}

template<class T>
T TemplateRepository<T>::get_item(int position) {
    return items[position];
}

template<class T>
void TemplateRepository<T>::add(const T &item) {
    items.push_back(item);
}

template<class T>
int TemplateRepository<T>::remove(const T &item) {
//    int position = get_position(item);
//    items.erase(position);
    for (int i = 0; i < items.size(); i++)
        if (items[i] == item) {
            items[i] = items.back();
            items.pop_back();
        }
    return 0;
//    for (auto object:items)
//        if (object == item) {
//            object = items.back();
//            items.pop_back();
//        }
}

template<class T>
void TemplateRepository<T>::update(const T &old, const T &item) {
    replace(items.begin(), items.end(), old, item);
}
