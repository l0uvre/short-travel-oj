#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int T, i, tmp, n, m;
bool skip[1000010] = {false};

string gen_new(string &str)
{
    int pos = 0, len = 0;
    string newstr;
    for (int j = 0; j < str.size(); j++)
    {
        //cout << "j" << j << "pos" << pos << "len" << len << endl;
        if (!skip[j])
        {
            len++;
        }
        else
        {
            newstr.append(str.begin() + pos, str.begin() + pos + len);
            //cout << newstr << endl;
            len = 0;
            pos = j + m;
            skip[j] = false;
            j += m - 1;
        }
    }
    if (len > 0)
    {
        newstr.append(str.begin() + pos, str.begin() + pos + len);
    }
    return newstr;
}

vector<int> computePrefix(string pat)
{
    int m = pat.size();
    ///int *longestPrefix = (int *)malloc(sizeof(int)*m);
    vector<int> longestPrefix(m);
    for (int i = 1, k = 0; i < m; i++)
    {
        while (k > 0 && pat[k] != pat[i])
        {
            k = longestPrefix[k - 1];
        }
        if (pat[i] == pat[k])
        {
            longestPrefix[i] = ++k;
        }
        else
        {
            longestPrefix[i] = k;
        }
    }
    return longestPrefix;
}
int KMP(string &str, string pat)
{
    int count = 0;
    n = str.size();
    m = pat.size();
    vector<int> longestPrefix = computePrefix(pat);
    //int * longestPrefix = computePrefix(pat);
    for (int i = 0, k = 0; i < n; i++)
    {
        //cout << "i " << i << " k " << k << endl;
        while (k > 0 && pat[k] != str[i])
        {
            k = longestPrefix[k - 1];
        }
        if (str[i] == pat[k])
        {
            k++;
        }
        if (k == m)
        {
            count++;
            skip[i - m + 1] = true;
            /*
            str.erase(i - m + 1, m);
            //cout << i - m + 2<< "gg"<< m << endl;
            if (i - 2 * m + 2 > -2)
            {
                i = i - 2 * m + 2;
            }
            else
            {
                i = -1;
            }
            */
            //k = 0;
            k = longestPrefix[k - 1];
        }
    }
    return count;
}

char str_[1000010], pattern_[1000010];
int finddu = 0;
int main()
{
    // std::ios::sync_with_stdio(false);
    cin.tie(0);
    //cin >> T;
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        scanf("%d", &tmp);
        scanf("%s", str_);
        //cin >> tmp >> str;
        scanf("%d", &tmp);
        scanf("%s", pattern_);
        //cin >> tmp >> pattern;
        string str(str_), pattern(pattern_);
        do
        {
            finddu = KMP(str, pattern);
            str = gen_new(str);
        } while (finddu != 0);

        //cout << KMP(str, pattern) << endl;
        // strncpy(str_, str.c_str(), sizeof(str_));
        // str_[sizeof(str_) - 1] = 0;
        // printf("%s\n", str_);
        cout << str << endl;
    }
    return 0;
}
