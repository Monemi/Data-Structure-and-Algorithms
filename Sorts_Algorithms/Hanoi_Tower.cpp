#include <iostream> 
#include <cmath> 
#include <chrono>

#define ARRAYSIZE 10000
using namespace std;
void Time_Calculator(void);
//========================================================Hanoi iterative
class TowersHanoi
{
private:
    struct
    {
        char chToPeg;
        char chFromPeg;
        int iDiskNo;
    }node[ARRAYSIZE]; //Array of Nodes 

    char except(char chFromPeg, char chToPeg); //returns peg other than provided as parameter 
public:

    TowersHanoi(); //constructor 
    TowersHanoi(int);
    //generates the tree 
    void generateTree(char chFromPeg, char chToPeg, int iDiskNo);
};
TowersHanoi::TowersHanoi(int disk_number)

{
    if (disk_number < 1) { disk_number = 3; }

    generateTree('A', 'B', disk_number);
    int cMoves = (int)pow(2, disk_number) - 1;

    cout << "THE MOVES ARE AS FOLLOWS\n";
    for (int i = 0; i < cMoves; i++)
        cout << i + 1 << ": " << "Move Disk " << node[i].iDiskNo << " From " << node[i].chFromPeg
        << " To " << node[i].chToPeg << endl;
}
void TowersHanoi::generateTree(char From, char To, int Now_Disk_Number)

{
    int j, iLevel = 1, iDistance, iDistance2;
    int iNodeIndex;

    node[(int)pow(2, Now_Disk_Number - 1) - 1].chToPeg = To;
    node[(int)pow(2, Now_Disk_Number - 1) - 1].chFromPeg = From;
    node[(int)pow(2, Now_Disk_Number - 1) - 1].iDiskNo = Now_Disk_Number;
    for (int i = 1; i <= Now_Disk_Number - 1; i++)

    {
        iDistance = 0;
        iDistance2 = (int)pow(2, Now_Disk_Number - i);
        for (j = 0; j < (int)pow(2, i); j++)

        {
            if (j % 2 == 0)

            {
                iNodeIndex = iDistance + (int)pow(2, Now_Disk_Number - 1 - i) - 1;
                node[iNodeIndex].chToPeg =
                    except(node[iNodeIndex + iDistance2 / 2].chFromPeg,
                        node[iNodeIndex + iDistance2 / 2].chToPeg);

                node[iNodeIndex].chFromPeg =
                    node[iNodeIndex + iDistance2 / 2].chFromPeg;
                node[iNodeIndex].iDiskNo = Now_Disk_Number - iLevel;
            }
            else

            {
                iNodeIndex = iDistance + (int)pow(2, Now_Disk_Number - 1 - i) - 1;
                node[iNodeIndex].chFromPeg =
                    except(node[iNodeIndex - iDistance2 / 2].chFromPeg,
                        node[iNodeIndex - iDistance2 / 2].chToPeg);

                node[iNodeIndex].chToPeg =
                    node[iNodeIndex - iDistance2 / 2].chToPeg;
                node[iNodeIndex].iDiskNo = Now_Disk_Number - iLevel;
            }
            iDistance += (int)pow(2, Now_Disk_Number - i);
        }
        iLevel++;
    }
}

char TowersHanoi::except(char chFromPeg, char chToPeg)

{
    if (chFromPeg == 'A' && chToPeg == 'B' || chFromPeg == 'B' && chToPeg == 'A')
        return 'C';
    if (chFromPeg == 'A' && chToPeg == 'C' || chFromPeg == 'C' && chToPeg == 'A')
        return 'B';
    if (chFromPeg == 'B' && chToPeg == 'C' || chFromPeg == 'C' && chToPeg == 'B')
        return 'A';
}

//================================================================================Hanoi Recursive 
void Hanoi_Recursive(int x, char A, char C, char B)
{
    if (x == 1)
    {
        cout << "Move the disc 1 from " << A << " to " << C << endl;
        x = x - 1;
    }
    else
    {
        Hanoi_Recursive(x - 1, A, B, C);
        cout << "Move the disc " << x << " from " << A << " to " << C << endl;
        Hanoi_Recursive(x - 1, B, C, A);
    }
}
//===========================================================This Method Calculate Time of Hanoi_Tower in  Recursive Functions
void Time_Calculator(void) {
    std::cout << "This Function Help you Undrestand Time Complexity of  Recursive Hanoi Method\nPlease Dont use above 20 disks(it take 100 seconds for me :))" << std::endl;
    std::cout << "Please Enter Disk Numbers For Methods :" << std::endl;
    int disk = 0;
    std::cin >> disk;
    std::cout << "1-Recursive Hanoi_Tower Started ==>" << std::endl;
    auto start1 = chrono::steady_clock::now();
    //Do some staff1
    Hanoi_Recursive(disk, 'A', 'C', 'B');
    auto end1 = chrono::steady_clock::now();
    std::cout << "2-Recursive Hanoi_Tower Ended <==" << std::endl;

    cout << "Recursive Hanoi Elapsed Time(ms) ==>  "
        << chrono::duration_cast<chrono::milliseconds>(end1 - start1).count()
        << " ms" << endl;

}
void main(void)

{
    int Disk_Count = 0;
    std::cout << "Enter Disks Count" << std::endl;
    std::cin >> Disk_Count;
    if (Disk_Count < 1) { Disk_Count = 3; }
    else {
        //---------------------------------------------------------------------------Using Iterative Hanoi_Tower 
        cout << "A represents FROM PEG,\nB represents TO PEG,\nC represents AUXILLARY PEG\n";
        TowersHanoi towersHanoi(Disk_Count);
        //---------------------------------------------------------------------------Using Recursive Hanoi_Tower 
        std::cout << "============================================ Recursive " << std::endl;
        Hanoi_Recursive(Disk_Count, 'A', 'C', 'B');
        //---------------------------------------------------------------------------Calculate Time Elapsed in Different Methodes !
    }
    std::cout << "============================================" << std::endl;
    Time_Calculator();
}


