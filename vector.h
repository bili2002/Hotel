template<typename Type>
class myVector {
private:
    Type *arr = nullptr;
    int maxSize = 0;
    int currSize = 0;

    void expandVector() {
        int newSize = maxSize != 0 ? maxSize*2 : 1;
        Type *temp = new Type[newSize];
        for (int i=0; i<currSize; i++) {
            temp[i] = arr[i];
        }

        delete[] arr;
        arr = temp;
        maxSize = newSize;
    }

    void shrinkVector() {
        Type *temp = new Type[maxSize/2];
        for (int i=0; i<currSize; i++) {
            temp[i] = arr[i];
        }

        delete[] arr;
        arr = temp;
        maxSize /= 2;
    }

    static void swap(Type &left, Type &right) {
        Type temp = left;
        left = right;
        right = temp;
    }

public:
    myVector(int size, Type var) {
        int newSize = 1;
        while (newSize < size) {
            newSize *= 2;
        }

        arr = new Type[newSize];
        maxSize = newSize;
        currSize = size;
    } 

    myVector(const myVector &oth) {
        maxSize = oth.maxSize;
        currSize = oth.currSize;

        arr = new Type[maxSize];
        for (int i=0; i<currSize; i++) {
            arr[i] = oth.arr[i];
        }
    }

    ~myVector() {
        delete[] arr;
    }
    
    void operator=(const myVector &oth) {
        maxSize = oth.maxSize;
        currSize = oth.currSize;

        arr = new Type[maxSize];
        for (int i=0; i<currSize; i++) {
            arr[i] = oth.arr[i];
        }
    }

    Type operator[](int i) {
        return arr[i];
    }

    void push_back(Type var) {
        if (currSize == maxSize) {
            expandVector();
        }
        arr[currSize++] = var;
    }

    void pop_back() {
        if (currSize == maxSize/2) {
            shrinkVector();
        }
        currSize--;
    }

    void erase(int pos) {
        for (int i=pos; i<currSize-1; i++) {
            swap(arr[i], arr[i+1]);
        }
        pop_back();
    }

    int size() {
        return currSize;
    }

    bool empty() {
        return currSize == 0;
    }

    Type *begin() {
        return arr;
    }
    
    Type *end() {
        return arr + currSize;
    }

    void swap(myVector &oth) {
        swap(maxSize, oth.maxSize);
        swap(currSize, oth.currSize);
        swap(arr, oth.arr);
    }
};