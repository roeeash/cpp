#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Directory
{
public:
    Directory(char *name)
    {
        this->path = "";
        this->name = name;
    }

    ~Directory()
    {
    }

    void printDir(int depth)
    {
        cout << "\n";
        string spaces = "\t";
        for (int i = 0; i < depth; i++)
        {
            spaces += "\t";
        }
        if (name == "root")
            cout << this->name << endl;
        else
            cout << spaces;
        sort(subDirectories.begin(),
             subDirectories.end(),
             [](const Directory &lhs, const Directory &rhs)
             {
                 return (lhs.name.compare(rhs.name) < 0);
             });
        cout << spaces;

        for (int i = 0;
             i < subDirectories.size(); i++)
        {

            cout << subDirectories[i].path << endl;
        }

        for (string file : files)
        {
            cout << file << endl;
        }
    }

    // compare two directories
    bool compare(const Directory &d) const
    {
        return (this->name.compare(d.name) < 0);
    }

    void addFile(char *inp)
    {
        files.push_back(inp);
        sort(files.begin(), files.end());
    }

    void addDir(char *inp)
    {
        string s(inp);
        Directory d(inp);
        if (name == "root")
            d.path += name + "->" + inp;
        else
            d.path += path + "->" + inp;
        d.parent = this;
        subDirectories.push_back(d);
        // sort(subDirectories.begin(), subDirectories.end(), &compare);

        cout
            << "\n"
            << inp << "'s parent name is " << d.parent->name << endl;
    }

    string name;
    string path;
    Directory *parent;
    vector<string> files;
    vector<Directory> subDirectories;
};

void addDir(Directory *d, char *inp)
{
    printf("\nAdding dir %s", inp);
    d->addDir(inp);
}

void addFile(Directory *d, char *inp)
{
    printf("\nAdding file %s", inp);
    d->addFile(inp);
}

Directory *changeDir(Directory *d, char *inp)
{
    printf("\nChanging dir %s", inp);
    if (!strcmp(inp, ".."))
    {
        cout << "go to parent" << endl;
        return d->parent;
    }

    for (int i = 0; i < d->subDirectories.size(); i++)
    {
        Directory *curr = &d->subDirectories[i];
        if (curr->name == inp)
        {
            printf("\nfound dir");
            return curr;
        }
    }
    printf("\ndir not found");
    return NULL;
}

void printDirPath(Directory *d)
{
    // printf("\nPrinting dir path");
    cout << d->path;
}

void printDirDepth(Directory *d, int depth)
{
    // printf("\nPrinting dir path");
    d->printDir(depth);
}

void printDirTree(Directory *r)
{
    printf("\nPrint dir tree");
    printDirDepth(r, 0);
    for (int i = 0; i < r->subDirectories.size(); i++)
    {
        printDirDepth(&r->subDirectories[i], i + 1);
    }
}

void clean()
{
    printf("\nCleaning memory");
}

int menu()
{
    printf("\n 1. Create a directory");
    printf("\n 2. Create a file");
    printf("\n 3. Change directory");
    printf("\n 4. Print current directory path");
    printf("\n 5. Print directory tree");
    printf("\n 6. Exit");
    printf("\n What would you like to do: ");
    int i = -1;
    while ((i < 1) || (i > 6))
    {
        char c;
        cin >> c;
        i = c - '0';
    }
    return i;
}

int main(int argc, char *argv[])
{
    char inp[100];
    int i = 0;
    char root[] = "root";
    // added directory
    Directory *d = new Directory(root);
    Directory *r = d;

    while (true)
    {
        i = menu();
        switch (i)
        {
        case 1:
            printf("\nCreate a directory. Dir name: ");
            cin >> inp;
            addDir(d, inp);
            break;
        case 2:
            printf("\nCreate a file. File name: ");
            cin >> inp;
            addFile(d, inp);
            break;
        case 3:
            printf("\nChange directory. Dir name: ");
            cin >> inp;
            d = changeDir(d, inp);
            break;
        case 4:
            printf("\nPrint directory path:\n");
            printDirPath(d);
            break;
        case 5:
            printf("\nPrint directory tree:\n");
            printDirTree(r);
            break;
        case 6:
            clean();
            return 0;
        }
    }
    return 0;
}