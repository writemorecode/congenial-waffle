#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

size_t median_of_three(std::vector<int>& a, size_t low, size_t high)
{
    const auto mid = low + (high - low) / 2;
    if (a[low] > a[high]) {
        std::swap(a[low], a[high]);
    }
    if (a[low] > a[mid]) {
        std::swap(a[low], a[mid]);
    }
    if (a[mid] > a[high]) {
        std::swap(a[mid], a[high]);
    }
    return mid;
}

size_t partition(std::vector<int>& a, size_t low, size_t high)
{
    const int pivot = a[low];
    auto i = low, j = high;
    while (true) {
        while (a[i] < pivot) {
            i++;
        }
        while (a[j] > pivot) {
            j--;
        }
        if (i >= j) {
            return j;
        }
        std::swap(a[i], a[j]);
        i++;
        j--;
    }
}

void quicksort_sequential(std::vector<int>& a, const size_t low,
    const size_t high)
{
    if (high == low) {
        return;
    }
    const auto median_index = median_of_three(a, low, high);
    std::swap(a[median_index], a[low]);
    const auto q = partition(a, low, high);

    quicksort_sequential(a, low, q);
    quicksort_sequential(a, q + 1, high);
}

std::vector<int> random_vector(const size_t n)
{
    std::vector<int> data(n);

    static std::random_device rd;
    static std::mt19937 gen(rd());
    constexpr int LIMIT = 10000;
    static std::uniform_int_distribution<int> dist(-LIMIT, LIMIT + 1);

    std::generate(data.begin(), data.end(), []() { return dist(gen); });
    return data;
}

std::ostream& operator<<(std::ostream& stream, const std::vector<int>& vec)
{
    for (const auto& x : vec) {
        stream << x << ' ';
    }
    return stream;
}

void quicksort(std::vector<int>& vec)
{
    quicksort_sequential(vec, 0, vec.size() - 1);
}

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " [n]"
                  << "\n";
        return EXIT_FAILURE;
    }

    const size_t n = std::atol(argv[1]);
    std::vector<int> vec(random_vector(n));
    quicksort(vec);

    if (!std::is_sorted(vec.begin(), vec.end())) {
        std::cout << "FAIL! Expected:\n";
        std::sort(vec.begin(), vec.end());
        std::cout << vec << "\n";
        return EXIT_FAILURE;
    }
}
