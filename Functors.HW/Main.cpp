#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>


// ������� ��� ������ ���������� ��������
struct FindMin {
    int operator()(const std::vector<int>& v) const {
        return *std::min_element(v.begin(), v.end());
    }
};

// ������� ��� ������ ������������� ��������
struct FindMax {
    int operator()(const std::vector<int>& v) const {
        return *std::max_element(v.begin(), v.end());
    }
};

// ������� ��� ���������� �� ����������
struct SortAscending {
    void operator()(std::vector<int>& v) const {
        std::sort(v.begin(), v.end());
    }
};

// ������� ��� ���������� �� ���������
struct SortDescending {
    void operator()(std::vector<int>& v) const {
        std::sort(v.begin(), v.end(), std::greater<int>());
    }
};

// ������� ��� ��������� ������� �� ���������
struct IncreaseBy {
    int value;
    IncreaseBy(int val) : value(val) {}

    void operator()(int& num) const {
        num += value;
    }
};

// ������� ��� ��������� ������� �� ���������
struct DecreaseBy {
    int value;
    DecreaseBy(int val) : value(val) {}

    void operator()(int& num) const {
        num -= value;
    }
};

// ������� ��� ��������� ��������, ����� �������� ��������
struct RemoveValue {
    int value;
    RemoveValue(int val) : value(val) {}

    bool operator()(int num) const {
        return num == value;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::vector<int> numbers = { 5, 2, 8, 1, 9, 3, 6, 4, 7 };

    // ������������ ��������
    FindMin findMin;
    std::cout << "̳������� ��������: " << findMin(numbers) << std::endl;

    FindMax findMax;
    std::cout << "����������� ��������: " << findMax(numbers) << std::endl;

    SortAscending sortAscending;
    sortAscending(numbers);
    std::cout << "³����������� �� ����������: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    SortDescending sortDescending;
    sortDescending(numbers);
    std::cout << "³����������� �� ���������: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    IncreaseBy increaseBy(2);
    for_each(numbers.begin(), numbers.end(), increaseBy);
    std::cout << "��������� �� 2: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    DecreaseBy decreaseBy(3);
    for_each(numbers.begin(), numbers.end(), decreaseBy);
    std::cout << "��������� �� 3: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    RemoveValue removeValue(4);
    numbers.erase(std::remove_if(numbers.begin(), numbers.end(), removeValue), numbers.end());
    std::cout << "ϳ��� ��������� �������, ����� 4: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
