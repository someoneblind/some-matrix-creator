#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int summ(int number)
{
    int sum = 0;
    string tempString = to_string(number);

    for (unsigned int i = 0; i < to_string(number).size(); ++i) {
        string symbol(1, to_string(number)[i]);
        sum += atoi(symbol.c_str());
    }

    return sum;
}

int rounding(double number)
{
    return static_cast<int>(ceil(number));
}

void alignment(int max, int number)
{
    for (unsigned int i = 0; i < (to_string(max).size() - to_string(number).size()); ++i) {
        cout << " ";
    }
    cout << number << " ";
}

void matrixCreator(int count, int maxRounds)
{
    int parentNumber;

    for (int i = 0; i < maxRounds; ++i) {

        parentNumber = i + 1;

        int sevenArray[count];
        int sevenArraySumNumbers[count];

        for (int i = 0; i < count; ++i) {
            sevenArray[i] = (i + 1) * parentNumber;
            sevenArraySumNumbers[i] = summ(sevenArray[i]);
            while (to_string(sevenArraySumNumbers[i]).size() > 1)
                sevenArraySumNumbers[i] = summ(sevenArraySumNumbers[i]);
        }

        for (int i = 0; i < rounding(static_cast<double>(count) / ceil(sqrt(count))); ++i) {
            alignment(rounding(sqrt(count)), i);
            cout << "   ";

            int rowLength = rounding(sqrt(count));

            if (i + 1 == rounding(static_cast<double>(count) / ceil(sqrt(count))))
                rowLength = count - i * rounding(sqrt(count));

            for (int j = 0; j < rowLength; ++j) {
                alignment(count * maxRounds, sevenArray[j + (rounding(sqrt(count))) * i]);
            }

            if (rowLength < rounding(sqrt(count))) {
                int rowLengthRemainder = rowLength;
                while (rowLengthRemainder < rounding(sqrt(count))) {
                    for (unsigned int i = 0; i < to_string(count * maxRounds).size(); ++i) {
                        cout << " ";
                    }
                    cout << " ";
                    ++rowLengthRemainder;
                }
            }

            cout << "               ";

            for (int j = 0; j < rowLength; ++j) {
                cout << sevenArraySumNumbers[j + (rounding(sqrt(count)) * i)] << " ";
            }

            cout << endl;
        }
        cout << endl << endl;
    }
}

int main(int argc, char *argv[])
{
    int count;

    int maxRounds;

    if (argc <= 1 || !strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
        cout << "   -h, --help                  " << "    give this help list" << endl;
        cout << "   [count] [max_rounds]        " << "    input parameters" << endl;
        exit(0);
    }

    if (argc > 1)
        count = abs(atoi(argv[1]));
    else
        count = 100;

    if (argc > 2)
        maxRounds = abs(atoi(argv[2]));
    else
        maxRounds = 10;

    matrixCreator(count, maxRounds);

    return 0;
}
