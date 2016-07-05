#pragma once

#include <algorithm>
#include <cmath>
#include <vector>

namespace mapbox {

template <typename T>
static int compare(T a, T b) {
    return a < b ? -1 : a > b ? 1 : 0;
}

template <typename T>
void quickselect(std::vector<T>& arr, size_t k, size_t left = 0, ssize_t right = -1) {
    if (right < 0) {
        right = arr.size() - 1;
    }

    while (right > left) {
        if (right - left > 600) {
            ssize_t n = right - left + 1;
            ssize_t m = k - left + 1;
            double z = std::log(n);
            double s = 0.5 * std::exp(2 * z / 3);
            double sd = 0.5 * std::sqrt(z * s * (n - s) / n) * (m - n / 2 < 0 ? -1 : 1);
            size_t newLeft = std::max(left, static_cast<size_t>(std::floor(k - m * s / n + sd)));
            size_t newRight =
                std::min(right, static_cast<ssize_t>(std::floor(k + (n - m) * s / n + sd)));
            quickselect(arr, k, newLeft, newRight);
        }

        T t = arr[k];
        size_t i = left;
        size_t j = right;

        std::swap(arr[left], arr[k]);
        if (compare(arr[right], t) > 0) {
            std::swap(arr[left], arr[right]);
        }

        while (i < j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
            while (compare(arr[i], t) < 0) {
                i++;
            }
            while (compare(arr[j], t) > 0) {
                j--;
            }
        }

        if (compare(arr[left], t) == 0) {
            std::swap(arr[left], arr[j]);
        } else {
            j++;
            std::swap(arr[j], arr[right]);
        }

        if (j <= k) {
            left = j + 1;
        }
        if (k <= j) {
            right = j - 1;
        }
    }
}
}
