#include <fstream>
#include <iostream>

template <std::size_t N>
void writeArrayToBin(const std::string& filename, int (&arr)[N]) {
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        std::cerr << "File could not be opened for writing." << std::endl;
        return;
    }

    outFile.write(reinterpret_cast<const char*>(arr), N * sizeof(int));
    outFile.close();
}


template <std::size_t N, std::size_t M>
void write2DArrayToBin(const std::string& filename, int (&arr)[N][M]) {
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        std::cerr << "File could not be opened for writing." << std::endl;
        return;
    }

    for(int i = 0; i < N; i++) {
        outFile.write(reinterpret_cast<const char*>(arr[i]), M * sizeof(int));
    }
    outFile.close();
}
int main() {
    int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    write2DArrayToBin("output.bin", arr);
    return 0;
}
