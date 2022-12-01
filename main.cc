#include <string>

int main(int argc, char* argv[]) {


    if (argc > 1) {
        int argument = 1;
        while (argument < ((argc - 1) / 2)) {
            if (argv[argument] == "text") {
                
            } else if (argv[argument] == "seed") {

            } else if (argv[argument] == "scriptfile1") {

            } else if (argv[argument] == "scriptfile2") {

            } else if (argv[argument] == "startlevel") {
                
            }
            ++argument;
        }
    }
    return 0;
}
