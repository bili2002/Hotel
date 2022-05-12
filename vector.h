template<typename T>
class myVector{
    T* arr = nullptr;
    int maxSize = 0;
    int currSize = 0;

    void expandVector() {
        int newSize = maxSize != 0 ? maxSize*2 + 1;
        T *temp = new T[newSize];
        for (int i=0; i<currSize; i++) {
            temp[i] = arr[i];
        }

        delete[] arr;
        arr = temp;
        maxSize = newSize;
    }

    void shrinkVector() {
        T *temp = new int[maxSize/2];
        for (int i=0; i<currSize; i++) {
            temp[i] = nums[i];
        }

        delete[] nums;
        nums = temp;
        maxSize /= 2;
    }

public:
    myVector(int size, T var) {
        int newSize = 1;
        while (newSize < size) {
            newSize *= 2;
        }

        arr = new T[newSize];
        maxSize = newSize;
        currSize = size;
    } 

    ~myVector() {
        delete[] arr;
    }

    void push_back(T var) {
        if (currSize == maxSize) {
            expandVector();
        }
        arr[currSize++] = var;
    }

    void pop_back(T var) {
        if (currSize == maxSize/2) {
            shrinkVector();
        }
        currSize--;
    }

    int size() {
        return currSize;
    }


};