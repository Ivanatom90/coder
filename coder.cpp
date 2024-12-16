#include "coder.h"

void MakeBinFromFile(std::string input_file, std::string output_file_path, int64_t mask){
    std::string str;
    std::ifstream file(input_file, std::ios_base::binary);
    std::ofstream outfile(output_file_path, std::ios_base::binary);
    int64_t res;
    if(file.is_open()){
        while(file.read((char*) &res, sizeof(int64_t))){
            if(file.gcount() == sizeof(int64_t)){
                res ^= mask;
                outfile.write((char*) &res, sizeof(res));
            }
        }
        file.close();
        outfile.close();
    } else {
        return;
    }

}

void Delay(int n){
    QEventLoop loop;
    QTimer::singleShot(n, &loop, SLOT(quit()));
    loop.exec();
}
