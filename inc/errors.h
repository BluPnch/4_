#ifndef ERRORS_H
#define ERRORS_H

#include "QMessageBox"

enum errors {
    ERR_OK,
    ERR_FILE_NOT_FOUND,
    ERR_FILE_FORMAT,
    ERR_FILE_CONTENT,
    ERR_PTR_ALL,
    ERR_NO_DOTS,
    ERR_NO_LINKS,
    ERR_UNKNOWN_COMMAND
};

// void error_message(errors res)
// {
//     if (res == ERR_FILE_NOT_FOUND)
//         QMessageBox::critical(NULL, "ERROR", "File is broken, or doesn't exist");
//     else if (res == ERR_FILE_FORMAT)
//         QMessageBox::critical(NULL, "ERROR", "File format error");
//     else if (res == ERR_FILE_CONTENT)
//         QMessageBox::critical(NULL, "ERROR", "File has wrong content");
//     else if (res == ERR_PTR_ALL)
//         QMessageBox::critical(NULL, "ERROR", "Error with memory allocation");
//     else if (res == ERR_NO_DOTS)
//         QMessageBox::critical(NULL, "ERROR", "File is empty, or array is empty!");
//     else if (res == ERR_UNKNOWN_COMMAND)
//         QMessageBox::critical(NULL, "ERROR", "Unknown command in enter point!");
//     else
//         QMessageBox::critical(NULL, "ERROR", "Unknown error");
// }

#endif //ERRORS_H
