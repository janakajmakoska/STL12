#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Pole {
private:
    T* elements;
    int size;
public:
    Pole(T* el, int s) {
        size = s;
        elements = new T[size];
        for (int i = 0; i < size; i++) {
            elements[i] = el[i];
        }
    }

    T getMax() {
        T max = elements[0];
        for (int i = 1; i < size; i++) {
            if (elements[i] > max) {
                max = elements[i];
            }
        }
        return max;
    }
};

template<typename T>
T max(Pole<T>& pole) {
    return pole.getMax();
}

int main() {
    int intEl[5] = { 3, 5, 7, 1, 9 };
    Pole<int> intPole(intEl, 5);
    cout << "Max element in int pole: " << max(intPole) << endl;

    char charEl[5] = { 'a', 'd', 'e', 'c', 'b' };
    Pole<char> charPole(charEl, 5);
    cout << "Max element in char pole: " << max(charPole) << endl;

    string stringEl[5] = { "apple", "banana", "cherry", "date", "elderberry" };
    Pole<string> stringPole(stringEl, 5);
    cout << "Max element in string pole: " << max(stringPole) << endl;

    return 0;
}
