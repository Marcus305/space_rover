#ifndef DATA_H
#define DATA_H

#include <FS.h>
#include <SPIFFS.h>

void *pathGenerator(File *path, File *colisions);

#endif