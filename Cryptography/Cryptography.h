#include <vector>

/* A simple class for returning exact row and column */
class Trace
{
public:
    int i, j;
};
/**
 * to remove duplicated char form a std::string 
 * @param key - received a std::string
 * @return a std::string that has no repeated char 
 * @copyright this function was written by Mr Polin Khan
 * */
std::string removeDuplicates(std::string key)
{
    bool isVisit[130] = {0};
    std::string final;
    int len = key.length();
    for (int i = 0; i < len; i++)
    {
        if (!isVisit[(int)key.at(i)])
        {
            final.push_back(key.at(i));
            isVisit[(int)key.at(i)] = 1;
        }
    }
    return final;
}

int found(std::string key, char ch)
{
    int len = key.length();
    for (size_t i = 0; i < len; i++)
    {
        if (ch == key[i])
            return 1;
    }
    return 0;
}

/**
 * generate a table of n x 9 char 
 * @param v - receive a std::vector inside another char std::vector
 * @param key - receive a std::string that will help to make proper table
 * @return void 
 * */
void tables(std::vector<std::vector<char>> &v, std::string key)
{

    char ch = 'A';
    int c = -1;
    int C = 0;
    char val = ch + c;

    /* added special characters and numbers */
    char sampleTable[] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 61, 63, 64, 91, 93, 123, 125, 33, 34, ' ', 36, 37, 38, 40, 41, 44, 46};
    int len = key.length();
    if (len > 9)
    {
        std::cout << "key should less then 9 word , we're making table using first 9 word of your key" << std::endl;
        key = key.substr(0, 9);
        len = 9;
    }

    for (size_t i = 0; i < 9; i++)
    {

        for (size_t j = 0; j < 9; j++, c++)
        {

            val = ch + c;

            /* added key infront of table */
            if (i == 0 && j == 0)
            {
                std::copy(key.begin(), key.end(), std::back_inserter(v[0]));
                j = len - 1;
            }

            /* added Upper case latter */
            else if (val >= 'A' && val <= 'Z')
            {
                if (val == 'Z')
                {
                    ch = 'a';
                    c = -1;
                }
                if (!found(key, val))
                    v[i].push_back(val);
                else
                    --j;
            }
            /* added lower case latter */
            else if (val >= 'a' && val <= 'z')
            {
                if (!found(key, val))
                    v[i].push_back(val);
                else
                    --j;
            }

            /*added number and some special Characters */
            else
            {
                val = sampleTable[C++];
                if (!found(key, val))
                    v[i].push_back(val);
                else
                    --j;
            }
        }
    }
}

/* return row and column position form generated table for a perticular pair of char */
Trace findPos(std::vector<std::vector<char>> &table, char &ch)
{
    Trace t;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (ch == table[i][j])
            {
                t.i = i;
                t.j = j;
                return t;
            }
        }
    }
    return t;
}

/* This function will generate cipher text form plain text for a pair char*/
void convertToCipher(char &ch1, char &ch2, std::vector<std::vector<char>> &table)
{
    /*get i and j of any character from generated table */
    Trace first = findPos(table, ch1);
    Trace second = findPos(table, ch2);

    if (first.i == second.i) /* If rows are same  amd encrease column  */
    {
        ch1 = table[first.i][(first.j + 1) % 9];
        ch2 = table[second.i][(second.j + 1) % 9];
    }
    else if (first.j == second.j) /*If columns are same then encrease row */
    {
        ch1 = table[(first.i + 1) % 9][first.j];
        ch2 = table[(second.i + 1) % 9][second.j];
    }
    else /* if row and column are different */
    {
        ch1 = table[first.i][second.j];
        ch2 = table[second.i][first.j];
    }
}
void contert_to_plain(char &ch1, char &ch2, std::vector<std::vector<char>> &table)
{
    /*get i and j of any character from generated table */
    Trace first = findPos(table, ch1);
    Trace second = findPos(table, ch2);

    if (first.i == second.i) /* If rows are same  amd encrease column  */
    {
        int firstJ = (first.j - 1) < 0 ? (9 - (abs(first.i - 1) % 9)) : (first.j - 1);
        int secondJ = (second.j - 1) < 0 ? (9 - (abs(second.j - 1) % 9)) : (second.j - 1);

        ch1 = table[first.i][firstJ];
        ch2 = table[second.i][secondJ];
    }
    else if (first.j == second.j) /*If columns are same then encrease row */
    {
        int firstI = (first.i - 1) < 0 ? (9 - (abs(first.i - 1) % 9)) : (first.i - 1);
        int secondI = (second.i - 1) < 0 ? (9 - (abs(second.i - 1) % 9)) : (second.i - 1);

        ch1 = table[firstI][first.j];
        ch2 = table[secondI][second.j];
    }
    else /* if row and column are different */
    {
        ch1 = table[first.i][second.j];
        ch2 = table[second.i][first.j];
    }
}

/* this function will create pair of plain text and return whole cipher text */
std::string make_cipher(std::string text, std::vector<std::vector<char>> &table)
{

    size_t i = 0;
    for (; i < text.length() - 1; i += 2)
    {
        text[i] == text[i + 1] ? text.insert(i + 1, 1, ' ') : text; // for creating vocas later

        if (i < text.length() - 1)
            convertToCipher(text[i], text[i + 1], table); // H E
    }
    if (text.length() % 2)
    {
        text.push_back(' ');
        convertToCipher(text[text.length() - 2], text[text.length() - 1], table);
    }

    return text;
}

std::string make_plainText(std::string text, std::vector<std::vector<char>> &table)
{
    int len = text.length();
    for (size_t i = 0; i < len; i += 2)
    {
        contert_to_plain(text[i], text[i + 1], table);
    }

    return text;
}

/**
 * playfair cipher function will make a cipher text from plain text 
 * @param plainText - receive a plain text that will convert into cipher text
 * @param key - receive a key that will help to make hep to create a proper and secure cipher text
 * @return std::string - return generated secure cipher text 
 **/
std::string playfair(std::string plainText, std::string key)
{

    if (plainText.length() == 0) // if void std::string occures
        plainText = " ";
    if (key.length() == 0)
        key = " ";
    /* Remove Duplicate from key */
    key = removeDuplicates(key);

    /* Generate Table */
    std::vector<std::vector<char>> table(9);
    tables(table, key);
    return make_cipher(plainText, table); /* to make cipher text form plaintext using play fare cipher */
}

/* making a function that can restore plain text form play fare cipher text */
/**
 * playfair_to_plaintext can change form cipher to plain text 
 * @param cipher_text - a std::string of cipher form text 
 * @param key - key of this program 
 * @return a plain text form cihper text 
 * */
std::string playfair_to_plaintext(std::string cipher_text, std::string key)
{
    key = removeDuplicates(key);
    std::vector<std::vector<char>> table(9);
    tables(table, key);
    return make_plainText(cipher_text, table); /* this is the only function that can restore to plain text form play fare cipher text using key */
}