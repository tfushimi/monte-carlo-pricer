#ifndef Wrapper_hpp
#define Wrapper_hpp

template<class T>
class Wrapper {
public:
    Wrapper() {
        dataPtr = nullptr;
    }
    
    Wrapper(const T& inner) {
        dataPtr = inner.clone();
    }
    
    ~Wrapper() {
        if (dataPtr != nullptr) {
            delete dataPtr;
        }
    }
    
    Wrapper(const Wrapper<T>& original) {
        if (original.dataPtr != nullptr) {
            dataPtr = original.dataPtr->clone();
        } else {
            dataPtr = nullptr;
        }
    }
        
    
    Wrapper& operator=(const Wrapper<T>& original) {
        if (this != &original) {
            if (dataPtr != nullptr) {
                delete dataPtr;
            }
            
            dataPtr = (original.dataPtr != nullptr) ? original.dataPtr->clone() : nullptr;
        }
        return *this;
    }
    
    T& operator*() {
        return *dataPtr;
    }
    
    const T& operator*() const {
        return *dataPtr;
    }
    
    const T* const operator->() const {
        return dataPtr;
    }
    
    T* operator->() {
        return dataPtr;
    }
    
private:
    T* dataPtr;
};


#endif /* Wrapper_h */
