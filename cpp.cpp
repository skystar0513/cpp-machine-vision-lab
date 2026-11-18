// anomaly map 생성
//step_01
#include <iostream>
#include <random>
#include <iomanip>

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

    for (int i = 0;i < size;i++) {
        anomalymap[i] = dis(gen);
    };



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


    delete[] anomalymap;


    return 0;
}
