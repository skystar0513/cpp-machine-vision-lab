#include <iostream>
#include <random>
#include <iomanip>

float GetMaxScore(const float* anomaly, int size) {
    float max_value = 0.0f;
    for (int i = 0; i < size; i++) {
        if (anomaly[i] > max_value) {
            max_value = anomaly[i];
        }
    }

    return max_value;

}

void thresholding(const float* anomalymap, unsigned char* mask, int size, float threshold) {
    for (int i = 0; i < size; i++) {
        if (anomalymap[i] >= threshold) {
            mask[i] = 255;
        }
        else {
            mask[i] = 0;
        }
    }
    
}


int main()
{
    int width = 5;
    int height = 5;
    int size = width * height;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<float> dis(0.1f, 1.0f);

    size_t memory = size * sizeof(float);
    float* anomalymap = new float[size];
    unsigned char* mask = new unsigned char[size]; //unsigned char 형의 mask 동적 메모리 생성
    size_t mask_memory = size * sizeof(unsigned char); //mask 메모리 사이즈 계산

    float threshold = 0.7f;

    for (int i = 0;i < size;i++) {
        anomalymap[i] = dis(gen);
    };


    thresholding(anomalymap, mask, size, threshold);
    float max_value = GetMaxScore(anomalymap, size);
    std::cout << "max_value: " << max_value << std::endl;


    std::cout << "===== Anomaly Inspection =====" << std::endl;
    std::cout << "Width      :" << width << std::endl;
    std::cout << "Height     :" << height << std::endl;
    std::cout << "Total Pixel  :"<< size << std::endl;
    std::cout << "Memory Size   :"<< memory << std::endl;
    std::cout << "===== Anomaly Map =====" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    for (int j = 0; j < size; j++) {

        std::cout << anomalymap[j] << " ";
        if ((j+1 )% width == 0) {
            std::cout << '\n';
        }
    }

    std::cout << "===== Binary Mask =====" << std::endl;
    std::cout << "Memory Size : " << mask_memory << " bytes" << std::endl;
    std::cout << "threshold : " << threshold <<  std::endl;

    for (int k = 0; k < size; k++) {

        std::cout << static_cast<int>(mask[k]) << " ";
        if ((k + 1) % width == 0) {
            std::cout << '\n';
        }
    }

    delete[] mask;
    delete[] anomalymap;


    return 0;
}
