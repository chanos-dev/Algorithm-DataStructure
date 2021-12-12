#include<iostream>
using namespace std;

void print(int n, string s)
{
    for (int i = 0; i < n; i++)
    {
        cout << "____";
    }

    cout << s << "\n";
}

void whatistherecursive(int s, int e)
{
    print(s, "\"����Լ��� ������?\"");

    if (s >= e)
    {
        print(s, "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"");
        print(s, "��� �亯�Ͽ���.");
        return;
    }

    print(s, "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.");
    print(s, "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.");
    print(s, "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"");
    whatistherecursive(s+1, e);

    print(s, "��� �亯�Ͽ���.");
}

int main()
{
    int n; cin >> n;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    whatistherecursive(0, n);
}