#include <iostream> 
#include <cmath> 
#define ARRAYSIZE 100 
using namespace std;
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
    //generates the tree 
    void generateTree(char chFromPeg, char chToPeg, int iDiskNo);
};
TowersHanoi::TowersHanoi()

{
    int disk_number;
    cout << "\nENTER THE NUMBER OF DISKS >> ";
    cin >> disk_number;

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

void main(void)

{
    //---------------------------------------------------------------------------Using Iterative Hanoi_Tower 
    cout << "A represents FROM PEG,\nB represents TO PEG,\nC represents AUXILLARY PEG\n";
    TowersHanoi towersHanoi;
    //---------------------------------------------------------------------------Using Recursive Hanoi_Tower 
    std::cout << "============================================" << std::endl;
    Hanoi_Recursive(5, 'A', 'C', 'B');
}


