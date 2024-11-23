#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        bool bob = false, alice = true;

        for (int i = 0; i < n + 1; i++)
        {

            // set up for empty string
            if (str.empty())
            {
                // cout << "for empty" << endl;
                if (alice)
                {
                    // cout << "alice" << endl;
                    cout << "NO" << endl;
                }
                else if (bob)
                {
                    // cout << "bob" << endl;
                    cout << "YES" << endl;
                }
                break;
            }

            // for the first char -> U
            if (str[0] == 'U')
            {
                // got in first string
                str.erase(0, 1);
                if (str.empty())
                {
                    if (bob)
                    {
                        bob = false;
                        alice = true;
                    }
                    else if (alice)
                    {
                        alice = false;
                        bob = true;
                    }
                    continue;
                }

                if (str.size() < 2)
                {
                    // no flip
                }
                else
                {
                    // flip
                    if (str.at(0) == 'U')
                    {
                        str[0] = 'D';
                    }
                    else
                    {
                        str[0] = 'U';
                    }
                    if (str.at(str.size() - 1) == 'U')
                    {
                        str[str.size() - 1] = 'D';
                    }
                    else
                    {
                        str[str.size() - 1] = 'U';
                    }
                }
            }
            else if (str.at(str.size() - 1) == 'U')
            {

                // got in last string
                str.erase(str.size() - 1, 1);
                if (str.empty())
                {
                    if (bob)
                    {
                        bob = false;
                        alice = true;
                    }
                    else if (alice)
                    {
                        alice = false;
                        bob = true;
                    }
                    continue;
                }

                if (str.size() < 2)
                {
                    // no flip
                }
                else
                {
                    // flip
                    if (str.at(str.size() - 1) == 'U')
                    {
                        str[str.size() - 1] = 'D';
                    }
                    else
                    {
                        str[str.size() - 1] = 'U';
                    }
                    if (str.at(0) == 'U')
                    {
                        str[0] = 'D';
                    }
                    else
                    {
                        str[0] = 'U';
                    }
                }
            }
            else
            {
                // there is no U face in first or last
                // cout << " for not getting d " << endl;
                if (alice)
                {
                    cout << "NO" << endl;
                }
                else if (bob)
                {
                    cout << "YES" << endl;
                }
                break;
            }

            if (bob)
            {
                bob = false;
                alice = true;
            }
            else if (alice)
            {
                alice = false;
                bob = true;
            }
        }
    }
}