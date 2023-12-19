#include <stdio.h>
#include <stdlib.h>

#include <Movement.h>
#include <Sonar.h>
#include <FS.h>
#include <SPIFFS.h>
#include <ArduinoJson.h>

void automaticMapping(File *pathing, File *colisions) {
    const size_t capacity = JSON_OBJECT_SIZE(2) + MAX_NODES * JSON_OBJECT_SIZE(3) + MAX_EDGES * JSON_OBJECT_SIZE(3);
    DynamicJsonDocument dataInstance(capacity);
    if(pathing->size() != 0) {
        String jsonPathContent = pathing->readString();
    } else {
        n = 0;
    }
    while(true) {

        double longPathPossible;
        double freePath;
    }
}