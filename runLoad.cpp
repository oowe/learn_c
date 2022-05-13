#include <iostream>
#include <thread>
#include <random>
#include <fstream>

using namespace std;

class Load
{
private:
    bool status;

public:
    Load()
    {
        status = true;
    }
    string getTimeStr()
    {
        time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
        string s(30, '\0');
        strftime(&s[0], s.size(), "%Y-%m-%d %H:%M:%S", localtime(&now));
        return s;
    }

    int getKw()
    {
        int min = 29;
        int max = 43;
        // random [29-43]
        int s = random() % (max - min + 1) + 29;
        return s;
    }
    bool getStatus()
    {
        return status;
    }
    int changeStatus()
    {
        status = !status;
        return status;
    }
};

int main(void)
{
    ofstream myfile;
    Load refrigerator;
    int i = 1;
    while (1)
    {
        cout << refrigerator.getTimeStr() << " " << refrigerator.getKw() << " " << boolalpha << refrigerator.getStatus() << endl;
        if (i % 10 == 0)
        {
            refrigerator.changeStatus();
            i = 1;
        }
        i++;
        string text("Some huge text to write to\n");
        string filename2("example.txt");
        fstream outfile;

        outfile.open(filename2, std::ios_base::out);
        if (!outfile.is_open())
        {
            cout << "failed to open " << filename2 << '\n';
        }
        else
        {
            outfile.write(text.data(), text.size());
            cout << "Done Writing!" << endl;
        }

        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
    return 0;
}
