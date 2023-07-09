#include <iostream>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> filesToDelete = {
        "asymprivate.bin",
        "asympublic.bin",
        "clients.json.encrypted"
    };
    std::string fileToClear = "companycars.xml";

    for (const auto& file : filesToDelete) {
        if (remove(file.c_str()) != 0) {
            return 1;
        }
    }

    std::ofstream ofs(fileToClear);
    if (!ofs) {
        return 1;
    }

    ofs << "<?xml version=\"1.0\" encoding=\"ISO-8859-2\"?>\n<companycars>\n</companycars>";
    return 0;
}


