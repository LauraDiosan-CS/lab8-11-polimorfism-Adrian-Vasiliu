#pragma once
#include "TemplateRepository.h"
#include <fstream>
using namespace std;

template<class T>
class TemplateFileRepo : public TemplateRepository<T> {
 private:
    const char *file;
    char delimiter;
 public:
    TemplateFileRepo();
    TemplateFileRepo(const char *, char);
    ~TemplateFileRepo();
    void read_file();
    void write_file();
};

template<class T>
TemplateFileRepo<T>::TemplateFileRepo() {
    file = nullptr;
    delimiter = ' ';
}

template<class T>
TemplateFileRepo<T>::TemplateFileRepo(const char *file_name, char character) {
    file = file_name;
    delimiter = character;
}

template<class T>
TemplateFileRepo<T>::~TemplateFileRepo() = default;

template<class T>
void TemplateFileRepo<T>::read_file() {
    this->items.clear();
    ifstream f(file);
    string line;
    while (getline(f, line)) {
        T item(line, delimiter);
        this->items.push_back(item);
    }
    f.close();
}

template<class T>
void TemplateFileRepo<T>::write_file() {
    ofstream f(file);
    for (T item : this->items) {
        f << item.string_delimiter(delimiter) << endl;
    }
    f.close();
}
