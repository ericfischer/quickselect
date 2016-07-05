#include "include/mapbox/quickselect.hpp"
#include <stdio.h>
#include <stdlib.h>

int main() {
    std::vector<int> arr = { 65, 28, 59, 33, 21, 56, 22, 95, 50, 12, 90, 53, 28, 77, 39 };
    mapbox::quickselect(arr, 8);

    std::vector<int> standard = { 39, 28, 28, 33, 21, 12, 22, 50, 53, 56, 59, 65, 90, 77, 95 };
    if (arr != standard) {
        fprintf(stderr, "Does not match\n");
        for (size_t i = 0; i < arr.size(); i++) {
            fprintf(stderr, "%d, ", arr[i]);
        }
        fprintf(stderr, "\n");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}
