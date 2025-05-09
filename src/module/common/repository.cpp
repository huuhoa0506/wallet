#include "repository.h"

using namespace std;

template <typename T>
T* Repository<T>::findById(string id) {


}

template <typename T>
bool Repository<T>::save(T* model) {
    // logic
}


template <typename T>
bool Repository<T>::write() {
    std::ofstream out(name+".csv");

    for (const auto& model : models) {
        // out << model.id << "," << user.name << "," << user.balance << "\n";
    }
    out.close();
}