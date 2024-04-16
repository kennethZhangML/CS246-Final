#include <iostream>
#include <string>

class Directory {

    // could've added a field for the author
    // but im too lazy to do this shit anymore
    struct File {
        std::string filename;
        int id;
        File* next;
        
        File(std::string filename, int id, File* next = nullptr) : filename{filename}, id{id}, next{next} {}
    };

    File* theDirectory = nullptr;

public:
    class FileIterator {
        File* currentFile;

    public:
        FileIterator(File* currentFile);
        bool operator!=(const FileIterator& other);
        std::string operator*() const;
        FileIterator& operator++();
    };

    ~Directory();
    void addFile(std::string filename, int id);
    FileIterator begin() const;
    FileIterator end() const;
};

Directory::FileIterator::FileIterator(File *currentFile) : currentFile{currentFile} {}

bool Directory::FileIterator::operator!=(const FileIterator& other) {
    return currentFile != other.currentFile;
}

std::string Directory::FileIterator::operator*() const {
    return currentFile->filename;
}

Directory::FileIterator& Directory::FileIterator::operator++() {
    if (this->currentFile != nullptr) {
        currentFile = currentFile->next;
    }
    return *this;
}

Directory::~Directory() {
    while (theDirectory != nullptr) {
        File *temp = theDirectory;
        theDirectory = theDirectory->next;
        delete temp;
    }
}

void Directory::addFile(std::string filename, int id) {
    theDirectory = new File{filename, id, theDirectory};
}

Directory::FileIterator Directory::begin() const {
    return FileIterator(theDirectory);
}

Directory::FileIterator Directory::end() const {
    return FileIterator(nullptr);
}

int main() {
    Directory mydir;
    mydir.addFile("CCP Manifesto", 1);
    mydir.addFile("Marxism is goated", 2);
    mydir.addFile("Caroline Kierstead is a Fatass", 3);
    mydir.addFile("Hitler in Paris: A Memoir", 4);

    std::cout << "Iterator through the directory: " << std::endl;
    for (Directory::FileIterator it = mydir.begin(); it != mydir.end(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}




