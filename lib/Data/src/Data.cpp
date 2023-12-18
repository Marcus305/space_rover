#include <FS.h>
#include <SPIFFS.h>

void pathGenerator(File *path, File *colisions) {
    File graphQuantity = SPIFFS.open("/graph_quantity.dat", "w+");
    String quantity = graphQuantity.readString();
    int n;

    if(quantity.length() > 0) {
        n = quantity.toInt();
    } else {
        n = 0;
    }

    String p = "/graphPath" + String(n);
    String c = "/graphColision" + String(n);
    path = &SPIFFS.open(p, "w+");
    colisions = &SPIFFS.open(p, "w+");
}