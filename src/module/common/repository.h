#include <model.cpp>
#include <string>

using namespace std;

template <typename T>   
class Repository {
    static_assert(std::is_base_of<Model, T>::value, "T must inherit from Model");

    string virtual name;
    vector<T> models;
    bool write();
    
public:
    T* findById(string id);
    bool save(T* model);
};
