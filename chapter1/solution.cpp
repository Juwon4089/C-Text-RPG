#include <iostream>
#include <string>

using namespace std;

const int SIZE = 4;

void printStatus(string name, int stat[])
{
    cout << "====================================" << endl;
    cout << "  " << name << " 의 현재 능력치" << endl;
    cout << "====================================" << endl;
    cout << "HP : " << stat[0] << "    MP : " << stat[1] << endl;
    cout << "공격력 : " << stat[2] << "    방어력 : " << stat[3] << endl;
    cout << "====================================" << endl;
}

int main()
{
    string name;
    int stat[SIZE] = { 0 };

    cout << "==========================================" << endl;
    cout << "      [ 던전 탈출 텍스트 RPG ]" << endl;
    cout << "==========================================" << endl;

    cout << "용사의 이름을 입력해주세요 : ";
    cin >> name;

    while (true)
    {
        cout << "HP와 MP를 입력해주세요 : ";
        cin >> stat[0] >> stat[1];

        if (stat[0] > 50 && stat[1] > 50)
        {
            break;
        }
        else
        {
            cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << endl;
        }
    }

    while (true)
    {
        cout << "공격력과 방어력을 입력해주세요 : ";
        cin >> stat[2] >> stat[3];

        if (stat[2] > 0 && stat[3] > 0)
        {
            break;
        }
        else
        {
            cout << "공격력이나 방어력이 너무 작습니다. 다시 입력해주세요." << endl;
        }
    }

    printStatus(name, stat);

    int hpPotion = 5;
    int mpPotion = 5;

    bool isGameStart = false;
    int choice;

    cout << endl;
    cout << "* HP 포션 5개, MP 포션 5개가 기본 지급되었습니다." << endl;

    while (!isGameStart)
    {
        cout << "============================================" << endl;
        cout << "< 캐릭터 강화 >" << endl;
        cout << "1. HP UP    2. MP UP    3. 공격력 2배" << endl;
        cout << "4. 방어력 2배    5. 현재 능력치    0. 게임 시작" << endl;
        cout << "============================================" << endl;
        cout << "번호를 선택해주세요 : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (hpPotion > 0)
            {
                stat[0] = stat[0] + 20;
                hpPotion = hpPotion - 1;

                cout << "HP가 20 증가했습니다." << endl;
                cout << "남은 HP 포션 : " << hpPotion << "개" << endl;
            }
            else
            {
                cout << "포션 부족" << endl;
            }
            break;

        case 2:
            if (mpPotion > 0)
            {
                stat[1] = stat[1] + 20;
                mpPotion = mpPotion - 1;

                cout << "MP가 20 증가했습니다." << endl;
                cout << "남은 MP 포션 : " << mpPotion << "개" << endl;
            }
            else
            {
                cout << "포션 부족" << endl;
            }
            break;

        case 3:
            stat[2] = stat[2] * 2;
            cout << "공격력이 2배가 되었습니다." << endl;
            break;

        case 4:
            stat[3] = stat[3] * 2;
            cout << "방어력이 2배가 되었습니다." << endl;
            break;

        case 5:
            printStatus(name, stat);
            break;

        case 0:
            cout << "게임을 시작합니다!" << endl;
            isGameStart = true;
            break;

        default:
            cout << "잘못된 번호입니다." << endl;
            break;
        }
    }

    return 0;
}
