int safe_array_access(int* arr, int sz, int idx) {
    if (idx > sz) {
        throw std::out_of_range("Индекс превышает размер массива");
    }
    else if (idx < 0) {
        throw std::out_of_range("Отрицательный индекс");
    }
    else if (arr == nullptr) {
        throw std::invalid_argument("Массив не существует (nullptr)");
    }

    return arr[idx];
}
